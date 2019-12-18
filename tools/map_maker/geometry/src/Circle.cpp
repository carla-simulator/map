// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Circle.hpp"
#include <cmath>
#include "ad/map/maker/geometry/Direction2d.hpp"

namespace ad {
namespace map {
namespace maker {
namespace geometry {

bool Circle::interpolate(double const from, double delta, bool const counterClockwise)
{
  if (interpolationStep < 0.001)
  {
    return false;
  }

  if (delta < 0.)
  {
    return false;
  }

  if (radius <= 0)
  {
    return false;
  }

  interpolatedPoints.clear();
  if (delta > 2 * M_PI) // limit delta to 2 PI
  {
    delta = 2 * M_PI;
  }

  // the increment of the angle for the interpolation
  // rationale: full circle has 2*PI*r = 360 deg ( = 2 * PI rad)
  //                                 r = 1 rad
  //                 interpolationStep = (interpolationStep / r) rad
  double increment = interpolationStep / radius;
  if (counterClockwise)
  {
    double to = from + delta;
    Direction2d angle{from};
    for (; angle.orientation < to; angle.orientation += increment)
    {
      interpolatedPoints.push_back(angle.movePoint(origin, radius));
    }
    angle.orientation = to;
    interpolatedPoints.push_back(angle.movePoint(origin, radius));
  }
  else
  {
    double to = from - delta;
    Direction2d angle{from};
    for (; angle.orientation > to; angle.orientation -= increment)
    {
      interpolatedPoints.push_back(angle.movePoint(origin, radius));
    }
    angle.orientation = to;
    interpolatedPoints.push_back(angle.movePoint(origin, radius));
  }

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
