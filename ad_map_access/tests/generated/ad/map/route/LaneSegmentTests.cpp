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
#include "ad/map/route/LaneSegment.hpp"

class LaneSegmentTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::LaneSegment value;
    ::ad::map::lane::LaneId valueLeft_neighbor(1);
    value.left_neighbor = valueLeft_neighbor;
    ::ad::map::lane::LaneId valueRight_neighbor(1);
    value.right_neighbor = valueRight_neighbor;
    ::ad::map::lane::LaneIdList valuePredecessors;
    ::ad::map::lane::LaneId valuePredecessorsElement(1);
    valuePredecessors.resize(1, valuePredecessorsElement);
    value.predecessors = valuePredecessors;
    ::ad::map::lane::LaneIdList valueSuccessors;
    ::ad::map::lane::LaneId valueSuccessorsElement(1);
    valueSuccessors.resize(1, valueSuccessorsElement);
    value.successors = valueSuccessors;
    ::ad::map::route::LaneInterval valueLane_interval;
    ::ad::map::lane::LaneId valueLane_intervalLane_id(1);
    valueLane_interval.lane_id = valueLane_intervalLane_id;
    ::ad::physics::ParametricValue valueLane_intervalStart(0.);
    valueLane_interval.start = valueLane_intervalStart;
    ::ad::physics::ParametricValue valueLane_intervalEnd(0.);
    valueLane_interval.end = valueLane_intervalEnd;
    bool valueLane_intervalWrong_way{true};
    valueLane_interval.wrong_way = valueLane_intervalWrong_way;
    value.lane_interval = valueLane_interval;
    ::ad::map::route::RouteLaneOffset valueRoute_lane_offset(
      std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
    value.route_lane_offset = valueRoute_lane_offset;
    mValue = value;
  }

  ::ad::map::route::LaneSegment mValue;
};

TEST_F(LaneSegmentTests, copyConstruction)
{
  ::ad::map::route::LaneSegment value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, moveConstruction)
{
  ::ad::map::route::LaneSegment tmpValue(mValue);
  ::ad::map::route::LaneSegment value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, copyAssignment)
{
  ::ad::map::route::LaneSegment value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, moveAssignment)
{
  ::ad::map::route::LaneSegment tmpValue(mValue);
  ::ad::map::route::LaneSegment value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneSegmentTests, comparisonOperatorEqual)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneSegmentTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LaneSegmentTests, comparisonOperatorLeft_neighborDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::lane::LaneId left_neighbor(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.left_neighbor = left_neighbor;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorRight_neighborDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::lane::LaneId right_neighbor(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.right_neighbor = right_neighbor;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorPredecessorsDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::lane::LaneIdList predecessors;
  ::ad::map::lane::LaneId predecessorsElement(std::numeric_limits<::ad::map::lane::LaneId>::max());
  predecessors.resize(2, predecessorsElement);
  valueA.predecessors = predecessors;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorSuccessorsDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::lane::LaneIdList successors;
  ::ad::map::lane::LaneId successorsElement(std::numeric_limits<::ad::map::lane::LaneId>::max());
  successors.resize(2, successorsElement);
  valueA.successors = successors;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorLane_intervalDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::route::LaneInterval lane_interval;
  ::ad::map::lane::LaneId lane_intervalLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  lane_interval.lane_id = lane_intervalLane_id;
  ::ad::physics::ParametricValue lane_intervalStart(1.);
  lane_interval.start = lane_intervalStart;
  ::ad::physics::ParametricValue lane_intervalEnd(1.);
  lane_interval.end = lane_intervalEnd;
  bool lane_intervalWrong_way{false};
  lane_interval.wrong_way = lane_intervalWrong_way;
  valueA.lane_interval = lane_interval;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneSegmentTests, comparisonOperatorRoute_lane_offsetDiffers)
{
  ::ad::map::route::LaneSegment valueA = mValue;
  ::ad::map::route::RouteLaneOffset route_lane_offset(std::numeric_limits<::ad::map::route::RouteLaneOffset>::max());
  valueA.route_lane_offset = route_lane_offset;
  ::ad::map::route::LaneSegment valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
