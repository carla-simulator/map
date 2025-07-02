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
#include "ad/map/landmark/LandmarkIdList.hpp"
#include "ad/map/lane/ComplianceVersion.hpp"
#include "ad/map/lane/ContactLaneList.hpp"
#include "ad/map/lane/LaneDirection.hpp"
#include "ad/map/lane/LaneId.hpp"
#include "ad/map/lane/LaneType.hpp"
#include "ad/map/point/BoundingSphere.hpp"
#include "ad/map/point/Geometry.hpp"
#include "ad/map/restriction/Restrictions.hpp"
#include "ad/map/restriction/SpeedLimitList.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/MetricRange.hpp"
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
 * \brief DataType Lane
 *
 * Specification of a lane
 */
struct Lane
{
  /*!
   * \brief Smart pointer on Lane
   */
  typedef std::shared_ptr<Lane> Ptr;

  /*!
   * \brief Smart pointer on constant Lane
   */
  typedef std::shared_ptr<Lane const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  Lane() = default;

  /*!
   * \brief standard destructor
   */
  ~Lane() = default;

  /*!
   * \brief standard copy constructor
   */
  Lane(const Lane &other) = default;

  /*!
   * \brief standard move constructor
   */
  Lane(Lane &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Lane
   *
   * \returns Reference to this Lane.
   */
  Lane &operator=(const Lane &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Lane
   *
   * \returns Reference to this Lane.
   */
  Lane &operator=(Lane &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Lane
   *
   * \returns \c true if both Lane are equal
   */
  bool operator==(const Lane &other) const
  {
    return (id == other.id) && (type == other.type) && (direction == other.direction)
      && (restrictions == other.restrictions) && (length == other.length) && (length_range == other.length_range)
      && (width == other.width) && (width_range == other.width_range) && (speed_limits == other.speed_limits)
      && (edge_left == other.edge_left) && (edge_right == other.edge_right) && (contact_lanes == other.contact_lanes)
      && (compliance_version == other.compliance_version) && (bounding_sphere == other.bounding_sphere)
      && (visible_landmarks == other.visible_landmarks);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Lane.
   *
   * \returns \c true if both Lane are different
   */
  bool operator!=(const Lane &other) const
  {
    return !operator==(other);
  }

  /*!
   * Identifier of the lane
   */
  ::ad::map::lane::LaneId id;

  /*!
   * Type of the lane
   */
  ::ad::map::lane::LaneType type{::ad::map::lane::LaneType::UNKNOWN};

  /*!
   * Driving direction of the lane
   */
  ::ad::map::lane::LaneDirection direction{::ad::map::lane::LaneDirection::INVALID};

  /*!
   * List of restrictions
   */
  ::ad::map::restriction::Restrictions restrictions;

  /*!
   * Length of the lane
   */
  ::ad::physics::Distance length;
  ::ad::physics::MetricRange length_range;

  /*!
   * Width of the lane
   */
  ::ad::physics::Distance width;
  ::ad::physics::MetricRange width_range;

  /*!
   * List of speed limits
   */
  ::ad::map::restriction::SpeedLimitList speed_limits;

  /*!
   * Left edge of the lane
   */
  ::ad::map::point::Geometry edge_left;

  /*!
   * Right edge of the lane
   */
  ::ad::map::point::Geometry edge_right;

  /*!
   * List of contacting lanes
   */
  ::ad::map::lane::ContactLaneList contact_lanes;
  ::ad::map::lane::ComplianceVersion compliance_version{0};
  ::ad::map::point::BoundingSphere bounding_sphere;

  /*!
   * List of visible landmarks
   */
  ::ad::map::landmark::LandmarkIdList visible_landmarks;
};

} // namespace lane
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANE_LANE
#define GEN_GUARD_AD_MAP_LANE_LANE
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
 * \param[in] _value Lane value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Lane const &_value)
{
  os << "Lane(";
  os << "id:";
  os << _value.id;
  os << ",";
  os << "type:";
  os << _value.type;
  os << ",";
  os << "direction:";
  os << _value.direction;
  os << ",";
  os << "restrictions:";
  os << _value.restrictions;
  os << ",";
  os << "length:";
  os << _value.length;
  os << ",";
  os << "length_range:";
  os << _value.length_range;
  os << ",";
  os << "width:";
  os << _value.width;
  os << ",";
  os << "width_range:";
  os << _value.width_range;
  os << ",";
  os << "speed_limits:";
  os << _value.speed_limits;
  os << ",";
  os << "edge_left:";
  os << _value.edge_left;
  os << ",";
  os << "edge_right:";
  os << _value.edge_right;
  os << ",";
  os << "contact_lanes:";
  os << _value.contact_lanes;
  os << ",";
  os << "compliance_version:";
  os << _value.compliance_version;
  os << ",";
  os << "bounding_sphere:";
  os << _value.bounding_sphere;
  os << ",";
  os << "visible_landmarks:";
  os << _value.visible_landmarks;
  os << ")";
  return os;
}

} // namespace lane
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Lane
 */
inline std::string to_string(::ad::map::lane::Lane const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::Lane> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::Lane const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANE_LANE
