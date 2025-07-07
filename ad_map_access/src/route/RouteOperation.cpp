// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RouteOperation.hpp"

#include <algorithm>
#include <map>
#include <set>

#include "RouteOperationPrivate.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/intersection/Intersection.hpp"
#include "ad/map/lane/BorderOperation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/MapMatchedOperation.hpp"
#include "ad/map/point/Operation.hpp"
#include "ad/map/route/LaneSegment.hpp"
#include "ad/map/route/Planning.hpp"

namespace ad {
namespace map {
namespace route {

RouteIterator getRouteIterator(route::RouteParaPoint const &routePosition, route::FullRoute const &route)
{
  RouteIterator result(route, route.road_segments.end());
  if (routePosition.route_planning_counter != route.route_planning_counter)
  {
    // route position not matching the route
    return result;
  }

  if (route.road_segments.empty()
      || (route.road_segments.front().segment_count_from_destination < routePosition.segment_count_from_destination)
      || (route.road_segments.back().segment_count_from_destination > routePosition.segment_count_from_destination))
  {
    // route position not found within route
    return result;
  }

  for (result.roadSegmentIterator = route.road_segments.begin();
       result.roadSegmentIterator != route.road_segments.end();
       result.roadSegmentIterator++)
  {
    if (result.roadSegmentIterator->segment_count_from_destination == routePosition.segment_count_from_destination)
    {
      // found the segment
      break;
    }
  }
  return result;
}

point::ParaPoint getLaneParaPoint(physics::ParametricValue const &routeParametricOffset,
                                  route::LaneInterval const &lane_interval)
{
  point::ParaPoint lane_point;
  if (isDegenerated(lane_interval))
  {
    lane_point = getIntervalStart(lane_interval);
  }
  else
  {
    lane_point.lane_id = lane_interval.lane_id;
    physics::ParametricValue const parametricLengthOffsetFromRouteStart
      = calcParametricLength(lane_interval) * routeParametricOffset;
    if (isRouteDirectionPositive(lane_interval))
    {
      lane_point.parametric_offset = lane_interval.start + parametricLengthOffsetFromRouteStart;
    }
    else
    {
      lane_point.parametric_offset = lane_interval.start - parametricLengthOffsetFromRouteStart;
    }
  }
  return lane_point;
}

point::ParaPointList getLaneParaPoints(route::RouteParaPoint const &routePosition, route::FullRoute const &route)
{
  point::ParaPointList resultPoints;
  auto routeIter = getRouteIterator(routePosition, route);
  if (routeIter.isValid())
  {
    for (auto &laneSegment : routeIter.roadSegmentIterator->drivable_lane_segments)
    {
      resultPoints.push_back(getLaneParaPoint(routePosition.parametric_offset, laneSegment.lane_interval));
    }
  }
  return resultPoints;
}

physics::Distance signedDistanceToLane(lane::LaneId const &checkLaneId,
                                       FullRoute const &route,
                                       match::MapMatchedPositionConfidenceList const &mapMatchedPositions)
{
  physics::Distance distance = match::signedDistanceToLane(checkLaneId, mapMatchedPositions);

  auto laneInRoute = findWaypoint(checkLaneId, route);

  if (!laneInRoute.isValid())
  {
    throw std::runtime_error("::ad::map::route::signedDistanceToLane() lane_id not found in route");
  }

  if (isRouteDirectionNegative(laneInRoute.laneSegmentIterator->lane_interval))
  {
    distance = distance * -1.;
  }

  return distance;
}

physics::Distance calcLength(FullRoute const &fullRoute)
{
  physics::Distance result(0.);
  for (auto const &roadSegment : fullRoute.road_segments)
  {
    result += calcLength(roadSegment);
  }
  access::getLogger()->trace("ad::map::route::calcLength({})={}", fullRoute, result);
  return result;
}

physics::Distance calcLength(RoadSegment const &roadSegment)
{
  physics::Distance result = std::numeric_limits<physics::Distance>::max();
  for (auto const &laneSegment : roadSegment.drivable_lane_segments)
  {
    physics::Distance laneSegmentLength = calcLength(laneSegment);
    if (laneSegmentLength < result)
    {
      result = laneSegmentLength;
    }
  }
  access::getLogger()->trace("ad::map::route::calcLength({})={}", roadSegment, result);
  return result;
}

physics::Distance calcLength(LaneSegment const &laneSegment)
{
  auto const result = calcLength(laneSegment.lane_interval);
  access::getLogger()->trace("ad::map::route::calcLength({})={}", laneSegment, result);
  return result;
}

physics::Distance calcLength(ConnectingRoute const &connectingRoute)
{
  physics::Distance result;
  if (connectingRoute.type == ConnectingRouteType::Invalid)
  {
    result = physics::Distance::getMax();
  }
  else
  {
    result = std::max(connectingRoute.route_a_length, connectingRoute.route_b_length);
  }
  access::getLogger()->trace("ad::map::route::calcLength({})={}", connectingRoute, result);
  return result;
}

physics::Distance calcLength(RouteIterator const &startIterator, RouteIterator const &endIterator)
{
  physics::Distance distance(0.);
  if (startIterator.isValid() && endIterator.isValid()
      && (std::distance(startIterator.roadSegmentIterator, endIterator.roadSegmentIterator) >= 0u))
  {
    for (auto roadSegmentIter = startIterator.roadSegmentIterator; roadSegmentIter < endIterator.roadSegmentIterator;
         roadSegmentIter++)
    {
      distance += calcLength(*roadSegmentIter);
    }
    distance += calcLength(*endIterator.roadSegmentIterator);
  }
  access::getLogger()->trace("ad::map::route::calcLength(routeiterators)={}", distance);
  return distance;
}

physics::Distance
calcLength(RouteParaPoint const &startRouteParaPoint, RouteParaPoint const &endRouteParaPoint, FullRoute const &route)
{
  physics::Distance distance = std::numeric_limits<physics::Distance>::max();

  const auto laneParaPointsStart = getLaneParaPoints(startRouteParaPoint, route);
  const auto laneParaPointsEnd = getLaneParaPoints(endRouteParaPoint, route);

  for (auto startLaneParaPoint : laneParaPointsStart)
  {
    auto startWaypoint = findWaypoint(startLaneParaPoint, route);
    if (startWaypoint.isValid())
    {
      for (auto endLaneParaPoint : laneParaPointsEnd)
      {
        auto endWaypoint = findWaypoint(endLaneParaPoint, route);
        if (endWaypoint.isValid())
        {
          physics::Distance startDistance = calcLength(startWaypoint);
          physics::Distance endDistance = calcLength(endWaypoint);

          distance = std::min(std::fabs(startDistance - endDistance), distance);
        }
      }
    }
  }

  access::getLogger()->trace("ad::map::route::calcLength({}->{})={}", startRouteParaPoint, endRouteParaPoint, distance);
  return distance;
}

physics::Duration calcDuration(LaneSegment const &laneSegment)
{
  return calcDuration(laneSegment.lane_interval);
}

physics::Duration calcDuration(FullRoute const &fullRoute)
{
  physics::Duration result(0.);
  for (auto const &roadSegment : fullRoute.road_segments)
  {
    result += calcDuration(roadSegment);
  }
  return result;
}

physics::Duration calcDuration(RoadSegment const &roadSegment)
{
  physics::Duration result = std::numeric_limits<physics::Duration>::max();
  for (auto const &laneSegment : roadSegment.drivable_lane_segments)
  {
    physics::Duration const laneSegmentDuration = calcDuration(laneSegment);
    if (laneSegmentDuration < result)
    {
      result = laneSegmentDuration;
    }
  }
  return result;
}

physics::Duration calcDuration(ConnectingRoute const &connectingRoute)
{
  physics::Duration result = std::max(calcDuration(connectingRoute.route_a), calcDuration(connectingRoute.route_b));
  return result;
}

restriction::SpeedLimitList getSpeedLimits(RoadSegment const &roadSegment)
{
  restriction::SpeedLimitList resultLimits;
  for (auto const &laneSegment : roadSegment.drivable_lane_segments)
  {
    auto const segmentSpeedLimits = getSpeedLimits(laneSegment);
    resultLimits.insert(resultLimits.end(), segmentSpeedLimits.begin(), segmentSpeedLimits.end());
  }
  return resultLimits;
}

restriction::SpeedLimitList getSpeedLimits(LaneSegment const &laneSegment)
{
  return getSpeedLimits(laneSegment.lane_interval);
}

restriction::SpeedLimitList getSpeedLimits(RouteIterator const &startIterator, RouteIterator const &endIterator)
{
  restriction::SpeedLimitList resultLimits;
  if (startIterator.isValid() && endIterator.isValid()
      && (std::distance(startIterator.roadSegmentIterator, endIterator.roadSegmentIterator) >= 0u))
  {
    for (auto roadSegmentIter = startIterator.roadSegmentIterator; roadSegmentIter < endIterator.roadSegmentIterator;
         roadSegmentIter++)
    {
      auto const segmentSpeedLimits = getSpeedLimits(*roadSegmentIter);
      resultLimits.insert(resultLimits.end(), segmentSpeedLimits.begin(), segmentSpeedLimits.end());
    }
  }
  return resultLimits;
}

restriction::SpeedLimitList getSpeedLimits(FullRoute const &fullRoute)
{
  restriction::SpeedLimitList resultLimits;
  for (auto const &roadSegment : fullRoute.road_segments)
  {
    auto const segmentSpeedLimits = getSpeedLimits(roadSegment);
    resultLimits.insert(resultLimits.end(), segmentSpeedLimits.begin(), segmentSpeedLimits.end());
  }
  return resultLimits;
}

restriction::SpeedLimitList getSpeedLimits(ConnectingRoute const &connectingRoute)
{
  restriction::SpeedLimitList resultLimits = getSpeedLimits(connectingRoute.route_a);
  auto const speedLimitsB = getSpeedLimits(connectingRoute.route_a);
  resultLimits.insert(resultLimits.end(), speedLimitsB.begin(), speedLimitsB.end());
  return resultLimits;
}

bool isWithinInterval(RoadSegment const &roadSegment, point::ParaPoint const &point)
{
  for (auto const &laneSegment : roadSegment.drivable_lane_segments)
  {
    if (isWithinInterval(laneSegment.lane_interval, point))
    {
      return true;
    }
  }

  return false;
}

void clearLaneSegmentPredecessors(RoadSegment &roadSegment)
{
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.predecessors.clear();
  }
}

void clearLaneSegmentSuccessors(RoadSegment &roadSegment)
{
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.successors.clear();
  }
}

void updateLaneSegmentNeighbors(RoadSegment &roadSegment)
{
  if (roadSegment.drivable_lane_segments.empty())
  {
    return;
  }

  roadSegment.drivable_lane_segments.front().left_neighbor = lane::LaneId();
  roadSegment.drivable_lane_segments.back().right_neighbor = lane::LaneId();

  auto leftLaneSegmentIter = roadSegment.drivable_lane_segments.begin();
  auto rightLaneSegmentIter = leftLaneSegmentIter;
  rightLaneSegmentIter++;

  while (rightLaneSegmentIter != std::end(roadSegment.drivable_lane_segments))
  {
    leftLaneSegmentIter->right_neighbor = rightLaneSegmentIter->lane_interval.lane_id;
    rightLaneSegmentIter->left_neighbor = leftLaneSegmentIter->lane_interval.lane_id;

    leftLaneSegmentIter = rightLaneSegmentIter;
    rightLaneSegmentIter++;
  }
}

void updateLaneSegmentSuccessors(RoadSegment &roadSegment, RoadSegment const &successorSegment)
{
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.successors.erase(
      std::remove_if(std::begin(laneSegment.successors),
                     std::end(laneSegment.successors),
                     [&successorSegment](lane::LaneId const &successorId) {
                       auto findResult = std::find_if(std::begin(successorSegment.drivable_lane_segments),
                                                      std::end(successorSegment.drivable_lane_segments),
                                                      [&successorId](LaneSegment const &segment) {
                                                        return segment.lane_interval.lane_id == successorId;
                                                      });
                       return findResult == std::end(successorSegment.drivable_lane_segments);
                     }),
      laneSegment.successors.end());
  }
}

