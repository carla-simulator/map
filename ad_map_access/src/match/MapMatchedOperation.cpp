// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/match/MapMatchedOperation.hpp"

#include <algorithm>
#include "ad/map/point/Operation.hpp"
#include "ad/map/route/LaneIntervalOperation.hpp"

namespace ad {
namespace map {
namespace match {

point::ParaPointList getParaPoints(MapMatchedPositionConfidenceList const &inMapMatchedPositions)
{
  point::ParaPointList result;
  result.reserve(inMapMatchedPositions.size());
  for (auto const &mapMatchedPosition : inMapMatchedPositions)
  {
    result.push_back(mapMatchedPosition.lane_point.para_point);
  }
  return result;
}

point::ENUHeading getObjectENUHeading(const match::MapMatchedObjectBoundingBox &map_matched_bounding_box)
{
  point::ECEFPoint rearLeftPosition;
  bool const rearLeftAvailable
    = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::RearLeft)].size() > 0u;
  if (rearLeftAvailable)
  {
    rearLeftPosition
      = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::RearLeft)]
          .front()
          .query_point;
  }
  point::ECEFPoint rearRightPosition;
  bool const rearRightAvailable
    = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::RearRight)].size() > 0u;
  if (rearRightAvailable)
  {
    rearRightPosition
      = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::RearRight)]
          .front()
          .query_point;
  }
  point::ECEFPoint frontLeftPosition;
  bool const frontLeftAvailable
    = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontLeft)].size() > 0u;
  if (frontLeftAvailable)
  {
    frontLeftPosition
      = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontLeft)]
          .front()
          .query_point;
  }
  point::ECEFPoint frontRightPosition;
  bool const frontRightAvailable
    = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontRight)].size() > 0u;
  if (frontRightAvailable)
  {
    frontRightPosition
      = map_matched_bounding_box.reference_point_positions[int32_t(match::ObjectReferencePoints::FrontRight)]
          .front()
          .query_point;
  }

  point::ECEFHeading ecefHeading;
  bool rotateENUHeading = false;
  if (rearLeftAvailable && rearRightAvailable && frontLeftAvailable && frontRightAvailable)
  {
    auto const rearCenterPosition = 0.5 * (rearLeftPosition + rearRightPosition);
    auto const frontCenterPosition = 0.5 * (frontLeftPosition + frontRightPosition);
    ecefHeading = point::createECEFHeading(rearCenterPosition, frontCenterPosition);
  }
  else if (rearLeftAvailable && frontLeftAvailable)
  {
    ecefHeading = point::createECEFHeading(rearLeftPosition, frontLeftPosition);
  }
  else if (rearRightAvailable && frontRightAvailable)
  {
    ecefHeading = point::createECEFHeading(rearRightPosition, frontRightPosition);
  }
  else if (frontLeftAvailable && frontRightAvailable)
  {
    ecefHeading = point::createECEFHeading(frontLeftPosition, frontRightPosition);
    rotateENUHeading = true;
  }
  else if (rearLeftAvailable && rearRightAvailable)
  {
    ecefHeading = point::createECEFHeading(rearLeftPosition, rearRightPosition);
    rotateENUHeading = true;
  }
  else
  {
    throw std::runtime_error("point::createENUHeading no two corner points available. Heading estimate is impossible");
  }
  auto enuHeading = point::createENUHeading(ecefHeading);
  if (rotateENUHeading)
  {
    enuHeading = point::createENUHeading(enuHeading.mENUHeading + M_PI_2);
  }
  return enuHeading;
}

physics::Distance signedDistanceToLane(lane::LaneId const checkLaneId,
                                       MapMatchedPositionConfidenceList const &mapMatchedPositions)
{
  physics::Distance distance = std::numeric_limits<physics::Distance>::max();

  auto findCheckPosition = std::find_if(std::begin(mapMatchedPositions),
                                        std::end(mapMatchedPositions),
                                        [checkLaneId](match::MapMatchedPosition const &position) {
                                          return position.lane_point.para_point.lane_id == checkLaneId;
                                        });

  if (findCheckPosition != std::end(mapMatchedPositions))
  {
    // found position
    if (findCheckPosition->type == match::MapMatchedPositionType::LANE_IN)
    {
      distance = physics::Distance(0.);
    }
    else if (findCheckPosition->type == match::MapMatchedPositionType::LANE_LEFT)
    {
      if (findCheckPosition->lane_point.lateral_t > physics::RatioValue(0.))
      {
        throw std::runtime_error("ad::map::match::signedDistanceToLane: inconsistent map matched positions."
                                 " Expected lateral_t to be < 0. for LANE_LEFT");
      }
      distance = findCheckPosition->lane_point.lateral_t * findCheckPosition->lane_point.lane_width;
    }
    else if (findCheckPosition->type == match::MapMatchedPositionType::LANE_RIGHT)
    {
      if (findCheckPosition->lane_point.lateral_t < physics::RatioValue(1.))
      {
        throw std::runtime_error("ad::map::match::signedDistanceToLane: inconsistent map matched positions."
                                 " Expected lateral_t to be > 1. for LANE_RIGHT");
      }
      distance = (findCheckPosition->lane_point.lateral_t - physics::RatioValue(1.))
        * findCheckPosition->lane_point.lane_width;
    }
    else
    {
      throw std::runtime_error("ad::map::match::signedDistanceToLane: inconsistent map matched positions."
                               " Expected type to be one of LANE_IN, LANE_LEFT, LEFT_RIGHT");
    }
  }

  return distance;
}

lane::ENUBorder getENUBorder(LaneOccupiedRegion const &lane_occupied_region)
{
  ad::map::route::LaneInterval laneInterval;
  laneInterval.lane_id = lane_occupied_region.lane_id;
  laneInterval.start = lane_occupied_region.longitudinal_range.minimum;
  laneInterval.end = lane_occupied_region.longitudinal_range.maximum;

  auto fullEnuBorder = route::getENUBorder(laneInterval);
  lane::ENUBorder resultBorder;
  resultBorder.left = lane::getLateralAlignmentEdge(
    fullEnuBorder, (physics::ParametricValue(1.0) - lane_occupied_region.lateral_range.maximum));
  resultBorder.right = lane::getLateralAlignmentEdge(
    fullEnuBorder, (physics::ParametricValue(1.0) - lane_occupied_region.lateral_range.minimum));

  return resultBorder;
}

} // namespace match
} // namespace map
} // namespace ad
