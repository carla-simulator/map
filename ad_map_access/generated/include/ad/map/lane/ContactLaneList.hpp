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
#include "ad/map/lane/ContactLane.hpp"
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
 * \brief DataType ContactLaneList
 */
typedef std::vector<::ad::map::lane::ContactLane> ContactLaneList;

} // namespace lane
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_VECTOR_AD_MAP_LANE_CONTACTLANE
#define GEN_GUARD_VECTOR_AD_MAP_LANE_CONTACTLANE
namespace std {
/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value ContactLaneList value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, vector<::ad::map::lane::ContactLane> const &_value)
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
 * \brief overload of the std::to_string for ContactLaneList
 */
inline std::string to_string(::ad::map::lane::ContactLaneList const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::ContactLaneList> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::ContactLaneList const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_VECTOR_AD_MAP_LANE_CONTACTLANE
