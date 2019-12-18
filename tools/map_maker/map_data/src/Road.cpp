// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/map_data/Road.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/LogFactory.hpp>
#include <ad/map/maker/geometry/Point2d.hpp>
#include <ad/map/maker/geometry/Polyline2d.hpp>
#include <algorithm>
#include "ad/map/maker/map_data/MapDataStore.hpp"
#include "ad/map/maker/map_data/PolyLineConversion.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

Road::Road(MapDataStore &dataStore, common::LogChannel &logChannel)
  : MapDataElement()
  , mStore(dataStore)
  , mLog(logChannel)
{
}

geometry::Polyline2d Road::centerLineToGeometry() const
{
  mLog(common::LogLevel::Verbose) << "  generate poly2d for center line\n";
  auto const &centerLine = mStore.polyLine(mCenterLineId);
  geometry::Polyline2d result;
  for (auto id : centerLine.mNodes)
  {
    result.points.push_back(mStore.point(id));
    mLog(common::LogLevel::Verbose) << "    polyLineToGeo: " << id << " -> " << mStore.point(id) << "\n";
  }
  return result;
}

uint32_t Road::considerPrevRoad(geometry::Polyline2d &polyLine) const
{
  if (mStore.hasRoad(mPredecessor))
  {
    Road const &pRoad = mStore.road(mPredecessor);
    PolyLine const &pPolyLine = mStore.polyLine(pRoad.mCenterLineId);
    if (pPolyLine.mNodes.size() > 1)
    {
      MapDataId const pointId = pPolyLine.mNodes[pPolyLine.mNodes.size() - 2];
      polyLine.points.insert(polyLine.points.begin(), mStore.point(pointId));
      mLog(common::LogLevel::Verbose) << "considerPrevRoad has prev road. Adding " << mStore.point(pointId) << "\n";
      return 1;
    }
    else
    {
      mLog(common::LogLevel::Error) << "PrevRoad set (roadId: " << mPredecessor
                                    << ") but does not have enough points!\n";
    }
  }

  return 0;
}

uint32_t Road::considerNextRoad(geometry::Polyline2d &polyLine) const
{
  if (mStore.hasRoad(mSuccessor))
  {
    Road const &pRoad = mStore.road(mSuccessor);
    PolyLine const &pPolyLine = mStore.polyLine(pRoad.mCenterLineId);
    if (pPolyLine.mNodes.size() > 1)
    {
      MapDataId const pointId = pPolyLine.mNodes[1];
      polyLine.points.push_back(mStore.point(pointId));
      mLog(common::LogLevel::Verbose) << "considerNextRoad has next road. Adding " << mStore.point(pointId) << "\n";
      return 1;
    }
    else
    {
      mLog(common::LogLevel::Error) << "NextRoad set (roadId: " << mSuccessor << ") but does not have enough points!\n";
    }
  }
  return 0;
}

bool Road::isValid() const
{
  return ((!mForwardLanes.empty() || !mBackwardLanes.empty()) && (mStore.polyLine(mCenterLineId).mNodes.size() > 1));
}

MapDataId Road::generateBorder(geometry::Polyline2d const &geometry,
                               uint32_t startIndex,
                               uint32_t endIndex,
                               MapDataId firstPoint,
                               MapDataId lastPoint) const
{
  if (lastPoint != InvalidId)
  {
    endIndex = 1;
  }
  if (firstPoint != InvalidId)
  {
    startIndex = 1;
  }

  PolyLine result = geometryToPolyline(mStore, geometry, startIndex, endIndex);
  if (firstPoint != InvalidId)
  {
    result.mNodes.insert(result.mNodes.begin(), firstPoint);
    mLog(common::LogLevel::Verbose) << "    using point " << result.mNodes.front()
                                    << " from intersection as first point\n";
  }
  if (lastPoint != InvalidId)
  {
    result.mNodes.push_back(lastPoint);
    mLog(common::LogLevel::Verbose) << "    using point " << result.mNodes.back()
                                    << " from intersection as last point\n";
  }

  return mStore.addPolyLine(result);
}

