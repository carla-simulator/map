// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/intersection/Intersection.hpp"

#include <math.h>

#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/landmark/LandmarkOperation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/point/Operation.hpp"
#include "ad/map/route/RouteOperation.hpp"

namespace ad {
namespace map {
namespace intersection {

IntersectionType Intersection::intersectionTypeFromContactTypes(lane::ContactTypeList const &types)
{
  for (auto contactType : types)
  {
    // fallthrough is intended here
    switch (contactType)
    {
        // clang-format off
      // switched off to keep the formatting of the comments
      case lane::ContactType::FREE:               ///< There is no physical or legal obstacles between two objects.
      case lane::ContactType::RIGHT_OF_WAY:
        return IntersectionType::HasWay;
      case lane::ContactType::STOP:               ///< STOP regulation at the end of the lane.
        return IntersectionType::Stop;
      case lane::ContactType::STOP_ALL:           ///< STOP 3-way, 4-way etc regulation at the end of the lane.
        return IntersectionType::AllWayStop;
      case lane::ContactType::YIELD:              ///< YIELD regulation at the end of the lane.
        return IntersectionType::Yield;
      case lane::ContactType::CROSSWALK:          ///< Crosswalk at the end of the lane.
        return IntersectionType::Crosswalk;
      case lane::ContactType::PRIO_TO_RIGHT:      ///< Priority to right at the end of the lane.
        return IntersectionType::PriorityToRight;
      case lane::ContactType::PRIO_TO_RIGHT_AND_STRAIGHT:      ///< Priority to right and straight at the end of the lane.
        return IntersectionType::PriorityToRightAndStraight;
      case lane::ContactType::TRAFFIC_LIGHT:      ///< Traffic light on the way
        return IntersectionType::TrafficLight;
      case lane::ContactType::SPEED_BUMP:         ///< Speed bump at the end of the lane.
      case lane::ContactType::INVALID:
      case lane::ContactType::UNKNOWN:            ///< Unknown value.
      case lane::ContactType::LANE_CHANGE:        ///< Transition between one lane to direct lateral neighboor.
      case lane::ContactType::LANE_CONTINUATION:  ///< Transition between one lane to longitudinal direct neighboor.
      case lane::ContactType::LANE_END:           ///< End of the Lane - line.
      case lane::ContactType::SINGLE_POINT:       ///< End of the Lane - point.
      case lane::ContactType::GATE_BARRIER:       ///< Gate with barrier at the end of the lane.
      case lane::ContactType::GATE_TOLBOOTH:      ///< Tolbooth barrier at the end of the lane.
      case lane::ContactType::GATE_SPIKES:        ///< Spikes (in direction) at the end of the lane.
      case lane::ContactType::GATE_SPIKES_CONTRA: ///< Spikes (in opposite direction) at the end of the lane.
      case lane::ContactType::CURB_UP:            ///< Curb up at the object side.
      case lane::ContactType::CURB_DOWN:          ///< Curb down at the object.
        break;      // in all other cases, we do nothing, maybe another contact has valid information.
      // clang-format on
      default:
        throw std::invalid_argument("Intersection from ContactTypes: Invalid contact type passed");
    }
  }
  return IntersectionType::Unknown;
}

IntersectionType getRightOfWayForTransition(lane::LaneId fromLaneId, lane::LaneId toLaneId)
{
  auto laneFrom = lane::getLane(fromLaneId);
  auto contactLanesFromOutside = lane::getContactLane(laneFrom, toLaneId);
  for (auto contact : contactLanesFromOutside)
  {
    auto intersectionTypeFromOutside = Intersection::intersectionTypeFromContactTypes(contact.types);
    if (intersectionTypeFromOutside != IntersectionType::Unknown)
    {
      return intersectionTypeFromOutside;
    }
  }

  auto laneTo = lane::getLane(toLaneId);
  auto contactLanesFromInside = lane::getContactLane(laneTo, fromLaneId);
  for (auto contact : contactLanesFromInside)
  {
    auto intersectionTypeFromInside = Intersection::intersectionTypeFromContactTypes(contact.types);
    if (intersectionTypeFromInside != IntersectionType::Unknown)
    {
      return intersectionTypeFromInside;
    }
  }

  return IntersectionType::Unknown;
}

IntersectionPtr Intersection::getIntersectionForRoadSegment(route::RouteIterator const &routeIterator)
{
  IntersectionPtr result;
  route::RoadSegmentList::const_iterator routePreviousSegmentIter;
  bool const intersectionStart = isRoadSegmentEnteringIntersection(routeIterator, routePreviousSegmentIter);
  if (intersectionStart)
  {
    try
    {
      result = IntersectionPtr(
        new Intersection(routeIterator.route, routePreviousSegmentIter, routeIterator.roadSegmentIterator));
    }
    catch (...)
    {
      access::getLogger()->warn("Failed to create intersection at route iterator {} for route: {}",
                                *routeIterator.roadSegmentIterator,
                                routeIterator.route);
    }
  }
  return result;
}

std::vector<IntersectionPtr> Intersection::getIntersectionsForRoute(route::FullRoute const &route)
{
  std::vector<IntersectionPtr> result;
  for (auto roadSegmentIter = route.road_segments.begin(); roadSegmentIter != route.road_segments.end();
       roadSegmentIter++)
  {
    // @todo: also consider segments leaving intersection if first segment is already within intersection
    auto roadSegmentResult = getIntersectionForRoadSegment(route::RouteIterator(route, roadSegmentIter));
    if (bool(roadSegmentResult))
    {
      result.push_back(roadSegmentResult);
    }
  }
  return result;
}

IntersectionPtr Intersection::getNextIntersectionOnRoute(route::FullRoute const &route)
{
  IntersectionPtr result;
  for (auto roadSegmentIter = route.road_segments.begin(); roadSegmentIter != route.road_segments.end();
       roadSegmentIter++)
  {
    // @todo: also consider segments leaving intersection if first segment is already within intersection
    result = getIntersectionForRoadSegment(route::RouteIterator(route, roadSegmentIter));
    if (bool(result))
    {
      return result;
    }
  }
  return result;
}

bool Intersection::segmentLeavesIntersectionOnRoute(route::FullRoute const &route,
                                                    route::RoadSegmentList::const_iterator const &roadSegmentIt,
                                                    lane::LaneId lane_id)
{
  // end of iterator? -> false
  // lane is of type intersection? -> iterate through successors
  // lane of type normal -> true
  if (roadSegmentIt == route.road_segments.end())
  {
    return false;
  }
  if (isLanePartOfAnIntersection(lane_id))
  {
    mLanesOnRoute.insert(lane_id);
    for (auto const &segment : roadSegmentIt->drivable_lane_segments)
    {
      if (segment.lane_interval.lane_id == lane_id)
      {
        for (auto successorId : segment.successors)
        {
          if (segmentLeavesIntersectionOnRoute(route, roadSegmentIt + 1, successorId))
          {
            return true;
          }
        }
      }
    }
    return false; // we did not find a (successor of a) a successor that leaves the intersection
  }
  else
  {
    // lane_id is outside of the intersection, thus the route left the intersection
    mOutgoingLanesOnRoute.insert(lane_id);
    return true;
  }
  return false;
}

lane::LaneIdSet
Intersection::successorsOnRouteLeavingIntersection(route::FullRoute const &route,
                                                   route::RoadSegmentList::const_iterator const &roadSegmentIt,
                                                   route::LaneSegment const &laneSegment)
{
  lane::LaneIdSet result;
  for (auto successorId : laneSegment.successors)
  {
    if (segmentLeavesIntersectionOnRoute(route, roadSegmentIt + 1, successorId))
    {
      result.insert(successorId);
    }
  }
  return result;
}

lane::LaneIdSet Intersection::successorsOnRouteLeavingIntersection(route::LaneSegment const &laneSegment)
{
  lane::LaneIdSet result;
  for (auto successorId : laneSegment.successors)
  {
    auto allReachableInternalAndOutgoingLanes
      = getAllReachableInternalAndOutgoingLanes(successorId, SuccessorMode::AnyIntersection);
    mLanesOnRoute.insert(allReachableInternalAndOutgoingLanes.first.begin(),
                         allReachableInternalAndOutgoingLanes.first.end());
    mOutgoingLanesOnRoute.insert(allReachableInternalAndOutgoingLanes.second.begin(),
                                 allReachableInternalAndOutgoingLanes.second.end());
    if (!allReachableInternalAndOutgoingLanes.second.empty())
    {
      result.insert(successorId);
    }
  }
  return result;
}

void Intersection::extractRightOfWayAndCollectTrafficLights(route::LaneInterval const &lane_interval,
                                                            lane::LaneIdSet const &successors,
                                                            lane::LaneId &toLaneId)
{
  auto beforeLaneId = lane_interval.lane_id;
  for (auto succId : successors)
  {
    auto intersectionType = getRightOfWayForTransition(beforeLaneId, succId);
    if (intersectionType != IntersectionType::Unknown)
    {
      if ((mIntersectionType != IntersectionType::Unknown) && (mIntersectionType != intersectionType))
      {
        access::getLogger()->warn("Different types of intersection detected! From {} To {}", beforeLaneId, succId);
      }
      toLaneId = succId;
      mIntersectionType = intersectionType;
      collectTrafficLights(beforeLaneId, toLaneId);
    }
  }
}

Intersection::Intersection(route::FullRoute const &route,
                           route::RoadSegmentList::const_iterator const &lastSegmentBeforeIntersection,
                           route::RoadSegmentList::const_iterator const &firstSegmentWithinIntersection)
  : mRoutePlanningCounter(route.route_planning_counter)
  , mSegmentCountFromDestination(firstSegmentWithinIntersection->segment_count_from_destination)
  , mSpeedLimit(std::numeric_limits<physics::Speed>::max())
{
  // ensure all intersection arms are initialized, to be safe when later accessing with std::map::at()
  mIntersectionArms[TurnDirection::Unknown] = lane::LaneIdSet();
  mIntersectionArms[TurnDirection::Right] = lane::LaneIdSet();
  mIntersectionArms[TurnDirection::Straight] = lane::LaneIdSet();
  mIntersectionArms[TurnDirection::Left] = lane::LaneIdSet();
  mIntersectionArms[TurnDirection::UTurn] = lane::LaneIdSet();

  // we don't need to check if the iterators are valid because this is called
  // from within getIntersectionForRoadSegment() only if the checks succeed
  lane::LaneId toLaneId{0};
  for (auto const &segment : lastSegmentBeforeIntersection->drivable_lane_segments)
  {
    mIncomingLanesOnRoute.insert(segment.lane_interval.lane_id);
    auto successors = successorsOnRouteLeavingIntersection(route, lastSegmentBeforeIntersection, segment);
    extractRightOfWayAndCollectTrafficLights(segment.lane_interval, successors, toLaneId);
  }
  if (toLaneId == lane::LaneId(0))
  {
    // seems as if the route doesn't lead out of the intersection
    // so try to collect all possible ways out
    for (auto const &segment : lastSegmentBeforeIntersection->drivable_lane_segments)
    {
      auto successors = successorsOnRouteLeavingIntersection(segment);
      extractRightOfWayAndCollectTrafficLights(segment.lane_interval, successors, toLaneId);
    }
  }

  extractLanesOfCoreIntersection(toLaneId);
  if (!isLanePartOfCoreIntersection(toLaneId))
  {
    throw std::runtime_error("Lane is not part of intersection!");
  }

  extractIncomingLanes();
  calculateParaPoints();
  extractCrossingLanes();
  orderIntersectionArmsAndExtractTurnDirection();
  extractLanesWithHigherPriority();
  extractLanesWithLowerPriority();
  extractLanesFromSameIntersectionArm();
  calculateEnteringProrityParaPoints();
  calculateSpeedLimit();
}

IntersectionType Intersection::intersectionType() const
{
  return mIntersectionType;
}

TurnDirection Intersection::turnDirection() const
{
  return mTurnDirection;
}

landmark::LandmarkIdSet const &Intersection::applicableTrafficLights() const
{
  return mTrafficLightIds;
}

lane::LaneIdSet const &Intersection::lanesOnRoute() const
{
  return mLanesOnRoute;
}

point::ParaPointList const &Intersection::paraPointsOnRoute() const
{
  return mParaPointsOnRoute;
}

lane::LaneIdSet const &Intersection::incomingLanesOnRoute() const
{
  return mIncomingLanesOnRoute;
}

lane::LaneIdSet const &Intersection::outgoingLanesOnRoute() const
{
  return mOutgoingLanesOnRoute;
}

point::ParaPointList const &Intersection::incomingParaPointsOnRoute() const
{
  return mIncomingParaPointsOnRoute;
}

point::ParaPointList const &Intersection::outgoingParaPointsOnRoute() const
{
  return mOutgoingParaPointsOnRoute;
}

point::ParaPointList const &Intersection::outgoingParaPoints() const
{
  return exitParaPoints();
}

lane::LaneIdSet const &Intersection::internalLanesWithHigherPriority() const
{
  return mInternalLanesWithHigherPriority;
}

lane::LaneIdSet const &Intersection::internalLanesWithLowerPriority() const
{
  return mInternalLanesWithLowerPriority;
}

lane::LaneIdSet const &Intersection::incomingLanesWithLowerPriority() const
{
  return mIncomingLanesWithLowerPriority;
}

lane::LaneIdSet const &Intersection::incomingLanesWithHigherPriority() const
{
  return mIncomingLanesWithHigherPriority;
}

lane::LaneIdSet const &Intersection::incomingLanes() const
{
  return mIncomingLanes;
}

lane::LaneIdSet const &Intersection::outgoingLanes() const
{
  return exitLanes();
}

point::ParaPointList const &Intersection::incomingParaPoints() const
{
  return mIncomingParaPoints;
}

point::ParaPointList const &Intersection::incomingParaPointsWithHigherPriority() const
{
  return mIncomingParaPointsWithHigherPriority;
}

point::ParaPointList const &Intersection::incomingParaPointsWithLowerPriority() const
{
  return mIncomingParaPointsWithLowerPriority;
}

lane::LaneIdSet const &Intersection::crossingLanes() const
{
  return mCrossingLanes;
}

route::RoutePlanningCounter Intersection::getRoutePlanningCounter() const
{
  return mRoutePlanningCounter;
}

route::SegmentCounter Intersection::getRouteSegmentCountFromDestination() const
{
  return mSegmentCountFromDestination;
}

void Intersection::updateRouteCounters(route::RoutePlanningCounter newRoutePlanningCounter,
                                       route::SegmentCounter newRouteSegmentCounter)
{
  mRoutePlanningCounter = newRoutePlanningCounter;
  mSegmentCountFromDestination = newRouteSegmentCounter;
}

route::RouteParaPoint Intersection::getIntersectionStartOnRoute() const
{
  route::RouteParaPoint result;
  result.route_planning_counter = getRoutePlanningCounter();
  result.segment_count_from_destination = getRouteSegmentCountFromDestination();
  result.parametric_offset = physics::ParametricValue(0.);
  return result;
}

void Intersection::extractIncomingLanes()
{
  for (auto lane_id : entryLanes())
  {
    if (mIncomingLanesOnRoute.count(lane_id) == 0)
    {
      mIncomingLanes.insert(lane_id);
      mIncomingParaPoints.push_back(getEntryParaPointOfExternalLane(lane_id));
    }
  }
}

void Intersection::calculateParaPoints()
{
  for (auto lane_id : mIncomingLanesOnRoute)
  {
    mIncomingParaPointsOnRoute.push_back(getEntryParaPointOfExternalLane(lane_id));
  }

  for (auto outGoingLaneId : mOutgoingLanesOnRoute)
  {
    mOutgoingParaPointsOnRoute.push_back(getExitParaPointOfExternalLane(outGoingLaneId));
  }

  for (auto lane_id : mLanesOnRoute)
  {
    auto para_point = getEntryParaPointOfExternalLane(lane_id);
    mParaPointsOnRoute.push_back(para_point);
  }
}

void Intersection::extractCrossingLanes()
{
  // first, collect all lanes that overlap with any lane of the route
  for (auto insideId : mLanesOnRoute)
  {
    mCrossingLanes.insert(mOverlapping[insideId].begin(), mOverlapping[insideId].end());
  }
  // remove all lanes that are a successor of one of the incoming lanes on the route
  // otherwise vehicles driving in the same or parallel direction would also be considered...
  lane::LaneIdSet internalSuccessorsOfRouteEntry;
  for (auto lane_id : mIncomingLanesOnRoute)
  {
    auto succ = getAllSuccessorsInLaneDirectionWithinIntersection(lane_id, SuccessorMode::OwnIntersection);
    internalSuccessorsOfRouteEntry.insert(succ.begin(), succ.end());
  }
  for (auto lane_id : internalSuccessorsOfRouteEntry)
  {
    mCrossingLanes.erase(lane_id);
  }
}

// this function return the directional angle of lane_id
point::ENUHeading getLaneDirectionalAngle(lane::LaneId lane_id)
{
  auto lane = lane::getLane(lane_id);

  // Collect the parapoint of the lane
  physics::ParametricValue laneParapoint
    = (isLaneDirectionNegative(lane) ? physics::ParametricValue(0.) : physics::ParametricValue(1.));

  // get the starting point and end point of the lane
  point::ECEFPoint laneStartPoint = getParametricPoint(lane, laneParapoint, physics::ParametricValue(0.5));
  point::ECEFPoint laneEndPoint
    = getParametricPoint(lane, physics::ParametricValue(1.) - laneParapoint, physics::ParametricValue(0.5));

  // get the directional vector
  point::ECEFHeading directionalVector = point::createECEFHeading(laneStartPoint, laneEndPoint);
  point::ENUHeading headingENU = point::createENUHeading(directionalVector, laneStartPoint);

  return headingENU;
}

static void directionOfLanes(point::ParaPointList const &lanes,
                             point::ENUHeading referenceAngle,
                             std::vector<std::pair<point::ENUHeading, point::ParaPoint>> &intersectionLanesDirection)

{
  for (auto const &lane : lanes)
  {
    auto angle = getLaneDirectionalAngle(lane.lane_id);

    // all angles should be relative to the angle of the arm where the route enters the intersection.
    angle = angle - referenceAngle;
    if (angle < point::ENUHeading(0))
    {
      angle += point::ENUHeading(2 * M_PI);
    }
    intersectionLanesDirection.push_back({angle, lane});
  }
}

point::ENUHeading degToENUHeading(double angle)
{
  return point::ENUHeading(angle * M_PI / 180.);
}

TurnDirection turnDirectionForAngle(point::ENUHeading const angle)
{
  // we assume that the angle is in range [0 2 PI] where 0 is the direction of the entering lane
  if ((angle > degToENUHeading(315.)) || (angle < degToENUHeading(45.)))
  {
    return TurnDirection::UTurn;
  }
  else if (angle > degToENUHeading(225.))
  {
    return TurnDirection::Left;
  }
  else if (angle > degToENUHeading(135.))
  {
    return TurnDirection::Straight;
  }
  else if (angle > degToENUHeading(45.))
  {
    return TurnDirection::Right;
  }
  else
  {
    // we should never come here
    return TurnDirection::Unknown;
  }
}

void Intersection::orderIntersectionArmsAndExtractTurnDirection()
{
  std::vector<std::pair<point::ENUHeading, point::ParaPoint>> intersectionLanesDirection;

  auto const egoIntersectionEntryLaneId = *mIncomingLanesOnRoute.begin();

  // angle (around up-axis) of the incoming lane, used as reference angle
  auto const referenceAngle = getLaneDirectionalAngle(egoIntersectionEntryLaneId);

  // calculate the angle for all incoming lanes of the intersection
  directionOfLanes(mEntryParaPoints, referenceAngle, intersectionLanesDirection);

  // calculate the angle for all outgoing lanes of the intersection
  directionOfLanes(mExitParaPoints, (referenceAngle + point::ENUHeading(M_PI)), intersectionLanesDirection);

  // Group all incoming/outgoing lanes into arms (ordered counterclockwise).

  for (auto laneDirection : intersectionLanesDirection)
  {
    auto turnDirection = turnDirectionForAngle(laneDirection.first);
    if ((mTurnDirection == TurnDirection::Unknown) && (mOutgoingLanesOnRoute.count(laneDirection.second.lane_id) > 0))
    {
      mTurnDirection = turnDirection;
    }
    mIntersectionArms[turnDirection].insert(laneDirection.second.lane_id);
  }
}

void Intersection::extractLanesWithHigherPriority()
{
  switch (mIntersectionType)
  {
    case IntersectionType::Yield: // fallthrough intended here
    case IntersectionType::Stop:
      adjustLanesForYield();
      break;
    case IntersectionType::Unknown: // fallthrough intended here, unknown means be careful with crossing lanes
    case IntersectionType::AllWayStop:
      // nothing to be done, simply use the crossing lanes
      mInternalLanesWithHigherPriority = mCrossingLanes;
      break;
    case IntersectionType::HasWay:
      adjustLanesForHasWay();
      break;
    case IntersectionType::Crosswalk: // no need for adaptation, there should not be any crossing lanes
      break;
    case IntersectionType::PriorityToRight:
    case IntersectionType::PriorityToRightAndStraight:
      adjustPriorityToRight();
      break;
    case IntersectionType::TrafficLight:
      adjustLanesForTrafficLight();
      break;
    default:
      // throw exception?
      break;
  }
}

void Intersection::extractLanesWithLowerPriority()
{
  for (auto lane_id : mInternalLanes)
  {
    if ((mLanesOnRoute.find(lane_id) == mLanesOnRoute.end())
        && (mInternalLanesWithHigherPriority.find(lane_id) == mInternalLanesWithHigherPriority.end()))
    {
      mInternalLanesWithLowerPriority.insert(lane_id);
    }
  }
}

void Intersection::extractLanesFromSameIntersectionArm()
{
  for (auto lane_id : mIncomingLanesOnRoute)
  {
    auto relevantLanes = getAllSuccessorsInLaneDirectionWithinIntersection(lane_id, SuccessorMode::OwnIntersection);
    mInternalLanesFromSameIntersectionArm.insert(relevantLanes.begin(), relevantLanes.end());
  }
}

void Intersection::calculateEnteringProrityParaPoints()
{
  for (auto lane_id : mIncomingLanes)
  {
    auto successorLanes = getAllSuccessorsInLaneDirectionWithinIntersection(lane_id, SuccessorMode::OwnIntersection);
    bool internalPriorityFound = false;

    for (auto successorLaneIter = successorLanes.begin();
         successorLaneIter != successorLanes.end() && !internalPriorityFound;
         successorLaneIter++)
    {
      if (mInternalLanesWithHigherPriority.find(*successorLaneIter) != mInternalLanesWithHigherPriority.end())
      {
        internalPriorityFound = true;
      }
    }
    if (internalPriorityFound)
    {
      auto para_point = getEntryParaPointOfExternalLane(lane_id);
      mIncomingParaPointsWithHigherPriority.push_back(para_point);
      mIncomingLanesWithHigherPriority.insert(lane_id);
    }
    else
    {
      auto para_point = getEntryParaPointOfExternalLane(lane_id);
      mIncomingParaPointsWithLowerPriority.push_back(para_point);
      mIncomingLanesWithLowerPriority.insert(lane_id);
    }
  }
}

bool Intersection::turnDirectionCrossesStraightTraffic() const
{
  // right handed traffic
  if (access::isRightHandedTraffic())
  {
    return (mTurnDirection == TurnDirection::Left) || (mTurnDirection == TurnDirection::UTurn);
  }
  // left handed traffic
  else
  {
    return (mTurnDirection == TurnDirection::Right) || (mTurnDirection == TurnDirection::UTurn);
  }
}

bool Intersection::outgoingIntersectionArmCanBeReached(lane::LaneId const lane_id,
                                                       TurnDirection const outgoingIntersectionArm)
{
  for (auto reachableOutgoingLaneId : getAllReachableOutgoingLanes(lane_id, SuccessorMode::OwnIntersection))
  {
    if (mIntersectionArms[outgoingIntersectionArm].count(reachableOutgoingLaneId) > 0)
    {
      return true;
    }
  }
  return false;
}

void Intersection::addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(
  lane::LaneId const &lane, TurnDirection const restrictToOutgoingIntersectionArm)
{
  auto lanesToCheck = getLaneAndAllSuccessorsInLaneDirectionWithinIntersection(lane, SuccessorMode::OwnIntersection);
  for (auto laneToCheckId : lanesToCheck)
  {
    if (mCrossingLanes.count(laneToCheckId) > 0)
    {
      if ((restrictToOutgoingIntersectionArm == TurnDirection::Unknown)
          || outgoingIntersectionArmCanBeReached(laneToCheckId, restrictToOutgoingIntersectionArm))
      {
        mInternalLanesWithHigherPriority.insert(laneToCheckId);
      }
    }
  }
}

void Intersection::addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(
  lane::LaneIdSet const &lanes, TurnDirection const restrictToOutgoingIntersectionArm)
{
  for (auto lane_id : lanes)
  {
    addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(lane_id, restrictToOutgoingIntersectionArm);
  }
}

void Intersection::addLaneAndSuccessorsToInternalLanesWithHigherPriority(
  lane::LaneId const &lane, TurnDirection const restrictToOutgoingIntersectionArm)
{
  auto lanesToCheck = getLaneAndAllSuccessorsInLaneDirectionWithinIntersection(lane, SuccessorMode::OwnIntersection);
  for (auto laneToCheckId : lanesToCheck)
  {
    if ((restrictToOutgoingIntersectionArm == TurnDirection::Unknown)
        || outgoingIntersectionArmCanBeReached(laneToCheckId, restrictToOutgoingIntersectionArm))
    {
      mInternalLanesWithHigherPriority.insert(laneToCheckId);
    }
  }
}

void Intersection::addLaneAndSuccessorsToInternalLanesWithHigherPriority(
  lane::LaneIdSet const &lanes, TurnDirection const restrictToOutgoingIntersectionArm)
{
  for (auto lane_id : lanes)
  {
    addLaneAndSuccessorsToInternalLanesWithHigherPriority(lane_id, restrictToOutgoingIntersectionArm);
  }
}

void Intersection::adjustLanesForHasWay()
{
  for (auto const &intersectionArm : mIntersectionArms)
  {
    for (auto lane_id : intersectionArm.second)
    {
      auto sucessorLanes
        = getDirectSuccessorsInLaneDirectionWithinIntersection(lane_id, SuccessorMode::OwnIntersection);
      for (auto sucessorLaneId : sucessorLanes)
      {
        auto trafficRuleAtOtherLane = getRightOfWayForTransition(lane_id, sucessorLaneId);

        // has way lanes have to be respected if we turn
        if ((trafficRuleAtOtherLane == IntersectionType::HasWay) && turnDirectionCrossesStraightTraffic())
        {
          addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(sucessorLaneId);
        }
      }
    }
  }
}

void Intersection::adjustLanesForYield()
{
  for (auto const &intersectionArm : mIntersectionArms)
  {
    for (auto lane_id : intersectionArm.second)
    {
      auto sucessorLanes
        = getDirectSuccessorsInLaneDirectionWithinIntersection(lane_id, SuccessorMode::OwnIntersection);
      for (auto sucessorLaneId : sucessorLanes)
      {
        auto trafficRuleAtOtherLane = getRightOfWayForTransition(lane_id, sucessorLaneId);
        // need to give way to all of lanes that have way
        if (trafficRuleAtOtherLane == IntersectionType::HasWay)
        {
          addLaneAndSuccessorsToInternalLanesWithHigherPriority(sucessorLaneId);
        }
        // yield lanes only have to be respected if we turn
        else if ((trafficRuleAtOtherLane == IntersectionType::Yield) && turnDirectionCrossesStraightTraffic())
        {
          addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(sucessorLaneId);
        }
      }
    }
  }
}

void Intersection::adjustPriorityToRight()
{
  if ((IntersectionType::PriorityToRightAndStraight == mIntersectionType)
      && (mTurnDirection == TurnDirection::Straight))
  {
    // if we drive straight, only the straight and left turning has prio
    addLaneAndSuccessorsToInternalLanesWithHigherPriority(mIntersectionArms[TurnDirection::Right], TurnDirection::Left);
    addLaneAndSuccessorsToInternalLanesWithHigherPriority(mIntersectionArms[TurnDirection::Right],
                                                          TurnDirection::UTurn);
  }
  else
  {
    // all traffic from right
    addLaneAndSuccessorsToInternalLanesWithHigherPriority(mIntersectionArms[TurnDirection::Right]);
  }

  // plus take care on the straight traffic when turning
  if (turnDirectionCrossesStraightTraffic())
  {
    addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(mIntersectionArms[TurnDirection::Straight]);
    if (IntersectionType::PriorityToRightAndStraight == mIntersectionType)
    {
      // the other straight driving lanes have priority, too
      addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(mIntersectionArms[TurnDirection::Right],
                                                                      TurnDirection::Left);
      addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(mIntersectionArms[TurnDirection::Left],
                                                                      TurnDirection::Right);
    }
  }
}

void Intersection::adjustLanesForTrafficLight()
{
  if (turnDirectionCrossesStraightTraffic() && onlySolidTrafficLightsOnRoute())
  {
    addLaneAndSuccessorsToInternalLanesWithHigherPriorityIfCrossing(mIntersectionArms[TurnDirection::Straight]);
  }
}

bool Intersection::objectOnIncomingLane(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mIncomingLanes.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnInternalLaneWithLowerPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mInternalLanesWithLowerPriority.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnIncomingLaneWithLowerPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mIncomingLanesWithLowerPriority.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnLaneWithLowerPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  return objectOnInternalLaneWithLowerPriority(object) || objectOnIncomingLaneWithLowerPriority(object);
}

bool Intersection::objectOnInternalLaneWithHigherPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mInternalLanesWithHigherPriority.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnIncomingLaneWithHigherPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mIncomingLanesWithHigherPriority.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnLaneWithHigherPriority(match::MapMatchedObjectBoundingBox const &object) const
{
  return objectOnInternalLaneWithHigherPriority(object) || objectOnIncomingLaneWithHigherPriority(object);
}

bool Intersection::objectOnCrossingLane(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mCrossingLanes.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectOnIntersectionRoute(match::MapMatchedObjectBoundingBox const &object) const
{
  for (auto const &occupiedLane : object.lane_occupied_regions)
  {
    if (mLanesOnRoute.count(occupiedLane.lane_id) > 0)
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectRouteCrossesIntersectionRoute(route::FullRoute const &objectRoute) const
{
  for (auto crossingLaneId : mCrossingLanes)
  {
    auto findResult = route::findWaypoint(crossingLaneId, objectRoute);
    if (findResult.isValid())
    {
      return true;
    }
  }
  return false;
}

bool Intersection::objectRouteFromSameArmAsIntersectionRoute(route::FullRoute const &objectRoute) const
{
  bool routeLaneFound = false;
  for (auto const &roadSegment : objectRoute.road_segments)
  {
    for (auto const &laneSegment : roadSegment.drivable_lane_segments)
    {
      if ((mInternalLanesFromSameIntersectionArm.count(laneSegment.lane_interval.lane_id) > 0)
          || (mIncomingLanesOnRoute.count(laneSegment.lane_interval.lane_id) > 0))
      {
        routeLaneFound = true;
      }
      else if (mInternalLanes.count(laneSegment.lane_interval.lane_id) > 0)
      {
        // another internal lane is found in the route, so route differs
        return false;
      }
      else if (routeLaneFound)
      {
        // if we previously have found a route lane and are now again outside the intersection: route is identical
        return routeLaneFound;
      }
      else
      {
        // nothing decided yet since neither a lane on intersection route found nor any other internal lane touched
      }
    }
  }
  return routeLaneFound;
}

bool Intersection::objectRouteOppositeToIntersectionRoute(route::FullRoute const &objectRoute) const
{
  route::FindWaypointResult findResult(objectRoute);
  for (auto const &laneOnOutgoingIntersectionArm : mIntersectionArms.at(mTurnDirection))
  {
    findResult = route::findWaypoint(laneOnOutgoingIntersectionArm, objectRoute);
    if (findResult.isValid())
    {
      break;
    }
  }
  if (!findResult.isValid())
  {
    // check if the object route starts already within the intersection
    if (!objectRoute.road_segments.empty() && !objectRoute.road_segments.begin()->drivable_lane_segments.empty()
        && mInternalLanes.count(
             objectRoute.road_segments.begin()->drivable_lane_segments.begin()->lane_interval.lane_id)
          > 0)
    {
      // object is already within intersection
      for (auto const &laneOnOutgoingIntersectionArm : mIntersectionArms.at(mTurnDirection))
      {
        auto internalLanesFromOutgoingIntersectionArm = getAllSuccessorsInLaneDirectionWithinIntersection(
          laneOnOutgoingIntersectionArm, SuccessorMode::OwnIntersection);
        if (internalLanesFromOutgoingIntersectionArm.count(
              objectRoute.road_segments.begin()->drivable_lane_segments.begin()->lane_interval.lane_id)
            > 0)
        {
          // and object came from outgoing intersection arm
          findResult = route::findWaypoint(
            objectRoute.road_segments.begin()->drivable_lane_segments.begin()->lane_interval.lane_id, objectRoute);
        }
      }
    }
  }

  if (findResult.isValid())
  {
    // shorten object route
    route::FullRoute remainingObjectRoute(objectRoute);
    route::shortenRoute(findResult.queryPosition, remainingObjectRoute);

    // now search for leaving the intersection at the route incoming arm
    for (auto const &laneOnIncomingIntersectionArm : mIntersectionArms.at(TurnDirection::UTurn))
    {
      auto result = route::findWaypoint(laneOnIncomingIntersectionArm, remainingObjectRoute);
      if (result.isValid())
      {
        return true;
      }
    }
  }
  return false;
}

physics::Distance Intersection::objectInterpenetrationDistanceWithIntersection(match::Object const &object) const
{
  physics::Distance maxDistance(0.);
  TurnDirection coveredIntersectionArms = TurnDirection::Unknown;
  for (auto const &occupiedLane : object.map_matched_bounding_box.lane_occupied_regions)
  {
    if ((mEntryBorderLanes.count(occupiedLane.lane_id)) > 0u || (mExitBorderLanes.count(occupiedLane.lane_id)) > 0)
    {
      auto const lane_length = lane::getLane(occupiedLane.lane_id).length;
      physics::Distance const penetrationDistance
        = (occupiedLane.longitudinal_range.maximum - occupiedLane.longitudinal_range.minimum) * lane_length;
      maxDistance = std::max(maxDistance, penetrationDistance);
    }
    else if (mInternalLanes.count(occupiedLane.lane_id) == 0u)
    {
      // not an internal lane, check if different intersection arms covered by the vehicle
      for (auto const &intersectionArm : mIntersectionArms)
      {
        if (intersectionArm.second.count(occupiedLane.lane_id) > 0u)
        {
          if (coveredIntersectionArms == TurnDirection::Unknown)
          {
            coveredIntersectionArms = intersectionArm.first;
          }
          else if (coveredIntersectionArms != intersectionArm.first)
          {
            // covering two different intersection arms, actually crossing the intersection
            return object.enu_position.dimension.length;
          }
        }
      }
    }
  }

  if ((maxDistance > physics::Distance(0.)) && (coveredIntersectionArms == TurnDirection::Unknown))
  {
    // not touching incoming/outgoing lane at all, but touching an internal lane
    // => fully within intersection
    maxDistance = object.enu_position.dimension.length;
  }

  // result must not extend length of the object
  maxDistance = std::min(maxDistance, object.enu_position.dimension.length);
  return maxDistance;
}

bool Intersection::objectRouteCrossesLanesWithHigherPriority(route::FullRoute const &objectRoute) const
{
  for (auto laneWithHigherPrioId : mInternalLanesWithHigherPriority)
  {
    auto findResult = route::findWaypoint(laneWithHigherPrioId, objectRoute);
    if (findResult.isValid())
    {
      return true;
    }
  }

  return false;
}

void Intersection::collectTrafficLights(lane::LaneId fromLaneId, lane::LaneId toLaneId)
{
  auto laneFrom = lane::getLane(fromLaneId);
  auto laneTo = lane::getLane(toLaneId);
  auto contactLanesFromOutside = lane::getContactLane(laneFrom, toLaneId);
  auto contactLanesFromInside = lane::getContactLane(laneTo, fromLaneId);
  for (auto contactLaneFromOutside : contactLanesFromOutside)
  {
    for (auto const &contactType : contactLaneFromOutside.types)
    {
      if (contactType == lane::ContactType::TRAFFIC_LIGHT)
      {
        mTrafficLightIds.insert(contactLaneFromOutside.landmark_id);
      }
    }
  }

  for (auto contactLaneFromInside : contactLanesFromInside)
  {
    for (auto const &contactType : contactLaneFromInside.types)
    {
      if (contactType == lane::ContactType::TRAFFIC_LIGHT)
      {
        mTrafficLightIds.insert(contactLaneFromInside.landmark_id);
      }
    }
  }
}

physics::Speed Intersection::getSpeedLimit() const
{
  return mSpeedLimit;
}

void Intersection::calculateSpeedLimit()
{
  for (auto const &internalLaneId : mInternalLanes)
  {
    route::LaneInterval lane_interval;
    lane_interval.lane_id = internalLaneId;
    lane_interval.start = physics::ParametricValue(0.);
    lane_interval.end = physics::ParametricValue(1.);
    auto speed_limits = route::getSpeedLimits(lane_interval);
    for (auto const &speed_limit : speed_limits)
    {
      mSpeedLimit = std::min(mSpeedLimit, speed_limit.speed_limit);
    }
  }
}

landmark::TrafficLightType Intersection::extractTrafficLightType(landmark::LandmarkId trafficLightId)
{
  auto trafficLight = landmark::getLandmark(trafficLightId);
  return trafficLight.traffic_light_type;
}

bool Intersection::isSolidTrafficLight(landmark::LandmarkId trafficLightId)
{
  switch (extractTrafficLightType(trafficLightId))
  {
    case landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_GREEN:
    case landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::BIKE_RED_GREEN:
    case landmark::TrafficLightType::BIKE_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::PEDESTRIAN_RED_GREEN:
    case landmark::TrafficLightType::PEDESTRIAN_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::RIGHT_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::RIGHT_STRAIGHT_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::STRAIGHT_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::LEFT_RED_YELLOW_GREEN:
    case landmark::TrafficLightType::LEFT_STRAIGHT_RED_YELLOW_GREEN:
      return false;
      break;
    case landmark::TrafficLightType::INVALID:
    case landmark::TrafficLightType::UNKNOWN:
    case landmark::TrafficLightType::SOLID_RED_YELLOW:
    case landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN:
      return true;
      break;
    default:
      throw std::invalid_argument("Intersection isSolidTrafficLight: Invalid traffic light type given");
  }
}

bool Intersection::onlySolidTrafficLightsOnRoute()
{
  for (auto trafficLightId : mTrafficLightIds)
  {
    if (!isSolidTrafficLight(trafficLightId))
    {
      return false;
    }
  }
  return true;
}

} // namespace intersection
} // namespace map
} // namespace ad

namespace std {

std::ostream &operator<<(std::ostream &os, ::ad::map::intersection::Intersection const &intersection)
{
  os << static_cast<::ad::map::intersection::CoreIntersection const &>(intersection);
  os << "Intersection[";
  os << toString(intersection.intersectionType());
  if (intersection.intersectionType() == ::ad::map::intersection::IntersectionType::TrafficLight)
  {
    os << ": " << intersection.applicableTrafficLights();
  }
  os << "]";
  os << std::endl;
  os << "->internalLanes: ";
  os << intersection.internalLanes();
  os << std::endl;
  os << "->internalLanesWithHigherPriority: ";
  os << intersection.internalLanesWithHigherPriority();
  os << std::endl;
  os << "->incomingLanes: ";
  os << intersection.incomingLanes();
  os << std::endl;
  os << "->incomingParaPoints: ";
  os << intersection.incomingParaPoints();
  os << std::endl;
  os << "->incomingParaPointsWithHigherPriority: ";
  os << intersection.incomingParaPointsWithHigherPriority();
  os << std::endl;
  os << "->crossingLanes";
  os << intersection.crossingLanes();
  os << std::endl;
  os << "->lanesOnRoute: ";
  os << intersection.lanesOnRoute();
  os << std::endl;
  os << "->incomingLanesOnRoute: ";
  os << intersection.incomingLanesOnRoute();
  os << std::endl;
  os << "->incomingParaPointsOnRoute: ";
  os << intersection.incomingParaPointsOnRoute();
  return os;
}

} // namespace std
