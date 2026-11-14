// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Clothoid.hpp"
#include <algorithm>
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

bool Clothoid::interpolate(double startRadius, double endRadius, double startAngle, double endAngle)
{
  if ((interpolationStep < 0.001) || (startRadius <= 0.) || (endRadius <= 0.))
  {
    return false;
  }

  interpolatedPoints.clear();

  // calculate the clothoid traversing parameter
  double const deltaAngle = endAngle - startAngle;
  if (std::abs(deltaAngle) < 1e-9)
  {
    return false;
  }
  double const lambda = (deltaAngle < 0.) ? -1. : 1.;

  // Linearly varying curvature along forward arc-length sigma in [0, totalLength]:
  //   k(sigma) = lambda * (k1 + ((k2 - k1) / totalLength) * sigma)
  //   totalLength = 2 * |deltaAngle| / (k1 + k2)
  // This handles tightening (startRadius > endRadius), opening (startRadius < endRadius),
  // and constant-curvature (startRadius == endRadius) arcs identically without division by zero.
  double const k1 = 1. / startRadius;
  double const k2 = 1. / endRadius;
  double const totalLength = (2. * std::abs(deltaAngle)) / (k1 + k2);
  double const curvatureSlope = (k2 - k1) / totalLength;

  Point2d current = origin;
  interpolatedPoints.push_back(current);

  double sigma = 0.;
  while (sigma < totalLength - 1e-9)
  {
    double const step = std::min(interpolationStep, totalLength - sigma);
    double const argument = startAngle + lambda * (k1 * sigma + 0.5 * curvatureSlope * sigma * sigma);
    current.x += step * std::cos(argument);
    current.y += step * std::sin(argument);
    interpolatedPoints.push_back(current);
    sigma += step;
  }

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
