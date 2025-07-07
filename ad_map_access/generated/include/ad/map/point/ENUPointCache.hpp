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

#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include "ad/map/point/ENUPointList.hpp"
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
 * \brief DataType ENUPointCache
 */
struct ENUPointCache
{
  /*!
   * \brief Smart pointer on ENUPointCache
   */
  typedef std::shared_ptr<ENUPointCache> Ptr;

  /*!
   * \brief Smart pointer on constant ENUPointCache
   */
  typedef std::shared_ptr<ENUPointCache const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  ENUPointCache() = default;

  /*!
   * \brief standard destructor
   */
  ~ENUPointCache() = default;

  /*!
   * \brief standard copy constructor
   */
  ENUPointCache(const ENUPointCache &other) = default;

  /*!
   * \brief standard move constructor
   */
  ENUPointCache(ENUPointCache &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other ENUPointCache
   *
   * \returns Reference to this ENUPointCache.
   */
  ENUPointCache &operator=(const ENUPointCache &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other ENUPointCache
   *
   * \returns Reference to this ENUPointCache.
   */
  ENUPointCache &operator=(ENUPointCache &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUPointCache
   *
   * \returns \c true if both ENUPointCache are equal
   */
  bool operator==(const ENUPointCache &other) const
  {
    return (enu_points == other.enu_points) && (enu_version == other.enu_version);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUPointCache.
   *
   * \returns \c true if both ENUPointCache are different
   */
  bool operator!=(const ENUPointCache &other) const
  {
    return !operator==(other);
  }

  ::ad::map::point::ENUPointList enu_points;
  uint64_t enu_version{0};
};

} // namespace point
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_POINT_ENUPOINTCACHE
#define GEN_GUARD_AD_MAP_POINT_ENUPOINTCACHE
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

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value ENUPointCache value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, ENUPointCache const &_value)
{
  os << "ENUPointCache(";
  os << "enu_points:";
  os << _value.enu_points;
  os << ",";
  os << "enu_version:";
  os << _value.enu_version;
  os << ")";
  return os;
}

} // namespace point
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for ENUPointCache
 */
inline std::string to_string(::ad::map::point::ENUPointCache const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::point::ENUPointCache> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::point::ENUPointCache const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_POINT_ENUPOINTCACHE