void updateLaneSegmentPredecessors(RoadSegment &roadSegment, RoadSegment const &predecessorSegment)
{
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.predecessors.erase(
      std::remove_if(std::begin(laneSegment.predecessors),
                     std::end(laneSegment.predecessors),
                     [&predecessorSegment](lane::LaneId const &predecessorId) {
                       auto findResult = std::find_if(std::begin(predecessorSegment.drivable_lane_segments),
                                                      std::end(predecessorSegment.drivable_lane_segments),
                                                      [&predecessorId](LaneSegment const &segment) {
                                                        return segment.lane_interval.lane_id == predecessorId;
                                                      });
                       return findResult == std::end(predecessorSegment.drivable_lane_segments);
                     }),
      laneSegment.predecessors.end());
  }
}

void updateLaneConnections(FullRoute &fullRoute)
{
  if (fullRoute.road_segments.empty())
  {
    return;
  }

  clearLaneSegmentPredecessors(fullRoute.road_segments.front());
  clearLaneSegmentSuccessors(fullRoute.road_segments.back());
  updateLaneSegmentNeighbors(fullRoute.road_segments.front());

  auto previousSegment = fullRoute.road_segments.begin();
  auto nextSegment = previousSegment;
  nextSegment++;

  while (nextSegment != std::end(fullRoute.road_segments))
  {
    updateLaneSegmentSuccessors(*previousSegment, *nextSegment);
    updateLaneSegmentPredecessors(*nextSegment, *previousSegment);
    updateLaneSegmentNeighbors(*nextSegment);

    previousSegment = nextSegment;
    nextSegment++;
  }
}

physics::Distance calcLength(FindWaypointResult const &findWaypointResult)
{
  physics::Distance result(0.);
  if (findWaypointResult.isValid())
  {
    auto roadSegmentIter = findWaypointResult.queryRoute.road_segments.begin();
    // all segments before
    for (; roadSegmentIter != findWaypointResult.queryRoute.road_segments.end()
         && roadSegmentIter != findWaypointResult.roadSegmentIterator;
         ++roadSegmentIter)
    {
      result += calcLength(*roadSegmentIter);
    }

    // the result segment interval
    if (roadSegmentIter == findWaypointResult.roadSegmentIterator)
    {
      // ensure that the interval is actually within the range
      auto laneSegmentIter = roadSegmentIter->drivable_lane_segments.begin();
      while (laneSegmentIter != roadSegmentIter->drivable_lane_segments.end()
             && laneSegmentIter != findWaypointResult.laneSegmentIterator)
      {
        ++laneSegmentIter;
      }

      if (laneSegmentIter == findWaypointResult.laneSegmentIterator)
      {
        LaneInterval calcInterval = laneSegmentIter->lane_interval;
        calcInterval.end = findWaypointResult.queryPosition.parametric_offset;
        result += calcLength(calcInterval);
      }
      else
      {
        throw(std::runtime_error(
          "::ad::map::route::calcLength(FindWaypointResult) intervalIter of the result is not valid"));
      }
    }
    else
    {
      throw(std::runtime_error(
        "::ad::map::route::calcLength(FindWaypointResult) roadSegmentIterator of the result is not valid"));
    }
  }
  return result;
}

FindWaypointResult::FindWaypointResult(FullRoute const &route)
  : queryRoute(route)
  , roadSegmentIterator(queryRoute.road_segments.end())
{
}

FindWaypointResult &FindWaypointResult::operator=(FindWaypointResult const &other)
{
  if ((&this->queryRoute) != (&other.queryRoute))
  {
    throw std::invalid_argument("FindWaypointResult::operator= incompatible input parameter");
  }
  if (this != &other)
  {
    this->queryPosition = other.queryPosition;
    this->roadSegmentIterator = other.roadSegmentIterator;
    this->laneSegmentIterator = other.laneSegmentIterator;
  }
  return *this;
}

FindWaypointResult FindWaypointResult::getLeftLane() const
{
  FindWaypointResult result(queryRoute);
  if (!isValid() || (!lane::isValid(laneSegmentIterator->left_neighbor, false)))
  {
    return result;
  }

  result = *this;
  result.laneSegmentIterator++;
  if (!result.isValid() || (result.laneSegmentIterator->lane_interval.lane_id != laneSegmentIterator->left_neighbor))
  {
    throw std::runtime_error("ad::map::route::FindWaypointResult::getLeftLane()>> Route inconsistent: "
                             "left lane not found");
  }
  result.queryPosition.lane_id = result.laneSegmentIterator->lane_interval.lane_id;
  return result;
}

FindWaypointResult FindWaypointResult::getRightLane() const
{
  FindWaypointResult result(queryRoute);
  if (!isValid() || (!lane::isValid(laneSegmentIterator->right_neighbor, false)))
  {
    return result;
  }

  result = *this;
  result.laneSegmentIterator--;
  if (!result.isValid() || (result.laneSegmentIterator->lane_interval.lane_id != laneSegmentIterator->right_neighbor))
  {
    throw std::runtime_error("ad::map::route::FindWaypointResult::getRightLane()>> Route inconsistent: "
                             "right lane not found");
  }
  result.queryPosition.lane_id = result.laneSegmentIterator->lane_interval.lane_id;
  return result;
}

// supporting function used commonly by getSuccessorLanes() and getPredecessorLanes()
std::vector<FindWaypointResult> getLanesOfCurrentRoadSegment(FindWaypointResult &result,
                                                             lane::LaneIdList const &expectedLanesVector)
{
  std::vector<FindWaypointResult> resultList;

  std::set<lane::LaneId> expectedLanes;
  expectedLanes.insert(expectedLanesVector.begin(), expectedLanesVector.end());
  for (result.laneSegmentIterator = result.roadSegmentIterator->drivable_lane_segments.begin();
       result.laneSegmentIterator != result.roadSegmentIterator->drivable_lane_segments.end();
       result.laneSegmentIterator++)
  {
    auto const findResult = expectedLanes.find(result.laneSegmentIterator->lane_interval.lane_id);
    if (findResult != expectedLanes.end())
    {
      // found a predecessor
      if (!result.isValid())
      {
        throw std::runtime_error(
          "ad::map::route::FindWaypointResult::getLanesOfCurrentRoadSegment()>> unexpected error");
      }
      result.queryPosition.lane_id = result.laneSegmentIterator->lane_interval.lane_id;
      resultList.push_back(result);
      expectedLanes.erase(findResult);
    }
  }

  if (!expectedLanes.empty())
  {
    throw std::runtime_error("ad::map::route::FindWaypointResult::getLanesOfCurrentRoadSegment()>> Route inconsistent: "
                             "not all expected lanes found within current road segment");
  }
  return resultList;
}

std::vector<FindWaypointResult> FindWaypointResult::getSuccessorLanes() const
{
  std::vector<FindWaypointResult> resultList;
  if (!isValid() || (laneSegmentIterator->successors.size() == 0u))
  {
    return resultList;
  }

  FindWaypointResult result(queryRoute);
  result = *this;
  result.roadSegmentIterator++;
  if (result.roadSegmentIterator == result.queryRoute.road_segments.end())
  {
    throw std::runtime_error("ad::map::route::FindWaypointResult::getSuccessorLanes()>> Route inconsistent: "
                             "next road segment not found");
  }
  return getLanesOfCurrentRoadSegment(result, laneSegmentIterator->successors);
}

std::vector<FindWaypointResult> FindWaypointResult::getPredecessorLanes() const
{
  if (!isValid() || (laneSegmentIterator->predecessors.size() == 0u))
  {
    return std::vector<FindWaypointResult>();
  }

  FindWaypointResult result(queryRoute);
  result = *this;
  if (result.roadSegmentIterator == result.queryRoute.road_segments.begin())
  {
    throw std::runtime_error("ad::map::route::FindWaypointResult::getPredecessorLanes()>> Route inconsistent: "
                             "previous road segment not found");
  }
  result.roadSegmentIterator--;
  return getLanesOfCurrentRoadSegment(result, laneSegmentIterator->predecessors);
}

FindWaypointResult
findWaypointImpl(point::ParaPoint const &position, route::FullRoute const &route, bool considerRouteStart)
{
  for (route::RoadSegmentList::const_iterator roadSegmentIter = route.road_segments.begin();
       roadSegmentIter != route.road_segments.end();
       ++roadSegmentIter)
  {
    for (route::LaneSegmentList::const_iterator laneSegmentIter = roadSegmentIter->drivable_lane_segments.begin();
         laneSegmentIter != roadSegmentIter->drivable_lane_segments.end();
         ++laneSegmentIter)
    {
      if (position.lane_id == laneSegmentIter->lane_interval.lane_id)
      {
        if (!considerRouteStart)
        {
          point::ParaPoint startPoint;
          startPoint.lane_id = position.lane_id;
          if (isRouteDirectionPositive(laneSegmentIter->lane_interval))
          {
            startPoint.parametric_offset = laneSegmentIter->lane_interval.start;
          }
          else
          {
            startPoint.parametric_offset = laneSegmentIter->lane_interval.end;
          }
          return FindWaypointResult(route, startPoint, roadSegmentIter, laneSegmentIter);
        }
        else
        {
          // due to numeric inaccuracies we need to check not just the internal itself
          // but also some surroundings
          // @todo: Ideally this has to be covered by the lane_interval operations
          // For now, just extend the Interval by 0.5 meter on each end
          LaneInterval lane_interval = laneSegmentIter->lane_interval;
          lane_interval = extendIntervalFromStart(lane_interval, physics::Distance(0.5));
          lane_interval = extendIntervalFromEnd(lane_interval, physics::Distance(0.5));

          if (isWithinInterval(lane_interval, position))
          {
            return FindWaypointResult(route, position, roadSegmentIter, laneSegmentIter);
          }
        }
      }
    }
  }
  return FindWaypointResult(route);
}

FindWaypointResult findWaypoint(point::ParaPoint const &position, route::FullRoute const &route)
{
  return findWaypointImpl(position, route, true);
}

FindWaypointResult findWaypoint(lane::LaneId const &lane_id, route::FullRoute const &route)
{
  point::ParaPoint findPoint;
  findPoint.lane_id = lane_id;
  findPoint.parametric_offset = physics::ParametricValue(0.5);
  return findWaypointImpl(findPoint, route, false);
}

