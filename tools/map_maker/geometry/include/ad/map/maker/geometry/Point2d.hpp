// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ostream>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

struct Point2d
{
  Point2d() = default;

  explicit Point2d(double _x, double _y);

  double x{};
  double y{};

  Point2d operator+(Point2d const &other) const;
  Point2d operator*(double const factor) const;
  Point2d operator-(Point2d const &other) const;
  Point2d &operator*=(double const &scalar);
  Point2d &operator+=(Point2d const &other);

  bool operator==(Point2d const &other) const
  {
    return ((x == other.x) && (y == other.y));
  }

  bool operator!=(Point2d const &other) const
  {
    return ((x != other.x) || (y != other.y));
  }

  double norm() const;
  double squaredDistance(Point2d const &other) const;
};

Point2d operator*(double const factor, Point2d const &point);
std::ostream &operator<<(std::ostream &out, Point2d const &p);

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
