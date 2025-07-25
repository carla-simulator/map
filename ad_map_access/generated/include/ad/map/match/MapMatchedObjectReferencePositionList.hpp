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
#include "ad/map/match/MapMatchedPositionConfidenceList.hpp"
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
 * \brief DataType MapMatchedObjectReferencePositionList
 *
 * The list of the MapMatchedPositionConfidenceList of all ObjectReferencePoints.
 */
typedef std::vector<::ad::map::match::MapMatchedPositionConfidenceList> MapMatchedObjectReferencePositionList;

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_VECTOR_VECTOR_AD_MAP_MATCH_MAPMATCHEDPOSITION
#define GEN_GUARD_VECTOR_VECTOR_AD_MAP_MATCH_MAPMATCHEDPOSITION
namespace std {
/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value MapMatchedObjectReferencePositionList value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os,
                                vector<::ad::map::match::MapMatchedPositionConfidenceList> const &_value)
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
 * \brief overload of the std::to_string for MapMatchedObjectReferencePositionList
 */
inline std::string to_string(::ad::map::match::MapMatchedObjectReferencePositionList const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::MapMatchedObjectReferencePositionList> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::match::MapMatchedObjectReferencePositionList const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_VECTOR_VECTOR_AD_MAP_MATCH_MAPMATCHEDPOSITION
