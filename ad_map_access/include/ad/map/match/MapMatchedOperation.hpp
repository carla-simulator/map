// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/match/Types.hpp"
#include "ad/map/point/Types.hpp"

/** @brief namespace admap */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace match */
namespace match {

/** @brief get the list of ParaPoints out of the map matched positions */
point::ParaPointList getParaPoints(MapMatchedPositionConfidenceList const &inMapMatchedPositions);

inline bool isLaneType(MapMatchedPositionType const &mapMatchedPositionType)
{
  return mapMatchedPositionType == MapMatchedPositionType::LANE_IN
    || mapMatchedPositionType == MapMatchedPositionType::LANE_LEFT
    || mapMatchedPositionType == MapMatchedPositionType::LANE_RIGHT;
}

/**
 * @brief Calculates the objects ENU angle based on the map matched position
 */
point::ENUHeading getObjectENUHeading(const match::MapMatchedObjectBoundingBox &map_matched_bounding_box);

/**
 * @brief get the signed distance to a lane within the map matched positions
 *
 * This check searches the mapMatchedPositions for the given \a checkLaneId and returns a signed distance value to the
 * lane.
 *
 * @param[in] checkLaneId the lane id to find
 * @param[in] mapMatchedPositions the map matched positions to check
 *
 * @returns:
 * If not part of the mapMatchedPositions:  distance = std::numeric_limits<physics::Distance>::max()
 * If it's found and map matched type is:
 * - MapMatchedPositionType::LANE_IN: distance = 0.
 * - MapMatchedPositionType::LANE_LEFT: distance < 0
 * - MapMatchedPositionType::LANE_RIGHT: distance > 0
 *
 * @throws std::runtime_error if mapMatchedPositions are inconsistent
 */
physics::Distance signedDistanceToLane(lane::LaneId const checkLaneId,
                                       MapMatchedPositionConfidenceList const &mapMatchedPositions);

/** @brief get the para point of the occupied Region in the middle of the longitudinal extend of it */
inline point::ParaPoint getCenterParaPoint(match::LaneOccupiedRegion const &occupiedRegion)
{
  point::ParaPoint para_point;
  para_point.lane_id = occupiedRegion.lane_id;
  para_point.parametric_offset
    = 0.5 * (occupiedRegion.longitudinal_range.maximum + occupiedRegion.longitudinal_range.minimum);
  return para_point;
}

/** @brief Check if the matched point is actually lateral within the lane  */
inline bool isLateralInLaneMatch(const MapMatchedPosition &mapMatchedPosition)
{
  if ((mapMatchedPosition.lane_point.lateral_t > physics::RatioValue(1.0))
      || (mapMatchedPosition.lane_point.lateral_t < physics::RatioValue(0.0)))
  {
    return false;
  }
  return true;
}

/** @brief Check if the matched point is actually longitudinally within the lane  */
inline bool isLongitudinalInLaneMatch(const MapMatchedPosition &mapMatchedPosition)
{
  // filter out longitudinal out-of-lane matches, indicated by border points being > 10cm away
  if ((mapMatchedPosition.lane_point.para_point.parametric_offset == physics::ParametricValue(0.))
      || (mapMatchedPosition.lane_point.para_point.parametric_offset == physics::ParametricValue(1.)))
  {
    if (mapMatchedPosition.matched_point_distance > physics::Distance(0.1))
    {
      return false;
    }
  }
  return true;
}

/** @brief Check if the matched point is actually laternally and longitudinally within the lane  */
inline bool isActualWithinLaneMatch(const MapMatchedPosition &mapMatchedPosition)
{
  return isLateralInLaneMatch(mapMatchedPosition) && isLongitudinalInLaneMatch(mapMatchedPosition);
}

/**
 * @brief get the enu borders of this lane region
 *
 * Note: The border (left/right edge) will start with the parametric offset
 * given by the longitudinal region and the lateral algignment will match the lateral region.
 * Be aware: Ordering of start/end left/right is not specified.
 */
lane::ENUBorder getENUBorder(LaneOccupiedRegion const &lane_occupied_region);

} // namespace match
} // namespace map
} // namespace ad
