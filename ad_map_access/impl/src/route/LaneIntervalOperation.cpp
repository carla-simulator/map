// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/LaneIntervalOperation.hpp"

#include <algorithm>
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace route {

point::ParaPoint getRouteIntervalStart(LaneInterval const &laneInterval)
{
  point::ParaPoint startPoint;
  if (route::isRouteDirectionPositive(laneInterval))
  {
    startPoint.parametricOffset = laneInterval.start;
  }
  else
  {
    startPoint.parametricOffset = laneInterval.end;
  }

  startPoint.laneId = laneInterval.laneId;

  return startPoint;
}

point::ParaPoint getRouteIntervalEnd(LaneInterval const &laneInterval)
{
  point::ParaPoint endPoint;
  if (route::isRouteDirectionPositive(laneInterval))
  {
    endPoint.parametricOffset = laneInterval.end;
  }
  else
  {
    endPoint.parametricOffset = laneInterval.start;
  }

  endPoint.laneId = laneInterval.laneId;

  return endPoint;
}

point::ParaPoint getIntervalStart(FullRoute const &route, lane::LaneId const &laneId)
{
  point::ParaPoint result;
  for (auto const &roadSegment : route.roadSegments)
  {
    auto it = find_if(roadSegment.drivableLaneSegments.begin(),
                      roadSegment.drivableLaneSegments.end(),
                      [&laneId](const LaneSegment &l) { return l.laneInterval.laneId == laneId; });

    if (it != roadSegment.drivableLaneSegments.end())
    {
      result.laneId = laneId;
      result.parametricOffset = it->laneInterval.start;
      return result;
    }
  }

  throw std::invalid_argument("ad::map::route::getIntervalStart: laneId not found in route");
}

physics::ParametricValue
getSignedDistance(LaneInterval const &laneInterval, point::ParaPoint const &first, point::ParaPoint const &second)
{
  if ((first.laneId != second.laneId) || (first.laneId != laneInterval.laneId))
  {
    throw std::invalid_argument("ad::map::route::getSignedDistance: lane id's not matching");
  }

  if (isRouteDirectionPositive(laneInterval))
  {
    return second.parametricOffset - first.parametricOffset;
  }
  else
  {
    return first.parametricOffset - second.parametricOffset;
  }
}

physics::ParametricValue
getUnsignedDistance(LaneInterval const &laneInterval, point::ParaPoint const &first, point::ParaPoint const &second)
{
  if ((first.laneId != second.laneId) || (first.laneId != laneInterval.laneId))
  {
    throw std::invalid_argument("ad::map::route::getSignedDistance: lane id's not matching");
  }
  return std::fabs(first.parametricOffset - second.parametricOffset);
}

physics::ParametricValue getProjectedParametricOffsetOnNeighborLane(LaneInterval const &currentInterval,
                                                                    LaneInterval const &neighborInterval,
                                                                    physics::ParametricValue const &parametricOffset)
{
  if (!lane::isSameOrDirectNeighbor(currentInterval.laneId, neighborInterval.laneId))
  {
    throw std::invalid_argument("ad::map::route::getProjectedParametricOffsetOnNeighborLane: lanes are not neighbors");
  }

  if (currentInterval.laneId == neighborInterval.laneId)
  {
    return parametricOffset;
  }

  // real neighbors
  auto currentLane = lane::getLane(currentInterval.laneId);
  auto neighborLane = lane::getLane(neighborInterval.laneId);
  auto leftNeighbors = lane::getContactLanes(currentLane, lane::ContactLocation::LEFT);
  auto rightNeighbors = lane::getContactLanes(currentLane, lane::ContactLocation::RIGHT);

  point::ECEFPoint leftECEFPoint;
  point::ECEFPoint rightECEFPoint;
  physics::ParametricValue offset;
  lane::projectParametricPointToEdges(currentLane, parametricOffset, leftECEFPoint, rightECEFPoint);

  if ((leftNeighbors.size() > 0) && (leftNeighbors[0].toLane == neighborInterval.laneId))
  {
    offset = ((point::findNearestPointOnEdge(neighborLane.edgeRight, leftECEFPoint)
               + point::findNearestPointOnEdge(neighborLane.edgeLeft, leftECEFPoint))
              / 2.);
  }
  else if ((rightNeighbors.size() > 0) && (rightNeighbors[0].toLane == neighborInterval.laneId))
  {
    offset = ((point::findNearestPointOnEdge(neighborLane.edgeRight, rightECEFPoint)
               + point::findNearestPointOnEdge(neighborLane.edgeLeft, rightECEFPoint))
              / 2.);
  }
  else
  {
    throw std::invalid_argument("ad::map::route::getProjectedParametricOffsetOnNeighborLane: lanes are not neighbors");
  }

  return offset;
}

physics::Distance calcLength(LaneInterval const &laneInterval)
{
  auto currentLane = lane::getLane(laneInterval.laneId);
  auto const resultDistance = currentLane.length * calcParametricLength(laneInterval);
  return resultDistance;
}

physics::Duration calcDuration(LaneInterval const &laneInterval)
{
  auto currentLane = lane::getLane(laneInterval.laneId);
  return lane::getDuration(currentLane, toParametricRange(laneInterval));
}

enum class EdgeType
{
  LEFT,
  RIGHT
};

template <typename LaneEdge> void getEdge(LaneInterval const &laneInterval, EdgeType edgeType, LaneEdge &outputEdge)
{
  auto currentLane = lane::getLane(laneInterval.laneId);

  auto range = toParametricRange(laneInterval);

  if (isRouteDirectionPositive(laneInterval))
  {
    if (edgeType == EdgeType::LEFT)
    {
      point::getParametricRange(currentLane.edgeLeft, range, outputEdge, false);
    }
    else if (edgeType == EdgeType::RIGHT)
    {
      point::getParametricRange(currentLane.edgeRight, range, outputEdge, false);
    }
  }
  else
  {
    if (edgeType == EdgeType::LEFT)
    {
      point::getParametricRange(currentLane.edgeRight, range, outputEdge, true);
    }
    else if (edgeType == EdgeType::RIGHT)
    {
      point::getParametricRange(currentLane.edgeLeft, range, outputEdge, true);
    }
  }
}

void getLeftEdge(LaneInterval const &laneInterval, point::ENUEdge &enuEdge)
{
  getEdge(laneInterval, EdgeType::LEFT, enuEdge);
}

void getRightEdge(LaneInterval const &laneInterval, point::ENUEdge &enuEdge)
{
  getEdge(laneInterval, EdgeType::RIGHT, enuEdge);
}

void getLeftEdge(LaneInterval const &laneInterval, point::GeoEdge &geoEdge)
{
  getEdge(laneInterval, EdgeType::LEFT, geoEdge);
}

void getRightEdge(LaneInterval const &laneInterval, point::GeoEdge &geoEdge)
{
  getEdge(laneInterval, EdgeType::RIGHT, geoEdge);
}

void getLeftEdge(LaneInterval const &laneInterval, point::ECEFEdge &ecefEdge)
{
  getEdge(laneInterval, EdgeType::LEFT, ecefEdge);
}

void getRightEdge(LaneInterval const &laneInterval, point::ECEFEdge &ecefEdge)
{
  getEdge(laneInterval, EdgeType::RIGHT, ecefEdge);
}

point::ENUEdge getRightENUEdge(LaneInterval const &laneInterval)
{
  point::ENUEdge enuEdge;
  getRightEdge(laneInterval, enuEdge);
  return enuEdge;
}

point::ECEFEdge getRightECEFEdge(LaneInterval const &laneInterval)
{
  point::ECEFEdge ecefEdge;
  getRightEdge(laneInterval, ecefEdge);
  return ecefEdge;
}

point::GeoEdge getRightGeoEdge(LaneInterval const &laneInterval)
{
  point::GeoEdge geoEdge;
  getRightEdge(laneInterval, geoEdge);
  return geoEdge;
}

point::ENUEdge getLeftENUEdge(LaneInterval const &laneInterval)
{
  point::ENUEdge enuEdge;
  getLeftEdge(laneInterval, enuEdge);
  return enuEdge;
}

point::ECEFEdge getLeftECEFEdge(LaneInterval const &laneInterval)
{
  point::ECEFEdge ecefEdge;
  getLeftEdge(laneInterval, ecefEdge);
  return ecefEdge;
}

point::GeoEdge getLeftGeoEdge(LaneInterval const &laneInterval)
{
  point::GeoEdge geoEdge;
  getLeftEdge(laneInterval, geoEdge);
  return geoEdge;
}

point::ENUEdge getLeftProjectedENUEdge(LaneInterval const &laneInterval)
{
  point::ENUEdge enuEdge;
  auto leftInterval = laneInterval;
  auto lane = lane::getLane(laneInterval.laneId);

  const auto startOffset = laneInterval.start;
  const auto endOffset = laneInterval.end;
  if (isRouteDirectionPositive(laneInterval))
  {
    leftInterval.start = point::findNearestPointOnEdge(
      lane.edgeLeft, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(0.)));
    leftInterval.end = point::findNearestPointOnEdge(
      lane.edgeLeft, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(0.)));
  }
  else
  {
    leftInterval.start = point::findNearestPointOnEdge(
      lane.edgeRight, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(1.)));
    leftInterval.end = point::findNearestPointOnEdge(
      lane.edgeRight, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(1.)));
  }
  if (isDegenerated(leftInterval))
  {
    leftInterval = laneInterval;
  }

  getLeftEdge(leftInterval, enuEdge);
  return enuEdge;
}

