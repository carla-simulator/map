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
#include "ad/map/point/ENUHeading.hpp"
#include "ad/map/point/ENUPoint.hpp"
#include "ad/map/point/GeoPoint.hpp"
#include "ad/physics/Dimension3D.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace match
 *
 * Map matching
 */
namespace match {

/*!
 * \brief DataType ENUObjectPosition
 */
struct ENUObjectPosition
{
  /*!
   * \brief Smart pointer on ENUObjectPosition
   */
  typedef std::shared_ptr<ENUObjectPosition> Ptr;

  /*!
   * \brief Smart pointer on constant ENUObjectPosition
   */
  typedef std::shared_ptr<ENUObjectPosition const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  ENUObjectPosition() = default;

  /*!
   * \brief standard destructor
   */
  ~ENUObjectPosition() = default;

  /*!
   * \brief standard copy constructor
   */
  ENUObjectPosition(const ENUObjectPosition &other) = default;

  /*!
   * \brief standard move constructor
   */
  ENUObjectPosition(ENUObjectPosition &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other ENUObjectPosition
   *
   * \returns Reference to this ENUObjectPosition.
   */
  ENUObjectPosition &operator=(const ENUObjectPosition &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other ENUObjectPosition
   *
   * \returns Reference to this ENUObjectPosition.
   */
  ENUObjectPosition &operator=(ENUObjectPosition &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUObjectPosition
   *
   * \returns \c true if both ENUObjectPosition are equal
   */
  bool operator==(const ENUObjectPosition &other) const
  {
    return (center_point == other.center_point) && (heading == other.heading)
      && (enu_reference_point == other.enu_reference_point) && (dimension == other.dimension);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUObjectPosition.
   *
   * \returns \c true if both ENUObjectPosition are different
   */
  bool operator!=(const ENUObjectPosition &other) const
  {
    return !operator==(other);
  }

  /*!
   * 3D position in ENU coordinates
   */
  ::ad::map::point::ENUPoint center_point;

  /*!
   * Angle in ENU coordinate system as angle measured from East to North axis (yaw) in radians.
   */
  ::ad::map::point::ENUHeading heading{std::numeric_limits<double>::quiet_NaN()};

  /*!
   * GNSS coordinate of the coordinate system origin / reference frame
   */
  ::ad::map::point::GeoPoint enu_reference_point;

  /*!
   * 3D dimension of the object
   */
  ::ad::physics::Dimension3D dimension;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_ENUOBJECTPOSITION
#define GEN_GUARD_AD_MAP_MATCH_ENUOBJECTPOSITION
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace match
 *
 * Map matching
 */
namespace match {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value ENUObjectPosition value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, ENUObjectPosition const &_value)
{
  os << "ENUObjectPosition(";
  os << "center_point:";
  os << _value.center_point;
  os << ",";
  os << "heading:";
  os << _value.heading;
  os << ",";
  os << "enu_reference_point:";
  os << _value.enu_reference_point;
  os << ",";
  os << "dimension:";
  os << _value.dimension;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for ENUObjectPosition
 */
inline std::string to_string(::ad::map::match::ENUObjectPosition const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::ENUObjectPosition> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::match::ENUObjectPosition const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_ENUOBJECTPOSITION
