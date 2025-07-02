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
#include "ad/map/point/ParaPoint.hpp"
#include "ad/map/route/planning/RoutingDirection.hpp"
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
 * @brief namespace planning
 */
namespace planning {

/*!
 * \brief DataType RoutingParaPoint
 *
 * It is essential to know in which direction a vehicle is oriented in respect to the
 * lane when trying to route.
 * Therefore, the routing para point extends the para point by a RoutingDirection.
 */
struct RoutingParaPoint
{
  /*!
   * \brief Smart pointer on RoutingParaPoint
   */
  typedef std::shared_ptr<RoutingParaPoint> Ptr;

  /*!
   * \brief Smart pointer on constant RoutingParaPoint
   */
  typedef std::shared_ptr<RoutingParaPoint const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  RoutingParaPoint() = default;

  /*!
   * \brief standard destructor
   */
  ~RoutingParaPoint() = default;

  /*!
   * \brief standard copy constructor
   */
  RoutingParaPoint(const RoutingParaPoint &other) = default;

  /*!
   * \brief standard move constructor
   */
  RoutingParaPoint(RoutingParaPoint &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other RoutingParaPoint
   *
   * \returns Reference to this RoutingParaPoint.
   */
  RoutingParaPoint &operator=(const RoutingParaPoint &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other RoutingParaPoint
   *
   * \returns Reference to this RoutingParaPoint.
   */
  RoutingParaPoint &operator=(RoutingParaPoint &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RoutingParaPoint
   *
   * \returns \c true if both RoutingParaPoint are equal
   */
  bool operator==(const RoutingParaPoint &other) const
  {
    return (point == other.point) && (direction == other.direction);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other RoutingParaPoint.
   *
   * \returns \c true if both RoutingParaPoint are different
   */
  bool operator!=(const RoutingParaPoint &other) const
  {
    return !operator==(other);
  }

  /*!
   * The referred para point of the routing.
   */
  ::ad::map::point::ParaPoint point;

  /*!
   * The direction at the routing point to be considered.
   */
  ::ad::map::route::planning::RoutingDirection direction{::ad::map::route::planning::RoutingDirection::DONT_CARE};
};

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
#define GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
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
 * @brief namespace planning
 */
namespace planning {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value RoutingParaPoint value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, RoutingParaPoint const &_value)
{
  os << "RoutingParaPoint(";
  os << "point:";
  os << _value.point;
  os << ",";
  os << "direction:";
  os << _value.direction;
  os << ")";
  return os;
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for RoutingParaPoint
 */
inline std::string to_string(::ad::map::route::planning::RoutingParaPoint const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::planning::RoutingParaPoint> : formatter<string_view>
{
  template <typename FormatContext>
  auto format(::ad::map::route::planning::RoutingParaPoint const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_PLANNING_ROUTINGPARAPOINT
