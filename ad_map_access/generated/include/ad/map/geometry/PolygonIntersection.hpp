/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-2046
 */

#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include "ad/map/point/ENUPointListVector.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace geometry
 */
namespace geometry {

/*!
 * \brief DataType PolygonIntersection
 */
struct PolygonIntersection
{
  /*!
   * \brief Smart pointer on PolygonIntersection
   */
  typedef std::shared_ptr<PolygonIntersection> Ptr;

  /*!
   * \brief Smart pointer on constant PolygonIntersection
   */
  typedef std::shared_ptr<PolygonIntersection const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  PolygonIntersection() = default;

  /*!
   * \brief standard destructor
   */
  ~PolygonIntersection() = default;

  /*!
   * \brief standard copy constructor
   */
  PolygonIntersection(const PolygonIntersection &other) = default;

  /*!
   * \brief standard move constructor
   */
  PolygonIntersection(PolygonIntersection &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other PolygonIntersection
   *
   * \returns Reference to this PolygonIntersection.
   */
  PolygonIntersection &operator=(const PolygonIntersection &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other PolygonIntersection
   *
   * \returns Reference to this PolygonIntersection.
   */
  PolygonIntersection &operator=(PolygonIntersection &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other PolygonIntersection
   *
   * \returns \c true if both PolygonIntersection are equal
   */
  bool operator==(const PolygonIntersection &other) const
  {
    return (intersection_lines == other.intersection_lines) && (is_within == other.is_within);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other PolygonIntersection.
   *
   * \returns \c true if both PolygonIntersection are different
   */
  bool operator!=(const PolygonIntersection &other) const
  {
    return !operator==(other);
  }

  /*!
   * The lines of the intersection of the polygon.
   */
  ::ad::map::point::ENUPointListVector intersection_lines;

  /*!
   * The polygon is within the other.
   */
  bool is_within{false};
};

} // namespace geometry
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_GEOMETRY_POLYGONINTERSECTION
#define GEN_GUARD_AD_MAP_GEOMETRY_POLYGONINTERSECTION
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace geometry
 */
namespace geometry {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value PolygonIntersection value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, PolygonIntersection const &_value)
{
  os << "PolygonIntersection(";
  os << "intersection_lines:";
  os << _value.intersection_lines;
  os << ",";
  os << "is_within:";
  os << _value.is_within;
  os << ")";
  return os;
}

} // namespace geometry
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for PolygonIntersection
 */
inline std::string to_string(::ad::map::geometry::PolygonIntersection const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::geometry::PolygonIntersection> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::geometry::PolygonIntersection const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_GEOMETRY_POLYGONINTERSECTION
