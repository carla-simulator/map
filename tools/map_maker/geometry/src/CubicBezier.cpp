// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/CubicBezier.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

bool CubicBezier::interpolate()
{
  if (interpolationDistance < 0.001)
  {
    return false;
  }

  if ((weights.size() != 4) || (controlPoints.size() != 4))
  {
    return false;
  }

  interpolatedPoints.clear();

  for (double t = 0.; t <= 1.; t += interpolationDistance)
  {
    // Bernstein polynomials
    const double b0 = (1 - t) * (1 - t) * (1 - t);
    const double b1 = 3.0 * t * (1 - t) * (1 - t);
    const double b2 = 3.0 * t * t * (1 - t);
    const double b3 = t * t * t;

    double denominator = weights[0] * b0 + weights[1] * b1 + weights[2] * b2 + weights[3] * b3;

    if (denominator == 0.)
    {
      return false;
    }

    denominator = 1. / denominator;

    Point2d nominator = controlPoints[0] * weights[0] * b0 + controlPoints[1] * weights[1] * b1
      + controlPoints[2] * weights[2] * b2 + controlPoints[3] * weights[3] * b3;
    interpolatedPoints.push_back(nominator * denominator);
  }

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
