// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/maker/geometry/Point2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/**
 * @brief This struct provides methods to perform an interpolation for a circle
 *
 *        Usage: 1. Circle circle;
 *               2. circle.origin = <point>
 *               2. circle.radius = <radius>
 *               3. circle.interpolationDistance = <value>
 *               4. circle.interpolate(startAngle, endAngle);
 */
struct Circle
{
  /**
   * Origin of circle
   */
  Point2d origin{};
  double radius{1.};
  /**
   * Arc length used for interpolation
   */
  double interpolationStep{0.};

  /**
   * List of interpolated points using the circle and the \sa interpolationDistance
   */
  std::vector<Point2d> interpolatedPoints;

  /**
   * @brief Perform circular interpolation and fill \sa interpolatedPoints
   *
   * Interpolation start at \param from [radians] and ends at \param from + \param delta [radians]
   * Delta can be at most 2*PI.
   * Interpolation can be both clockwise and counter-clockwise
   * Independent of the interpolationDistance, the last point is always from + delta
   * @return true on success, false on failure
   */
  bool interpolate(double const from, double delta, bool const counterClockwise);
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