FindWaypointResult findWaypoint(physics::Distance const &length, route::FullRoute const &route)
{
  auto roadSegmentIter = route.road_segments.begin();
  auto remainingLength = length;
  while ((roadSegmentIter != route.road_segments.end()) && (remainingLength >= physics::Distance(0)))
  {
    auto const segmentLength = calcLength(*roadSegmentIter);
    if (segmentLength < remainingLength)
    {
      remainingLength -= segmentLength;
      roadSegmentIter++;
    }
    else
    {
      // found the result
      route::LaneSegmentList::const_iterator laneSegmentIter = roadSegmentIter->drivable_lane_segments.begin();
      if (laneSegmentIter != roadSegmentIter->drivable_lane_segments.end())
      {
        auto shortenedInterval = shortenIntervalFromBegin(laneSegmentIter->lane_interval, remainingLength);
        return FindWaypointResult(route, getIntervalStart(shortenedInterval), roadSegmentIter, laneSegmentIter);
      }
    }
  }
  // seem that end of route was reachead before lenght reached
  return FindWaypointResult(route);
}

FindWaypointResult findNearestWaypoint(point::ParaPointList const &positions, route::FullRoute const &route)
{
  FindWaypointResult resultWaypoint(route);

  for (auto const &position : positions)
  {
    auto findResult = findWaypoint(position, route);
    if (findResult.isValid())
    {
      if ( // no other result yet
        (!resultWaypoint.isValid())
        // new result is nearer already on route segment level
        || (findResult.roadSegmentIterator < resultWaypoint.roadSegmentIterator))
      {
        resultWaypoint = findResult;
      }
      else if (findResult.roadSegmentIterator == resultWaypoint.roadSegmentIterator)
      {
        // new result is on the same segment, so let the parametric_offset value of the query decide
        if (isRouteDirectionPositive(resultWaypoint.laneSegmentIterator->lane_interval))
        {
          if (findResult.queryPosition.parametric_offset < resultWaypoint.queryPosition.parametric_offset)
          {
            resultWaypoint = findResult;
          }
        }
        else
        {
          if (findResult.queryPosition.parametric_offset > resultWaypoint.queryPosition.parametric_offset)
          {
            resultWaypoint = findResult;
          }
        }
      }
    }
  }

  return resultWaypoint;
}

FindWaypointResult findNearestWaypoint(match::MapMatchedPositionConfidenceList const &mapMatchedPositions,
                                       route::FullRoute const &route)
{
  return findNearestWaypoint(match::getParaPoints(mapMatchedPositions), route);
}

FindWaypointResult findCenterWaypoint(match::Object const &object, route::FullRoute const &route)
{
  FindWaypointResult resultWaypoint(route);
  // first try to search the center point as main reference of the object
  if (object.map_matched_bounding_box.reference_point_positions.size()
      > static_cast<std::size_t>(match::ObjectReferencePoints::Center))
  {
    resultWaypoint = findNearestWaypoint(
      object.map_matched_bounding_box
        .reference_point_positions[static_cast<std::size_t>(match::ObjectReferencePoints::Center)],
      route);
  }
  if (!resultWaypoint.isValid())
  {
    // sort the occupied region center points by the length of the region
    // to start the search with the largest longitudinal region (which is most likely the main lane)
    std::multimap<physics::Distance, point::ParaPoint, std::greater<physics::Distance>> occupiedRegionCenters;
    for (auto const &occupiedRegion : object.map_matched_bounding_box.lane_occupied_regions)
    {
      auto const occupiedRegionLength = lane::calcLength(occupiedRegion);
      auto const occupiedRegionCenter = match::getCenterParaPoint(occupiedRegion);
      occupiedRegionCenters.insert({occupiedRegionLength, occupiedRegionCenter});
    }
    for (auto const &occupiedRegionCenter : occupiedRegionCenters)
    {
      resultWaypoint = findWaypoint(occupiedRegionCenter.second, route);
      if (resultWaypoint.isValid())
      {
        break;
      }
    }
  }
  if (!resultWaypoint.isValid())
  {
    // still nothing found, so we take the nearest of the rest of the reference point positions
    point::ParaPointList mapMatchedParaPoints;
    for (auto i = 0u; i < object.map_matched_bounding_box.reference_point_positions.size(); ++i)
    {
      if (i != static_cast<std::size_t>(match::ObjectReferencePoints::Center))
      {
        auto paraPoints = match::getParaPoints(object.map_matched_bounding_box.reference_point_positions[i]);
        mapMatchedParaPoints.insert(mapMatchedParaPoints.end(), paraPoints.begin(), paraPoints.end());
      }
    }
    resultWaypoint = findNearestWaypoint(mapMatchedParaPoints, route);
  }
  if (!resultWaypoint.isValid())
  {
    // still nothing found, so search if any point of the route is within our occupied regions
    for (auto const &occupiedRegion : object.map_matched_bounding_box.lane_occupied_regions)
    {
      auto laneWaypoint = findWaypoint(occupiedRegion.lane_id, route);
      if (laneWaypoint.isValid())
      {
        auto const routeParmetricLaneRange = route::toParametricRange(laneWaypoint.laneSegmentIterator->lane_interval);
        auto const intersectingRange
          = physics::getIntersectionRange(routeParmetricLaneRange, occupiedRegion.longitudinal_range);
        if (physics::isRangeValid(intersectingRange))
        {
          laneWaypoint.queryPosition.parametric_offset = intersectingRange.minimum;
          resultWaypoint = laneWaypoint;
          break;
        }
      }
    }
  }
  return resultWaypoint;
}

FindWaypointResult objectOnRoute(match::MapMatchedObjectBoundingBox const &object, route::FullRoute const &route)
{
  point::ParaPointList positions;
  for (auto const &occupiedRegion : object.lane_occupied_regions)
  {
    point::ParaPoint point;
    point.lane_id = occupiedRegion.lane_id;
    point.parametric_offset = occupiedRegion.longitudinal_range.minimum;
    positions.push_back(point);
    point.parametric_offset = occupiedRegion.longitudinal_range.maximum;
    positions.push_back(point);
  }

  return findNearestWaypoint(positions, route);
}

FindWaypointResult intersectionOnRoute(intersection::Intersection const &intersection, route::FullRoute const &route)
{
  FindWaypointResult result(route);

  if (route.road_segments.empty())
  {
    return result;
  }

  /**
   * Check if we are already inside the intersection
   */
  auto findResult = std::find_if(std::begin(route.road_segments.front().drivable_lane_segments),
                                 std::end(route.road_segments.front().drivable_lane_segments),
                                 [&intersection](LaneSegment const &laneSegment) {
                                   return intersection.internalLanes().find(laneSegment.lane_interval.lane_id)
                                     != intersection.internalLanes().end();
                                 });
  if (findResult != std::end(route.road_segments.front().drivable_lane_segments))
  {
    result.laneSegmentIterator = findResult;
    result.roadSegmentIterator = route.road_segments.begin();
    result.queryPosition.lane_id = result.laneSegmentIterator->lane_interval.lane_id;
    result.queryPosition.parametric_offset = result.laneSegmentIterator->lane_interval.start;
  }
  else
  {
    result = findNearestWaypoint(intersection.incomingParaPointsOnRoute(), route);
    if (!result.isValid())
    {
      result = findNearestWaypoint(intersection.incomingParaPoints(), route);
    }
  }

  return result;
}

bool isConnectedRoutePartOfAnIntersection(route::ConnectingRoute const &connectingRoute)
{
  return intersection::Intersection::isRoutePartOfAnIntersection(connectingRoute.route_a)
    || intersection::Intersection::isRoutePartOfAnIntersection(connectingRoute.route_b);
}

route::ConnectingRoute swapConnectingRouteObjects(route::ConnectingRoute const &other)
{
  route::ConnectingRoute resultRoute;
  resultRoute.type = other.type;
  resultRoute.route_a = other.route_b;
  resultRoute.route_a_length = other.route_b_length;
  resultRoute.heading_rating_a = other.heading_rating_b;
  resultRoute.route_a_heading_start = other.route_b_heading_start;
  resultRoute.route_a_heading_end = other.route_b_heading_end;
  resultRoute.route_b = other.route_a;
  resultRoute.route_b_length = other.route_a_length;
  resultRoute.heading_rating_b = other.heading_rating_a;
  resultRoute.route_b_heading_start = other.route_a_heading_start;
  resultRoute.route_b_heading_end = other.route_a_heading_end;
  return resultRoute;
}

void alignRouteStartingPoints(point::ParaPoint const &startAlignmentParaPoint, route::FullRoute &route)
{
  if (route.road_segments.empty())
  {
    return;
  }

  // we need to ensure, that the starting point of all segments are aligned,
  // i.e. the starting points are located on an imaginary line on the curve radius
  auto const startAlignmentLane = lane::getLane(startAlignmentParaPoint.lane_id);
  auto const startAlignmentPoint = lane::getProjectedParametricPoint(
    startAlignmentLane, startAlignmentParaPoint.parametric_offset, physics::ParametricValue(0.5));

  for (route::LaneSegmentList::iterator laneSegmentIter = route.road_segments.front().drivable_lane_segments.begin();
       laneSegmentIter != route.road_segments.front().drivable_lane_segments.end();
       ++laneSegmentIter)
  {
    // don't touch alignment interval
    // don't touch degenerated intervals
    if ((laneSegmentIter->lane_interval.lane_id != startAlignmentParaPoint.lane_id)
        && (!route::isDegenerated(laneSegmentIter->lane_interval)))
    {
      auto const lane = lane::getLane(laneSegmentIter->lane_interval.lane_id);
      auto const rightT = point::findNearestPointOnEdge(lane.edge_right, startAlignmentPoint);
      auto const leftT = point::findNearestPointOnEdge(lane.edge_left, startAlignmentPoint);
      auto const newStart = 0.5 * (rightT + leftT);
      // Be aware: only update the start if the values actually differ considering the ParametricValue::getPrecision()
      // to prevent from 0. becoming 1e-10
      if (newStart != laneSegmentIter->lane_interval.start)
      {
        // and ensure not to revert the interval direction by pushing the start after the interval end
        if (!route::isAfterInterval(laneSegmentIter->lane_interval, newStart))
        {
          laneSegmentIter->lane_interval.start = newStart;
        }
      }
    }
  }
}

void alignRouteEndingPoints(point::ParaPoint const &alignmentParaPoint, route::FullRoute &route)
{
  if (route.road_segments.empty())
  {
    return;
  }

  // we need to ensure, that the end point of all segments are aligned,
  // i.e. the end points are located on an imaginary line on the curve radius
  auto const alignmentLane = lane::getLane(alignmentParaPoint.lane_id);
  auto const alignmentPoint = lane::getProjectedParametricPoint(
    alignmentLane, alignmentParaPoint.parametric_offset, physics::ParametricValue(0.5));

  for (route::LaneSegmentList::iterator laneSegmentIter = route.road_segments.back().drivable_lane_segments.begin();
       laneSegmentIter != route.road_segments.back().drivable_lane_segments.end();
       ++laneSegmentIter)
  {
    // don't touch alignment interval
    // don't touch degenerated intervals
    if ((laneSegmentIter->lane_interval.lane_id != alignmentParaPoint.lane_id)
        && (!route::isDegenerated(laneSegmentIter->lane_interval)))
    {
      auto const lane = lane::getLane(laneSegmentIter->lane_interval.lane_id);
      auto const rightT = point::findNearestPointOnEdge(lane.edge_right, alignmentPoint);
      auto const leftT = point::findNearestPointOnEdge(lane.edge_left, alignmentPoint);
      auto const newEnd = 0.5 * (rightT + leftT);
      // Be aware: only update the end if the values actually differ considering the ParametricValue::getPrecision()
      // to prevent from 1. becoming 0.9999999999
      if (newEnd != laneSegmentIter->lane_interval.end)
      {
        // and ensure not to revert the interval direction by pushing the end before the interval start
        if (!route::isBeforeInterval(laneSegmentIter->lane_interval, newEnd))
        {
          laneSegmentIter->lane_interval.end = newEnd;
        }
      }
    }
  }
}

