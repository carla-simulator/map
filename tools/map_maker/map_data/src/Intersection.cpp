// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/Intersection.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/CubicBezier.hpp>
#include <ad/map/maker/geometry/Direction2d.hpp>
#include <ad/map/maker/geometry/Polyline2d.hpp>
#include <algorithm>
#include <cmath> // for M_PI
#include <lapacke.h>
#include "ad/map/maker/map_data/IntersectionConnector.hpp"
#include "ad/map/maker/map_data/MapDataStore.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

Intersection::Intersection(MapDataStore &dataStore, common::LogFactory &logFactory)
  : MapDataElement()
  , mStore(dataStore)
  , mLog(logFactory.logChannel("Intersection"))
  , mRoadLog(logFactory.logChannel("InternalRoad"))
{
}

// Matrix of values for least squares calculation of center point
std::vector<double> calculateA(std::vector<geometry::Point2d> const &n)
{
  // A = sum_n { I - n*n' }
  std::vector<double> A(4, 0.);

  for (uint32_t k = 0; k < n.size(); k++)
  {
    A[0] += 1. - n[k].x * n[k].x; // Axx
    A[1] += 0. - n[k].x * n[k].y; // Axy
    A[2] += 0. - n[k].y * n[k].x; // Ayx
    A[3] += 1. - n[k].y * n[k].y; // Ayy
  }

  return A;
}

// Vector of values for least squares calculation of center point
std::vector<double> calculateB(std::vector<geometry::Point2d> const &n, std::vector<geometry::Point2d> const &a)
{
  // b = sum_n { (I - n*n') * a_n}
  std::vector<double> b(2, 0.);

  for (uint32_t k = 0; k < n.size(); k++)
  {
    double Axx = 1. - n[k].x * n[k].x;
    double Axy = 0. - n[k].x * n[k].y;
    double Ayx = 0. - n[k].y * n[k].x;
    double Ayy = 1. - n[k].y * n[k].y;

    b[0] += Axx * a[k].x + Axy * a[k].y;
    b[1] += Ayx * a[k].x + Ayy * a[k].y;
  }
  return b;
}

geometry::Point2d Intersection::calculateLSQIntersectionPoint() const
{
  geometry::Point2d center;
  std::vector<geometry::Point2d> endPoints;
  std::vector<geometry::Point2d> directionVectors;

  for (auto const &arm : mArms)
  {
    auto const &road = mStore.road(arm.connectedRoad);
    auto const &polyLine = mStore.polyLine(road.mCenterLineId);
    auto const numberOfPoints = polyLine.mNodes.size();

    if (numberOfPoints < 2)
    {
      mLog(common::LogLevel::Error) << "Invalid arm for intersection " << mId << " \n";
      return center;
    }

    geometry::Point2d p1, p2; // endpoints of the arm's polyline segment connected to the intersection

    if (arm.isEntry)
    {
      p1 = mStore.point(polyLine.mNodes[numberOfPoints - 1]);
      p2 = mStore.point(polyLine.mNodes[numberOfPoints - 2]);
    }
    else
    {
      p1 = mStore.point(polyLine.mNodes[0]);
      p2 = mStore.point(polyLine.mNodes[1]);
    }

    geometry::Direction2d direction(p2, p1);
    auto const directionVector = direction.orientationAsPoint();
    endPoints.push_back(p1);
    directionVectors.push_back(directionVector);
  }

  auto matrixA = calculateA(directionVectors);
  auto vectorB = calculateB(directionVectors, endPoints);

  uint32_t const m = 2;
  uint32_t const n = 2;
  uint32_t const bCols = 1;

  // least squares solution of ||b - Ax||
  auto info = LAPACKE_dgels(LAPACK_ROW_MAJOR, 'N', m, n, bCols, matrixA.data(), m, vectorB.data(), bCols);

  if (info != 0)
  {
    mLog(common::LogLevel::Error) << "Invalid center point calculation for intersection " << mId << " \n";
    return center;
  }
  center = geometry::Point2d{vectorB[0], vectorB[1]};
  return center;
}

geometry::Point2d Intersection::calculateIntersectionCentroid() const
{
  geometry::Point2d center;
  double numberOfArmsRatio = 1 / (static_cast<double>(mArms.size()));
  for (auto const &arm : mArms)
  {
    auto const &road = mStore.road(arm.connectedRoad);
    auto const &polyLine = mStore.polyLine(road.mCenterLineId);
    geometry::Point2d point;
    if (arm.isEntry)
    {
      point = mStore.point(polyLine.mNodes.back());
    }
    else
    {
      point = mStore.point(polyLine.mNodes.front());
    }
    center += numberOfArmsRatio * point;
  }
  return center;
}

void Intersection::generateCenter()
{
  geometry::Point2d center;
  if (mArms.size() < 3u)
  {
    center = calculateIntersectionCentroid();
  }
  else
  {
    center = calculateLSQIntersectionPoint();
  }

  mCenterPointId = mStore.getOrCreateIdForPoint(center);
}

bool Intersection::addRoad(MapDataId const roadId, common::RightOfWay const regulation, bool isEntry)
{
  Road road = mStore.road(roadId); // will throw if road does not exist

  if (mId == InvalidId)
  {
    mLog(common::LogLevel::Warning)
      << "Adding road to an intersection with invalid id. Lane successor/predecessors won't be set correctly \n";
  }
  if (isEntry)
  {
    mStore.road(roadId).mSuccessor = mId;
  }
  else
  {
    mStore.road(roadId).mPredecessor = mId;
  }

  IntersectionArm arm;
  arm.connectedRoad = roadId;
  arm.isEntry = isEntry;
  arm.mId = mStore.getNextId();
  arm.rightOfWay = regulation;
  mLog(common::LogLevel::Verbose) << "Adding arm with id " << arm.mId << " for road " << roadId;
  mLog << " as " << (isEntry ? "incoming" : "outgoing") << "\n";
  mArms.push_back(arm);

  return true;
}

