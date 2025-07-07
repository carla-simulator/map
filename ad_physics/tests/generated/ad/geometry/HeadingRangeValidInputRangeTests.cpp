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

#include "ad/geometry/HeadingRangeValidInputRange.hpp"

TEST(HeadingRangeValidInputRangeTests, testValidInputRange)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueBegin(-6.283185308);
  value.begin = valueBegin;
  ::ad::physics::Angle valueEnd(-6.283185308);
  value.end = valueEnd;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangeBeginTooSmall)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueBegin(-6.283185308);
  value.begin = valueBegin;
  ::ad::physics::Angle valueEnd(-6.283185308);
  value.end = valueEnd;

  // override member with data type value below input range minimum
  ::ad::physics::Angle invalidInitializedMember(-6.283185308 * 1.1);
  value.begin = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangeBeginTooBig)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueBegin(-6.283185308);
  value.begin = valueBegin;
  ::ad::physics::Angle valueEnd(-6.283185308);
  value.end = valueEnd;

  // override member with data type value above input range maximum
  ::ad::physics::Angle invalidInitializedMember(6.283185308 * 1.1);
  value.begin = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangebeginDefault)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueDefault;
  value.begin = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangeEndTooSmall)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueBegin(-6.283185308);
  value.begin = valueBegin;
  ::ad::physics::Angle valueEnd(-6.283185308);
  value.end = valueEnd;

  // override member with data type value below input range minimum
  ::ad::physics::Angle invalidInitializedMember(-6.283185308 * 1.1);
  value.end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangeEndTooBig)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueBegin(-6.283185308);
  value.begin = valueBegin;
  ::ad::physics::Angle valueEnd(-6.283185308);
  value.end = valueEnd;

  // override member with data type value above input range maximum
  ::ad::physics::Angle invalidInitializedMember(6.283185308 * 1.1);
  value.end = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(HeadingRangeValidInputRangeTests, testValidInputRangeendDefault)
{
  ::ad::geometry::HeadingRange value;
  ::ad::physics::Angle valueDefault;
  value.end = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