MapDataId Road::beginOfRightForwardBorder(uint32_t index) const
{
  if (mStore.hasIntersection(mPredecessor))
  {
    auto const &intersection = mStore.intersection(mPredecessor);
    auto const &contactPoint = mStore.polyLine(mCenterLineId).mNodes.front();
    return intersection.prevPointIdForForwardLane(contactPoint, false, index);
  }
  return InvalidId;
}

MapDataId Road::endOfRightForwardBorder(uint32_t index) const
{
  if (mStore.hasIntersection(mSuccessor))
  {
    auto const &intersection = mStore.intersection(mSuccessor);
    auto const &contactPoint = mStore.polyLine(mCenterLineId).mNodes.back();
    return intersection.succPointIdForForwardLane(contactPoint, false, index);
  }
  return InvalidId;
}

MapDataId Road::beginOfLeftBackwardBorder(uint32_t index) const
{
  if (mStore.hasIntersection(mPredecessor))
  {
    auto const &intersection = mStore.intersection(mPredecessor);
    auto const &contactPoint = mStore.polyLine(mCenterLineId).mNodes.front();
    return intersection.succPointIdForBackwardLane(contactPoint, true, index);
  }
  return InvalidId;
}

MapDataId Road::endOfLeftBackwardBorder(uint32_t index) const
{
  if (mStore.hasIntersection(mSuccessor))
  {
    auto const &intersection = mStore.intersection(mSuccessor);
    auto const &contactPoint = mStore.polyLine(mCenterLineId).mNodes.back();
    return intersection.prevPointIdForBackwardLane(contactPoint, true, index);
  }
  return InvalidId;
}

void Road::generateLanes()
{
  // Check wether this road was already generated
  if (isValid())
  {
    return;
  }

  // Lanes have not been generated, check that the center polyline has at least two points
  if (mStore.polyLine(mCenterLineId).mNodes.size() < 2)
  {
    mLog(common::LogLevel::Info) << "Ignoring empty road: " << mCenterLineId << "\n";
    return;
  }

  mLog(common::LogLevel::Verbose) << "generateLanes for road " << mId << " with center: " << mCenterLineId << "\n";

  geometry::Polyline2d centerPolyline = centerLineToGeometry();
  uint32_t start = considerPrevRoad(centerPolyline);
  uint32_t end = considerNextRoad(centerPolyline);

  // forward lanes, going from left to right, starting with the center
  double width = 0.;
  for (uint32_t w = 0u; w < mForwardWidths.size(); ++w)
  {
    width -= mForwardWidths[w];
    geometry::Polyline2d rightPolyLine;
    if (!centerPolyline.shift(width, rightPolyLine, mLog))
    {
      mLog(common::LogLevel::Warning) << "Wrong shifted border for forward lane (index: " << w << ")\n";
    }
    MapDataId firstPoint = beginOfRightForwardBorder(w);
    MapDataId lastPoint = endOfRightForwardBorder(w);
    MapDataId rightBorderId = generateBorder(rightPolyLine, start, end, firstPoint, lastPoint);
    mLog(common::LogLevel::Verbose) << "  Created right border with id " << rightBorderId << "\n";
    addForwardLane(rightBorderId);
  }

  // backward lanes, going from right to left ("against forward direction"), starting with center
  // the order of the points is the same as for forward lanes, if storing lanelets, the order has to be reversed
  width = 0.;
  for (uint32_t w = 0u; w < mBackwardWidths.size(); ++w)
  {
    width += mBackwardWidths[w];
    geometry::Polyline2d leftPolyLine;
    if (!centerPolyline.shift(width, leftPolyLine, mLog))
    {
      mLog(common::LogLevel::Warning) << "Wrong shifted border for backward lane (index: " << w << ")\n";
    }
    MapDataId firstPoint = beginOfLeftBackwardBorder(w);
    MapDataId lastPoint = endOfLeftBackwardBorder(w);
    MapDataId leftBorderId = generateBorder(leftPolyLine, start, end, firstPoint, lastPoint);
    mLog(common::LogLevel::Verbose) << "  Created left border with id " << leftBorderId << "\n";
    addBackwardLane(leftBorderId);
  }

  assignLeftRightLaneNeighbors();
}