bool Intersection::addIncomingRoad(MapDataId const roadId, common::RightOfWay const regulation)
{
  return addRoad(roadId, regulation, true);
}

bool Intersection::addOutgoingRoad(MapDataId const roadId, common::RightOfWay const regulation)
{
  return addRoad(roadId, regulation, false);
}

std::vector<MapDataId> *getListOfNodes(MapDataId id, MapDataStore &store)
{
  Road &road = store.road(id);
  PolyLine &polyLine = store.polyLine(road.mCenterLineId);
  return &polyLine.mNodes;
}

void Intersection::adjustArm(IntersectionArm &arm, double distance) const
{
  MapDataId roadId = arm.connectedRoad;
  geometry::Point2d center = mStore.point(mCenterPointId);
  std::vector<MapDataId> *nodes = getListOfNodes(roadId, mStore);
  double traveledDistance = 0.0;
  geometry::Point2d previousNode;
  geometry::Point2d currentNode;

  double margin = marginForTypeOfRoad(mStore.road(roadId).mRoadType);
  double adjustingDistance = std::min(distance + margin, 20.0);
  if (arm.isEntry)
  {
    currentNode = mStore.point(nodes->back());
    do
    {
      nodes->pop_back();
      if (nodes->empty())
      {
        Road &road = mStore.road(roadId);
        roadId = road.mPredecessor;
        if (mStore.hasRoad(roadId))
        {
          road.mPredecessor = InvalidId;
          road.mSuccessor = InvalidId;
          mLog(common::LogLevel::Info) << "Switching to predecessor: " << roadId << "\n";
          nodes = getListOfNodes(roadId, mStore);
          nodes->pop_back();
        }
      }
      if (!nodes->empty())
      {
        previousNode = currentNode;
        currentNode = mStore.point(nodes->back());
        traveledDistance += sqrt(previousNode.squaredDistance(currentNode));
      }
    } while (!nodes->empty() && traveledDistance < adjustingDistance);
  }
  else
  {
    currentNode = mStore.point(nodes->front());
    do
    {
      nodes->erase(nodes->begin());
      if (nodes->empty())
      {
        Road &road = mStore.road(roadId);
        roadId = road.mSuccessor;
        if (mStore.hasRoad(roadId))
        {
          road.mPredecessor = InvalidId;
          road.mSuccessor = InvalidId;
          mLog(common::LogLevel::Info) << "Switching to successor: " << roadId << "\n";
          nodes = getListOfNodes(roadId, mStore);
          nodes->erase(nodes->begin());
        }
      }
      if (!nodes->empty())
      {
        previousNode = currentNode;
        currentNode = mStore.point(nodes->front());
        traveledDistance += sqrt(previousNode.squaredDistance(currentNode));
      }
    } while (!nodes->empty() && traveledDistance < adjustingDistance);
  }

  auto remainingDistance = adjustingDistance - traveledDistance;
  if (fabs(remainingDistance) < 0.1)
  {
    // TODO: Small remaining distances cause issues when shifting polylines that follow a curve
    mLog(common::LogLevel::Warning) << "Small remaining distance\n";

    remainingDistance = -0.1;
  }

  if (mStore.hasRoad(roadId))
  {
    // move current node remaining distance to direction to nodes->back
    geometry::Direction2d dir(previousNode, currentNode);

    geometry::Point2d connectionPoint = dir.movePoint(currentNode, remainingDistance);
    arm.connectionPoint = mStore.getOrCreateIdForPoint(connectionPoint);

    nodes->insert(arm.isEntry ? nodes->end() : nodes->begin(), arm.connectionPoint);

    arm.orientation = dir.orientation;
    arm.connectedRoad = roadId;
  }
  else
  {
    geometry::Direction2d dir(arm.orientation);
    geometry::Point2d connectionPoint = dir.movePoint(center, adjustingDistance);
    arm.connectionPoint = mStore.getOrCreateIdForPoint(connectionPoint);
  }

  if (mStore.hasRoad(roadId))
  {
    Road &road = mStore.road(roadId);
    if (arm.isEntry)
    {
      road.mSuccessor = mId;
    }
    else
    {
      road.mPredecessor = mId;
    }
  }

  // after all, calculate the distance of the road start/end to the junction
  // in case of a ramp, this is not necessary, as ramps are handled differently (in road5)
  if (mStore.hasRoad(roadId) && (mIntersectionType != IntersectionType::Ramp))
  {
    Road &road = mStore.road(roadId);
    const auto center = mStore.point(mCenterPointId);
    const auto roadCenterLine = mStore.polyLine(mStore.road(roadId).mCenterLineId).mNodes;
    geometry::Point2d roadPoint = center;
    if (isRoadEntry(roadId))
    {
      roadPoint = mStore.point(roadCenterLine.back());
    }
    else if (isRoadExit(roadId))
    {
      roadPoint = mStore.point(roadCenterLine.front());
    }
    const geometry::Line2d line(roadPoint, center);
    road.mDistanceToJunctionCenter = line.length();
  }
}

double Intersection::calculateMaxDistanceToCenter() const
{
  if (isCrosswalk())
  {
    return 1.;
  }

  double maxWidth = 0.;
  for (auto const &arm : mArms)
  {
    Road const &road = mStore.road(arm.connectedRoad);
    double maxWidthAtArm = std::max(road.forwardWidth(), road.backwardWidth());
    maxWidth = std::max(maxWidth, maxWidthAtArm);
  }

  return 2 * maxWidth;
}

