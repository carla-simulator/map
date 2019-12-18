// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/point/ParaPointList.hpp"
#include "ad/map/route/Routing.hpp"

/* @brief namespace ad */
namespace ad {
/* @brief namespace map */
namespace map {
/* @brief namespace route */
namespace route {
/**
 * @namespace planning
 * @brief provides route planning capabilities on the road network of the map
 */
namespace planning {

/**
 * @brief Implements routing on the lane network.
 */
class Route
{
public:
  /**
   * @brief Full route description.
   */
  typedef std::vector<point::ParaPointList> FullRoute;

  /**
   * @brief Routing type.
   */
  enum class Type
  {
    INVALID,                   ///< Invalid value.
    SHORTEST,                  ///< Shortest route by distance.
    SHORTEST_IGNORE_DIRECTION, ///< Shortest route by distance, allow to drive also in lanes with other direction
  };

  /**
   * @brief Constructor. Calculates route between two points.
   * @param[in] start Start point.
   * @param[in] dest  Destination point.
   * @param[in] routingType   Type of the route to be calculated.
   */
  Route(const RoutingParaPoint &start, const RoutingParaPoint &dest, Type const &routingType);

  Route(Route const &) = delete;
  Route(Route const &&) = delete;
  Route &operator=(Route const &) = delete;
  Route &operator=(Route &&) = delete;

  /**
   * @brief Destructor.
   */
  virtual ~Route() = default;

  /** @returns Start point as ParaPoint. */
  const point::ParaPoint &getStart() const
  {
    return start_.point;
  }

  /** @returns Start point as RoutingParaPoint. */
  const RoutingParaPoint &getRoutingStart() const
  {
    return start_;
  }

  /** @returns Destination point as ParaPoint. */
  const point::ParaPoint &getDest() const
  {
    return dest_.point;
  }

  /** @returns Destination point as RoutingParaPoint. */
  const RoutingParaPoint &getRoutingDest() const
  {
    return dest_;
  }

  /** @returns Type of the route to be calculated. */
  Type getType() const
  {
    return type_;
  }

  /**
   * @returns true if route calculation ignores lane direction.
   */
  bool laneDirectionIsIgnored() const;

  /**
   * @brief Performs the routing.
   * @returns true if routing succeeded.
   */
  virtual bool calculate() = 0;

  /**
   * @returns true if calculated route is valid.
   */
  bool isValid() const
  {
    return valid_;
  }

  /** @returns Raw calculated route. */
  const point::ParaPointList &getRawRoute(size_t const routeIndex = 0u) const;

  /** @returns Raw calculated route. */
  const std::vector<point::ParaPointList> &getRawRoutes() const
  {
    return raw_routes;
  }

  /** @returns Full calculated route. */
  FullRoute getFullRoute(size_t const routeIndex = 0u) const;

  /** @returns All full calculated routes. */
  std::vector<FullRoute> getFullRoutes() const;

protected:
  RoutingParaPoint start_; ///< Start point.
  RoutingParaPoint dest_;  ///< Destination point.
  Type type_;              ///< Type of the route to be calculated.

  bool valid_;                                  ///< Indicates if calculation was successful.
  std::vector<point::ParaPointList> raw_routes; ///< Calculated routes.
};

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
