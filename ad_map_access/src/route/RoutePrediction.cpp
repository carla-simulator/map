// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RoutePrediction.hpp"

// need to make RouteTreeElement public if debug output is required!
#define DEBUG_OUTPUT 0

#if DEBUG_OUTPUT
#include <iostream>

namespace std {

inline ostream &operator<<(ostream &out, ad::map::route::planning::RoutePrediction::RouteTreeElement const &value)
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

} // namespace std
#endif

namespace ad {
namespace map {
namespace route {
namespace planning {

RoutePrediction::RoutePrediction(const RoutingParaPoint &start,
                                 physics::Distance const &predictionDistance,
                                 physics::Duration const &predictionDuration,
                                 Type typ)
  : RouteExpander(start, start, predictionDistance, predictionDuration, typ)
{
}

RoutePrediction::RoutePrediction(const RoutingParaPoint &start, physics::Distance const &predictionDistance, Type typ)
  : RouteExpander(start, start, predictionDistance, physics::Duration::getMax(), typ)
{
}

RoutePrediction::RoutePrediction(const RoutingParaPoint &start, physics::Duration const &predictionDuration, Type typ)
  : RouteExpander(start, start, physics::Distance::getMax(), predictionDuration, typ)
{
}

bool RoutePrediction::calculate()
{
  mProcessedTransitions.clear();
  mElementsToProcess.clear();
  mRawRoutes.clear();

  RoutingPoint start;
  start.first = getRoutingStart();
  start.second = RoutingCost();

  if (getRoutingStart().direction == RoutingDirection::DONT_CARE)
  {
    // Don't care routing direction means the vehicle can drive forward or backward.
    // Within the routing we have to replace this by concrete directions,
    // otherwise the vehicle would be able to switch between forward/backward while driving on the route
    // which especially is not meant by the don't care flag.
    start.first.direction = RoutingDirection::POSITIVE;
  }
  mRouteTreeRoot = std::make_shared<RouteTreeElement>(nullptr, start);
  mElementsToProcess.push_back(mRouteTreeRoot);

  if (getRoutingStart().direction == RoutingDirection::DONT_CARE)
  {
    // add the negative concrete start of prediction option by changing direction without cost
    auto startOtherDirection = start;
    startOtherDirection.first.direction = RoutingDirection::NEGATIVE;
    insertNeighbor(start, startOtherDirection);
  }

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
                                  RoutingPoint const &neighbor,
                                  ExpandReason const &expandReason)
{
  (void)originLane;
  (void)neighborLane;

  if (expandReason == ExpandReason::Destination)
  {
    return;
  }

  insertNeighbor(origin, neighbor);
}

void RoutePrediction::insertNeighbor(RoutingPoint const &origin, RoutingPoint const &neighbor)
{
  auto currentTreeElement = mElementsToProcess.front();

  auto newChildElement = std::make_shared<RouteTreeElement>(currentTreeElement.get(), neighbor);
  auto insertProcessedResult = mProcessedTransitions[origin.first].insert(newChildElement);
  if (insertProcessedResult.second)
  {
    auto insertToProcessResult = currentTreeElement->children.insert(newChildElement);
    if (!insertToProcessResult.second)
    {
      // this child is already in the current element, nothing to be done
      return;
    }
  }
  else
  {
    // a similar child (a twin) was already already expanded, take that one as our child
    currentTreeElement->children.insert(*insertProcessedResult.first);
    // nothing further to be done since already processed
    return;
  }

#if DEBUG_OUTPUT
  std::cout << "Adding neighbor" << *(newChildElement.get()) << std::endl;
#endif
  mElementsToProcess.push_back(newChildElement);
}

void RoutePrediction::reconstructPaths()
{
  mValid = bool(mRouteTreeRoot);
  if (mValid)
  {
    for (auto const &processedTransition : mProcessedTransitions)
    {
      for (auto const &element : processedTransition.second)
      {
        if (element->children.empty())
        {
          // a leaf in the route tree
          RawRoute rawRoute;
          rawRoute.routeDistance = element->routingPoint.second.routeDistance;
          rawRoute.routeDuration = element->routingPoint.second.routeDuration;
#if DEBUG_OUTPUT
          std::cout << "Leaf " << *element << std::endl;
#endif
          RouteTreeElement const *parent = element.get();
          while (parent != nullptr)
          {
            rawRoute.paraPointList.insert(rawRoute.paraPointList.begin(), parent->routingPoint.first.point);
            parent = parent->theParent;
          }
          mRawRoutes.push_back(rawRoute);
#if DEBUG_OUTPUT
          std::cout << "Added path [" << mRawRoutes.size() << "]" << std::endl;
          for (auto &point : rawRoute.paraPointList)
          {
            std::cout << " " << point << std::endl;
          }
          std::cout << "----------" << std::endl;
#endif
        }
      }
    }
  }
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
