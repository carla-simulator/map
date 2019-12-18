// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/RouteAStar.hpp"

#include <algorithm>

#define DEBUG_OUTPUT 0

#if DEBUG_OUTPUT
#include <iostream>
inline std::ostream &operator<<(std::ostream &out, ad::map::point::ParaPoint const &value)
{
  out << "(" << static_cast<uint64_t>(value.laneId) << "|" << static_cast<double>(value.parametricOffset) << ")";
  return out;
}

inline std::ostream &operator<<(std::ostream &out, ::ad::map::route::planning::RouteAstar::RoutingPoint const &value)
{
  out << value.first.point << "|" << (int)value.first.direction << " (" << static_cast<double>(value.second.g_score)
      << "," << static_cast<double>(value.second.f_score) << ")";
  return out;
}
#endif

namespace ad {
namespace map {
namespace route {
namespace planning {

static const physics::Distance COST_LONGITUDINAL(1.); ///< Cost of longitudinal lane change.
static const physics::Distance COST_LATERAL(5.);      ///< Cost of lateral lane change.

RouteAstar::RouteAstar(const RoutingParaPoint &start, const RoutingParaPoint &dest, Type typ)
  : RouteExpander(start, dest, typ)
{
  mDestLane = lane::getLanePtr(dest.point.laneId);
  if (!mDestLane)
  {
    throw std::runtime_error("Dest lane not found!");
  }
  mStartLane = lane::getLanePtr(start.point.laneId);
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
  mCameFrom.clear();

  // A* working structures.
  // Initial values.
  RouteAstarScore cost;
  cost.f_score = costEstimate(mStartLane, start_.point);
  mProcessingMap.insert({start_, cost});
  // Run
  bool path_found = false;
#if DEBUG_OUTPUT
  std::cout << "######### (typ:" << (int)type_ << " #########"
            << " start: " << start_.point << " dest: " << dest_.point << std::endl;
#endif
  while (!mProcessingMap.empty())
  {
    // sort the routing points by the smallest total cost
    struct FScoreCompare
    {
      bool operator()(RoutingPoint const &left, RoutingPoint const &right)
      {
        return left.second.f_score < right.second.f_score;
      }
    };
    auto minimum_cost_iterator = std::min_element(mProcessingMap.begin(), mProcessingMap.end(), FScoreCompare());
    if (((dest_.direction == RoutingDirection::DONT_CARE)
         || (dest_.direction == minimum_cost_iterator->first.direction))
        && (minimum_cost_iterator->first.point == dest_.point))
    {
      reconstructPath(minimum_cost_iterator->first);
      path_found = true;
#if DEBUG_OUTPUT
      std::cout << "Target reached " << *minimum_cost_iterator << std::endl;
      for (auto const &point : getRawRoute())
      {
        std::cout << " " << point << std::endl;
      }
      std::cout << "#########" << std::endl;
#endif
      mProcessingMap.clear();
    }
    else
    {
      RoutingPoint const minimum_value = *minimum_cost_iterator;
      mProcessingMap.erase(minimum_cost_iterator);
      mProcessedPoints.insert(minimum_value.first);
#if DEBUG_OUTPUT
      std::cout << "Expanding: " << minimum_value << std::endl;
#endif
      expandNeighbors(minimum_value);
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
  mCameFrom.clear();

  return path_found;
}

physics::Distance RouteAstar::costEstimate(lane::Lane::ConstPtr neighborLane, point::ParaPoint const &neighbor)
{
  point::ECEFPoint pt_a = getParametricPoint(*neighborLane, neighbor.parametricOffset, physics::ParametricValue(0.5));
  point::ECEFPoint pt_b = getParametricPoint(*mDestLane, getDest().parametricOffset, physics::ParametricValue(0.5));
  physics::Distance d = distance(pt_a, pt_b);
  return d;
}

void RouteAstar::addNeighbor(lane::Lane::ConstPtr originLane,
                             RoutingPoint const &origin,
                             lane::Lane::ConstPtr neighborLane,
                             RoutingParaPoint const &neighbor,
                             ExpandReason const &expandReason)
{
  if (mProcessedPoints.find(neighbor) == mProcessedPoints.end())
  {
    physics::Distance expand_g_score;
    switch (expandReason)
    {
      case ExpandReason::Destination:
      case ExpandReason::SameLaneNeighbor:
      {
        if (originLane != neighborLane)
        {
          throw std::runtime_error("Expected same lanes!");
        }
        auto const deltaTParam = std::fabs(origin.first.point.parametricOffset - neighbor.point.parametricOffset);
        physics::Distance const laneLength = originLane->length;
        expand_g_score = deltaTParam * laneLength;
        break;
      }
      case ExpandReason::LongitudinalNeighbor:
      {
        expand_g_score = COST_LONGITUDINAL;
        break;
      }
      case ExpandReason::LateralNeighbor:
      {
        expand_g_score = COST_LATERAL;
        break;
      }
      default:
        throw std::runtime_error("RouteAstar::AddNeighbor>> Unsupported expand reason!");
        break;
    }

    RouteAstarScore cost;
    cost.g_score = origin.second.g_score + expand_g_score;
    auto insert_result = mProcessingMap.insert({neighbor, cost});
    if ( // insertion succeeded
      insert_result.second ||
      // g_score of new neighbor is smaller than the found duplicate
      (cost.g_score < insert_result.first->second.g_score))
    {
      cost.f_score = cost.g_score + costEstimate(neighborLane, neighbor.point);
      insert_result.first->second = cost;
      mCameFrom[neighbor] = origin.first;
#if DEBUG_OUTPUT
      std::cout << "Inserted: " << *insert_result.first << std::endl;
#endif
    }
  }
}

void RouteAstar::reconstructPath(RoutingParaPoint const &dest)
{
  raw_routes.clear();

  point::ParaPointList raw_route;
  for (auto current = dest;;)
  {
    raw_route.insert(raw_route.begin(), current.point);
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
  dest_ = dest;
  valid_ = true;
  raw_routes.push_back(raw_route);
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
