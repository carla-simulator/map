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

  auto const evaluatePoint = [&](double const t, Point2d &outPoint) -> bool {
    double const oneMinusT = 1. - t;
    double const b0 = oneMinusT * oneMinusT;
    double const b1 = 2. * t * oneMinusT;
    double const b2 = t * t;

    double const denominator = weights[0] * b0 + weights[1] * b1 + weights[2] * b2;
    if (denominator == 0.)
    {
      return false;
    }

    Point2d const nominator
      = controlPoints[0] * weights[0] * b0 + controlPoints[1] * weights[1] * b1 + controlPoints[2] * weights[2] * b2;
    outPoint = nominator * (1. / denominator);
    return true;
  };

  double lastT = 0.;
  for (double t = 0.; t <= 1.; t += interpolationDistance)
  {
    Point2d pt;
    if (!evaluatePoint(t, pt))
    {
      return false;
    }
    interpolatedPoints.push_back(pt);
    lastT = t;
  }

  if (1. - lastT > 1e-9)
  {
    Point2d endPt;
    if (!evaluatePoint(1., endPt))
    {
      return false;
    }
    interpolatedPoints.push_back(endPt);
  }

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
