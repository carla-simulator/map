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

#include "ad/map/route/LaneSegmentListValidInputRange.hpp"

TEST(LaneSegmentListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::route::LaneSegmentList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneSegmentListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::route::LaneSegmentList value;
  ::ad::map::route::LaneSegment element;
  ::ad::map::lane::LaneId elementLeft_neighbor(1);
  element.left_neighbor = elementLeft_neighbor;
  ::ad::map::lane::LaneId elementRight_neighbor(1);
  element.right_neighbor = elementRight_neighbor;
  ::ad::map::lane::LaneIdList elementPredecessors;
  ::ad::map::lane::LaneId elementPredecessorsElement(1);
  elementPredecessors.resize(1, elementPredecessorsElement);
  element.predecessors = elementPredecessors;
  ::ad::map::lane::LaneIdList elementSuccessors;
  ::ad::map::lane::LaneId elementSuccessorsElement(1);
  elementSuccessors.resize(1, elementSuccessorsElement);
  element.successors = elementSuccessors;
  ::ad::map::route::LaneInterval elementLane_interval;
  ::ad::map::lane::LaneId elementLane_intervalLane_id(1);
  elementLane_interval.lane_id = elementLane_intervalLane_id;
  ::ad::physics::ParametricValue elementLane_intervalStart(0.);
  elementLane_interval.start = elementLane_intervalStart;
  ::ad::physics::ParametricValue elementLane_intervalEnd(0.);
  elementLane_interval.end = elementLane_intervalEnd;
  bool elementLane_intervalWrong_way{true};
  elementLane_interval.wrong_way = elementLane_intervalWrong_way;
  element.lane_interval = elementLane_interval;
  ::ad::map::route::RouteLaneOffset elementRoute_lane_offset(
    std::numeric_limits<::ad::map::route::RouteLaneOffset>::lowest());
  element.route_lane_offset = elementRoute_lane_offset;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneSegmentListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::route::LaneSegmentList value;
  ::ad::map::route::LaneSegment element;
  ::ad::map::route::LaneInterval elementLane_interval;
  ::ad::physics::ParametricValue elementLane_intervalStart(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementLane_interval.start = elementLane_intervalStart;
  element.lane_interval = elementLane_interval;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