ShortenRouteResult shortenRouteImpl(FindWaypointResult const &findWaypointResult,
                                    point::ParaPointList const &currentPositions,
                                    route::FullRoute &route,
                                    ShortenRouteMode const shortenRouteMode)
{
  if (route.road_segments.empty())
  {
    return ShortenRouteResult::FailedRouteEmpty;
  }

  if (findWaypointResult.isValid())
  {
    ShortenRouteResult result = ShortenRouteResult::Succeeded;
    if ((shortenRouteMode == ShortenRouteMode::DontCutIntersectionAndPrependIfSucceededBeforeRoute)
        && (intersection::Intersection::isLanePartOfAnIntersection(
          findWaypointResult.laneSegmentIterator->lane_interval.lane_id)))
    {
      // check for intersection
      for (auto roadSegmentIter = findWaypointResult.roadSegmentIterator;
           roadSegmentIter != route.road_segments.begin();
           roadSegmentIter--)
      {
        RouteIterator routeIterator(route, roadSegmentIter);
        route::RoadSegmentList::const_iterator routePreviousSegmentIter;
        auto intersectionStarts
          = intersection::Intersection::isRoadSegmentEnteringIntersection(routeIterator, routePreviousSegmentIter);
        if (intersectionStarts)
        {
          // erase leading route in front of the intersection
          route.road_segments.erase(route.road_segments.begin(), routePreviousSegmentIter);

          // and shorten the previous segments lane intervals
          for (route::LaneSegmentList::iterator laneSegmentIter
               = route.road_segments.front().drivable_lane_segments.begin();
               laneSegmentIter != route.road_segments.front().drivable_lane_segments.end();
               ++laneSegmentIter)
          {
            laneSegmentIter->lane_interval.start = laneSegmentIter->lane_interval.end;
          }

          result = ShortenRouteResult::SucceededIntersectionNotCut;

          // done: break loop (iterators became invalid!)
          break;
        }
      }
    }

    if (result != ShortenRouteResult::SucceededIntersectionNotCut)
    {
      // erase leading route (iterator only valid in case route not yet shortened)
      route.road_segments.erase(route.road_segments.begin(), findWaypointResult.roadSegmentIterator);

      // in addition, we have to shorten the parametric offsets
      for (route::LaneSegmentList::iterator laneSegmentIter
           = route.road_segments.front().drivable_lane_segments.begin();
           laneSegmentIter != route.road_segments.front().drivable_lane_segments.end();
           ++laneSegmentIter)
      {
        if (isWithinInterval(laneSegmentIter->lane_interval, findWaypointResult.queryPosition.parametric_offset))
        {
          laneSegmentIter->lane_interval.start = findWaypointResult.queryPosition.parametric_offset;
        }
        else if (!isDegenerated(laneSegmentIter->lane_interval)
                 && isAfterInterval(laneSegmentIter->lane_interval, findWaypointResult.queryPosition.parametric_offset))
        {
          laneSegmentIter->lane_interval.start = laneSegmentIter->lane_interval.end;
        }
      }

      if (route::isDegenerated(route.road_segments.front().drivable_lane_segments.front().lane_interval))
      {
        bool removeDegeneratedRouteStart = true;
        if (shortenRouteMode == ShortenRouteMode::DontCutIntersectionAndPrependIfSucceededBeforeRoute)
        {
          if (route.road_segments.size() > 1u)
          {
            RouteIterator routeIterator(route, route.road_segments.begin() + 1);
            route::RoadSegmentList::const_iterator routePreviousSegmentIter;
            auto intersectionStarts
              = intersection::Intersection::isRoadSegmentEnteringIntersection(routeIterator, routePreviousSegmentIter);
            removeDegeneratedRouteStart = !intersectionStarts;
          }
        }

        if (removeDegeneratedRouteStart)
        {
          // remove also degenerated route start segments
          route.road_segments.erase(route.road_segments.begin());
        }
        else
        {
          result = ShortenRouteResult::SucceededIntersectionNotCut;
        }
      }
      else
      {
        alignRouteStartingPoints(findWaypointResult.queryPosition, route);
      }
    }

    if (route.road_segments.empty())
    {
      return ShortenRouteResult::SucceededRouteEmpty;
    }
    else
    {
      // remove predecessors
      clearLaneSegmentPredecessors(route.road_segments.front());
      return result;
    }
  }

  // check if we are right before the route ---> do not clear in this case
  for (auto &laneSegment : route.road_segments.front().drivable_lane_segments)
  {
    for (auto const &currentPosition : currentPositions)
    {
      if (isBeforeInterval(laneSegment.lane_interval, currentPosition))
      {
        if (shortenRouteMode == ShortenRouteMode::Normal)
        {
          return ShortenRouteResult::SucceededBeforeRoute;
        }
        else
        {
          laneSegment.lane_interval.start = currentPosition.parametric_offset;
          alignRouteStartingPoints(currentPosition, route);
          return ShortenRouteResult::Succeeded;
        }
      }
    }
  }

  // check if we are right after the route ---> clear in this case, but still return true
  for (auto const &laneSegment : route.road_segments.back().drivable_lane_segments)
  {
    for (auto const &currentPosition : currentPositions)
    {
      if (!isDegenerated(laneSegment.lane_interval) && isAfterInterval(laneSegment.lane_interval, currentPosition))
      {
        route.road_segments.clear();
        return ShortenRouteResult::SucceededRouteEmpty;
      }
    }
  }

  // we are neither right before nor right after nor on the route --> clear
  route.road_segments.clear();
  return ShortenRouteResult::FailedRouteEmpty;
}

ShortenRouteResult shortenRoute(FindWaypointResult const &findWaypointResult,
                                route::FullRoute &route,
                                ShortenRouteMode const shortenRouteMode)
{
  return shortenRouteImpl(findWaypointResult, {findWaypointResult.queryPosition}, route, shortenRouteMode);
}

ShortenRouteResult shortenRoute(point::ParaPointList const &currentPositions,
                                route::FullRoute &route,
                                ShortenRouteMode const shortenRouteMode)
{
  auto findWaypointResult = findNearestWaypoint(currentPositions, route);
  return shortenRouteImpl(findWaypointResult, currentPositions, route, shortenRouteMode);
}

ShortenRouteResult
shortenRoute(point::ParaPoint const &currentPosition, route::FullRoute &route, ShortenRouteMode const shortenRouteMode)
{
  point::ParaPointList currentPositions = {currentPosition};
  return shortenRoute(currentPositions, route, shortenRouteMode);
}

ShortenRouteResult shortenRoute(match::MapMatchedPositionConfidenceList const &mapMatchedPositions,
                                route::FullRoute &route,
                                ShortenRouteMode const shortenRouteMode)
{
  return shortenRoute(match::getParaPoints(mapMatchedPositions), route, shortenRouteMode);
}

ShortenRouteResult shortenRoute(const physics::Distance &length_to_shorten,
                                route::FullRoute &route,
                                ShortenRouteMode const shortenRouteMode)
{
  auto findWaypointResult = findWaypoint(length_to_shorten, route);
  return shortenRoute(findWaypointResult, route, shortenRouteMode);
}

void shortenRouteToDistance(route::FullRoute &route,
                            const physics::Distance &length,
                            ShortenRouteToDistanceMode const mode)
{
  auto roadSegmentIterator = route.road_segments.begin();
  auto remainingLength = length;
  while ((roadSegmentIterator != route.road_segments.end()) && (remainingLength > physics::Distance(0)))
  {
    auto const segmentLength = calcLength(*roadSegmentIterator);
    if (segmentLength <= remainingLength)
    {
      remainingLength -= segmentLength;
      roadSegmentIterator++;
    }
    else
    {
      // this is the last remaining segment; it has to be shortened
      if ((mode == ShortenRouteToDistanceMode::DontCutIntersection)
          && intersection::Intersection::isLanePartOfAnIntersection(
            roadSegmentIterator->drivable_lane_segments.front().lane_interval.lane_id))
      {
        // don't cut in between of intersections, rather keep the whole intersection within the route
        for (roadSegmentIterator++; (roadSegmentIterator != route.road_segments.end()); roadSegmentIterator++)
        {
          if (!intersection::Intersection::isLanePartOfAnIntersection(
                roadSegmentIterator->drivable_lane_segments.front().lane_interval.lane_id))
          {
            // outside the intersection, so we can cut the rest
            break;
          }
        }
      }
      else
      {
        auto const deltaLength = segmentLength - remainingLength;
        shortenSegmentFromEnd(*roadSegmentIterator, deltaLength);
        // and push the iterator to the next, where we then can cut
        roadSegmentIterator++;
      }
      // nothing remains, loop ends now
      remainingLength = physics::Distance(0);
    }
  }
  route.road_segments.erase(roadSegmentIterator, route.road_segments.end());
  if (!route.road_segments.empty())
  {
    // remove successors from last road segment
    clearLaneSegmentSuccessors(route.road_segments.back());
  }
}

void removeLastRoadSegment(route::FullRoute &route)
{
  if (!route.road_segments.empty())
  {
    route.road_segments.pop_back();
    if (!route.road_segments.empty())
    {
      // remove successors from last road segment
      clearLaneSegmentSuccessors(route.road_segments.back());
    }
  }
}

void removeLastRoadSegmentIfDegenerated(route::FullRoute &route)
{
  // first drop degenerated road segments at the end of route to ensure we get proper direction
  if (!route.road_segments.empty()
      && (route.road_segments.back().drivable_lane_segments.empty()
          || isDegenerated(route.road_segments.back().drivable_lane_segments.front().lane_interval)))
  {
    removeLastRoadSegment(route);
  }
}

bool prepareRouteForExtension(route::FullRoute &route,
                              route::planning::RoutingParaPoint &routeExtensionStartPoint,
                              route::LaneSegment &extensionReferenceLaneSegment)
{
  // first drop degenerated road segments at the end of route to ensure we get proper direction
  removeLastRoadSegmentIfDegenerated(route);

  // abort on degenerated route
  if (route.road_segments.empty() || route.road_segments.back().drivable_lane_segments.empty())
  {
    return false;
  }

  extensionReferenceLaneSegment = route.road_segments.back().drivable_lane_segments.front();
  routeExtensionStartPoint = route::planning::createRoutingPoint(
    extensionReferenceLaneSegment.lane_interval.lane_id,
    extensionReferenceLaneSegment.lane_interval.start,
    (isRouteDirectionPositive(extensionReferenceLaneSegment.lane_interval) ? planning::RoutingDirection::POSITIVE
                                                                           : planning::RoutingDirection::NEGATIVE));
  return true;
}

route::FullRoute mergeRouteExtension(route::FullRoute const &route,
                                     route::LaneSegment const &extensionReferenceLaneSegment,
                                     route::FullRoute const &routeExtension)
{
  FullRoute newRoute(route);
  removeLastRoadSegment(newRoute);
  for (auto const &roadSegment : routeExtension.road_segments)
  {
    route::appendRoadSegmentToRoute(roadSegment.drivable_lane_segments.front().lane_interval,
                                    extensionReferenceLaneSegment.route_lane_offset
                                      + roadSegment.drivable_lane_segments.front().route_lane_offset,
                                    newRoute,
                                    {});
  }
  planning::updateRoutePlanningCounters(newRoute);
  return newRoute;
}

