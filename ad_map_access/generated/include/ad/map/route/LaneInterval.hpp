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
 * \brief DataType LaneInterval
 *
 * Defines an interval on a lane containing a parametric start and end value.
 * The ordering describes the logical start and logical end of the interval when traveling
 * on a lane along the route.
 * If the parametric values are given with start > end the route traveling direction
 * is negative compared to the geometrical direction of the lane.
 * Be awae: it doesn't provide insight into the nominal driving direction of a lane.
 */
struct LaneInterval
{
  /*!
   * \brief Smart pointer on LaneInterval
   */
  typedef std::shared_ptr<LaneInterval> Ptr;

  /*!
   * \brief Smart pointer on constant LaneInterval
   */
  typedef std::shared_ptr<LaneInterval const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  LaneInterval() = default;

  /*!
   * \brief standard destructor
   */
  ~LaneInterval() = default;

  /*!
   * \brief standard copy constructor
   */
  LaneInterval(const LaneInterval &other) = default;

  /*!
   * \brief standard move constructor
   */
  LaneInterval(LaneInterval &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LaneInterval
   *
   * \returns Reference to this LaneInterval.
   */
  LaneInterval &operator=(const LaneInterval &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LaneInterval
   *
   * \returns Reference to this LaneInterval.
   */
  LaneInterval &operator=(LaneInterval &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneInterval
   *
   * \returns \c true if both LaneInterval are equal
   */
  bool operator==(const LaneInterval &other) const
  {
    return (lane_id == other.lane_id) && (start == other.start) && (end == other.end) && (wrong_way == other.wrong_way);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneInterval.
   *
   * \returns \c true if both LaneInterval are different
   */
  bool operator!=(const LaneInterval &other) const
  {
    return !operator==(other);
  }

  ::ad::map::lane::LaneId lane_id{0};
  ::ad::physics::ParametricValue start;
  ::ad::physics::ParametricValue end;

  /*!
   * True, if driving is against the correct driving direction
   */
  bool wrong_way{false};
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_LANEINTERVAL
#define GEN_GUARD_AD_MAP_ROUTE_LANEINTERVAL
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
 * \param[in] _value LaneInterval value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneInterval const &_value)
{
  os << "LaneInterval(";
  os << "lane_id:";
  os << _value.lane_id;
  os << ",";
  os << "start:";
  os << _value.start;
  os << ",";
  os << "end:";
  os << _value.end;
  os << ",";
  os << "wrong_way:";
  os << _value.wrong_way;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneInterval
 */
inline std::string to_string(::ad::map::route::LaneInterval const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::LaneInterval> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::LaneInterval const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_LANEINTERVAL
