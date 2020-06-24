/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/*
 * Generated file
 */

#include <gtest/gtest.h>

#include <limits>

#include "ad/map/match/MapMatchedObjectBoundingBoxValidInputRange.hpp"

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::map::match::LaneOccupiedRegionList valueLaneOccupiedRegions;
  ::ad::map::match::LaneOccupiedRegion valueLaneOccupiedRegionsElement;
  ::ad::map::lane::LaneId valueLaneOccupiedRegionsElementLaneId(1);
  valueLaneOccupiedRegionsElement.laneId = valueLaneOccupiedRegionsElementLaneId;
  ::ad::physics::ParametricRange valueLaneOccupiedRegionsElementLongitudinalRange;
  ::ad::physics::ParametricValue valueLaneOccupiedRegionsElementLongitudinalRangeMinimum(0.);
  valueLaneOccupiedRegionsElementLongitudinalRange.minimum = valueLaneOccupiedRegionsElementLongitudinalRangeMinimum;
  ::ad::physics::ParametricValue valueLaneOccupiedRegionsElementLongitudinalRangeMaximum(0.);
  valueLaneOccupiedRegionsElementLongitudinalRange.maximum = valueLaneOccupiedRegionsElementLongitudinalRangeMaximum;
  valueLaneOccupiedRegionsElementLongitudinalRange.maximum = valueLaneOccupiedRegionsElementLongitudinalRange.minimum;
  valueLaneOccupiedRegionsElementLongitudinalRange.minimum = valueLaneOccupiedRegionsElementLongitudinalRange.maximum;
  valueLaneOccupiedRegionsElement.longitudinalRange = valueLaneOccupiedRegionsElementLongitudinalRange;
  ::ad::physics::ParametricRange valueLaneOccupiedRegionsElementLateralRange;
  ::ad::physics::ParametricValue valueLaneOccupiedRegionsElementLateralRangeMinimum(0.);
  valueLaneOccupiedRegionsElementLateralRange.minimum = valueLaneOccupiedRegionsElementLateralRangeMinimum;
  ::ad::physics::ParametricValue valueLaneOccupiedRegionsElementLateralRangeMaximum(0.);
  valueLaneOccupiedRegionsElementLateralRange.maximum = valueLaneOccupiedRegionsElementLateralRangeMaximum;
  valueLaneOccupiedRegionsElementLateralRange.maximum = valueLaneOccupiedRegionsElementLateralRange.minimum;
  valueLaneOccupiedRegionsElementLateralRange.minimum = valueLaneOccupiedRegionsElementLateralRange.maximum;
  valueLaneOccupiedRegionsElement.lateralRange = valueLaneOccupiedRegionsElementLateralRange;
  valueLaneOccupiedRegions.resize(1, valueLaneOccupiedRegionsElement);
  value.laneOccupiedRegions = valueLaneOccupiedRegions;
  std::vector<::ad::map::match::MapMatchedPositionConfidenceList> valueReferencePointPositions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReferencePointPositionsElement;
  ::ad::map::match::MapMatchedPosition valueReferencePointPositionsElementElement;
  ::ad::map::match::LanePoint valueReferencePointPositionsElementElementLanePoint;
  ::ad::map::point::ParaPoint valueReferencePointPositionsElementElementLanePointParaPoint;
  ::ad::map::lane::LaneId valueReferencePointPositionsElementElementLanePointParaPointLaneId(1);
  valueReferencePointPositionsElementElementLanePointParaPoint.laneId
    = valueReferencePointPositionsElementElementLanePointParaPointLaneId;
  ::ad::physics::ParametricValue valueReferencePointPositionsElementElementLanePointParaPointParametricOffset(0.);
  valueReferencePointPositionsElementElementLanePointParaPoint.parametricOffset
    = valueReferencePointPositionsElementElementLanePointParaPointParametricOffset;
  valueReferencePointPositionsElementElementLanePoint.paraPoint
    = valueReferencePointPositionsElementElementLanePointParaPoint;
  ::ad::physics::RatioValue valueReferencePointPositionsElementElementLanePointLateralT(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReferencePointPositionsElementElementLanePoint.lateralT
    = valueReferencePointPositionsElementElementLanePointLateralT;
  ::ad::physics::Distance valueReferencePointPositionsElementElementLanePointLaneLength(-1e9);
  valueReferencePointPositionsElementElementLanePoint.laneLength
    = valueReferencePointPositionsElementElementLanePointLaneLength;
  ::ad::physics::Distance valueReferencePointPositionsElementElementLanePointLaneWidth(-1e9);
  valueReferencePointPositionsElementElementLanePoint.laneWidth
    = valueReferencePointPositionsElementElementLanePointLaneWidth;
  valueReferencePointPositionsElementElement.lanePoint = valueReferencePointPositionsElementElementLanePoint;
  ::ad::map::match::MapMatchedPositionType valueReferencePointPositionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReferencePointPositionsElementElement.type = valueReferencePointPositionsElementElementType;
  ::ad::map::point::ECEFPoint valueReferencePointPositionsElementElementMatchedPoint;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementMatchedPointX(-6400000);
  valueReferencePointPositionsElementElementMatchedPoint.x = valueReferencePointPositionsElementElementMatchedPointX;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementMatchedPointY(-6400000);
  valueReferencePointPositionsElementElementMatchedPoint.y = valueReferencePointPositionsElementElementMatchedPointY;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementMatchedPointZ(-6400000);
  valueReferencePointPositionsElementElementMatchedPoint.z = valueReferencePointPositionsElementElementMatchedPointZ;
  valueReferencePointPositionsElementElement.matchedPoint = valueReferencePointPositionsElementElementMatchedPoint;
  ::ad::physics::Probability valueReferencePointPositionsElementElementProbability(0.);
  valueReferencePointPositionsElementElement.probability = valueReferencePointPositionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReferencePointPositionsElementElementQueryPoint;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementQueryPointX(-6400000);
  valueReferencePointPositionsElementElementQueryPoint.x = valueReferencePointPositionsElementElementQueryPointX;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementQueryPointY(-6400000);
  valueReferencePointPositionsElementElementQueryPoint.y = valueReferencePointPositionsElementElementQueryPointY;
  ::ad::map::point::ECEFCoordinate valueReferencePointPositionsElementElementQueryPointZ(-6400000);
  valueReferencePointPositionsElementElementQueryPoint.z = valueReferencePointPositionsElementElementQueryPointZ;
  valueReferencePointPositionsElementElement.queryPoint = valueReferencePointPositionsElementElementQueryPoint;
  ::ad::physics::Distance valueReferencePointPositionsElementElementMatchedPointDistance(-1e9);
  valueReferencePointPositionsElementElement.matchedPointDistance
    = valueReferencePointPositionsElementElementMatchedPointDistance;
  valueReferencePointPositionsElement.resize(1, valueReferencePointPositionsElementElement);
  valueReferencePointPositions.push_back(valueReferencePointPositionsElement);
  value.referencePointPositions = valueReferencePointPositions;
  ASSERT_TRUE(withinValidInputRange(value));
}
