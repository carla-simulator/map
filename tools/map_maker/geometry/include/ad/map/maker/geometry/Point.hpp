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

struct Point
{
  Point() = default;

  explicit Point(double lat, double lon, double x, double y, double z);
  explicit Point(double x, double y, double z);

  double latitude{};
  double longitude{};
  double x{};
  double y{};
  double z{};

  Point operator+(Point const &other) const;

  Point operator*(double const factor) const;

  Point operator-(Point const &other) const;

  Point &operator*=(double const &scalar);

  constexpr bool operator==(Point const &other) const
  {
    return (this->x == other.x && this->y == other.y && this->z == other.z);
  }

  bool operator!=(Point const &other);
};

// really needed?
std::ostream &operator<<(std::ostream &out, Point const &p);

Point operator*(double const &scalar, Point const &p);

extern double squaredDistance(Point const &a, Point const &b);

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
