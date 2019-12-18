// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <utility>

#include "ad/map/lane/LaneOperation.hpp"
#include "ad/map/route/Route.hpp"

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
 * @brief Implements routing support functionality on the lane network.
 *
 * This class is used to expand a route by its reachable neighbors.
 * The routing cost data is defined by a template type to be defined by the actual routing class.
 */
template <class RoutingCostData> class RouteExpander : public Route
{
public:
  //! definition of the routing point
  typedef std::pair<RoutingParaPoint, RoutingCostData> RoutingPoint;

  /**
   * @brief Constructor
   *
   * @param[in] start Start point.
   * @param[in] dest  Destination point.
   * @param[in] typ   Type of the route to be calculated.
   */
  RouteExpander(const RoutingParaPoint &start, const RoutingParaPoint &dest, Type const &routingType)
    : Route(start, dest, routingType)
  {
  }

  RouteExpander(RouteExpander const &) = delete;
  RouteExpander(RouteExpander const &&) = delete;
  RouteExpander &operator=(RouteExpander const &) = delete;
  RouteExpander &operator=(RouteExpander &&) = delete;

  /**
   * @brief destructor.
   */
  virtual ~RouteExpander() = default;

  /**
   * @brief Triggers the expansion of the given routing point \a origin to its valid neighborhood
   */
  void expandNeighbors(RoutingPoint const &origin);

protected:
  /**
   * @brief Definition of the reasons for route expansion
   */
  enum class ExpandReason
  {
    SameLaneNeighbor,     //!< expand the route by a neighbor point within the same lane
    LongitudinalNeighbor, //!< expand the route by a longitudinal neighbor lane point
    LateralNeighbor,      //!< expand the route by a lateral neighbor lane point
    Destination,          //!< expand the destination
  };

  /**
   * @brief a neighbor is added
   *
   * Override this function in the derived class to get notified on expanded neighbors.
   *
   * @param[in] originLane the lane object of the \a origin point
   * @param[in] origin the origin RoutingPoint provided to the ExpandNeighbors() function
   * @param[in] neighborLane the lane object of the \a neighbor point
   * @param[in] neighbor the neighbor point which is added
   * @param[in] expandReason the reason why the origin was expanded to this neighbor
   */
  virtual void addNeighbor(lane::Lane::ConstPtr originLane,
                           RoutingPoint const &origin,
                           lane::Lane::ConstPtr neighborLane,
                           RoutingParaPoint const &neighbor,
                           ExpandReason const &expandReason)
    = 0;

  //! @returns \c true if the given origin point is the parametric start
  bool isStart(RoutingPoint const &origin)
  {
    return origin.first.point.parametricOffset == physics::ParametricValue(0.);
  }

  //! @returns \c true if the given origin point is the parametric end
  bool isEnd(RoutingPoint const &origin)
  {
    return origin.first.point.parametricOffset == physics::ParametricValue(1.);
  }

  //! @returns \c true if the given origin point on the given lane defines a positive movement
  bool isPositiveMovement(lane::Lane::ConstPtr lane, RoutingPoint const &origin)
  {
    return (laneDirectionIsIgnored() || isLaneDirectionPositive(*lane))
      && (origin.first.direction != RoutingDirection::NEGATIVE);
  }

  //! @returns \c true if the given origin point on the given lane defines a negative movement
  bool isNegativeMovement(lane::Lane::ConstPtr lane, RoutingPoint const &origin)
  {
    return (laneDirectionIsIgnored() || isLaneDirectionNegative(*lane))
      && (origin.first.direction != RoutingDirection::POSITIVE);
  }

  //! perform the expansion of the neighbor points on the same lane
  void expandSameLaneNeighbors(lane::Lane::ConstPtr lane, RoutingPoint const &origin);
  //! perform the expansion of the neighbor points in longitudinal (contacts: successor/predecessor) lane direction
  void expandLongitudinalNeighbors(lane::Lane::ConstPtr lane, RoutingPoint const &origin);
  //! perform the expansion of the neighbor points in lateral (contacts: left/right) lane direction
  void expandLateralNeighbors(lane::Lane::ConstPtr lane, RoutingPoint const &origin);
};

template <class RoutingCostData>
void RouteExpander<RoutingCostData>::expandNeighbors(
  typename RouteExpander<RoutingCostData>::RoutingPoint const &origin)
{
  lane::Lane::ConstPtr lane = lane::getLanePtr(origin.first.point.laneId);
  if (lane)
  {
    if (isRouteable(*lane))
    {
      expandSameLaneNeighbors(lane, origin);
      expandLongitudinalNeighbors(lane, origin);
      expandLateralNeighbors(lane, origin);
    }
  }
  else
  {
    throw std::runtime_error("RouteExpander::ExpandNeighbors No lane!");
  }
}

