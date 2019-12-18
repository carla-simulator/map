// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RoutePrediction.hpp"

// need to make RouteTreeElement public if debug output is required!
#define DEBUG_OUTPUT 0

#if DEBUG_OUTPUT
#include <iostream>

inline std::ostream &operator<<(std::ostream &out, ad::map::point::ParaPoint const &value)
{
  out << "(" << static_cast<uint64_t>(value.laneId) << "|" << static_cast<double>(value.parametricOffset) << ")";
  return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                ad::map::route::planning::RoutePrediction::RouteTreeElement const &value)
{
  out << value.routingPoint.first.point << "|" << static_cast<int16_t>(value.routingPoint.first.direction) << " ("
      << static_cast<double>(value.routingPoint.second.routeDistance) << "meters ,"
      << static_cast<double>(value.routingPoint.second.routeDuration) << " seconds) [";
  auto current = value.theParent;
  while (current != nullptr)
  {
    out << current->routingPoint.first.point << ", ";
    current = current->theParent;
  }
  out << "]";
  return out;
}
#endif

namespace ad {
namespace map {
namespace route {
namespace planning {

RoutePrediction::RoutePrediction(const RoutingParaPoint &start,
                                 physics::Distance const &predictionDistance,
                                 physics::Duration const &predictionDuration)
  : RouteExpander(start, start, Route::Type::SHORTEST)
  , mPredictionDistance(predictionDistance)
  , mPredictionDuration(predictionDuration)
{
}

RoutePrediction::RoutePrediction(const RoutingParaPoint &start, physics::Distance const &predictionDistance)
  : RouteExpander(start, start, Route::Type::SHORTEST)
  , mPredictionDistance(predictionDistance)
  , mPredictionDuration(physics::Duration::getMax())
{
}

RoutePrediction::RoutePrediction(const RoutingParaPoint &start, physics::Duration const &predictionDuration)
  : RouteExpander(start, start, Route::Type::SHORTEST)
  , mPredictionDistance(physics::Distance::getMax())
  , mPredictionDuration(predictionDuration)
{
}

bool RoutePrediction::calculate()
{
  mProcessedTransitions.clear();
  mElementsToProcess.clear();
  mRouteTreeRoot = std::make_shared<RouteTreeElement>(nullptr, getRoutingStart());

  mElementsToProcess.push_back(mRouteTreeRoot);

  while (!mElementsToProcess.empty())
  {
    expandNeighbors(mElementsToProcess.front()->routingPoint);
    mElementsToProcess.pop_front();
  }

  reconstructPaths();
  mRouteTreeRoot.reset();
  return isValid();
}

void RoutePrediction::addNeighbor(lane::Lane::ConstPtr originLane,
                                  RoutingPoint const &origin,
                                  lane::Lane::ConstPtr neighborLane,
                                  RoutingParaPoint const &neighbor,
                                  ExpandReason const &expandReason)
{
  if (expandReason == ExpandReason::Destination)
  {
    return;
  }

  auto insertResult = mProcessedTransitions[origin.first].insert(neighbor);
  if (!insertResult.second)
  {
    return;
  }

  auto element = std::make_shared<RouteTreeElement>(mElementsToProcess.front().get(), neighbor, origin.second);

  if (mElementsToProcess.front()->children.find(element) != mElementsToProcess.front()->children.end())
  {
    return;
  }

  physics::Distance neighborDistance{0.};
  physics::Duration neighborDuration{0.};
  if ((expandReason == ExpandReason::SameLaneNeighbor) || (expandReason == ExpandReason::LateralNeighbor))
  {
    point::ECEFPoint pt_origin
      = getParametricPoint(*originLane, origin.first.point.parametricOffset, physics::ParametricValue(0.5));
    point::ECEFPoint pt_neighbor
      = getParametricPoint(*neighborLane, neighbor.point.parametricOffset, physics::ParametricValue(0.5));
    neighborDistance = point::distance(pt_neighbor, pt_origin);
    physics::ParametricRange drivingRange;
    if (origin.first.point.parametricOffset < neighbor.point.parametricOffset)
    {
      drivingRange.minimum = origin.first.point.parametricOffset;
      drivingRange.maximum = neighbor.point.parametricOffset;
    }
    else
    {
      drivingRange.minimum = neighbor.point.parametricOffset;
      drivingRange.maximum = origin.first.point.parametricOffset;
    }

    if (expandReason == ExpandReason::SameLaneNeighbor)
    {
      neighborDuration = getDuration(*originLane, drivingRange);
    }
    else
    {
      neighborDuration = neighborDistance / getMaxSpeed(*originLane, drivingRange);
    }
  }
  if (neighborDistance < physics::Distance(0.1))
  {
    neighborDistance = physics::Distance(0.1);
  }
  element->routingPoint.second.routeDistance += neighborDistance;
  element->routingPoint.second.routeDuration += neighborDuration;
  mElementsToProcess.front()->children.insert(element);

#if DEBUG_OUTPUT
  std::cout << "Adding neighbor" << *element.get() << std::endl;
#endif
  if ((element->routingPoint.second.routeDistance < mPredictionDistance)
      && (element->routingPoint.second.routeDuration < mPredictionDuration))
  {
    mElementsToProcess.push_back(element);
  }
}

void RoutePrediction::RouteTreeElement::addPaths(std::vector<point::ParaPointList> &paths)
{
  if (children.size() > 0u)
  {
    for (auto child : children)
    {
      child->addPaths(paths);
    }
  }
  else
  {
    // a leaf in the route tree
    point::ParaPointList raw_route;
    RouteTreeElement const *current = this;
    while (current != nullptr)
    {
      raw_route.insert(raw_route.begin(), current->routingPoint.first.point);
      current = current->theParent;
    }
    paths.push_back(raw_route);
#if DEBUG_OUTPUT
    std::cout << "Leaf " << *this << std::endl;
    std::cout << "Added path [" << paths.size() << "]" << std::endl;
    for (auto &element : raw_route)
    {
      std::cout << " " << element << std::endl;
    }
    std::cout << "----------" << std::endl;
#endif
  }
}

void RoutePrediction::reconstructPaths()
{
  raw_routes.clear();
  valid_ = bool(mRouteTreeRoot);
  if (valid_)
  {
    mRouteTreeRoot->addPaths(raw_routes);
  }
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
