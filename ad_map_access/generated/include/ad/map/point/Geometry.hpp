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
#include <limits>
#include <memory>
#include <sstream>
#include "ad/map/point/ECEFPointList.hpp"
#include "ad/map/point/ENUPointCache.hpp"
#include "ad/physics/Distance.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace point
 *
 * Handling geographic positions in different coordinate systems
 */
namespace point {

/*!
 * \brief DataType Geometry
 */
struct Geometry
{
  /*!
   * \brief Smart pointer on Geometry
   */
  typedef std::shared_ptr<Geometry> Ptr;

  /*!
   * \brief Smart pointer on constant Geometry
   */
  typedef std::shared_ptr<Geometry const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  Geometry() = default;

  /*!
   * \brief standard destructor
   */
  ~Geometry() = default;

  /*!
   * \brief standard copy constructor
   */
  Geometry(const Geometry &other) = default;

  /*!
   * \brief standard move constructor
   */
  Geometry(Geometry &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Geometry
   *
   * \returns Reference to this Geometry.
   */
  Geometry &operator=(const Geometry &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Geometry
   *
   * \returns Reference to this Geometry.
   */
  Geometry &operator=(Geometry &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Geometry
   *
   * \returns \c true if both Geometry are equal
   */
  bool operator==(const Geometry &other) const
  {
    return (is_valid == other.is_valid) && (is_closed == other.is_closed) && (ecef_points == other.ecef_points)
      && (length == other.length) && (private_enu_points_cache == other.private_enu_points_cache);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Geometry.
   *
   * \returns \c true if both Geometry are different
   */
  bool operator!=(const Geometry &other) const
  {
    return !operator==(other);
  }

  bool is_valid{false};
  bool is_closed{false};
  ::ad::map::point::ECEFPointList ecef_points;
  ::ad::physics::Distance length;

  /*!
   * Private member storing the ecefPointList as enuPointList.
   * Access this member only through respective interface functions to ensure the cache
   * is updated when required.
   */
  ::ad::map::point::ENUPointCache private_enu_points_cache;
};

} // namespace point
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_POINT_GEOMETRY
#define GEN_GUARD_AD_MAP_POINT_GEOMETRY
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace point
 *
 * Handling geographic positions in different coordinate systems
 */
namespace point {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value Geometry value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Geometry const &_value)
{
  os << "Geometry(";
  os << "is_valid:";
  os << _value.is_valid;
  os << ",";
  os << "is_closed:";
  os << _value.is_closed;
  os << ",";
  os << "ecef_points:";
  os << _value.ecef_points;
  os << ",";
  os << "length:";
  os << _value.length;
  os << ",";
  os << "private_enu_points_cache:";
  os << _value.private_enu_points_cache;
  os << ")";
  return os;
}

} // namespace point
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Geometry
 */
inline std::string to_string(::ad::map::point::Geometry const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::point::Geometry> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::point::Geometry const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_POINT_GEOMETRY
