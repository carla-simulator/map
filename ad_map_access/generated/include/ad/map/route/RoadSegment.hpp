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
#include "ad/map/point/BoundingSphere.hpp"
#include "ad/map/route/LaneSegmentList.hpp"
#include "ad/map/route/SegmentCounter.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace route
 *
 * Handling of routes
 */
namespace route {

/*!
 * \brief DataType RoadSegment
 *
 * Defines a segment of a road containing parallel lanes that are allowed to be used.
 * The segment consists of an ordered list of RouteLaneInterval entries and a counter
 * of the road segment.
 * The RouteLaneIntervals are ordered from right most lane at index 0 up to left most
 * lane in the sense of the route traveling direction.
 * The counter is assigned once on route planning indicating the segment count from
 * destination.
 * The first segment of the initially planned route should have a segment_count_from_destination
 * == 'number of route segments' and
 * the last segment a segment_count_from_destination == 1.
 * If the stack transports only route previews or is shortening the route while traveling
 * along one gains information on how the route changed.
 * In addition the road segments bounding sphere is provided.
 *
 *
 */
struct RoadSegment
{
  /*!
   * \brief Smart pointer on RoadSegment
   */
  typedef std::shared_ptr<RoadSegment> Ptr;

  /*!
   * \brief Smart pointer on constant RoadSegment
   */
  typedef std::shared_ptr<RoadSegment const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  RoadSegment() = default;

  /*!
   * \brief standard destructor
   */
  ~RoadSegment() = default;

  /*!
   * \brief standard copy constructor
   */
  RoadSegment(const RoadSegment &other) = default;

  /*!
   * \brief standard move constructor
   */
  RoadSegment(RoadSegment &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other RoadSegment
   *
   * \returns Reference to this RoadSegment.
   */
  RoadSegment &operator=(const RoadSegment &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other RoadSegment
   *
   * \returns Reference to this RoadSegment.
   */
  RoadSegment &operator=(RoadSegment &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RoadSegment
   *
   * \returns \c true if both RoadSegment are equal
   */
  bool operator==(const RoadSegment &other) const
  {
    return (drivable_lane_segments == other.drivable_lane_segments)
      && (segment_count_from_destination == other.segment_count_from_destination)
      && (bounding_sphere == other.bounding_sphere);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RoadSegment.
   *
   * \returns \c true if both RoadSegment are different
   */
  bool operator!=(const RoadSegment &other) const
  {
    return !operator==(other);
  }

  ::ad::map::route::LaneSegmentList drivable_lane_segments;
  ::ad::map::route::SegmentCounter segment_count_from_destination{0};

  /*!
   * Bounding sphere of the road segment
   */
  ::ad::map::point::BoundingSphere bounding_sphere;
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_ROADSEGMENT
#define GEN_GUARD_AD_MAP_ROUTE_ROADSEGMENT
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace route
 *
 * Handling of routes
 */
namespace route {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value RoadSegment value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, RoadSegment const &_value)
{
  os << "RoadSegment(";
  os << "drivable_lane_segments:";
  os << _value.drivable_lane_segments;
  os << ",";
  os << "segment_count_from_destination:";
  os << _value.segment_count_from_destination;
  os << ",";
  os << "bounding_sphere:";
  os << _value.bounding_sphere;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for RoadSegment
 */
inline std::string to_string(::ad::map::route::RoadSegment const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::RoadSegment> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::RoadSegment const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_ROADSEGMENT
