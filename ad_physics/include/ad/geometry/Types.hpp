// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

/**
 * @file
 */

#pragma once

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <sstream>
#include "ad/geometry/HeadingRange.hpp"
#include "ad/geometry/HeadingRangeVector.hpp"
#include "ad/physics/AngleOperation.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/Distance2D.hpp"
#include "ad/physics/Distance2DList.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace geometry
 */
namespace geometry {

// Basic types
typedef boost::geometry::model::d2::point_xy<double> Point;
typedef std::vector<Point> PointVector;
typedef boost::geometry::model::linestring<Point> Line;
typedef std::vector<Line> LineVector;
typedef boost::geometry::model::polygon<Point, false> Polygon; // counterclockwise
typedef std::vector<Polygon> PolygonVector;
typedef boost::geometry::model::multi_point<Point> MultiPoint;
typedef std::vector<MultiPoint> MultiPointVector;

/**
 * @brief create a Point from a Distance2D
 *
 * @param[in] distance distance to convert
 *
 * @returns point
 */
inline Point toPoint(physics::Distance2D const &distance)
{
  return Point(distance.x.mDistance, distance.y.mDistance);
}

/**
 * @brief create a Point from two Distance components
 *
 * @param[in] distanceX x component of type Distance
 * @param[in] distanceY y component of type Distance
 *
 * @returns point
 */
inline Point toPoint(physics::Distance const &distanceX, physics::Distance const &distanceY)
{
  return Point(distanceX.mDistance, distanceY.mDistance);
}

/**
 * @brief create a Point from two double components
 *
 * @param[in] coordinateX x component of type double
 * @param[in] coordinateY y component of type double
 *
 * @returns point
 */
inline Point toPoint(double const &coordinateX, double const &coordinateY)
{
  return Point(coordinateX, coordinateY);
}

/**
 * @brief convert a Point to a Distance2D
 *
 * @param[in] point point to convert
 *
 * @returns distance
 */
inline physics::Distance2D toDistance(Point const &point)
{
  physics::Distance2D distance;
  distance.x = physics::Distance(point.x());
  distance.y = physics::Distance(point.y());
  return distance;
}

} // namespace geometry
} // namespace ad

namespace boost {
namespace geometry {
namespace model {
namespace d2 {

/*!
 * @brief Point operation: vector addition
 *
 * @param[in] a point a
 * @param[in] b point b
 *
 * @returns c = a + b
 */
inline ad::geometry::Point operator+(ad::geometry::Point const &a, ad::geometry::Point const &b)
{
  auto result = a;
  boost::geometry::add_point(result, b);
  return result;
}

/*!
 * @brief Point operation: vector subtraction
 *
 * @param[in] a point a
 * @param[in] b point b
 *
 * @returns c = a - b
 */
inline ad::geometry::Point operator-(ad::geometry::Point const &a, ad::geometry::Point const &b)
{
  auto result = a;
  boost::geometry::subtract_point(result, b);
  return result;
}

/*!
 * @brief comparison operation: Point
 *
 * @param[in] a point a
 * @param[in] b point b
 *
 * @returns a == b
 */
inline bool operator==(ad::geometry::Point const &a, ad::geometry::Point const &b)
{
  return (std::abs(a.x() - b.x()) <= std::numeric_limits<double>::epsilon())
    && (std::abs(a.y() - b.y()) <= std::numeric_limits<double>::epsilon());
}

/*!
 * @brief comparison operation: Points not equal
 *
 * @param[in] a point a
 * @param[in] b point b
 *
 * @returns a != b
 */
inline bool operator!=(ad::geometry::Point const &a, ad::geometry::Point const &b)
{
  return !(a == b);
}

} // namespace d2

/*!
 * @brief comparison operation: Polygon
 *
 * @param[in] a polygon a
 * @param[in] b polygon b
 *
 * @returns a == b
 */
inline bool operator==(ad::geometry::Polygon const &a, ad::geometry::Polygon const &b)
{
  if (a.outer().size() != b.outer().size())
  {
    return false;
  }
  for (size_t i = 0u; i < a.outer().size(); ++i)
  {
    if (a.outer()[i] != b.outer()[i])
    {
      return false;
    }
  }
  return true;
}

/*!
 * @brief comparison operation: Polygons not equal
 *
 * @param[in] a polygon a
 * @param[in] b polygon b
 *
 * @returns a != b
 */
inline bool operator!=(ad::geometry::Polygon const &a, ad::geometry::Polygon const &b)
{
  return !(a == b);
}

/*!
 * @brief comparison operation: less on Point type
 *
 * Mainly required for creation of stable std containers.
 *
 * @param[in] a point a
 * @param[in] b point b
 *
 * @returns a < b
 */
inline bool operator<(ad::geometry::Point const &a, ad::geometry::Point const &b)
{
  if (a == b)
  {
    return false;
  }
  else if (std::abs(a.x() - b.x()) > std::numeric_limits<double>::epsilon())
  {
    return a.x() < b.x();
  }
  else
  {
    return a.y() < b.y();
  }
}

/*!
 * @brief comparison operation: less on Polygon type
 *
 * Mainly required for creation of stable std containers.
 *
 * @param[in] a polygon a
 * @param[in] b polygon b
 *
 * @returns a < b
 */
inline bool operator<(ad::geometry::Polygon const &a, ad::geometry::Polygon const &b)
{
  if (a.outer().size() == b.outer().size())
  {
    for (size_t i = 0u; i < a.outer().size(); ++i)
    {
      if (a.outer()[i] != b.outer()[i])
      {
        return a.outer()[i] < b.outer()[i];
      }
    }
  }
  else
  {
    return a.outer().size() < b.outer().size();
  }
  return false;
}

} // namespace model
} // namespace geometry
} // namespace boost

namespace std {

/*!
 * @brief to_string overload for Point
 *
 * @param[in] value a point
 *
 * @returns string describing point
 */
inline std::string to_string(ad::geometry::Point const &value)
{
  std::stringstream stream;
  stream << "[" << value.x() << "," << value.y() << "]";
  return stream.str();
}

/*!
 * @brief to_string overload for Polygon
 *
 * @param[in] value a polygon
 *
 * @returns string describing polygon
 */
inline std::string to_string(ad::geometry::Polygon const &value)
{
  std::stringstream stream;
  stream << "[";
  for (auto pt : value.outer())
  {
    stream << std::to_string(pt) << ",";
  }
  stream << "]";
  return stream.str();
}

/*!
 * @brief to_string overload for PolygonVector
 *
 * @param[in] value a polygon vector
 *
 * @returns string describing polygon vector
 */
inline std::string to_string(ad::geometry::PolygonVector const &value)
{
  std::stringstream stream;
  stream << "[";
  for (auto polygon : value)
  {
    stream << std::to_string(polygon) << ",";
  }
  stream << "]";
  return stream.str();
}

/*!
 * @brief to_string overload for Line
 *
 * @param[in] value a line
 *
 * @returns string describing line
 */
inline std::string to_string(ad::geometry::Line value)
{
  std::stringstream stream;
  stream << "[";
  for (auto pt : value)
  {
    stream << "[" << pt.x() << "," << pt.y() << "],";
  }
  stream << "]";
  return stream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::geometry::Point> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::geometry::Point const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::geometry::Polygon> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::geometry::Polygon const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::geometry::PolygonVector> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::geometry::PolygonVector const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::geometry::Line> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::geometry::Line const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};
