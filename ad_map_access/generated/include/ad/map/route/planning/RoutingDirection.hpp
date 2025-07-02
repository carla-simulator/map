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
 * @brief namespace route
 *
 * Handling of routes
 */
namespace route {
/*!
 * @brief namespace planning
 */
namespace planning {

/*!
 * \brief DataType RoutingDirection
 *
 * Direction at the para point in respect to the lane orientation
 */
enum class RoutingDirection : int32_t
{
  /*!
   * Vehicle direction is not relevant.
   */
  DONT_CARE = 0,

  /*!
   * Vehicle direction is same as Lane orientation.
   */
  POSITIVE = 1,

  /*!
   * Vehicle direction is opposite of Lane orientation.
   */
  NEGATIVE = 2
};

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
/*!
 * \brief Conversion of ::ad::map::route::planning::RoutingDirection to std::string helper.
 */
std::string toString(::ad::map::route::planning::RoutingDirection const e);

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
template <>::ad::map::route::planning::RoutingDirection fromString(std::string const &str);

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGDIRECTION
#define GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGDIRECTION
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace route
 *
 * Handling of routes
 */
namespace route {
/*!
 * @brief namespace planning
 */
namespace planning {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] value RoutingDirection value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, RoutingDirection const &value)
{
  return os << toString(value);
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for RoutingDirection
 */
inline std::string to_string(::ad::map::route::planning::RoutingDirection const &value)
{
  return ::toString(value);
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::planning::RoutingDirection> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::route::planning::RoutingDirection const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGDIRECTION
