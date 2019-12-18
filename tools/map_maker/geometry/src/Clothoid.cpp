// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Clothoid.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

bool Clothoid::interpolate(double startRadius, double endRadius, double startAngle, double endAngle)
{
  if (interpolationStep < 0.001)
  {
    return false;
  }

  interpolatedPoints.clear();

  // calculate the clothoid traversing parameter
  double lambda{1.};
  double const deltaAngle = endAngle - startAngle;
  if (deltaAngle < 0.) // clothoid bend to right
  {
    lambda = -1.;
  }

  // clothoid parameters A = R*sqrt(2*deltAngle) in this case no zero curvature
  // radius if given and the fromula is different
  double const endRadiusSquared = endRadius * endRadius;
  double const startRadiusSquared = startRadius * startRadius;
  double const endStartRadiusProduct = endRadius * startRadius;
  double const endStartRadiusSubtracted = endRadiusSquared - startRadiusSquared;
  double const clothoidConstantA
    = endStartRadiusProduct * std::sqrt(2. * std::abs(deltaAngle / endStartRadiusSubtracted));
  double const clothoidConstantASquared = clothoidConstantA * clothoidConstantA;

  // length of clothoid till the starting point
  double const l1 = clothoidConstantASquared / startRadius;

  // length of clothoid till the end point
  double const l2 = clothoidConstantASquared / endRadius;

  // road5 reports l2 - l1 as its length ...
  // angle in the zero curviture (real begining of the clothoid)
  double const angle0 = startAngle - lambda * ((clothoidConstantASquared / 2) / startRadiusSquared);
  // numerically estimating by Euler's method
  Point2d current{};
  for (double currLen = l1; currLen < l2; currLen += interpolationStep)
  {
    double const snA = currLen / clothoidConstantA;
    double const snASquared = snA * snA;
    double const argument = lambda / 2 * snASquared + angle0;
    current.x = current.x + interpolationStep * cos(argument);
    current.y = current.y + interpolationStep * sin(argument);
    interpolatedPoints.push_back(current);
  }
  double const snA = l2 / clothoidConstantA;
  double const snASquared = snA * snA;
  double const argument = lambda / 2 * snASquared + angle0;
  current.x = current.x + interpolationStep * cos(argument);
  current.y = current.y + interpolationStep * sin(argument);
  interpolatedPoints.push_back(current);

  // and finally move points to correct location
  Point2d translation = origin - interpolatedPoints[0];
  for (Point2d &p : interpolatedPoints)
  {
    p += translation;
  }
  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
