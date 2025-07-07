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
#include "ad/map/match/LanePoint.hpp"
#include "ad/map/match/MapMatchedPositionType.hpp"
#include "ad/map/point/ECEFPoint.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/Probability.hpp"
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
 * \brief DataType MapMatchedPosition
 *
 * A map matched position
 */
struct MapMatchedPosition
{
  /*!
   * \brief Smart pointer on MapMatchedPosition
   */
  typedef std::shared_ptr<MapMatchedPosition> Ptr;

  /*!
   * \brief Smart pointer on constant MapMatchedPosition
   */
  typedef std::shared_ptr<MapMatchedPosition const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  MapMatchedPosition() = default;

  /*!
   * \brief standard destructor
   */
  ~MapMatchedPosition() = default;

  /*!
   * \brief standard copy constructor
   */
  MapMatchedPosition(const MapMatchedPosition &other) = default;

  /*!
   * \brief standard move constructor
   */
  MapMatchedPosition(MapMatchedPosition &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other MapMatchedPosition
   *
   * \returns Reference to this MapMatchedPosition.
   */
  MapMatchedPosition &operator=(const MapMatchedPosition &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other MapMatchedPosition
   *
   * \returns Reference to this MapMatchedPosition.
   */
  MapMatchedPosition &operator=(MapMatchedPosition &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedPosition
   *
   * \returns \c true if both MapMatchedPosition are equal
   */
  bool operator==(const MapMatchedPosition &other) const
  {
    return (lane_point == other.lane_point) && (type == other.type) && (matched_point == other.matched_point)
      && (probability == other.probability) && (query_point == other.query_point)
      && (matched_point_distance == other.matched_point_distance);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedPosition.
   *
   * \returns \c true if both MapMatchedPosition are different
   */
  bool operator!=(const MapMatchedPosition &other) const
  {
    return !operator==(other);
  }

  /*!
   * matched point as LanePoint.
   * parametric_offset
   */
  ::ad::map::match::LanePoint lane_point;
  ::ad::map::match::MapMatchedPositionType type{::ad::map::match::MapMatchedPositionType::INVALID};
  ::ad::map::point::ECEFPoint matched_point;
  ::ad::physics::Probability probability;

  /*!
   * Point that is used for determining this matched pos.
   */
  ::ad::map::point::ECEFPoint query_point;

  /*!
   * The distance between the matched_point and the query_point.
   */
  ::ad::physics::Distance matched_point_distance;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDPOSITION
#define GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDPOSITION
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
 * \param[in] _value MapMatchedPosition value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, MapMatchedPosition const &_value)
{
  os << "MapMatchedPosition(";
  os << "lane_point:";
  os << _value.lane_point;
  os << ",";
  os << "type:";
  os << _value.type;
  os << ",";
  os << "matched_point:";
  os << _value.matched_point;
  os << ",";
  os << "probability:";
  os << _value.probability;
  os << ",";
  os << "query_point:";
  os << _value.query_point;
  os << ",";
  os << "matched_point_distance:";
  os << _value.matched_point_distance;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for MapMatchedPosition
 */
inline std::string to_string(::ad::map::match::MapMatchedPosition const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::MapMatchedPosition> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::match::MapMatchedPosition const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDPOSITION
