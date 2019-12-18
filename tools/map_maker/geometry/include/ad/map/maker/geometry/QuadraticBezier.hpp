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
 * @brief This struct provides methods to perform a quadratic bezier curve interpolation for a set of (exactly 3)
 *        2D points.
 *
 *        The first and last provided point are points the bezier curve will pass through, while the curve will only
 *        come close to the middle point. In order to change the distance between the curve and the middle point, the
 *        default weights of the bezier curve for each point may be adjusted. A weight > 1 for the middle control
 *        point will reduce the distance, a weight < 1 will increase the distance.
 *
 *
 *        Usage: 1. QuadraticBezier bezierCurve;
 *               2. bezierCurve.controlPoints = <list of points>
 *               3. bezierCurve.interpolationDistance = <value>
 *               4. bezierCurve.interpolate();
 */
struct QuadraticBezier
{
  /**
   * List of control points that describe the bezier curve
   * @note Exactly 3 control points are required
   */
  std::vector<Point2d> controlPoints;

  /**
   * Weights of the different control points
   */
  std::vector<double> weights = {1., 1., 1.};

  /**
   * List of interpolated points using the cubic spline and the interpolationDistance
   */
  std::vector<Point2d> interpolatedPoints;

  /**
   * Step width used for interpolation (on [0,1] interval)
   */
  double interpolationDistance{0.};

  /**
   * @brief Perform an interpolation along the quadratic bezier curve
   * @return true on success, false on failure
   */
  bool interpolate();
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
