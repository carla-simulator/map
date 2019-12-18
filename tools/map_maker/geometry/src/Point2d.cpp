// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/Point2d.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

Point2d::Point2d(double _x, double _y)
  : x(_x)
  , y(_y)
{
}

Point2d Point2d::operator+(Point2d const &other) const
{
  Point2d result = *this;
  result.x += other.x;
  result.y += other.y;
  return result;
}

Point2d Point2d::operator-(Point2d const &other) const
{
  Point2d result = *this;
  result.x -= other.x;
  result.y -= other.y;
  return result;
}

Point2d Point2d::operator*(double const factor) const
{
  Point2d result = *this;
  result.x *= factor;
  result.y *= factor;
  return result;
}

Point2d &Point2d::operator*=(double const &scalar)
{
  x *= scalar;
  y *= scalar;
  return *this;
}

Point2d &Point2d::operator+=(Point2d const &other)
{
  x += other.x;
  y += other.y;
  return *this;
}

Point2d operator*(double const &scalar, Point2d const &p)
{
  Point2d res = p * scalar;
  return res;
}

double Point2d::norm() const
{
  return std::sqrt(x * x + y * y);
}

double Point2d::squaredDistance(Point2d const &other) const
{
  return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
}

Point2d operator*(double const factor, Point2d const &point)
{
  return point * factor;
}

std::ostream &operator<<(std::ostream &out, Point2d const &p)
{
  return out << "[" << p.x << ", " << p.y << "]";
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
