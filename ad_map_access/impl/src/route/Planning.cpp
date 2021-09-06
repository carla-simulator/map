// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
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

void updateRoutePlanningCounters(route::FullRoute &route)
{
  static RoutePlanningCounter routePlanningCounter = 0u;

  // post process the route counters
  routePlanningCounter++;
  route.routePlanningCounter = routePlanningCounter;
  route.fullRouteSegmentCount = route.roadSegments.size();
  for (size_t i = 0; i < route.roadSegments.size(); ++i)
  {
    route.roadSegments[i].segmentCountFromDestination = route.fullRouteSegmentCount - i;
  }
}

RoutingParaPoint createRoutingPoint(lane::LaneId const &laneId,
                                    physics::ParametricValue const &parametricOffset,
                                    RoutingDirection const &routingDirection)
{
  RoutingParaPoint routingPoint;
  routingPoint.point = point::createParaPoint(laneId, parametricOffset);
  routingPoint.direction = routingDirection;
  return routingPoint;
}

RoutingParaPoint createRoutingPoint(point::ParaPoint const &paraPoint, RoutingDirection const &routingDirection)
{
  RoutingParaPoint routingPoint;
  routingPoint.point = paraPoint;
  routingPoint.direction = routingDirection;
  return routingPoint;
}

RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion,
                                    RoutingDirection const &routingDirection)
{
  point::ParaPoint paraPoint;
  paraPoint.laneId = occupiedRegion.laneId;
  // the current lane direction has no impact if the routing direction is explicitly set
  // since routing will select neighbor lanes that might have different direction to be able to expand
  if (routingDirection == RoutingDirection::POSITIVE)
  {
    paraPoint.parametricOffset = occupiedRegion.longitudinalRange.minimum;
  }
  else if (routingDirection == RoutingDirection::NEGATIVE)
  {
    paraPoint.parametricOffset = occupiedRegion.longitudinalRange.maximum;
  }
  else
  {
    // otherwise we don't know the actual routing direction and take the lane direction
    // into account
    bool const laneDirectionPositive = lane::isLaneDirectionPositive(paraPoint.laneId);
    bool const routingDirectionPositive = (routingDirection != RoutingDirection::NEGATIVE);
    if (laneDirectionPositive ^ routingDirectionPositive)
    {
      // both different
      paraPoint.parametricOffset = occupiedRegion.longitudinalRange.maximum;
    }
    else
    {
      // both positive or both negative
      paraPoint.parametricOffset = occupiedRegion.longitudinalRange.minimum;
    }
  }

  return createRoutingPoint(paraPoint, routingDirection);
}