template <typename T> bool extendRouteToDestinationsT(route::FullRoute &route, const std::vector<T> &dest)
{
  route::planning::RoutingParaPoint routeExtensionStartPoint;
  route::LaneSegment extensionReferenceLaneSegment;
  if (!prepareRouteForExtension(route, routeExtensionStartPoint, extensionReferenceLaneSegment))
  {
    return false;
  }

  auto routeExtension = route::planning::planRoute(routeExtensionStartPoint, dest, route.route_creation_mode);

  route = mergeRouteExtension(route, extensionReferenceLaneSegment, routeExtension);

  return true;
}

bool extendRouteToDestinations(route::FullRoute &route, const std::vector<route::planning::RoutingParaPoint> &dest)
{
  return extendRouteToDestinationsT(route, dest);
}

bool extendRouteToDestinations(route::FullRoute &route, const point::GeoPointList &dest)
{
  return extendRouteToDestinationsT(route, dest);
}

bool extendRouteToDestinations(route::FullRoute &route, const point::ENUPointList &dest)
{
  return extendRouteToDestinationsT(route, dest);
}

bool extendRouteToDistance(route::FullRoute &route,
                           const physics::Distance &length,
                           route::FullRouteList &additionalRoutes,
                           ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  if (!additionalRoutes.empty())
  {
    access::getLogger()->error("ad::map::route::extendRouteToDistance: additional Routes parameter is not empty, "
                               "containing {} elements. Aborting.",
                               additionalRoutes.size());
    return false;
  }

  // check length of route and abort if long enough
  auto routeLength = route::calcLength(route);
  auto distance = length - routeLength;
  if (distance < physics::Distance(0))
  {
    return true;
  }

  route::planning::RoutingParaPoint routeExtensionStartPoint;
  route::LaneSegment extensionReferenceLaneSegment;
  if (!prepareRouteForExtension(route, routeExtensionStartPoint, extensionReferenceLaneSegment))
  {
    return false;
  }

  distance += route::calcLength(extensionReferenceLaneSegment.lane_interval);

  // the shorter version of the route is kept to obey
  // potential intersections which already might have been entered by one of the prediction paths e.g.
  // because of a slightly shorter lane entering in that intersection arm
  auto routeExtensions
    = route::planning::predictRoutesOnDistance(routeExtensionStartPoint,
                                               distance,
                                               route.route_creation_mode,
                                               planning::FilterDuplicatesMode::SubRoutesPreferShorterOnes,
                                               relevantLanes);

  auto it = routeExtensions.begin();
  if (it != routeExtensions.end())
  {
    ++it;
  }
  for (; it != routeExtensions.end(); ++it)
  {
    auto const &routeExtension = *it;
    auto newRoute = mergeRouteExtension(route, extensionReferenceLaneSegment, routeExtension);
    additionalRoutes.push_back(newRoute);
  }

  // extend route itself
  if (routeExtensions.size() > 0)
  {
    auto const &routeExtension = routeExtensions.front();
    route = mergeRouteExtension(route, extensionReferenceLaneSegment, routeExtension);
  }

  return true;
}

void shortenSegmentFromBegin(RoadSegment &roadSegment, physics::Distance const &distance)
{
  if (roadSegment.drivable_lane_segments.empty())
  {
    throw std::runtime_error("ad::map::route::shortenSegmentFromBegin>> Route inconsistent: "
                             "route contains no drivable_lane_segments");
  }

  auto shortenedInterval = shortenIntervalFromBegin(roadSegment.drivable_lane_segments.front().lane_interval, distance);
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.lane_interval.start = shortenedInterval.start;
  }
}

void shortenSegmentFromEnd(RoadSegment &roadSegment, physics::Distance const &distance)
{
  if (roadSegment.drivable_lane_segments.empty())
  {
    throw std::runtime_error("ad::map::route::shortenSegmentFromBegin>> Route inconsistent: "
                             "route contains no drivable_lane_segments");
  }

  auto shortenedInterval = shortenIntervalFromEnd(roadSegment.drivable_lane_segments.front().lane_interval, distance);
  for (auto &laneSegment : roadSegment.drivable_lane_segments)
  {
    laneSegment.lane_interval.end = shortenedInterval.end;
  }
}

bool calculateRouteParaPointAtDistance(route::FullRoute const &route,
                                       route::RouteParaPoint const &origin,
                                       physics::Distance const &distance,
                                       route::RouteParaPoint &resultingPoint)
{
  RouteIterator routeIterator = getRouteIterator(origin, route);

  physics::Distance accumulatedDistance(0.);

  bool routeParaPointFound = false;

  while (!routeParaPointFound && routeIterator.isValid())
  {
    physics::ParametricValue originOffset(0.);
    const physics::Distance segmentLength = calcLength((*routeIterator.roadSegmentIterator));

    physics::Distance distanceToSegmentBorder = segmentLength;
    if (routeIterator.roadSegmentIterator->segment_count_from_destination == origin.segment_count_from_destination)
    {
      originOffset = origin.parametric_offset;
      if (distance < physics::Distance(0))
      {
        distanceToSegmentBorder = segmentLength * (origin.parametric_offset);
      }
      else
      {
        distanceToSegmentBorder = segmentLength * (physics::ParametricValue(1.0) - origin.parametric_offset);
      }
    }
    else
    {
      if (distance < physics::Distance(0))
      {
        originOffset = physics::ParametricValue(1.);
      }
    }

    if ((accumulatedDistance + distanceToSegmentBorder) >= std::fabs(distance))
    {
      physics::Distance const remainingLength = std::fabs(distance) - accumulatedDistance;

      resultingPoint.route_planning_counter = route.route_planning_counter;
      resultingPoint.segment_count_from_destination = routeIterator.roadSegmentIterator->segment_count_from_destination;
      physics::ParametricValue delta(remainingLength / segmentLength);
      if (distance < physics::Distance(0))
      {
        resultingPoint.parametric_offset = originOffset - delta;
      }
      else
      {
        resultingPoint.parametric_offset = originOffset + delta;
      }
      accumulatedDistance = std::fabs(distance);
      routeParaPointFound = true;
    }
    else
    {
      accumulatedDistance += distanceToSegmentBorder;
    }

    if (distance < physics::Distance(0))
    {
      if (routeIterator.roadSegmentIterator != std::begin(routeIterator.route.road_segments))
      {
        routeIterator.roadSegmentIterator--;
      }
      else
      {
        routeIterator.roadSegmentIterator = std::end(routeIterator.route.road_segments);
      }
    }
    else
    {
      routeIterator.roadSegmentIterator++;
    }
  }

  return routeParaPointFound;
}

bool getRouteParaPointFromParaPoint(point::ParaPoint const &para_point,
                                    FullRoute const &route,
                                    route::RouteParaPoint &routeParaPoint)
{
  auto const waypointResult = route::findWaypoint(para_point, route);

  if (!waypointResult.isValid())
  {
    return false;
  }

  routeParaPoint.route_planning_counter = route.route_planning_counter;
  routeParaPoint.segment_count_from_destination = waypointResult.roadSegmentIterator->segment_count_from_destination;
  routeParaPoint.parametric_offset
    = std::fabs(para_point.parametric_offset - waypointResult.laneSegmentIterator->lane_interval.start);

  return true;
}

route::FullRoute getRouteExpandedTo(route::FullRoute const &route, RouteCreationMode const route_creation_mode)
{
  route::FullRoute expandedRoute;
  expandedRoute.route_creation_mode = route_creation_mode;
  for (const auto &roadSegment : route.road_segments)
  {
    if (!roadSegment.drivable_lane_segments.empty())
    {
      appendRoadSegmentToRoute(roadSegment.drivable_lane_segments.front().lane_interval,
                               roadSegment.drivable_lane_segments.front().route_lane_offset,
                               expandedRoute,
                               {});
    }
  }
  planning::updateRoutePlanningCounters(expandedRoute);

  if (!route.road_segments.empty())
  {
    if (!route.road_segments.front().drivable_lane_segments.empty())
    {
      point::ParaPoint const alignmentParaPoint
        = getIntervalStart(route.road_segments.front().drivable_lane_segments.front().lane_interval);
      alignRouteStartingPoints(alignmentParaPoint, expandedRoute);
    }
    if (!route.road_segments.back().drivable_lane_segments.empty())
    {
      point::ParaPoint const alignmentParaPoint
        = getIntervalEnd(route.road_segments.back().drivable_lane_segments.front().lane_interval);
      alignRouteEndingPoints(alignmentParaPoint, expandedRoute);
    }
  }

  return expandedRoute;
}

