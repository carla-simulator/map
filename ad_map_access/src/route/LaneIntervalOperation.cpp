// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/LaneIntervalOperation.hpp"

#include <algorithm>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/BorderOperation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/point/Operation.hpp"

namespace ad {
namespace map {
namespace route {

physics::ParametricValue calcParametricLength(LaneInterval const &lane_interval)
{
  return std::fabs(lane_interval.start - lane_interval.end);
}

point::ParaPoint getIntervalStart(FullRoute const &route, lane::LaneId const &lane_id)
{
  point::ParaPoint result;
  for (auto const &roadSegment : route.road_segments)
  {
    auto it = find_if(roadSegment.drivable_lane_segments.begin(),
                      roadSegment.drivable_lane_segments.end(),
                      [&lane_id](const LaneSegment &l) { return l.lane_interval.lane_id == lane_id; });

    if (it != roadSegment.drivable_lane_segments.end())
    {
      result.lane_id = lane_id;
      result.parametric_offset = it->lane_interval.start;
      return result;
    }
  }

  throw std::invalid_argument("ad::map::route::getIntervalStart: lane_id not found in route");
}

physics::ParametricValue
getSignedDistance(LaneInterval const &lane_interval, point::ParaPoint const &first, point::ParaPoint const &second)
{
  if ((first.lane_id != second.lane_id) || (first.lane_id != lane_interval.lane_id))
  {
    throw std::invalid_argument("ad::map::route::getSignedDistance: lane id's not matching");
  }

  if (isRouteDirectionPositive(lane_interval))
  {
    return second.parametric_offset - first.parametric_offset;
  }
  else
  {
    return first.parametric_offset - second.parametric_offset;
  }
}

physics::ParametricValue
getUnsignedDistance(LaneInterval const &lane_interval, point::ParaPoint const &first, point::ParaPoint const &second)
{
  if ((first.lane_id != second.lane_id) || (first.lane_id != lane_interval.lane_id))
  {
    throw std::invalid_argument("ad::map::route::getSignedDistance: lane id's not matching");
  }
  return std::fabs(first.parametric_offset - second.parametric_offset);
}

bool isRouteDirectionPositive(LaneInterval const &lane_interval)
{
  if (lane_interval.start == lane_interval.end)
  {
    return lane::isLaneDirectionPositive(lane_interval.lane_id) ^ lane_interval.wrong_way;
  }
  else
  {
    return (lane_interval.start < lane_interval.end);
  }
}

bool isRouteDirectionAlignedWithDrivingDirection(LaneInterval const &lane_interval)
{
  if (isRouteDirectionPositive(lane_interval))
  {
    return lane::isLaneDirectionPositive(lane_interval.lane_id);
  }
  else
  {
    return lane::isLaneDirectionNegative(lane_interval.lane_id);
  }
}

physics::ParametricValue getProjectedParametricOffsetOnNeighborLane(LaneInterval const &currentInterval,
                                                                    LaneInterval const &neighborInterval,
                                                                    physics::ParametricValue const &parametric_offset)
{
  if (!lane::isSameOrDirectNeighbor(currentInterval.lane_id, neighborInterval.lane_id))
  {
    throw std::invalid_argument("ad::map::route::getProjectedParametricOffsetOnNeighborLane: lanes are not neighbors");
  }

  if (currentInterval.lane_id == neighborInterval.lane_id)
  {
    return parametric_offset;
  }

  // real neighbors
  auto currentLane = lane::getLane(currentInterval.lane_id);
  auto neighborLane = lane::getLane(neighborInterval.lane_id);
  auto leftNeighbors = lane::getContactLanes(currentLane, lane::ContactLocation::LEFT);
  auto rightNeighbors = lane::getContactLanes(currentLane, lane::ContactLocation::RIGHT);

  point::ECEFPoint leftECEFPoint;
  point::ECEFPoint rightECEFPoint;
  physics::ParametricValue offset;
  lane::projectParametricPointToEdges(currentLane, parametric_offset, leftECEFPoint, rightECEFPoint);

  if ((leftNeighbors.size() > 0) && (leftNeighbors[0].to_lane == neighborInterval.lane_id))
  {
    offset = ((point::findNearestPointOnEdge(neighborLane.edge_right, leftECEFPoint)
               + point::findNearestPointOnEdge(neighborLane.edge_left, leftECEFPoint))
              / 2.);
  }
  else if ((rightNeighbors.size() > 0) && (rightNeighbors[0].to_lane == neighborInterval.lane_id))
  {
    offset = ((point::findNearestPointOnEdge(neighborLane.edge_right, rightECEFPoint)
               + point::findNearestPointOnEdge(neighborLane.edge_left, rightECEFPoint))
              / 2.);
  }
  else
  {
    throw std::invalid_argument("ad::map::route::getProjectedParametricOffsetOnNeighborLane: lanes are not neighbors");
  }

  return offset;
}

physics::Distance calcLength(LaneInterval const &lane_interval)
{
  auto currentLane = lane::getLane(lane_interval.lane_id);
  auto const resultDistance = currentLane.length * calcParametricLength(lane_interval);
  return resultDistance;
}

physics::Duration calcDuration(LaneInterval const &lane_interval)
{
  auto currentLane = lane::getLane(lane_interval.lane_id);
  return lane::getDuration(currentLane, toParametricRange(lane_interval));
}

template <typename LaneEdge>
void getEdge(LaneInterval const &lane_interval, lane::EdgeType edge_type, LaneEdge &outputEdge)
{
  auto currentLane = lane::getLane(lane_interval.lane_id);

  outputEdge.lateral_alignment = physics::ParametricValue();
  auto projectedInterval = lane_interval;
  if (isRouteDirectionPositive(lane_interval))
  {
    if (edge_type == lane::EdgeType::LEFT)
    {
      point::getParametricRange(currentLane.edge_left, toParametricRange(lane_interval), outputEdge.points, false);
      outputEdge.lateral_alignment = lane::cLateralAlignmentLeft;
    }
    else if (edge_type == lane::EdgeType::LEFT_PROJECTED)
    {
      projectedInterval.start = point::findNearestPointOnEdge(
        currentLane.edge_left,
        lane::getProjectedParametricPoint(currentLane, lane_interval.start, physics::ParametricValue(0.)));
      projectedInterval.end = point::findNearestPointOnEdge(
        currentLane.edge_left,
        lane::getProjectedParametricPoint(currentLane, lane_interval.end, physics::ParametricValue(0.)));
      point::getParametricRange(currentLane.edge_left, toParametricRange(projectedInterval), outputEdge.points, false);
      outputEdge.lateral_alignment = lane::cLateralAlignmentLeft;
    }
    else if (edge_type == lane::EdgeType::RIGHT)
    {
      point::getParametricRange(currentLane.edge_right, toParametricRange(lane_interval), outputEdge.points, false);
      outputEdge.lateral_alignment = lane::cLateralAlignmentRight;
    }
    else if (edge_type == lane::EdgeType::RIGHT_PROJECTED)
    {
      projectedInterval.start = point::findNearestPointOnEdge(
        currentLane.edge_right,
        lane::getProjectedParametricPoint(currentLane, lane_interval.start, physics::ParametricValue(1.)));
      projectedInterval.end = point::findNearestPointOnEdge(
        currentLane.edge_right,
        lane::getProjectedParametricPoint(currentLane, lane_interval.end, physics::ParametricValue(1.)));
      point::getParametricRange(currentLane.edge_right, toParametricRange(projectedInterval), outputEdge.points, false);
      outputEdge.lateral_alignment = lane::cLateralAlignmentRight;
    }
  }
  else
  {
    if (edge_type == lane::EdgeType::LEFT)
    {
      point::getParametricRange(currentLane.edge_right, toParametricRange(lane_interval), outputEdge.points, true);
      outputEdge.lateral_alignment = lane::cLateralAlignmentLeft;
    }
    else if (edge_type == lane::EdgeType::LEFT_PROJECTED)
    {
      projectedInterval.start = point::findNearestPointOnEdge(
        currentLane.edge_right,
        lane::getProjectedParametricPoint(currentLane, lane_interval.start, physics::ParametricValue(1.)));
      projectedInterval.end = point::findNearestPointOnEdge(
        currentLane.edge_right,
        lane::getProjectedParametricPoint(currentLane, lane_interval.end, physics::ParametricValue(1.)));
      point::getParametricRange(currentLane.edge_right, toParametricRange(projectedInterval), outputEdge.points, true);
      outputEdge.lateral_alignment = lane::cLateralAlignmentLeft;
    }
    else if (edge_type == lane::EdgeType::RIGHT)
    {
      point::getParametricRange(currentLane.edge_left, toParametricRange(lane_interval), outputEdge.points, true);
      outputEdge.lateral_alignment = lane::cLateralAlignmentRight;
    }
    else if (edge_type == lane::EdgeType::RIGHT_PROJECTED)
    {
      projectedInterval.start = point::findNearestPointOnEdge(
        currentLane.edge_left,
        lane::getProjectedParametricPoint(currentLane, lane_interval.start, physics::ParametricValue(0.)));
      projectedInterval.end = point::findNearestPointOnEdge(
        currentLane.edge_left,
        lane::getProjectedParametricPoint(currentLane, lane_interval.end, physics::ParametricValue(0.)));
      point::getParametricRange(currentLane.edge_left, toParametricRange(projectedInterval), outputEdge.points, true);
      outputEdge.lateral_alignment = lane::cLateralAlignmentRight;
    }
  }
  outputEdge.edge_type = edge_type;
  if (!withinValidInputRange(outputEdge) || (outputEdge.points.size() < 2u))
  {
    access::getLogger()->error("ad::map::route::getEdge({}) invalid edge. projectedInterval({}). Lane {}. result {} ",
                               lane_interval,
                               projectedInterval,
                               currentLane,
                               outputEdge);
  }
}

void getLeftEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT, enuEdge);
}

void getRightEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT, enuEdge);
}