void Road::invertRoadDirection()
{
  std::set<MapDataId> polylineIds;

  for (auto &laneId : mCreatedLanes)
  {
    auto &lane = mStore.lane(laneId);
    lane.invertLaneDirection(mStore, false);
    polylineIds.insert(lane.rightBorder);
    polylineIds.insert(lane.leftBorder);
  }

  polylineIds.insert(mCenterLineId);

  for (auto &polylineId : polylineIds)
  {
    auto &polyline = mStore.polyLine(polylineId);
    std::reverse(polyline.mNodes.begin(), polyline.mNodes.end());
  }

  std::swap(mPredecessor, mSuccessor);
  std::swap(mForwardWidths, mBackwardWidthsAtEnd);
  std::swap(mBackwardWidths, mForwardWidthsAtEnd);
  std::swap(mForwardLanes, mBackwardLanes);
  std::swap(mForwardTurnDirections, mBackwardTurnDirections);
  std::reverse(mCreatedLanes.begin(), mCreatedLanes.end());
}

void Road::convertToLeftHandTraffic()
{
  for (auto &laneId : mCreatedLanes)
  {
    auto &lane = mStore.lane(laneId);
    if (lane.drivingDirection == DrivingDirection::Forward)
    {
      lane.drivingDirection = DrivingDirection::Backward;
    }
    else if (lane.drivingDirection == DrivingDirection::Backward)
    {
      lane.drivingDirection = DrivingDirection::Forward;
    }
  }

  std::swap(mForwardWidths, mBackwardWidths);
  std::swap(mBackwardWidths, mForwardWidths);
  std::swap(mForwardLanes, mBackwardLanes);
  std::swap(mForwardTurnDirections, mBackwardTurnDirections);
  std::reverse(mCreatedLanes.begin(), mCreatedLanes.end());
}

DrivingDirection Road::calculateDrivingDirection(DrivingDirection nominalDrivingDirection) const
{
  DrivingDirection drivingDirection = nominalDrivingDirection;
  if (mForwardWidths.size() + mBackwardWidths.size() == 1)
  {
    if (mRoadType == RoadType::Service)
    {
      // single lane service roads become bidirectional
      drivingDirection = DrivingDirection::Bidirectional;
    }
  }
  return drivingDirection;
}

void Road::addForwardLane(MapDataId rightBorderId)
{
  MapDataId leftBorderId = mCenterLineId;
  if (mForwardLanes.size() > 0)
  {
    leftBorderId = mStore.lane(mForwardLanes.back()).rightBorder;
  }
  Lane lane(mId, leftBorderId, rightBorderId, calculateDrivingDirection(DrivingDirection::Forward));
  MapDataId laneId = mStore.addLane(lane);
  mForwardLanes.push_back(laneId);
  mCreatedLanes.push_back(laneId);
}

void Road::addBackwardLane(MapDataId leftBorderId)
{
  MapDataId rightBorderId = mCenterLineId;
  if (mBackwardLanes.size() > 0)
  {
    rightBorderId = mStore.lane(mBackwardLanes.back()).leftBorder;
  }
  Lane lane(mId, leftBorderId, rightBorderId, calculateDrivingDirection(DrivingDirection::Backward));
  MapDataId laneId = mStore.addLane(lane);
  mBackwardLanes.push_back(laneId);
  mCreatedLanes.insert(mCreatedLanes.begin(), laneId);
}

void Road::assignLeftRightLaneNeighbors() const
{
  for (uint32_t k = 1; k < mCreatedLanes.size(); k++)
  {
    auto leftId = mCreatedLanes[k - 1];
    auto rightId = mCreatedLanes[k];
    mStore.lane(leftId).rightNeighbor = rightId;
    mStore.lane(rightId).leftNeighbor = leftId;
  }
}

double Road::forwardWidth() const
{
  double res = 0.;
  for (double w : mForwardWidths)
  {
    res += w;
  }
  return res;
}

double Road::backwardWidth() const
{
  double res = 0.;
  for (double w : mBackwardWidths)
  {
    res += w;
  }
  return res;
}

