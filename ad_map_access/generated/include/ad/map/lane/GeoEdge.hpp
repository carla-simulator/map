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
#include "ad/map/point/GeoPointList.hpp"
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
 * \brief DataType GeoEdge
 *
 * Ordered list of Geo Points desribing the directed border of a lane interval.
 */
struct GeoEdge
{
  /*!
   * \brief Smart pointer on GeoEdge
   */
  typedef std::shared_ptr<GeoEdge> Ptr;

  /*!
   * \brief Smart pointer on constant GeoEdge
   */
  typedef std::shared_ptr<GeoEdge const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  GeoEdge() = default;

  /*!
   * \brief standard destructor
   */
  ~GeoEdge() = default;

  /*!
   * \brief standard copy constructor
   */
  GeoEdge(const GeoEdge &other) = default;

  /*!
   * \brief standard move constructor
   */
  GeoEdge(GeoEdge &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other GeoEdge
   *
   * \returns Reference to this GeoEdge.
   */
  GeoEdge &operator=(const GeoEdge &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other GeoEdge
   *
   * \returns Reference to this GeoEdge.
   */
  GeoEdge &operator=(GeoEdge &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other GeoEdge
   *
   * \returns \c true if both GeoEdge are equal
   */
  bool operator==(const GeoEdge &other) const
  {
    return (lateral_alignment == other.lateral_alignment) && (points == other.points) && (edge_type == other.edge_type);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other GeoEdge.
   *
   * \returns \c true if both GeoEdge are different
   */
  bool operator!=(const GeoEdge &other) const
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
   * The list of ordered Geo points of this edge.
   */
  ::ad::map::point::GeoPointList points;

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
#ifndef GEN_GUARD_AD_MAP_LANE_GEOEDGE
#define GEN_GUARD_AD_MAP_LANE_GEOEDGE
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
 * \param[in] _value GeoEdge value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, GeoEdge const &_value)
{
  os << "GeoEdge(";
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
 * \brief overload of the std::to_string for GeoEdge
 */
inline std::string to_string(::ad::map::lane::GeoEdge const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::GeoEdge> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::GeoEdge const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_GEOEDGE