point::ENUEdge getRightProjectedENUEdge(LaneInterval const &laneInterval)
{
  point::ENUEdge enuEdge;
  auto rightInterval = laneInterval;
  auto lane = lane::getLane(laneInterval.laneId);

  const auto startOffset = laneInterval.start;
  const auto endOffset = laneInterval.end;
  if (isRouteDirectionPositive(laneInterval))
  {
    rightInterval.start = point::findNearestPointOnEdge(
      lane.edgeRight, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(1.)));
    rightInterval.end = point::findNearestPointOnEdge(
      lane.edgeRight, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(1.)));
  }
  else
  {
    rightInterval.start = point::findNearestPointOnEdge(
      lane.edgeLeft, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(0.)));
    rightInterval.end = point::findNearestPointOnEdge(
      lane.edgeLeft, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(0.)));
  }
  if (isDegenerated(rightInterval))
  {
    rightInterval = laneInterval;
  }
  getRightEdge(rightInterval, enuEdge);
  return enuEdge;
}

lane::GeoBorder getGeoBorder(LaneInterval const &laneInterval)
{
  lane::GeoBorder geoBorder;
  getLeftEdge(laneInterval, geoBorder.left);
  getRightEdge(laneInterval, geoBorder.right);
  return geoBorder;
}

lane::ECEFBorder getECEFBorder(LaneInterval const &laneInterval)
{
  lane::ECEFBorder ecefBorder;
  getLeftEdge(laneInterval, ecefBorder.left);
  getRightEdge(laneInterval, ecefBorder.right);
  return ecefBorder;
}

