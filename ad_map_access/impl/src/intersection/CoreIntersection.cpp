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

point::ParaPoint CoreIntersection::getEntryParaPointOfExternalLane(lane::LaneId const &laneId) const
{
  point::ParaPoint p;
  p.laneId = laneId;
  p.parametricOffset
    = (lane::isLaneDirectionNegative(laneId) ? physics::ParametricValue(0.) : physics::ParametricValue(1.));
  return p;
}

point::ParaPoint CoreIntersection::getExitParaPointOfExternalLane(lane::LaneId const &laneId) const
{
  point::ParaPoint p;
  p.laneId = laneId;
  p.parametricOffset
    = (lane::isLaneDirectionNegative(laneId) ? physics::ParametricValue(1.) : physics::ParametricValue(0.));
  return p;
}

point::ParaPoint CoreIntersection::getEntryParaPointOfInternalLane(lane::LaneId const &laneId) const
{
  // for internal lanes the para point logic is vice-versa to external lanes
  return getExitParaPointOfExternalLane(laneId);
}

point::ParaPoint CoreIntersection::getExitParaPointOfInternalLane(lane::LaneId const &laneId) const
{
  // for internal lanes the para point logic is vice-versa to external lanes
  return getEntryParaPointOfExternalLane(laneId);
}