void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT_PROJECTED, enuEdge);
}

void getRightProjectedEdge(LaneInterval const &lane_interval, lane::ENUEdge &enuEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT_PROJECTED, enuEdge);
}

void getLeftEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT, geoEdge);
}

void getRightEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT, geoEdge);
}

void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT_PROJECTED, geoEdge);
}

void getRightProjectedEdge(LaneInterval const &lane_interval, lane::GeoEdge &geoEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT_PROJECTED, geoEdge);
}

void getLeftEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT, ecefEdge);
}

void getRightEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT, ecefEdge);
}

void getLeftProjectedEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge)
{
  getEdge(lane_interval, lane::EdgeType::LEFT_PROJECTED, ecefEdge);
}

void getRightProjectedEdge(LaneInterval const &lane_interval, lane::ECEFEdge &ecefEdge)
{
  getEdge(lane_interval, lane::EdgeType::RIGHT_PROJECTED, ecefEdge);
}

lane::ENUEdge getRightENUEdge(LaneInterval const &lane_interval)
{
  lane::ENUEdge enuEdge;
  getRightEdge(lane_interval, enuEdge);
  return enuEdge;
}

lane::ECEFEdge getRightECEFEdge(LaneInterval const &lane_interval)
{
  lane::ECEFEdge ecefEdge;
  getRightEdge(lane_interval, ecefEdge);
  return ecefEdge;
}