FullRoute getRouteSection(FindWaypointResult const &currentLane,
                          physics::Distance const &distanceFront,
                          physics::Distance const &distanceEnd,
                          FullRoute const &route,
                          RouteSectionCreationMode const routeSectionCreationMode)
{
  FullRoute resultRoute;
  if (!currentLane.isValid() || (&currentLane.queryRoute != &route))
  {
    return resultRoute;
  }
  resultRoute.full_route_segment_count = route.full_route_segment_count;
  resultRoute.route_planning_counter = route.route_planning_counter;

  LaneSegment currentLaneSegment = *currentLane.laneSegmentIterator;

  LaneInterval currentStartInterval;
  currentStartInterval.lane_id = currentLane.laneSegmentIterator->lane_interval.lane_id;
  currentStartInterval.start = currentLane.laneSegmentIterator->lane_interval.start;
  currentStartInterval.end = currentLane.queryPosition.parametric_offset;

  physics::Distance accumulatedDistanceFront = calcLength(currentStartInterval);

  if (accumulatedDistanceFront >= distanceFront)
  {
    currentLaneSegment.lane_interval
      = shortenIntervalFromBegin(currentLaneSegment.lane_interval, accumulatedDistanceFront - distanceFront);
    accumulatedDistanceFront = distanceFront;
  }
  else
  {
    auto currentPredecessors = currentLane.getPredecessorLanes();
    while ( // required distance not yet reached
      (accumulatedDistanceFront < distanceFront)
      // there are still predecessors available
      && (!currentPredecessors.empty()))
    {
      // another road segment will be added
      route::RoadSegment newRoadSegment;
      newRoadSegment.bounding_sphere = currentPredecessors[0].roadSegmentIterator->bounding_sphere;
      newRoadSegment.segment_count_from_destination
        = currentPredecessors[0].roadSegmentIterator->segment_count_from_destination;

      std::vector<FindWaypointResult> nextPredecessors;
      for (auto const &predecessor : currentPredecessors)
      {
        newRoadSegment.drivable_lane_segments.push_back(*predecessor.laneSegmentIterator);
        auto const furtherPredecessors = predecessor.getPredecessorLanes();
        nextPredecessors.insert(
          std::end(nextPredecessors), std::begin(furtherPredecessors), std::end(furtherPredecessors));
      }

      auto currentSegmentLength = calcLength(newRoadSegment);
      if (accumulatedDistanceFront + currentSegmentLength > distanceFront)
      {
        route::shortenSegmentFromBegin(newRoadSegment, accumulatedDistanceFront + currentSegmentLength - distanceFront);
        accumulatedDistanceFront = distanceFront;
      }
      else
      {
        accumulatedDistanceFront += currentSegmentLength;
      }

      access::getLogger()->trace("ad::map::route::getRouteSection: prepending road segment {}: {} ({})",
                                 newRoadSegment,
                                 accumulatedDistanceFront,
                                 distanceFront);
      resultRoute.road_segments.insert(std::begin(resultRoute.road_segments), newRoadSegment);

      // prepare for next cycle
      currentPredecessors.swap(nextPredecessors);
    }
  }

  LaneInterval currentEndInterval;
  currentEndInterval.lane_id = currentLane.laneSegmentIterator->lane_interval.lane_id;
  currentEndInterval.start = currentLane.queryPosition.parametric_offset;
  currentEndInterval.end = currentLane.laneSegmentIterator->lane_interval.end;

  physics::Distance accumulatedDistanceEnd = calcLength(currentEndInterval);
  if (accumulatedDistanceEnd >= distanceEnd)
  {
    currentLaneSegment.lane_interval
      = shortenIntervalFromEnd(currentLaneSegment.lane_interval, accumulatedDistanceEnd - distanceEnd);
    accumulatedDistanceEnd = distanceEnd;
  }
  else
  {
    currentLaneSegment.lane_interval.end = currentEndInterval.end;
  }

  // current road segment is added
  route::RoadSegment currentRoadSegment;
  currentRoadSegment.bounding_sphere = currentLane.roadSegmentIterator->bounding_sphere;
  currentRoadSegment.segment_count_from_destination = currentLane.roadSegmentIterator->segment_count_from_destination;
  currentRoadSegment.drivable_lane_segments.push_back(currentLaneSegment);
  access::getLogger()->trace("ad::map::route::getRouteSection: appending current road segment {}: {}({}) -> {}({})",
                             currentRoadSegment,
                             accumulatedDistanceFront,
                             distanceFront,
                             accumulatedDistanceEnd,
                             distanceEnd);
  resultRoute.road_segments.insert(std::end(resultRoute.road_segments), currentRoadSegment);

  auto currentSuccessors = currentLane.getSuccessorLanes();
  while ( // required distance not yet reached
    (accumulatedDistanceEnd < distanceEnd)
    // there are still successors available
    && (!currentSuccessors.empty()))
  {
    // another road segment will be added
    route::RoadSegment newRoadSegment;
    newRoadSegment.bounding_sphere = currentSuccessors[0].roadSegmentIterator->bounding_sphere;
    newRoadSegment.segment_count_from_destination
      = currentSuccessors[0].roadSegmentIterator->segment_count_from_destination;

    std::vector<FindWaypointResult> nextSuccessors;
    for (auto const &successor : currentSuccessors)
    {
      newRoadSegment.drivable_lane_segments.push_back(*successor.laneSegmentIterator);
      auto const furtherSuccessors = successor.getSuccessorLanes();
      nextSuccessors.insert(std::end(nextSuccessors), std::begin(furtherSuccessors), std::end(furtherSuccessors));
    }

    auto currentSegmentLength = calcLength(newRoadSegment);
    if (accumulatedDistanceEnd + currentSegmentLength > distanceEnd)
    {
      route::shortenSegmentFromEnd(newRoadSegment, accumulatedDistanceEnd + currentSegmentLength - distanceEnd);
      accumulatedDistanceEnd = distanceEnd;
    }
    else
    {
      accumulatedDistanceEnd += currentSegmentLength;
    }

    access::getLogger()->trace("ad::map::route::getRouteSection: appending road segment {}: {} ({})",
                               newRoadSegment,
                               accumulatedDistanceEnd,
                               distanceEnd);
    resultRoute.road_segments.insert(std::end(resultRoute.road_segments), newRoadSegment);

    // prepare for next cycle
    currentSuccessors.swap(nextSuccessors);
  }

  access::getLogger()->trace("ad::map::route::getRouteSection: result before update lane connections {}", resultRoute);
  updateLaneConnections(resultRoute);

  if (routeSectionCreationMode == RouteSectionCreationMode::AllRouteLanes)
  {
    resultRoute = getRouteExpandedTo(resultRoute, route.route_creation_mode);
  }

  access::getLogger()->debug("ad::map::route::getRouteSection({} < {}:{} > {} ) {}",
                             distanceFront,
                             currentLane.laneSegmentIterator->lane_interval.lane_id,
                             currentLane.queryPosition.parametric_offset,
                             distanceEnd,
                             resultRoute);

  return resultRoute;
}

FullRoute getRouteSection(point::ParaPoint const &center_point,
                          physics::Distance const &distanceFront,
                          physics::Distance const &distanceEnd,
                          FullRoute const &route,
                          RouteSectionCreationMode const routeSectionCreationMode)
{
  return getRouteSection(
    findWaypoint(center_point, route), distanceFront, distanceEnd, route, routeSectionCreationMode);
}

FullRoute getRouteSection(match::Object const &object,
                          FullRoute const &route,
                          RouteSectionCreationMode const routeSectionCreationMode)
{
  auto const objectCenterPointOnRoute = findCenterWaypoint(object, route);
  auto const routeAroundVehicle = getRouteSection(objectCenterPointOnRoute,
                                                  object.enu_position.dimension.length,
                                                  object.enu_position.dimension.length,
                                                  route,
                                                  routeSectionCreationMode);
  return routeAroundVehicle;
}

FindLaneChangeResult::FindLaneChangeResult(FullRoute const &route)
  : queryRoute(route)
  , laneChangeStartRouteIterator(queryRoute.road_segments.end())
  , laneChangeEndRouteIterator(queryRoute.road_segments.end())
  , laneChangeDirection(LaneChangeDirection::Invalid)
{
}

physics::Distance FindLaneChangeResult::calcZoneLength() const
{
  physics::Distance distance(0.);
  if (isValid())
  {
    for (auto roadSegmentIter = laneChangeStartRouteIterator; roadSegmentIter < laneChangeEndRouteIterator;
         roadSegmentIter++)
    {
      distance += calcLength(*roadSegmentIter);
    }
    distance += calcLength(*laneChangeEndRouteIterator);
  }
  return distance;
}

FindLaneChangeResult findFirstLaneChange(match::MapMatchedPosition const &currentPosition,
                                         route::FullRoute const &route)
{
  // this is what we want to return. Two indices defining the start and the end of the lane change
  FindLaneChangeResult result(route);

  // first, find the iterator where the first lane change needs to be finished at the latest. If the target lane is
  // always blocked the user of this function may want to set a stop line at the routeIteratorLaneChangeEnd. To do
  // this,
  // - we travel along the successors starting from the current position as long as we can
  // - if the next route section is not reachable by successors and is not the end of the route, we found the lane
  //   change end and traverse along the route in the other direction to find the lane change start
  // - if we can travel along the whole route without changing lanes, we return an invalid result (since there is no
  //   lane change on this route segment)
  FindWaypointResult const findWaypointResult = findWaypoint(currentPosition.lane_point.para_point, route);

  if (!findWaypointResult.isValid())
  {
    if (!route.road_segments.empty())
    {
      access::getLogger()->error(
        "ad::map::route::findFirstLaneChange: Current position is not part of the route {} {}", currentPosition, route);
    }
    // returning an invalid result (as if no lane change was found)
    return result;
  }

  // find the potential end of the lane change
  // if there is no successor, the lane change has to end
  // and if there is more than one successor, the lane change has to end, too
  auto laneChangeEndResult = findWaypointResult;
  for (auto successorLanes = findWaypointResult.getSuccessorLanes(); successorLanes.size() == 1u;
       successorLanes = successorLanes[0].getSuccessorLanes())
  {
    laneChangeEndResult = successorLanes[0];
  }

  // Find the transition lane, to which we need to change to be able to get to the next road segment.
  // The closest neighbor lane to laneChangeEndResult having any successors
  FindWaypointResult right_neighbor(route);
  std::size_t rightNeighborDistance = 0u;
  for (auto neighbor = laneChangeEndResult.getRightLane(); neighbor.isValid(); neighbor = neighbor.getRightLane())
  {
    rightNeighborDistance++;
    if (!neighbor.getSuccessorLanes().empty())
    {
      right_neighbor = neighbor;
      break;
    }
  }

  FindWaypointResult left_neighbor(route);
  std::size_t leftNeighborDistance = 0u;
  for (auto neighbor = laneChangeEndResult.getLeftLane(); neighbor.isValid(); neighbor = neighbor.getLeftLane())
  {
    leftNeighborDistance++;
    if (!neighbor.getSuccessorLanes().empty())
    {
      left_neighbor = neighbor;
      break;
    }
  }

  FindWaypointResult transitionEndLane(route);
  if (left_neighbor.isValid() && right_neighbor.isValid())
  {
    if (leftNeighborDistance < rightNeighborDistance)
    {
      transitionEndLane = left_neighbor;
      result.laneChangeDirection = LaneChangeDirection::RightToLeft;
    }
    else
    {
      transitionEndLane = right_neighbor;
      result.laneChangeDirection = LaneChangeDirection::LeftToRight;
    }
  }
  else if (left_neighbor.isValid())
  {
    transitionEndLane = left_neighbor;
    result.laneChangeDirection = LaneChangeDirection::RightToLeft;
  }
  else if (right_neighbor.isValid())
  {
    transitionEndLane = right_neighbor;
    result.laneChangeDirection = LaneChangeDirection::LeftToRight;
  }
  else
  {
    // there is no lane change at all, since no neighbor has any successor
    access::getLogger()->trace("ad::map::route::no lane change required {} {}", currentPosition, route);
    return result;
  }

  // we found an actual lane change
  result.laneChangeEndRouteIterator = transitionEndLane.roadSegmentIterator;
  result.laneChangeEndLaneSegmentIterator = transitionEndLane.laneSegmentIterator;

  // now, traverse back to the beginning (currentPosiion) from the transition lane
  // if there is no predecessor, the lane change has to begin latest there
  // and if there is more than one predecessor, the lane change has to begin there, too
  bool currentPositionReached = false;

  while (!currentPositionReached)
  {
    auto laneChangeBeginResult = transitionEndLane;
    for (auto predecessorLanes = transitionEndLane.getPredecessorLanes(); predecessorLanes.size() == 1u;
         predecessorLanes = predecessorLanes[0].getPredecessorLanes())
    {
      laneChangeBeginResult = predecessorLanes[0];
    }

    FindWaypointResult transitionStartLane(route);
    if (result.laneChangeDirection == LaneChangeDirection::LeftToRight)
    {
      transitionStartLane = laneChangeBeginResult.getLeftLane();
    }
    else
    {
      transitionStartLane = laneChangeBeginResult.getRightLane();
    }
    if (!transitionStartLane.isValid())
    {
      access::getLogger()->error("ad::map::route::findFirstLaneChange: cannot find valid transition start lane at lane "
                                 "change, begin: {} with lane change direction {} and route: {}",
                                 laneChangeBeginResult.laneSegmentIterator->lane_interval.lane_id,
                                 result.laneChangeDirection,
                                 route);

      // returning an invalid result (as if no lane change was found)
      return result;
    }

    result.laneChangeStartRouteIterator = transitionStartLane.roadSegmentIterator;
    result.laneChangeStartLaneSegmentIterator = transitionStartLane.laneSegmentIterator;

    access::getLogger()->debug("ad::map::route::findFirstLaneChange: found valid lane change {} starting at {}  "
                               "lane_id[] {} ending at {}  lane_id[] {} input position {} and route {}",
                               result.laneChangeDirection,
                               *result.laneChangeStartRouteIterator,
                               result.laneChangeStartLaneSegmentIterator->lane_interval.lane_id,
                               *result.laneChangeEndRouteIterator,
                               result.laneChangeEndLaneSegmentIterator->lane_interval.lane_id,
                               currentPosition,
                               route);

    if (result.laneChangeStartLaneSegmentIterator->lane_interval.lane_id
        == currentPosition.lane_point.para_point.lane_id)
    {
      currentPositionReached = true;
    }
    else
    {
      result.laneChangeEndRouteIterator = result.laneChangeStartRouteIterator;
      result.laneChangeEndLaneSegmentIterator = result.laneChangeStartLaneSegmentIterator;
      transitionEndLane.laneSegmentIterator = result.laneChangeEndLaneSegmentIterator;
      transitionEndLane.roadSegmentIterator = result.laneChangeStartRouteIterator;
    }

    result.numberOfConnectedLaneChanges++;
  }

  return result;
}

