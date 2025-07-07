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

#include "ad/map/lane/EdgeTypeValidInputRange.hpp"

TEST(EdgeTypeValidInputRangeTests, testValidInputRangeValid)
{
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::UNKNOWN));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::CENTER));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::ALIGNED));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::LEFT_PROJECTED));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::RIGHT_PROJECTED));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::LEFT));
  ASSERT_TRUE(withinValidInputRange(::ad::map::lane::EdgeType::RIGHT));
}

TEST(EdgeTypeValidInputRangeTests, testValidInputRangeInvalid)
{
  int32_t minValue = std::numeric_limits<int32_t>::max();

  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::UNKNOWN));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::CENTER));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::ALIGNED));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT_PROJECTED));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT_PROJECTED));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT));
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT));

  ASSERT_FALSE(withinValidInputRange(static_cast<::ad::map::lane::EdgeType>(minValue - 1)));
}
