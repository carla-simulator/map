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
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include "ad/map/intersection/IntersectionType.hpp"
#include "ad/map/landmark/TrafficLightType.hpp"
#include "ad/physics/Distance.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace config
 *
 * Configuration
 */
namespace config {

/*!
 * \brief DataType MapEntry
 *
 * Holds a filename of a map and some settings used when loading the map
 */
struct MapEntry
{
  /*!
   * \brief Smart pointer on MapEntry
   */
  typedef std::shared_ptr<MapEntry> Ptr;

  /*!
   * \brief Smart pointer on constant MapEntry
   */
  typedef std::shared_ptr<MapEntry const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  MapEntry() = default;

  /*!
   * \brief standard destructor
   */
  ~MapEntry() = default;

  /*!
   * \brief standard copy constructor
   */
  MapEntry(const MapEntry &other) = default;

  /*!
   * \brief standard move constructor
   */
  MapEntry(MapEntry &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other MapEntry
   *
   * \returns Reference to this MapEntry.
   */
  MapEntry &operator=(const MapEntry &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other MapEntry
   *
   * \returns Reference to this MapEntry.
   */
  MapEntry &operator=(MapEntry &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapEntry
   *
   * \returns \c true if both MapEntry are equal
   */
  bool operator==(const MapEntry &other) const
  {
    return (filename == other.filename) && (open_drive_overlap_margin == other.open_drive_overlap_margin)
      && (open_drive_default_intersection_type == other.open_drive_default_intersection_type)
      && (open_drive_default_traffic_light_type == other.open_drive_default_traffic_light_type);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapEntry.
   *
   * \returns \c true if both MapEntry are different
   */
  bool operator!=(const MapEntry &other) const
  {
    return !operator==(other);
  }

  /*!
   * holds the fully qualified path name of the map file
   */
  std::string filename;

  /*!
   * optional parameter for open drive maps defining the margin to be used when calculating lane overlaps
   */
  ::ad::physics::Distance open_drive_overlap_margin{0.};

  /*!
   * The default intersection type
   */
  ::ad::map::intersection::IntersectionType open_drive_default_intersection_type{
    ::ad::map::intersection::IntersectionType::Unknown};
  ::ad::map::landmark::TrafficLightType open_drive_default_traffic_light_type{
    ::ad::map::landmark::TrafficLightType::SOLID_RED_YELLOW_GREEN};
};

} // namespace config
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_CONFIG_MAPENTRY
#define GEN_GUARD_AD_MAP_CONFIG_MAPENTRY
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace config
 *
 * Configuration
 */
namespace config {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value MapEntry value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, MapEntry const &_value)
{
  os << "MapEntry(";
  os << "filename:";
  os << _value.filename;
  os << ",";
  os << "open_drive_overlap_margin:";
  os << _value.open_drive_overlap_margin;
  os << ",";
  os << "open_drive_default_intersection_type:";
  os << _value.open_drive_default_intersection_type;
  os << ",";
  os << "open_drive_default_traffic_light_type:";
  os << _value.open_drive_default_traffic_light_type;
  os << ")";
  return os;
}

} // namespace config
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for MapEntry
 */
inline std::string to_string(::ad::map::config::MapEntry const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::config::MapEntry> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::config::MapEntry const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_CONFIG_MAPENTRY
