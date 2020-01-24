// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/point/Types.hpp"
#include "ad/map/route/FullRoute.hpp"
#include "ad/map/route/LaneChangeDirection.hpp"
#include "ad/map/route/LaneInterval.hpp"
#include "ad/map/route/LaneSegment.hpp"
#include "ad/map/route/RoadSegment.hpp"
#include "ad/map/route/RouteParaPoint.hpp"

/* @brief namespace admap */
namespace ad {
/* @brief namespace map */
namespace map {
/* @brief namespace route */
namespace route {

struct ConnectingInterval
{
  /**
  * \brief standard comparison operator
  *
  * \param[in] other Other ConnectingInterval
  *
  * \returns \c true if both ConnectingInterval are equal
  */
  bool operator==(const ConnectingInterval &other) const
  {
    return (laneInterval == other.laneInterval) && (laneOffset == other.laneOffset);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other ConnectingInterval.
   *
   * \returns \c true if both ConnectingInterval are different
   */
  bool operator!=(const ConnectingInterval &other) const
  {
    return !operator==(other);
  }

  route::LaneInterval laneInterval;
  int32_t laneOffset{0};
};

typedef std::vector<route::ConnectingInterval> ConnectingSegment;

struct ConnectingRoute
{
  /* todo: support of Y-routes where both vehicles have some distinct prefix and then connect entering from same
  direction
  std::vector<route::ConnectingSegment> prefixSegmentsA;
  std::vector<route::ConnectingSegment> prefixSegmentsB;
  */
  std::vector<route::ConnectingSegment> connectingSegments;
  physics::Distance connectingRouteLength{0.};
  int32_t destinationLaneOffset{0};
  int32_t minLaneOffset{0};
  int32_t maxLaneOffset{0};
};

} // namespace route
} // namespace map
} // namespace ad
