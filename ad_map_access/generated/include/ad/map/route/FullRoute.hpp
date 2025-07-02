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
#include "ad/map/route/RoadSegmentList.hpp"
#include "ad/map/route/RouteCreationMode.hpp"
#include "ad/map/route/RouteLaneOffset.hpp"
#include "ad/map/route/RoutePlanningCounter.hpp"
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
 * \brief DataType FullRoute
 *
 * Defines a route along a road containing a consecutive RouteRoadSegments, a counter
 * of the segments and a route planning counter
 * The counters are assigned once on route planning.
 * The route planning counter indicates if a replanning of the route took place.
 * The full_route_segment_count indicates the number of route segments after route
 * planning.
 * If the stack transports only route previews or is shortening the route while traveling
 * along the counters remain untouched.
 *
 *
 *
 *
 */
struct FullRoute
{
  /*!
   * \brief Smart pointer on FullRoute
   */
  typedef std::shared_ptr<FullRoute> Ptr;

  /*!
   * \brief Smart pointer on constant FullRoute
   */
  typedef std::shared_ptr<FullRoute const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  FullRoute() = default;

  /*!
   * \brief standard destructor
   */
  ~FullRoute() = default;

  /*!
   * \brief standard copy constructor
   */
  FullRoute(const FullRoute &other) = default;

  /*!
   * \brief standard move constructor
   */
  FullRoute(FullRoute &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other FullRoute
   *
   * \returns Reference to this FullRoute.
   */
  FullRoute &operator=(const FullRoute &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other FullRoute
   *
   * \returns Reference to this FullRoute.
   */
  FullRoute &operator=(FullRoute &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other FullRoute
   *
   * \returns \c true if both FullRoute are equal
   */
  bool operator==(const FullRoute &other) const
  {
    return (road_segments == other.road_segments) && (route_planning_counter == other.route_planning_counter)
      && (full_route_segment_count == other.full_route_segment_count)
      && (destination_lane_offset == other.destination_lane_offset) && (min_lane_offset == other.min_lane_offset)
      && (max_lane_offset == other.max_lane_offset) && (route_creation_mode == other.route_creation_mode);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other FullRoute.
   *
   * \returns \c true if both FullRoute are different
   */
  bool operator!=(const FullRoute &other) const
  {
    return !operator==(other);
  }

  ::ad::map::route::RoadSegmentList road_segments;
  ::ad::map::route::RoutePlanningCounter route_planning_counter{0u};
  ::ad::map::route::SegmentCounter full_route_segment_count{0u};

  /*!
   * The lane offset of the planning destination.
   */
  ::ad::map::route::RouteLaneOffset destination_lane_offset{0};

  /*!
   * The minimal lane offset of the route.
   */
  ::ad::map::route::RouteLaneOffset min_lane_offset{0};

  /*!
   * The maximal lane offset of the route.
   */
  ::ad::map::route::RouteLaneOffset max_lane_offset{0};

  /*!
   * Store the information on how the route was initially created to be able to consider this when applying route
   * operations.
   */
  ::ad::map::route::RouteCreationMode route_creation_mode{::ad::map::route::RouteCreationMode::Undefined};
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_FULLROUTE
#define GEN_GUARD_AD_MAP_ROUTE_FULLROUTE
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
 * \param[in] _value FullRoute value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, FullRoute const &_value)
{
  os << "FullRoute(";
  os << "road_segments:";
  os << _value.road_segments;
  os << ",";
  os << "route_planning_counter:";
  os << _value.route_planning_counter;
  os << ",";
  os << "full_route_segment_count:";
  os << _value.full_route_segment_count;
  os << ",";
  os << "destination_lane_offset:";
  os << _value.destination_lane_offset;
  os << ",";
  os << "min_lane_offset:";
  os << _value.min_lane_offset;
  os << ",";
  os << "max_lane_offset:";
  os << _value.max_lane_offset;
  os << ",";
  os << "route_creation_mode:";
  os << _value.route_creation_mode;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for FullRoute
 */
inline std::string to_string(::ad::map::route::FullRoute const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::FullRoute> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::FullRoute const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_FULLROUTE