void Intersection::adjustRoads()
{
  for (auto &arm : mArms)
  {
    mLog(common::LogLevel::Verbose) << "Adjusting road for arm " << arm.connectedRoad << "\n";
    adjustArm(arm, arm.distanceToCenter);
    mLog(common::LogLevel::Verbose) << "Connected road after adjustment " << arm.connectedRoad << "\n";
  }
}

void Intersection::calculateConnectionPoints()
{
  std::map<MapDataId, double> armDists;

  for (auto const &arm : mArms)
  {
    if (isCrosswalk())
    {
      double crosswalkMargin = 1.0; // in m
      mLog(common::LogLevel::Info) << "Intersection is crosswalk, using dist " << crosswalkMargin << "\n";
      armDists[arm.connectedRoad] = crosswalkMargin;
    }
    else
    {
      // Loop over all arm combinations and calculate the intersection points between the arms
      double maxAdjustingDistance{0.0};
      for (auto const &otherArm : mArms)
      {
        mLog(common::LogLevel::Verbose) << "Adjusting arm " << arm.connectedRoad << " with arm "
                                        << otherArm.connectedRoad << "\n";
        if ((arm.connectedRoad == otherArm.connectedRoad) && (!(arm.isEntry != otherArm.isEntry)))
        {
          mLog(common::LogLevel::Verbose) << "Ignoring arm pair \n";
        }
        else if (fabs(geometry::minimumAngleDifference(arm.orientation, otherArm.orientation)) < (M_PI / 18.0))
        {
          mLog(common::LogLevel::Verbose) << "Near parallel arm, ignoring arm pair \n";
        }
        else
        {
          double adjustingDistance = calculateAdjustingDistance(arm, otherArm);
          maxAdjustingDistance = std::max(adjustingDistance, maxAdjustingDistance);
        }
      }
      armDists[arm.connectedRoad] = maxAdjustingDistance;
    }
  }

  for (auto &arm : mArms)
  {
    arm.distanceToCenter = armDists[arm.connectedRoad];
  }
}

double leftWidthOfRoad(const Road &road, bool isEntry)
{
  if (isEntry)
  {
    return road.forwardWidth();
  }
  else
  {
    return road.backwardWidth();
  }
}

double rightWidthOfRoad(const Road &road, bool isEntry)
{
  if (isEntry)
  {
    return road.backwardWidth();
  }
  else
  {
    return road.forwardWidth();
  }
}

double Intersection::calculateAdjustingDistance(const IntersectionArm &thisArm, const IntersectionArm &otherArm) const
{
  const double angleBetween = otherArm.orientation - thisArm.orientation;
  const Road &thisRoad = mStore.road(thisArm.connectedRoad);
  const Road &otherRoad = mStore.road(otherArm.connectedRoad);
  double thisLeftWidth = leftWidthOfRoad(thisRoad, thisArm.isEntry);
  double thisRightWidth = rightWidthOfRoad(thisRoad, thisArm.isEntry);
  double otherLeftWidth = leftWidthOfRoad(otherRoad, otherArm.isEntry);
  double otherRightWidth = rightWidthOfRoad(otherRoad, otherArm.isEntry);
  double thisLeftProjection = std::max(thisLeftWidth * cos(angleBetween - M_PI_2), 0.0);
  double thisRightProjection = std::max(thisRightWidth * cos(angleBetween + M_PI_2), 0.0);
  double otherLeftProjection = std::max(otherLeftWidth * cos(angleBetween + M_PI_2), 0.0);
  double otherRightProjection = std::max(otherRightWidth * cos(angleBetween - M_PI_2), 0.0);
  double thisCompensation = 0.0;
  double otherCompensation = 0.0;
  double otherProjection = 0.0;

  // Calculate the maximum projection of the forward and backward lanes on the other road
  if (thisLeftProjection > thisRightProjection)
  {
    if (thisLeftProjection > 0.0)
    {
      thisCompensation = fabs(thisLeftWidth * tan(angleBetween - M_PI_2));
    }
  }
  else
  {
    if (thisRightProjection > 0.0)
    {
      thisCompensation = fabs(thisRightWidth * tan(angleBetween + M_PI_2));
    }
  }

  // Calculate maximum projection of the other road forward and backward lanes on this road
  if (otherLeftProjection > otherRightProjection)
  {
    if (otherLeftProjection > 0.0)
    {
      otherProjection = otherLeftProjection;
      otherCompensation = fabs(otherLeftWidth / cos(angleBetween + M_PI_2));
    }
  }
  else
  {
    if (otherRightProjection > 0.0)
    {
      otherProjection = otherRightProjection;
      otherCompensation = fabs(otherRightWidth / cos(angleBetween - M_PI_2));
    }
  }

  // Use composite compensation only when the absolute value of the angle between the arms is lower than M_PI_2
  if (fabs(geometry::minimumAngleDifference(thisArm.orientation, otherArm.orientation)) < M_PI_2)
  {
    return thisCompensation + otherCompensation;
  }
  else
  {
    return otherProjection;
  }
}

