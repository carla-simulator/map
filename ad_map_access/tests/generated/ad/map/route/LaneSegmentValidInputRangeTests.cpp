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

#include "ad/map/route/LaneSegmentValidInputRange.hpp"

TEST(LaneSegmentValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneSegmentValidInputRangeTests, testValidInputRangeLane_intervalTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::route::LaneInterval invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberStart(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.start = invalidInitializedMemberStart;
  value.lane_interval = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneSegmentValidInputRangeTests, testValidInputRangeLane_intervalTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::route::LaneInterval invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberStart(1. * 1.1);
  invalidInitializedMember.start = invalidInitializedMemberStart;
  value.lane_interval = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