MapDataId Road::borderIdOfForwardLane(uint64_t index, bool returnLeft) const
{
  if (index < mForwardLanes.size())
  {
    auto const &lane = mStore.lane(mForwardLanes.at(index));
    if (returnLeft)
    {
      return lane.leftBorder;
    }
    else
    {
      return lane.rightBorder;
    }
  }
  return InvalidId;
}

MapDataId Road::borderIdOfBackwardLane(uint64_t index, bool returnLeft) const
{
  if (index < mBackwardLanes.size())
  {
    auto const &lane = mStore.lane(mBackwardLanes.at(index));
    if (returnLeft)
    {
      return lane.leftBorder;
    }
    else
    {
      return lane.rightBorder;
    }
  }
  return InvalidId;
}

void Road::assignLanesForRoad(MapDataId const otherId, bool otherIsSuccessor) const
{
  auto const &otherRoad = mStore.road(otherId);

  bool connectRoadsOfDifferentWidth{true}; // TODO: Make it a parameter?
  bool roadConnected{false};

  for (auto const &thisLaneId : mCreatedLanes)
  {
    auto &thisLane = mStore.lane(thisLaneId);
    auto const &thisLeftConnect = otherIsSuccessor ? mStore.polyLine(thisLane.leftBorder).mNodes.back()
                                                   : mStore.polyLine(thisLane.rightBorder).mNodes.front();
    auto const &thisRightConnect = otherIsSuccessor ? mStore.polyLine(thisLane.rightBorder).mNodes.back()
                                                    : mStore.polyLine(thisLane.leftBorder).mNodes.front();

    for (auto const &otherLaneId : otherRoad.mCreatedLanes)
    {
      auto &otherLane = mStore.lane(otherLaneId);
      auto const &otherLeftBackConnect = mStore.polyLine(otherLane.rightBorder).mNodes.back();
      auto const &otherRightBackConnect = mStore.polyLine(otherLane.leftBorder).mNodes.back();

      auto const &otherLeftFrontConnect = mStore.polyLine(otherLane.leftBorder).mNodes.front();
      auto const &otherRightFrontConnect = mStore.polyLine(otherLane.rightBorder).mNodes.front();

      if ((thisLeftConnect == otherLeftBackConnect && thisRightConnect == otherRightBackConnect)
          || (thisLeftConnect == otherLeftFrontConnect && thisRightConnect == otherRightFrontConnect))
      {
        if (otherIsSuccessor)
        {
          thisLane.successors.push_back(otherLaneId);
          roadConnected = true;
        }
        else
        {
          thisLane.predecessors.push_back(otherLaneId);
          roadConnected = true;
        }
      }
    }
  }

  if (!roadConnected && connectRoadsOfDifferentWidth)
  {
    // could this be a lane connection between two roads with different width size?
    // fallback to check if any of the line edges are connected
    for (auto const &thisLaneId : mCreatedLanes)
    {
      auto &thisLane = mStore.lane(thisLaneId);
      auto const &thisLeftConnect = otherIsSuccessor ? mStore.polyLine(thisLane.leftBorder).mNodes.back()
                                                     : mStore.polyLine(thisLane.rightBorder).mNodes.front();
      auto const &thisRightConnect = otherIsSuccessor ? mStore.polyLine(thisLane.rightBorder).mNodes.back()
                                                      : mStore.polyLine(thisLane.leftBorder).mNodes.front();

      for (auto const &otherLaneId : otherRoad.mCreatedLanes)
      {
        auto &otherLane = mStore.lane(otherLaneId);
        auto const &otherLeftBackConnect = mStore.polyLine(otherLane.rightBorder).mNodes.back();
        auto const &otherRightBackConnect = mStore.polyLine(otherLane.leftBorder).mNodes.back();

        auto const &otherLeftFrontConnect = mStore.polyLine(otherLane.leftBorder).mNodes.front();
        auto const &otherRightFrontConnect = mStore.polyLine(otherLane.rightBorder).mNodes.front();

        if ((thisLeftConnect == otherLeftBackConnect || thisRightConnect == otherRightBackConnect)
            || (thisLeftConnect == otherLeftFrontConnect || thisRightConnect == otherRightFrontConnect))
        {
          if (otherIsSuccessor)
          {
            thisLane.successors.push_back(otherLaneId);
            roadConnected = true;
          }
          else
          {
            thisLane.predecessors.push_back(otherLaneId);
            roadConnected = true;
          }
        }
      }
    }
  }
}

