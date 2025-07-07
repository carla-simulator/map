// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/intersection/CoreIntersection.hpp"

#include "ad/map/access/Logging.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/AdMapMatching.hpp"
#include "ad/map/route/RouteOperation.hpp"

namespace ad {
namespace map {
namespace intersection {

point::ParaPoint CoreIntersection::getEntryParaPointOfExternalLane(lane::LaneId const &lane_id) const
{
  point::ParaPoint p;
  p.lane_id = lane_id;
  p.parametric_offset
    = (lane::isLaneDirectionNegative(lane_id) ? physics::ParametricValue(0.) : physics::ParametricValue(1.));
  return p;
}

point::ParaPoint CoreIntersection::getExitParaPointOfExternalLane(lane::LaneId const &lane_id) const
{
  point::ParaPoint p;
  p.lane_id = lane_id;
  p.parametric_offset
    = (lane::isLaneDirectionNegative(lane_id) ? physics::ParametricValue(1.) : physics::ParametricValue(0.));
  return p;
}

point::ParaPoint CoreIntersection::getEntryParaPointOfInternalLane(lane::LaneId const &lane_id) const
{
  // for internal lanes the para point logic is vice-versa to external lanes
  return getExitParaPointOfExternalLane(lane_id);
}

point::ParaPoint CoreIntersection::getExitParaPointOfInternalLane(lane::LaneId const &lane_id) const
{
  // for internal lanes the para point logic is vice-versa to external lanes
  return getEntryParaPointOfExternalLane(lane_id);
}

bool CoreIntersection::isLanePartOfIntersection(lane::LaneId const lane_id, SuccessorMode const successorMode) const
{
  if (successorMode == SuccessorMode::OwnIntersection)
  {
    return isLanePartOfCoreIntersection(lane_id);
  }
  else
  {
    return isLanePartOfAnIntersection(lane_id);
  }
}

lane::LaneIdSet const &CoreIntersection::internalLanes() const
{
  return mInternalLanes;
}

lane::LaneIdSet const &CoreIntersection::entryLanes() const
{
  return mEntryLanes;
}

lane::LaneIdSet const &CoreIntersection::entryBorderLanes() const
{
  return mEntryBorderLanes;
}

point::ParaPointList const &CoreIntersection::entryParaPoints() const
{
  return mEntryParaPoints;
}

point::ParaPointList const &CoreIntersection::entryBorderParaPoints() const
{
  return mEntryBorderParaPoints;
}

lane::LaneIdSet const &CoreIntersection::exitLanes() const
{
  return mExitLanes;
}

lane::LaneIdSet const &CoreIntersection::exitBorderLanes() const
{
  return mExitBorderLanes;
}

point::ParaPointList const &CoreIntersection::exitParaPoints() const
{
  return mExitParaPoints;
}

point::ParaPointList const &CoreIntersection::exitBorderParaPoints() const
{
  return mExitBorderParaPoints;
}

bool CoreIntersection::isLanePartOfCoreIntersection(lane::LaneId const lane_id) const
{
  return (mInternalLanes.find(lane_id) != mInternalLanes.end());
}

void CoreIntersection::extractLanesOfCoreIntersection(lane::LaneId const lane_id)
{
  if (isLanePartOfCoreIntersection(lane_id))
  {
    return;
  }
  auto lane = lane::getLane(lane_id);
  if (!lane::isLanePartOfAnIntersection(lane))
  {
    // restrict ourselves to lanes inside the intersection
    return;
  }
  mInternalLanes.insert(lane_id);
  if (mInternalLanes.size() == 1u)
  {
    mInternalLanesBoundingSphere = lane.bounding_sphere;
  }
  else
  {
    mInternalLanesBoundingSphere = mInternalLanesBoundingSphere + lane.bounding_sphere;
  }
  for (auto const &contact : lane.contact_lanes)
  {
    processContactsForLane(lane, contact);
    extractLanesOfCoreIntersection(contact.to_lane);
  }
}

void CoreIntersection::processContactsForLane(lane::Lane const &lane, lane::ContactLane const &contact)
{
  auto const &toId = contact.to_lane;
  switch (contact.location)
  {
    case lane::ContactLocation::OVERLAP:
      mOverlapping[lane.id].insert(toId);
      break;
    case lane::ContactLocation::SUCCESSOR:
      if (isLaneDirectionPositive(lane))
      {
        mSuccessor[lane.id].insert(toId);
        checkAndInsertExitLane(toId, lane.id);
      }
      else
      {
        mPredecessor[lane.id].insert(toId);
        checkAndInsertEntryLane(toId, lane.id);
      }
      break;
    case lane::ContactLocation::PREDECESSOR:
      if (isLaneDirectionNegative(lane))
      {
        mSuccessor[lane.id].insert(toId);
        checkAndInsertExitLane(toId, lane.id);
      }
      else
      {
        mPredecessor[lane.id].insert(toId);
        checkAndInsertEntryLane(toId, lane.id);
      }
      break;
    default:
      break; // ignored for now
  }
}

void CoreIntersection::checkAndInsertEntryLane(lane::LaneId const lane_id, lane::LaneId const tolaneId)
{
  if (!isLanePartOfAnIntersection(lane_id))
  {
    if (mEntryLanes.insert(lane_id).second)
    {
      mEntryParaPoints.push_back(getEntryParaPointOfExternalLane(lane_id));
    }
    if (mEntryBorderLanes.insert(tolaneId).second)
    {
      mEntryBorderParaPoints.push_back(getEntryParaPointOfInternalLane(tolaneId));
    }
  }
}

void CoreIntersection::checkAndInsertExitLane(lane::LaneId const lane_id, lane::LaneId const tolaneId)
{
  if (!isLanePartOfAnIntersection(lane_id))
  {
    if (mExitLanes.insert(lane_id).second)
    {
      mExitParaPoints.push_back(getExitParaPointOfExternalLane(lane_id));
    }
    if (mExitBorderLanes.insert(tolaneId).second)
    {
      mExitBorderParaPoints.push_back(getExitParaPointOfInternalLane(tolaneId));
    }
  }
}

std::pair<lane::LaneIdSet, lane::LaneIdSet>
CoreIntersection::getDirectSuccessorsInLaneDirection(lane::LaneId const lane_id,
                                                     SuccessorMode const successorMode) const
{
  auto lane = lane::getLane(lane_id);
  auto location = lane::ContactLocation::SUCCESSOR;
  if (lane.direction == lane::LaneDirection::NEGATIVE)
  {
    location = lane::ContactLocation::PREDECESSOR;
  }
  std::pair<lane::LaneIdSet, lane::LaneIdSet> result;
  for (auto const &contact : lane::getContactLanes(lane, location))
  {
    lane::LaneId const successorLane = contact.to_lane;
    if (isLanePartOfIntersection(successorLane, successorMode))
    {
      // restrict first to within intersection
      result.first.insert(successorLane);
    }
    else
    {
      // restrict second to outside intersection
      result.second.insert(successorLane);
    }
  }
  return result;
}

lane::LaneIdSet
CoreIntersection::getDirectSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const lane_id,
                                                                       SuccessorMode const successorMode) const
{
  return getDirectSuccessorsInLaneDirection(lane_id, successorMode).first;
}

lane::LaneIdSet
CoreIntersection::getAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const lane_id,
                                                                    SuccessorMode const successorMode) const
{
  lane::LaneIdSet result;
  auto directSuccessors = getDirectSuccessorsInLaneDirectionWithinIntersection(lane_id, successorMode);
  for (auto directSuccessorId : directSuccessors)
  {
    auto directSuccessorRecursiveResult
      = getAllSuccessorsInLaneDirectionWithinIntersection(directSuccessorId, successorMode);
    result.insert(directSuccessorRecursiveResult.begin(), directSuccessorRecursiveResult.end());
  }
  result.insert(directSuccessors.begin(), directSuccessors.end());
  return result;
}

lane::LaneIdSet
CoreIntersection::getLaneAndAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const lane_id,
                                                                           SuccessorMode const successorMode) const
{
  auto result = getAllSuccessorsInLaneDirectionWithinIntersection(lane_id, successorMode);
  if (isLanePartOfIntersection(lane_id, successorMode))
  {
    result.insert(lane_id);
  }
  return result;
}

