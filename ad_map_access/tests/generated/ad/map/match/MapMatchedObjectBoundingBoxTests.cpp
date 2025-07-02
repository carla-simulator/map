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

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/match/MapMatchedObjectBoundingBox.hpp"

class MapMatchedObjectBoundingBoxTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    ::ad::physics::ParametricValue valueReference_point_positionsElementElementLane_pointPara_pointParametric_offset(
      0.);
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
    valueReference_point_positionsElementElementQuery_point.x
      = valueReference_point_positionsElementElementQuery_pointX;
    ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointY(-6400000);
    valueReference_point_positionsElementElementQuery_point.y
      = valueReference_point_positionsElementElementQuery_pointY;
    ::ad::map::point::ECEFCoordinate valueReference_point_positionsElementElementQuery_pointZ(-6400000);
    valueReference_point_positionsElementElementQuery_point.z
      = valueReference_point_positionsElementElementQuery_pointZ;
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
    mValue = value;
  }

  ::ad::map::match::MapMatchedObjectBoundingBox mValue;
};

TEST_F(MapMatchedObjectBoundingBoxTests, copyConstruction)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedObjectBoundingBoxTests, moveConstruction)
{
  ::ad::map::match::MapMatchedObjectBoundingBox tmpValue(mValue);
  ::ad::map::match::MapMatchedObjectBoundingBox value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedObjectBoundingBoxTests, copyAssignment)
{
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedObjectBoundingBoxTests, moveAssignment)
{
  ::ad::map::match::MapMatchedObjectBoundingBox tmpValue(mValue);
  ::ad::map::match::MapMatchedObjectBoundingBox value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedObjectBoundingBoxTests, comparisonOperatorEqual)
{
  ::ad::map::match::MapMatchedObjectBoundingBox valueA = mValue;
  ::ad::map::match::MapMatchedObjectBoundingBox valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(MapMatchedObjectBoundingBoxTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(MapMatchedObjectBoundingBoxTests, comparisonOperatorLane_occupied_regionsDiffers)
{
  ::ad::map::match::MapMatchedObjectBoundingBox valueA = mValue;
  ::ad::map::match::LaneOccupiedRegionList lane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion lane_occupied_regionsElement;
  ::ad::map::lane::LaneId lane_occupied_regionsElementLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  lane_occupied_regionsElement.lane_id = lane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange lane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue lane_occupied_regionsElementLongitudinal_rangeMinimum(1.);
  lane_occupied_regionsElementLongitudinal_range.minimum = lane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue lane_occupied_regionsElementLongitudinal_rangeMaximum(1.);
  lane_occupied_regionsElementLongitudinal_range.maximum = lane_occupied_regionsElementLongitudinal_rangeMaximum;
  lane_occupied_regionsElementLongitudinal_range.maximum = lane_occupied_regionsElementLongitudinal_range.minimum;
  lane_occupied_regionsElementLongitudinal_range.minimum = lane_occupied_regionsElementLongitudinal_range.maximum;
  lane_occupied_regionsElement.longitudinal_range = lane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange lane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue lane_occupied_regionsElementLateral_rangeMinimum(1.);
  lane_occupied_regionsElementLateral_range.minimum = lane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue lane_occupied_regionsElementLateral_rangeMaximum(1.);
  lane_occupied_regionsElementLateral_range.maximum = lane_occupied_regionsElementLateral_rangeMaximum;
  lane_occupied_regionsElementLateral_range.maximum = lane_occupied_regionsElementLateral_range.minimum;
  lane_occupied_regionsElementLateral_range.minimum = lane_occupied_regionsElementLateral_range.maximum;
  lane_occupied_regionsElement.lateral_range = lane_occupied_regionsElementLateral_range;
  lane_occupied_regions.resize(2, lane_occupied_regionsElement);
  valueA.lane_occupied_regions = lane_occupied_regions;
  ::ad::map::match::MapMatchedObjectBoundingBox valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedObjectBoundingBoxTests, comparisonOperatorReference_point_positionsDiffers)
{
  ::ad::map::match::MapMatchedObjectBoundingBox valueA = mValue;
  ::ad::map::match::MapMatchedObjectReferencePositionList reference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList reference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition reference_point_positionsElementElement;
  ::ad::map::match::LanePoint reference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint reference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId reference_point_positionsElementElementLane_pointPara_pointLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  reference_point_positionsElementElementLane_pointPara_point.lane_id
    = reference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue reference_point_positionsElementElementLane_pointPara_pointParametric_offset(1.);
  reference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = reference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  reference_point_positionsElementElementLane_point.para_point
    = reference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue reference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::max());
  reference_point_positionsElementElementLane_point.lateral_t
    = reference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance reference_point_positionsElementElementLane_pointLane_length(1e9);
  reference_point_positionsElementElementLane_point.lane_length
    = reference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance reference_point_positionsElementElementLane_pointLane_width(1e9);
  reference_point_positionsElementElementLane_point.lane_width
    = reference_point_positionsElementElementLane_pointLane_width;
  reference_point_positionsElementElement.lane_point = reference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType reference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::LANE_RIGHT);
  reference_point_positionsElementElement.type = reference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint reference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementMatched_pointX(6400000);
  reference_point_positionsElementElementMatched_point.x = reference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementMatched_pointY(6400000);
  reference_point_positionsElementElementMatched_point.y = reference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementMatched_pointZ(6400000);
  reference_point_positionsElementElementMatched_point.z = reference_point_positionsElementElementMatched_pointZ;
  reference_point_positionsElementElement.matched_point = reference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability reference_point_positionsElementElementProbability(1.);
  reference_point_positionsElementElement.probability = reference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint reference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementQuery_pointX(6400000);
  reference_point_positionsElementElementQuery_point.x = reference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementQuery_pointY(6400000);
  reference_point_positionsElementElementQuery_point.y = reference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate reference_point_positionsElementElementQuery_pointZ(6400000);
  reference_point_positionsElementElementQuery_point.z = reference_point_positionsElementElementQuery_pointZ;
  reference_point_positionsElementElement.query_point = reference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance reference_point_positionsElementElementMatched_point_distance(1e9);
  reference_point_positionsElementElement.matched_point_distance
    = reference_point_positionsElementElementMatched_point_distance;
  reference_point_positionsElement.resize(2, reference_point_positionsElementElement);
  reference_point_positions.resize(2, reference_point_positionsElement);
  valueA.reference_point_positions = reference_point_positions;
  ::ad::map::match::MapMatchedObjectBoundingBox valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedObjectBoundingBoxTests, comparisonOperatorSampling_distanceDiffers)
{
  ::ad::map::match::MapMatchedObjectBoundingBox valueA = mValue;
  ::ad::physics::Distance sampling_distance(1e9);
  valueA.sampling_distance = sampling_distance;
  ::ad::map::match::MapMatchedObjectBoundingBox valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedObjectBoundingBoxTests, comparisonOperatorMatch_radiusDiffers)
{
  ::ad::map::match::MapMatchedObjectBoundingBox valueA = mValue;
  ::ad::physics::Distance match_radius(1e9);
  valueA.match_radius = match_radius;
  ::ad::map::match::MapMatchedObjectBoundingBox valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
