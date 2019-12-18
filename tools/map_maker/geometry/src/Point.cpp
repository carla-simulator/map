// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Point.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

Point::Point(double lat, double lon, double x_, double y_, double z_)
  : latitude(lat)
  , longitude(lon)
  , x(x_)
  , y(y_)
  , z(z_)
{
}

Point::Point(double x_, double y_, double z_)
  : Point(0.0, 0.0, x_, y_, z_)
{
}

Point Point::operator+(Point const &other) const
{
  Point result = *this;
  result.x += other.x;
  result.y += other.y;
  result.z += other.z;
  return result;
}

Point Point::operator*(double const factor) const
{
  Point result = *this;
  result.x *= factor;
  result.y *= factor;
  result.z *= factor;
  return result;
}

Point Point::operator-(Point const &other) const
{
  Point result = *this;
  result.x -= other.x;
  result.y -= other.y;
  result.z -= other.z;
  return result;
}

Point &Point::operator*=(double const &scalar)
{
  *this = *this * scalar;
  return *this;
}

bool Point::operator!=(Point const &other)
{
  return !(*this == other);
}

Point operator*(double const &scalar, Point const &p)
{
  Point res = p * scalar;
  return res;
}

std::ostream &operator<<(std::ostream &out, Point const &p)
{
  return out << "[" << p.longitude << "," << p.latitude << "] -> [" << p.x << "," << p.y << "," << p.z << "]";
}

double squaredDistance(Point const &a, Point const &b)
{
  double const xSquare = (a.x - b.x) * (a.x - b.x);
  double const ySquare = (a.y - b.y) * (a.y - b.y);
  return xSquare + ySquare;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