void Road::assignSuccPredLaneNeighbors() const
{
  // handle successor
  if (mStore.hasRoad(mSuccessor))
  {
    assignLanesForRoad(mSuccessor, true);
  }
  else if (mStore.hasIntersection(mSuccessor))
  {
    auto intersectionRoads = mStore.intersection(mSuccessor).roadsConnectedTo(mId);
    for (auto const roadId : intersectionRoads)
    {
      assignLanesForRoad(roadId, true);
    }
  }
  else
  {
    if (mSuccessor != InvalidId)
    {
      mLog(common::LogLevel::Warning) << "Road " << mId << " has invalid successor: " << mSuccessor << "\n";
    }
  }

  // handle predecessor
  if (mStore.hasRoad(mPredecessor))
  {
    assignLanesForRoad(mPredecessor, false);
  }
  else if (mStore.hasIntersection(mPredecessor))
  {
    auto intersectionRoads = mStore.intersection(mPredecessor).roadsConnectedTo(mId);
    for (auto const roadId : intersectionRoads)
    {
      assignLanesForRoad(roadId, false);
    }
  }
  else
  {
    if (mPredecessor != InvalidId)
    {
      mLog(common::LogLevel::Warning) << "Road " << mId << " has invalid predecessor: " << mSuccessor << "\n";
    }
  }

  if ((mRoadType == RoadType::Intersection) && (mCreatedLanes.size() == 1u))
  {
    auto &lane = mStore.lane(mCreatedLanes[0]);
    if ((lane.successors.size() == 1u) && (lane.predecessors.size() == 1u))
    {
      auto const &successor = mStore.lane(lane.successors[0]);
      auto const &predecessor = mStore.lane(lane.predecessors[0]);
      if ((successor.drivingDirection == DrivingDirection::Bidirectional)
          && (predecessor.drivingDirection == DrivingDirection::Bidirectional))
      {
        lane.drivingDirection = DrivingDirection::Bidirectional;
      }
    }
  }
}

// Intersects all the polylines contained in this road
bool Road::fullyIntersects(geometry::Line2d const &line) const
{
  for (auto const &laneId : mCreatedLanes)
  {
    auto const &leftBorder = mStore.polyLine(mStore.lane(laneId).leftBorder);
    auto const &rightBorder = mStore.polyLine(mStore.lane(laneId).rightBorder);
    geometry::Polyline2d leftBorderGeometry = polylineToGeometry(mStore, leftBorder);
    geometry::Polyline2d rightBorderGeometry = polylineToGeometry(mStore, rightBorder);

    if (!leftBorderGeometry.intersectsWithLine(line))
    {
      return false;
    }
    if (!rightBorderGeometry.intersectsWithLine(line))
    {
      return false;
    }
  }

  return true;
}