lane::LaneIdSet CoreIntersection::getAllReachableOutgoingLanes(lane::LaneId const lane_id,
                                                               SuccessorMode const successorMode) const
{
  lane::LaneIdSet result;
  auto directSuccessors = getDirectSuccessorsInLaneDirection(lane_id, successorMode);
  // recursive until end of intersection
  for (auto directSuccessorId : directSuccessors.first)
  {
    auto directSuccessorRecursiveResult = getAllReachableOutgoingLanes(directSuccessorId, successorMode);
    result.insert(directSuccessorRecursiveResult.begin(), directSuccessorRecursiveResult.end());
  }
  result.insert(directSuccessors.second.begin(), directSuccessors.second.end());
  return result;
}

std::pair<lane::LaneIdSet, lane::LaneIdSet>
CoreIntersection::getAllReachableInternalAndOutgoingLanes(lane::LaneId const lane_id,
                                                          SuccessorMode const successorMode) const
{
  std::pair<lane::LaneIdSet, lane::LaneIdSet> result;
  auto directSuccessors = getDirectSuccessorsInLaneDirection(lane_id, successorMode);
  // recursive until end of intersection
  for (auto directSuccessorId : directSuccessors.first)
  {
    auto directSuccessorRecursiveResult = getAllReachableInternalAndOutgoingLanes(directSuccessorId, successorMode);
    result.first.insert(directSuccessorRecursiveResult.first.begin(), directSuccessorRecursiveResult.first.end());
    result.second.insert(directSuccessorRecursiveResult.second.begin(), directSuccessorRecursiveResult.second.end());
  }
  result.first.insert(directSuccessors.first.begin(), directSuccessors.first.end());
  result.second.insert(directSuccessors.second.begin(), directSuccessors.second.end());
  return result;
}