void Intersection::orderArmsByDirection()
{
  std::map<double, IntersectionArm> orderedArms;
  for (auto &arm : mArms)
  {
    if (isValidArm(arm))
    {
      Road const &road = mStore.road(arm.connectedRoad);
      PolyLine &polyLine = mStore.polyLine(road.mCenterLineId);
      geometry::Point2d connPoint;
      geometry::Point2d roadPoint;
      /* A note on the indices of the points: Given a polyline with n nodes:
       * 0---1---2--- ... ---n-2----n-1
       * For the calculation of the orientation at begin/end we take nodes with indices
       * 0, 1 (at the beginning) and n-2, n-1 (at the end).
       * If a road goes into the intersection (arm.isEntry): use index n-1 and n-2
       * If a road goes out of the intersection (!arm.isEntry): use index 0 and 1
       */

      if (arm.isEntry)
      {
        connPoint = mStore.point(polyLine.mNodes[polyLine.mNodes.size() - 1]);
        roadPoint = mStore.point(polyLine.mNodes[polyLine.mNodes.size() - 2]);
      }
      else
      {
        connPoint = mStore.point(polyLine.mNodes[0]);
        roadPoint = mStore.point(polyLine.mNodes[1]);
      }

      geometry::Direction2d dir(connPoint, roadPoint);
      arm.orientation = dir.orientation;
      orderedArms[arm.orientation] = arm;
      mLog(common::LogLevel::Verbose) << "Arm for road " << arm.connectedRoad << " has direction " << arm.orientation
                                      << " (" << arm.orientation * 180. / M_PI << " deg)\n";
    }
    else
    {
      mLog(common::LogLevel::Warning) << "Invalid arm with road " << arm.connectedRoad << "\n";
    }
  }

  mArms.clear();
  for (auto orderedArm : orderedArms)
  {
    mArms.push_back(orderedArm.second);
  }
}

/*
 * Iterate over all arms and identify all possible roads between them, remove those who are forbidden due to
 * turn restrictions.
 * 1. Setup the IntersectionConnector and add all the arms.
 * 2. Generate all the possible internal connections.
 * 3. Depending on the type of intersection, remove forbidden connections, uturns, etc.
 * 4. Setup the internal road information
 */
void Intersection::generateInternalRoads()
{
  IntersectionConnector connector;
  auto const numArms = mArms.size();
  for (uint32_t armIndex = 0u; armIndex < numArms; ++armIndex)
  {
    connector.addArm(mStore, armIndex, mArms[armIndex]);
  }

  connector.generateConnections(mStore);
  connector.removeUTurns();

  if (mIntersectionType == IntersectionType::Complex)
  {
    connector.removeForbiddenConnections();
    connector.keepOneToOneLogicConnections();
  }
  else if (mIntersectionType == IntersectionType::Regular)
  {
    connector.removeForbiddenConnections();
    connector.keepOnlyClosestOutgoingConnections();
  }
  else if (mIntersectionType == IntersectionType::Ramp)
  {
    connector.removeSharpTurns();
    connector.keepOneToOneLogicConnections();
  }
  else if (mIntersectionType == IntersectionType::Service)
  {
    connector.removeForbiddenConnections();
    connector.removeSharpTurns();
    connector.keepOnlyClosestConnections();
  }
  else
  {
    connector.removeForbiddenConnections();
    connector.keepOnlyClosestConnections();
  }

  std::set<IntersectionConnection> orderedConnections(connector.intersectionConnections().begin(),
                                                      connector.intersectionConnections().end());
  for (auto const &orderedConnection : orderedConnections)
  {
    addInternalRoadConnection(orderedConnection);
  }
}

double offsetForLane(Road const &road, uint32_t laneIndex, bool isForwardLane)
{
  double offset{0.0};
  auto const &widths = isForwardLane ? road.mForwardWidths : road.mBackwardWidths;
  for (uint32_t i = 0u; i < laneIndex; ++i)
  {
    offset += widths[i];
  }
  return offset;
}

void Intersection::addInternalRoadConnection(const IntersectionConnection &connection)
{
  uint32_t armInIndex = connection.inArmId;
  uint32_t armOutIndex = connection.outArmId;
  uint32_t laneInIndex = connection.inLaneId;
  uint32_t laneOutIndex = connection.outLaneId;
  auto const &inArm = mArms[armInIndex];
  auto const &outArm = mArms[armOutIndex];
  auto const &entryRoad = mStore.road(inArm.connectedRoad);
  auto const &exitRoad = mStore.road(outArm.connectedRoad);

  double widthAtStart = inArm.isEntry ? entryRoad.mForwardWidths[laneInIndex] : entryRoad.mBackwardWidths[laneInIndex];
  double widthAtEnd = outArm.isEntry ? exitRoad.mBackwardWidths[laneOutIndex] : exitRoad.mForwardWidths[laneOutIndex];
  double offsetAtStart = offsetForLane(entryRoad, laneInIndex, inArm.isEntry);
  double offsetAtEnd = offsetForLane(exitRoad, laneOutIndex, !outArm.isEntry);

  bool foundRoad{false};

  for (auto &internalRoad : mInternalRoads)
  {
    Road &road = mStore.road(internalRoad.roadId);
    if ((internalRoad.startIndex == armInIndex) && (internalRoad.endIndex == armOutIndex))
    {
      // New connection belongs to this road as forward connection
      if ((internalRoad.inCenterLaneId + road.mForwardWidths.size() == laneInIndex)
          && (internalRoad.outCenterLaneId + road.mForwardWidths.size() == laneOutIndex))
      {
        foundRoad = true;
        road.mForwardWidths.push_back(widthAtStart);
        road.mForwardWidthsAtEnd.push_back(widthAtEnd);
      }
    }
    else if ((internalRoad.startIndex == armOutIndex) && (internalRoad.endIndex == armInIndex))
    {
      // New connection belongs to this road as backward connection
      if ((road.mBackwardWidths.size() == laneOutIndex + internalRoad.inCenterLaneId)
          && (road.mBackwardWidths.size() == laneInIndex + internalRoad.outCenterLaneId))
      {
        foundRoad = true;
        Road &road = mStore.road(internalRoad.roadId);
        road.mBackwardWidths.push_back(widthAtEnd);
        road.mBackwardWidthsAtEnd.push_back(widthAtStart);
      }
    }
  }

  if (!foundRoad)
  {
    InternalRoad internalRoad;
    MapDataId startId = pointForInternalRoad(armInIndex, -offsetAtStart);
    MapDataId endId = pointForInternalRoad(armOutIndex, offsetAtEnd);

    internalRoad.startPointId = startId;
    internalRoad.endPointId = endId;
    internalRoad.inCenterLaneId = laneInIndex;
    internalRoad.outCenterLaneId = laneOutIndex;
    internalRoad.startIndex = armInIndex;
    internalRoad.endIndex = armOutIndex;

    auto roadId = mStore.createRoad(mRoadLog);
    auto &road = mStore.road(roadId);

    road.mRoadType = RoadType::Intersection;
    road.mSuccessor = exitRoad.mId;
    road.mPredecessor = entryRoad.mId;
    road.mForwardWidths.push_back(widthAtStart);
    road.mForwardWidthsAtEnd.push_back(widthAtEnd);
    double forwardSpeedLimit = inArm.isEntry ? entryRoad.mForwardSpeedLimit : entryRoad.mBackwardSpeedLimit;
    forwardSpeedLimit
      = std::min(forwardSpeedLimit, outArm.isEntry ? exitRoad.mBackwardSpeedLimit : exitRoad.mForwardSpeedLimit);
    road.mForwardSpeedLimit = forwardSpeedLimit;
    double backwardSpeedLimit = inArm.isEntry ? entryRoad.mBackwardSpeedLimit : entryRoad.mForwardSpeedLimit;
    backwardSpeedLimit
      = std::min(backwardSpeedLimit, outArm.isEntry ? exitRoad.mForwardSpeedLimit : exitRoad.mBackwardSpeedLimit);
    road.mBackwardSpeedLimit = backwardSpeedLimit;

    internalRoad.roadId = roadId;
    mInternalRoads.push_back(internalRoad);
    mRoads.push_back(roadId);
  }
}

