// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/lane/MapAreaOperation.hpp"

#include "ad/map/intersection/CoreIntersection.hpp"
#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/route/Planning.hpp"

namespace ad {
namespace map {
namespace lane {

LaneIdSet getLanesOfMapArea(::ad::map::point::BoundingSphere const &bounding_sphere)
{
  LaneIdSet mapArea;
  for (auto const &lane_id : ::ad::map::lane::getLanes())
  {
    auto lane = ::ad::map::lane::getLane(lane_id);
    if (::ad::map::lane::isNear(lane, bounding_sphere))
    {
      mapArea.insert(lane_id);
    }
  }
  return mapArea;
}

LaneIdSet getLanesOfMapArea(std::vector<MapAreaPredictionStartPoint> const &predictionStartPoints)
{
  LaneIdSet mapArea;
  for (auto const &predictionStartPoint : predictionStartPoints)
  {
    auto const reachableRoutes
      = ::ad::map::route::planning::predictRoutesOnDistance(predictionStartPoint.prediction_start,
                                                            predictionStartPoint.prediction_distance,
                                                            predictionStartPoint.route_creation_mode,
                                                            ::ad::map::route::planning::FilterDuplicatesMode::Off);
    for (auto const &route : reachableRoutes)
    {
      auto const route_lanes = route::getLanesOfRoute(route);
      mapArea.insert(route_lanes.begin(), route_lanes.end());
    }
  }
  return mapArea;
}

LaneIdSet getLanesOfMapArea(::ad::map::point::ENUPoint const &intersectionPoint,
                            ::ad::physics::Distance const &intersectionDistance)
{
  LaneIdSet mapArea;
  auto intersections
    = ::ad::map::intersection::CoreIntersection::getCoreIntersectionsForInLaneMatches(intersectionPoint);
  for (auto intersection : intersections)
  {
    auto const &internalLanes = intersection->internalLanes();
    mapArea.insert(internalLanes.begin(), internalLanes.end());

    for (auto entryParaPoint : intersection->entryParaPoints())
    {
      auto const reachableRoutes
        = ::ad::map::route::planning::predictRoutesDirectionless(entryParaPoint,
                                                                 intersectionDistance,
                                                                 physics::Duration::getMax(),
                                                                 ::ad::map::route::RouteCreationMode::AllNeighborLanes,
                                                                 ::ad::map::route::planning::FilterDuplicatesMode::Off);
      for (auto const &route : reachableRoutes)
      {
        auto const route_lanes = route::getLanesOfRoute(route);
        mapArea.insert(route_lanes.begin(), route_lanes.end());
      }
    }
    for (auto exitParaPoint : intersection->exitParaPoints())
    {
      auto const reachableRoutes
        = ::ad::map::route::planning::predictRoutesDirectionless(exitParaPoint,
                                                                 intersectionDistance,
                                                                 physics::Duration::getMax(),
                                                                 ::ad::map::route::RouteCreationMode::AllNeighborLanes,
                                                                 ::ad::map::route::planning::FilterDuplicatesMode::Off);
      for (auto const &route : reachableRoutes)
      {
        auto const route_lanes = route::getLanesOfRoute(route);
        mapArea.insert(route_lanes.begin(), route_lanes.end());
      }
    }
  }
  return mapArea;
}

} // namespace lane
} // namespace map
} // namespace ad