bool CoreIntersection::isLanePartOfAnIntersection(lane::LaneId const lane_id)
{
  auto lane = lane::getLane(lane_id);
  return lane::isLanePartOfAnIntersection(lane);
}

bool CoreIntersection::isRoutePartOfAnIntersection(route::FullRoute const &route)
{
  for (auto const &roadSegment : route.road_segments)
  {
    for (auto const &laneSegment : roadSegment.drivable_lane_segments)
    {
      if (isLanePartOfAnIntersection(laneSegment.lane_interval.lane_id))
      {
        return true;
      }
    }
  }
  return false;
}

bool laneEntersIntersection(lane::LaneId const &from, lane::LaneId const &to)
{
  return ((from != to) && !CoreIntersection::isLanePartOfAnIntersection(from)
          && CoreIntersection::isLanePartOfAnIntersection(to));
}

bool CoreIntersection::isRoadSegmentEnteringIntersection(
  route::RouteIterator const &routeIterator, route::RoadSegmentList::const_iterator &routePreviousSegmentIter)
{
  if ((routeIterator.roadSegmentIterator != routeIterator.route.road_segments.end())
      && (routeIterator.roadSegmentIterator != routeIterator.route.road_segments.begin()))
  {
    auto previousSegmentIter = routeIterator.roadSegmentIterator;
    previousSegmentIter--;
    // only look at the first parapoint per index
    auto const fromLane = previousSegmentIter->drivable_lane_segments.front().lane_interval.lane_id;
    auto const to_lane = routeIterator.roadSegmentIterator->drivable_lane_segments.front().lane_interval.lane_id;
    if (laneEntersIntersection(fromLane, to_lane))
    {
      routePreviousSegmentIter = previousSegmentIter;
      return true;
    }
  }
  return false;
}

bool CoreIntersection::isIntersectionOnRoute(route::FullRoute const &route)
{
  for (auto roadSegmentIter = route.road_segments.begin(); roadSegmentIter != route.road_segments.end();
       roadSegmentIter++)
  {
    route::RoadSegmentList::const_iterator routePreviousSegmentIter;
    // @todo: also consider segments leaving intersection if first segment is already within intersection
    if (isRoadSegmentEnteringIntersection(route::RouteIterator(route, roadSegmentIter), routePreviousSegmentIter))
    {
      return true;
    }
  }
  return false;
}