/*
 * Generate the polylines of the road's lanes
 */
void Intersection::generateInternalGeometry()
{
  for (auto const &internalRoad : mInternalRoads)
  {
    interpolateInternalRoad(internalRoad);
  }
}

MapDataId Intersection::pointForInternalRoad(uint64_t index, double offset) const
{
  geometry::Point2d reference = mStore.point(mArms[index].connectionPoint);
  geometry::Direction2d direction(mArms[index].orientation - M_PI_2); // rotate by -90 degree
  geometry::Point2d point = direction.movePoint(reference, offset);
  MapDataId id = mStore.getOrCreateIdForPoint(point);
  return id;
}

PolyLine Intersection::generateBezierInterpolation(geometry::Polyline2d const &source) const
{
  if (source.points.size() != 5)
  {
    // must never happen
    throw std::runtime_error("generateBezierInterpolation called with wrong number of points!");
  }
  geometry::CubicBezier bezier;
  bezier.controlPoints.push_back(source.points[0]);
  bezier.controlPoints.push_back(source.points[1]);
  bezier.controlPoints.push_back(source.points[3]);
  bezier.controlPoints.push_back(source.points[4]);
  bezier.interpolationDistance = 1. / (mBezierInterpolationSteps);

  mLog(common::LogLevel::Verbose) << "    Control points for bezier interpolation:\n";
  PolyLine result;
  for (auto const &p : bezier.controlPoints)
  {
    mLog(common::LogLevel::Verbose) << "      " << p << "\n";
  }

  mLog(common::LogLevel::Verbose) << "    Points from bezier interpolation\n";
  result.mNodes.push_back(mStore.getOrCreateIdForPoint(source.points[0]));
  mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << source.points[0] << "\n";

  if (bezier.interpolate())
  {
    if (bezier.interpolatedPoints.size() > 2)
    {
      for (uint32_t p = 1u; p < bezier.interpolatedPoints.size() - 1; ++p)
      {
        auto const &point = bezier.interpolatedPoints.at(p);
        result.mNodes.push_back(mStore.getOrCreateIdForPoint(point));
        mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << point << "\n";
      }
    }
  }
  else
  {
    mLog(common::LogLevel::Warning) << "  Unable to interpolate internal road with bezier curve!\n";

    result.mNodes.push_back(mStore.getOrCreateIdForPoint(source.points[1]));
    mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << source.points[1] << "\n";

    result.mNodes.push_back(mStore.getOrCreateIdForPoint(source.points[2]));
    mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << source.points[2] << "\n";

    result.mNodes.push_back(mStore.getOrCreateIdForPoint(source.points[3]));
    mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << source.points[3] << "\n";
  }

  result.mNodes.push_back(mStore.getOrCreateIdForPoint(source.points[4]));
  mLog(common::LogLevel::Verbose) << "      " << result.mNodes.back() << " " << source.points[4] << "\n";
  return result;
}

