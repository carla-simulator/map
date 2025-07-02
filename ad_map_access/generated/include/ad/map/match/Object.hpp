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
#include <sstream>
#include "ad/map/match/ENUObjectPosition.hpp"
#include "ad/map/match/MapMatchedObjectBoundingBox.hpp"
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
 * \brief DataType Object
 */
struct Object
{
  /*!
   * \brief Smart pointer on Object
   */
  typedef std::shared_ptr<Object> Ptr;

  /*!
   * \brief Smart pointer on constant Object
   */
  typedef std::shared_ptr<Object const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  Object() = default;

  /*!
   * \brief standard destructor
   */
  ~Object() = default;

  /*!
   * \brief standard copy constructor
   */
  Object(const Object &other) = default;

  /*!
   * \brief standard move constructor
   */
  Object(Object &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Object
   *
   * \returns Reference to this Object.
   */
  Object &operator=(const Object &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Object
   *
   * \returns Reference to this Object.
   */
  Object &operator=(Object &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Object
   *
   * \returns \c true if both Object are equal
   */
  bool operator==(const Object &other) const
  {
    return (enu_position == other.enu_position) && (map_matched_bounding_box == other.map_matched_bounding_box);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Object.
   *
   * \returns \c true if both Object are different
   */
  bool operator!=(const Object &other) const
  {
    return !operator==(other);
  }

  /*!
   * Position of the object
   */
  ::ad::map::match::ENUObjectPosition enu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox map_matched_bounding_box;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_OBJECT
#define GEN_GUARD_AD_MAP_MATCH_OBJECT
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
 * \param[in] _value Object value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Object const &_value)
{
  os << "Object(";
  os << "enu_position:";
  os << _value.enu_position;
  os << ",";
  os << "map_matched_bounding_box:";
  os << _value.map_matched_bounding_box;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Object
 */
inline std::string to_string(::ad::map::match::Object const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::Object> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::match::Object const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_OBJECT