lane::GeoEdge getRightGeoEdge(LaneInterval const &lane_interval)
{
  lane::GeoEdge geoEdge;
  getRightEdge(lane_interval, geoEdge);
  return geoEdge;
}

lane::ENUEdge getLeftENUEdge(LaneInterval const &lane_interval)
{
  lane::ENUEdge enuEdge;
  getLeftEdge(lane_interval, enuEdge);
  return enuEdge;
}

lane::ECEFEdge getLeftECEFEdge(LaneInterval const &lane_interval)
{
  lane::ECEFEdge ecefEdge;
  getLeftEdge(lane_interval, ecefEdge);
  return ecefEdge;
}

lane::GeoEdge getLeftGeoEdge(LaneInterval const &lane_interval)
{
  lane::GeoEdge geoEdge;
  getLeftEdge(lane_interval, geoEdge);
  return geoEdge;
}

lane::ENUEdge getRightProjectedENUEdge(LaneInterval const &lane_interval)
{
  lane::ENUEdge enuEdge;
  getRightProjectedEdge(lane_interval, enuEdge);
  return enuEdge;
}

lane::ECEFEdge getRightProjectedECEFEdge(LaneInterval const &lane_interval)
{
  lane::ECEFEdge ecefEdge;
  getRightProjectedEdge(lane_interval, ecefEdge);
  return ecefEdge;
}