RoutingDirection getNominalRoutingDirection(point::ParaPoint const &paraPoint, point::ENUHeading const &heading)
{
  RoutingDirection routingDirection;
  if (lane::isHeadingInLaneDirection(paraPoint, heading))
  {
    if (lane::isLaneDirectionPositive(paraPoint.laneId))
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
    if (lane::isLaneDirectionPositive(paraPoint.laneId))
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

RoutingParaPoint createRoutingPoint(point::ParaPoint const &paraPoint, point::ENUHeading const &heading)
{
  return createRoutingPoint(paraPoint, getNominalRoutingDirection(paraPoint, heading));
}

RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion, point::ENUHeading const &heading)
{
  return createRoutingPoint(occupiedRegion,
                            getNominalRoutingDirection(match::getCenterParaPoint(occupiedRegion), heading));
}

void addParaPointToRouteDestList(point::ParaPoint const &paraPoint, std::vector<RoutingParaPoint> &routingDestList)
{
  if (routingDestList.empty())
  {
    routingDestList.push_back(createRoutingPoint(paraPoint));
    return;
  }

  if (routingDestList.back().point.laneId != paraPoint.laneId)
  {
    routingDestList.push_back(createRoutingPoint(paraPoint));
    return;
  }

  // the last point in the destination list is on the same lane as the new paraPoint
  // in this case, we need to ensure, that the order of the points is aligned to the
  // driving direction. If this is the case, we *add* the new paraPoint, otherwise, we
  // *replace* the last point with the new paraPoint.

  auto lane = lane::getLane(paraPoint.laneId);

  // positive lane direction means increasing TParam
  if (lane.direction == lane::LaneDirection::POSITIVE)
  {
    if (routingDestList.back().point.parametricOffset < paraPoint.parametricOffset)
    {
      routingDestList.push_back(createRoutingPoint(paraPoint));
      return;
    }
  }

  // negative lane direction means decreasing TParam
  if (lane.direction == lane::LaneDirection::NEGATIVE)
  {
    if (routingDestList.back().point.parametricOffset > paraPoint.parametricOffset)
    {
      routingDestList.push_back(createRoutingPoint(paraPoint));
      return;
    }
  }

  // in all other cases, we replace the last point with the new paraPoint
  routingDestList.back() = createRoutingPoint(paraPoint);
  return;
}

FullRoute createFullRoute(const planning::Route::RawRoute &rawRoute,
                          RouteCreationMode const routeCreationMode,
                          lane::LaneIdSet const &relevantLanes)
{
  FullRoute resultRoute;
  resultRoute.routeCreationMode = routeCreationMode;

  RouteLaneOffset currentLaneOffset = 0;
  for (size_t i = 0u; i < rawRoute.paraPointList.size();)
  {
    // first create a plain route containing no neighboring lanes
    const point::ParaPoint &intervalStartPoint = rawRoute.paraPointList[i];
    LaneInterval newInterval;
    newInterval.laneId = intervalStartPoint.laneId;
    newInterval.start = intervalStartPoint.parametricOffset;
    newInterval.end = newInterval.start;

    // search the end: the last point of the last neighbor
    int32_t laneMovesRight = 0;
    auto nextIntervalContact = lane::ContactLocation::INVALID;
    for (++i; i < rawRoute.paraPointList.size(); ++i)
    {
      nextIntervalContact = getDirectNeighborhoodRelation(newInterval.laneId, rawRoute.paraPointList[i].laneId);
      if ((nextIntervalContact == lane::ContactLocation::OVERLAP)
          || (nextIntervalContact == lane::ContactLocation::LEFT)
          || (nextIntervalContact == lane::ContactLocation::RIGHT))
      {
        newInterval.laneId = rawRoute.paraPointList[i].laneId;
        newInterval.end = rawRoute.paraPointList[i].parametricOffset;
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
    auto newLane = lane::getLane(newInterval.laneId);
    if ((newLane.direction != lane::LaneDirection::POSITIVE) && (newLane.direction != lane::LaneDirection::NEGATIVE))
    {
      newInterval.wrongWay = false;
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
        else if (resultRoute.roadSegments.empty())
        {
          // we actually cannot decide, the route is directionless
        }
        // reached the end of the route
        // since this is degenerated, we know which physical end of the lane we reached
        else if (intervalStartPoint.parametricOffset == physics::ParametricValue(0.))
        {
          // entered the lane from the beginning
          physicalRouteDirection = lane::LaneDirection::POSITIVE;
        }
        else if (intervalStartPoint.parametricOffset == physics::ParametricValue(1.))
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
        auto intervalStartLane = lane::getLane(intervalStartPoint.laneId);
        newInterval.wrongWay = intervalStartLane.direction != newLane.direction;
      }
      else
      {
        newInterval.wrongWay = physicalRouteDirection != newLane.direction;
      }
    }

    // update route lane offset (has to be done after setting wrongWay flag!)
    if (laneMovesRight != 0)
    {
      bool const rightNeighbor = isRouteDirectionPositive(newInterval) ^ (laneMovesRight < 0);
      for (size_t laneMoves = static_cast<size_t>(std::abs(laneMovesRight)); laneMoves > 0u; laneMoves--)
      {
        updateRouteLaneOffset(rightNeighbor, currentLaneOffset, resultRoute);
      }
    }

    // add the new interval
    appendRoadSegmentToRoute(newInterval, currentLaneOffset, resultRoute, relevantLanes);
  }
  resultRoute.destinationLaneOffset = currentLaneOffset;

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
                    RouteCreationMode const routeCreationMode)
{
  RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST);
  planning::Route::RawRoute rawRoute;
  if (routePlanning.calculate())
  {
    rawRoute = routePlanning.getRawRoute();
  }
  return createFullRoute(rawRoute, routeCreationMode, {});
}

FullRoute planRoute(const match::MapMatchedPositionConfidenceList &mapMatchingResults,
                    const RoutingParaPoint &routingStart,
                    RouteCreationMode const routeCreationMode)
{
  FullRoute resultRoute;
  physics::Distance resultDistance = std::numeric_limits<physics::Distance>::max();

  for (const auto &mapMatchingResult : mapMatchingResults)
  {
    FullRoute route
      = planRoute(routingStart, createRoutingPoint(mapMatchingResult.lanePoint.paraPoint), routeCreationMode);

    if (route.roadSegments.size() > 0)
    {
      physics::Distance const routeDistance = calcLength(route);

      if (routeDistance < resultDistance)
      {
        resultDistance = routeDistance;
        resultRoute = route;
      }
    }
  }
  return resultRoute;
}

template <typename T>
FullRoute planRoutePoint(const RoutingParaPoint &routingStart, const T &dest, RouteCreationMode const routeCreationMode)
{
  match::AdMapMatching mapMatching;
  auto mapMatchingResults = mapMatching.getMapMatchedPositions(dest, physics::Distance(1.), physics::Probability(.05));

  return planRoute(mapMatchingResults, routingStart, routeCreationMode);
}

FullRoute
planRoute(const RoutingParaPoint &routingStart, const point::GeoPoint &dest, RouteCreationMode const routeCreationMode)
{
  return planRoutePoint(routingStart, dest, routeCreationMode);
}

FullRoute
planRoute(const RoutingParaPoint &routingStart, const point::ENUPoint &dest, RouteCreationMode const routeCreationMode)
{
  return planRoutePoint(routingStart, dest, routeCreationMode);
}

template <typename T>
FullRoute
planRouteVector(const RoutingParaPoint &start, const std::vector<T> &dest, RouteCreationMode const routeCreationMode)
{
  match::AdMapMatching mapMatching;
  std::vector<RoutingParaPoint> routingDestList;
  for (auto destIter = dest.begin(); destIter != dest.end(); destIter++)
  {
    auto mapMatchingResults
      = mapMatching.getMapMatchedPositions(*destIter, physics::Distance(1.), physics::Probability(.05));

    if ((destIter + 1) == dest.end())
    {
      if (mapMatchingResults.size() >= 1u)
      {
        addParaPointToRouteDestList(mapMatchingResults[0].lanePoint.paraPoint, routingDestList);
      }
      else
      {
        access::getLogger()->error("planRoute failed to locate final destination in the map {}", *destIter);
        return FullRoute();
      }
    }
    else if (mapMatchingResults.size() == 1u)
    {
      addParaPointToRouteDestList(mapMatchingResults[0].lanePoint.paraPoint, routingDestList);
    }
    else if (mapMatchingResults.size() == 0u)
    {
      access::getLogger()->trace("planRoute ignoring intermediate point not located in the map {}", *destIter);
    }
    else
    {
      access::getLogger()->trace("planRoute ignoring ambiguous intermediate point {}", *destIter);
    }
  }
  return planRoute(start, routingDestList, routeCreationMode);
}

FullRoute planRoute(const RoutingParaPoint &start,
                    const std::vector<point::GeoPoint> &dest,
                    RouteCreationMode const routeCreationMode)
{
  return planRouteVector(start, dest, routeCreationMode);
}

FullRoute planRoute(const RoutingParaPoint &start,
                    const std::vector<point::ENUPoint> &dest,
                    RouteCreationMode const routeCreationMode)
{
  return planRouteVector(start, dest, routeCreationMode);
}

FullRoute planRoute(const RoutingParaPoint &start,
                    std::vector<RoutingParaPoint> const &dest,
                    RouteCreationMode const routeCreationMode)
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
      access::getLogger()->error(
        "planRoute failed to calculate route between {} and {}", routingStart.point, routingDest.point);
      return FullRoute();
    }
  }
  return createFullRoute(mergedRawRoute, routeCreationMode, {});
}

