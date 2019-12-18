// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/Planning.hpp"

#include <algorithm>
#include "ad/map/access/Logging.hpp"
#include "ad/map/access/Operation.hpp"
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
  return createRoutingPoint(match::getParaPoint(occupiedRegion), routingDirection);
}

RoutingParaPoint createRoutingPoint(point::ParaPoint const &paraPoint, point::ENUHeading const &heading)
{
  RoutingParaPoint routingPoint;
  if (lane::isHeadingInLaneDirection(paraPoint, heading))
  {
    if (lane::isLaneDirectionPositive(paraPoint.laneId))
    {
      routingPoint = createRoutingPoint(paraPoint, RoutingDirection::POSITIVE);
    }
    else
    {
      routingPoint = createRoutingPoint(paraPoint, RoutingDirection::NEGATIVE);
    }
  }
  else
  {
    if (lane::isLaneDirectionPositive(paraPoint.laneId))
    {
      routingPoint = createRoutingPoint(paraPoint, RoutingDirection::NEGATIVE);
    }
    else
    {
      routingPoint = createRoutingPoint(paraPoint, RoutingDirection::POSITIVE);
    }
  }
  return routingPoint;
}

RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion, point::ENUHeading const &heading)
{
  return createRoutingPoint(match::getParaPoint(occupiedRegion), heading);
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

FullRoute createFullRoute(const point::ParaPointList rawRoute)
{
  static RoutePlanningCounter routePlanningCounter = 0u;

  FullRoute resultRoute;

  for (size_t i = 0u; i < rawRoute.size();)
  {
    // first create a plain route containing no neighboring lanes
    const point::ParaPoint &intervalStartPoint = rawRoute[i];
    LaneInterval newInterval;
    newInterval.laneId = intervalStartPoint.laneId;
    newInterval.start = intervalStartPoint.parametricOffset;
    newInterval.end = newInterval.start;

    // search the end: the last point of the last neighbor
    for (++i; i < rawRoute.size(); ++i)
    {
      if (lane::isSameOrDirectNeighbor(newInterval.laneId, rawRoute[i].laneId))
      {
        newInterval.laneId = rawRoute[i].laneId;
        newInterval.end = rawRoute[i].parametricOffset;
      }
      else
      {
        break;
      }
    }

    // add the new interval
    appendRoadSegmentToRoute(newInterval, resultRoute.roadSegments);
  }

  // post process the route counters
  routePlanningCounter++;
  resultRoute.routePlanningCounter = routePlanningCounter;
  resultRoute.fullRouteSegmentCount = resultRoute.roadSegments.size();
  for (size_t i = 0; i < resultRoute.roadSegments.size(); ++i)
  {
    resultRoute.roadSegments[i].segmentCountFromDestination = resultRoute.roadSegments.size() - i;
  }

  access::getLogger()->trace("createFullRoute result {}", resultRoute);
  return resultRoute;
}

FullRoute planRoute(const RoutingParaPoint &routingStart, const RoutingParaPoint &routingDest)
{
  RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST);
  point::ParaPointList rawRoute;
  if (routePlanning.calculate())
  {
    rawRoute = routePlanning.getRawRoute();
  }
  return createFullRoute(rawRoute);
}

FullRoute planRoute(const RoutingParaPoint &routingStart, const point::GeoPoint &dest)
{
  FullRoute resultRoute;
  physics::Distance resultDistance = std::numeric_limits<physics::Distance>::max();
  match::AdMapMatching mapMatching;
  auto mapMatchingResults = mapMatching.getMapMatchedPositions(dest, physics::Distance(1.), physics::Probability(.05));
  for (auto const &mapMatchingResult : mapMatchingResults)
  {
    FullRoute route = planRoute(routingStart, createRoutingPoint(mapMatchingResult.lanePoint.paraPoint));
    physics::Distance const routeDistance = calcLength(route);
    if (routeDistance < resultDistance)
    {
      resultDistance = routeDistance;
      resultRoute = route;
    }
  }

  return resultRoute;
}

FullRoute planRoute(const RoutingParaPoint &start, const std::vector<point::GeoPoint> &dest)
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
  return planRoute(start, routingDestList);
}

