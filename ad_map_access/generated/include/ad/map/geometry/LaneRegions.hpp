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
#include <memory>
#include <sstream>
#include "ad/map/match/LaneOccupiedRegionList.hpp"
#include "ad/map/point/BoundingSphere.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace geometry
 */
namespace geometry {

/*!
 * \brief DataType LaneRegions
 *
 * This stuct contains the lane regions around a reference position.
 * The regions are divided into a list of fully occluded, fully visible and partly
 * occluded LaneOccupiedRegions.
 */
struct LaneRegions
{
  /*!
   * \brief Smart pointer on LaneRegions
   */
  typedef std::shared_ptr<LaneRegions> Ptr;

  /*!
   * \brief Smart pointer on constant LaneRegions
   */
  typedef std::shared_ptr<LaneRegions const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  LaneRegions() = default;

  /*!
   * \brief standard destructor
   */
  ~LaneRegions() = default;

  /*!
   * \brief standard copy constructor
   */
  LaneRegions(const LaneRegions &other) = default;

  /*!
   * \brief standard move constructor
   */
  LaneRegions(LaneRegions &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other LaneRegions
   *
   * \returns Reference to this LaneRegions.
   */
  LaneRegions &operator=(const LaneRegions &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other LaneRegions
   *
   * \returns Reference to this LaneRegions.
   */
  LaneRegions &operator=(LaneRegions &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneRegions
   *
   * \returns \c true if both LaneRegions are equal
   */
  bool operator==(const LaneRegions &other) const
  {
    return (fully_occluded == other.fully_occluded) && (partly_occluded == other.partly_occluded)
      && (fully_visible == other.fully_visible) && (reference_position == other.reference_position);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other LaneRegions.
   *
   * \returns \c true if both LaneRegions are different
   */
  bool operator!=(const LaneRegions &other) const
  {
    return !operator==(other);
  }

  /*!
   * The lane regions that are fully occluded
   */
  ::ad::map::match::LaneOccupiedRegionList fully_occluded;

  /*!
   * The lane regions that are partly occluded
   */
  ::ad::map::match::LaneOccupiedRegionList partly_occluded;

  /*!
   * The lane regions that are fully visible
   */
  ::ad::map::match::LaneOccupiedRegionList fully_visible;

  /*!
   * The reference position of the lane regions.
   */
  ::ad::map::point::BoundingSphere reference_position;
};

} // namespace geometry
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_GEOMETRY_LANEREGIONS
#define GEN_GUARD_AD_MAP_GEOMETRY_LANEREGIONS
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace geometry
 */
namespace geometry {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value LaneRegions value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, LaneRegions const &_value)
{
  os << "LaneRegions(";
  os << "fully_occluded:";
  os << _value.fully_occluded;
  os << ",";
  os << "partly_occluded:";
  os << _value.partly_occluded;
  os << ",";
  os << "fully_visible:";
  os << _value.fully_visible;
  os << ",";
  os << "reference_position:";
  os << _value.reference_position;
  os << ")";
  return os;
}

} // namespace geometry
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for LaneRegions
 */
inline std::string to_string(::ad::map::geometry::LaneRegions const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::geometry::LaneRegions> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::geometry::LaneRegions const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_GEOMETRY_LANEREGIONS
