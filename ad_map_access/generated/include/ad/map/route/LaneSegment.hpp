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
#include "ad/map/lane/LaneId.hpp"
#include "ad/map/lane/LaneIdList.hpp"
#include "ad/map/route/LaneInterval.hpp"
#include "ad/map/route/RouteLaneOffset.hpp"
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
 * \brief DataType LaneSegment
 *
 * A lane segment is a part of a road segment and therefore created with the context
 * of a route.
 * It consists of a specific lane interval and the connection (predecessors, successors,
 * right and left neighbor) of the lane interval to other lane intervals within the
 * route.
 * Be aware: The semantics of the connection is respecting the route direction.
 */
struct LaneSegment
{
  /*!
   * \brief Smart pointer on LaneSegment
   */
  typedef std::shared_ptr<LaneSegment> Ptr;

  /*!
   * \brief Smart pointer on constant LaneSegment
   */
  typedef std::shared_ptr<LaneSegment const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  LaneSegment() = default;

  /*!
   * \brief standard destructor
   */
  ~LaneSegment() = default;

  /*!
   * \brief standard copy constructor
   */
  LaneSegment(const LaneSegment &other) = default;

  /*!
   * \brief standard move constructor
   */
  LaneSegment(LaneSegment &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LaneSegment
   *
   * \returns Reference to this LaneSegment.
   */
  LaneSegment &operator=(const LaneSegment &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LaneSegment
   *
   * \returns Reference to this LaneSegment.
   */
  LaneSegment &operator=(LaneSegment &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneSegment
   *
   * \returns \c true if both LaneSegment are equal
   */
  bool operator==(const LaneSegment &other) const
  {
    return (left_neighbor == other.left_neighbor) && (right_neighbor == other.right_neighbor)
      && (predecessors == other.predecessors) && (successors == other.successors)
      && (lane_interval == other.lane_interval) && (route_lane_offset == other.route_lane_offset);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneSegment.
   *
   * \returns \c true if both LaneSegment are different
   */
  bool operator!=(const LaneSegment &other) const
  {
    return !operator==(other);
  }

  /*!
   * The identifier of the left neighboring lane
   */
  ::ad::map::lane::LaneId left_neighbor{0};

  /*!
   * The identifier of the right neighboring lane
   */
  ::ad::map::lane::LaneId right_neighbor{0};

  /*!
   * The list of lane identifiers of preceding lanes
   */
  ::ad::map::lane::LaneIdList predecessors;

  /*!
   * The list of lane identifiers of succeeding lanes
   */
  ::ad::map::lane::LaneIdList successors;

  /*!
   * The interval of the lane
   */
  ::ad::map::route::LaneInterval lane_interval;

  /*!
   * The offset of the lane in number of lane changes left (--) or right (++) from start of the route planning.
   */
  ::ad::map::route::RouteLaneOffset route_lane_offset{0};
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_LANESEGMENT
#define GEN_GUARD_AD_MAP_ROUTE_LANESEGMENT
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
 * \param[in] _value LaneSegment value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneSegment const &_value)
{
  os << "LaneSegment(";
  os << "left_neighbor:";
  os << _value.left_neighbor;
  os << ",";
  os << "right_neighbor:";
  os << _value.right_neighbor;
  os << ",";
  os << "predecessors:";
  os << _value.predecessors;
  os << ",";
  os << "successors:";
  os << _value.successors;
  os << ",";
  os << "lane_interval:";
  os << _value.lane_interval;
  os << ",";
  os << "route_lane_offset:";
  os << _value.route_lane_offset;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneSegment
 */
inline std::string to_string(::ad::map::route::LaneSegment const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::LaneSegment> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::LaneSegment const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_LANESEGMENT
