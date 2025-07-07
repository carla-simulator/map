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
#include "ad/map/lane/EdgeType.hpp"
#include "ad/map/point/ENUPointList.hpp"
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
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/*!
 * \brief DataType ENUEdge
 *
 * Ordered list of ENU Points desribing the directed border of a lane interval.
 */
struct ENUEdge
{
  /*!
   * \brief Smart pointer on ENUEdge
   */
  typedef std::shared_ptr<ENUEdge> Ptr;

  /*!
   * \brief Smart pointer on constant ENUEdge
   */
  typedef std::shared_ptr<ENUEdge const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  ENUEdge() = default;

  /*!
   * \brief standard destructor
   */
  ~ENUEdge() = default;

  /*!
   * \brief standard copy constructor
   */
  ENUEdge(const ENUEdge &other) = default;

  /*!
   * \brief standard move constructor
   */
  ENUEdge(ENUEdge &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other ENUEdge
   *
   * \returns Reference to this ENUEdge.
   */
  ENUEdge &operator=(const ENUEdge &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other ENUEdge
   *
   * \returns Reference to this ENUEdge.
   */
  ENUEdge &operator=(ENUEdge &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUEdge
   *
   * \returns \c true if both ENUEdge are equal
   */
  bool operator==(const ENUEdge &other) const
  {
    return (lateral_alignment == other.lateral_alignment) && (points == other.points) && (edge_type == other.edge_type);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ENUEdge.
   *
   * \returns \c true if both ENUEdge are different
   */
  bool operator!=(const ENUEdge &other) const
  {
    return !operator==(other);
  }

  /*!
   * Defines the lateral position of the edge points in relation to the lane/segment/route
   * it is derived from.
   * The lateral alignment is within the bounds [0.0; 1.0] and holds these values for
   * defined edge EdgeType:
   * 1.0: EdgeType::LEFT
   * 0.5: EdgeType::CENTER
   * 0.0: EdgeType::RIGTH
   * [0.0; 1.0]: EdgeType::ALIGNED
   * <invalid>: EdgeType::UNKNOWN
   */
  ::ad::physics::ParametricValue lateral_alignment;

  /*!
   * The list of ordered ENU points of this edge.
   */
  ::ad::map::point::ENUPointList points;

  /*!
   * Defines the lateral position of the edge points in relation to the lane it is derived from.
   */
  ::ad::map::lane::EdgeType edge_type{::ad::map::lane::EdgeType::UNKNOWN};
};

} // namespace lane
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_ENUEDGE
#define GEN_GUARD_AD_MAP_LANE_ENUEDGE
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value ENUEdge value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, ENUEdge const &_value)
{
  os << "ENUEdge(";
  os << "lateral_alignment:";
  os << _value.lateral_alignment;
  os << ",";
  os << "points:";
  os << _value.points;
  os << ",";
  os << "edge_type:";
  os << _value.edge_type;
  os << ")";
  return os;
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for ENUEdge
 */
inline std::string to_string(::ad::map::lane::ENUEdge const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::ENUEdge> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::ENUEdge const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_ENUEDGE
