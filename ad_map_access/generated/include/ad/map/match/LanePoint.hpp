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
#include "ad/map/point/ParaPoint.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/RatioValue.hpp"
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
 * \brief DataType LanePoint
 *
 * Defines a point on a lane.
 * Besides the parametric offsets in longitudinal and lateral direction also the length
 * and width of the lane at this point.
 */
struct LanePoint
{
  /*!
   * \brief Smart pointer on LanePoint
   */
  typedef std::shared_ptr<LanePoint> Ptr;

  /*!
   * \brief Smart pointer on constant LanePoint
   */
  typedef std::shared_ptr<LanePoint const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  LanePoint() = default;

  /*!
   * \brief standard destructor
   */
  ~LanePoint() = default;

  /*!
   * \brief standard copy constructor
   */
  LanePoint(const LanePoint &other) = default;

  /*!
   * \brief standard move constructor
   */
  LanePoint(LanePoint &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LanePoint
   *
   * \returns Reference to this LanePoint.
   */
  LanePoint &operator=(const LanePoint &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LanePoint
   *
   * \returns Reference to this LanePoint.
   */
  LanePoint &operator=(LanePoint &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LanePoint
   *
   * \returns \c true if both LanePoint are equal
   */
  bool operator==(const LanePoint &other) const
  {
    return (para_point == other.para_point) && (lateral_t == other.lateral_t) && (lane_length == other.lane_length)
      && (lane_width == other.lane_width);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LanePoint.
   *
   * \returns \c true if both LanePoint are different
   */
  bool operator!=(const LanePoint &other) const
  {
    return !operator==(other);
  }

  ::ad::map::point::ParaPoint para_point;
  ::ad::physics::RatioValue lateral_t;

  /*!
   * Length of lane
   */
  ::ad::physics::Distance lane_length;

  /*!
   * Width of lane
   */
  ::ad::physics::Distance lane_width;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_LANEPOINT
#define GEN_GUARD_AD_MAP_MATCH_LANEPOINT
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
 * \param[in] _value LanePoint value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LanePoint const &_value)
{
  os << "LanePoint(";
  os << "para_point:";
  os << _value.para_point;
  os << ",";
  os << "lateral_t:";
  os << _value.lateral_t;
  os << ",";
  os << "lane_length:";
  os << _value.lane_length;
  os << ",";
  os << "lane_width:";
  os << _value.lane_width;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LanePoint
 */
inline std::string to_string(::ad::map::match::LanePoint const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::LanePoint> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::match::LanePoint const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_LANEPOINT