geometry::Polyline2d Intersection::generateBasicPolylineForInterpolation(InternalRoad const &internalRoad,
                                                                         double shiftStart,
                                                                         double shiftEnd) const
{
  // Generate all required points that form the basis for all borders of all lanes (for the given road)
  geometry::Direction2d startDir(mArms[internalRoad.startIndex].orientation);
  geometry::Direction2d orthogonalStartDir = geometry::Direction2d(startDir.orientation - M_PI_2);
  auto startPoint = orthogonalStartDir.movePoint(mStore.point(internalRoad.startPointId), shiftStart);
  auto secondPoint = startDir.movePoint(startPoint, 0.1); // only a reference point

  geometry::Direction2d endDir(mArms[internalRoad.endIndex].orientation);
  geometry::Direction2d orthogonalEndDir = geometry::Direction2d(endDir.orientation + M_PI_2);
  auto endPoint = orthogonalEndDir.movePoint(mStore.point(internalRoad.endPointId), shiftEnd);
  auto secondToLastPoint = endDir.movePoint(endPoint, 0.1); // only a reference point

  // Minimum angle between the arms in the [0, M_PI] domain
  double angleBetweenArms = fmod(fabs(startDir.orientation - endDir.orientation), M_PI);

  geometry::Point2d center;
  geometry::Point2d internalPointA;
  geometry::Point2d internalPointB;

  center = startPoint * 0.5 + endPoint * 0.5;

  // Calculate a new center only if angle between arms is between 5 and 175 degrees
  if (angleBetweenArms > M_PI / 36.0 && angleBetweenArms < 31.0 * M_PI / 36.0)
  {
    // TODO: Move logic to geometry, example: Line2d
    geometry::Point2d p1 = startPoint;
    geometry::Point2d p2 = secondPoint;
    geometry::Point2d p3 = endPoint;
    geometry::Point2d p4 = secondToLastPoint;

    double distanceToStartMargin = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    double distanceToEndMargin = (p4.x - p1.x) * (p3.y - p1.y) - (p4.y - p1.y) * (p3.x - p1.x);

    // A valid intersection point is formed when both distances have the same sign
    if (distanceToStartMargin * distanceToEndMargin >= 0)
    {
      // Calculate intersection point
      auto px_num = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
      auto py_num = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
      auto xy_den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

      center.x = px_num / xy_den;
      center.y = py_num / xy_den;
    }
  }

  // Correct the special case when there is a narrow angle between the lanes

  // The points are located two thirds of the distance between the road ends and the projected center into the lanes.
  double angleCorrection = 2.0 / 3.0;

  // Use the new center to estimate the internal points. This is done by projecting the center into the lanes.
  // internal point A calculation
  geometry::Direction2d startDirToIntersection(startPoint, center);
  double orientationPointA = (startDir.orientation + M_PI) - startDirToIntersection.orientation;
  double startProjection = std::max(std::sqrt(center.squaredDistance(startPoint)) * cos(orientationPointA), 0.0);
  internalPointA = startDir.movePoint(startPoint, -angleCorrection * startProjection);

  geometry::Direction2d endDirToIntersection(endPoint, center);
  double orientationPointB = (endDir.orientation + M_PI) - endDirToIntersection.orientation;
  double endProjection = std::max(std::sqrt(center.squaredDistance(endPoint)) * cos(orientationPointB), 0.0);
  internalPointB = endDir.movePoint(endPoint, -angleCorrection * endProjection);

  geometry::Polyline2d origin;
  origin.points.push_back(startPoint);
  origin.points.push_back(internalPointA);
  origin.points.push_back(center);
  origin.points.push_back(internalPointB);
  origin.points.push_back(endPoint);

  return origin;
}

void Intersection::interpolateInternalRoad(InternalRoad const &internalRoad) const
{
  mLog(common::LogLevel::Verbose) << "Generating geometry for road with id " << internalRoad.roadId << "\n";
  mLog(common::LogLevel::Verbose) << "  Starting at node with id " << internalRoad.startPointId << "  "
                                  << mStore.point(internalRoad.startPointId) << "\n";

  /*
   * Basic idea:
   * Create a polyline that has first, last point + the three required points for bezier interpolation
   * Use this polyline and shift it for all required borders. Use those shifted polylines to apply the
   * bezier approximation
   */
  geometry::Polyline2d origin = generateBasicPolylineForInterpolation(internalRoad);
  auto centerLine = generateBezierInterpolation(origin);
  auto &road = mStore.road(internalRoad.roadId);
  road.mCenterLineId = mStore.addPolyLine(centerLine);
  mLog(common::LogLevel::Verbose) << "  Finalize center line for (id: " << road.mCenterLineId
                                  << ") internal road with node id " << internalRoad.endPointId << "  "
                                  << mStore.point(internalRoad.endPointId) << "\n";

  if (!mFullInterpolation)
  {
    return;
  }

  mLog(common::LogLevel::Verbose) << "  Intersection::generateLanes for road " << road.mId << "\n";
  // forward lanes
  // going from left to right, starting with the center
  if (road.mForwardWidths.size() != road.mForwardWidthsAtEnd.size())
  {
    mLog(common::LogLevel::Error) << "  Number of forward widths start/end do not match! Aborting\n";
    return;
  }

  double movementAtStart = 0.;
  double movementAtEnd = 0.;
  for (uint32_t i = 0u; i < road.mForwardWidths.size(); ++i)
  {
    movementAtStart -= road.mForwardWidths.at(i);
    movementAtEnd -= road.mForwardWidthsAtEnd.at(i);
    geometry::Polyline2d rightPolyLineBase
      = generateBasicPolylineForInterpolation(internalRoad, movementAtStart, movementAtEnd);

    auto rightBorder = generateBezierInterpolation(rightPolyLineBase);
    MapDataId rightBorderId = mStore.addPolyLine(rightBorder);
    mLog(common::LogLevel::Verbose) << "  Generate right border with id: " << rightBorderId << "\n";
    road.addForwardLane(rightBorderId);
  }

  // backward lanes
  // going from right to left ("against backwards direction"), starting with center
  // the order of the points is the same as for forward lanes, if storing lanelets, the order has to be reversed
  if (road.mBackwardWidths.size() != road.mBackwardWidthsAtEnd.size())
  {
    mLog(common::LogLevel::Error) << "  Number of backward widths start/end do not match! Aborting\n";
    return;
  }
  movementAtStart = 0.;
  movementAtEnd = 0.;
  for (uint32_t i = 0u; i < road.mBackwardWidths.size(); ++i)
  {
    movementAtStart += road.mBackwardWidths.at(i);
    movementAtEnd += road.mBackwardWidthsAtEnd.at(i);
    geometry::Polyline2d leftPolyLineBase
      = generateBasicPolylineForInterpolation(internalRoad, movementAtStart, movementAtEnd);
    auto leftBorder = generateBezierInterpolation(leftPolyLineBase);
    MapDataId leftBorderId = mStore.addPolyLine(leftBorder);
    mLog(common::LogLevel::Verbose) << "  Generate left border with id: " << leftBorderId << "\n";
    road.addBackwardLane(leftBorderId);
  }

  road.assignLeftRightLaneNeighbors();
}