void addLaneIdUnique(lane::LaneIdList &laneIds, lane::LaneId const lane_id)
{
  auto findResult = std::find(std::begin(laneIds), std::end(laneIds), lane_id);
  if (findResult == std::end(laneIds))
  {
    laneIds.push_back(lane_id);
  }
}

void addRoutePredecessorRelationToNewSegment(lane::Lane const &lane,
                                             route::LaneSegment &laneSegment,
                                             route::FullRoute &route,
                                             bool routeDirectionPositive)
{
  if (route.road_segments.empty())
  {
    return;
  }
  for (auto predecessorLaneContact : lane::getContactLanes(
         lane, routeDirectionPositive ? lane::ContactLocation::PREDECESSOR : lane::ContactLocation::SUCCESSOR))
  {
    auto predecessorLaneId = predecessorLaneContact.to_lane;
    auto predecessorLaneSegmentIter = std::find_if(std::begin(route.road_segments.back().drivable_lane_segments),
                                                   std::end(route.road_segments.back().drivable_lane_segments),
                                                   [&predecessorLaneId](route::LaneSegment const &innerLaneSegment) {
                                                     return innerLaneSegment.lane_interval.lane_id == predecessorLaneId;
                                                   });

    if (predecessorLaneSegmentIter != std::end(route.road_segments.back().drivable_lane_segments))
    {
      addLaneIdUnique(predecessorLaneSegmentIter->successors, laneSegment.lane_interval.lane_id);
      addLaneIdUnique(laneSegment.predecessors, predecessorLaneId);
      laneSegment.route_lane_offset = predecessorLaneSegmentIter->route_lane_offset;
    }
  }
}

bool isRightNeighbor(lane::ContactLocation const contactLocation, bool const isRouteDirectionPositive)
{
  bool right_neighbor;
  // determine the neighborhood relationship in respect to route direction
  if (contactLocation == lane::ContactLocation::RIGHT)
  {
    right_neighbor = isRouteDirectionPositive;
  }
  else // contactLocation == core::ContactLocation::LEFT
  {
    right_neighbor = !isRouteDirectionPositive;
  }
  return right_neighbor;
}

void updateRouteLaneOffsetRange(RouteLaneOffset const &route_lane_offset, FullRoute &route)
{
  if (route_lane_offset > route.max_lane_offset)
  {
    route.max_lane_offset = route_lane_offset;
  }
  if (route_lane_offset < route.min_lane_offset)
  {
    route.min_lane_offset = route_lane_offset;
  }
}

void updateRouteLaneOffset(bool const right_neighbor, RouteLaneOffset &route_lane_offset, FullRoute &route)
{
  if (right_neighbor)
  {
    route_lane_offset--;
  }
  else
  {
    route_lane_offset++;
  }
  updateRouteLaneOffsetRange(route_lane_offset, route);
}

void appendLaneSegmentToRoute(route::LaneInterval const &lane_interval,
                              route::FullRoute &route,
                              route::SegmentCounter const segment_count_from_destination)
{
  auto lane = lane::getLane(lane_interval.lane_id);

  route::RoadSegment roadSegment;
  roadSegment.bounding_sphere = lane.bounding_sphere;
  roadSegment.segment_count_from_destination = segment_count_from_destination;

  bool const routeDirectionPositive = isRouteDirectionPositive(lane_interval);

  route::LaneSegment laneSegment;
  laneSegment.lane_interval = lane_interval;

  addRoutePredecessorRelationToNewSegment(lane, laneSegment, route, routeDirectionPositive);

  roadSegment.drivable_lane_segments.push_back(laneSegment);
  route.road_segments.push_back(roadSegment);
}

void appendRoadSegmentToRoute(route::LaneInterval const &lane_interval,
                              route::RouteLaneOffset const &route_lane_offset,
                              FullRoute &route,
                              lane::LaneIdSet const &relevantLanes)
{
  auto lane = lane::getLane(lane_interval.lane_id);

  route::RoadSegment roadSegment;
  roadSegment.bounding_sphere = lane.bounding_sphere;
  // this information will be post processed by updateRoutePlanningCounters()
  roadSegment.segment_count_from_destination = 0u;

  const bool routeDirectionPositive = isRouteDirectionPositive(lane_interval);

  route::LaneSegment laneSegment;
  laneSegment.lane_interval = lane_interval;
  laneSegment.route_lane_offset = route_lane_offset;
  updateRouteLaneOffsetRange(route_lane_offset, route);
  addRoutePredecessorRelationToNewSegment(lane, laneSegment, route, routeDirectionPositive);
  roadSegment.drivable_lane_segments.push_back(laneSegment);

  lane::LaneDirection const direction = lane.direction;
  for (auto contactLocation : {lane::ContactLocation::LEFT, lane::ContactLocation::RIGHT})
  {
    route::RouteLaneOffset currentRouteLaneOffset = route_lane_offset;
    bool const right_neighbor = isRightNeighbor(contactLocation, routeDirectionPositive);
    lane::ContactLaneList contact_lanes = lane::getContactLanes(lane, contactLocation);

    lane::LaneIdSet visitedLaneIds;
    visitedLaneIds.insert(lane_interval.lane_id);

    // we expect that per map model only one contact lane is possible in one direction
    while (contact_lanes.size() == 1u)
    {
      // in some broken map cases we could end in an infinite loop here, due to broken neighborhood relations
      // to avoid this issue, add an early return upon detecting the start lane again
      lane::LaneId otherLaneId = contact_lanes.front().to_lane;

      if (!isLaneRelevantForExpansion(otherLaneId, relevantLanes))
      {
        // stop expansion
        contact_lanes.clear();
        break;
      }

      auto laneNotVisited = visitedLaneIds.insert(otherLaneId);
      if (!laneNotVisited.second)
      {
        access::getLogger()->warn("ad::map::route::appendRoadSegmentToRoute: Broken neighborhood relations detected "
                                  "for LaneId {}, Skipping expansion.",
                                  lane_interval.lane_id);
        contact_lanes.clear();
        break;
      }

      auto const &otherLane = lane::getLane(otherLaneId);
      if (((route.route_creation_mode == RouteCreationMode::SameDrivingDirection) && (lane::isRouteable(otherLane))
           && (direction == otherLane.direction))
          || ((route.route_creation_mode == RouteCreationMode::AllRoutableLanes) && (lane::isRouteable(otherLane)))
          || (route.route_creation_mode == RouteCreationMode::AllNeighborLanes))
      {
        route::LaneSegment newLaneSegment;
        newLaneSegment.lane_interval.lane_id = otherLaneId;
        newLaneSegment.lane_interval.start = lane_interval.start;
        newLaneSegment.lane_interval.end = lane_interval.end;
        if (direction == otherLane.direction)
        {
          newLaneSegment.lane_interval.wrong_way = lane_interval.wrong_way;
        }
        else
        {
          newLaneSegment.lane_interval.wrong_way = !lane_interval.wrong_way;
        }
        updateRouteLaneOffset(right_neighbor, currentRouteLaneOffset, route);
        newLaneSegment.route_lane_offset = currentRouteLaneOffset;

        roadSegment.bounding_sphere = roadSegment.bounding_sphere + otherLane.bounding_sphere;

        addRoutePredecessorRelationToNewSegment(otherLane, newLaneSegment, route, routeDirectionPositive);

        // sorting: right lanes are added at front, left lanes at back
        if (right_neighbor)
        {
          roadSegment.drivable_lane_segments.front().right_neighbor = newLaneSegment.lane_interval.lane_id;
          newLaneSegment.left_neighbor = roadSegment.drivable_lane_segments.front().lane_interval.lane_id;
          roadSegment.drivable_lane_segments.insert(roadSegment.drivable_lane_segments.begin(), newLaneSegment);
        }
        else
        {
          roadSegment.drivable_lane_segments.back().left_neighbor = newLaneSegment.lane_interval.lane_id;
          newLaneSegment.right_neighbor = roadSegment.drivable_lane_segments.back().lane_interval.lane_id;
          roadSegment.drivable_lane_segments.insert(roadSegment.drivable_lane_segments.end(), newLaneSegment);
        }

        // go aside recursively
        contact_lanes = lane::getContactLanes(otherLane, contactLocation);
      }
      else
      {
        contact_lanes.clear();
      }
    }
    if (!contact_lanes.empty())
    {
      throw std::runtime_error(
        "AdRoadNetworkAdm::fillRoadSegment algorithm is not able to handle multiple left/right contact lanes");
    }
  }
  route.road_segments.push_back(roadSegment);
}

physics::Distance addOpposingLaneSegmentToRoadSegment(point::ParaPoint const &startpoint,
                                                      physics::Distance const &distance,
                                                      route::RoadSegment &roadSegment,
                                                      route::FullRoute &route)
{
  if (roadSegment.drivable_lane_segments.empty())
  {
    return physics::Distance(-1.);
  }

  route::LaneInterval lane_interval;
  lane_interval.lane_id = startpoint.lane_id;
  lane_interval.start = startpoint.parametric_offset;
  lane_interval.end = roadSegment.drivable_lane_segments[0].lane_interval.end;

  // the lane segment we want to add is opposing the current road segment
  // for right-hand traffic this means, the lane segment is left of the left-most lane segment
  // for left-hand traffic this is the segment right of the right-most lane segment
  LaneSegmentList::iterator neighborIterator;
  if (!access::isLeftHandedTraffic())
  {
    // sorting: right lanes are added at front, left lanes at back
    neighborIterator = roadSegment.drivable_lane_segments.end() - 1;
  }
  else
  {
    neighborIterator = roadSegment.drivable_lane_segments.begin();
  }
  lane_interval.end = neighborIterator->lane_interval.end;

  // let's ensure that the lane segment is neighbor of the provided road segment
  auto const neighborhood
    = getDirectNeighborhoodRelation(lane_interval.lane_id, neighborIterator->lane_interval.lane_id);
  if ((neighborhood != lane::ContactLocation::LEFT) && (neighborhood != lane::ContactLocation::RIGHT))
  {
    return physics::Distance(-1.);
  }

  // determine wrong way flag
  if (lane::isLaneDirectionPositive(neighborIterator->lane_interval.lane_id)
      == lane::isLaneDirectionPositive(lane_interval.lane_id))
  {
    lane_interval.wrong_way = neighborIterator->lane_interval.wrong_way;
  }
  else
  {
    lane_interval.wrong_way = !neighborIterator->lane_interval.wrong_way;
  }

  lane_interval = route::restrictIntervalFromBegin(lane_interval, distance);

  route::LaneSegment laneSegment;
  laneSegment.lane_interval = lane_interval;
  laneSegment.route_lane_offset = neighborIterator->route_lane_offset;

  if (!access::isLeftHandedTraffic())
  {
    laneSegment.right_neighbor = neighborIterator->lane_interval.lane_id;
    neighborIterator->left_neighbor = lane_interval.lane_id;
    updateRouteLaneOffset(false, laneSegment.route_lane_offset, route);
    roadSegment.drivable_lane_segments.push_back(laneSegment);
  }
  else
  {
    laneSegment.left_neighbor = neighborIterator->lane_interval.lane_id;
    neighborIterator->right_neighbor = lane_interval.lane_id;
    updateRouteLaneOffset(true, laneSegment.route_lane_offset, route);
    roadSegment.drivable_lane_segments.insert(roadSegment.drivable_lane_segments.begin(), laneSegment);
  }

  return route::calcLength(lane_interval);
}