template <class RoutingCostData>
void RouteExpander<RoutingCostData>::expandSameLaneNeighbors(
  lane::Lane::ConstPtr lane, typename RouteExpander<RoutingCostData>::RoutingPoint const &origin)
{
  if ((lane->id == getDest().laneId)
      && ((isPositiveMovement(lane, origin) && (origin.first.point.parametricOffset <= getDest().parametricOffset))
          || (isNegativeMovement(lane, origin) && (origin.first.point.parametricOffset >= getDest().parametricOffset))))
  {
    // approaching the destination from valid side
    addNeighbor(lane, origin, lane, getRoutingDest(), ExpandReason::Destination);
  }
  if (isPositiveMovement(lane, origin) && !isEnd(origin))
  {
    addNeighbor(lane,
                origin,
                lane,
                createRoutingParaPoint(lane->id, physics::ParametricValue(1.), origin.first.direction),
                ExpandReason::SameLaneNeighbor);
  }
  if (isNegativeMovement(lane, origin) && !isStart(origin))
  {
    addNeighbor(lane,
                origin,
                lane,
                createRoutingParaPoint(lane->id, physics::ParametricValue(0.), origin.first.direction),
                ExpandReason::SameLaneNeighbor);
  }
}

template <class RoutingCostData>
void RouteExpander<RoutingCostData>::expandLongitudinalNeighbors(
  lane::Lane::ConstPtr lane, typename RouteExpander<RoutingCostData>::RoutingPoint const &origin)
{
  lane::ContactLaneList contact_lanes;
  if (isEnd(origin) && isPositiveMovement(lane, origin))
  {
    contact_lanes = getContactLanes(*lane, lane::ContactLocation::SUCCESSOR);
  }
  else if (isStart(origin) && isNegativeMovement(lane, origin))
  {
    contact_lanes = getContactLanes(*lane, lane::ContactLocation::PREDECESSOR);
  }
  for (auto contact_lane : contact_lanes)
  {
    lane::Lane::ConstPtr other_lane = lane::getLanePtr(contact_lane.toLane);
    if (other_lane)
    {
      if (isRouteable(*other_lane))
      {
        lane::ContactLocation other_to_lane = getContactLocation(*other_lane, lane->id);
        if (other_to_lane == lane::ContactLocation::SUCCESSOR)
        {
          auto routingDirection = RoutingDirection::NEGATIVE;
          if (origin.first.direction == RoutingDirection::DONT_CARE)
          {
            routingDirection = RoutingDirection::DONT_CARE;
          }
          addNeighbor(lane,
                      origin,
                      other_lane,
                      createRoutingParaPoint(other_lane->id, physics::ParametricValue(1.), routingDirection),
                      ExpandReason::LongitudinalNeighbor);
        }
        else if (other_to_lane == lane::ContactLocation::PREDECESSOR)
        {
          auto routingDirection = RoutingDirection::POSITIVE;
          if (origin.first.direction == RoutingDirection::DONT_CARE)
          {
            routingDirection = RoutingDirection::DONT_CARE;
          }
          addNeighbor(lane,
                      origin,
                      other_lane,
                      createRoutingParaPoint(other_lane->id, physics::ParametricValue(0.), routingDirection),
                      ExpandReason::LongitudinalNeighbor);
        }
        else
        {
          throw std::runtime_error("Other lane neither SUCCESSOR not PREDECESSOR!");
        }
      }
    }
    else
    {
      throw std::runtime_error("No other lane!");
    }
  }
}

template <class RoutingCostData>
void RouteExpander<RoutingCostData>::expandLateralNeighbors(
  lane::Lane::ConstPtr lane, typename RouteExpander<RoutingCostData>::RoutingPoint const &origin)
{
  if (lane->type != lane::LaneType::INTERSECTION)
  {
    for (auto const &contact_lane : getContactLanes(*lane, {lane::ContactLocation::LEFT, lane::ContactLocation::RIGHT}))
    {
      lane::Lane::ConstPtr other_lane = lane::getLanePtr(contact_lane.toLane);
      if (other_lane)
      {
        if (isRouteable(*other_lane))
        {
          if (laneDirectionIsIgnored() || (lane->direction == other_lane->direction))
          {
            addNeighbor(
              lane,
              origin,
              other_lane,
              createRoutingParaPoint(other_lane->id, origin.first.point.parametricOffset, origin.first.direction),
              ExpandReason::LateralNeighbor);
          }
        }
      }
      else
      {
        throw std::runtime_error("No other lane!");
      }
    }
  }
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
