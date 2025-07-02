// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/Planning.hpp"

#include <algorithm>
#include "RouteOperationPrivate.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
#include "ad/map/lane/BorderOperation.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/match/AdMapMatching.hpp"
#include "ad/map/match/MapMatchedOperation.hpp"
#include "ad/map/route/RouteAStar.hpp"
#include "ad/map/route/RouteOperation.hpp"
#include "ad/map/route/RoutePrediction.hpp"

namespace ad {
namespace map {
namespace route {
namespace planning {

physics::Probability createHeadingRating(point::ENUHeading const &routeHeading,
                                         point::ENUHeading const &objectHeading,
                                         double objectHeadingOffset = 0.);

struct ConnectingRouteCandidate
{
  ConnectingRouteCandidate(const match::Object &iObjectA,
                           const match::Object &iObjectB,
                           Route::RawRoute const &iRawRoute,
                           match::LaneOccupiedRegion const &iRegionA,
                           match::LaneOccupiedRegion const &iRegionB,
                           lane::LaneIdSet const &iRelevantLanes)
    : objectA(iObjectA)
    , objectB(iObjectB)
    , rawRoute(iRawRoute)
    , regionA(iRegionA)
    , regionB(iRegionB)
    , relevantLanes(iRelevantLanes)
  {
  }

  ConnectingRouteCandidate(ConnectingRouteCandidate const &other) = delete;
  ConnectingRouteCandidate(ConnectingRouteCandidate &&other) = default;

  ConnectingRouteCandidate &operator=(ConnectingRouteCandidate const &other) = delete;
  ConnectingRouteCandidate &operator=(ConnectingRouteCandidate &&other)
  {
    if ((this != &other) && (&this->objectA == &other.objectA) && (&this->objectB == &other.objectB)
        && (&this->relevantLanes == &other.relevantLanes))
    {
      rawRoute = std::move(other.rawRoute);
      regionA = std::move(other.regionA);
      regionB = std::move(other.regionB);
      fullRoute = std::move(other.fullRoute);
      fullRouteLength = std::move(other.fullRouteLength);
      enuHeadingRouteA = std::move(other.enuHeadingRouteA);
      enuHeadingRouteB = std::move(other.enuHeadingRouteB);

      headingRatingAlongRouteA = std::move(other.headingRatingAlongRouteA);
      headingRatingAlongRouteB = std::move(other.headingRatingAlongRouteB);
      headingRatingOppositeRouteA = std::move(other.headingRatingOppositeRouteA);
      headingRatingOppositeRouteB = std::move(other.headingRatingOppositeRouteB);

      resultRoute = std::move(other.resultRoute);
    }
    return *this;
  }

  const match::Object &objectA;
  const match::Object &objectB;
  Route::RawRoute rawRoute;
  match::LaneOccupiedRegion regionA;
  match::LaneOccupiedRegion regionB;
  lane::LaneIdSet const &relevantLanes;

  FullRoute fullRoute;
  physics::Distance fullRouteLength{};
  point::ENUHeading enuHeadingRouteA;
  point::ENUHeading enuHeadingRouteB;

  physics::Probability headingRatingAlongRouteA{0.};
  physics::Probability headingRatingAlongRouteB{0.};
  physics::Probability headingRatingOppositeRouteA{0.};
  physics::Probability headingRatingOppositeRouteB{0.};

  ConnectingRoute resultRoute;

  void createFullRouteAndRating()
  {
    fullRoute = calculateFullRoute(regionA, regionB, true);
    fullRouteLength = route::calcLength(fullRoute);

    headingRatingAlongRouteA = createHeadingRating(enuHeadingRouteA, objectA.enu_position.heading);
    headingRatingAlongRouteB = createHeadingRating(enuHeadingRouteB, objectB.enu_position.heading);
    headingRatingOppositeRouteA = createHeadingRating(enuHeadingRouteA, objectA.enu_position.heading, M_PI);
    headingRatingOppositeRouteB = createHeadingRating(enuHeadingRouteB, objectB.enu_position.heading, M_PI);
  }

  FullRoute calculateFullRoute(match::LaneOccupiedRegion const &regionDropStart,
                               match::LaneOccupiedRegion const &regionDropEnd,
                               bool updateHeading);

  FullRoute getInvertedFullRoute()
  {
    std::reverse(rawRoute.paraPointList.begin(), rawRoute.paraPointList.end());
    return calculateFullRoute(regionB, regionA, false);
  }

  bool isDegenerated()
  {
    return fullRouteLength == physics::Distance(0.);
  }

  bool objectADrivesAlongRoute()
  {
    return headingRatingAlongRouteA > physics::Probability(0.);
  }

  bool objectBDrivesOppositeToRoute()
  {
    return headingRatingOppositeRouteB > physics::Probability(0.);
  }

  void setAFollowsB()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Following;
      resultRoute.route_a = fullRoute;
      resultRoute.route_a_length = fullRouteLength;
      resultRoute.route_a_heading_start = enuHeadingRouteA;
      resultRoute.route_a_heading_end = enuHeadingRouteB;
      resultRoute.route_b = route::FullRoute();
      resultRoute.route_b_length = physics::Distance(0.);
      resultRoute.route_b_heading_start = point::ENUHeading(0.);
      resultRoute.route_b_heading_end = point::ENUHeading(0.);
      resultRoute.heading_rating_a = headingRatingAlongRouteA;
      resultRoute.heading_rating_b = headingRatingAlongRouteB;
    }
  }

  void setBFollowsA()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Following;
      resultRoute.route_a = route::FullRoute();
      resultRoute.route_a_length = physics::Distance(0.);
      resultRoute.route_a_heading_start = point::ENUHeading(0.);
      resultRoute.route_a_heading_end = point::ENUHeading(0.);
      resultRoute.route_b = getInvertedFullRoute();
      resultRoute.route_b_length = fullRouteLength;
      resultRoute.route_b_heading_start = point::createENUHeading(enuHeadingRouteB.mENUHeading + M_PI);
      resultRoute.route_b_heading_end = point::createENUHeading(enuHeadingRouteA.mENUHeading + M_PI);
      resultRoute.heading_rating_a = headingRatingOppositeRouteA;
      resultRoute.heading_rating_b = headingRatingOppositeRouteB;
    }
  }

  void setOpposing()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Opposing;
      resultRoute.route_a = fullRoute;
      resultRoute.route_a_length = fullRouteLength;
      resultRoute.route_a_heading_start = enuHeadingRouteA;
      resultRoute.route_a_heading_end = enuHeadingRouteB;
      resultRoute.route_b = getInvertedFullRoute();
      resultRoute.route_b_length = fullRouteLength;
      resultRoute.route_b_heading_start = point::createENUHeading(enuHeadingRouteB.mENUHeading + M_PI);
      resultRoute.route_b_heading_end = point::createENUHeading(enuHeadingRouteA.mENUHeading + M_PI);
      resultRoute.heading_rating_a = headingRatingAlongRouteA;
      resultRoute.heading_rating_b = headingRatingOppositeRouteB;
    }
  }

  void setInvertedOpposing()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Opposing;
      resultRoute.route_a = getInvertedFullRoute();
      resultRoute.route_a_length = fullRouteLength;
      resultRoute.route_a_heading_start = point::createENUHeading(enuHeadingRouteB.mENUHeading + M_PI);
      resultRoute.route_a_heading_end = point::createENUHeading(enuHeadingRouteA.mENUHeading + M_PI);
      resultRoute.route_b = fullRoute;
      resultRoute.route_b_length = fullRouteLength;
      resultRoute.route_b_heading_start = enuHeadingRouteA;
      resultRoute.route_b_heading_end = enuHeadingRouteB;
      resultRoute.heading_rating_a = headingRatingOppositeRouteA;
      resultRoute.heading_rating_b = headingRatingAlongRouteB;
    }
  }

  bool isResultValid() const
  {
    return resultRoute.type != ConnectingRouteType::Invalid;
  }
};

