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
#include "ad/map/match/LaneOccupiedRegionList.hpp"
#include "ad/map/match/MapMatchedObjectReferencePositionList.hpp"
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
 * @brief namespace match
 *
 * Map matching
 */
namespace match {

/*!
 * \brief DataType MapMatchedObjectBoundingBox
 */
struct MapMatchedObjectBoundingBox
{
  /*!
   * \brief Smart pointer on MapMatchedObjectBoundingBox
   */
  typedef std::shared_ptr<MapMatchedObjectBoundingBox> Ptr;

  /*!
   * \brief Smart pointer on constant MapMatchedObjectBoundingBox
   */
  typedef std::shared_ptr<MapMatchedObjectBoundingBox const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  MapMatchedObjectBoundingBox() = default;

  /*!
   * \brief standard destructor
   */
  ~MapMatchedObjectBoundingBox() = default;

  /*!
   * \brief standard copy constructor
   */
  MapMatchedObjectBoundingBox(const MapMatchedObjectBoundingBox &other) = default;

  /*!
   * \brief standard move constructor
   */
  MapMatchedObjectBoundingBox(MapMatchedObjectBoundingBox &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns Reference to this MapMatchedObjectBoundingBox.
   */
  MapMatchedObjectBoundingBox &operator=(const MapMatchedObjectBoundingBox &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns Reference to this MapMatchedObjectBoundingBox.
   */
  MapMatchedObjectBoundingBox &operator=(MapMatchedObjectBoundingBox &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns \c true if both MapMatchedObjectBoundingBox are equal
   */
  bool operator==(const MapMatchedObjectBoundingBox &other) const
  {
    return (lane_occupied_regions == other.lane_occupied_regions)
      && (reference_point_positions == other.reference_point_positions)
      && (sampling_distance == other.sampling_distance) && (match_radius == other.match_radius);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox.
   *
   * \returns \c true if both MapMatchedObjectBoundingBox are different
   */
  bool operator!=(const MapMatchedObjectBoundingBox &other) const
  {
    return !operator==(other);
  }

  ::ad::map::match::LaneOccupiedRegionList lane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList reference_point_positions;

  /*!
   * Sampling distance used to calculate the bounding box.
   */
  ::ad::physics::Distance sampling_distance{0.0};

  /*!
   * The actual map matching radius around the object.
   */
  ::ad::physics::Distance match_radius{0.0};
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
#define GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
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
 * \param[in] _value MapMatchedObjectBoundingBox value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, MapMatchedObjectBoundingBox const &_value)
{
  os << "MapMatchedObjectBoundingBox(";
  os << "lane_occupied_regions:";
  os << _value.lane_occupied_regions;
  os << ",";
  os << "reference_point_positions:";
  os << _value.reference_point_positions;
  os << ",";
  os << "sampling_distance:";
  os << _value.sampling_distance;
  os << ",";
  os << "match_radius:";
  os << _value.match_radius;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for MapMatchedObjectBoundingBox
 */
inline std::string to_string(::ad::map::match::MapMatchedObjectBoundingBox const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::MapMatchedObjectBoundingBox> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::match::MapMatchedObjectBoundingBox const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
