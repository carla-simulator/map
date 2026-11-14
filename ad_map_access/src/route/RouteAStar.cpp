// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RouteAStar.hpp"

#include <algorithm>
#include <utility>
#include "ad/map/access/Logging.hpp"

#define DEBUG_OUTPUT 0

#if DEBUG_OUTPUT
#include <iostream>

namespace std {

inline ostream &operator<<(ostream &out, ::ad::map::route::planning::RouteAstar::RoutingPoint const &value)
{
  out << value.first.point << "|" << (int)value.first.direction << " ("
      << static_cast<double>(value.second.routeDistance) << ","
      << static_cast<double>(value.second.costData.estimatedDistanceToTarget) << ")";
  return out;
}

} // namespace std
#endif

namespace ad {
namespace map {
namespace route {
namespace planning {

RouteAstar::RouteAstar(const RoutingParaPoint &start,
                       const RoutingParaPoint &dest,
                       physics::Distance const &maxDistance,
                       physics::Duration const &maxDuration,
                       Type typ)
  : RouteExpander(start, dest, maxDistance, maxDuration, typ)
{
  initLanePointer();
}

RouteAstar::RouteAstar(const RoutingParaPoint &start,
                       const RoutingParaPoint &dest,
                       physics::Distance const &maxDistance,
                       Type typ)
  : RouteExpander(start, dest, maxDistance, physics::Duration::getMax(), typ)
{
  initLanePointer();
}

RouteAstar::RouteAstar(const RoutingParaPoint &start,
                       const RoutingParaPoint &dest,
                       physics::Duration const &maxDuration,
                       Type typ)
  : RouteExpander(start, dest, physics::Distance::getMax(), maxDuration, typ)
{
  initLanePointer();
}

RouteAstar::RouteAstar(const RoutingParaPoint &start, const RoutingParaPoint &dest, Type typ)
  : RouteExpander(start, dest, physics::Distance::getMax(), physics::Duration::getMax(), typ)
{
  initLanePointer();
}

void RouteAstar::initLanePointer()
{
  mDestLane = lane::getLanePtr(mDest.point.lane_id);
  if (!mDestLane)
  {
    throw std::runtime_error("Dest lane not found!");
  }
  mDestPoint = getParametricPoint(*mDestLane, getDest().parametric_offset, physics::ParametricValue(0.5));
  mStartLane = lane::getLanePtr(mStart.point.lane_id);
  if (!mStartLane)
  {
    throw std::runtime_error("Start lane not found!");
  }
}

// https://en.wikipedia.org/wiki/A*_search_algorithm
bool RouteAstar::calculate()
{
  mProcessedPoints.clear();
  mProcessingMap.clear();
  mOpenQueue = OpenPriorityQueue();
  mCameFrom.clear();
  mRawRoutes.clear();

  // A* working structures.
  // Initial values.
  RoutingCost cost;
  cost.costData.estimatedDistanceToTarget = costEstimate(mStartLane, mStart.point);
  if (mStart.direction == RoutingDirection::DONT_CARE)
  {
    // Don't care routing direction means the vehicle can drive forward or backward.
    // Within the routing we have to replace this by concrete directions,
    // otherwise the vehicle would be able to switch between forward/backward while driving on the route
    // which especially is not meant by the don't care flag.
    auto startPositive = mStart;
    startPositive.direction = RoutingDirection::POSITIVE;
    mProcessingMap.insert({startPositive, cost});
    mOpenQueue.push({cost.costData.estimatedDistanceToTarget, startPositive});
    auto startNegative = mStart;
    startNegative.direction = RoutingDirection::NEGATIVE;
    mProcessingMap.insert({startNegative, cost});
    mOpenQueue.push({cost.costData.estimatedDistanceToTarget, startNegative});
  }
  else
  {
    mProcessingMap.insert({mStart, cost});
    mOpenQueue.push({cost.costData.estimatedDistanceToTarget, mStart});
  }
  // Run
  bool pathFound = false;
#if DEBUG_OUTPUT
  std::cout << "######### (typ:" << (int)mType << " #########"
            << " start: " << mStart.point << " dest: " << mDest.point << std::endl;
#endif
  while (!mOpenQueue.empty() && !mProcessingMap.empty())
  {
    auto const topEntry = mOpenQueue.top();
    mOpenQueue.pop();
    auto minimumCostIterator = mProcessingMap.find(topEntry.point);
    if ((minimumCostIterator == mProcessingMap.end())
        || (minimumCostIterator->second.costData.estimatedDistanceToTarget != topEntry.estimatedDistanceToTarget))
    {
      continue;
    }

    if (((mDest.direction == RoutingDirection::DONT_CARE) || (mDest.direction == minimumCostIterator->first.direction))
        && (minimumCostIterator->first.point == mDest.point))
    {
      reconstructPath(*minimumCostIterator);
      pathFound = true;
#if DEBUG_OUTPUT
      std::cout << "Target reached " << *minimumCostIterator << std::endl;
      for (auto const &point : getRawRoute().paraPointList)
      {
        std::cout << " " << point << std::endl;
      }
      std::cout << "#########" << std::endl;
#endif
      mProcessingMap.clear();
      mOpenQueue = OpenPriorityQueue();
    }
    else
    {
      RoutingPoint const minimumValue = *minimumCostIterator;
      mProcessingMap.erase(minimumCostIterator);
      mProcessedPoints.insert(minimumValue.first);
#if DEBUG_OUTPUT
      std::cout << "Expanding: " << minimumValue << std::endl;
#endif
      expandNeighbors(minimumValue);
#if DEBUG_OUTPUT
      std::cout << "Results in " << std::endl;
      for (auto &element : mProcessingMap)
      {
        std::cout << " " << element << std::endl;
      }
      std::cout << "----------" << std::endl;
#endif
    }
  }

  mProcessedPoints.clear();
  mProcessingMap.clear();
  mOpenQueue = OpenPriorityQueue();
  mCameFrom.clear();

  return pathFound;
}

physics::Distance RouteAstar::costEstimate(lane::Lane::ConstPtr neighborLane, point::ParaPoint const &neighbor)
{
  point::ECEFPoint const pt_a
    = getParametricPoint(*neighborLane, neighbor.parametric_offset, physics::ParametricValue(0.5));
  return distance(pt_a, mDestPoint);
}

void RouteAstar::addNeighbor(lane::Lane::ConstPtr originLane,
                             RoutingPoint const &origin,
                             lane::Lane::ConstPtr neighborLane,
                             RoutingPoint const &neighbor,
                             ExpandReason const &expandReason)
{
  (void)originLane;
  (void)expandReason;

  if (mProcessedPoints.find(neighbor.first) == mProcessedPoints.end())
  {
    auto insertResult = mProcessingMap.insert(neighbor);
    if ( // insertion succeeded
      insertResult.second ||
      // actual distance of new neighbor is smaller than the found duplicate
      (neighbor.second.routeDistance < insertResult.first->second.routeDistance))
    {
      auto const estimatedDestCost = costEstimate(neighborLane, neighbor.first.point);
      auto const totalEstimatedCost = neighbor.second.routeDistance + estimatedDestCost;
      insertResult.first->second.routeDistance = neighbor.second.routeDistance;
      insertResult.first->second.routeDuration = neighbor.second.routeDuration;
      insertResult.first->second.costData.estimatedDistanceToTarget = totalEstimatedCost;
      mOpenQueue.push({totalEstimatedCost, neighbor.first});
      mCameFrom[neighbor.first] = origin.first;
#if DEBUG_OUTPUT
      std::cout << "Inserted: " << *insertResult.first << std::endl;
#endif
    }
  }
}

void RouteAstar::reconstructPath(RoutingPoint const &dest)
{
  RawRoute rawRoute;
  rawRoute.routeDistance = dest.second.routeDistance;
  rawRoute.routeDuration = dest.second.routeDuration;
  for (auto current = dest.first;;)
  {
    rawRoute.paraPointList.push_back(current.point);
    auto it = mCameFrom.find(current);
    if (it == mCameFrom.end())
    {
      break;
    }
    else
    {
      current = it->second;
    }
  }
  std::reverse(rawRoute.paraPointList.begin(), rawRoute.paraPointList.end());
  mDest = dest.first;
  mValid = true;
  mRawRoutes.push_back(std::move(rawRoute));
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