std::string toString(::ad::map::route::planning::ConnectingRouteCandidate const &value)
{
  std::stringstream os;
  os << "ConnectingRouteCandidate("
     << " A:" << value.regionA << " routeHeading:" << value.enuHeadingRouteA
     << " objectHeading:" << value.objectA.enu_position.heading << " ratingAlong:" << value.headingRatingAlongRouteA
     << " ratingOpposite:" << value.headingRatingOppositeRouteA << " B:" << value.regionB
     << " routeHeading:" << value.enuHeadingRouteB << " objectHeading:" << value.objectB.enu_position.heading
     << " ratingAlong:" << value.headingRatingAlongRouteB << " ratingOpposite:" << value.headingRatingOppositeRouteB
     << " len:" << value.fullRouteLength << " feas:" << getHeadingFeasibility(value.resultRoute) << " "
     << value.fullRoute << " raw:" << value.rawRoute << "result: " << value.resultRoute << ")";
  return os.str();
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::planning::ConnectingRouteCandidate> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::route::planning::ConnectingRouteCandidate const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(::ad::map::route::planning::toString(value), ctx);
  }
};

namespace ad {
namespace map {
namespace route {
namespace planning {

void updateRoutePlanningCounters(route::FullRoute &route)
{
  static RoutePlanningCounter route_planning_counter = 0u;

  // post process the route counters
  route_planning_counter++;
  route.route_planning_counter = route_planning_counter;
  route.full_route_segment_count = route.road_segments.size();
  for (size_t i = 0; i < route.road_segments.size(); ++i)
  {
    route.road_segments[i].segment_count_from_destination = route.full_route_segment_count - i;
  }
}

RoutingParaPoint createRoutingPoint(lane::LaneId const &lane_id,
                                    physics::ParametricValue const &parametric_offset,
                                    RoutingDirection const &routingDirection)
{
  RoutingParaPoint routingPoint;
  routingPoint.point = point::createParaPoint(lane_id, parametric_offset);
  routingPoint.direction = routingDirection;
  return routingPoint;
}

RoutingParaPoint createRoutingPoint(point::ParaPoint const &para_point, RoutingDirection const &routingDirection)
{
  RoutingParaPoint routingPoint;
  routingPoint.point = para_point;
  routingPoint.direction = routingDirection;
  return routingPoint;
}

RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion,
                                    RoutingDirection const &routingDirection)
{
  point::ParaPoint para_point;
  para_point.lane_id = occupiedRegion.lane_id;
  // the current lane direction has no impact if the routing direction is explicitly set
  // since routing will select neighbor lanes that might have different direction to be able to expand
  if (routingDirection == RoutingDirection::POSITIVE)
  {
    para_point.parametric_offset = occupiedRegion.longitudinal_range.minimum;
  }
  else if (routingDirection == RoutingDirection::NEGATIVE)
  {
    para_point.parametric_offset = occupiedRegion.longitudinal_range.maximum;
  }
  else
  {
    // otherwise we don't know the actual routing direction and take the lane direction
    // into account
    bool const laneDirectionPositive = lane::isLaneDirectionPositive(para_point.lane_id);
    bool const routingDirectionPositive = (routingDirection != RoutingDirection::NEGATIVE);
    if (laneDirectionPositive ^ routingDirectionPositive)
    {
      // both different
      para_point.parametric_offset = occupiedRegion.longitudinal_range.maximum;
    }
    else
    {
      // both positive or both negative
      para_point.parametric_offset = occupiedRegion.longitudinal_range.minimum;
    }
  }

  return createRoutingPoint(para_point, routingDirection);
}

RoutingDirection getNominalRoutingDirection(point::ParaPoint const &para_point, point::ENUHeading const &heading)
{
  RoutingDirection routingDirection;
  if (lane::isHeadingInLaneDirection(para_point, heading))
  {
    if (lane::isLaneDirectionPositive(para_point.lane_id))
    {
      routingDirection = RoutingDirection::POSITIVE;
    }
    else
    {
      routingDirection = RoutingDirection::NEGATIVE;
    }
  }
  else
  {
    if (lane::isLaneDirectionPositive(para_point.lane_id))
    {
      routingDirection = RoutingDirection::NEGATIVE;
    }
    else
    {
      routingDirection = RoutingDirection::POSITIVE;
    }
  }
  return routingDirection;
}

RoutingParaPoint createRoutingPoint(point::ParaPoint const &para_point, point::ENUHeading const &heading)
{
  return createRoutingPoint(para_point, getNominalRoutingDirection(para_point, heading));
}

RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion, point::ENUHeading const &heading)
{
  return createRoutingPoint(occupiedRegion,
                            getNominalRoutingDirection(match::getCenterParaPoint(occupiedRegion), heading));
}

void addParaPointToRouteDestList(point::ParaPoint const &para_point, RoutingParaPointList &routingDestList)
{
  if (routingDestList.empty())
  {
    routingDestList.push_back(createRoutingPoint(para_point));
    return;
  }

  if (routingDestList.back().point.lane_id != para_point.lane_id)
  {
    routingDestList.push_back(createRoutingPoint(para_point));
    return;
  }

  // the last point in the destination list is on the same lane as the new para_point
  // in this case, we need to ensure, that the order of the points is aligned to the
  // driving direction. If this is the case, we *add* the new para_point, otherwise, we
  // *replace* the last point with the new para_point.

  auto lane = lane::getLane(para_point.lane_id);

  // positive lane direction means increasing TParam
  if (lane.direction == lane::LaneDirection::POSITIVE)
  {
    if (routingDestList.back().point.parametric_offset < para_point.parametric_offset)
    {
      routingDestList.push_back(createRoutingPoint(para_point));
      return;
    }
  }

  // negative lane direction means decreasing TParam
  if (lane.direction == lane::LaneDirection::NEGATIVE)
  {
    if (routingDestList.back().point.parametric_offset > para_point.parametric_offset)
    {
      routingDestList.push_back(createRoutingPoint(para_point));
      return;
    }
  }

  // in all other cases, we replace the last point with the new para_point
  routingDestList.back() = createRoutingPoint(para_point);
  return;
}

FullRoute createFullRoute(const planning::Route::RawRoute &rawRoute,
                          RouteCreationMode const route_creation_mode,
                          lane::LaneIdSet const &relevantLanes)
{
  FullRoute resultRoute;
  resultRoute.route_creation_mode = route_creation_mode;

  RouteLaneOffset currentLaneOffset = 0;
  for (size_t i = 0u; i < rawRoute.paraPointList.size();)
  {
    // first create a plain route containing no neighboring lanes
    const point::ParaPoint &intervalStartPoint = rawRoute.paraPointList[i];
    LaneInterval newInterval;
    newInterval.lane_id = intervalStartPoint.lane_id;
    newInterval.start = intervalStartPoint.parametric_offset;
    newInterval.end = newInterval.start;

    // search the end: the last point of the last neighbor
    int32_t laneMovesRight = 0;
    auto nextIntervalContact = lane::ContactLocation::INVALID;
    for (++i; i < rawRoute.paraPointList.size(); ++i)
    {
      nextIntervalContact = getDirectNeighborhoodRelation(newInterval.lane_id, rawRoute.paraPointList[i].lane_id);
      if ((nextIntervalContact == lane::ContactLocation::OVERLAP)
          || (nextIntervalContact == lane::ContactLocation::LEFT)
          || (nextIntervalContact == lane::ContactLocation::RIGHT))
      {
        newInterval.lane_id = rawRoute.paraPointList[i].lane_id;
        newInterval.end = rawRoute.paraPointList[i].parametric_offset;
        if (nextIntervalContact == lane::ContactLocation::RIGHT)
        {
          laneMovesRight++;
        }
        else if (nextIntervalContact == lane::ContactLocation::LEFT)
        {
          laneMovesRight--;
        }
      }
      else
      {
        break;
      }
    }

    // determine wrong way flag
    auto newLane = lane::getLane(newInterval.lane_id);
    if ((newLane.direction != lane::LaneDirection::POSITIVE) && (newLane.direction != lane::LaneDirection::NEGATIVE))
    {
      newInterval.wrong_way = false;
    }
    else
    {
      auto physicalRouteDirection = lane::LaneDirection::NONE;
      if (newInterval.start < newInterval.end)
      {
        physicalRouteDirection = lane::LaneDirection::POSITIVE;
      }
      else if (newInterval.start > newInterval.end)
      {
        physicalRouteDirection = lane::LaneDirection::NEGATIVE;
      }
      else
      {
        // decide by the contact to the next route point
        if (nextIntervalContact == lane::ContactLocation::SUCCESSOR)
        {
          physicalRouteDirection = lane::LaneDirection::POSITIVE;
        }
        else if (nextIntervalContact == lane::ContactLocation::PREDECESSOR)
        {
          physicalRouteDirection = lane::LaneDirection::NEGATIVE;
        }
        // reached the end of the route
        // route only consists of this single degenerated segment
        else if (resultRoute.road_segments.empty())
        {
          // we actually cannot decide, the route is directionless
        }
        // reached the end of the route
        // since this is degenerated, we know which physical end of the lane we reached
        else if (intervalStartPoint.parametric_offset == physics::ParametricValue(0.))
        {
          // entered the lane from the beginning
          physicalRouteDirection = lane::LaneDirection::POSITIVE;
        }
        else if (intervalStartPoint.parametric_offset == physics::ParametricValue(1.))
        {
          // entered the lane from the end
          physicalRouteDirection = lane::LaneDirection::NEGATIVE;
        }
        else
        {
          // this should not happen, otherwise we jumped somehow in the middle
          // => directionless
        }
      }

      if (physicalRouteDirection == lane::LaneDirection::NONE)
      {
        // decision is made based on the lane direction difference between
        // interval start lane and this end lane
        // Since in case we changed lanes sidewards the newInterval might
        // have a different routing direction than the intervalStartPoint
        auto intervalStartLane = lane::getLane(intervalStartPoint.lane_id);
        newInterval.wrong_way = intervalStartLane.direction != newLane.direction;
      }
      else
      {
        newInterval.wrong_way = physicalRouteDirection != newLane.direction;
      }
    }

    // update route lane offset (has to be done after setting wrong_way flag!)
    if (laneMovesRight != 0)
    {
      bool const right_neighbor = isRouteDirectionPositive(newInterval) ^ (laneMovesRight < 0);
      for (size_t laneMoves = static_cast<size_t>(std::abs(laneMovesRight)); laneMoves > 0u; laneMoves--)
      {
        updateRouteLaneOffset(right_neighbor, currentLaneOffset, resultRoute);
      }
    }

    // add the new interval
    appendRoadSegmentToRoute(newInterval, currentLaneOffset, resultRoute, relevantLanes);
  }
  resultRoute.destination_lane_offset = currentLaneOffset;

  updateRoutePlanningCounters(resultRoute);

  if (!rawRoute.paraPointList.empty())
  {
    // ensure the route starting points are aligned
    alignRouteStartingPoints(rawRoute.paraPointList.front(), resultRoute);
    alignRouteEndingPoints(rawRoute.paraPointList.back(), resultRoute);
  }

  access::getLogger()->trace("createFullRoute result {}", resultRoute);
  return resultRoute;
}

FullRoute planRoute(const RoutingParaPoint &routingStart,
                    const RoutingParaPoint &routingDest,
                    RouteCreationMode const route_creation_mode)
{
  RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST);
  planning::Route::RawRoute rawRoute;
  if (routePlanning.calculate())
  {
    rawRoute = routePlanning.getRawRoute();
  }
  return createFullRoute(rawRoute, route_creation_mode, {});
}

FullRoute planRoute(const match::MapMatchedPositionConfidenceList &mapMatchingResults,
                    const RoutingParaPoint &routingStart,
                    RouteCreationMode const route_creation_mode)
{
  FullRoute resultRoute;
  physics::Distance resultDistance = std::numeric_limits<physics::Distance>::max();
  for (const auto &mapMatchingResult : mapMatchingResults)
  {
    FullRoute route
      = planRoute(routingStart, createRoutingPoint(mapMatchingResult.lane_point.para_point), route_creation_mode);
    physics::Distance const routeDistance = calcLength(route);
    if (routeDistance < resultDistance)
    {
      resultDistance = routeDistance;
      resultRoute = route;
    }
  }
  return resultRoute;
}

template <typename T>
FullRoute
planRoutePoint(const RoutingParaPoint &routingStart, const T &dest, RouteCreationMode const route_creation_mode)
{
  match::AdMapMatching mapMatching;
  auto mapMatchingResults = mapMatching.getMapMatchedPositions(dest, physics::Distance(1.), physics::Probability(.05));

  return planRoute(mapMatchingResults, routingStart, route_creation_mode);
}

FullRoute planRoute(const RoutingParaPoint &routingStart,
                    const point::GeoPoint &dest,
                    RouteCreationMode const route_creation_mode)
{
  return planRoutePoint(routingStart, dest, route_creation_mode);
}

FullRoute planRoute(const RoutingParaPoint &routingStart,
                    const point::ENUPoint &dest,
                    RouteCreationMode const route_creation_mode)
{
  return planRoutePoint(routingStart, dest, route_creation_mode);
}

template <typename T>
FullRoute
planRouteVector(const RoutingParaPoint &start, const std::vector<T> &dest, RouteCreationMode const route_creation_mode)
{
  match::AdMapMatching mapMatching;
  RoutingParaPointList routingDestList;
  for (auto destIter = dest.begin(); destIter != dest.end(); destIter++)
  {
    auto mapMatchingResultsRaw
      = mapMatching.getMapMatchedPositions(*destIter, physics::Distance(1.), physics::Probability(.05));

    match::MapMatchedPositionConfidenceList inLaneMatches;
    for (auto const &mapMatchingResult : mapMatchingResultsRaw)
    {
      if (match::isActualWithinLaneMatch(mapMatchingResult))
      {
        inLaneMatches.push_back(mapMatchingResult);
      }
    }

    if ((destIter + 1) == dest.end())
    {
      if (inLaneMatches.size() >= 1u)
      {
        addParaPointToRouteDestList(inLaneMatches[0].lane_point.para_point, routingDestList);
      }
      else
      {
        access::getLogger()->error("planRoute failed to locate final destination in the map {}", *destIter);
        return FullRoute();
      }
    }
    else if (inLaneMatches.size() == 1u)
    {
      addParaPointToRouteDestList(inLaneMatches[0].lane_point.para_point, routingDestList);
    }
    else if (inLaneMatches.size() == 0u)
    {
      access::getLogger()->trace("planRoute ignoring intermediate point not located in the map {}", *destIter);
    }
    else
    {
      access::getLogger()->trace("planRoute ignoring ambiguous intermediate point {}", *destIter);
    }
  }
  return planRoute(start, routingDestList, route_creation_mode);
}

FullRoute
planRoute(const RoutingParaPoint &start, const point::GeoPointList &dest, RouteCreationMode const route_creation_mode)
{
  return planRouteVector(start, dest, route_creation_mode);
}

FullRoute
planRoute(const RoutingParaPoint &start, const point::ENUPointList &dest, RouteCreationMode const route_creation_mode)
{
  return planRouteVector(start, dest, route_creation_mode);
}

FullRoute
planRoute(const RoutingParaPoint &start, RoutingParaPointList const &dest, RouteCreationMode const route_creation_mode)
{
  auto routingStart = start;
  planning::Route::RawRoute mergedRawRoute;
  for (auto &routingDest : dest)
  {
    RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST);
    if (routePlanning.calculate())
    {
      auto rawRoute = routePlanning.getRawRoute();
      mergedRawRoute.paraPointList.insert(
        mergedRawRoute.paraPointList.end(), rawRoute.paraPointList.begin(), rawRoute.paraPointList.end());
      mergedRawRoute.routeDistance += rawRoute.routeDistance;
      mergedRawRoute.routeDuration += rawRoute.routeDuration;
      routingStart = routePlanning.getRoutingDest();
    }
    else
    {
      access::getLogger()->debug(
        "planRoute failed to calculate route between {} and destintation point {}: ignore destination",
        routingStart.point,
        routingDest.point);
    }
  }
  return createFullRoute(mergedRawRoute, route_creation_mode, {});
}