bool CoreIntersection::isLanePartOfIntersection(lane::LaneId const laneId, SuccessorMode const successorMode) const
{
  if (successorMode == SuccessorMode::OwnIntersection)
  {
    return isLanePartOfCoreIntersection(laneId);
  }
  else
  {
    return isLanePartOfAnIntersection(laneId);
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

point::ParaPointList const &CoreIntersection::entryParaPoints() const
{
  return mEntryParaPoints;
}

lane::LaneIdSet const &CoreIntersection::exitLanes() const
{
  return mExitLanes;
}

point::ParaPointList const &CoreIntersection::exitParaPoints() const
{
  return mExitParaPoints;
}

bool CoreIntersection::isLanePartOfCoreIntersection(lane::LaneId const laneId) const
{
  return (mInternalLanes.find(laneId) != mInternalLanes.end());
}

void CoreIntersection::extractLanesOfCoreIntersection(lane::LaneId const laneId)
{
  if (isLanePartOfCoreIntersection(laneId))
  {
    return;
  }
  auto lane = lane::getLane(laneId);
  if (!lane::isLanePartOfAnIntersection(lane))
  {
    // restrict ourselves to lanes inside the intersection
    return;
  }
  mInternalLanes.insert(laneId);
  if (mInternalLanes.size() == 1u)
  {
    mInternalLanesBoundingSphere = lane.boundingSphere;
  }
  else
  {
    mInternalLanesBoundingSphere = mInternalLanesBoundingSphere + lane.boundingSphere;
  }
  for (auto const &contact : lane.contactLanes)
  {
    processContactsForLane(lane, contact);
    extractLanesOfCoreIntersection(contact.toLane);
  }
}

void CoreIntersection::processContactsForLane(lane::Lane const &lane, lane::ContactLane const &contact)
{
  auto const &toId = contact.toLane;
  switch (contact.location)
  {
    case lane::ContactLocation::OVERLAP:
      mOverlapping[lane.id].insert(toId);
      break;
    case lane::ContactLocation::SUCCESSOR:
      if (isLaneDirectionPositive(lane))
      {
        mSuccessor[lane.id].insert(toId);
        checkAndInsertExitLane(toId);
      }
      else
      {
        mPredecessor[lane.id].insert(toId);
        checkAndInsertEntryLane(toId);
      }
      break;
    case lane::ContactLocation::PREDECESSOR:
      if (isLaneDirectionNegative(lane))
      {
        mSuccessor[lane.id].insert(toId);
        checkAndInsertExitLane(toId);
      }
      else
      {
        mPredecessor[lane.id].insert(toId);
        checkAndInsertEntryLane(toId);
      }
      break;
    default:
      break; // ignored for now
  }
}

void CoreIntersection::checkAndInsertEntryLane(lane::LaneId const laneId)
{
  if (!isLanePartOfAnIntersection(laneId))
  {
    if (mEntryLanes.insert(laneId).second)
    {
      mEntryParaPoints.push_back(getEntryParaPointOfExternalLane(laneId));
    }
  }
}

void CoreIntersection::checkAndInsertExitLane(lane::LaneId const laneId)
{
  if (!isLanePartOfAnIntersection(laneId))
  {
    if (mExitLanes.insert(laneId).second)
    {
      mExitParaPoints.push_back(getExitParaPointOfExternalLane(laneId));
    }
  }
}

std::pair<lane::LaneIdSet, lane::LaneIdSet>
CoreIntersection::getDirectSuccessorsInLaneDirection(lane::LaneId const laneId, SuccessorMode const successorMode) const
{
  auto lane = lane::getLane(laneId);
  auto location = lane::ContactLocation::SUCCESSOR;
  if (lane.direction == lane::LaneDirection::NEGATIVE)
  {
    location = lane::ContactLocation::PREDECESSOR;
  }
  std::pair<lane::LaneIdSet, lane::LaneIdSet> result;
  for (auto const &contact : lane::getContactLanes(lane, location))
  {
    lane::LaneId const successorLane = contact.toLane;
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
CoreIntersection::getDirectSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                       SuccessorMode const successorMode) const
{
  return getDirectSuccessorsInLaneDirection(laneId, successorMode).first;
}

lane::LaneIdSet
CoreIntersection::getAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                    SuccessorMode const successorMode) const
{
  lane::LaneIdSet result;
  auto directSuccessors = getDirectSuccessorsInLaneDirectionWithinIntersection(laneId, successorMode);
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
CoreIntersection::getLaneAndAllSuccessorsInLaneDirectionWithinIntersection(lane::LaneId const laneId,
                                                                           SuccessorMode const successorMode) const
{
  auto result = getAllSuccessorsInLaneDirectionWithinIntersection(laneId, successorMode);
  if (isLanePartOfIntersection(laneId, successorMode))
  {
    result.insert(laneId);
  }
  return result;
}

lane::LaneIdSet CoreIntersection::getAllReachableOutgoingLanes(lane::LaneId const laneId,
                                                               SuccessorMode const successorMode) const
{
  lane::LaneIdSet result;
  auto directSuccessors = getDirectSuccessorsInLaneDirection(laneId, successorMode);
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
CoreIntersection::getAllReachableInternalAndOutgoingLanes(lane::LaneId const laneId,
                                                          SuccessorMode const successorMode) const
{
  std::pair<lane::LaneIdSet, lane::LaneIdSet> result;
  auto directSuccessors = getDirectSuccessorsInLaneDirection(laneId, successorMode);
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

bool CoreIntersection::isLanePartOfAnIntersection(lane::LaneId const laneId)
{
  auto lane = lane::getLane(laneId);
  return lane::isLanePartOfAnIntersection(lane);
}

bool CoreIntersection::isRoutePartOfAnIntersection(route::FullRoute const &route)
{
  for (auto const &roadSegment : route.roadSegments)
  {
    for (auto const &laneSegment : roadSegment.drivableLaneSegments)
    {
      if (isLanePartOfAnIntersection(laneSegment.laneInterval.laneId))
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
  if ((routeIterator.roadSegmentIterator != routeIterator.route.roadSegments.end())
      && (routeIterator.roadSegmentIterator != routeIterator.route.roadSegments.begin()))
  {
    auto previousSegmentIter = routeIterator.roadSegmentIterator;
    previousSegmentIter--;
    // only look at the first parapoint per index
    auto const fromLane = previousSegmentIter->drivableLaneSegments.front().laneInterval.laneId;
    auto const toLane = routeIterator.roadSegmentIterator->drivableLaneSegments.front().laneInterval.laneId;
    if (laneEntersIntersection(fromLane, toLane))
    {
      routePreviousSegmentIter = previousSegmentIter;
      return true;
    }
  }
  return false;
}

bool CoreIntersection::isIntersectionOnRoute(route::FullRoute const &route)
{
  for (auto roadSegmentIter = route.roadSegments.begin(); roadSegmentIter != route.roadSegments.end();
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
  for (auto const &occupiedLane : object.laneOccupiedRegions)
  {
    if (mInternalLanes.count(occupiedLane.laneId) > 0)
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
  if (objectWithinIntersection(object.mapMatchedBoundingBox))
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

CoreIntersection::CoreIntersection(lane::LaneId const &laneId)
{
  extractLanesOfCoreIntersection(laneId);
}

CoreIntersectionPtr CoreIntersection::getCoreIntersectionFor(lane::LaneId const &laneId)
{
  CoreIntersectionPtr result;
  if (isLanePartOfAnIntersection(laneId))
  {
    result = CoreIntersectionPtr(new CoreIntersection(laneId));
  }
  return result;
}

template <typename CONTAINER>
std::vector<CoreIntersectionPtr> CoreIntersection::getCoreIntersectionsForLaneIds(CONTAINER const &laneIds)
{
  std::vector<CoreIntersectionPtr> result;
  for (auto &laneId : laneIds)
  {
    if (isLanePartOfAnIntersection(laneId))
    {
      bool createIntersection = true;
      for (auto const &intersection : result)
      {
        auto const internalLanes = intersection->internalLanes();
        if (internalLanes.find(laneId) != internalLanes.end())
        {
          createIntersection = false;
          break;
        }
      }
      if (createIntersection)
      {
        result.push_back(CoreIntersectionPtr(new CoreIntersection(laneId)));
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
  return CoreIntersection::getCoreIntersectionFor(mapMatchedPosition.lanePoint.paraPoint.laneId);
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
      inLaneMatches.insert(mapMatchedPosition.lanePoint.paraPoint.laneId);
    }
  }

  return CoreIntersection::getCoreIntersectionsForLaneIds(inLaneMatches);
}

std::vector<CoreIntersectionPtr>
CoreIntersection::getCoreIntersectionsForInLaneMatches(match::MapMatchedObjectBoundingBox const &object)
{
  lane::LaneIdSet inLaneMatches;
  for (auto const &occupiedRegion : object.laneOccupiedRegions)
  {
    inLaneMatches.insert(occupiedRegion.laneId);
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