// warning, destructive operation
bool Road::crop(geometry::Line2d const &line, bool reverse)
{
  if (!fullyIntersects(line))
  {
    return false;
  }

  auto const &centerLine = mStore.polyLine(mCenterLineId);
  geometry::Polyline2d centerLineGeometry = polylineToGeometry(mStore, centerLine);
  geometry::Polyline2d newCenterLineGeometry;
  geometry::Polyline2d remainingCenterLineGeometry;

  if (reverse)
  {
    centerLineGeometry.splitPolyline(remainingCenterLineGeometry, newCenterLineGeometry, line);
  }
  else
  {
    centerLineGeometry.splitPolyline(newCenterLineGeometry, remainingCenterLineGeometry, line);
  }

  PolyLine newCenterLine = geometryToPolyline(mStore, newCenterLineGeometry);
  auto newCenterLineId = mStore.addPolyLine(newCenterLine);
  mStore.road(mId).mCenterLineId = newCenterLineId;
  mCenterLineId = newCenterLineId;

  // The upcoming operations are done directly on the store to avoid issues.

  for (auto const &laneId : mCreatedLanes)
  {
    auto const &leftBorder = mStore.polyLine(mStore.lane(laneId).leftBorder);
    auto const &rightBorder = mStore.polyLine(mStore.lane(laneId).rightBorder);
    geometry::Polyline2d leftBorderGeometry = polylineToGeometry(mStore, leftBorder);
    geometry::Polyline2d rightBorderGeometry = polylineToGeometry(mStore, rightBorder);

    geometry::Polyline2d newLeftBorderGeometry;
    geometry::Polyline2d newRightBorderGeometry;
    geometry::Polyline2d remainingGeometry;

    if (reverse)
    {
      leftBorderGeometry.splitPolyline(remainingGeometry, newLeftBorderGeometry, line);
      rightBorderGeometry.splitPolyline(remainingGeometry, newRightBorderGeometry, line);
    }
    else
    {
      leftBorderGeometry.splitPolyline(newLeftBorderGeometry, remainingGeometry, line);
      rightBorderGeometry.splitPolyline(newRightBorderGeometry, remainingGeometry, line);
    }

    PolyLine newLeftBorder = geometryToPolyline(mStore, newLeftBorderGeometry);
    PolyLine newRightBorder = geometryToPolyline(mStore, newRightBorderGeometry);

    auto newLeftBorderId = mStore.addPolyLine(newLeftBorder);
    auto newRightBorderId = mStore.addPolyLine(newRightBorder);

    mStore.lane(laneId).leftBorder = newLeftBorderId;
    mStore.lane(laneId).rightBorder = newRightBorderId;
  }

  return true;
}

// warning, destructive operation
MapDataId Road::split(geometry::Line2d const &line, bool reverse)
{
  if (!fullyIntersects(line))
  {
    return InvalidId;
  }

  auto const &centerLine = mStore.polyLine(mCenterLineId);
  geometry::Polyline2d centerLineGeometry = polylineToGeometry(mStore, centerLine);

  geometry::Polyline2d newCenterLineGeometry;
  geometry::Polyline2d remainingCenterLineGeometry;

  if (reverse)
  {
    centerLineGeometry.splitPolyline(remainingCenterLineGeometry, newCenterLineGeometry, line);
  }
  else
  {
    centerLineGeometry.splitPolyline(newCenterLineGeometry, remainingCenterLineGeometry, line);
  }

  auto newRoadId = mStore.addRoad(Road(mStore, mLog));
  auto &newRoad = mStore.road(newRoadId);
  PolyLine newRoadCenterLine = geometryToPolyline(mStore, remainingCenterLineGeometry);
  auto newRoadCenterLineId = mStore.addPolyLine(newRoadCenterLine);
  newRoad.mCenterLineId = newRoadCenterLineId;
  newRoad.mForwardWidths = mForwardWidths; // @TODO: widths would need to be interpolated
  newRoad.mForwardWidthsAtEnd = mForwardWidthsAtEnd;
  newRoad.mBackwardWidths = mBackwardWidths;
  newRoad.mBackwardWidthsAtEnd = mBackwardWidthsAtEnd;
  newRoad.generateLanes();

  PolyLine newCenterLine = geometryToPolyline(mStore, newCenterLineGeometry);
  auto newCenterLineId = mStore.addPolyLine(newCenterLine);
  mStore.road(mId).mCenterLineId = newCenterLineId;
  mCenterLineId = newCenterLineId;
  // weird ability of the method to edit other lanes but not itself, so to guarantee
  // the edition is better to edit it via the store

  for (auto const &laneId : mCreatedLanes)
  {
    auto const &leftBorder = mStore.polyLine(mStore.lane(laneId).leftBorder);
    auto const &rightBorder = mStore.polyLine(mStore.lane(laneId).rightBorder);
    geometry::Polyline2d leftBorderGeometry = polylineToGeometry(mStore, leftBorder);
    geometry::Polyline2d rightBorderGeometry = polylineToGeometry(mStore, rightBorder);

    geometry::Polyline2d newLeftBorderGeometry;
    geometry::Polyline2d newRightBorderGeometry;
    geometry::Polyline2d remainingGeometry;

    if (reverse)
    {
      leftBorderGeometry.splitPolyline(remainingGeometry, newLeftBorderGeometry, line);
      rightBorderGeometry.splitPolyline(remainingGeometry, newRightBorderGeometry, line);
    }
    else
    {
      leftBorderGeometry.splitPolyline(newLeftBorderGeometry, remainingGeometry, line);
      rightBorderGeometry.splitPolyline(newRightBorderGeometry, remainingGeometry, line);
    }

    PolyLine newLeftBorder = geometryToPolyline(mStore, newLeftBorderGeometry);
    PolyLine newRightBorder = geometryToPolyline(mStore, newRightBorderGeometry);

    auto newLeftBorderId = mStore.addPolyLine(newLeftBorder);
    auto newRightBorderId = mStore.addPolyLine(newRightBorder);

    mStore.lane(laneId).leftBorder = newLeftBorderId;
    mStore.lane(laneId).rightBorder = newRightBorderId;
  }

  return newRoadId;
}