lane::ENUBorder getENUBorder(LaneInterval const &laneInterval)
{
  lane::ENUBorder enuBorder;
  getLeftEdge(laneInterval, enuBorder.left);
  getRightEdge(laneInterval, enuBorder.right);
  return enuBorder;
}

lane::ENUBorder getENUProjectedBorder(LaneInterval const &laneInterval)
{
  lane::ENUBorder enuBorder;
  auto leftInterval = laneInterval;
  auto rightInterval = laneInterval;

  auto lane = lane::getLane(laneInterval.laneId);

  const auto startOffset = laneInterval.start;
  const auto endOffset = laneInterval.end;

  // if the lane interval is longer than 0.5 meters, perform projection
  if (calcLength(laneInterval) > physics::Distance(0.5))
  {
    if (isRouteDirectionPositive(laneInterval))
    {
      leftInterval.start = point::findNearestPointOnEdge(
        lane.edgeLeft, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(0.)));
      rightInterval.start = point::findNearestPointOnEdge(
        lane.edgeRight, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(1.)));
      leftInterval.end = point::findNearestPointOnEdge(
        lane.edgeLeft, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(0.)));
      rightInterval.end = point::findNearestPointOnEdge(
        lane.edgeRight, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(1.)));
    }
    else
    {
      leftInterval.start = point::findNearestPointOnEdge(
        lane.edgeRight, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(1.)));
      rightInterval.start = point::findNearestPointOnEdge(
        lane.edgeLeft, lane::getProjectedParametricPoint(lane, startOffset, physics::ParametricValue(0.)));
      leftInterval.end = point::findNearestPointOnEdge(
        lane.edgeRight, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(1.)));
      rightInterval.end = point::findNearestPointOnEdge(
        lane.edgeLeft, lane::getProjectedParametricPoint(lane, endOffset, physics::ParametricValue(0.)));
    }
  }

  getLeftEdge(leftInterval, enuBorder.left);
  getRightEdge(rightInterval, enuBorder.right);
  return enuBorder;
}

