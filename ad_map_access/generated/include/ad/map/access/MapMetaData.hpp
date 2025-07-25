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
#include "ad/map/access/TrafficType.hpp"
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
 * \brief DataType MapMetaData
 *
 * Meta data specific to a map
 */
struct MapMetaData
{
  /*!
   * \brief Smart pointer on MapMetaData
   */
  typedef std::shared_ptr<MapMetaData> Ptr;

  /*!
   * \brief Smart pointer on constant MapMetaData
   */
  typedef std::shared_ptr<MapMetaData const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  MapMetaData() = default;

  /*!
   * \brief standard destructor
   */
  ~MapMetaData() = default;

  /*!
   * \brief standard copy constructor
   */
  MapMetaData(const MapMetaData &other) = default;

  /*!
   * \brief standard move constructor
   */
  MapMetaData(MapMetaData &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other MapMetaData
   *
   * \returns Reference to this MapMetaData.
   */
  MapMetaData &operator=(const MapMetaData &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other MapMetaData
   *
   * \returns Reference to this MapMetaData.
   */
  MapMetaData &operator=(MapMetaData &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMetaData
   *
   * \returns \c true if both MapMetaData are equal
   */
  bool operator==(const MapMetaData &other) const
  {
    return (traffic_type == other.traffic_type);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMetaData.
   *
   * \returns \c true if both MapMetaData are different
   */
  bool operator!=(const MapMetaData &other) const
  {
    return !operator==(other);
  }

  ::ad::map::access::TrafficType traffic_type;
};

} // namespace access
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ACCESS_MAPMETADATA
#define GEN_GUARD_AD_MAP_ACCESS_MAPMETADATA
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
 * \param[in] _value MapMetaData value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, MapMetaData const &_value)
{
  os << "MapMetaData(";
  os << "traffic_type:";
  os << _value.traffic_type;
  os << ")";
  return os;
}

} // namespace access
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for MapMetaData
 */
inline std::string to_string(::ad::map::access::MapMetaData const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::access::MapMetaData> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::access::MapMetaData const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ACCESS_MAPMETADATA
