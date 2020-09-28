/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-1997
 */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "ad/map/point/ECEFPoint.hpp"
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
 * \brief DataType ECEFEdge
 */
typedef std::vector<::ad::map::point::ECEFPoint> ECEFEdge;

} // namespace point
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_VECTOR_AD_MAP_POINT_ECEFPOINT
#define GEN_GUARD_VECTOR_AD_MAP_POINT_ECEFPOINT
namespace std {
/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value ECEFEdge value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, vector<::ad::map::point::ECEFPoint> const &_value)
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
 * \brief overload of the std::to_string for ECEFEdge
 */
inline std::string to_string(::ad::map::point::ECEFEdge const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std
#endif // GEN_GUARD_VECTOR_AD_MAP_POINT_ECEFPOINT