bool addOpposingLaneToRoute(point::ParaPoint const &pointOnOppositeLane,
                            physics::Distance const &distanceOnWrongLane,
                            route::FullRoute &route,
                            physics::Distance &coveredDistance)
{
  coveredDistance = physics::Distance(0.);
  uint32_t segmentCounter = 0;
  point::ParaPoint startPoint = pointOnOppositeLane;

  if (route.road_segments.empty())
  {
    return false;
  }

  auto startWayPoint = findWaypoint(startPoint, route);
  if (startWayPoint.isValid())
  {
    if (std::find_if(
          route.road_segments[0].drivable_lane_segments.begin(),
          route.road_segments[0].drivable_lane_segments.end(),
          [&startPoint](const route::LaneSegment &l) { return l.lane_interval.lane_id == startPoint.lane_id; })
        != route.road_segments[0].drivable_lane_segments.end())
    {
      // point is already on route
      return false;
    }
  }

  while (coveredDistance < distanceOnWrongLane)
  {
    auto segmentDistance = route::addOpposingLaneSegmentToRoadSegment(
      startPoint, distanceOnWrongLane, route.road_segments[segmentCounter], route);

    if (segmentDistance < physics::Distance(0.))
    {
      return false;
    }

    coveredDistance += segmentDistance;

    if (coveredDistance < distanceOnWrongLane)
    {
      lane::ContactLaneList successors;
      if (route::isRouteDirectionNegative(route.road_segments[segmentCounter].drivable_lane_segments[0].lane_interval))
      {
        // get predecessor, if there are multiple its an intersection so stop
        successors = lane::getContactLanes(lane::getLane(startPoint.lane_id), lane::ContactLocation::PREDECESSOR);
      }
      else
      {
        // get successor, if there are multiple its an intersection so stop
        successors = lane::getContactLanes(lane::getLane(startPoint.lane_id), lane::ContactLocation::SUCCESSOR);
      }

      segmentCounter++;

      if ((successors.size() == 0) || (successors.size() > 1) || (segmentCounter == route.road_segments.size()))
      {
        break;
      }

      startPoint.lane_id = successors[0].to_lane;
      startPoint.parametric_offset = route.road_segments[segmentCounter].drivable_lane_segments[0].lane_interval.start;

      if (intersection::Intersection::isLanePartOfAnIntersection(startPoint.lane_id))
      {
        break;
      }
    }
  }

  return true;
}

bool calculateBypassingRoute(route::FullRoute const &route, route::FullRoute &bypassingRoute)
{
  bypassingRoute = route::FullRoute();

  for (const auto &segment : route.road_segments)
  {
    if (segment.drivable_lane_segments.empty())
    {
      // this should not happen
      // better avoid to passing
      return false;
    }

    // select the most outer relevant lane segment
    // that is for left-hand traffic the right most segment
    // that is for right-hand traffic the left most segment
    LaneSegment laneSegment;
    if (access::isLeftHandedTraffic())
    {
      laneSegment = segment.drivable_lane_segments.front();
    }
    else
    {
      laneSegment = segment.drivable_lane_segments.back();
    }

    // depending on the lane orientation and the driving direction (left-hand vs. right-hand)
    // the bypassingRoute has to use the left or right neighbor segments
    bool useLeftNeighbor = isRouteDirectionPositive(laneSegment.lane_interval);
    useLeftNeighbor = useLeftNeighbor ^ access::isLeftHandedTraffic();

    auto lane = lane::getLane(laneSegment.lane_interval.lane_id);
    lane::ContactLaneList contact_lanes;
    if (useLeftNeighbor)
    {
      contact_lanes = lane::getContactLanes(lane, lane::ContactLocation::LEFT);
    }
    else
    {
      contact_lanes = lane::getContactLanes(lane, lane::ContactLocation::RIGHT);
    }

    if (contact_lanes.empty())
    {
      // there are no neighbors, thus no bypass option
      return false;
    }

    auto neighborLaneId = contact_lanes.front().to_lane;
    auto neighborLane = lane::getLane(neighborLaneId);
    if (lane::isLanePartOfAnIntersection(neighborLane))
    {
      return false;
    }

    route::LaneInterval neighborLaneInterval = laneSegment.lane_interval;
    neighborLaneInterval.lane_id = neighborLaneId;
    if (lane.direction != neighborLane.direction)
    {
      neighborLaneInterval.wrong_way = !neighborLaneInterval.wrong_way;
    }
    route::appendLaneSegmentToRoute(neighborLaneInterval, bypassingRoute);
  }

  for (size_t i = 0; i < bypassingRoute.road_segments.size(); ++i)
  {
    bypassingRoute.road_segments[i].segment_count_from_destination = bypassingRoute.road_segments.size() - i;
  }

  return true;
}

// let's keep this for the moment like this with the internal inline function
// we will have to rework the border calculation in each case
// - add TRange instead of TParam...
// - consider the laneIntervals directly instead of the whole segment
inline LaneInterval
cutLaneIntervalAtEndByRoadSegmentParametricOffset(LaneInterval const &interval,
                                                  physics::ParametricValue const segmentParametricOffset)
{
  physics::ParametricValue laneParametricOffset = segmentParametricOffset;
  if (isRouteDirectionNegative(interval))
  {
    laneParametricOffset = physics::ParametricValue(1.) - segmentParametricOffset;
  }
  return cutIntervalAtEnd(interval, laneParametricOffset);
}

template <typename BorderType>
void getBorderOfRoadSegment(RoadSegment const &roadSegment,
                            BorderType &border,
                            physics::ParametricValue const parametric_offset)
{
  if (!roadSegment.drivable_lane_segments.empty())
  {
    getRightProjectedEdge(cutLaneIntervalAtEndByRoadSegmentParametricOffset(
                            roadSegment.drivable_lane_segments.front().lane_interval, parametric_offset),
                          border.right);
    getLeftProjectedEdge(cutLaneIntervalAtEndByRoadSegmentParametricOffset(
                           roadSegment.drivable_lane_segments.back().lane_interval, parametric_offset),
                         border.left);
  }
}

lane::ECEFBorder getECEFBorderOfRoadSegment(RoadSegment const &roadSegment,
                                            physics::ParametricValue const parametric_offset)
{
  lane::ECEFBorder result;
  getBorderOfRoadSegment(roadSegment, result, parametric_offset);
  return result;
}

lane::ENUBorder getENUBorderOfRoadSegment(RoadSegment const &roadSegment,
                                          physics::ParametricValue const parametric_offset)
{
  lane::ENUBorder result;
  getBorderOfRoadSegment(roadSegment, result, parametric_offset);
  return result;
}

lane::GeoBorder getGeoBorderOfRoadSegment(RoadSegment const &roadSegment,
                                          physics::ParametricValue const parametric_offset)
{
  lane::GeoBorder result;
  getBorderOfRoadSegment(roadSegment, result, parametric_offset);
  return result;
}

lane::ENUBorderList getENUBorderOfRoute(FullRoute const &route)
{
  lane::ENUBorderList enuBorderList;
  enuBorderList.reserve(route.road_segments.size());
  for (auto const &roadSegment : route.road_segments)
  {
    enuBorderList.push_back(getENUBorderOfRoadSegment(roadSegment));
  }
  return enuBorderList;
}

lane::ECEFBorderList getECEFBorderOfRoute(FullRoute const &route)
{
  lane::ECEFBorderList ecefBorderList;
  ecefBorderList.reserve(route.road_segments.size());
  for (auto const &roadSegment : route.road_segments)
  {
    ecefBorderList.push_back(getECEFBorderOfRoadSegment(roadSegment));
  }
  return ecefBorderList;
}

lane::GeoBorderList getGeoBorderOfRoute(FullRoute const &route)
{
  lane::GeoBorderList geoBorderList;
  geoBorderList.reserve(route.road_segments.size());
  for (auto const &roadSegment : route.road_segments)
  {
    geoBorderList.push_back(getGeoBorderOfRoadSegment(roadSegment));
  }
  return geoBorderList;
}

point::ENUHeading getENUHeadingOfRoute(match::Object const &object, FullRoute const &route)
{
  FindWaypointResult objectCenterWaypoint = findCenterWaypoint(object, route);
  if (!objectCenterWaypoint.isValid())
  {
    access::getLogger()->error("ad::map::route::getENUHeadingOfRoute: object not found in route {} {}", object, route);
    return ad::map::point::ENUHeading(2 * M_PI);
  }
  // ensure the found object point on route is in the route section
  auto const routeSectionAroundObject = getRouteSection(objectCenterWaypoint,
                                                        object.enu_position.dimension.length,
                                                        object.enu_position.dimension.length,
                                                        route,
                                                        RouteSectionCreationMode::AllRouteLanes);
  auto const routeENUBorders = getENUBorderOfRoute(routeSectionAroundObject);
  // first try to get the heading directly at the actual object center point
  auto heading
    = lane::getENUHeading(routeENUBorders, object.enu_position.center_point, object.enu_position.dimension.length);
  if (std::fabs(heading) >= ad::map::point::ENUHeading(2 * M_PI))
  {
    // if this doesn't work out (in case another part of the object was actually found, like only front/back)
    // we take the orientation of the lane at the found position, lateral center of the route
    auto const enuObjectCenterWaypoint
      = lane::getENULanePoint(objectCenterWaypoint.queryPosition, physics::ParametricValue(0.5));
    heading = lane::getENUHeading(routeENUBorders, enuObjectCenterWaypoint, object.enu_position.dimension.length);
  }
  return heading;
}

bool isObjectHeadingInRouteDirection(match::Object const &object, FullRoute const &route)
{
  auto const enuHeadingOfRoute = getENUHeadingOfRoute(object, route);
  if (enuHeadingOfRoute >= ad::map::point::ENUHeading(2 * M_PI))
  {
    throw std::runtime_error("route::isObjectHeadingInRouteDirection>> object not found in route");
  }
  // enforce normalization of angle difference
  const auto headingDifference = point::normalizeENUHeading(std::fabs(enuHeadingOfRoute - object.enu_position.heading));
  if (std::fabs(headingDifference).mENUHeading > M_PI / 2.)
  {
    return false;
  }
  return true;
}

lane::LaneIdSet getLanesOfRoute(::ad::map::route::FullRoute const &route)
{
  lane::LaneIdSet route_lanes;
  for (auto const &roadSegment : route.road_segments)
  {
    for (auto const &laneSegment : roadSegment.drivable_lane_segments)
    {
      route_lanes.insert(laneSegment.lane_interval.lane_id);
    }
  }
  return route_lanes;
}

} // namespace route
} // namespace map
} // namespace ad