std::string toString(::ad::map::route::planning::CompareRouteResult const e)
{
  switch (e)
  {
    case CompareRouteResult::Equal:
      return "CompareRouteResult::Equal";
    case CompareRouteResult::Shorter:
      return "CompareRouteResult::Shorter";
    case CompareRouteResult::Longer:
      return "CompareRouteResult::Longer";
    case CompareRouteResult::Differ:
      return "CompareRouteResult::Differ";
    default:
      return "CompareRouteResult::out-of-range";
  }
}

enum class CheckMode
{
  Start,
  MiddleAfterStart,
  Middle,
  EndAfterStart,
  End,
};

CompareRouteResult
compareRoadSegmentOnIntervalLevelOrdered(RoadSegment const &left, RoadSegment const &right, CheckMode checkMode)
{
  CompareRouteResult equalResult = CompareRouteResult::Equal;
  if (left.drivable_lane_segments.size() == right.drivable_lane_segments.size())
  {
    for (std::size_t j = 0u; j < left.drivable_lane_segments.size(); j++)
    {
      if (left.drivable_lane_segments[j].lane_interval.lane_id != right.drivable_lane_segments[j].lane_interval.lane_id)
      {
        return CompareRouteResult::Differ;
      }

      // don't re-check for start equality directly after start
      if ((checkMode != CheckMode::MiddleAfterStart) && (checkMode != CheckMode::EndAfterStart))
      {
        bool const startEqual
          = left.drivable_lane_segments[j].lane_interval.start == right.drivable_lane_segments[j].lane_interval.start;

        if (!startEqual)
        {
          if (checkMode != CheckMode::Start)
          {
            return CompareRouteResult::Differ;
          }
          else if (isBeforeInterval(left.drivable_lane_segments[j].lane_interval,
                                    right.drivable_lane_segments[j].lane_interval.start))
          {
            equalResult = CompareRouteResult::Shorter;
          }
          else
          {
            equalResult = CompareRouteResult::Longer;
          }
        }
      }

      // don't check for end equality while searching for start
      if (checkMode != CheckMode::Start)
      {
        bool const endEqual
          = left.drivable_lane_segments[j].lane_interval.end == right.drivable_lane_segments[j].lane_interval.end;
        if (!endEqual)
        {
          if ((checkMode != CheckMode::End) && (checkMode != CheckMode::EndAfterStart))
          {
            return CompareRouteResult::Differ;
          }
          else if (isAfterInterval(left.drivable_lane_segments[j].lane_interval,
                                   right.drivable_lane_segments[j].lane_interval.end))
          {
            equalResult = CompareRouteResult::Shorter;
          }
          else
          {
            equalResult = CompareRouteResult::Longer;
          }
        }
      }
    }
  }
  else
  {
    return CompareRouteResult::Differ;
  }
  return equalResult;
}

