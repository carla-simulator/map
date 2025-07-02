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
#include "ad/physics/AccelerationRange.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

/*!
 * \brief DataType AccelerationRangeList
 *
 * List of AccelerationRange
 */
typedef std::vector<::ad::physics::AccelerationRange> AccelerationRangeList;

} // namespace physics
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_VECTOR_AD_PHYSICS_ACCELERATIONRANGE
#define GEN_GUARD_VECTOR_AD_PHYSICS_ACCELERATIONRANGE
namespace std {
/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value AccelerationRangeList value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, vector<::ad::physics::AccelerationRange> const &_value)
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
 * \brief overload of the std::to_string for AccelerationRangeList
 */
inline std::string to_string(::ad::physics::AccelerationRangeList const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::physics::AccelerationRangeList> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::physics::AccelerationRangeList const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_VECTOR_AD_PHYSICS_ACCELERATIONRANGE
