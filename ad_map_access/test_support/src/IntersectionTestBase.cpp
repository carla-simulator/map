// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/test_support/IntersectionTestBase.hpp"

#include <algorithm>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/AdMapMatching.hpp"
#include "ad/map/point/Types.hpp"
#include "ad/map/route/Planning.hpp"

namespace ad {
namespace map {
namespace test_support {

/** Special handling required for intersections as we also test intersections which only have three
 *  arms. In that case one direction only provides 'null'-points. These will throw an exception in
 *  the underlying map, although the test base assumes that those will be set to LaneId 0
 */
lane::LaneId laneIdFromPoint(point::GeoPoint const &p)
{
  if (!point::isValid(p, false))
  {
    return lane::LaneId();
  }
  return lane::uniqueLaneId(p);
}

void IntersectionTestBase::SetUp()
{
  //::ad::map::access::getLogger()->set_level(spdlog::level::trace);
  prepareMap();

  // first transform geo to LaneId
  mFromNorth = laneIdFromPoint(getGeoFromNorth());
  mToNorth = laneIdFromPoint(getGeoToNorth());
  mFromSouth = laneIdFromPoint(getGeoFromSouth());
  mToSouth = laneIdFromPoint(getGeoToSouth());
  mFromWest = laneIdFromPoint(getGeoFromWest());
  mToWest = laneIdFromPoint(getGeoToWest());
  mFromEast = laneIdFromPoint(getGeoFromEast());
  mToEast = laneIdFromPoint(getGeoToEast());

  // then plan the route and extract the intersection

  auto const routeStartId = getRouteStart();
  if ((routeStartId != mFromEast) && (routeStartId != mFromWest) && (routeStartId != mFromNorth)
      && (routeStartId != mFromSouth))
  {
    throw std::runtime_error("IntersectionTestBase::SetUp() getRouteStart must return one of the mFrom* lanes.");
  }

  auto const routeEndId = getRouteEnd();
  if ((routeEndId != mToEast) && (routeEndId != mToWest) && (routeEndId != mToNorth) && (routeEndId != mToSouth))
  {
    throw std::runtime_error("IntersectionTestBase::SetUp() getRouteEnd must return one of the mTo* lanes.");
  }

  mPlannedRoute = planRoute(routeStartId, routeEndId);
  mPlannedRouteValues = getRouteBaseValues(routeStartId, routeEndId);
  auto intersections = intersection::Intersection::getIntersectionsForRoute(mPlannedRoute);
  if (intersections.empty())
  {
    throw std::runtime_error("No intersection for route!");
  }
  mIntersection = intersections[0];

  // then calculate the inner lanes
  mNorthToSouth = getRouteBaseValues(mFromNorth, mToSouth);
  mNorthToWest = getRouteBaseValues(mFromNorth, mToWest);
  mNorthToEast = getRouteBaseValues(mFromNorth, mToEast);
  mSouthToNorth = getRouteBaseValues(mFromSouth, mToNorth);
  mSouthToWest = getRouteBaseValues(mFromSouth, mToWest);
  mSouthToEast = getRouteBaseValues(mFromSouth, mToEast);
  mWestToNorth = getRouteBaseValues(mFromWest, mToNorth);
  mWestToSouth = getRouteBaseValues(mFromWest, mToSouth);
  mWestToEast = getRouteBaseValues(mFromWest, mToEast);
  mEastToNorth = getRouteBaseValues(mFromEast, mToNorth);
  mEastToSouth = getRouteBaseValues(mFromEast, mToSouth);
  mEastToWest = getRouteBaseValues(mFromEast, mToWest);

  verifyImpossibleWays(mNorthToEast);
  verifyImpossibleWays(mNorthToSouth);
  verifyImpossibleWays(mNorthToWest);
  verifyImpossibleWays(mSouthToEast);
  verifyImpossibleWays(mSouthToNorth);
  verifyImpossibleWays(mSouthToWest);
  verifyImpossibleWays(mWestToEast);
  verifyImpossibleWays(mWestToNorth);
  verifyImpossibleWays(mWestToSouth);
  verifyImpossibleWays(mEastToNorth);
  verifyImpossibleWays(mEastToSouth);
  verifyImpossibleWays(mEastToWest);
}

void IntersectionTestBase::TearDown()
{
  access::cleanup();
}

route::FullRoute IntersectionTestBase::planRoute(lane::LaneId const &routeStartId, lane::LaneId const &routeEndId) const
{
  if ((!lane::isValid(routeStartId)) || (!lane::isValid(routeEndId)))
  {
    throw std::runtime_error("IntersectionTestBase::planRoute() route start or route end are invalid."
                             "Did you select intersection arms for your route that actually exist?");
  }
  return route::planning::planRoute(point::createParaPoint(routeStartId, physics::ParametricValue(0.5)),
                                    point::createParaPoint(routeEndId, physics::ParametricValue(0.5)));
}

IntersectionTestBase::RouteBasedValues IntersectionTestBase::getRouteBaseValues(lane::LaneId const &routeStartId,
                                                                                lane::LaneId const &routeEndId) const
{
  RouteBasedValues routeBasedValues;
  if ((!lane::isValid(routeStartId, false)) || (!lane::isValid(routeEndId, false)))
  {
    return routeBasedValues;
  }

  auto fullRoute = planRoute(routeStartId, routeEndId);
  if (fullRoute.road_segments.size() < 3u)
  {
    return routeBasedValues;
  }

  for (uint32_t i = 0; i < fullRoute.road_segments.size(); i++)
  {
    for (auto drivableLaneSegment : fullRoute.road_segments[i].drivable_lane_segments)
    {
      if (i == 0)
      {
        routeBasedValues.mIncomingLanes.insert(drivableLaneSegment.lane_interval.lane_id);
        routeBasedValues.mIncomingParaPoints.push_back(route::getIntervalEnd(drivableLaneSegment.lane_interval));
      }
      else if (i == (fullRoute.road_segments.size() - 1))
      {
        routeBasedValues.mOutgoingLanes.insert(drivableLaneSegment.lane_interval.lane_id);
        routeBasedValues.mOutgoingParaPoints.push_back(route::getIntervalStart(drivableLaneSegment.lane_interval));
      }
      else
      {
        routeBasedValues.mInternalLanes.insert(drivableLaneSegment.lane_interval.lane_id);
        routeBasedValues.mInternalLaneIntervals.push_back(drivableLaneSegment.lane_interval);
      }
    }
  }
  for (auto incomingLane : routeBasedValues.mIncomingLanes)
  {
    for (auto outcomingLane : routeBasedValues.mOutgoingLanes)
    {
      auto parallelRoute = planRoute(incomingLane, outcomingLane);

      for (uint32_t i = 1; i < parallelRoute.road_segments.size() - 1; i++)
      {
        for (auto drivableLaneSegment : parallelRoute.road_segments[i].drivable_lane_segments)
        {
          routeBasedValues.mInternalLanes.insert(drivableLaneSegment.lane_interval.lane_id);
          routeBasedValues.mInternalLaneIntervals.push_back(drivableLaneSegment.lane_interval);
        }
      }
    }
  }

  return routeBasedValues;
}

lane::LaneIdSet IntersectionTestBase::createUnorderedLaneIdSet(std::vector<lane::LaneIdSet> const &lanesVector) const
{
  lane::LaneIdSet resultSet;
  for (auto const &lanes : lanesVector)
  {
    resultSet.insert(lanes.begin(), lanes.end());
  }
  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::createUnorderedLaneIdSet(std::vector<lane::LaneId> const &lanes) const
{
  lane::LaneIdSet resultSet;
  resultSet.insert(lanes.begin(), lanes.end());
  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::createUnorderedLaneIdSet(lane::LaneId const &lane) const
{
  lane::LaneIdSet resultSet;
  resultSet.insert(lane);
  return resultSet;
}

point::ParaPointList
IntersectionTestBase::createParaPointVector(std::vector<point::ParaPointList> const &paraPointsVector) const
{
  point::ParaPointList resultVector;
  for (auto const &paraPoints : paraPointsVector)
  {
    for (auto const &para_point : paraPoints)
    {
      auto findResult = std::find(resultVector.begin(), resultVector.end(), para_point);
      if (findResult == resultVector.end())
      {
        resultVector.push_back(para_point);
      }
    }
  }
  return resultVector;
}

void IntersectionTestBase::verifyImpossibleWays(RouteBasedValues &routeBasedValues)
{
  lane::LaneIdSet const allOutgoingLanes = createUnorderedLaneIdSet({mNorthToEast.mOutgoingLanes,
                                                                     mNorthToSouth.mOutgoingLanes,
                                                                     mNorthToWest.mOutgoingLanes,
                                                                     mSouthToEast.mOutgoingLanes,
                                                                     mSouthToNorth.mOutgoingLanes,
                                                                     mSouthToWest.mOutgoingLanes,
                                                                     mWestToEast.mOutgoingLanes,
                                                                     mWestToNorth.mOutgoingLanes,
                                                                     mWestToSouth.mOutgoingLanes,
                                                                     mEastToNorth.mOutgoingLanes,
                                                                     mEastToSouth.mOutgoingLanes,
                                                                     mEastToWest.mOutgoingLanes});
  for (auto internalLane : routeBasedValues.mInternalLanes)
  {
    if (allOutgoingLanes.count(internalLane) > 0u)
    {
      routeBasedValues.mIncomingLanes.clear();
      routeBasedValues.mIncomingParaPoints.clear();
      routeBasedValues.mInternalLanes.clear();
      routeBasedValues.mInternalLaneIntervals.clear();
      routeBasedValues.mOutgoingLanes.clear();
      routeBasedValues.mOutgoingParaPoints.clear();

      break;
    }
  }
}

lane::LaneIdSet IntersectionTestBase::getInternalLanes() const
{
  return createUnorderedLaneIdSet({mNorthToEast.mInternalLanes,
                                   mNorthToSouth.mInternalLanes,
                                   mNorthToWest.mInternalLanes,
                                   mSouthToEast.mInternalLanes,
                                   mSouthToNorth.mInternalLanes,
                                   mSouthToWest.mInternalLanes,
                                   mWestToEast.mInternalLanes,
                                   mWestToNorth.mInternalLanes,
                                   mWestToSouth.mInternalLanes,
                                   mEastToNorth.mInternalLanes,
                                   mEastToSouth.mInternalLanes,
                                   mEastToWest.mInternalLanes});
}

lane::LaneIdSet IntersectionTestBase::getIncomingLanes() const
{
  lane::LaneIdSet resultSet = createUnorderedLaneIdSet(
    {getIncomingLanesNorth(), getIncomingLanesSouth(), getIncomingLanesEast(), getIncomingLanesWest()});

  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::getIncomingLanesNorth() const
{
  lane::LaneIdSet resultSet = createUnorderedLaneIdSet(
    {mNorthToEast.mIncomingLanes, mNorthToSouth.mIncomingLanes, mNorthToWest.mIncomingLanes});
  for (auto const &incomingLaneOnRoute : mPlannedRouteValues.mIncomingLanes)
  {
    resultSet.erase(incomingLaneOnRoute);
  }
  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::getIncomingLanesSouth() const
{
  lane::LaneIdSet resultSet = createUnorderedLaneIdSet(
    {mSouthToEast.mIncomingLanes, mSouthToNorth.mIncomingLanes, mSouthToWest.mIncomingLanes});
  for (auto const &incomingLaneOnRoute : mPlannedRouteValues.mIncomingLanes)
  {
    resultSet.erase(incomingLaneOnRoute);
  }
  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::getIncomingLanesEast() const
{
  lane::LaneIdSet resultSet
    = createUnorderedLaneIdSet({mEastToNorth.mIncomingLanes, mEastToSouth.mIncomingLanes, mEastToWest.mIncomingLanes});
  for (auto const &incomingLaneOnRoute : mPlannedRouteValues.mIncomingLanes)
  {
    resultSet.erase(incomingLaneOnRoute);
  }
  return resultSet;
}

lane::LaneIdSet IntersectionTestBase::getIncomingLanesWest() const
{
  lane::LaneIdSet resultSet
    = createUnorderedLaneIdSet({mWestToEast.mIncomingLanes, mWestToNorth.mIncomingLanes, mWestToSouth.mIncomingLanes});
  for (auto const &incomingLaneOnRoute : mPlannedRouteValues.mIncomingLanes)
  {
    resultSet.erase(incomingLaneOnRoute);
  }
  return resultSet;
}

point::ParaPointList IntersectionTestBase::getIncomingParaPoints() const
{
  point::ParaPointList resultVector = createParaPointVector({mNorthToEast.mIncomingParaPoints,
                                                             mNorthToSouth.mIncomingParaPoints,
                                                             mNorthToWest.mIncomingParaPoints,
                                                             mSouthToEast.mIncomingParaPoints,
                                                             mSouthToNorth.mIncomingParaPoints,
                                                             mSouthToWest.mIncomingParaPoints,
                                                             mWestToEast.mIncomingParaPoints,
                                                             mWestToNorth.mIncomingParaPoints,
                                                             mWestToSouth.mIncomingParaPoints,
                                                             mEastToNorth.mIncomingParaPoints,
                                                             mEastToSouth.mIncomingParaPoints,
                                                             mEastToWest.mIncomingParaPoints});
  for (auto const &incomingParaPointOnRoute : mPlannedRouteValues.mIncomingParaPoints)
  {
    resultVector.erase(std::remove(resultVector.begin(), resultVector.end(), incomingParaPointOnRoute),
                       resultVector.end());
  }
  return resultVector;
}

point::ParaPoint
IntersectionTestBase::getLaneParaPointFromRouteParametricOffset(lane::LaneId const lane_id,
                                                                physics::ParametricValue const routeParametricOffset)
{
  route::LaneInterval relevantLaneInterval;
  relevantLaneInterval.lane_id = lane::LaneId();
  relevantLaneInterval.start = physics::ParametricValue(0.);
  relevantLaneInterval.end = physics::ParametricValue(0.);
  for (auto const &routeBasedValue : {mNorthToSouth,
                                      mNorthToWest,
                                      mNorthToEast,
                                      mSouthToNorth,
                                      mSouthToWest,
                                      mSouthToEast,
                                      mWestToNorth,
                                      mWestToSouth,
                                      mWestToEast,
                                      mEastToNorth,
                                      mEastToSouth,
                                      mEastToWest})
  {
    auto incomingFindResult
      = std::find_if(routeBasedValue.mIncomingParaPoints.begin(),
                     routeBasedValue.mIncomingParaPoints.end(),
                     [lane_id](point::ParaPoint const &para_point) { return para_point.lane_id == lane_id; });
    if (incomingFindResult != routeBasedValue.mIncomingParaPoints.end())
    {
      relevantLaneInterval.lane_id = lane_id;
      relevantLaneInterval.end = incomingFindResult->parametric_offset;
      relevantLaneInterval.start = physics::ParametricValue(1.) - relevantLaneInterval.end;
      break;
    }
    auto outgoingFindResult
      = std::find_if(routeBasedValue.mOutgoingParaPoints.begin(),
                     routeBasedValue.mOutgoingParaPoints.end(),
                     [lane_id](point::ParaPoint const &para_point) { return para_point.lane_id == lane_id; });
    if (outgoingFindResult != routeBasedValue.mOutgoingParaPoints.end())
    {
      relevantLaneInterval.lane_id = lane_id;
      relevantLaneInterval.start = outgoingFindResult->parametric_offset;
      relevantLaneInterval.end = physics::ParametricValue(1.) - relevantLaneInterval.start;
      break;
    }
    auto internalFindResult
      = std::find_if(routeBasedValue.mInternalLaneIntervals.begin(),
                     routeBasedValue.mInternalLaneIntervals.end(),
                     [lane_id](route::LaneInterval const &lane_interval) { return lane_interval.lane_id == lane_id; });
    if (internalFindResult != routeBasedValue.mInternalLaneIntervals.end())
    {
      relevantLaneInterval = *internalFindResult;
      break;
    }
  }

  if (route::isDegenerated(relevantLaneInterval))
  {
    throw std::runtime_error(
      "IntersectionTestBase::getLaneParaPointFromRouteParametricOffset() lane not found within intersection.");
  }

  return route::getLaneParaPoint(routeParametricOffset, relevantLaneInterval);
}

} // namespace test_support
} // namespace map
} // namespace ad
