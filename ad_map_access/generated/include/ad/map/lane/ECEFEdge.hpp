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
#include "ad/map/point/ECEFPointList.hpp"
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
 * \brief DataType ECEFEdge
 *
 * Ordered list of ECEF Points desribing the directed border of a lane interval.
 */
struct ECEFEdge
{
  /*!
   * \brief Smart pointer on ECEFEdge
   */
  typedef std::shared_ptr<ECEFEdge> Ptr;

  /*!
   * \brief Smart pointer on constant ECEFEdge
   */
  typedef std::shared_ptr<ECEFEdge const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  ECEFEdge() = default;

  /*!
   * \brief standard destructor
   */
  ~ECEFEdge() = default;

  /*!
   * \brief standard copy constructor
   */
  ECEFEdge(const ECEFEdge &other) = default;

  /*!
   * \brief standard move constructor
   */
  ECEFEdge(ECEFEdge &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other ECEFEdge
   *
   * \returns Reference to this ECEFEdge.
   */
  ECEFEdge &operator=(const ECEFEdge &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other ECEFEdge
   *
   * \returns Reference to this ECEFEdge.
   */
  ECEFEdge &operator=(ECEFEdge &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ECEFEdge
   *
   * \returns \c true if both ECEFEdge are equal
   */
  bool operator==(const ECEFEdge &other) const
  {
    return (points == other.points) && (edge_type == other.edge_type) && (lateral_alignment == other.lateral_alignment);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ECEFEdge.
   *
   * \returns \c true if both ECEFEdge are different
   */
  bool operator!=(const ECEFEdge &other) const
  {
    return !operator==(other);
  }

  /*!
   * The list of ordered ECEF points of this edge.
   */
  ::ad::map::point::ECEFPointList points;

  /*!
   * Defines the lateral position of the edge points in relation to the lane it is derived from.
   */
  ::ad::map::lane::EdgeType edge_type{::ad::map::lane::EdgeType::UNKNOWN};

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
};

} // namespace lane
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_ECEFEDGE
#define GEN_GUARD_AD_MAP_LANE_ECEFEDGE
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
 * \param[in] _value ECEFEdge value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, ECEFEdge const &_value)
{
  os << "ECEFEdge(";
  os << "points:";
  os << _value.points;
  os << ",";
  os << "edge_type:";
  os << _value.edge_type;
  os << ",";
  os << "lateral_alignment:";
  os << _value.lateral_alignment;
  os << ")";
  return os;
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for ECEFEdge
 */
inline std::string to_string(::ad::map::lane::ECEFEdge const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::ECEFEdge> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::ECEFEdge const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_ECEFEDGE
