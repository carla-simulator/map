// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/config/PointOfInterest.hpp"
#include "ad/map/match/MapMatchedObjectBoundingBox.hpp"
#include "ad/map/route/Routing.hpp"
#include "ad/map/route/Types.hpp"

/* @brief namespace ad */
namespace ad {
/* @brief namespace map */
namespace map {
/* @brief namespace route */
namespace route {
/**
 * @namespace planning
 * @brief provides route planning capabilities on the road network of the map
 */
namespace planning {

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] laneId  the lane id
 * @param[in] parametricOffset the parametric offset
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
RoutingParaPoint createRoutingPoint(lane::LaneId const &laneId,
                                    physics::ParametricValue const &parametricOffset,
                                    RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE);

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] paraPoint the parametric point
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
RoutingParaPoint createRoutingPoint(point::ParaPoint const &paraPoint,
                                    RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE);

/**
 * @brief create a RoutingParaPoint
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
 * @param[in] paraPoint the parametric point
 * @param[in] heading the heading to be respected
 */
RoutingParaPoint createRoutingPoint(point::ParaPoint const &paraPoint, point::ENUHeading const &heading);

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] occupiedRegion the occupied region
 * @param[in] heading the heading to be respected
 */
RoutingParaPoint createRoutingPoint(match::LaneOccupiedRegion const &occupiedRegion, point::ENUHeading const &heading);

/** @brief Calculates route between two points.
* @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
* @param[in] dest  Destination point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
*/
route::FullRoute planRoute(const RoutingParaPoint &start, const RoutingParaPoint &dest);

/** @brief Calculates route between two points.
 *
 * Orientation at start/dest are not considered.
 *
 * @param[in] start Start point.
 * @param[in] dest  Destination point.
 */
inline route::FullRoute planRoute(const point::ParaPoint &start, const point::ParaPoint &dest)
{
  return planRoute(createRoutingPoint(start), createRoutingPoint(dest));
}

/** @brief Calculates route between two points.
 *
 * Orientation at dest is not considered.
 *
* @param[in] start Start point.
* @param[in] startHeading Heading at start point.
* @param[in] dest  Destination point.
*/
inline route::FullRoute
planRoute(const point::ParaPoint &start, point::ENUHeading const &startHeading, const point::ParaPoint &dest)
{
  return planRoute(createRoutingPoint(start, startHeading), createRoutingPoint(dest));
}

/** @brief Calculates route between two points.
* @param[in] start Start point.
* @param[in] startHeading Heading at start point.
* @param[in] dest  Destination point.
* @param[in] destHeading Heading at dest point.
*/
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const point::ParaPoint &dest,
                                  point::ENUHeading const &destHeading)
{
  return planRoute(createRoutingPoint(start, startHeading), createRoutingPoint(dest, destHeading));
}

/** @brief Calculates route between two points.
  * @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
  * @param[in] dest  Destination point as geo point.
  */
route::FullRoute planRoute(const RoutingParaPoint &start, const point::GeoPoint &dest);

/** @brief Calculates route between two points.
  * @param[in] start Start point as RoutingParaPoint (Be aware: routing direction in respect to lane orientation!).
  * @param[in] dest  Destination point as ENU point.
  */
route::FullRoute planRoute(const RoutingParaPoint &start, const point::ENUPoint &dest);

/** @brief Calculates route between two points.
  * @param[in] start Start point.
  * @param[in] dest  Destination point as geo point.
  */
inline route::FullRoute planRoute(const point::ParaPoint &start, const point::GeoPoint &dest)
{
  return planRoute(createRoutingPoint(start), dest);
}

/** @brief Calculates route between two points.
  * @param[in] start Start point.
  * @param[in] startHeading Heading at start point.
  * @param[in] dest  Destination point as geo point.
  */
inline route::FullRoute
planRoute(const point::ParaPoint &start, point::ENUHeading const &startHeading, const point::GeoPoint &dest)
{
  return planRoute(createRoutingPoint(start, startHeading), dest);
}