std::ostream &operator<<(std::ostream &os, CompareRouteResult const &value)
{
  switch (value)
  {
    case CompareRouteResult::Equal:
      return os << "CompareRouteResult::Equal";
    case CompareRouteResult::Shorter:
      return os << "CompareRouteResult::Shorter";
    case CompareRouteResult::Longer:
      return os << "CompareRouteResult::Longer";
    case CompareRouteResult::Differ:
      return os << "CompareRouteResult::Differ";
    default:
      return os << "CompareRouteResult::out-of-range";
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
  if (left.drivableLaneSegments.size() == right.drivableLaneSegments.size())
  {
    for (std::size_t j = 0u; j < left.drivableLaneSegments.size(); j++)
    {
      if (left.drivableLaneSegments[j].laneInterval.laneId != right.drivableLaneSegments[j].laneInterval.laneId)
      {
        return CompareRouteResult::Differ;
      }

      // don't re-check for start equality directly after start
      if ((checkMode != CheckMode::MiddleAfterStart) && (checkMode != CheckMode::EndAfterStart))
      {
        bool const startEqual
          = left.drivableLaneSegments[j].laneInterval.start == right.drivableLaneSegments[j].laneInterval.start;

        if (!startEqual)
        {
          if (checkMode != CheckMode::Start)
          {
            return CompareRouteResult::Differ;
          }
          else if (isBeforeInterval(left.drivableLaneSegments[j].laneInterval,
                                    right.drivableLaneSegments[j].laneInterval.start))
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
          = left.drivableLaneSegments[j].laneInterval.end == right.drivableLaneSegments[j].laneInterval.end;
        if (!endEqual)
        {
          if ((checkMode != CheckMode::End) && (checkMode != CheckMode::EndAfterStart))
          {
            return CompareRouteResult::Differ;
          }
          else if (isAfterInterval(left.drivableLaneSegments[j].laneInterval,
                                   right.drivableLaneSegments[j].laneInterval.end))
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
  if (left.roadSegments.size() < right.roadSegments.size())
  {
    smallRoute = &left;
    largeRoute = &right;
    equalResult = CompareRouteResult::Shorter;
  }
  else if (left.roadSegments.size() > right.roadSegments.size())
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
  if (smallRoute->roadSegments.size() == 0u)
  {
    if (largeRoute->roadSegments.size() == 0u)
    {
      return CompareRouteResult::Equal;
    }
    else
    {
      return CompareRouteResult::Differ;
    }
  }

  std::size_t largeRouteIndexOffset = 0u;
  std::size_t const maxIndexOffset = largeRoute->roadSegments.size() - smallRoute->roadSegments.size();
  std::size_t smallRouteIndex = 0u;
  auto checkMode{CheckMode::Start};
  // search for comparison begin
  for (; largeRouteIndexOffset <= maxIndexOffset; largeRouteIndexOffset++)
  {
    auto const compareSegmentResult = compareRoadSegmentOnIntervalLevelOrdered(
      smallRoute->roadSegments[smallRouteIndex], largeRoute->roadSegments[largeRouteIndexOffset], checkMode);
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
  for (; smallRouteIndex < smallRoute->roadSegments.size(); smallRouteIndex++)
  {
    std::size_t const largeRouteIndex = smallRouteIndex + largeRouteIndexOffset;
    if (smallRouteIndex + 1u == smallRoute->roadSegments.size())
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
      smallRoute->roadSegments[smallRouteIndex], largeRoute->roadSegments[largeRouteIndex], checkMode);

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

std::vector<FullRoute> filterDuplicatedRoutes(const std::vector<FullRoute> fullRoutes,
                                              FilterDuplicatesMode const filterMode)
{
  std::vector<FullRoute> filteredRoutes;
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
                                    RouteCreationMode const routeCreationMode,
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
      resultRoutes.push_back(createFullRoute(rawRoute, routeCreationMode, relevantLanes));
    }
  }
  return filterDuplicatedRoutes(resultRoutes, filterMode);
}

FullRouteList predictRoutes(const RoutingParaPoint &start,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const routeCreationMode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutesInternal(
    start, predictionDistance, predictionDuration, routeCreationMode, filterMode, relevantLanes, Route::Type::SHORTEST);
}

std::vector<route::FullRoute> predictRoutesDirectionless(const point::ParaPoint &start,
                                                         physics::Distance const &predictionDistance,
                                                         physics::Duration const &predictionDuration,
                                                         RouteCreationMode const routeCreationMode,
                                                         FilterDuplicatesMode const filterMode,
                                                         ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutesInternal(createRoutingParaPoint(start.laneId, start.parametricOffset),
                               predictionDistance,
                               predictionDuration,
                               routeCreationMode,
                               filterMode,
                               relevantLanes,
                               Route::Type::SHORTEST_IGNORE_DIRECTION);
}

FullRouteList predictRoutes(const match::MapMatchedObjectBoundingBox &startObject,
                            physics::Distance const &predictionDistance,
                            physics::Duration const &predictionDuration,
                            RouteCreationMode const routeCreationMode,
                            FilterDuplicatesMode const filterMode,
                            ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  FullRouteList resultRoutes;
  auto const enuHeading = match::getObjectENUHeading(startObject);
  for (auto const &startMatchingResult : startObject.laneOccupiedRegions)
  {
    auto const routingStart = createRoutingPoint(startMatchingResult, enuHeading);
    auto const routes = predictRoutes(routingStart,
                                      predictionDistance,
                                      predictionDuration,
                                      routeCreationMode,
                                      FilterDuplicatesMode::Off,
                                      relevantLanes);
    resultRoutes.insert(resultRoutes.end(), routes.begin(), routes.end());
  }
  return filterDuplicatedRoutes(resultRoutes, filterMode);
}

FullRouteList predictRoutesOnDuration(const RoutingParaPoint &start,
                                      physics::Duration const &predictionDuration,
                                      RouteCreationMode const routeCreationMode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    start, physics::Distance::getMax(), predictionDuration, routeCreationMode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDuration(const match::MapMatchedObjectBoundingBox &startObject,
                                      physics::Duration const &predictionDuration,
                                      RouteCreationMode const routeCreationMode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, physics::Distance::getMax(), predictionDuration, routeCreationMode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDistance(const RoutingParaPoint &start,
                                      physics::Distance const &predictionDistance,
                                      RouteCreationMode const routeCreationMode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    start, predictionDistance, physics::Duration::getMax(), routeCreationMode, filterMode, relevantLanes);
}

FullRouteList predictRoutesOnDistance(const match::MapMatchedObjectBoundingBox &startObject,
                                      physics::Distance const &predictionDistance,
                                      RouteCreationMode const routeCreationMode,
                                      FilterDuplicatesMode const filterMode,
                                      ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return predictRoutes(
    startObject, predictionDistance, physics::Duration::getMax(), routeCreationMode, filterMode, relevantLanes);
}

bool doRoadSegmentsHaveCommonLanes(route::RoadSegment const &roadSegmentA, route::RoadSegment const &roadSegmentB)
{
  for (route::LaneSegmentList::const_iterator laneSegmentIterA = roadSegmentA.drivableLaneSegments.begin();
       laneSegmentIterA != roadSegmentA.drivableLaneSegments.end();
       ++laneSegmentIterA)
  {
    for (route::LaneSegmentList::const_iterator laneSegmentIterB = roadSegmentB.drivableLaneSegments.begin();
         laneSegmentIterB != roadSegmentB.drivableLaneSegments.end();
         ++laneSegmentIterB)
    {
      if (laneSegmentIterA->laneInterval.laneId == laneSegmentIterB->laneInterval.laneId)
      {
        // found a common lane
        return true;
      }
    }
  }
  return false;
}

route::RoadSegmentList::iterator
findRoadSegmentWithCommonLanes(route::RoadSegment const &roadSegment,
                               route::RoadSegmentList::iterator roadSegmentSearchIterStart,
                               route::RoadSegmentList::iterator roadSegmentSearchIterEnd)
{
  for (auto iter = roadSegmentSearchIterStart; iter != roadSegmentSearchIterEnd; iter++)
  {
    if (doRoadSegmentsHaveCommonLanes(roadSegment, *iter))
    {
      return iter;
    }
  }
  return roadSegmentSearchIterEnd;
}

ConnectingRoute
calculateConnectingRouteCreateMergingRouteUpToPositions(route::FullRoute &objectARoute,
                                                        route::RoadSegmentList::iterator roadSegmentIterA,
                                                        route::FullRoute &objectBRoute,
                                                        route::RoadSegmentList::iterator roadSegmentIterB)
{
  ConnectingRoute resultRoute;
  resultRoute.type = ConnectingRouteType::Merging;
  // cut the route at the beginning of the current road segments
  for (route::LaneSegmentList::iterator laneSegmentIterA = roadSegmentIterA->drivableLaneSegments.begin();
       laneSegmentIterA != roadSegmentIterA->drivableLaneSegments.end();
       ++laneSegmentIterA)
  {
    laneSegmentIterA->laneInterval.end = laneSegmentIterA->laneInterval.start;
    laneSegmentIterA->successors.clear();
  }
  roadSegmentIterA++;
  roadSegmentIterA = objectARoute.roadSegments.erase(roadSegmentIterA, objectARoute.roadSegments.end());
  resultRoute.routeA = objectARoute;

  for (route::LaneSegmentList::iterator laneSegmentIterB = roadSegmentIterB->drivableLaneSegments.begin();
       laneSegmentIterB != roadSegmentIterB->drivableLaneSegments.end();
       ++laneSegmentIterB)
  {
    laneSegmentIterB->laneInterval.end = laneSegmentIterB->laneInterval.start;
    laneSegmentIterB->successors.clear();
  }
  roadSegmentIterB++;
  roadSegmentIterB = objectBRoute.roadSegments.erase(roadSegmentIterB, objectBRoute.roadSegments.end());
  resultRoute.routeB = objectBRoute;
  return resultRoute;
}

ConnectingRoute calculateConnectingRouteCheckForMergingRoute(route::FullRoute &objectARoute,
                                                             route::FullRoute &objectBRoute)
{
  auto roadSegmentIterA = objectARoute.roadSegments.begin();
  auto roadSegmentIterB = objectBRoute.roadSegments.begin();
  physics::Distance routeADistanceCovered{0.};
  physics::Distance routeBDistanceCovered{0.};

  do
  {
    // we want to find the shortest connecting route
    // therefore, increment the roadSegmentIter of the route with less distance covered
    if (routeADistanceCovered <= routeBDistanceCovered)
    {
      if (roadSegmentIterA != objectARoute.roadSegments.end())
      {
        routeADistanceCovered += calcLength(*roadSegmentIterA);

        // fix current segment A and search rest of B
        auto findResultB
          = findRoadSegmentWithCommonLanes(*roadSegmentIterA, roadSegmentIterB, objectBRoute.roadSegments.end());
        if (findResultB != objectBRoute.roadSegments.end())
        {
          return calculateConnectingRouteCreateMergingRouteUpToPositions(
            objectARoute, roadSegmentIterA, objectBRoute, findResultB);
        }

        roadSegmentIterA++;
      }
    }
    if (routeBDistanceCovered <= routeADistanceCovered)
    {
      if (roadSegmentIterB != objectBRoute.roadSegments.end())
      {
        routeBDistanceCovered += calcLength(*roadSegmentIterB);

        // fix current segment B and search rest of A
        auto findResultA
          = findRoadSegmentWithCommonLanes(*roadSegmentIterB, roadSegmentIterA, objectARoute.roadSegments.end());
        if (findResultA != objectARoute.roadSegments.end())
        {
          return calculateConnectingRouteCreateMergingRouteUpToPositions(
            objectARoute, findResultA, objectBRoute, roadSegmentIterB);
        }

        roadSegmentIterB++;
      }
    }
  } while ((roadSegmentIterA != objectARoute.roadSegments.end())
           && (roadSegmentIterB != objectBRoute.roadSegments.end()));

  ConnectingRoute resultRoute;
  resultRoute.type = ConnectingRouteType::Invalid;
  return resultRoute;
}

double createHeadingRating(point::ENUHeading const &routeHeading,
                           point::ENUHeading const &objectHeading,
                           double objectHeadingOffset = 0.)
{
  auto routeHeadingD = static_cast<double>(routeHeading);
  auto objectHeadingD = static_cast<double>(objectHeading) + objectHeadingOffset;

  auto const headingDifference
    = std::fabs(physics::normalizeAngleSigned(physics::Angle(routeHeadingD - objectHeadingD)));

  if (headingDifference > physics::cPI_2)
  {
    return 0.;
  }
  return 1. - 2. * headingDifference / physics::cPI;
}

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

  const match::Object &objectA;
  const match::Object &objectB;
  Route::RawRoute rawRoute;
  match::LaneOccupiedRegion regionA;
  match::LaneOccupiedRegion regionB;
  lane::LaneIdSet const &relevantLanes;

  void createFullRouteAndRating()
  {
    fullRoute = calculateFullRoute(regionA, regionB, true);
    fullRouteLength = route::calcLength(fullRoute);

    headingRatingAlongRouteA = createHeadingRating(enuHeadingRouteA, objectA.enuPosition.heading);
    headingRatingAlongRouteB = createHeadingRating(enuHeadingRouteB, objectB.enuPosition.heading);
    headingRatingOppositeRouteA = createHeadingRating(enuHeadingRouteA, objectA.enuPosition.heading, M_PI);
    headingRatingOppositeRouteB = createHeadingRating(enuHeadingRouteB, objectB.enuPosition.heading, M_PI);
  }

  FullRoute calculateFullRoute(match::LaneOccupiedRegion const &regionDropStart,
                               match::LaneOccupiedRegion const &regionDropEnd,
                               bool updateHeading);

  FullRoute getInvertedFullRoute()
  {
    std::reverse(rawRoute.paraPointList.begin(), rawRoute.paraPointList.end());
    return calculateFullRoute(regionB, regionA, false);
  }

  FullRoute fullRoute;
  physics::Distance fullRouteLength{};
  point::ENUHeading enuHeadingRouteA;
  point::ENUHeading enuHeadingRouteB;

  double headingRatingAlongRouteA{0.};
  double headingRatingAlongRouteB{0.};
  double headingRatingOppositeRouteA{0.};
  double headingRatingOppositeRouteB{0.};

  bool isDegenerated()
  {
    return fullRouteLength == physics::Distance(0.);
  }

  bool objectADrivesAlongRoute()
  {
    return headingRatingAlongRouteA > 0.;
  }

  bool objectBDrivesOppositeToRoute()
  {
    return headingRatingOppositeRouteB > 0.;
  }

  void setAFollowsB()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Following;
      resultRoute.routeA = fullRoute;
      resultRoute.routeB = route::FullRoute();
      headingFeasibility = headingRatingAlongRouteA * headingRatingAlongRouteB;
    }
  }

  void setBFollowsA()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Following;
      resultRoute.routeA = route::FullRoute();
      resultRoute.routeB = getInvertedFullRoute();
      headingFeasibility = headingRatingOppositeRouteA * headingRatingOppositeRouteB;
    }
  }

  void setOpposing()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Opposing;
      resultRoute.routeA = fullRoute;
      resultRoute.routeB = getInvertedFullRoute();
      headingFeasibility = headingRatingAlongRouteA * headingRatingOppositeRouteB;
    }
  }

  void setInvertedOpposing()
  {
    if (!isResultValid())
    {
      resultRoute.type = ConnectingRouteType::Opposing;
      resultRoute.routeA = getInvertedFullRoute();
      resultRoute.routeB = fullRoute;
      headingFeasibility = headingRatingOppositeRouteA * headingRatingAlongRouteB;
    }
  }

  bool isResultValid() const
  {
    return resultRoute.type != ConnectingRouteType::Invalid;
  }

  bool isResultFeasible() const
  {
    if (resultRoute.type == ConnectingRouteType::Invalid)
    {
      return false;
    }

    // both 45° error -> headingFeasibility = 0.25
    return headingFeasibility > 0.2;
  }

  ConnectingRoute resultRoute;
  double headingFeasibility{0.};
};