LaneInterval shortenIntervalFromBegin(LaneInterval const &laneInterval, physics::Distance const &distance)
{
  LaneInterval result = laneInterval;
  physics::ParametricValue delta(distance / lane::calcLength(laneInterval.laneId));
  if (isRouteDirectionPositive(laneInterval))
  {
    result.start = std::min(laneInterval.start + delta, laneInterval.end);
  }
  else
  {
    result.start = std::max(laneInterval.start - delta, laneInterval.end);
  }
  return result;
}

LaneInterval restrictIntervalFromBegin(LaneInterval const &laneInterval, physics::Distance const &distance)
{
  LaneInterval result = laneInterval;
  physics::ParametricValue delta(distance / lane::calcLength(laneInterval.laneId));
  if (isRouteDirectionNegative(laneInterval))
  {
    result.end = std::max(physics::ParametricValue(0.), laneInterval.start - delta);
  }
  else
  {
    result.end = std::min(physics::ParametricValue(1.), laneInterval.start + delta);
  }

  return result;
}

LaneInterval extendIntervalUntilEnd(LaneInterval const &laneInterval)
{
  LaneInterval resultInterval = laneInterval;
  if (isDegenerated(resultInterval))
  {
    // nothing to be done
  }
  else if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.end = physics::ParametricValue(1.0);
  }
  else
  {
    resultInterval.end = physics::ParametricValue(0.0);
  }
  return resultInterval;
}

LaneInterval shortenIntervalFromEnd(LaneInterval const &laneInterval, physics::Distance const &distance)
{
  LaneInterval result = laneInterval;
  physics::ParametricValue delta(distance / lane::calcLength(laneInterval.laneId));
  if (isRouteDirectionPositive(laneInterval))
  {
    result.end = std::max(laneInterval.end - delta, laneInterval.start);
  }
  else
  {
    result.end = std::min(laneInterval.end + delta, laneInterval.start);
  }
  return result;
}

LaneInterval extendIntervalFromStart(LaneInterval const &laneInterval, physics::Distance const &distance)
{
  if (isDegenerated(laneInterval))
  {
    return laneInterval;
  }

  LaneInterval resultInterval = laneInterval;
  physics::ParametricValue offset(distance / lane::calcLength(laneInterval.laneId));

  if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.start = std::max(physics::ParametricValue(0.0), laneInterval.start - offset);
  }
  else
  {
    resultInterval.start = std::min(physics::ParametricValue(1.0), laneInterval.start + offset);
  }
  return resultInterval;
}

LaneInterval extendIntervalFromEnd(LaneInterval const &laneInterval, physics::Distance const &distance)
{
  if (isDegenerated(laneInterval))
  {
    return laneInterval;
  }

  LaneInterval resultInterval = laneInterval;
  physics::ParametricValue offset(distance / lane::calcLength(laneInterval.laneId));

  if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.end = std::min(physics::ParametricValue(1.0), laneInterval.end + offset);
  }
  else
  {
    resultInterval.end = std::max(physics::ParametricValue(0.0), laneInterval.end - offset);
  }
  return resultInterval;
}

LaneInterval extendIntervalUntilStart(LaneInterval const &laneInterval)
{
  LaneInterval resultInterval = laneInterval;
  if (isDegenerated(resultInterval))
  {
    // nothing to be done
  }
  else if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.start = physics::ParametricValue(0.0);
  }
  else
  {
    resultInterval.start = physics::ParametricValue(1.0);
  }
  return resultInterval;
}

LaneInterval cutIntervalAtStart(LaneInterval const &laneInterval, physics::ParametricValue const &newIntervalStart)
{
  LaneInterval result = laneInterval;
  if (isWithinInterval(laneInterval, newIntervalStart))
  {
    result.start = newIntervalStart;
  }
  return result;
}

LaneInterval cutIntervalAtEnd(LaneInterval const &laneInterval, physics::ParametricValue const &newIntervalEnd)
{
  LaneInterval result = laneInterval;
  if (isWithinInterval(laneInterval, newIntervalEnd))
  {
    result.end = newIntervalEnd;
  }
  return result;
}

restriction::SpeedLimitList getSpeedLimits(LaneInterval const &laneInterval)
{
  auto lanePtr = lane::getLanePtr(laneInterval.laneId);
  return getSpeedLimits(*lanePtr, toParametricRange(laneInterval));
}

} // namespace route
} // namespace map
} // namespace ad
