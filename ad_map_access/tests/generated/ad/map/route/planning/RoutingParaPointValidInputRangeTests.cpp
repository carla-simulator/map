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

#include "ad/map/route/planning/RoutingParaPointValidInputRange.hpp"

TEST(RoutingParaPointValidInputRangeTests, testValidInputRange)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  ::ad::map::point::ParaPoint valuePoint;
  ::ad::map::lane::LaneId valuePointLane_id(1);
  valuePoint.lane_id = valuePointLane_id;
  ::ad::physics::ParametricValue valuePointParametric_offset(0.);
  valuePoint.parametric_offset = valuePointParametric_offset;
  value.point = valuePoint;
  ::ad::map::route::planning::RoutingDirection valueDirection(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  value.direction = valueDirection;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(RoutingParaPointValidInputRangeTests, testValidInputRangePointTooSmall)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  ::ad::map::point::ParaPoint valuePoint;
  ::ad::map::lane::LaneId valuePointLane_id(1);
  valuePoint.lane_id = valuePointLane_id;
  ::ad::physics::ParametricValue valuePointParametric_offset(0.);
  valuePoint.parametric_offset = valuePointParametric_offset;
  value.point = valuePoint;
  ::ad::map::route::planning::RoutingDirection valueDirection(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  value.direction = valueDirection;

  // override member with data type value below input range minimum
  ::ad::map::point::ParaPoint invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberParametric_offset(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.parametric_offset = invalidInitializedMemberParametric_offset;
  value.point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RoutingParaPointValidInputRangeTests, testValidInputRangePointTooBig)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  ::ad::map::point::ParaPoint valuePoint;
  ::ad::map::lane::LaneId valuePointLane_id(1);
  valuePoint.lane_id = valuePointLane_id;
  ::ad::physics::ParametricValue valuePointParametric_offset(0.);
  valuePoint.parametric_offset = valuePointParametric_offset;
  value.point = valuePoint;
  ::ad::map::route::planning::RoutingDirection valueDirection(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  value.direction = valueDirection;

  // override member with data type value above input range maximum
  ::ad::map::point::ParaPoint invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberParametric_offset(1. * 1.1);
  invalidInitializedMember.parametric_offset = invalidInitializedMemberParametric_offset;
  value.point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RoutingParaPointValidInputRangeTests, testValidInputRangeDirectionTooSmall)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  ::ad::map::point::ParaPoint valuePoint;
  ::ad::map::lane::LaneId valuePointLane_id(1);
  valuePoint.lane_id = valuePointLane_id;
  ::ad::physics::ParametricValue valuePointParametric_offset(0.);
  valuePoint.parametric_offset = valuePointParametric_offset;
  value.point = valuePoint;
  ::ad::map::route::planning::RoutingDirection valueDirection(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  value.direction = valueDirection;

  // override member with data type value below input range minimum
  ::ad::map::route::planning::RoutingDirection invalidInitializedMember(
    static_cast<::ad::map::route::planning::RoutingDirection>(-1));
  value.direction = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(RoutingParaPointValidInputRangeTests, testValidInputRangeDirectionTooBig)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  ::ad::map::point::ParaPoint valuePoint;
  ::ad::map::lane::LaneId valuePointLane_id(1);
  valuePoint.lane_id = valuePointLane_id;
  ::ad::physics::ParametricValue valuePointParametric_offset(0.);
  valuePoint.parametric_offset = valuePointParametric_offset;
  value.point = valuePoint;
  ::ad::map::route::planning::RoutingDirection valueDirection(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  value.direction = valueDirection;

  // override member with data type value above input range maximum
  ::ad::map::route::planning::RoutingDirection invalidInitializedMember(
    static_cast<::ad::map::route::planning::RoutingDirection>(-1));
  value.direction = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