std::ostream &operator<<(std::ostream &os, ConnectingRouteCandidate const &value)
{
  os << "ConnectingRouteCandidate("
     << " A:" << value.regionA << " routeHeading:" << value.enuHeadingRouteA
     << " objectHeading:" << value.objectA.enuPosition.heading << " ratingAlong:" << value.headingRatingAlongRouteA
     << " ratingOpposite:" << value.headingRatingOppositeRouteA << " B:" << value.regionB
     << " routeHeading:" << value.enuHeadingRouteB << " objectHeading:" << value.objectB.enuPosition.heading
     << " ratingAlong:" << value.headingRatingAlongRouteB << " ratingOpposite:" << value.headingRatingOppositeRouteB
     << " len:" << value.fullRouteLength << " feas:" << value.headingFeasibility << " " << value.fullRoute
     << " raw:" << value.rawRoute << "result: " << value.resultRoute << ")";
  return os;
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
  return left.headingFeasibility < right.headingFeasibility;
}

FullRoute ConnectingRouteCandidate::calculateFullRoute(match::LaneOccupiedRegion const &regionDropStart,
                                                       match::LaneOccupiedRegion const &regionDropEnd,
                                                       bool const updateHeading)
{
  auto route = createFullRoute(rawRoute, RouteCreationMode::AllRoutableLanes, relevantLanes);

  if (!route.roadSegments.empty())
  {
    // drop the lane regions which led to the creation of the route as start and destination
    // and calculate the heading of the lanes in the respective regions
    for (auto &laneSegment : route.roadSegments.front().drivableLaneSegments)
    {
      if (laneSegment.laneInterval.laneId == regionDropStart.laneId)
      {
        bool alignmentRequired = false;
        if (isWithinInterval(laneSegment.laneInterval, regionDropStart.longitudinalRange.minimum))
        {
          if (laneSegment.laneInterval.start != regionDropStart.longitudinalRange.minimum)
          {
            laneSegment.laneInterval.start = regionDropStart.longitudinalRange.minimum;
            alignmentRequired = true;
          }
        }
        if (isWithinInterval(laneSegment.laneInterval, regionDropStart.longitudinalRange.maximum))
        {
          if (laneSegment.laneInterval.start != regionDropStart.longitudinalRange.maximum)
          {
            laneSegment.laneInterval.start = regionDropStart.longitudinalRange.maximum;
            alignmentRequired = true;
          }
        }
        if (alignmentRequired)
        {
          alignRouteStartingPoints(getIntervalStart(laneSegment.laneInterval), route);
        }

        if (updateHeading)
        {
          enuHeadingRouteA = lane::getLaneENUHeading(route::getIntervalStart(laneSegment.laneInterval));
          if (laneSegment.laneInterval.wrongWay)
          {
            // on a wrong way segment, we have to turn the lane heading in route direction
            enuHeadingRouteA = point::createENUHeading(static_cast<double>(enuHeadingRouteA) + M_PI);
          }
        }
        break;
      }
    }
    for (auto &laneSegment : route.roadSegments.back().drivableLaneSegments)
    {
      if (laneSegment.laneInterval.laneId == regionDropEnd.laneId)
      {
        bool alignmentRequired = false;
        if (isWithinInterval(laneSegment.laneInterval, regionDropEnd.longitudinalRange.minimum))
        {
          if (laneSegment.laneInterval.end != regionDropEnd.longitudinalRange.minimum)
          {
            laneSegment.laneInterval.end = regionDropEnd.longitudinalRange.minimum;
            alignmentRequired = true;
          }
        }
        if (isWithinInterval(laneSegment.laneInterval, regionDropEnd.longitudinalRange.maximum))
        {
          if (laneSegment.laneInterval.end != regionDropEnd.longitudinalRange.maximum)
          {
            laneSegment.laneInterval.end = regionDropEnd.longitudinalRange.maximum;
            alignmentRequired = true;
          }
        }
        if (alignmentRequired)
        {
          alignRouteEndingPoints(getIntervalEnd(laneSegment.laneInterval), route);
        }
        if (updateHeading)
        {
          enuHeadingRouteB = lane::getLaneENUHeading(route::getIntervalEnd(laneSegment.laneInterval));
          if (laneSegment.laneInterval.wrongWay)
          {
            // on a wrong way segment, we have to turn the lane heading in route direction
            enuHeadingRouteB = point::createENUHeading(static_cast<double>(enuHeadingRouteB) + M_PI);
          }
        }
        break;
      }
    }
  }

  return route;
}

