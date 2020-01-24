// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/route/Route.hpp"
#include "ad/map/lane/LaneOperation.hpp"

namespace ad {
namespace map {
namespace route {
namespace planning {

Route::Route(const RoutingParaPoint &start, const RoutingParaPoint &dest, Type const &routingType)
  : start_(start)
  , dest_(dest)
  , type_(routingType)
  , valid_(false)
{
  if (type_ == Type::INVALID)
  {
    throw std::runtime_error("type INVALID");
  }
}

bool Route::laneDirectionIsIgnored() const
{
  switch (type_)
  {
    case Type::SHORTEST_IGNORE_DIRECTION:
      return true;
    case Type::SHORTEST:
    default:
      return false;
  }
}

const point::ParaPointList &Route::getRawRoute(size_t const routeIndex) const
{
  static point::ParaPointList const emptyRoute;
  if (raw_routes.size() > routeIndex)
  {
    return raw_routes[routeIndex];
  }
  return emptyRoute;
}

Route::BasicRoute Route::getBasicRoute(size_t const routeIndex) const
{
  auto rawRoute = getRawRoute(routeIndex);
  BasicRoute fr;
  for (size_t i = 0; i < rawRoute.size(); i++)
  {
    const point::ParaPoint &para_point = rawRoute[i];
    point::ParaPointList pps;
    pps.push_back(para_point);
    for (size_t k = 0; k < 2; k++)
    {
      for (lane::Lane::ConstPtr lane = lane::getLanePtr(para_point.laneId); lane;)
      {
        lane::LaneDirection const direction = lane->direction;
        lane::ContactLaneList const cl
          = getContactLanes(*lane, k == 0 ? lane::ContactLocation::LEFT : lane::ContactLocation::RIGHT);
        lane = nullptr;
        for (auto contact : cl)
        {
          lane::LaneId other_lane_id = contact.toLane;
          bool is_prev = false;
          if (i > 0)
          {
            is_prev = other_lane_id == rawRoute[i - 1].laneId;
          }
          bool is_next = false;
          if (i + 1 < rawRoute.size())
          {
            is_next = other_lane_id == rawRoute[i + 1].laneId;
          }
          if (!is_next && !is_prev)
          {
            lane::Lane::ConstPtr other_lane = lane::getLanePtr(other_lane_id);
            if ((direction == other_lane->direction) || laneDirectionIsIgnored())
            {
              point::ParaPoint ppt;
              ppt.laneId = other_lane_id;
              ppt.parametricOffset = para_point.parametricOffset;
              pps.push_back(ppt);
              lane = other_lane;
            }
          }
        }
      }
    }
    fr.push_back(pps);
  }
  return fr;
}

std::vector<Route::BasicRoute> Route::getBasicRoutes() const
{
  std::vector<BasicRoute> routeVector;
  routeVector.resize(raw_routes.size());
  for (size_t i = 0u; i < raw_routes.size(); ++i)
  {
    routeVector[i] = getBasicRoute(i);
  }
  return routeVector;
}

} // namespace planning
} // namespace route
} // namespace map
} // namespace ad
