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

#include "ad/map/match/LanePointValidInputRange.hpp"

TEST(LanePointValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangePara_pointTooSmall)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value below input range minimum
  ::ad::map::point::ParaPoint invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberParametric_offset(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.parametric_offset = invalidInitializedMemberParametric_offset;
  value.para_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangePara_pointTooBig)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value above input range maximum
  ::ad::map::point::ParaPoint invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberParametric_offset(1. * 1.1);
  invalidInitializedMember.parametric_offset = invalidInitializedMemberParametric_offset;
  value.para_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangeLane_lengthTooSmall)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.lane_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangeLane_lengthTooBig)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.lane_length = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangelane_lengthDefault)
{
  ::ad::map::match::LanePoint value;
  ::ad::physics::Distance valueDefault;
  value.lane_length = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangeLane_widthTooSmall)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.lane_width = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangeLane_widthTooBig)
{
  ::ad::map::match::LanePoint value;
  ::ad::map::point::ParaPoint valuePara_point;
  ::ad::map::lane::LaneId valuePara_pointLane_id(1);
  valuePara_point.lane_id = valuePara_pointLane_id;
  ::ad::physics::ParametricValue valuePara_pointParametric_offset(0.);
  valuePara_point.parametric_offset = valuePara_pointParametric_offset;
  value.para_point = valuePara_point;
  ::ad::physics::RatioValue valueLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  value.lateral_t = valueLateral_t;
  ::ad::physics::Distance valueLane_length(-1e9);
  value.lane_length = valueLane_length;
  ::ad::physics::Distance valueLane_width(-1e9);
  value.lane_width = valueLane_width;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.lane_width = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LanePointValidInputRangeTests, testValidInputRangelane_widthDefault)
{
  ::ad::map::match::LanePoint value;
  ::ad::physics::Distance valueDefault;
  value.lane_width = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