MapDataId Intersection::getInternalRoadId(MapDataId const startId, MapDataId const endId) const
{
  for (auto const &internalRoad : mInternalRoads)
  {
    if ((internalRoad.startPointId == endId) && (internalRoad.endPointId == startId))
    {
      return internalRoad.roadId;
    }
  }

  return InvalidId;
}

MapDataId Intersection::getInternalRoadId(MapDataId const pointId) const
{
  for (auto const &internalRoad : mInternalRoads)
  {
    if ((internalRoad.startPointId == pointId) || (internalRoad.endPointId == pointId))
    {
      return internalRoad.roadId;
    }
  }

  return InvalidId;
}

void Intersection::generateInnerData(double interpolationStepSize, bool fullInterpolation)
{
  mBezierInterpolationSteps = interpolationStepSize;
  mFullInterpolation = fullInterpolation;

  mLog(common::LogLevel::Info) << "Generate data for intersection " << mId << " (" << mCenterPointId << ")\n";
  orderArmsByDirection();
  calculateConnectionPoints();
  adjustRoads();
  generateInternalRoads();
  generateInternalGeometry();
}

void Intersection::generateArmData(double interpolationStepSize, bool fullInterpolation)
{
  mBezierInterpolationSteps = interpolationStepSize;
  mFullInterpolation = fullInterpolation;

  mLog(common::LogLevel::Info) << "Adjusting data for intersection " << mId << " (" << mCenterPointId << ")\n";
  orderArmsByDirection();
  calculateConnectionPoints();
}

void Intersection::generateInternalRoadsAndGeometry(double interpolationStepSize, bool fullInterpolation)
{
  mBezierInterpolationSteps = interpolationStepSize;
  mFullInterpolation = fullInterpolation;

  adjustRoads();
  generateInternalRoads();
  generateInternalGeometry();
}

double Intersection::marginForTypeOfRoad(const RoadType &roadType) const
{
  switch (roadType)
  {
    case RoadType::Service:
      return 1.0;
    case RoadType::Residential:
      return 1.0;
    case RoadType::Primary:
    case RoadType::Secondary:
    case RoadType::Tertiary:
    case RoadType::Motorway:
    case RoadType::Trunk:
      return 1.0;
    case RoadType::Link:
      return 3.0;
    case RoadType::Unclassified:
    case RoadType::Invalid:
    default:
      return 1.0;
  }
}

double Intersection::intersectionMargin()
{
  double margin = 10.0;

  for (auto const &arm : mArms)
  {
    if (arm.connectedRoad != InvalidId)
    {
      margin = std::min(margin, marginForTypeOfRoad(mStore.road(arm.connectedRoad).mRoadType));
    }
  }
  return margin;
}

bool Intersection::isRoadEntry(MapDataId roadId) const
{
  for (auto const &arm : mArms)
  {
    if (arm.connectedRoad == roadId)
    {
      return arm.isEntry;
    }
  }
  return false;
}

bool Intersection::isRoadExit(MapDataId roadId) const
{
  for (auto const &arm : mArms)
  {
    if (arm.connectedRoad == roadId)
    {
      return !arm.isEntry;
    }
  }
  return false;
}

MapDataId
Intersection::succPointIdForForwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const
{
  MapDataId internalRoadId = getInternalRoadId(connectionPointId);
  if (internalRoadId == InvalidId)
  {
    return InvalidId;
  }

  auto const &road = mStore.road(internalRoadId);
  auto const &centerLine = mStore.polyLine(road.mCenterLineId);
  bool isStartOfRoad = (centerLine.mNodes.front() == connectionPointId);

  MapDataId borderId = InvalidId;
  if (isStartOfRoad)
  {
    // internal road has same direction as requested (outside/incoming) road, thus use forward lanes, too
    borderId = road.borderIdOfForwardLane(indexOfLane, forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.front();
    }
  }
  else
  {
    // internal road has opposite direction as requested (outside/incoming) road, thus use backward lanes
    borderId = road.borderIdOfBackwardLane(indexOfLane, !forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.back();
    }
  }

  return InvalidId;
}

MapDataId
Intersection::prevPointIdForForwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const
{
  MapDataId internalRoadId = getInternalRoadId(connectionPointId);
  if (internalRoadId == InvalidId)
  {
    return InvalidId;
  }

  auto const &road = mStore.road(internalRoadId);
  auto const &centerLine = mStore.polyLine(road.mCenterLineId);
  bool isStartOfRoad = (centerLine.mNodes.front() == connectionPointId);

  MapDataId borderId = InvalidId;
  if (!isStartOfRoad) // use negated value (compared to succPointIdForForwardLane)
  {
    // internal road has same direction as requested (outside/incoming) road, thus use forward lanes, too
    borderId = road.borderIdOfForwardLane(indexOfLane, forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.back(); // use back() instead of front() (compared to succPointIdForForwardLane)
    }
  }
  else
  {
    // internal road has opposite direction as requested (outside/incoming) road, thus use backward lanes
    borderId = road.borderIdOfBackwardLane(indexOfLane, !forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.front(); // use front() instead of back() (compared to succPointIdForForwardLane)
    }
  }

  return InvalidId;
}

