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

#include "ad/map/route/RouteParaPointValidInputRange.hpp"

TEST(RouteParaPointValidInputRangeTests, testValidInputRange)
{
  ::ad::map::route::RouteParaPoint value;
  ::ad::map::route::RoutePlanningCounter valueRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  value.route_planning_counter = valueRoute_planning_counter;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RouteParaPointValidInputRangeTests, testValidInputRangeParametric_offsetTooSmall)
{
  ::ad::map::route::RouteParaPoint value;
  ::ad::map::route::RoutePlanningCounter valueRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  value.route_planning_counter = valueRoute_planning_counter;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricValue invalidInitializedMember(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  value.parametric_offset = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RouteParaPointValidInputRangeTests, testValidInputRangeParametric_offsetTooBig)
{
  ::ad::map::route::RouteParaPoint value;
  ::ad::map::route::RoutePlanningCounter valueRoute_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
  value.route_planning_counter = valueRoute_planning_counter;
  ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
  value.segment_count_from_destination = valueSegment_count_from_destination;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricValue invalidInitializedMember(1. * 1.1);
  value.parametric_offset = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RouteParaPointValidInputRangeTests, testValidInputRangeparametric_offsetDefault)
{
  ::ad::map::route::RouteParaPoint value;
  ::ad::physics::ParametricValue valueDefault;
  value.parametric_offset = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
