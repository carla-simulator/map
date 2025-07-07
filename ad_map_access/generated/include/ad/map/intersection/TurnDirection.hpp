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
 * @brief namespace intersection
 *
 * Contains datatypes related to intersection handling
 */
namespace intersection {

/*!
 * \brief DataType TurnDirection
 *
 * Describes the turn directions within an intersection.
 */
enum class TurnDirection : int32_t
{
  /*!
   * not set, invalid
   */
  Unknown = 0,

  /*!
   * turning right
   */
  Right = 1,

  /*!
   * straight through the intersection
   */
  Straight = 2,

  /*!
   * turning left
   */
  Left = 3,

  /*!
   * turning 180 degree
   */
  UTurn = 4
};

} // namespace intersection
} // namespace map
} // namespace ad
/*!
 * \brief Conversion of ::ad::map::intersection::TurnDirection to std::string helper.
 */
std::string toString(::ad::map::intersection::TurnDirection const e);

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
template <>::ad::map::intersection::TurnDirection fromString(std::string const &str);

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_INTERSECTION_TURNDIRECTION
#define GEN_GUARD_AD_MAP_INTERSECTION_TURNDIRECTION
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace intersection
 *
 * Contains datatypes related to intersection handling
 */
namespace intersection {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] value TurnDirection value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, TurnDirection const &value)
{
  return os << toString(value);
}

} // namespace intersection
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for TurnDirection
 */
inline std::string to_string(::ad::map::intersection::TurnDirection const &value)
{
  return ::toString(value);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::intersection::TurnDirection> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::intersection::TurnDirection const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_INTERSECTION_TURNDIRECTION