ConnectingRoute calculateConnectingRoute(const match::Object &objectA,
                                         const match::Object &objectB,
                                         physics::Distance const &maxDistance,
                                         physics::Duration const &maxDuration,
                                         std::vector<route::FullRoute> const &objectAPredictionHints,
                                         std::vector<route::FullRoute> const &objectBPredictionHints,
                                         lane::LaneIdSet const &relevantLanes)
{
  std::list<ConnectingRouteCandidate> connectingRouteCandidates;
  for (auto const &startMatchingResult : objectA.mapMatchedBoundingBox.laneOccupiedRegions)
  {
    if (!isLaneRelevantForExpansion(startMatchingResult.laneId, relevantLanes))
    {
      continue;
    }
    auto const routingStart = createRoutingPoint(startMatchingResult);
    for (auto const &destMatchingResult : objectB.mapMatchedBoundingBox.laneOccupiedRegions)
    {
      if (!isLaneRelevantForExpansion(destMatchingResult.laneId, relevantLanes))
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
    // first sort our candidates by raw route distance distance
    connectingRouteCandidates.sort(compareCandidateRawRoutes);

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

      if (candidateIter->isResultFeasible())
      {
        // found a valid and feasible connecting route, return
        access::getLogger()->trace("calculateConnectingRoute[]: select valid and feasible result {}", *candidateIter);
        return candidateIter->resultRoute;
      }

      if (candidateIter->isResultValid())
      {
        // not feasible, continue evaluation
        access::getLogger()->trace("calculateConnectingRoute[]: valid, but not feasible. Continue... {}",
                                   *candidateIter);
        candidateIter++;
      }
      else
      {
        // not valid, drop
        access::getLogger()->trace("calculateConnectingRoute[]: not valid, dropping. Continue... {}", *candidateIter);
        candidateIter = connectingRouteCandidates.erase(candidateIter);
      }
    }

    if (connectingRouteCandidates.size() > 0u)
    {
      // take the most feasible of the remaining
      connectingRouteCandidates.sort(compareCandidateFeasibility);
      access::getLogger()->trace("calculateConnectingRoute[]: select most feasible of the remaining {}",
                                 connectingRouteCandidates.front());
      return connectingRouteCandidates.front().resultRoute;
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
      objectAPredictions = predictRoutes(objectA.mapMatchedBoundingBox,
                                         maxDistance,
                                         maxDuration,
                                         RouteCreationMode::SameDrivingDirection,
                                         FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                                         relevantLanes);
    }
    auto objectBPredictions = objectBPredictionHints;
    if (objectBPredictions.empty())
    {
      objectBPredictions = predictRoutes(objectB.mapMatchedBoundingBox,
                                         maxDistance,
                                         maxDuration,
                                         RouteCreationMode::SameDrivingDirection,
                                         FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                                         relevantLanes);
    }

    auto resultDistance = std::numeric_limits<physics::Distance>::max();
    ConnectingRoute resultRoute;
    for (auto &objectAPrediction : objectAPredictions)
    {
      for (auto &objectBPrediction : objectBPredictions)
      {
        auto mergingRouteResult = calculateConnectingRouteCheckForMergingRoute(objectAPrediction, objectBPrediction);
        if (mergingRouteResult.type == ConnectingRouteType::Merging)
        {
          auto mergeDistance = std::min(calcLength(mergingRouteResult.routeA), calcLength(mergingRouteResult.routeB));
          if (mergeDistance < resultDistance)
          {
            resultDistance = mergeDistance;
            resultRoute = std::move(mergingRouteResult);
          }
        }
      }
    }
    access::getLogger()->trace("calculateConnectingRoute[]: merge result {}", resultRoute);
    return resultRoute;
  }

  access::getLogger()->trace("calculateConnectingRoute[]: empty result");
  return ConnectingRoute();
}

ConnectingRoute calculateConnectingRoute(const match::Object &startObject,
                                         const match::Object &destObject,
                                         physics::Distance const &maxDistance,
                                         std::vector<route::FullRoute> const &objectAPredictionHints,
                                         std::vector<route::FullRoute> const &objectBPredictionHints,
                                         ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return calculateConnectingRoute(startObject,
                                  destObject,
                                  maxDistance,
                                  std::numeric_limits<physics::Duration>::max(),
                                  objectAPredictionHints,
                                  objectBPredictionHints,
                                  relevantLanes);
}

ConnectingRoute calculateConnectingRoute(const match::Object &startObject,
                                         const match::Object &destObject,
                                         physics::Duration const &maxDuration,
                                         std::vector<route::FullRoute> const &objectAPredictionHints,
                                         std::vector<route::FullRoute> const &objectBPredictionHints,
                                         ::ad::map::lane::LaneIdSet const &relevantLanes)
{
  return calculateConnectingRoute(startObject,
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
