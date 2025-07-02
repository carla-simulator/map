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

#include "ad/map/point/ParaPointValidInputRange.hpp"

TEST(ParaPointValidInputRangeTests, testValidInputRange)
{
  ::ad::map::point::ParaPoint value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ParaPointValidInputRangeTests, testValidInputRangeParametric_offsetTooSmall)
{
  ::ad::map::point::ParaPoint value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricValue invalidInitializedMember(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  value.parametric_offset = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ParaPointValidInputRangeTests, testValidInputRangeParametric_offsetTooBig)
{
  ::ad::map::point::ParaPoint value;
  ::ad::map::lane::LaneId valueLane_id(1);
  value.lane_id = valueLane_id;
  ::ad::physics::ParametricValue valueParametric_offset(0.);
  value.parametric_offset = valueParametric_offset;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricValue invalidInitializedMember(1. * 1.1);
  value.parametric_offset = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ParaPointValidInputRangeTests, testValidInputRangeparametric_offsetDefault)
{
  ::ad::map::point::ParaPoint value;
  ::ad::physics::ParametricValue valueDefault;
  value.parametric_offset = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