bool CoreIntersection::objectWithinIntersection(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mInternalLanes.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool CoreIntersection::objectRouteCrossesIntersection(route::FullRoute const &objectRoute) const
{
  for (auto internalLaneId : mInternalLanes)
  {
    auto findResult = route::findWaypoint(internalLaneId, objectRoute);
    if (findResult.isValid())
    {
      return true;
    }
  }
  return false;
}

physics::Distance CoreIntersection::objectDistanceToIntersection(match::Object const &object) const
{
  physics::Distance minDistance = std::numeric_limits<physics::Distance>::max();
  if (objectWithinIntersection(object.map_matched_bounding_box))
  {
    minDistance = physics::Distance(0.);
  }
  else
  {
    for (auto internalLaneId : mInternalLanes)
    {
      minDistance = std::min(minDistance, lane::getDistanceToLane(internalLaneId, object));
    }
  }
  return minDistance;
}

CoreIntersection::CoreIntersection(lane::LaneId const &lane_id)
{
  extractLanesOfCoreIntersection(lane_id);
}

CoreIntersectionPtr CoreIntersection::getCoreIntersectionFor(lane::LaneId const &lane_id)
{
  CoreIntersectionPtr result;
  if (isLanePartOfAnIntersection(lane_id))
  {
    result = CoreIntersectionPtr(new CoreIntersection(lane_id));
  }
  return result;
}

template <typename CONTAINER>
std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsForLaneIds(CONTAINER const &laneIds)
{
  std::vector<CoreIntersectionPtr> result;
  for (auto &lane_id : laneIds)
  {
    if (isLanePartOfAnIntersection(lane_id))
    {
      bool createIntersection = true;
      for (auto const &intersection : result)
      {
        auto const internalLanes = intersection->internalLanes();
        if (internalLanes.find(lane_id) != internalLanes.end())
        {
          createIntersection = false;
          break;
        }
      }
      if (createIntersection)
      {
        result.push_back(CoreIntersectionPtr(new CoreIntersection(lane_id)));
      }
    }
  }
  return result;
}

std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsFor(lane::LaneIdSet const &laneIds)
{
  return getCoreIntersectionsForLaneIds(laneIds);
}

std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsFor(lane::LaneIdList const &laneIds)
{
  return getCoreIntersectionsForLaneIds(laneIds);
}

CoreIntersectionPtr CoreIntersection::getCoreIntersectionFor(match::MapMatchedPosition const &mapMatchedPosition)
{
  return CoreIntersection::getCoreIntersectionFor(mapMatchedPosition.lane_point.para_point.lane_id);
}

std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsForInLaneMatches(point::ENUPoint const &position)
{
  match::AdMapMatching mapMatching;
  auto mapMatchedPositionConfidenceList = mapMatching.findLanes(toECEF(position), physics::Distance(2.));
  return CoreIntersection::getCoreIntersectionsForInLaneMatches(mapMatchedPositionConfidenceList);
}

std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsForInLaneMatches(
  match::MapMatchedPositionConfidenceList const &mapMatchedPositionConfidenceList)
{
  lane::LaneIdSet inLaneMatches;
  for (auto const &mapMatchedPosition : mapMatchedPositionConfidenceList)
  {
    if (mapMatchedPosition.type == match::MapMatchedPositionType::LANE_IN)
    {
      inLaneMatches.insert(mapMatchedPosition.lane_point.para_point.lane_id);
    }
  }

  return CoreIntersection::getCoreIntersectionsForLaneIds(inLaneMatches);
}

std::vector<CoreIntersectionPtr>
CoreIntersection::getCoreIntersectionsForInLaneMatches(match::MapMatchedObjectBoundingBox const &object)
{
  lane::LaneIdSet inLaneMatches;
  for (auto const &occupiedRegion : object.lane_occupied_regions)
  {
    inLaneMatches.insert(occupiedRegion.lane_id);
  }

  return CoreIntersection::getCoreIntersectionsForLaneIds(inLaneMatches);
}

std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsForMap()
{
  return getCoreIntersectionsFor(lane::getLanes());
}

} // namespace intersection
} // namespace map
} // namespace ad

namespace std {

std::ostream &operator<<(std::ostream &os, ::ad::map::intersection::CoreIntersection const &intersection)
{
  os << "CoreIntersection(";
  os << " boundingSphere(center=" << ::ad::map::point::toENU(intersection.getBoundingSphere().center)
     << ", radius=" << intersection.getBoundingSphere().radius << ")";
  os << std::endl;
  os << "->internalLanes: ";
  os << intersection.internalLanes();
  os << std::endl;
  os << "->entryLanes: ";
  os << intersection.entryLanes();
  os << std::endl;
  os << " -> entryParaPoints: ";
  os << intersection.entryParaPoints();
  os << std::endl;
  os << " -> exitLanes: ";
  os << intersection.exitLanes();
  os << std::endl;
  os << " -> exitParaPoints: ";
  os << intersection.exitParaPoints();
  os << ")" << std::endl;
  return os;
}

} // namespace std