CompareRouteResult compareRoutesOnIntervalLevel(FullRoute const &left, FullRoute const &right)
{
  FullRoute const *smallRoute;
  FullRoute const *largeRoute;
  CompareRouteResult equalResult;
  if (left.road_segments.size() < right.road_segments.size())
  {
    smallRoute = &left;
    largeRoute = &right;
    equalResult = CompareRouteResult::Shorter;
  }
  else if (left.road_segments.size() > right.road_segments.size())
  {
    smallRoute = &right;
    largeRoute = &left;
    equalResult = CompareRouteResult::Longer;
  }
  else
  {
    smallRoute = &left;
    largeRoute = &right;
    equalResult = CompareRouteResult::Equal;
  }

  // handle empty routes
  if (smallRoute->road_segments.size() == 0u)
  {
    if (largeRoute->road_segments.size() == 0u)
    {
      return CompareRouteResult::Equal;
    }
    else
    {
      return CompareRouteResult::Differ;
    }
  }

  std::size_t largeRouteIndexOffset = 0u;
  std::size_t const maxIndexOffset = largeRoute->road_segments.size() - smallRoute->road_segments.size();
  std::size_t smallRouteIndex = 0u;
  auto checkMode{CheckMode::Start};
  // search for comparison begin
  for (; largeRouteIndexOffset <= maxIndexOffset; largeRouteIndexOffset++)
  {
    auto const compareSegmentResult = compareRoadSegmentOnIntervalLevelOrdered(
      smallRoute->road_segments[smallRouteIndex], largeRoute->road_segments[largeRouteIndexOffset], checkMode);
    if (compareSegmentResult != CompareRouteResult::Differ)
    {
      if (equalResult == CompareRouteResult::Equal)
      {
        equalResult = compareSegmentResult;
      }
      else if (compareSegmentResult == CompareRouteResult::Longer)
      {
        // small route is longer!
        return CompareRouteResult::Differ;
      }
      break;
    }
  }
  // no identical start segment found
  if (largeRouteIndexOffset > maxIndexOffset)
  {
    return CompareRouteResult::Differ;
  }

  // search for equality over the whole shorter route

  // since we checked the start for the current segment already, we check with MiddleAfterStart mode first
  checkMode = CheckMode::MiddleAfterStart;
  for (; smallRouteIndex < smallRoute->road_segments.size(); smallRouteIndex++)
  {
    std::size_t const largeRouteIndex = smallRouteIndex + largeRouteIndexOffset;
    if (smallRouteIndex + 1u == smallRoute->road_segments.size())
    {
      if (checkMode == CheckMode::MiddleAfterStart)
      {
        checkMode = CheckMode::EndAfterStart;
      }
      else
      {
        checkMode = CheckMode::End;
      }
    }

    auto const compareSegmentResult = compareRoadSegmentOnIntervalLevelOrdered(
      smallRoute->road_segments[smallRouteIndex], largeRoute->road_segments[largeRouteIndex], checkMode);

    if (compareSegmentResult != CompareRouteResult::Equal)
    {
      if ((checkMode != CheckMode::End) && (checkMode != CheckMode::EndAfterStart))
      {
        return CompareRouteResult::Differ;
      }

      // last segment allowed to be shorter
      if (equalResult == CompareRouteResult::Equal)
      {
        equalResult = compareSegmentResult;
      }
      else if (compareSegmentResult == CompareRouteResult::Longer)
      {
        // small route is longer!
        return CompareRouteResult::Differ;
      }
    }
    // next rounds we use Middle
    checkMode = CheckMode::Middle;
  }

  return equalResult;
}

