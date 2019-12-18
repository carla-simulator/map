// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/QuadraticBezier.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

bool QuadraticBezier::interpolate()
{
  if (interpolationDistance < 0.001)
  {
    return false;
  }

  if ((weights.size() != 3) || (controlPoints.size() != 3))
  {
    return false;
  }

  interpolatedPoints.clear();

  for (double t = 0.; t <= 1.; t += interpolationDistance)
  {
    // Bernstein polynomials
    const double b0 = (1 - t) * (1 - t);
    const double b1 = 2 * t * (1 - t);
    const double b2 = t * t;

    double denominator = weights[0] * b0 + weights[1] * b1 + weights[2] * b2;

    if (denominator == 0.)
    {
      return false;
    }

    denominator = 1. / denominator;

    Point2d nominator
      = controlPoints[0] * weights[0] * b0 + controlPoints[1] * weights[1] * b1 + controlPoints[2] * weights[2] * b2;
    interpolatedPoints.push_back(nominator * denominator);
  }

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
