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
#include <sstream>
#include <vector>
#include "ad/map/route/planning/RoutingParaPoint.hpp"
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
 * \brief DataType RoutingParaPointList
 *
 * List of RoutingParaPoints.
 */
typedef std::vector<::ad::map::route::planning::RoutingParaPoint> RoutingParaPointList;

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_VECTOR_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
#define GEN_GUARD_VECTOR_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
namespace std {
/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value RoutingParaPointList value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, vector<::ad::map::route::planning::RoutingParaPoint> const &_value)
{
  os << "[";
  for (auto it = _value.begin(); it != _value.end(); it++)
  {
    if (it != _value.begin())
    {
      os << ",";
    }
    os << *it;
  }
  os << "]";
  return os;
}
} // namespace std

namespace std {
/*!
 * \brief overload of the std::to_string for RoutingParaPointList
 */
inline std::string to_string(::ad::map::route::planning::RoutingParaPointList const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::planning::RoutingParaPointList> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::route::planning::RoutingParaPointList const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_VECTOR_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
