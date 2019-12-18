// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <deque>
#include <map>
#include "ad/map/route/RouteExpander.hpp"
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
 * @brief cost data for route prediction
 */
struct RoutePredictionCost
{
  physics::Distance routeDistance{0.};
  physics::Duration routeDuration{0.};
};

/**
 * @brief Implements route prediction on the lane network.
 */
class RoutePrediction : public RouteExpander<RoutePredictionCost>
{
public:
  using RouteExpander::RoutingPoint;

  /**
   * @brief Constructor.
   *
   *    Calculates route predictions from a starting point until either the given predictionDistance or the given
   * predictionDuration is reached.
   *
   * @param[in] start Start point.
   * @param[in] predictionDistance maximum prediction distance.
   * @param[in] predictionDuration maximum prediction duration.
   */
  RoutePrediction(const RoutingParaPoint &start,
                  physics::Distance const &predictionDistance,
                  physics::Duration const &predictionDuration);

  /**
   * @brief Constructor.
   *
   *    Calculates route predictions from a starting point until either the given predictionDistance is reached.
   *
   * @param[in] start Start point.
   * @param[in] predictionDistance maximum prediction distance.
   */
  RoutePrediction(const RoutingParaPoint &start, physics::Distance const &predictionDistance);

  /**
   * @brief Constructor.
   *
   *    Calculates route predictions from a starting point until either the given predictionDuration is reached.
   *
   * @param[in] start Start point.
   * @param[in] predictionDuration maximum prediction duration.
   */
  RoutePrediction(const RoutingParaPoint &start, physics::Duration const &predictionDuration);

  /**
   * @brief Calculates the route predictions using breadth search algorithm.
   */
  bool calculate() override;

private:
  /**
   * @brief Reimplemented from RouteExpander::AddNeighbor()
   */
  void addNeighbor(lane::Lane::ConstPtr originLane,
                   RoutingPoint const &origin,
                   lane::Lane::ConstPtr neighborLane,
                   RoutingParaPoint const &neighbor,
                   ExpandReason const &expandReason) override;

  /**
   * @brief Element of the routing tree
   */
  struct RouteTreeElement
  {
    //! Constructor.
    RouteTreeElement(RouteTreeElement const *parent,
                     RoutingParaPoint const &routingParaPoint,
                     RoutePredictionCost const predictionCost = RoutePredictionCost())
      : routingPoint({routingParaPoint, predictionCost})
      , theParent(parent)
    {
    }

    //! function used for path reconstruction. All leaves have to add their path
    void addPaths(std::vector<point::ParaPointList> &paths);

    //! comparing route tree elements by their actual route-point to ensure children are unique
    struct RouteTreeElementCompare
    {
      bool operator()(const std::shared_ptr<RouteTreeElement> &left, const std::shared_ptr<RouteTreeElement> &right)
      {
        return left->routingPoint.first < right->routingPoint.first;
      }
    };

    //! the routing point represented by this tree element
    RoutingPoint routingPoint;
    //! the children of the tree element. If children are empty, the element is a leaf of the tree
    std::set<std::shared_ptr<RouteTreeElement>, RouteTreeElementCompare> children;
    //! pointer to the parent, required for later reconstruction of the paths
    RouteTreeElement const *const theParent;
  };

  /**
   * @brief reconstruct the path after search finished
   */
  void reconstructPaths();

  //! prediction distance to be used
  physics::Distance const mPredictionDistance;
  //! prediction duration to be used
  physics::Duration const mPredictionDuration;

  //! the tree root element
  std::shared_ptr<RouteTreeElement> mRouteTreeRoot;

  /**
   * @brief the already processed transitions from -> {to} (only process a transition once)
   */
  std::map<RoutingParaPoint, RoutingParaPointSet> mProcessedTransitions;

  //! the list of elements to be processed
  std::deque<std::shared_ptr<RouteTreeElement>> mElementsToProcess;
};

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
