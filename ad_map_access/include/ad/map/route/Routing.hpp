// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <set>
#include "ad/map/point/ParaPointOperation.hpp"
#include "ad/map/route/planning/RoutingParaPointList.hpp"

/**
 * @brief Standard comparison operator.
 * @returns True if this objects can be taken as smaller than the other.
 */
inline bool operator<(const ::ad::map::route::planning::RoutingParaPoint &left,
                      const ::ad::map::route::planning::RoutingParaPoint &right)
{
  if (left.direction == right.direction)
  {
    return left.point < right.point;
  }
  return left.direction < right.direction;
}

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
 * @brief Comparison struct for RoutingParaPoint usage in std::map/set.
 */
struct RoutingParaPointCompare
{
  bool operator()(const RoutingParaPoint &left, const RoutingParaPoint &right) const
  {
    return left < right;
  }
};

/**
 * @brief create a RoutingParaPoint
 *
 * @param[in] lane_id  the lane id
 * @param[in] parametric_offset the parametric offset
 * @param[in] routingDirection the routing direction in respect to the lane orientation
 *   Be aware: this might be different from the nominal driving direction!
 */
inline RoutingParaPoint createRoutingParaPoint(lane::LaneId const &lane_id,
                                               physics::ParametricValue const &parametric_offset,
                                               RoutingDirection const &routingDirection = RoutingDirection::DONT_CARE)
{
  RoutingParaPoint routingPoint;
  routingPoint.point.lane_id = lane_id;
  routingPoint.point.parametric_offset = parametric_offset;
  routingPoint.direction = routingDirection;
  return routingPoint;
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
