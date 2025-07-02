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
#include "ad/physics/ParametricRange.hpp"
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
 * \brief DataType LaneOccupiedRegion
 *
 * The occupied region of a lane
 */
struct LaneOccupiedRegion
{
  /*!
   * \brief Smart pointer on LaneOccupiedRegion
   */
  typedef std::shared_ptr<LaneOccupiedRegion> Ptr;

  /*!
   * \brief Smart pointer on constant LaneOccupiedRegion
   */
  typedef std::shared_ptr<LaneOccupiedRegion const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  LaneOccupiedRegion() = default;

  /*!
   * \brief standard destructor
   */
  ~LaneOccupiedRegion() = default;

  /*!
   * \brief standard copy constructor
   */
  LaneOccupiedRegion(const LaneOccupiedRegion &other) = default;

  /*!
   * \brief standard move constructor
   */
  LaneOccupiedRegion(LaneOccupiedRegion &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LaneOccupiedRegion
   *
   * \returns Reference to this LaneOccupiedRegion.
   */
  LaneOccupiedRegion &operator=(const LaneOccupiedRegion &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LaneOccupiedRegion
   *
   * \returns Reference to this LaneOccupiedRegion.
   */
  LaneOccupiedRegion &operator=(LaneOccupiedRegion &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneOccupiedRegion
   *
   * \returns \c true if both LaneOccupiedRegion are equal
   */
  bool operator==(const LaneOccupiedRegion &other) const
  {
    return (lane_id == other.lane_id) && (longitudinal_range == other.longitudinal_range)
      && (lateral_range == other.lateral_range);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneOccupiedRegion.
   *
   * \returns \c true if both LaneOccupiedRegion are different
   */
  bool operator!=(const LaneOccupiedRegion &other) const
  {
    return !operator==(other);
  }

  ::ad::map::lane::LaneId lane_id{0};
  ::ad::physics::ParametricRange longitudinal_range;
  ::ad::physics::ParametricRange lateral_range;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_LANEOCCUPIEDREGION
#define GEN_GUARD_AD_MAP_MATCH_LANEOCCUPIEDREGION
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
 * \param[in] _value LaneOccupiedRegion value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneOccupiedRegion const &_value)
{
  os << "LaneOccupiedRegion(";
  os << "lane_id:";
  os << _value.lane_id;
  os << ",";
  os << "longitudinal_range:";
  os << _value.longitudinal_range;
  os << ",";
  os << "lateral_range:";
  os << _value.lateral_range;
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneOccupiedRegion
 */
inline std::string to_string(::ad::map::match::LaneOccupiedRegion const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::match::LaneOccupiedRegion> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::match::LaneOccupiedRegion const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_MATCH_LANEOCCUPIEDREGION
