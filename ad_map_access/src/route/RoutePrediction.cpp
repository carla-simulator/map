// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RoutePrediction.hpp"

#include <algorithm>
#include <utility>

// need to make RouteTreeElement public if debug output is required!
#define DEBUG_OUTPUT 0

#if DEBUG_OUTPUT
#include <iostream>

namespace std {

inline ostream &operator<<(ostream &out, ad::map::route::planning::RoutePrediction::RouteTreeElement const &value)
{
  out << value.routingPoint.first.point << "|" << static_cast<int16_t>(value.routingPoint.first.direction) << " ("
      << value.routingPoint.second.routeDistance.mDistance << "meters ,"
      << value.routingPoint.second.routeDuration.mDuration << " seconds) [";
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
  mElementsCreated.clear();
  mRouteTreeRoot = nullptr;
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
  mElementsCreated.emplace_back(nullptr, start);
  mRouteTreeRoot = &mElementsCreated.back();
  mElementsToProcess.push_back(mRouteTreeRoot);

  if (getRoutingStart().direction == RoutingDirection::DONT_CARE)
  {
    // Add the negative concrete start direction as an independent root rather than a child transition,
    // so an unexpandable reverse direction on a one-way lane does not emit a bogus 0-length leaf route.
    auto startOtherDirection = start;
    startOtherDirection.first.direction = RoutingDirection::NEGATIVE;
    mElementsCreated.emplace_back(nullptr, startOtherDirection);
    mElementsToProcess.push_back(&mElementsCreated.back());
  }

  while (!mElementsToProcess.empty())
  {
    expandNeighbors(mElementsToProcess.front()->routingPoint);
    mElementsToProcess.pop_front();
  }

  reconstructPaths();
  mProcessedTransitions.clear();
  mRouteTreeRoot = nullptr;
  mElementsCreated.clear();

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
  auto &transitionSet = mProcessedTransitions[origin.first];

  RouteTreeElement probe(currentTreeElement, neighbor);
  auto const existingIt = transitionSet.find(&probe);
  if (existingIt != transitionSet.end())
  {
    // a similar child (a twin) was already expanded, take that one as our child
    currentTreeElement->children.insert(*existingIt);
    // nothing further to be done since already processed
    return;
  }

  mElementsCreated.emplace_back(currentTreeElement, neighbor);
  RouteTreeElement *newChildElement = &mElementsCreated.back();
  transitionSet.insert(newChildElement);
  auto insertToProcessResult = currentTreeElement->children.insert(newChildElement);
  if (!insertToProcessResult.second)
  {
    // this child is already in the current element, nothing to be done
    return;
  }

#if DEBUG_OUTPUT
  std::cout << "Adding neighbor" << *(newChildElement) << std::endl;
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
          RouteTreeElement const *parent = element;
          while (parent != nullptr)
          {
            rawRoute.paraPointList.push_back(parent->routingPoint.first.point);
            parent = parent->theParent;
          }
          std::reverse(rawRoute.paraPointList.begin(), rawRoute.paraPointList.end());
          mRawRoutes.push_back(std::move(rawRoute));
#if DEBUG_OUTPUT
          std::cout << "Added path [" << mRawRoutes.size() << "]" << std::endl;
          for (auto &point : mRawRoutes.back().paraPointList)
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
