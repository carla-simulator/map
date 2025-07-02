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
 * \brief DataType LaneType
 *
 * Type of lane
 */
enum class LaneType : int32_t
{
  /*!
   INVALID
   */
  INVALID = 0,
  /*!
   UNKNOWN
   */
  UNKNOWN = 1,
  /*!
   NORMAL
   */
  NORMAL = 2,
  /*!
   INTERSECTION
   */
  INTERSECTION = 3,
  /*!
   SHOULDER
   */
  SHOULDER = 4,
  /*!
   EMERGENCY
   */
  EMERGENCY = 5,
  /*!
   MULTI
   */
  MULTI = 6,
  /*!
   PEDESTRIAN
   */
  PEDESTRIAN = 7,
  /*!
   OVERTAKING
   */
  OVERTAKING = 8,
  /*!
   TURN
   */
  TURN = 9,
  /*!
   BIKE
   */
  BIKE = 10,
  /*!
   OPENDRIVE_REFERENCE_LINE
   */
  OPENDRIVE_REFERENCE_LINE = 11
};

} // namespace lane
} // namespace map
} // namespace ad
/*!
 * \brief Conversion of ::ad::map::lane::LaneType to std::string helper.
 */
std::string toString(::ad::map::lane::LaneType const e);

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
template <>::ad::map::lane::LaneType fromString(std::string const &str);

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_LANETYPE
#define GEN_GUARD_AD_MAP_LANE_LANETYPE
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
 * \param[in] value LaneType value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneType const &value)
{
  return os << toString(value);
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneType
 */
inline std::string to_string(::ad::map::lane::LaneType const &value)
{
  return ::toString(value);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::LaneType> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::LaneType const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_LANETYPE