FullRouteList filterDuplicatedRoutes(const FullRouteList fullRoutes, FilterDuplicatesMode const filterMode)
{
  FullRouteList filteredRoutes;
  if (filterMode == FilterDuplicatesMode::Off)
  {
    filteredRoutes = fullRoutes;
  }
  else
  {
    for (auto const &route : fullRoutes)
    {
      bool addRoute = true;
      for (auto &filteredRoute : filteredRoutes)
      {
        // - if both are the same the new one is not added
        // - if one of the routes is a real sub-route of the other the filteringMode decides which to take
        // - otherwise, both are disjunct and the new one might be added to the filtered list
        auto comparisonResult = compareRoutesOnIntervalLevel(route, filteredRoute);
        if (((filterMode == FilterDuplicatesMode::OnlyEqual) && (comparisonResult == CompareRouteResult::Equal))
            || ((filterMode != FilterDuplicatesMode::OnlyEqual) && (comparisonResult != CompareRouteResult::Differ)))
        {
          addRoute = false;
          if ((filterMode == FilterDuplicatesMode::SubRoutesPreferShorterOnes)
              && (comparisonResult == CompareRouteResult::Shorter))
          {
            // the new route is shorter, and so overwrites the current filtered one
            access::getLogger()->trace(
              "filterDuplicatedRoutes: replacing route by shorter one {} -> {}", filteredRoute, route);
            filteredRoute = route;
          }
          else if ((filterMode == FilterDuplicatesMode::SubRoutesPreferLongerOnes)
                   && (comparisonResult == CompareRouteResult::Longer))
          {
            // the new route is longer, and so overwrites the current filtered one
            access::getLogger()->trace(
              "filterDuplicatedRoutes: replacing route by longer one {} -> {}", filteredRoute, route);
            filteredRoute = route;
          }
          else
          {
            // the new route is either identical or doesn't match the desired filter mode
            // it is just skipped
            access::getLogger()->trace("filterDuplicatedRoutes: skipping {} route {}", comparisonResult, route);
          }
          // stop the inner loop on filteredRoutes
          break;
        }
      }
      // new route differs to all filtered ones, so we have to add it
      if (addRoute)
      {
        access::getLogger()->trace("filterDuplicatedRoutes: adding route {}", route);
        filteredRoutes.push_back(route);
      }
    }
  }
  return filteredRoutes;
}

FullRouteList predictRoutesInternal(const RoutingParaPoint &start,
                                    physics::Distance const &predictionDistance,
                                    physics::Duration const &predictionDuration,
                                    RouteCreationMode const route_creation_mode,
                                    FilterDuplicatesMode const filterMode,
                                    ::ad::map::lane::LaneIdSet const &relevantLanes,
                                    Route::Type const routingTyp)
{
  FullRouteList resultRoutes;
  RoutePrediction routePrediction(start, predictionDistance, predictionDuration, routingTyp);
  routePrediction.setRelevantLanes(relevantLanes);
  if (routePrediction.calculate())
  {
    for (auto &rawRoute : routePrediction.getRawRoutes())
    {
      resultRoutes.push_back(createFullRoute(rawRoute, route_creation_mode, relevantLanes));
    }
  }
  return filterDuplicatedRoutes(resultRoutes, filterMode);
}

FullRouteList predictRoutes(const RoutingParaPoint &start,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const route_creation_mode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutesInternal(start,
                               predictionDistance,
                               predictionDuration,
                               route_creation_mode,
                               filterMode,
                               relevantLanes,
                               Route::Type::SHORTEST);
}

route::FullRouteList predictRoutesDirectionless(const point::ParaPoint &start,
                                                physics::Distance const &predictionDistance,
                                                physics::Duration const &predictionDuration,
                                                RouteCreationMode const route_creation_mode,
                                                FilterDuplicatesMode const filterMode,
                                                ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutesInternal(createRoutingParaPoint(start.lane_id, start.parametric_offset),
                               predictionDistance,
                               predictionDuration,
                               route_creation_mode,
                               filterMode,
                               relevantLanes,
                               Route::Type::SHORTEST_IGNORE_DIRECTION);
}

FullRouteList predictRoutes(const match::MapMatchedObjectBoundingBox &startObject,
                            const point::ENUHeading enuHeading,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const route_creation_mode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  FullRouteList resultRoutes;
  for (auto const &startMatchingResult : startObject.lane_occupied_regions)
  {
    auto const routingStart = createRoutingPoint(startMatchingResult, enuHeading);
    auto const routes = predictRoutes(routingStart,
                                      predictionDistance,
                                      predictionDuration,
                                      route_creation_mode,
                                      FilterDuplicatesMode::Off,
                                      relevantLanes);
    resultRoutes.insert(resultRoutes.end(), routes.begin(), routes.end());
  }
  return filterDuplicatedRoutes(resultRoutes, filterMode);
}

FullRouteList predictRoutes(const match::Object &startObject,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const route_creation_mode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(startObject.map_matched_bounding_box,
                       startObject.enu_position.heading,
                       predictionDistance,
                       predictionDuration,
                       route_creation_mode,
                       filterMode,
                       relevantLanes);
}