/** @brief Calculates route between two points.
  * @param[in] start Start point.
  * @param[in] dest  Destination point as point of interest.
  */
inline FullRoute planRoute(const point::ParaPoint &start, const config::PointOfInterest &dest)
{
  return planRoute(start, dest.geoPoint);
}

/** @brief Calculates route between two points considering supporting points on the way.
  * @param[in] start Start point.
 * @param[in] dest Vector with supporting points as geo points to be visited on the route. Last point in the list is the
 * actual destination point.
 *
 * Be aware: Supporting points providing multiple map maptched positions (i.e. the ones located within intersections)
 * are discarded to ensure the proper route is taken.
 */
FullRoute planRoute(const RoutingParaPoint &start, const std::vector<point::GeoPoint> &dest);

/**
 * @brief Calculates route between two points considering supporting points on the way
 * @param[in] start Start point.
 * @param[in] dest Vector with supporting points to be visited on the route. Last point in the list is the actual
 * destination point.
 */
FullRoute planRoute(const RoutingParaPoint &start, std::vector<RoutingParaPoint> const &dest);

/** @brief Calculates route between two points considering supporting points on the way.
  * @param[in] start Start point.
  * @param[in] startHeading Heading at start point.
 * @param[in] dest Vector with supporting points as geo points to be visited on the route. Last point in the list is the
 * actual destination point.
  */
inline route::FullRoute planRoute(const point::ParaPoint &start,
                                  point::ENUHeading const &startHeading,
                                  const std::vector<point::GeoPoint> &dest)
{
  return planRoute(createRoutingPoint(start, startHeading), dest);
}

/**
 * @brief perform route based prediction restricted by the prediction duration.
 *
 * @param[in] start start point.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 *
 * @return vector with all possible predicted routes.
 */
std::vector<route::FullRoute> predictRoutesOnDuration(const RoutingParaPoint &start,
                                                      physics::Duration const &predictionDuration);

/**
 * @brief perform route based prediction restricted by the prediction distance.
 *
 * @param[in] start start point.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 *
 * @return vector with all possible predicted routes.
 */
std::vector<route::FullRoute> predictRoutesOnDistance(const RoutingParaPoint &start,
                                                      physics::Distance const &predictionDistance);

/**
 * @brief perform route based prediction restricted by the prediction distance and duration.
 *
 * @param[in] start start point.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 *
 * @return vector with all possible predicted routes.
 */
std::vector<route::FullRoute> predictRoutes(const RoutingParaPoint &start,
                                            physics::Distance const &predictionDistance,
                                            physics::Duration const &predictionDuration);

/**
 * @brief perform route based prediction restricted by the prediction duration.
 *
 * @param[in] start start point as map matched bounding box.
 * @param[in] predictionDuration duration when the prediction can be stopped.
 *
 * @return vector with all possible predicted routes.
 */
std::vector<route::FullRoute> predictRoutesOnDuration(const match::MapMatchedObjectBoundingBox &start,
                                                      physics::Duration const &predictionDuration);

/**
 * @brief perform route based prediction restricted by the prediction distance.
 *
 * @param[in] start start point as map matched bounding box.
 * @param[in] predictionDistance distance when the prediction can be stopped.
 *
 * @return vector with all possible predicted routes.
 */
std::vector<route::FullRoute> predictRoutesOnDistance(const match::MapMatchedObjectBoundingBox &start,
                                                      physics::Distance const &predictionDistance);

/**
 * @brief Calculate the connecting route between the the two objects
 *
 * The heading of the object at start is respected on route planning, the heading of the object at the destination is
 * ignored.
 * For route calculations the route type core::Route::Type::SHORTEST_IGNORE_DIRECTION is used.
 * The returned connecting route only contains the direct predecessor and successor lanes of the raw route.
 * Neighbor lanes not being relevant for the two objects are not provided.
 *
 * @param[in] startObject object at starting position
 * @param[in] destObject object at destination position
 */
ConnectingRoute calculateConnectingRoute(const match::MapMatchedObjectBoundingBox &startObject,
                                         const match::MapMatchedObjectBoundingBox &destObject);

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
