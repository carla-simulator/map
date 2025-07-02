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
#include "ad/map/route/RoutePlanningCounter.hpp"
#include "ad/map/route/SegmentCounter.hpp"
#include "ad/physics/ParametricValue.hpp"
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
 * \brief DataType RouteParaPoint
 */
struct RouteParaPoint
{
  /*!
   * \brief Smart pointer on RouteParaPoint
   */
  typedef std::shared_ptr<RouteParaPoint> Ptr;

  /*!
   * \brief Smart pointer on constant RouteParaPoint
   */
  typedef std::shared_ptr<RouteParaPoint const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  RouteParaPoint() = default;

  /*!
   * \brief standard destructor
   */
  ~RouteParaPoint() = default;

  /*!
   * \brief standard copy constructor
   */
  RouteParaPoint(const RouteParaPoint &other) = default;

  /*!
   * \brief standard move constructor
   */
  RouteParaPoint(RouteParaPoint &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other RouteParaPoint
   *
   * \returns Reference to this RouteParaPoint.
   */
  RouteParaPoint &operator=(const RouteParaPoint &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other RouteParaPoint
   *
   * \returns Reference to this RouteParaPoint.
   */
  RouteParaPoint &operator=(RouteParaPoint &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RouteParaPoint
   *
   * \returns \c true if both RouteParaPoint are equal
   */
  bool operator==(const RouteParaPoint &other) const
  {
    return (route_planning_counter == other.route_planning_counter)
      && (segment_count_from_destination == other.segment_count_from_destination)
      && (parametric_offset == other.parametric_offset);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RouteParaPoint.
   *
   * \returns \c true if both RouteParaPoint are different
   */
  bool operator!=(const RouteParaPoint &other) const
  {
    return !operator==(other);
  }

  ::ad::map::route::RoutePlanningCounter route_planning_counter{0u};
  ::ad::map::route::SegmentCounter segment_count_from_destination{0};

  /*!
   * The parametric offset in the range of [0;1] within the lane's geometry as defined
   * in the map.
   * 0.0 refers to the start of the lanes points.
   * 1.0 refers to the end of the lanes points.
   * 0.5 refers to in between at half length of the lane.
   * Be aware: Depending on the route direction on the lane either the parametric offset
   * 0.0 or 1.0 can define the start point of that route on that lane.
   */
  ::ad::physics::ParametricValue parametric_offset;
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_ROUTEPARAPOINT
#define GEN_GUARD_AD_MAP_ROUTE_ROUTEPARAPOINT
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
 * \param[in] _value RouteParaPoint value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, RouteParaPoint const &_value)
{
  os << "RouteParaPoint(";
  os << "route_planning_counter:";
  os << _value.route_planning_counter;
  os << ",";
  os << "segment_count_from_destination:";
  os << _value.segment_count_from_destination;
  os << ",";
  os << "parametric_offset:";
  os << _value.parametric_offset;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for RouteParaPoint
 */
inline std::string to_string(::ad::map::route::RouteParaPoint const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::RouteParaPoint> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::RouteParaPoint const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_ROUTEPARAPOINT