FullRouteList predictRoutes(const match::MapMatchedObjectBoundingBox &startObject,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const route_creation_mode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  auto const enuHeading = match::getObjectENUHeading(startObject);
  return predictRoutes(
    startObject, enuHeading, predictionDistance, predictionDuration, route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesDirectionless(const match::MapMatchedObjectBoundingBox &startObject,
                                         physics::Distance const &predictionDistance,
                                         physics::Duration const &predictionDuration,
                                         RouteCreationMode const route_creation_mode,
                                         FilterDuplicatesMode const filterMode,
                                         ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  FullRouteList resultRoutes;
  for (auto const &startMatchingResult : startObject.lane_occupied_regions)
  {
    auto const routingStart = createRoutingPoint(startMatchingResult, RoutingDirection::DONT_CARE);
    auto const routes = predictRoutesInternal(routingStart,
                                              predictionDistance,
                                              predictionDuration,
                                              route_creation_mode,
                                              FilterDuplicatesMode::Off,
                                              relevantLanes,
                                              Route::Type::SHORTEST_IGNORE_DIRECTION);
    resultRoutes.insert(resultRoutes.end(), routes.begin(), routes.end());
  }
  return filterDuplicatedRoutes(resultRoutes, filterMode);
}

FullRouteList predictRoutesDirectionless(const match::Object &startObject,
                                         physics::Distance const &predictionDistance,
                                         physics::Duration const &predictionDuration,
                                         RouteCreationMode const route_creation_mode,
                                         FilterDuplicatesMode const filterMode,
                                         ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutesDirectionless(startObject.map_matched_bounding_box,
                                    predictionDistance,
                                    predictionDuration,
                                    route_creation_mode,
                                    filterMode,
                                    relevantLanes);
}

FullRouteList predictRoutesOnDuration(const RoutingParaPoint &start,
                                      physics::Duration const &predictionDuration,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    start, physics::Distance::getMax(), predictionDuration, route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDuration(const match::MapMatchedObjectBoundingBox &startObject,
                                      physics::Duration const &predictionDuration,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, physics::Distance::getMax(), predictionDuration, route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDuration(const match::Object &startObject,
                                      physics::Duration const &predictionDuration,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, physics::Distance::getMax(), predictionDuration, route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDistance(const RoutingParaPoint &start,
                                      physics::Distance const &predictionDistance,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    start, predictionDistance, physics::Duration::getMax(), route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDistance(const match::MapMatchedObjectBoundingBox &startObject,
                                      physics::Distance const &predictionDistance,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, predictionDistance, physics::Duration::getMax(), route_creation_mode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDistance(const match::Object &startObject,
                                      physics::Distance const &predictionDistance,
                                      RouteCreationMode const route_creation_mode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, predictionDistance, physics::Duration::getMax(), route_creation_mode, filterMode, relevantLanes);
}

point::ENUHeading
dropStartRegion(match::LaneOccupiedRegion const &regionDropStart, FullRoute &route, bool const calculateENUHeading)
{
  point::ENUHeading resultHeading;
  // drop the lane regions which led to the creation of the route as start
  // and calculate the heading of the lanes in the region
  for (auto &laneSegment : route.road_segments.front().drivable_lane_segments)
  {
    if (laneSegment.lane_interval.lane_id == regionDropStart.lane_id)
    {
      bool alignmentRequired = false;
      if (isWithinInterval(laneSegment.lane_interval, regionDropStart.longitudinal_range.minimum))
      {
        if (laneSegment.lane_interval.start != regionDropStart.longitudinal_range.minimum)
        {
          laneSegment.lane_interval.start = regionDropStart.longitudinal_range.minimum;
          alignmentRequired = true;
        }
      }
      if (isWithinInterval(laneSegment.lane_interval, regionDropStart.longitudinal_range.maximum))
      {
        if (laneSegment.lane_interval.start != regionDropStart.longitudinal_range.maximum)
        {
          laneSegment.lane_interval.start = regionDropStart.longitudinal_range.maximum;
          alignmentRequired = true;
        }
      }
      if (alignmentRequired)
      {
        alignRouteStartingPoints(getIntervalStart(laneSegment.lane_interval), route);
      }

      if (calculateENUHeading)
      {
        resultHeading = lane::getLaneENUHeading(route::getIntervalStart(laneSegment.lane_interval));
        if (laneSegment.lane_interval.wrong_way)
        {
          // on a wrong way segment, we have to turn the lane heading in route direction
          resultHeading = point::createENUHeading(resultHeading.mENUHeading + M_PI);
        }
      }
      break;
    }
  }
  return resultHeading;
}

point::ENUHeading
dropEndRegion(match::LaneOccupiedRegion const &regionDropEnd, FullRoute &route, bool const calculateENUHeading)
{
  point::ENUHeading resultHeading;
  // drop the lane regions which led to the creation of the route as destination
  // and calculate the heading of the lanes in the region
  for (auto &laneSegment : route.road_segments.back().drivable_lane_segments)
  {
    if (laneSegment.lane_interval.lane_id == regionDropEnd.lane_id)
    {
      bool alignmentRequired = false;
      if (isWithinInterval(laneSegment.lane_interval, regionDropEnd.longitudinal_range.minimum))
      {
        if (laneSegment.lane_interval.end != regionDropEnd.longitudinal_range.minimum)
        {
          laneSegment.lane_interval.end = regionDropEnd.longitudinal_range.minimum;
          alignmentRequired = true;
        }
      }
      if (isWithinInterval(laneSegment.lane_interval, regionDropEnd.longitudinal_range.maximum))
      {
        if (laneSegment.lane_interval.end != regionDropEnd.longitudinal_range.maximum)
        {
          laneSegment.lane_interval.end = regionDropEnd.longitudinal_range.maximum;
          alignmentRequired = true;
        }
      }
      if (alignmentRequired)
      {
        alignRouteEndingPoints(getIntervalEnd(laneSegment.lane_interval), route);
      }
      if (calculateENUHeading)
      {
        resultHeading = lane::getLaneENUHeading(route::getIntervalEnd(laneSegment.lane_interval));
        if (laneSegment.lane_interval.wrong_way)
        {
          // on a wrong way segment, we have to turn the lane heading in route direction
          resultHeading = point::createENUHeading(resultHeading.mENUHeading + M_PI);
        }
      }
      break;
    }
  }
  return resultHeading;
}

point::ENUHeading dropStartRegion(const match::Object &object, FullRoute &route)
{
  for (auto const &laneSegment : route.road_segments.front().drivable_lane_segments)
  {
    if (laneSegment.route_lane_offset == 0)
    {
      for (auto const &startRegion : object.map_matched_bounding_box.lane_occupied_regions)
      {
        if (startRegion.lane_id == laneSegment.lane_interval.lane_id)
        {
          return dropStartRegion(startRegion, route, true);
        }
      }
    }
  }
  return point::ENUHeading();
}

physics::Probability createHeadingRating(point::ENUHeading const &routeHeading,
                                         point::ENUHeading const &objectHeading,
                                         double objectHeadingOffset)
{
  if ((!routeHeading.isValid()) || (!objectHeading.isValid()))
  {
    return physics::Probability(0.);
  }
  auto routeHeadingD = routeHeading.mENUHeading;
  auto objectHeadingD = objectHeading.mENUHeading + objectHeadingOffset;

  auto const headingDifference
    = std::fabs(physics::normalizeAngleSigned(physics::Angle(routeHeadingD - objectHeadingD)));

  if (headingDifference > physics::cPI_2)
  {
    return physics::Probability(0.);
  }
  return physics::Probability(1. - 2. * headingDifference / physics::cPI);
}

struct MergingRouteSearch
{
  MergingRouteSearch(match::Object const &objectA,
                     route::FullRoute &objectARoute,
                     match::Object const &objectB,
                     route::FullRoute &objectBRoute)
    : iterA(objectA, objectARoute)
    , iterB(objectB, objectBRoute)
  {
  }

  ConnectingRoute checkForMergingConnectingRoute();

  struct ObjectRouteIterator
  {
    ObjectRouteIterator(match::Object const &objectIn, route::FullRoute &routeIn)
      : object(objectIn)
      , route(routeIn)
    {
      roadSegmentIter = route.road_segments.begin();
    }

    physics::Distance distanceCovered() const
    {
      return routeDistanceCovered;
    }
    bool isValid() const
    {
      return roadSegmentIter != route.road_segments.end();
    }
    void step(ObjectRouteIterator &other);
    void cutOffRouteAfterMerge(route::RoadSegmentList::iterator const &cutRoadSegmentIter,
                               point::ParaPoint const &laneCutPoint);

    const match::Object &object;
    route::FullRoute &route;
    route::RoadSegmentList::iterator roadSegmentIter;
    physics::Distance routeDistanceCovered{0.};
    point::ENUHeading laneHeadingAtCut;
    bool cutPerformed{false};
  };

  ObjectRouteIterator iterA;
  ObjectRouteIterator iterB;
};

void MergingRouteSearch::ObjectRouteIterator::step(ObjectRouteIterator &other)
{
  if (roadSegmentIter != route.road_segments.end())
  {
    routeDistanceCovered += calcLength(*roadSegmentIter);

    for (auto otherIter = other.roadSegmentIter; otherIter != other.route.road_segments.end(); otherIter++)
    {
      for (auto otherSegmentIter = otherIter->drivable_lane_segments.begin();
           otherSegmentIter != otherIter->drivable_lane_segments.end();
           ++otherSegmentIter)
      {
        for (auto ownSegmentIter = roadSegmentIter->drivable_lane_segments.begin();
             ownSegmentIter != roadSegmentIter->drivable_lane_segments.end();
             ++ownSegmentIter)
        {
          if (overlapsInterval(ownSegmentIter->lane_interval, otherSegmentIter->lane_interval))
          {
            // found a common lane interval

            // calculate the exact cutting position of both routes
            auto const ownParametricRange = toParametricRange(ownSegmentIter->lane_interval);
            auto const otherParametricRange = toParametricRange(otherSegmentIter->lane_interval);
            auto const intersectingRange = getIntersectionRange(ownParametricRange, otherParametricRange);
            point::ParaPoint cutPoint;
            cutPoint.lane_id = ownSegmentIter->lane_interval.lane_id;
            if (isRouteDirectionPositive(ownSegmentIter->lane_interval))
            {
              cutPoint.parametric_offset = intersectingRange.minimum;
            }
            else
            {
              cutPoint.parametric_offset = intersectingRange.maximum;
            }
            cutOffRouteAfterMerge(roadSegmentIter, cutPoint);

            if (isRouteDirectionPositive(otherSegmentIter->lane_interval))
            {
              cutPoint.parametric_offset = intersectingRange.minimum;
            }
            else
            {
              cutPoint.parametric_offset = intersectingRange.maximum;
            }
            other.cutOffRouteAfterMerge(otherIter, cutPoint);
            return;
          }
        }
      }
    }

    roadSegmentIter++;
  }
}

void MergingRouteSearch::ObjectRouteIterator::cutOffRouteAfterMerge(
  route::RoadSegmentList::iterator const &cutRoadSegmentIter, point::ParaPoint const &laneCutPoint)
{
  roadSegmentIter = cutRoadSegmentIter;
  for (route::LaneSegmentList::iterator laneSegmentIter = roadSegmentIter->drivable_lane_segments.begin();
       laneSegmentIter != roadSegmentIter->drivable_lane_segments.end();
       ++laneSegmentIter)
  {
    laneSegmentIter->lane_interval.end = laneCutPoint.parametric_offset;
    laneSegmentIter->successors.clear();

    if (laneSegmentIter->lane_interval.lane_id == laneCutPoint.lane_id)
    {
      laneHeadingAtCut = lane::getLaneENUHeading(laneCutPoint);
      if (laneSegmentIter->lane_interval.wrong_way)
      {
        // on a wrong way segment, we have to turn the lane heading in route direction
        laneHeadingAtCut = point::createENUHeading(laneHeadingAtCut.mENUHeading + M_PI);
      }
    }
  }
  roadSegmentIter++;
  roadSegmentIter = route.road_segments.erase(roadSegmentIter, route.road_segments.end());
  cutPerformed = true;
}

ConnectingRoute MergingRouteSearch::checkForMergingConnectingRoute()
{
  do
  {
    // we want to find the shortest connecting route
    // therefore, increment the roadSegmentIter of the route with less distance covered
    if (iterA.distanceCovered() <= iterB.distanceCovered())
    {
      iterA.step(iterB);
    }
    else
    {
      iterB.step(iterA);
    }
  } while (iterA.isValid() && iterB.isValid());

  ConnectingRoute resultRoute;
  if (iterA.cutPerformed && iterB.cutPerformed)
  {
    resultRoute.type = ConnectingRouteType::Merging;

    point::ENUHeading const objectARouteHeading = dropStartRegion(iterA.object, iterA.route);
    resultRoute.route_a = iterA.route;
    resultRoute.route_a_length = calcLength(iterA.route);
    resultRoute.route_a_heading_start = objectARouteHeading;
    resultRoute.route_a_heading_end = iterA.laneHeadingAtCut;
    resultRoute.heading_rating_a = createHeadingRating(objectARouteHeading, iterA.object.enu_position.heading);

    point::ENUHeading const objectBRouteHeading = dropStartRegion(iterB.object, iterB.route);
    resultRoute.route_b = iterB.route;
    resultRoute.route_b_length = calcLength(iterB.route);
    resultRoute.route_b_heading_start = objectBRouteHeading;
    resultRoute.route_b_heading_end = iterB.laneHeadingAtCut;
    resultRoute.heading_rating_b = createHeadingRating(objectBRouteHeading, iterB.object.enu_position.heading);
  }
  else
  {
    resultRoute.type = ConnectingRouteType::Invalid;
  }

  return resultRoute;
}

void filterDuplicatedConnectingRoutes(std::list<ConnectingRouteCandidate> &connectingRouteCandidates)
{
  std::list<ConnectingRouteCandidate> filteredCandidates;
  for (auto &connectingRoute : connectingRouteCandidates)
  {
    bool addRoute = true;
    for (auto &filteredConnectingRoute : filteredCandidates)
    {
      // - if both are the same the new one is not added
      // - if one of the routes is a real sub-route of the other the filteringMode decides which to take
      // - otherwise, both are disjunct and the new one might be added to the filtered list
      auto comparisonResult
        = compareRoutesOnIntervalLevel(connectingRoute.fullRoute, filteredConnectingRoute.fullRoute);
      if (comparisonResult != CompareRouteResult::Differ)
      {
        addRoute = false;
        if (comparisonResult == CompareRouteResult::Shorter)
        {
          // the new route is shorter, and so overwrites the current filtered one
          access::getLogger()->trace(
            "filterDuplicatedConnectingRoutes: replacing connectingRoute by shorter one {} -> {}",
            filteredConnectingRoute,
            connectingRoute);
          filteredConnectingRoute = std::move(connectingRoute);
        }
        else
        {
          // the new route is not shorter
          // it is just skipped
          access::getLogger()->trace(
            "filterDuplicatedConnectingRoutes: skipping {} connectingRoute {}", comparisonResult, connectingRoute);
        }
        // stop the inner loop on filteredCandidates
        break;
      }
    }
    // new route differs to all filtered ones, so we have to add it
    if (addRoute)
    {
      access::getLogger()->trace("filterDuplicatedConnectingRoutes: adding connectingRoute {}", connectingRoute);
      filteredCandidates.push_back(std::move(connectingRoute));
    }
  }
  connectingRouteCandidates.swap(filteredCandidates);
}

bool compareCandidateRawRoutes(ConnectingRouteCandidate const &left, ConnectingRouteCandidate const &right)
{
  if ((left.rawRoute.routeDistance < right.rawRoute.routeDistance)
      || ((left.rawRoute.routeDistance == right.rawRoute.routeDistance)
          && (left.rawRoute.paraPointList.size() < right.rawRoute.paraPointList.size())))
  {
    return true;
  }
  return false;
}

bool compareCandidateFeasibility(ConnectingRouteCandidate const &left, ConnectingRouteCandidate const &right)
{
  // we want to sort descending
  return getHeadingFeasibility(left.resultRoute) > getHeadingFeasibility(right.resultRoute);
}

FullRoute ConnectingRouteCandidate::calculateFullRoute(match::LaneOccupiedRegion const &regionDropStart,
                                                       match::LaneOccupiedRegion const &regionDropEnd,
                                                       bool const updateHeading)
{
  auto route = createFullRoute(rawRoute, RouteCreationMode::AllRoutableLanes, relevantLanes);

  if (!route.road_segments.empty())
  {
    auto heading = dropStartRegion(regionDropStart, route, updateHeading);
    if (updateHeading)
    {
      enuHeadingRouteA = heading;
    }
    heading = dropEndRegion(regionDropEnd, route, updateHeading);
    if (updateHeading)
    {
      enuHeadingRouteB = heading;
    }
  }

  return route;
}

route::ConnectingRouteList calculateConnectingRoutes(const match::Object &objectA,
                                                     const match::Object &objectB,
                                                     physics::Distance const &maxDistance,
                                                     physics::Duration const &maxDuration,
                                                     route::FullRouteList const &objectAPredictionHints,
                                                     route::FullRouteList const &objectBPredictionHints,
                                                     lane::LaneIdSet const &relevantLanes)
{
  route::ConnectingRouteList resultRoutes;
  std::list<ConnectingRouteCandidate> connectingRouteCandidates;
  for (auto const &startMatchingResult : objectA.map_matched_bounding_box.lane_occupied_regions)
  {
    if (!isLaneRelevantForExpansion(startMatchingResult.lane_id, relevantLanes))
    {
      continue;
    }
    auto const routingStart = createRoutingPoint(startMatchingResult);
    for (auto const &destMatchingResult : objectB.map_matched_bounding_box.lane_occupied_regions)
    {
      if (!isLaneRelevantForExpansion(destMatchingResult.lane_id, relevantLanes))
      {
        continue;
      }
      auto const routingDest = createRoutingPoint(destMatchingResult);

      RouteAstar routePlanning(
        routingStart, routingDest, maxDistance, maxDuration, Route::Type::SHORTEST_IGNORE_DIRECTION);
      routePlanning.setRelevantLanes(relevantLanes);
      if (routePlanning.calculate())
      {
        auto rawRoute = routePlanning.getRawRoute();
        connectingRouteCandidates.push_back(
          ConnectingRouteCandidate(objectA, objectB, rawRoute, startMatchingResult, destMatchingResult, relevantLanes));
      }
    }
  }

  access::getLogger()->trace("calculateConnectingRoute[]: created {} candidates for {} <-> {} max_d:{} max_t:{}",
                             connectingRouteCandidates.size(),
                             objectA,
                             objectB,
                             maxDistance,
                             maxDuration);
  if (connectingRouteCandidates.size() > 0u)
  {
    for (auto candidateIter = connectingRouteCandidates.begin(); candidateIter != connectingRouteCandidates.end();)
    {
      // create the full routes
      candidateIter->createFullRouteAndRating();

      access::getLogger()->trace("calculateConnectingRoute: analyze {}", *candidateIter);

      // special handling for degenerated routes upfront
      if (candidateIter->isDegenerated())
      {
        if (candidateIter->rawRoute.paraPointList.size() == 1u)
        {
          // same lane, same point longitudinally:
          // define that A is following B
          candidateIter->setAFollowsB();
        }
        if (candidateIter->objectADrivesAlongRoute() == candidateIter->objectBDrivesOppositeToRoute())
        {
          // opposite case
          if (candidateIter->objectADrivesAlongRoute())
          {
            // both driving in positive route direction as usual
            candidateIter->setOpposing();
          }
          else
          {
            // switch the routes to have both again in proper direction
            candidateIter->setInvertedOpposing();
          }
        }
      }

      if (candidateIter->objectADrivesAlongRoute() && candidateIter->objectBDrivesOppositeToRoute())
      {
        candidateIter->setOpposing();
      }
      else if (candidateIter->objectADrivesAlongRoute())
      {
        candidateIter->setAFollowsB();
      }
      else if (candidateIter->objectBDrivesOppositeToRoute())
      {
        candidateIter->setBFollowsA();
      }
      else
      {
        // both are driving away from each other, no result here
      }

      if (!candidateIter->isResultValid())
      {
        // not valid, drop
        access::getLogger()->trace("calculateConnectingRoute: not valid, dropping. Continue... {}", *candidateIter);
        candidateIter = connectingRouteCandidates.erase(candidateIter);
      }
      else if (candidateIter->fullRouteLength > maxDistance)
      {
        // too long, drop
        // since route expansion stops after the maxDistance is reached
        // a found candidate can also be larger, depending on the length of the last segment being added.
        // We have to drop these to provide consistent results:
        //  e.g. connectingRoute(A,B) could have no candidates (and will switch in check for merging below)
        //  while connectingRoute(B,A) has one that is much longer
        // Therefore, we ignore ones that are longer than the provided maxDistance
        access::getLogger()->trace(
          "calculateConnectingRoute: candidate is longer {} than maxDistance {}, dropping. Continue... {}",
          candidateIter->fullRouteLength,
          maxDistance,
          *candidateIter);
        candidateIter = connectingRouteCandidates.erase(candidateIter);
      }
      else
      {
        // valid result
        access::getLogger()->trace("calculateConnectingRoute: valid candidate... {}", *candidateIter);
        candidateIter++;
      }
    }

    filterDuplicatedConnectingRoutes(connectingRouteCandidates);

    // Sort our candidates by feasibility
    connectingRouteCandidates.sort(compareCandidateFeasibility);

    if (connectingRouteCandidates.size() > 0u)
    {
      for (auto const &connectingRoute : connectingRouteCandidates)
      {
        access::getLogger()->trace("calculateConnectingRoute: adding result route {}", connectingRoute);
        resultRoutes.push_back(connectingRoute.resultRoute);
      }
    }
  }
  else
  {
    // no direct connecting route between the two objects found
    // check if we have a ConnectingRouteType::Merging case
    // search if one of the route lanes of A is part of one of the route lanes of B
    auto objectAPredictions = objectAPredictionHints;
    if (objectAPredictions.empty())
    {
      objectAPredictions = predictRoutes(objectA,
                                         maxDistance,
                                         maxDuration,
                                         RouteCreationMode::SameDrivingDirection,
                                         FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                                         relevantLanes);
    }
    auto objectBPredictions = objectBPredictionHints;
    if (objectBPredictions.empty())
    {
      objectBPredictions = predictRoutes(objectB,
                                         maxDistance,
                                         maxDuration,
                                         RouteCreationMode::SameDrivingDirection,
                                         FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                                         relevantLanes);
    }

    auto resultDistance = std::numeric_limits<physics::Distance>::max();
    for (auto &objectAPrediction : objectAPredictions)
    {
      for (auto &objectBPrediction : objectBPredictions)
      {
        MergingRouteSearch mergingRouteSearch(objectA, objectAPrediction, objectB, objectBPrediction);
        auto mergingRouteResult = mergingRouteSearch.checkForMergingConnectingRoute();
        if (mergingRouteResult.type == ConnectingRouteType::Merging)
        {
          if ((mergingRouteResult.route_a_length > maxDistance) || (mergingRouteResult.route_b_length > maxDistance))
          {
            // too long, drop
            // since connecting routes that are longer than the maxDistance might just have been missed by the regular
            // candidate search above longer merging routes have to be dropped (see also comment above on dropping too
            // long results)
            access::getLogger()->trace(
              "calculateConnectingRoute: merging candidate is longer {} than maxDistance {}, dropping. {}",
              std::max(mergingRouteResult.route_a_length, mergingRouteResult.route_b_length),
              maxDistance,
              mergingRouteResult);
          }
          else
          {
            auto mergeDistance = std::min(mergingRouteResult.route_a_length, mergingRouteResult.route_b_length);
            if (mergeDistance < resultDistance)
            {
              if (resultRoutes.empty())
              {
                access::getLogger()->trace("calculateConnectingRoute: merging candidate of length {} found: {}",
                                           mergeDistance,
                                           mergingRouteResult);
                resultRoutes.push_back(mergingRouteResult);
              }
              else
              {
                access::getLogger()->trace(
                  "calculateConnectingRoute: merging candidate is shorter {} than last {}, new result candidate: {}",
                  mergeDistance,
                  resultDistance,
                  mergingRouteResult);
                resultRoutes[0] = std::move(mergingRouteResult);
              }
              resultDistance = mergeDistance;
            }
          }
        }
      }
    }
  }

  if (resultRoutes.empty())
  {
    access::getLogger()->trace("calculateConnectingRoute: empty result");
  }
  else
  {
    access::getLogger()->trace("calculateConnectingRoute: {} results", resultRoutes.size());
  }
  return resultRoutes;
}

route::ConnectingRouteList calculateConnectingRoutes(const match::Object &startObject,
                                                     const match::Object &destObject,
                                                     physics::Distance const &maxDistance,
                                                     route::FullRouteList const &objectAPredictionHints,
                                                     route::FullRouteList const &objectBPredictionHints,
                                                     ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return calculateConnectingRoutes(startObject,
                                   destObject,
                                   maxDistance,
                                   std::numeric_limits<physics::Duration>::max(),
                                   objectAPredictionHints,
                                   objectBPredictionHints,
                                   relevantLanes);
}

route::ConnectingRouteList calculateConnectingRoutes(const match::Object &startObject,
                                                     const match::Object &destObject,
                                                     physics::Duration const &maxDuration,
                                                     route::FullRouteList const &objectAPredictionHints,
                                                     route::FullRouteList const &objectBPredictionHints,
                                                     ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return calculateConnectingRoutes(startObject,
                                   destObject,
                                   std::numeric_limits<physics::Distance>::max(),
                                   maxDuration,
                                   objectAPredictionHints,
                                   objectBPredictionHints,
                                   relevantLanes);
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