lane::GeoEdge getRightProjectedGeoEdge(LaneInterval const &lane_interval)
{
  lane::GeoEdge geoEdge;
  getRightProjectedEdge(lane_interval, geoEdge);
  return geoEdge;
}

lane::ENUEdge getLeftProjectedENUEdge(LaneInterval const &lane_interval)
{
  lane::ENUEdge enuEdge;
  getLeftProjectedEdge(lane_interval, enuEdge);
  return enuEdge;
}

lane::ECEFEdge getLeftProjectedECEFEdge(LaneInterval const &lane_interval)
{
  lane::ECEFEdge ecefEdge;
  getLeftProjectedEdge(lane_interval, ecefEdge);
  return ecefEdge;
}

lane::GeoEdge getLeftProjectedGeoEdge(LaneInterval const &lane_interval)
{
  lane::GeoEdge geoEdge;
  getLeftProjectedEdge(lane_interval, geoEdge);
  return geoEdge;
}

lane::GeoBorder getGeoBorder(LaneInterval const &lane_interval)
{
  lane::GeoBorder geoBorder;
  getLeftEdge(lane_interval, geoBorder.left);
  getRightEdge(lane_interval, geoBorder.right);
  return geoBorder;
}

lane::ECEFBorder getECEFBorder(LaneInterval const &lane_interval)
{
  lane::ECEFBorder ecefBorder;
  getLeftEdge(lane_interval, ecefBorder.left);
  getRightEdge(lane_interval, ecefBorder.right);
  return ecefBorder;
}

lane::ENUBorder getENUBorder(LaneInterval const &lane_interval)
{
  lane::ENUBorder enuBorder;
  getLeftEdge(lane_interval, enuBorder.left);
  getRightEdge(lane_interval, enuBorder.right);
  return enuBorder;
}

lane::ENUBorder getENUProjectedBorder(LaneInterval const &lane_interval)
{
  lane::ENUBorder enuBorder;
  getLeftProjectedEdge(lane_interval, enuBorder.left);
  getRightProjectedEdge(lane_interval, enuBorder.right);
  return enuBorder;
}

LaneInterval shortenIntervalFromBegin(LaneInterval const &lane_interval, physics::Distance const &distance)
{
  LaneInterval result = lane_interval;
  physics::ParametricValue delta(distance / lane::calcLength(lane_interval.lane_id));
  if (isRouteDirectionPositive(lane_interval))
  {
    result.start = std::min(lane_interval.start + delta, lane_interval.end);
  }
  else
  {
    result.start = std::max(lane_interval.start - delta, lane_interval.end);
  }
  return result;
}

LaneInterval restrictIntervalFromBegin(LaneInterval const &lane_interval, physics::Distance const &distance)
{
  LaneInterval result = lane_interval;
  physics::ParametricValue delta(distance / lane::calcLength(lane_interval.lane_id));
  if (isRouteDirectionNegative(lane_interval))
  {
    result.end = std::max(physics::ParametricValue(0.), lane_interval.start - delta);
  }
  else
  {
    result.end = std::min(physics::ParametricValue(1.), lane_interval.start + delta);
  }

  return result;
}