FullRoute planRoute(const RoutingParaPoint &start, std::vector<RoutingParaPoint> const &dest)
{
  auto routingStart = start;
  point::ParaPointList mergedRawRoute;
  for (auto &routingDest : dest)
  {
    RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST);
    if (routePlanning.calculate())
    {
      auto rawRoute = routePlanning.getRawRoute();
      mergedRawRoute.insert(mergedRawRoute.end(), rawRoute.begin(), rawRoute.end());
      routingStart = routePlanning.getRoutingDest();
    }
    else
    {
      access::getLogger()->error(
        "planRoute failed to calculate route between {} and {}", routingStart.point, routingDest.point);
      return FullRoute();
    }
  }
  return createFullRoute(mergedRawRoute);
}

enum class CompareRouteResult
{
  Equal,
  Smaller,
  Larger,
  Differ
};

CompareRouteResult compareRoutesOnIntervalLevel(FullRoute const &left, FullRoute const &right)
{
  // compare routes on laneInterval level
  auto minSize = std::min(left.roadSegments.size(), right.roadSegments.size());
  for (std::size_t i = 0u; i < minSize; i++)
  {
    if (left.roadSegments[i].drivableLaneSegments.size() == right.roadSegments[i].drivableLaneSegments.size())
    {
      for (std::size_t j = 0u; j < left.roadSegments[i].drivableLaneSegments.size(); j++)
      {
        if (left.roadSegments[i].drivableLaneSegments[j].laneInterval
            != right.roadSegments[i].drivableLaneSegments[j].laneInterval)
        {
          return CompareRouteResult::Differ;
        }
      }
    }
    else
    {
      return CompareRouteResult::Differ;
    }
  }
  if (left.roadSegments.size() == right.roadSegments.size())
  {
    return CompareRouteResult::Equal;
  }
  else if (left.roadSegments.size() < right.roadSegments.size())
  {
    return CompareRouteResult::Smaller;
  }
  else
  {
    return CompareRouteResult::Larger;
  }
}

std::vector<FullRoute> filterDuplicatedRoutes(const std::vector<FullRoute> fullRoutes)
{
  std::vector<FullRoute> filteredRoutes;

  for (auto const &route : fullRoutes)
  {
    bool addRoute = true;
    for (auto &filteredRoute : filteredRoutes)
    {
      // - if both are the same the new one is not added
      // - if one of the routes is a real sub-route of the other, the longer version of the route is kept
      // - otherwhise, both are disjunct and the new one might be added to the filtered list
      auto comparisonResult = compareRoutesOnIntervalLevel(route, filteredRoute);
      if (comparisonResult != CompareRouteResult::Differ)
      {
        addRoute = false;
        if (comparisonResult == CompareRouteResult::Larger)
        {
          // the new route is larger, and so overwrites the current filtered one
          filteredRoute = route;
        }
        else
        {
          // the new route is either identical or smaller than the current filtered one
          // it is just skipped
        }
        // stop the inner loop on filteredRoutes
        break;
      }
    }
    // new route differs to all filtered ones, so we have to add it
    if (addRoute)
    {
      filteredRoutes.push_back(route);
    }
  }
  return filteredRoutes;
}

std::vector<FullRoute> predictRoutesOnDuration(const RoutingParaPoint &start,
                                               physics::Duration const &predictionDuration)
{
  std::vector<FullRoute> resultRoutes;
  RoutePrediction routePrediction(start, predictionDuration);
  if (routePrediction.calculate())
  {
    for (auto &rawRoute : routePrediction.getRawRoutes())
    {
      resultRoutes.push_back(createFullRoute(rawRoute));
    }
  }
  return filterDuplicatedRoutes(resultRoutes);
}

std::vector<FullRoute> predictRoutesOnDistance(const RoutingParaPoint &start,
                                               physics::Distance const &predictionDistance)
{
  std::vector<FullRoute> resultRoutes;
  RoutePrediction routePrediction(start, predictionDistance);
  if (routePrediction.calculate())
  {
    for (auto &rawRoute : routePrediction.getRawRoutes())
    {
      resultRoutes.push_back(createFullRoute(rawRoute));
    }
  }
  return filterDuplicatedRoutes(resultRoutes);
}

std::vector<FullRoute> predictRoutes(const RoutingParaPoint &start,
                                     physics::Distance const &predictionDistance,
                                     physics::Duration const &predictionDuration)
{
  std::vector<FullRoute> resultRoutes;
  RoutePrediction routePrediction(start, predictionDistance, predictionDuration);
  if (routePrediction.calculate())
  {
    for (auto &rawRoute : routePrediction.getRawRoutes())
    {
      resultRoutes.push_back(createFullRoute(rawRoute));
    }
  }
  return filterDuplicatedRoutes(resultRoutes);
}

