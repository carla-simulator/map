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
#include <string>
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/*!
 * \brief DataType EdgeType
 *
 * The type of a Geo/ENU/ECEF-Edge in respect to the lane it is derived from.
 */
enum class EdgeType : int32_t
{
  /*!
   * undefined default value.
   */
  UNKNOWN = 0,

  /*!
   * The Edge is the representing the center line of a lane interval.
   */
  CENTER = 1,

  /*!
   * The Edge is repesents a specially aligned edge of a lane interval.
   */
  ALIGNED = 2,

  /*!
   * The Edge is the left edge of a lane interval.
   * The Edge was created using projection of the start/end points.
   */
  LEFT_PROJECTED = 3,

  /*!
   * The Edge is the right edge of a lane interval.
   * The Edge was created using projection of the start/end points.
   */
  RIGHT_PROJECTED = 4,

  /*!
   * The Edge is the left edge of a lane interval.
   */
  LEFT = 5,

  /*!
   * The Edge is the right edge of a lane interval.
   */
  RIGHT = 6
};

} // namespace lane
} // namespace map
} // namespace ad
/*!
 * \brief Conversion of ::ad::map::lane::EdgeType to std::string helper.
 */
std::string toString(::ad::map::lane::EdgeType const e);

/*!
 * \brief Conversion from std::string to enum type T helper.
 *
 * \param [in] str - a fully qualified string name of enum class type
 *
 * \return T enum value
 *
 * \throws std::out_of_range exception if the given string does not match any enum type
 *
 * Example usage:
 * \code
 *   auto value = fromString<SomeEnumType>("SomeEnumType::eValue");
 *   assert(value == SomeEnumType::eValue);
 *   // Or:
 *   auto value = fromString<SomeEnumType>("eValue");
 *   assert(value == SomeEnumType::eValue);
 * \endcode
 */
template <typename EnumType> EnumType fromString(std::string const &str);

/*!
 * \brief Conversion from std::string to enum type T helper.
 *
 * \param [in] str - a fully qualified string name of enum class type
 *
 * \return T enum value
 *
 * \throws std::out_of_range exception if the given string does not match any enum type
 *
 * Example usage:
 * \code
 *   auto value = fromString<SomeEnumType>("SomeEnumType::eValue");
 *   assert(value == SomeEnumType::eValue);
 *   // Or:
 *   auto value = fromString<SomeEnumType>("eValue");
 *   assert(value == SomeEnumType::eValue);
 * \endcode
 */
template <>::ad::map::lane::EdgeType fromString(std::string const &str);

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_EDGETYPE
#define GEN_GUARD_AD_MAP_LANE_EDGETYPE
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] value EdgeType value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, EdgeType const &value)
{
  return os << toString(value);
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for EdgeType
 */
inline std::string to_string(::ad::map::lane::EdgeType const &value)
{
  return ::toString(value);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::EdgeType> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::EdgeType const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_EDGETYPE
