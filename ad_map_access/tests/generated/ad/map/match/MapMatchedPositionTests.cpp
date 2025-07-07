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
#include "ad/map/match/MapMatchedPosition.hpp"

class MapMatchedPositionTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::match::MapMatchedPosition value;
    ::ad::map::match::LanePoint valueLane_point;
    ::ad::map::point::ParaPoint valueLane_pointPara_point;
    ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
    valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
    ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
    valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
    valueLane_point.para_point = valueLane_pointPara_point;
    ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
    valueLane_point.lateral_t = valueLane_pointLateral_t;
    ::ad::physics::Distance valueLane_pointLane_length(-1e9);
    valueLane_point.lane_length = valueLane_pointLane_length;
    ::ad::physics::Distance valueLane_pointLane_width(-1e9);
    valueLane_point.lane_width = valueLane_pointLane_width;
    value.lane_point = valueLane_point;
    ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
    value.type = valueType;
    ::ad::map::point::ECEFPoint valueMatched_point;
    ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
    valueMatched_point.x = valueMatched_pointX;
    ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
    valueMatched_point.y = valueMatched_pointY;
    ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
    valueMatched_point.z = valueMatched_pointZ;
    value.matched_point = valueMatched_point;
    ::ad::physics::Probability valueProbability(0.);
    value.probability = valueProbability;
    ::ad::map::point::ECEFPoint valueQuery_point;
    ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
    valueQuery_point.x = valueQuery_pointX;
    ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
    valueQuery_point.y = valueQuery_pointY;
    ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
    valueQuery_point.z = valueQuery_pointZ;
    value.query_point = valueQuery_point;
    ::ad::physics::Distance valueMatched_point_distance(-1e9);
    value.matched_point_distance = valueMatched_point_distance;
    mValue = value;
  }

  ::ad::map::match::MapMatchedPosition mValue;
};

TEST_F(MapMatchedPositionTests, copyConstruction)
{
  ::ad::map::match::MapMatchedPosition value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedPositionTests, moveConstruction)
{
  ::ad::map::match::MapMatchedPosition tmpValue(mValue);
  ::ad::map::match::MapMatchedPosition value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedPositionTests, copyAssignment)
{
  ::ad::map::match::MapMatchedPosition value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedPositionTests, moveAssignment)
{
  ::ad::map::match::MapMatchedPosition tmpValue(mValue);
  ::ad::map::match::MapMatchedPosition value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorEqual)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorLane_pointDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::map::match::LanePoint lane_point;
  ::ad::map::point::ParaPoint lane_pointPara_point;
  ::ad::map::lane::LaneId lane_pointPara_pointLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  lane_pointPara_point.lane_id = lane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue lane_pointPara_pointParametric_offset(1.);
  lane_pointPara_point.parametric_offset = lane_pointPara_pointParametric_offset;
  lane_point.para_point = lane_pointPara_point;
  ::ad::physics::RatioValue lane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::max());
  lane_point.lateral_t = lane_pointLateral_t;
  ::ad::physics::Distance lane_pointLane_length(1e9);
  lane_point.lane_length = lane_pointLane_length;
  ::ad::physics::Distance lane_pointLane_width(1e9);
  lane_point.lane_width = lane_pointLane_width;
  valueA.lane_point = lane_point;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorTypeDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::map::match::MapMatchedPositionType type(::ad::map::match::MapMatchedPositionType::LANE_RIGHT);
  valueA.type = type;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorMatched_pointDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::map::point::ECEFPoint matched_point;
  ::ad::map::point::ECEFCoordinate matched_pointX(6400000);
  matched_point.x = matched_pointX;
  ::ad::map::point::ECEFCoordinate matched_pointY(6400000);
  matched_point.y = matched_pointY;
  ::ad::map::point::ECEFCoordinate matched_pointZ(6400000);
  matched_point.z = matched_pointZ;
  valueA.matched_point = matched_point;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorProbabilityDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::physics::Probability probability(1.);
  valueA.probability = probability;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorQuery_pointDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::map::point::ECEFPoint query_point;
  ::ad::map::point::ECEFCoordinate query_pointX(6400000);
  query_point.x = query_pointX;
  ::ad::map::point::ECEFCoordinate query_pointY(6400000);
  query_point.y = query_pointY;
  ::ad::map::point::ECEFCoordinate query_pointZ(6400000);
  query_point.z = query_pointZ;
  valueA.query_point = query_point;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(MapMatchedPositionTests, comparisonOperatorMatched_point_distanceDiffers)
{
  ::ad::map::match::MapMatchedPosition valueA = mValue;
  ::ad::physics::Distance matched_point_distance(1e9);
  valueA.matched_point_distance = matched_point_distance;
  ::ad::map::match::MapMatchedPosition valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
