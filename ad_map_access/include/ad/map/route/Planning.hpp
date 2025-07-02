// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/config/PointOfInterest.hpp"
#include "ad/map/match/Object.hpp"
#include "ad/map/route/Route.hpp"
#include "ad/map/route/RouteOperation.hpp"
#include "ad/map/route/Routing.hpp"
#include "ad/map/route/Types.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace route */
namespace route {
/**
 * @brief provides route planning capabilities on the road network of the map
 */
namespace planning {

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] lane_id  the lane id
 * @param[in] parametric_offset the parametric offset
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
RoutingParaPoint createRoutingPoint(lane::LaneId const &lane_id,
                                    physics::ParametricValue const &parametric_offset,
                                    RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE);

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] para_point the parametric point
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
RoutingParaPoint createRoutingPoint(point::ParaPoint const &para_point,
                                    RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE);

/**
 * @brief create a RoutingParaPoint
 *
 * We select the routing point by either taking the maximum or minimum of the occupied region
 * Since occupied regions span over a certain area, the point is selected in a way,
 * that it is ensured that any other point within the region can be reached by routing with
 * the given routing direction
 *
 * @param[in] occupiedRegion the occupied region
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion,
                                    RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE);

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] para_point the parametric point
 * @param[in] heading the heading to be respected
 */
RoutingParaPoint createRoutingPoint(point::ParaPoint const &para_point, point::ENUHeading const &heading);

/**
 * @brief create a RoutingParaPoint
 *
 * We select the routing point by either taking the maximum or minimum of the occupied region
 * Since occupied regions span over a certain area, the point is selected in a way,
 * that it is ensured that any other point within the region can be reached by routing with
 * the given routing direction
 *
 * @param[in] occupiedRegion the occupied region
 * @param[in] heading the heading to be respected
 */
RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion, point::ENUHeading const &heading);

/** @brief Calculates route between two points.
 * @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
 * @param[in] dest  Destination point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
route::FullRoute planRoute(const RoutingParaPoint &start,
                           const RoutingParaPoint &dest,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/** @brief Calculates route between two points.
 *
 * Orientation at start/dest are not considered.
 *
 * @param[in] start Start point.
 * @param[in] dest  Destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  const point::ParaPoint &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start), createRoutingPoint(dest), route_creation_mode);
}

/** @brief Calculates route between two points.
 *
 * Orientation at dest is not considered.
 *
 * @param[in] start Start point.
 * @param[in] startHeading Heading at start point.
 * @param[in] dest  Destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const point::ParaPoint &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start, startHeading), createRoutingPoint(dest), route_creation_mode);
}

/** @brief Calculates route between two points.
 * @param[in] start Start point.
 * @param[in] startHeading Heading at start point.
 * @param[in] dest  Destination point.
 * @param[in] destHeading Heading at dest point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const point::ParaPoint &dest,
                                  point::ENUHeading const &destHeading,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start, startHeading), createRoutingPoint(dest, destHeading), route_creation_mode);
}

/** @brief Calculates route between two points.
 * @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
 * @param[in] dest  Destination point as geo point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
route::FullRoute planRoute(const RoutingParaPoint &start,
                           const point::GeoPoint &dest,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/** @brief Calculates route between two points.
 * @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
 * @param[in] dest  Destination point as ENU point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
route::FullRoute planRoute(const RoutingParaPoint &start,
                           const point::ENUPoint &dest,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/** @brief Calculates route between two points.
 * @param[in] start Start point.
 * @param[in] dest  Destination point as geo point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  const point::GeoPoint &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start), dest, route_creation_mode);
}

/** @brief Calculates route between two points.
 * @param[in] start Start point.
 * @param[in] dest  Destination point as enu point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  const point::ENUPoint &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start), dest, route_creation_mode);
}

/** @brief Calculates route between two points.
 * @param[in] start Start point.
 * @param[in] startHeading Heading at start point.
 * @param[in] dest  Destination point as geo point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const point::GeoPoint &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start, startHeading), dest, route_creation_mode);
}

/** @brief Calculates route between two points.
 * @param[in] start Start point.
 * @param[in] dest  Destination point as point of interest.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline FullRoute planRoute(const point::ParaPoint &start,
                           const config::PointOfInterest &dest,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(start, dest.geo_point, route_creation_mode);
}

/** @brief Calculates route between two points considering supporting points on the way.
 * @param[in] start Start point.
 * @param[in] dest Vector with supporting points as geo points to be visited on the route. Last point in the list is the
 * actual destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 *
 * Be aware: Supporting points providing multiple map maptched positions (i.e. the ones located within intersections)
 * are discarded to ensure the proper route is taken.
 */
