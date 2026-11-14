// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Direction2d.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

Direction2d::Direction2d(double const _orientation)
  : orientation(normalizeAngle(_orientation))
{
}

Direction2d::Direction2d(Point2d const &point)
{
  orientation = normalizeAngle(atan2(point.y, point.x));
}

Direction2d::Direction2d(Point2d const &start, Point2d const &end)
{
  orientation = normalizeAngle(atan2((end.y - start.y), (end.x - start.x)));
}

Point2d Direction2d::orientationAsPoint() const
{
  return Point2d(cos(orientation), sin(orientation));
}

Point2d Direction2d::movePoint(Point2d const &point, double const distance) const
{
  Point2d result = orientationAsPoint();
  result *= distance;
  result += point;
  return result;
}

Direction2d Direction2d::bisectionAngle(Direction2d const &other) const
{
  Point2d bisect = orientationAsPoint() + other.orientationAsPoint();
  Direction2d result(bisect);
  result.orientation = normalizeAngle(result.orientation + M_PI_2);
  return result;
}

void Direction2d::normalize()
{
  orientation = normalizeAngle(orientation);
}

double normalizeAngle(double orientation)
{
  if (!std::isfinite(orientation))
  {
    return 0.;
  }
  double const twoPi = 2. * M_PI;
  double result = std::fmod(orientation, twoPi);
  if (result < 0.)
  {
    result += twoPi;
  }
  return result;
}

double degToRad(double angle)
{
  return angle * M_PI / 180.;
}

double radToDeg(double angle)
{
  return angle * 180. / M_PI;
}

double minimumAngleDifference(double alpha, double beta)
{
  if (!std::isfinite(alpha) || !std::isfinite(beta))
  {
    return 0.;
  }
  double const twoPi = 2. * M_PI;
  double diff = std::fmod(alpha - beta, twoPi);
  if (diff > M_PI)
  {
    diff -= twoPi;
  }
  else if (diff <= -M_PI)
  {
    diff += twoPi;
  }
  return diff;
}

Point2d threePointShift(Point2d const &before, Point2d const &center, Point2d const &after, double const distance)
{
  const double minimumScaling = 0.01;
  const Direction2d directionBefore(before, center);
  const Direction2d directionAfter(center, after);
  const Direction2d shiftDirection = directionBefore.bisectionAngle(directionAfter);

  double scaling = std::max(sin(shiftDirection.orientation - directionBefore.orientation), minimumScaling);

  return shiftDirection.movePoint(center, distance / scaling);
}

Point2d twoPointShift(Point2d const &point, Point2d const &reference, double const distance)
{
  Direction2d shiftDirection = orthogonalDirection(reference, point);
  return shiftDirection.movePoint(point, distance);
}

Point2d orthogonalShift(Point2d const &point, double const orientation, double const distance)
{
  Direction2d shiftDirection(orientation + M_PI_2);
  return shiftDirection.movePoint(point, distance);
}

Direction2d orthogonalDirection(Point2d const &from, Point2d const &to)
{
  Direction2d result(from, to);
  result.orientation += M_PI_2;
  result.normalize();
  return result;
}

Direction2d bisectionAngle(Point2d const &before, Point2d const &center, Point2d const &after)
{
  Direction2d from(before, center);
  Direction2d to(center, after);
  return from.bisectionAngle(to);
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
