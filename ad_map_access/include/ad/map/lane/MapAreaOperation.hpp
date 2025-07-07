// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/lane/Types.hpp"
#include "ad/map/point/Types.hpp"
#include "ad/map/route/Planning.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace lane */
namespace lane {

/**
 * @brief retrieve the lanes of a map area from a bounding sphere
 *
 * This function collects all lanes within the given bounding sphere in a LaneIdSet
 * to consider for further map operations.
 * For collecting the lanes ::ad::map::lane::isNear() is called that checks for overlapping
 * of the bounding sphere of the lane and the given bounding sphere.
 *
 * @param[in] bounding_sphere the bounding sphere of the map area to be considered
 *
 * @returns lane ids of the map area
 */
LaneIdSet getLanesOfMapArea(::ad::map::point::BoundingSphere const &bounding_sphere);

/**
 * @brief definition of a prediction start point including the required prediction parameters
 * to be used for this start point
 */
struct MapAreaPredictionStartPoint
{
  ::ad::map::route::planning::RoutingParaPoint prediction_start;
  ::ad::physics::Distance prediction_distance;
  ::ad::map::route::RouteCreationMode route_creation_mode;
};

/*!
 * @brief retrieve the lanes of a map area from a set of reachable lanes
 *
 * This function collects all reachable lanes from the given list of input PredictionStartPoint
 * to consider for all map operations.
 *
 * @param[in] predictionStartPoints the start points used to perform route prediction
 * with respective prediction distance and route creation mode
 *
 * @returns lane ids of the map area
 */
LaneIdSet getLanesOfMapArea(std::vector<MapAreaPredictionStartPoint> const &predictionStartPoints);

/**
 * @brief restriction of the map area around an intersection to a set of reachable lanes
 *
 * This function collects all reachable lanes from the intersection at the given intersectionPoint
 * to consider for all map operations.
 * Reachable in the sense of all inner intersection lanes plus all entry/exit arms of the intersection
 * until the given intersectionDistance is reached.
 *
 * @param[in] intersectionPoint the start points used to check for an intersection to be used
 * @param[in] intersectionDistance distance to be used for a directionless prediction from
 *            all intersection border points
 *
 * @returns lane ids of the map area
 */
LaneIdSet getLanesOfMapArea(::ad::map::point::ENUPoint const &intersectionPoint,
                            ::ad::physics::Distance const &intersectionDistance);

} // namespace lane
} // namespace map
} // namespace ad