std::vector<FullRoute> predictRoutesOnDuration(const match::MapMatchedObjectBoundingBox &startObject,
                                               physics::Duration const &predictionDuration)
{
  std::vector<FullRoute> resultRoutes;
  auto const enuHeading = match::getObjectENUHeading(startObject);
  for (auto const &startMatchingResult : startObject.laneOccupiedRegions)
  {
    auto const routingStart = createRoutingPoint(startMatchingResult, enuHeading);
    auto const routes = predictRoutesOnDuration(routingStart, predictionDuration);
    resultRoutes.insert(resultRoutes.end(), routes.begin(), routes.end());
  }
  return filterDuplicatedRoutes(resultRoutes);
}

std::vector<FullRoute> predictRoutesOnDistance(const match::MapMatchedObjectBoundingBox &startObject,
                                               physics::Distance const &predictionDistance)
{
  std::vector<FullRoute> resultRoutes;
  auto const enuHeading = match::getObjectENUHeading(startObject);
  for (auto const &startMatchingResult : startObject.laneOccupiedRegions)
  {
    auto const routingStart = createRoutingPoint(startMatchingResult, enuHeading);
    auto const routes = predictRoutesOnDistance(routingStart, predictionDistance);
    resultRoutes.insert(resultRoutes.end(), routes.begin(), routes.end());
  }
  return filterDuplicatedRoutes(resultRoutes);
}

ConnectingRoute calculateConnectingBasicRoute(const RoutingParaPoint &routingStart, const RoutingParaPoint &routingDest)
{
  ConnectingRoute route;
  route.connectingRouteLength = physics::Distance(0.);
  route.minLaneOffset = 0;
  route.maxLaneOffset = 0;
  RouteAstar routePlanning(routingStart, routingDest, Route::Type::SHORTEST_IGNORE_DIRECTION);
  if (routePlanning.calculate())
  {
    int32_t currentLaneOffset = 0;
    auto rawRoute = routePlanning.getRawRoute();

    for (size_t i = 0u; i < rawRoute.size();)
    {
      // first create a ConnectingRoute containing only raw route lanes
      const point::ParaPoint &intervalStartPoint = rawRoute[i];
      ConnectingInterval newInterval;
      newInterval.laneInterval.laneId = intervalStartPoint.laneId;
      newInterval.laneInterval.start = intervalStartPoint.parametricOffset;
      newInterval.laneInterval.end = newInterval.laneInterval.start;
      // wrongWay flag will be handled in post processing
      newInterval.laneInterval.wrongWay = false;
      newInterval.laneOffset = currentLaneOffset;

      // search the segment end and keep track on the lane offset
      for (++i; i < rawRoute.size(); ++i)
      {
        auto const neighborhood
          = lane::getDirectNeighborhoodRelation(newInterval.laneInterval.laneId, rawRoute[i].laneId);
        if ((neighborhood == lane::ContactLocation::OVERLAP) || (neighborhood == lane::ContactLocation::LEFT)
            || (neighborhood == lane::ContactLocation::RIGHT))
        {
          newInterval.laneInterval.laneId = rawRoute[i].laneId;
          newInterval.laneInterval.end = rawRoute[i].parametricOffset;
          if (neighborhood == lane::ContactLocation::LEFT)
          {
            currentLaneOffset--;
            if (currentLaneOffset < route.minLaneOffset)
            {
              route.minLaneOffset = currentLaneOffset;
            }
          }
          else if (neighborhood == lane::ContactLocation::RIGHT)
          {
            currentLaneOffset++;
            if (currentLaneOffset > route.maxLaneOffset)
            {
              route.maxLaneOffset = currentLaneOffset;
            }
          }
          newInterval.laneOffset = currentLaneOffset;
        }
        else
        {
          break;
        }
      }

      ConnectingSegment routeSegment;
      routeSegment.push_back(newInterval);
      route.connectingSegments.push_back(routeSegment);
      route.connectingRouteLength += calcLength(newInterval.laneInterval);
    }
    route.destinationLaneOffset = currentLaneOffset;
  }
  return route;
}

