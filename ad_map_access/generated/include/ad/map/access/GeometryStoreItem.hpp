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
 * @brief namespace access
 *
 * Accessing map data
 */
namespace access {

/*!
 * \brief DataType GeometryStoreItem
 */
struct GeometryStoreItem
{
  /*!
   * \brief Smart pointer on GeometryStoreItem
   */
  typedef std::shared_ptr<GeometryStoreItem> Ptr;

  /*!
   * \brief Smart pointer on constant GeometryStoreItem
   */
  typedef std::shared_ptr<GeometryStoreItem const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  GeometryStoreItem() = default;

  /*!
   * \brief standard destructor
   */
  ~GeometryStoreItem() = default;

  /*!
   * \brief standard copy constructor
   */
  GeometryStoreItem(const GeometryStoreItem &other) = default;

  /*!
   * \brief standard move constructor
   */
  GeometryStoreItem(GeometryStoreItem &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other GeometryStoreItem
   *
   * \returns Reference to this GeometryStoreItem.
   */
  GeometryStoreItem &operator=(const GeometryStoreItem &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other GeometryStoreItem
   *
   * \returns Reference to this GeometryStoreItem.
   */
  GeometryStoreItem &operator=(GeometryStoreItem &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other GeometryStoreItem
   *
   * \returns \c true if both GeometryStoreItem are equal
   */
  bool operator==(const GeometryStoreItem &other) const
  {
    return (left_edge_offset == other.left_edge_offset) && (right_edge_offset == other.right_edge_offset)
      && (left_edge_points == other.left_edge_points) && (right_edge_points == other.right_edge_points);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other GeometryStoreItem.
   *
   * \returns \c true if both GeometryStoreItem are different
   */
  bool operator!=(const GeometryStoreItem &other) const
  {
    return !operator==(other);
  }

  uint32_t left_edge_offset{0};
  uint32_t right_edge_offset{0};
  uint32_t left_edge_points{0};
  uint32_t right_edge_points{0};
};

} // namespace access
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ACCESS_GEOMETRYSTOREITEM
#define GEN_GUARD_AD_MAP_ACCESS_GEOMETRYSTOREITEM
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace access
 *
 * Accessing map data
 */
namespace access {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value GeometryStoreItem value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, GeometryStoreItem const &_value)
{
  os << "GeometryStoreItem(";
  os << "left_edge_offset:";
  os << _value.left_edge_offset;
  os << ",";
  os << "right_edge_offset:";
  os << _value.right_edge_offset;
  os << ",";
  os << "left_edge_points:";
  os << _value.left_edge_points;
  os << ",";
  os << "right_edge_points:";
  os << _value.right_edge_points;
  os << ")";
  return os;
}

} // namespace access
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for GeometryStoreItem
 */
inline std::string to_string(::ad::map::access::GeometryStoreItem const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::access::GeometryStoreItem> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::access::GeometryStoreItem const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ACCESS_GEOMETRYSTOREITEM