LaneInterval extendIntervalUntilEnd(LaneInterval const &lane_interval)
{
  LaneInterval resultInterval = lane_interval;
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

LaneInterval shortenIntervalFromEnd(LaneInterval const &lane_interval, physics::Distance const &distance)
{
  LaneInterval result = lane_interval;
  physics::ParametricValue delta(distance / lane::calcLength(lane_interval.lane_id));
  if (isRouteDirectionPositive(lane_interval))
  {
    result.end = std::max(lane_interval.end - delta, lane_interval.start);
  }
  else
  {
    result.end = std::min(lane_interval.end + delta, lane_interval.start);
  }
  return result;
}

LaneInterval extendIntervalFromStart(LaneInterval const &lane_interval, physics::Distance const &distance)
{
  if (isDegenerated(lane_interval))
  {
    return lane_interval;
  }

  LaneInterval resultInterval = lane_interval;
  physics::ParametricValue offset(distance / lane::calcLength(lane_interval.lane_id));

  if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.start = std::max(physics::ParametricValue(0.0), lane_interval.start - offset);
  }
  else
  {
    resultInterval.start = std::min(physics::ParametricValue(1.0), lane_interval.start + offset);
  }
  return resultInterval;
}

LaneInterval extendIntervalFromEnd(LaneInterval const &lane_interval, physics::Distance const &distance)
{
  if (isDegenerated(lane_interval))
  {
    return lane_interval;
  }

  LaneInterval resultInterval = lane_interval;
  physics::ParametricValue offset(distance / lane::calcLength(lane_interval.lane_id));

  if (isRouteDirectionPositive(resultInterval))
  {
    resultInterval.end = std::min(physics::ParametricValue(1.0), lane_interval.end + offset);
  }
  else
  {
    resultInterval.end = std::max(physics::ParametricValue(0.0), lane_interval.end - offset);
  }
  return resultInterval;
}

LaneInterval extendIntervalUntilStart(LaneInterval const &lane_interval)
{
  LaneInterval resultInterval = lane_interval;
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

LaneInterval cutIntervalAtStart(LaneInterval const &lane_interval, physics::ParametricValue const &newIntervalStart)
{
  LaneInterval result = lane_interval;
  if (isWithinInterval(lane_interval, newIntervalStart))
  {
    result.start = newIntervalStart;
  }
  return result;
}

LaneInterval cutIntervalAtEnd(LaneInterval const &lane_interval, physics::ParametricValue const &newIntervalEnd)
{
  LaneInterval result = lane_interval;
  if (isWithinInterval(lane_interval, newIntervalEnd))
  {
    result.end = newIntervalEnd;
  }
  return result;
}

restriction::SpeedLimitList getSpeedLimits(LaneInterval const &lane_interval)
{
  auto lanePtr = lane::getLanePtr(lane_interval.lane_id);
  return getSpeedLimits(*lanePtr, toParametricRange(lane_interval));
}

void getMetricRanges(LaneInterval const &lane_interval,
                     physics::MetricRange &length_range,
                     physics::MetricRange &width_range)
{
  auto lanePtr = lane::getLanePtr(lane_interval.lane_id);
  if (std::fabs(lane_interval.end - lane_interval.start) == physics::ParametricValue(1.0))
  {
    length_range = lanePtr->length_range;
    width_range = lanePtr->width_range;
  }
  else if (std::fabs(lane_interval.end - lane_interval.start) == physics::ParametricValue(0.0))
  {
    length_range.minimum = physics::Distance(0.0);
    length_range.maximum = physics::Distance(0.0);
    width_range = lanePtr->width_range;
  }
  else
  {
    auto const enuBorders = getENUProjectedBorder(lane_interval);
    auto const leftLength = calcLength(enuBorders.left.points);
    auto const rightLength = calcLength(enuBorders.right.points);
    length_range.minimum = std::min(leftLength, rightLength);
    length_range.maximum = std::max(leftLength, rightLength);

    width_range = lanePtr->width_range;
    if ((lanePtr->width_range.maximum - lanePtr->width_range.minimum) > physics::Distance(.1))
    {
      // take the effort on with range calculation only if there is significant difference within the lane
      auto const widthRangeResult
        = calculateWidthRange(enuBorders.left.points, leftLength, enuBorders.right.points, rightLength);
      if (physics::isRangeValid(widthRangeResult.first, false))
      {
        width_range = widthRangeResult.first;
      }
    }
  }
}

} // namespace route
} // namespace map
} // namespace ad