inline void addWrongWayFlag(lane::Lane const &lane, ConnectingInterval &connectingInverval)
{
  connectingInverval.laneInterval.wrongWay
    = !((isRouteDirectionPositive(connectingInverval.laneInterval) && lane::isLaneDirectionPositive(lane))
        || (isRouteDirectionNegative(connectingInverval.laneInterval) && lane::isLaneDirectionNegative(lane)));
}

ConnectingRoute calculateConnectingRoute(const match::MapMatchedObjectBoundingBox &startObject,
                                         const match::MapMatchedObjectBoundingBox &destObject)
{
  ConnectingRoute resultRoute;
  resultRoute.connectingRouteLength = std::numeric_limits<physics::Distance>::max();

  auto const enuHeading = match::getObjectENUHeading(startObject);
  for (auto const &startMatchingResult : startObject.laneOccupiedRegions)
  {
    for (auto const &destMatchingResult : destObject.laneOccupiedRegions)
    {
      auto const routingStart = createRoutingPoint(startMatchingResult, enuHeading);
      auto const routingDest = createRoutingPoint(destMatchingResult);

      auto const route = calculateConnectingBasicRoute(routingStart, routingDest);
      if ((!route.connectingSegments.empty()) && (route.connectingRouteLength < resultRoute.connectingRouteLength))
      {
        resultRoute = route;
      }
    }
  }

  // post process the result route:
  // - expand relevant neighbors
  // - fill wrong way flags
  std::size_t numberOfLanesPerSegment = 1u;
  if (resultRoute.maxLaneOffset > resultRoute.minLaneOffset)
  {
    auto deltaLaneOffset = resultRoute.maxLaneOffset - resultRoute.minLaneOffset;
    numberOfLanesPerSegment += static_cast<std::size_t>(deltaLaneOffset);
  }
  for (auto &connectingSegment : resultRoute.connectingSegments)
  {
    if (connectingSegment.size() != 1u)
    {
      throw std::runtime_error("planning::calculateConnectingRoute unexpected size of connectingSegment");
    }

    // handle current interval
    auto rawLane = lane::getLane(connectingSegment.front().laneInterval.laneId);
    addWrongWayFlag(rawLane, connectingSegment.front());
    auto const rawIntervalOffset = connectingSegment.front().laneOffset;

    // reserve the space for the rest
    connectingSegment.reserve(numberOfLanesPerSegment);

    // add right neighbors
    auto lane = rawLane;
    for (int32_t offset = rawIntervalOffset + 1; offset <= resultRoute.maxLaneOffset; offset++)
    {
      lane::ContactLaneList contactLanes = getContactLanes(lane, lane::ContactLocation::RIGHT);
      // we expect that per map model only one contact lane is possible in one direction
      if (contactLanes.size() == 1u)
      {
        ConnectingInterval newInterval;
        newInterval.laneInterval.laneId = contactLanes.front().toLane;
        newInterval.laneInterval.start = connectingSegment.front().laneInterval.start;
        newInterval.laneInterval.end = connectingSegment.front().laneInterval.end;
        newInterval.laneOffset = offset;

        lane = lane::getLane(newInterval.laneInterval.laneId);
        addWrongWayFlag(lane, newInterval);
        // sorting: right lanes are added at front, left lanes at back
        connectingSegment.insert(connectingSegment.begin(), newInterval);
      }
      else
      {
        break;
      }
    }
    // add left neighbors
    lane = rawLane;
    for (int32_t offset = rawIntervalOffset - 1; offset >= resultRoute.minLaneOffset; offset--)
    {
      lane::ContactLaneList contactLanes = getContactLanes(lane, lane::ContactLocation::LEFT);
      // we expect that per map model only one contact lane is possible in one direction
      if (contactLanes.size() == 1u)
      {
        ConnectingInterval newInterval;
        newInterval.laneInterval.laneId = contactLanes.front().toLane;
        newInterval.laneInterval.start = connectingSegment.front().laneInterval.start;
        newInterval.laneInterval.end = connectingSegment.front().laneInterval.end;
        newInterval.laneOffset = offset;

        lane = lane::getLane(newInterval.laneInterval.laneId);
        addWrongWayFlag(lane, newInterval);
        // sorting: left lanes are added at back
        connectingSegment.insert(connectingSegment.end(), newInterval);
      }
      else
      {
        break;
      }
    }
  }
  return resultRoute;
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