FullRoute planRoute(const RoutingParaPoint &start,
                    const point::GeoPointList &dest,
                    RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/** @brief Calculates route between two points considering supporting points on the way.
 * @param[in] start Start point.
 * @param[in] dest Vector with supporting points as ENU points to be visited on the route. Last point in the list is the
 * actual destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 *
 * Be aware: Supporting points providing multiple map maptched positions (i.e. the ones located within intersections)
 * are discarded to ensure the proper route is taken.
 */
FullRoute planRoute(const RoutingParaPoint &start,
                    const point::ENUPointList &dest,
                    RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/**
 * @brief Calculates route between two points considering supporting points on the way
 * @param[in] start Start point.
 * @param[in] dest Vector with supporting points to be visited on the route. Last point in the list is the actual
 * destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
FullRoute planRoute(const RoutingParaPoint &start,
                    RoutingParaPointList const &dest,
                    RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection);

/** @brief Calculates route between two points considering supporting points on the way.
 * @param[in] start Start point.
 * @param[in] startHeading Heading at start point.
 * @param[in] dest Vector with supporting points as geo points to be visited on the route. Last point in the list is the
 * actual destination point.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const point::GeoPointList &dest,
                                  RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection)
{
  return planRoute(createRoutingPoint(start, startHeading), dest, route_creation_mode);
}

/** @brief mode for filtering duplicates in prediction
 */
enum class FilterDuplicatesMode
{
  /** no filtering at all
   */
  Off,
  /** filter routes that are exactly equal
   */
  OnlyEqual,
  /** filter real sub-routes, prefer shorter ones
   */
  SubRoutesPreferShorterOnes,
  /** filter real sub-routes, prefer longer ones
   */
  SubRoutesPreferLongerOnes
};

/**
 * @brief perform route based prediction restricted by the prediction duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDuration(const RoutingParaPoint &start,
                        physics::Duration const &predictionDuration,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDistance(const RoutingParaPoint &start,
                        physics::Distance const &predictionDistance,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutes(const RoutingParaPoint &start,
              physics::Distance const &predictionDistance,
              physics::Duration const &predictionDuration,
              RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
              FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
              ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point as map matched bounding box.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDuration(const match::MapMatchedObjectBoundingBox &start,
                        physics::Duration const &predictionDuration,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point as map matched bounding box.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDistance(const match::MapMatchedObjectBoundingBox &start,
                        physics::Distance const &predictionDistance,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] start start point as map matched bounding box.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutes(const match::MapMatchedObjectBoundingBox &start,
              physics::Distance const &predictionDistance,
              physics::Duration const &predictionDuration,
              RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
              FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
              ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] startObject start point as matched object.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDuration(const match::Object &startObject,
                        physics::Duration const &predictionDuration,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] startObject start point as matched object.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesOnDistance(const match::Object &startObject,
                        physics::Distance const &predictionDistance,
                        RouteCreationMode const route_creation_mode = RouteCreationMode::SameDrivingDirection,
                        FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                        ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * @param[in] startObject start point as matched object.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::SameDrivingDirection)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList predictRoutes(const match::Object &startObject,
                                   physics::Distance const &predictionDistance,
                                   physics::Duration const &predictionDuration,
                                   RouteCreationMode const route_creation_mode,
                                   FilterDuplicatesMode const filterMode,
                                   ::ad::map::lane::LaneIdSet const &relevantLanes);

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * This variant of route prediction allows to travel in either road directions.
 * Therefore, the start orientation is irrelevant (considered to be RoutingDirection::DONT_CARE).
 *
 * @param[in] start start point as parametric point.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::AllRoutableLanes)
 *  Be aware: selecting a route_creation_mode of RouteCreationMode::SameDrivingDirection will lead to incomplete
 * FullRoutes
 *  since the routes starting in wrong direction cannot be presented by this!
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesDirectionless(const point::ParaPoint &start,
                           physics::Distance const &predictionDistance,
                           physics::Duration const &predictionDuration,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::AllRoutableLanes,
                           FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                           ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * This variant of route prediction allows to travel in either road directions.
 * Therefore, the start orientation is irrelevant (considered to be RoutingDirection::DONT_CARE).
 *
 * @param[in] startObject start point as map matched bounding box.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::AllRoutableLanes)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesDirectionless(const match::MapMatchedObjectBoundingBox &startObject,
                           physics::Distance const &predictionDistance,
                           physics::Duration const &predictionDuration,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::AllRoutableLanes,
                           FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                           ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 * Note: Route predictions will not stop in the middle of an intersection.
 *   They continue until the intersection is left again.
 *
 * This variant of route prediction allows to travel in either road directions.
 * Therefore, the start orientation is irrelevant (considered to be RoutingDirection::DONT_CARE).
 *
 * @param[in] startObject start point as matched object.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 * @param[in] route_creation_mode the mode of creating the route (default: RouteCreationMode::AllRoutableLanes)
 * @param[in] filterMode the mode for filtering the routes (default: FilterDuplicatesMode::SubRoutesPreferLongerOnes)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @return vector with all possible predicted routes.
 */
route::FullRouteList
predictRoutesDirectionless(const match::Object &startObject,
                           physics::Distance const &predictionDistance,
                           physics::Duration const &predictionDuration,
                           RouteCreationMode const route_creation_mode = RouteCreationMode::AllRoutableLanes,
                           FilterDuplicatesMode const filterMode = FilterDuplicatesMode::SubRoutesPreferLongerOnes,
                           ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief Filter duplicated routes from a list of routes
 *
 * If one of the routes is a real sub-route of the other, the longer version of the route is kept, the shorter dropped
 *
 * @param[in] fullRoutes list of full routes to be filtered
 * @param[in] filterMode the mode for filtering the routes
 *
 * @returns the filtered list of routes according to the provided \a filterMode
 */
FullRouteList filterDuplicatedRoutes(const FullRouteList fullRoutes, FilterDuplicatesMode const filterMode);

/** @brief result for comparing two routes with each other
 */
enum class CompareRouteResult
{
  /**
   * equal
   */
  Equal,
  /**
   * shorter
   */
  Shorter,
  /**
   * longer
   */
  Longer,
  /**
   * differ
   */
  Differ
};

/*!
 * \brief Conversion of ::ad::map::route::planning::CompareRouteResult to std::string helper.
 */
std::string toString(::ad::map::route::planning::CompareRouteResult const e);

/**
 * @brief Compare two routes on interval level
 *
 * @returns CompareRouteResult of the comparison
 * @retval CompareRouteResult::Equal left route and right route are considered equal on interval level
 * @retval CompareRouteResult::Shorter left route is a real sub-route of the right route, therefore left route is
 * considered shorter
 * @retval CompareRouteResult::Longer right route is a real sub-route of the left route, therefore left route is
 * considered longer
 * @retval CompareRouteResult::Differ left route and right route are considered different on interval level
 *
 */
CompareRouteResult compareRoutesOnIntervalLevel(FullRoute const &left, FullRoute const &right);

/**
 * @brief Calculate the connecting routes between the the two objects
 *
 * For route calculations the route type core::Route::Type::SHORTEST_IGNORE_DIRECTION is used.
 * The prediction hints are taken into account if no direct connecting route can be found in search of a merge route.
 * If no prediction hints are given, respective route predictions are calculated internally.
 *
 * @param[in] startObject object at starting position
 * @param[in] destObject object at destination position
 * @param[in] maxDistance distance when the search can be stopped.
 * @param[in] maxDuration duration when the search can be stopped.
 * @param[in] startObjectPredictionHints route prediction hints for start object (optional)
 * @param[in] destObjectPredictionHints route prediction hints for dest object (optional)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @returns list of connecting routes sorted by their feasibility descending in terms of object to route heading (see
 * also getHeadingFeasibility())
 */
route::ConnectingRouteList
calculateConnectingRoutes(const match::Object &startObject,
                          const match::Object &destObject,
                          physics::Distance const &maxDistance,
                          physics::Duration const &maxDuration,
                          route::FullRouteList const &startObjectPredictionHints = route::FullRouteList(),
                          route::FullRouteList const &destObjectPredictionHints = route::FullRouteList(),
                          ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief Calculate the connecting routes between the the two objects
 *
 * For route calculations the route type core::Route::Type::SHORTEST_IGNORE_DIRECTION is used.
 * The prediction hints are taken into account if no direct connecting route can be found in search of a merge route.
 * If no prediction hints are given, respective route predictions are calculated internally.
 *
 * @param[in] startObject object at starting position
 * @param[in] destObject object at destination position
 * @param[in] maxDistance distance when the search can be stopped.
 * @param[in] startObjectPredictionHints route prediction hints for start object (optional)
 * @param[in] destObjectPredictionHints route prediction hints for dest object (optional)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @returns list of connecting routes sorted by their feasibility descending in terms of object to route heading (see
 * also getHeadingFeasibility())
 */
route::ConnectingRouteList
calculateConnectingRoutes(const match::Object &startObject,
                          const match::Object &destObject,
                          physics::Distance const &maxDistance,
                          route::FullRouteList const &startObjectPredictionHints = route::FullRouteList(),
                          route::FullRouteList const &destObjectPredictionHints = route::FullRouteList(),
                          ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief Calculate the connecting routes between the the two objects
 *
 * For route calculations the route type core::Route::Type::SHORTEST_IGNORE_DIRECTION is used.
 * The prediction hints are taken into account if no direct connecting route can be found in search of a merge route.
 * If no prediction hints are given, respective route predictions are calculated internally.
 *
 * @param[in] startObject object at starting position
 * @param[in] destObject object at destination position
 * @param[in] maxDuration duration when the search can be stopped.
 * @param[in] startObjectPredictionHints route prediction hints for start object (optional)
 * @param[in] destObjectPredictionHints route prediction hints for dest object (optional)
 * @param[in] relevantLanes if not empty, the function restricts the prediction to the given set of lanes
 *
 * @returns list of connecting routes sorted by their feasibility descending in terms of object to route heading (see
 * also getHeadingFeasibility())
 */
route::ConnectingRouteList
calculateConnectingRoutes(const match::Object &startObject,
                          const match::Object &destObject,
                          physics::Duration const &maxDuration,
                          route::FullRouteList const &startObjectPredictionHints = route::FullRouteList(),
                          route::FullRouteList const &destObjectPredictionHints = route::FullRouteList(),
                          ::ad::map::lane::LaneIdSet const &relevantLanes = ::ad::map::lane::LaneIdSet());

/**
 * @brief update route planning counters of the route
 *
 * mainly used internally.
 */
void updateRoutePlanningCounters(route::FullRoute &route);

/**
 * @brief helper function to create a full route
 *
 * mainly used internally.
 */
FullRoute createFullRoute(const Route::RawRoute &rawRoute,
                          RouteCreationMode const route_creation_mode,
                          lane::LaneIdSet const &relevantLanes);

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief overload of fmt::formatter calling toString
 */
template <> struct fmt::formatter<::ad::map::route::planning::CompareRouteResult> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::route::planning::CompareRouteResult const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(::ad::map::route::planning::toString(value), ctx);
  }
};
