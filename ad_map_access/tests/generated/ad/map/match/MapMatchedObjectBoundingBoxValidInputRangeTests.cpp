/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
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
  ::ad::map::match::LaneOccupiedRegionList valueLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueLane_occupied_regionsElementLane_id(1);
  valueLane_occupied_regionsElement.lane_id = valueLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_range.minimum;
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_range.maximum;
  valueLane_occupied_regionsElement.longitudinal_range = valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_rangeMaximum;
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_range.minimum;
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_range.maximum;
  valueLane_occupied_regionsElement.lateral_range = valueLane_occupied_regionsElementLateral_range;
  valueLane_occupied_regions.resize(1, valueLane_occupied_regionsElement);
  value.lane_occupied_regions = valueLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId valueReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueReference_point_positionsElementElementLane_point.para_point
    = valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReference_point_positionsElementElementLane_point.lateral_t
    = valueReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_length(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_length
    = valueReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_width(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_width
    = valueReference_point_positionsElementElementLane_pointLane_width;
  valueReference_point_positionsElementElement.lane_point = valueReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReference_point_positionsElementElement.type = valueReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointX(-6400000);
  valueReference_point_positionsElementElementMatched_point.x
    = valueReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointY(-6400000);
  valueReference_point_positionsElementElementMatched_point.y
    = valueReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointZ(-6400000);
  valueReference_point_positionsElementElementMatched_point.z
    = valueReference_point_positionsElementElementMatched_pointZ;
  valueReference_point_positionsElementElement.matched_point
    = valueReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueReference_point_positionsElementElementProbability(0.);
  valueReference_point_positionsElementElement.probability = valueReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointX(-6400000);
  valueReference_point_positionsElementElementQuery_point.x = valueReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
  valueReference_point_positionsElementElementQuery_point.y = valueReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
  valueReference_point_positionsElementElementQuery_point.z = valueReference_point_positionsElementElementQuery_pointZ;
  valueReference_point_positionsElementElement.query_point = valueReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueReference_point_positionsElementElementMatched_point_distance(-1e9);
  valueReference_point_positionsElementElement.matched_point_distance
    = valueReference_point_positionsElementElementMatched_point_distance;
  valueReference_point_positionsElement.resize(1, valueReference_point_positionsElementElement);
  valueReference_point_positions.resize(1, valueReference_point_positionsElement);
  value.reference_point_positions = valueReference_point_positions;
  ::ad::physics::Distance valueSampling_distance(-1e9);
  value.sampling_distance = valueSampling_distance;
  ::ad::physics::Distance valueMatch_radius(-1e9);
  value.match_radius = valueMatch_radius;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangeSampling_distanceTooSmall)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::map::match::LaneOccupiedRegionList valueLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueLane_occupied_regionsElementLane_id(1);
  valueLane_occupied_regionsElement.lane_id = valueLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_range.minimum;
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_range.maximum;
  valueLane_occupied_regionsElement.longitudinal_range = valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_rangeMaximum;
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_range.minimum;
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_range.maximum;
  valueLane_occupied_regionsElement.lateral_range = valueLane_occupied_regionsElementLateral_range;
  valueLane_occupied_regions.resize(1, valueLane_occupied_regionsElement);
  value.lane_occupied_regions = valueLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId valueReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueReference_point_positionsElementElementLane_point.para_point
    = valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReference_point_positionsElementElementLane_point.lateral_t
    = valueReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_length(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_length
    = valueReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_width(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_width
    = valueReference_point_positionsElementElementLane_pointLane_width;
  valueReference_point_positionsElementElement.lane_point = valueReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReference_point_positionsElementElement.type = valueReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointX(-6400000);
  valueReference_point_positionsElementElementMatched_point.x
    = valueReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointY(-6400000);
  valueReference_point_positionsElementElementMatched_point.y
    = valueReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointZ(-6400000);
  valueReference_point_positionsElementElementMatched_point.z
    = valueReference_point_positionsElementElementMatched_pointZ;
  valueReference_point_positionsElementElement.matched_point
    = valueReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueReference_point_positionsElementElementProbability(0.);
  valueReference_point_positionsElementElement.probability = valueReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointX(-6400000);
  valueReference_point_positionsElementElementQuery_point.x = valueReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
  valueReference_point_positionsElementElementQuery_point.y = valueReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
  valueReference_point_positionsElementElementQuery_point.z = valueReference_point_positionsElementElementQuery_pointZ;
  valueReference_point_positionsElementElement.query_point = valueReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueReference_point_positionsElementElementMatched_point_distance(-1e9);
  valueReference_point_positionsElementElement.matched_point_distance
    = valueReference_point_positionsElementElementMatched_point_distance;
  valueReference_point_positionsElement.resize(1, valueReference_point_positionsElementElement);
  valueReference_point_positions.resize(1, valueReference_point_positionsElement);
  value.reference_point_positions = valueReference_point_positions;
  ::ad::physics::Distance valueSampling_distance(-1e9);
  value.sampling_distance = valueSampling_distance;
  ::ad::physics::Distance valueMatch_radius(-1e9);
  value.match_radius = valueMatch_radius;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.sampling_distance = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangeSampling_distanceTooBig)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::map::match::LaneOccupiedRegionList valueLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueLane_occupied_regionsElementLane_id(1);
  valueLane_occupied_regionsElement.lane_id = valueLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_range.minimum;
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_range.maximum;
  valueLane_occupied_regionsElement.longitudinal_range = valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_rangeMaximum;
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_range.minimum;
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_range.maximum;
  valueLane_occupied_regionsElement.lateral_range = valueLane_occupied_regionsElementLateral_range;
  valueLane_occupied_regions.resize(1, valueLane_occupied_regionsElement);
  value.lane_occupied_regions = valueLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId valueReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueReference_point_positionsElementElementLane_point.para_point
    = valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReference_point_positionsElementElementLane_point.lateral_t
    = valueReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_length(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_length
    = valueReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_width(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_width
    = valueReference_point_positionsElementElementLane_pointLane_width;
  valueReference_point_positionsElementElement.lane_point = valueReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReference_point_positionsElementElement.type = valueReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointX(-6400000);
  valueReference_point_positionsElementElementMatched_point.x
    = valueReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointY(-6400000);
  valueReference_point_positionsElementElementMatched_point.y
    = valueReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointZ(-6400000);
  valueReference_point_positionsElementElementMatched_point.z
    = valueReference_point_positionsElementElementMatched_pointZ;
  valueReference_point_positionsElementElement.matched_point
    = valueReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueReference_point_positionsElementElementProbability(0.);
  valueReference_point_positionsElementElement.probability = valueReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointX(-6400000);
  valueReference_point_positionsElementElementQuery_point.x = valueReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
  valueReference_point_positionsElementElementQuery_point.y = valueReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
  valueReference_point_positionsElementElementQuery_point.z = valueReference_point_positionsElementElementQuery_pointZ;
  valueReference_point_positionsElementElement.query_point = valueReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueReference_point_positionsElementElementMatched_point_distance(-1e9);
  valueReference_point_positionsElementElement.matched_point_distance
    = valueReference_point_positionsElementElementMatched_point_distance;
  valueReference_point_positionsElement.resize(1, valueReference_point_positionsElementElement);
  valueReference_point_positions.resize(1, valueReference_point_positionsElement);
  value.reference_point_positions = valueReference_point_positions;
  ::ad::physics::Distance valueSampling_distance(-1e9);
  value.sampling_distance = valueSampling_distance;
  ::ad::physics::Distance valueMatch_radius(-1e9);
  value.match_radius = valueMatch_radius;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.sampling_distance = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangesampling_distanceDefault)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::physics::Distance valueDefault;
  value.sampling_distance = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangeMatch_radiusTooSmall)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::map::match::LaneOccupiedRegionList valueLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueLane_occupied_regionsElementLane_id(1);
  valueLane_occupied_regionsElement.lane_id = valueLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_range.minimum;
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_range.maximum;
  valueLane_occupied_regionsElement.longitudinal_range = valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_rangeMaximum;
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_range.minimum;
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_range.maximum;
  valueLane_occupied_regionsElement.lateral_range = valueLane_occupied_regionsElementLateral_range;
  valueLane_occupied_regions.resize(1, valueLane_occupied_regionsElement);
  value.lane_occupied_regions = valueLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId valueReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueReference_point_positionsElementElementLane_point.para_point
    = valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReference_point_positionsElementElementLane_point.lateral_t
    = valueReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_length(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_length
    = valueReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_width(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_width
    = valueReference_point_positionsElementElementLane_pointLane_width;
  valueReference_point_positionsElementElement.lane_point = valueReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReference_point_positionsElementElement.type = valueReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointX(-6400000);
  valueReference_point_positionsElementElementMatched_point.x
    = valueReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointY(-6400000);
  valueReference_point_positionsElementElementMatched_point.y
    = valueReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointZ(-6400000);
  valueReference_point_positionsElementElementMatched_point.z
    = valueReference_point_positionsElementElementMatched_pointZ;
  valueReference_point_positionsElementElement.matched_point
    = valueReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueReference_point_positionsElementElementProbability(0.);
  valueReference_point_positionsElementElement.probability = valueReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointX(-6400000);
  valueReference_point_positionsElementElementQuery_point.x = valueReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
  valueReference_point_positionsElementElementQuery_point.y = valueReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
  valueReference_point_positionsElementElementQuery_point.z = valueReference_point_positionsElementElementQuery_pointZ;
  valueReference_point_positionsElementElement.query_point = valueReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueReference_point_positionsElementElementMatched_point_distance(-1e9);
  valueReference_point_positionsElementElement.matched_point_distance
    = valueReference_point_positionsElementElementMatched_point_distance;
  valueReference_point_positionsElement.resize(1, valueReference_point_positionsElementElement);
  valueReference_point_positions.resize(1, valueReference_point_positionsElement);
  value.reference_point_positions = valueReference_point_positions;
  ::ad::physics::Distance valueSampling_distance(-1e9);
  value.sampling_distance = valueSampling_distance;
  ::ad::physics::Distance valueMatch_radius(-1e9);
  value.match_radius = valueMatch_radius;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.match_radius = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangeMatch_radiusTooBig)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::map::match::LaneOccupiedRegionList valueLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueLane_occupied_regionsElementLane_id(1);
  valueLane_occupied_regionsElement.lane_id = valueLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueLane_occupied_regionsElementLongitudinal_range.maximum
    = valueLane_occupied_regionsElementLongitudinal_range.minimum;
  valueLane_occupied_regionsElementLongitudinal_range.minimum
    = valueLane_occupied_regionsElementLongitudinal_range.maximum;
  valueLane_occupied_regionsElement.longitudinal_range = valueLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_rangeMaximum;
  valueLane_occupied_regionsElementLateral_range.maximum = valueLane_occupied_regionsElementLateral_range.minimum;
  valueLane_occupied_regionsElementLateral_range.minimum = valueLane_occupied_regionsElementLateral_range.maximum;
  valueLane_occupied_regionsElement.lateral_range = valueLane_occupied_regionsElementLateral_range;
  valueLane_occupied_regions.resize(1, valueLane_occupied_regionsElement);
  value.lane_occupied_regions = valueLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId valueReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueReference_point_positionsElementElementLane_point.para_point
    = valueReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueReference_point_positionsElementElementLane_point.lateral_t
    = valueReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_length(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_length
    = valueReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueReference_point_positionsElementElementLane_pointLane_width(-1e9);
  valueReference_point_positionsElementElementLane_point.lane_width
    = valueReference_point_positionsElementElementLane_pointLane_width;
  valueReference_point_positionsElementElement.lane_point = valueReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueReference_point_positionsElementElement.type = valueReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointX(-6400000);
  valueReference_point_positionsElementElementMatched_point.x
    = valueReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointY(-6400000);
  valueReference_point_positionsElementElementMatched_point.y
    = valueReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementMatched_pointZ(-6400000);
  valueReference_point_positionsElementElementMatched_point.z
    = valueReference_point_positionsElementElementMatched_pointZ;
  valueReference_point_positionsElementElement.matched_point
    = valueReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueReference_point_positionsElementElementProbability(0.);
  valueReference_point_positionsElementElement.probability = valueReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointX(-6400000);
  valueReference_point_positionsElementElementQuery_point.x = valueReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
  valueReference_point_positionsElementElementQuery_point.y = valueReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
  valueReference_point_positionsElementElementQuery_point.z = valueReference_point_positionsElementElementQuery_pointZ;
  valueReference_point_positionsElementElement.query_point = valueReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueReference_point_positionsElementElementMatched_point_distance(-1e9);
  valueReference_point_positionsElementElement.matched_point_distance
    = valueReference_point_positionsElementElementMatched_point_distance;
  valueReference_point_positionsElement.resize(1, valueReference_point_positionsElementElement);
  valueReference_point_positions.resize(1, valueReference_point_positionsElement);
  value.reference_point_positions = valueReference_point_positions;
  ::ad::physics::Distance valueSampling_distance(-1e9);
  value.sampling_distance = valueSampling_distance;
  ::ad::physics::Distance valueMatch_radius(-1e9);
  value.match_radius = valueMatch_radius;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.match_radius = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedObjectBoundingBoxValidInputRangeTests, testValidInputRangematch_radiusDefault)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  ::ad::physics::Distance valueDefault;
  value.match_radius = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
