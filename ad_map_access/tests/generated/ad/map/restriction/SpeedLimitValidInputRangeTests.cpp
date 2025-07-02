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

#include "ad/map/restriction/SpeedLimitValidInputRange.hpp"

TEST(SpeedLimitValidInputRangeTests, testValidInputRange)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueSpeed_limit(-100.);
  value.speed_limit = valueSpeed_limit;
  ::ad::physics::ParametricRange valueLane_piece;
  ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
  valueLane_piece.minimum = valueLane_pieceMinimum;
  ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
  valueLane_piece.maximum = valueLane_pieceMaximum;
  valueLane_piece.maximum = valueLane_piece.minimum;
  valueLane_piece.minimum = valueLane_piece.maximum;
  value.lane_piece = valueLane_piece;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(SpeedLimitValidInputRangeTests, testValidInputRangeSpeed_limitTooSmall)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueSpeed_limit(-100.);
  value.speed_limit = valueSpeed_limit;
  ::ad::physics::ParametricRange valueLane_piece;
  ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
  valueLane_piece.minimum = valueLane_pieceMinimum;
  ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
  valueLane_piece.maximum = valueLane_pieceMaximum;
  valueLane_piece.maximum = valueLane_piece.minimum;
  valueLane_piece.minimum = valueLane_piece.maximum;
  value.lane_piece = valueLane_piece;

  // override member with data type value below input range minimum
  ::ad::physics::Speed invalidInitializedMember(-100. * 1.1);
  value.speed_limit = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(SpeedLimitValidInputRangeTests, testValidInputRangeSpeed_limitTooBig)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueSpeed_limit(-100.);
  value.speed_limit = valueSpeed_limit;
  ::ad::physics::ParametricRange valueLane_piece;
  ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
  valueLane_piece.minimum = valueLane_pieceMinimum;
  ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
  valueLane_piece.maximum = valueLane_pieceMaximum;
  valueLane_piece.maximum = valueLane_piece.minimum;
  valueLane_piece.minimum = valueLane_piece.maximum;
  value.lane_piece = valueLane_piece;

  // override member with data type value above input range maximum
  ::ad::physics::Speed invalidInitializedMember(100. * 1.1);
  value.speed_limit = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(SpeedLimitValidInputRangeTests, testValidInputRangespeed_limitDefault)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueDefault;
  value.speed_limit = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(SpeedLimitValidInputRangeTests, testValidInputRangeLane_pieceTooSmall)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueSpeed_limit(-100.);
  value.speed_limit = valueSpeed_limit;
  ::ad::physics::ParametricRange valueLane_piece;
  ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
  valueLane_piece.minimum = valueLane_pieceMinimum;
  ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
  valueLane_piece.maximum = valueLane_pieceMaximum;
  valueLane_piece.maximum = valueLane_piece.minimum;
  valueLane_piece.minimum = valueLane_piece.maximum;
  value.lane_piece = valueLane_piece;

  // override member with data type value below input range minimum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.lane_piece = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(SpeedLimitValidInputRangeTests, testValidInputRangeLane_pieceTooBig)
{
  ::ad::map::restriction::SpeedLimit value;
  ::ad::physics::Speed valueSpeed_limit(-100.);
  value.speed_limit = valueSpeed_limit;
  ::ad::physics::ParametricRange valueLane_piece;
  ::ad::physics::ParametricValue valueLane_pieceMinimum(0.);
  valueLane_piece.minimum = valueLane_pieceMinimum;
  ::ad::physics::ParametricValue valueLane_pieceMaximum(0.);
  valueLane_piece.maximum = valueLane_pieceMaximum;
  valueLane_piece.maximum = valueLane_piece.minimum;
  valueLane_piece.minimum = valueLane_piece.maximum;
  value.lane_piece = valueLane_piece;

  // override member with data type value above input range maximum
  ::ad::physics::ParametricRange invalidInitializedMember;
  ::ad::physics::ParametricValue invalidInitializedMemberMinimum(1. * 1.1);
  invalidInitializedMember.minimum = invalidInitializedMemberMinimum;
  value.lane_piece = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
