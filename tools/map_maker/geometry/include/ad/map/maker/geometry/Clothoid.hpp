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
 * @brief This struct provides a method to perform an interpolation for a clothoid
 *
 *        Usage: 1. Clothoid clothoid;
 *               2. clothoid.origin = <point>
 *               3. clothoid.interpolationDistance = <value>
 *
 * Implementation after:
 * The Clothoid Computation: A Simple and Efficient Numerical Algorithm
 * Url: https://www.researchgate.net/publication/292669884
 */
struct Clothoid
{
  Point2d origin{};             //!< start position clothoid
  double interpolationStep{0.}; //!< arc length between two interpolated points

  /**
   * List of interpolated points using the clothoid and the \sa interpolationDistance
   */
  std::vector<Point2d> interpolatedPoints;

  /**
   * @brief Perform circular interpolation and fill \sa interpolatedPoints
   *
   * Interpolation starts with angle \param startAngle [radians] and ends with angle \param endAngle [radians]
   * Uses radii startRadius, endRadius for the requested "bending". Use an endAngle greater than startAngle
   * to have bending to the left
   *
   * @return true on success, false on failure (interpolation step too small)
   */
  bool interpolate(double startRadius, double endRadius, double startAngle, double endAngle);
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
