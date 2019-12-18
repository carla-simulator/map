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
 * @brief This struct provides methods to perform a cubic spline interpolation for a set of 2D points
 *
 *        Usage: 1. CubicSpline cSpline;
 *               2. cSpline.knotPoints = <list of points>
 *               3. cSpline.interpolationDistance = <value>
 *               4. cSpline.interpolate();
 */
struct CubicSpline
{
  /**
   * List of knot points that the cubic spline has to go through
   */
  std::vector<Point2d> knotPoints;

  /**
   * List of interpolated points using the cubic spline and the \sa interpolationDistance
   */
  std::vector<Point2d> interpolatedPoints;

  /**
   * Distance along x-axis used for interpolation
   */
  double interpolationDistance{0.};

  /**
   * @brief Perform cubic spline interpolation on \sa knotPoints and filling \sa interpolatedPoints
   * @param[in] linearAlongXAxis  If set to true, interpolated points will be calculated by walking along the x-Axis
   *                              with stepsize \a interpolatedPoints
   * @return true on success, false on failure
   */
  bool interpolate(bool linearAlongXAxis = false);
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
