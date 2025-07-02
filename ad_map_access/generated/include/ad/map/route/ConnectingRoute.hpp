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
#include "ad/map/point/ENUHeading.hpp"
#include "ad/map/route/ConnectingRouteType.hpp"
#include "ad/map/route/FullRoute.hpp"
#include "ad/physics/Distance.hpp"
#include "ad/physics/Probability.hpp"
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
 * \brief DataType ConnectingRoute
 *
 * A special route connecting two objects, A and B, in the map. The connection route
 * consists of two routes.
 * route_a is non empty, if the shorted path between A and B can be traveled by A in
 * forward direction.
 * route_b is non empty, if the shorted path between A and B can be traveled by B in
 * forward direction.
 * We have the following possibilities:
 * 1: There exists no connecting route (according to the search length/distance restrictions
 * ): both route_a and route_b are empty
 * 2: A and B are driving in same direction: one is able to reach the other with driving
 * forward, but not vice versa
 * 2.1: If A is in front of B: route_a is empty, route_b contains the route part from
 * B towards A
 * 2.2: If B is in front of A: route_b is empty, route_a contains the route part from
 * A towards B
 * 3. A and B driving in opposite direction: both are able to reach each other by driving
 * forward:
 * route_a contains the route part from A towards B and route_b the inverted route
 * part from B towards A.
 * 4. A and B can reach each other directly, but their routes merge at some point:
 * route_a contains the route part from A towards the merge point
 * route_b contains the route part from B towards the merge point
 */
struct ConnectingRoute
{
  /*!
   * \brief Smart pointer on ConnectingRoute
   */
  typedef std::shared_ptr<ConnectingRoute> Ptr;

  /*!
   * \brief Smart pointer on constant ConnectingRoute
   */
  typedef std::shared_ptr<ConnectingRoute const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  ConnectingRoute() = default;

  /*!
   * \brief standard destructor
   */
  ~ConnectingRoute() = default;

  /*!
   * \brief standard copy constructor
   */
  ConnectingRoute(const ConnectingRoute &other) = default;

  /*!
   * \brief standard move constructor
   */
  ConnectingRoute(ConnectingRoute &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other ConnectingRoute
   *
   * \returns Reference to this ConnectingRoute.
   */
  ConnectingRoute &operator=(const ConnectingRoute &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other ConnectingRoute
   *
   * \returns Reference to this ConnectingRoute.
   */
  ConnectingRoute &operator=(ConnectingRoute &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ConnectingRoute
   *
   * \returns \c true if both ConnectingRoute are equal
   */
  bool operator==(const ConnectingRoute &other) const
  {
    return (type == other.type) && (route_a == other.route_a) && (route_b == other.route_b)
      && (route_a_length == other.route_a_length) && (route_b_length == other.route_b_length)
      && (heading_rating_a == other.heading_rating_a) && (heading_rating_b == other.heading_rating_b)
      && (route_a_heading_start == other.route_a_heading_start) && (route_a_heading_end == other.route_a_heading_end)
      && (route_b_heading_start == other.route_b_heading_start) && (route_b_heading_end == other.route_b_heading_end);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ConnectingRoute.
   *
   * \returns \c true if both ConnectingRoute are different
   */
  bool operator!=(const ConnectingRoute &other) const
  {
    return !operator==(other);
  }

  /*!
   * The type of connecting route.
   */
  ::ad::map::route::ConnectingRouteType type{::ad::map::route::ConnectingRouteType::Invalid};

  /*!
   * The route prefix of object A.
   * This part of the connected route is only used by object A to travel towards B.
   * If B is behind A, this part of the connecting route is empty.
   */
  ::ad::map::route::FullRoute route_a;

  /*!
   * The route prefix of object B.
   * This part of the connected route is only used by object B to travel towards A.
   * If A is behind B, this part of the connecting route is empty.
   */
  ::ad::map::route::FullRoute route_b;

  /*!
   * Length of route_a
   */
  ::ad::physics::Distance route_a_length{0.0};

  /*!
   * Length of route_b
   */
  ::ad::physics::Distance route_b_length{0.0};

  /*!
   * A rating value on the heading of object a in respect to the heading of the connected
   * route at the position of object a:
   * - If headingDifference > physics::cPI_2: rating=0
   * - Else rating = (1. - 2. * headingDifference / physics::cPI)
   * With headingDifference always beeing positive.
   */
  ::ad::physics::Probability heading_rating_a{0.0};

  /*!
   * A rating value on the heading of object b in respect to the heading of the connected
   * route at the position of object b:
   * - If headingDifference > physics::cPI_2: rating=0
   * - Else rating = (1. - 2. * headingDifference / physics::cPI)
   * With headingDifference always beeing positive.
   */
  ::ad::physics::Probability heading_rating_b{0.0};

  /*!
   * ENU Heading of the route_a at the start of the route.
   */
  ::ad::map::point::ENUHeading route_a_heading_start{0.0};

  /*!
   * ENU Heading of the route_a at the end of the route.
   */
  ::ad::map::point::ENUHeading route_a_heading_end{0.0};

  /*!
   * ENU Heading of the route_b at the start of the route.
   */
  ::ad::map::point::ENUHeading route_b_heading_start{0.0};

  /*!
   * ENU Heading of the route_b at the end of the route.
   */
  ::ad::map::point::ENUHeading route_b_heading_end{0.0};
};

} // namespace route
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_ROUTE_CONNECTINGROUTE
#define GEN_GUARD_AD_MAP_ROUTE_CONNECTINGROUTE
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
 * \param[in] _value ConnectingRoute value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, ConnectingRoute const &_value)
{
  os << "ConnectingRoute(";
  os << "type:";
  os << _value.type;
  os << ",";
  os << "route_a:";
  os << _value.route_a;
  os << ",";
  os << "route_b:";
  os << _value.route_b;
  os << ",";
  os << "route_a_length:";
  os << _value.route_a_length;
  os << ",";
  os << "route_b_length:";
  os << _value.route_b_length;
  os << ",";
  os << "heading_rating_a:";
  os << _value.heading_rating_a;
  os << ",";
  os << "heading_rating_b:";
  os << _value.heading_rating_b;
  os << ",";
  os << "route_a_heading_start:";
  os << _value.route_a_heading_start;
  os << ",";
  os << "route_a_heading_end:";
  os << _value.route_a_heading_end;
  os << ",";
  os << "route_b_heading_start:";
  os << _value.route_b_heading_start;
  os << ",";
  os << "route_b_heading_end:";
  os << _value.route_b_heading_end;
  os << ")";
  return os;
}

} // namespace route
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for ConnectingRoute
 */
inline std::string to_string(::ad::map::route::ConnectingRoute const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::route::ConnectingRoute> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::route::ConnectingRoute const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_ROUTE_CONNECTINGROUTE