MapDataId
Intersection::prevPointIdForBackwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const
{
  MapDataId internalRoadId = getInternalRoadId(connectionPointId);
  if (internalRoadId == InvalidId)
  {
    return InvalidId;
  }

  auto const &road = mStore.road(internalRoadId);
  auto const &centerLine = mStore.polyLine(road.mCenterLineId);
  bool isStartOfRoad = (centerLine.mNodes.front() == connectionPointId);

  MapDataId borderId = InvalidId;
  if (isStartOfRoad)
  {
    // internal road has same direction as requested (outside/incoming) road, thus use backward lanes, too
    borderId = road.borderIdOfBackwardLane(indexOfLane, forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.front();
    }
  }
  else
  {
    // internal road has opposite direction as requested (outside/incoming) road, thus use forward lanes
    borderId = road.borderIdOfForwardLane(indexOfLane, !forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.back();
    }
  }

  return InvalidId;
}

MapDataId
Intersection::succPointIdForBackwardLane(MapDataId connectionPointId, bool forLeftBorder, uint32_t indexOfLane) const
{
  MapDataId internalRoadId = getInternalRoadId(connectionPointId);
  if (internalRoadId == InvalidId)
  {
    return InvalidId;
  }

  auto const &road = mStore.road(internalRoadId);
  auto const &centerLine = mStore.polyLine(road.mCenterLineId);
  bool isStartOfRoad = (centerLine.mNodes.front() == connectionPointId);

  MapDataId borderId = InvalidId;
  if (!isStartOfRoad)
  {
    // internal road has same direction as requested (outside/incoming) road, thus use backward lanes, too
    borderId = road.borderIdOfBackwardLane(indexOfLane, forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.back();
    }
  }
  else
  {
    // internal road has opposite direction as requested (outside/incoming) road, thus use forward lanes
    borderId = road.borderIdOfForwardLane(indexOfLane, !forLeftBorder);
    if (borderId != InvalidId)
    {
      auto const &borderLine = mStore.polyLine(borderId);
      return borderLine.mNodes.front();
    }
  }

  return InvalidId;
}

bool Intersection::isValidArm(const IntersectionArm &arm)
{
  Road const &road = mStore.road(arm.connectedRoad);
  PolyLine const &polyLine = mStore.polyLine(road.mCenterLineId);

  // For the moment we only check that the polyline of the connected road has enough points
  return (polyLine.mNodes.size() > 1);
}

std::set<MapDataId> Intersection::roadsAtConnectionPoint(MapDataId const connectionPoint) const
{
  std::set<MapDataId> result;
  for (auto const &connection : mInternalRoads)
  {
    if ((connection.startPointId == connectionPoint) || (connection.endPointId == connectionPoint))
    {
      result.insert(connection.roadId);
    }
  }
  return result;
}

int32_t Intersection::indexOfArmForConnectionPoint(MapDataId const connectionPoint) const
{
  for (size_t i = 0u; i < mArms.size(); ++i)
  {
    if (mArms[i].connectionPoint == connectionPoint)
    {
      return static_cast<int32_t>(i);
    }
  }
  return -1;
}

int32_t Intersection::indexOfArmForConnectedRoad(MapDataId const connectedRoadId, bool isEntry) const
{
  for (size_t i = 0u; i < mArms.size(); ++i)
  {
    if ((mArms[i].connectedRoad == connectedRoadId) && (mArms[i].isEntry == isEntry))
    {
      return static_cast<int32_t>(i);
    }
  }
  return -1;
}

std::set<MapDataId> Intersection::roadsConnectedTo(MapDataId const connectedRoadId) const
{
  std::set<MapDataId> result;
  for (auto const &internalRoadId : mRoads)
  {
    if (mStore.hasRoad(internalRoadId)
        && (mStore.road(internalRoadId).mPredecessor == connectedRoadId
            || mStore.road(internalRoadId).mSuccessor == connectedRoadId))
    {
      result.insert(internalRoadId);
    }
  }
  return result;
}

MapDataId Intersection::roadConnectedTo(MapDataId const connectedRoadId) const
{
  for (auto const &internalRoadId : mRoads)
  {
    if (mStore.hasRoad(internalRoadId)
        && ((mStore.road(internalRoadId).mPredecessor == connectedRoadId)
            || (mStore.road(internalRoadId).mSuccessor == connectedRoadId)))
    {
      return internalRoadId;
    }
  }
  return InvalidId;
}

//  Checks if a given road serves as connecting road for the roads roadAId and roadBId
bool connectsRoads(Road const &road, MapDataId const roadAId, MapDataId const roadBId)
{
  return (((road.mPredecessor == roadAId) && (road.mSuccessor == roadBId))
          || ((road.mPredecessor == roadBId) && (road.mSuccessor == roadAId)));
}

std::vector<MapDataId> Intersection::findConnectingRoad(MapDataId const roadAId, MapDataId const roadBId) const
{
  std::vector<MapDataId> connectedRoads;
  for (auto const &internalRoadId : mRoads)
  {
    if (mStore.hasRoad(internalRoadId))
    {
      auto &road = mStore.road(internalRoadId);
      if (connectsRoads(road, roadAId, roadBId))
      {
        connectedRoads.push_back(internalRoadId);
      }
    }
  }
  return connectedRoads;
}

bool Intersection::isCrosswalk() const
{
  if ((mIntersectionType == IntersectionType::CrosswalkZebra)
      || (mIntersectionType == IntersectionType::CrosswalkPelican))
  {
    return true;
  }

  return false;
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