geometry::Point2d Road::findNearestPoint(geometry::Point2d const &point) const
{
  if (!isValid() || mCreatedLanes.size() == 0)
  {
    return geometry::Point2d{0.0, 0.0};
  }

  auto nearestPoint = mStore.lane(mCreatedLanes[0]).findNearestPoint(mStore, point);
  auto nearestDistance = point.squaredDistance(nearestPoint);

  for (uint32_t k = 1; k < mCreatedLanes.size(); k++)
  {
    auto projectedPoint = mStore.lane(mCreatedLanes[k]).findNearestPoint(mStore, point);
    auto distance = point.squaredDistance(projectedPoint);
    if (distance < nearestDistance)
    {
      nearestDistance = distance;
      nearestPoint = projectedPoint;
    }
  }

  return nearestPoint;
}

std::size_t indexOfPoint(MapDataId pointId, std::vector<MapDataId> const &points)
{
  for (std::size_t index = 0u; index < points.size(); ++index)
  {
    if (points[index] == pointId)
    {
      return index;
    }
  }
  throw std::runtime_error("Unable to locate point " + std::to_string(pointId) + " in centerline");
}

geometry::Direction2d Road::shiftingDirectionAtPoint(MapDataId pointId) const
{
  auto centerline = mStore.polyLine(mCenterLineId).mNodes;
  auto pos = indexOfPoint(pointId, centerline);
  // at the beginning
  if (pos == 0)
  {
    // option 1: we have a predecessor
    if (mStore.hasRoad(mPredecessor))
    {
      if (mStore.road(mPredecessor).mCenterLineId == InvalidId)
      {
        throw std::runtime_error("Predecessor has no center line");
      }
      auto const &otherline = mStore.polyLine(mStore.road(mPredecessor).mCenterLineId).mNodes;
      auto const &before = otherline[otherline.size() - 2];
      return geometry::bisectionAngle(
        mStore.point(before), mStore.point(centerline[pos]), mStore.point(centerline[pos + 1]));
    }
    else
    {
      return geometry::orthogonalDirection(mStore.point(centerline[pos]), mStore.point(centerline[pos + 1]));
    }
  }
  // in between
  else if (pos < centerline.size() - 1)
  {
    return geometry::bisectionAngle(
      mStore.point(centerline[pos - 1]), mStore.point(centerline[pos]), mStore.point(centerline[pos + 1]));
  }
  // at the end
  else if (pos == centerline.size() - 1)
  {
    if (mStore.hasRoad(mSuccessor))
    {
      if (mStore.road(mSuccessor).mCenterLineId == InvalidId)
      {
        throw std::runtime_error("Successor has no center line");
      }
      auto const &otherline = mStore.polyLine(mStore.road(mSuccessor).mCenterLineId).mNodes;
      auto const &after = otherline[1];
      return geometry::bisectionAngle(
        mStore.point(centerline[pos - 1]), mStore.point(centerline[pos]), mStore.point(after));
    }
    else
    {
      return geometry::orthogonalDirection(mStore.point(centerline[pos - 1]), mStore.point(centerline[pos]));
    }
  }
  // no else intended here

  return geometry::Direction2d(0.);
}

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
