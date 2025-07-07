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

#include "ad/map/match/LaneOccupiedRegionValidInputRange.hpp"

TEST(LaneOccupiedRegionValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::LaneOccupiedRegion value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricRange valueLongitudinal_range;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
  valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
  valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
  valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
  valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
  value.longitudinal_range = valueLongitudinal_range;
  ::ad::physics::ParametricRange valueLateral_range;
  ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
  valueLateral_range.minimum = valueLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
  valueLateral_range.maximum = valueLateral_rangeMaximum;
  valueLateral_range.maximum = valueLateral_range.minimum;
  valueLateral_range.minimum = valueLateral_range.maximum;
  value.lateral_range = valueLateral_range;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionValidInputRangeTests, testValidInputRangeLongitudinal_rangeTooSmall)
{
  ::ad::map::match::LaneOccupiedRegion value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricRange valueLongitudinal_range;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
  valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
  valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
  valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
  valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
  value.longitudinal_range = valueLongitudinal_range;
  ::ad::physics::ParametricRange valueLateral_range;
  ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
  valueLateral_range.minimum = valueLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
  valueLateral_range.maximum = valueLateral_rangeMaximum;
  valueLateral_range.maximum = valueLateral_range.minimum;
  valueLateral_range.minimum = valueLateral_range.maximum;
  value.lateral_range = valueLateral_range;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.longitudinal_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionValidInputRangeTests, testValidInputRangeLongitudinal_rangeTooBig)
{
  ::ad::map::match::LaneOccupiedRegion value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricRange valueLongitudinal_range;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
  valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
  valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
  valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
  valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
  value.longitudinal_range = valueLongitudinal_range;
  ::ad::physics::ParametricRange valueLateral_range;
  ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
  valueLateral_range.minimum = valueLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
  valueLateral_range.maximum = valueLateral_rangeMaximum;
  valueLateral_range.maximum = valueLateral_range.minimum;
  valueLateral_range.minimum = valueLateral_range.maximum;
  value.lateral_range = valueLateral_range;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(1. * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.longitudinal_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionValidInputRangeTests, testValidInputRangeLateral_rangeTooSmall)
{
  ::ad::map::match::LaneOccupiedRegion value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricRange valueLongitudinal_range;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
  valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
  valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
  valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
  valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
  value.longitudinal_range = valueLongitudinal_range;
  ::ad::physics::ParametricRange valueLateral_range;
  ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
  valueLateral_range.minimum = valueLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
  valueLateral_range.maximum = valueLateral_rangeMaximum;
  valueLateral_range.maximum = valueLateral_range.minimum;
  valueLateral_range.minimum = valueLateral_range.maximum;
  value.lateral_range = valueLateral_range;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.lateral_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneOccupiedRegionValidInputRangeTests, testValidInputRangeLateral_rangeTooBig)
{
  ::ad::map::match::LaneOccupiedRegion value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricRange valueLongitudinal_range;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMinimum(0.);
  valueLongitudinal_range.minimum = valueLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueLongitudinal_rangeMaximum(0.);
  valueLongitudinal_range.maximum = valueLongitudinal_rangeMaximum;
  valueLongitudinal_range.maximum = valueLongitudinal_range.minimum;
  valueLongitudinal_range.minimum = valueLongitudinal_range.maximum;
  value.longitudinal_range = valueLongitudinal_range;
  ::ad::physics::ParametricRange valueLateral_range;
  ::ad::physics::ParametricValue valueLateral_rangeMinimum(0.);
  valueLateral_range.minimum = valueLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueLateral_rangeMaximum(0.);
  valueLateral_range.maximum = valueLateral_rangeMaximum;
  valueLateral_range.maximum = valueLateral_range.minimum;
  valueLateral_range.minimum = valueLateral_range.maximum;
  value.lateral_range = valueLateral_range;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(1. * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.lateral_range = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
