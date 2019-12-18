// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/ArithmeticHelpers.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

vec2d::vec2d(double x_, double y_)
  : x(x_)
  , y(y_)
{
}

vec2d::vec2d(Point const &first, Point const &second)
  : vec2d(second.x - first.x, second.y - first.y)
{
}

vec2d::vec2d(double const len, double const suv1x, double const suv1y)
  : vec2d(len * suv1y, len * suv1x)
{
}

double vec2d::length() const
{
  return std::sqrt(x * x + y * y);
}

void vec2d::scale(double const factor)
{
  x *= factor;
  y *= factor;
}

void vec2d::normalize()
{
  const double len = length();
  x /= len;
  y /= len;
}

std::string vec2d::toString() const
{
  return std::string{"["} + std::to_string(x) + std::string{","} + std::to_string(y) + std::string{"]"};
}

std::ostream &operator<<(std::ostream &out, vec2d const &v)
{
  return out << v.toString();
}

vec2d const xVersor()
{
  return vec2d{1., 0.};
}

vec2d const yVersor()
{
  return vec2d{0., 1.};
}

double cross_product(vec2d const &u, vec2d const &v)
{
  return (u.x * v.y - u.y * v.x);
}

double dot_product(vec2d const &u, vec2d const &v)
{
  return (u.x * v.x + u.y * v.y);
}

double angle(vec2d const &u, vec2d const &v)
{
  auto const arg = dot_product(u, v) / (u.length() * v.length());
  if (std::fabs(arg - 1.0) <= 10e-6)
  {
    return 0.0;
  }
  else if (std::fabs(arg + 1.0) <= 10e-6)
  {
    return M_PI;
  }
  else
  {
    return std::acos(arg);
  }
}

double directedAngle(vec2d const &u, vec2d const &v)
{
  auto a = std::atan2(cross_product(u, v), dot_product(u, v));
  return a;
}

double directedAngle(Point const &a, Point const &b)
{
  return std::atan2((b.y - a.y), (b.x - a.x));
}

vec2d rotated90Vector(vec2d const &v, Side const side, double const len)
{
  if (!std::isnormal(v.length()))
  {
    throw std::logic_error{std::string{"rotated90Vector() error, invalid vector passed: "} + v.toString()};
  }

  vec2d result = v;
  result.normalize();
  result.scale(len);

  if (side == Side::LEFT)
  {
    rotate90CounterClockwise(result);
  }
  else if (side == Side::RIGHT)
  {
    rotate90Clockwise(result);
  }

  return result;
}

vec2d bisectingVector(vec2d const &u, vec2d const &v, double const len)
{
  return bisectingVector(u, v, Side::RIGHT, len);
}

vec2d bisectingVector(vec2d const &u, vec2d const &v, Side const side, double const len)
{
  if (!std::isnormal(u.length()) || !std::isnormal(v.length()))
  {
    throw std::invalid_argument{std::string{"bisectingVector() error, invalid vector passed: "} + v.toString()};
  }

  auto const theta = angle(u, v) / 2.;
  auto const turn = (cross_product(u, v) > 0) ? 1 : -1;
  auto bisectingVector = u;

  bisectingVector.normalize();
  bisectingVector.scale(len + std::tan(theta) * len / 2.0);

  if (side == Side::LEFT)
  {
    rotate(M_PI_2 + theta * turn, bisectingVector);
  }
  else if (side == Side::RIGHT)
  {
    rotate(-M_PI_2 + theta * turn, bisectingVector);
  }

  if (!std::isnormal(bisectingVector.x) || !std::isnormal(bisectingVector.y))
  {
    throw std::logic_error{"bisectingVector() error, resulting vector is NaN"};
  }

  return bisectingVector;
}

void rotate90CounterClockwise(vec2d &v)
{
  double const old_x = v.x;
  v.x = -v.y;
  v.y = old_x;
}

void rotate90Clockwise(vec2d &v)
{
  double const old_x = v.x;
  v.x = v.y;
  v.y = -old_x;
}

void rotate180(vec2d &v)
{
  v.x = -v.x;
  v.y = -v.y;
}

void rotate(double theta, vec2d &v)
{
  auto newX = std::cos(theta) * v.x - sin(theta) * v.y;
  auto newY = std::sin(theta) * v.x + cos(theta) * v.y;
  v.x = newX;
  v.y = newY;
}

void move(vec2d const &offset, Point &pt)
{
  pt.x += offset.x;
  pt.y += offset.y;
}

Point rotated(Point const &origin, double theta, Point const &pt)
{
  Point newPt = pt;

  newPt.x = std::cos(theta) * (pt.x - origin.x) - std::sin(theta) * (pt.y - origin.y) + origin.x;
  newPt.y = std::sin(theta) * (pt.x - origin.x) + std::cos(theta) * (pt.y - origin.y) + origin.y;

  return newPt;
}

double distance(Point const &p1, Point const &p2)
{
  return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

vec2d rotated90OffsetVector(Point const &first, Point const &second, double const len, Side const side)
{
  vec2d const this_vector = vec2d(first, second);
  vec2d offset_vector = vec2d(first, second);
  offset_vector.normalize();
  offset_vector.scale(len);
  rotate90Clockwise(offset_vector);

  double const direction = cross_product(this_vector, offset_vector);

  if (side == Side::LEFT && (direction < 0))
  {
    rotate180(offset_vector);
  }
  else if (side == Side::RIGHT && (direction > 0))
  {
    rotate180(offset_vector);
  }

  return offset_vector;
}

straight2d lineCoefs(Point const &first, Point const &second)
{
  return straight2d{first.y - second.y, second.x - first.x, first.x * second.y - second.x * first.y};
}

straight2d parallelShiftedLineCoefs(Point first, Point second, double const laneWidth, Side const side)
{
  vec2d const offset_vector = rotated90OffsetVector(first, second, laneWidth, side);

  move(offset_vector, first);
  move(offset_vector, second);

  return lineCoefs(first, second);
}

void move(vec2d const &offset, straight2d &straight)
{
  straight.C = (-straight.B) * offset.x + straight.C + offset.y;
}

bool haveCrossingPoint(straight2d first, straight2d second)
{
  return ((first.A * second.B - second.A * first.B) != 0.0);
}

Point crossingPoint(straight2d first, straight2d second)
{
  double const W = first.A * second.B - second.A * first.B;
  double const Wx = second.C * first.B - first.C * second.B;
  double const Wy = second.A * first.C - first.A * second.C;

  if (W == 0.0)
  {
    throw std::runtime_error{"geometry::crossingPoint(): No crossing point for given straights"};
  }

  auto point = Point{};
  point.x = Wx / W;
  point.y = Wy / W;

  return point;
}

Point closerCrossingPoint(Point const &p1, Point const &p2, circle2d const &c)
{
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;

  double A = dx * dx + dy * dy;
  double B = 2 * (dx * (p1.x - c.center.x) + dy * (p1.y - c.center.y));

  double C
    = (p1.x - c.center.x) * (p1.x - c.center.x) + (p1.y - c.center.y) * (p1.y - c.center.y) - c.radius * c.radius;

  double det = B * B - 4 * A * C;

  if (A < 0.0000001 || det < 0)
  {
    throw std::runtime_error{"closerCrossingPoint() - no crossing point found"};
  }
  else if (det == 0)
  {
    double t = -B / (2 * A);
    return Point{NAN, NAN, p1.x + t * dx, p1.y + t * dy, 0.0};
  }
  else
  {
    double t = ((-B + std::sqrt(det)) / (2 * A));
    return Point{NAN, NAN, p1.x + t * dx, p1.y + t * dy, 0.0};
  }
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
