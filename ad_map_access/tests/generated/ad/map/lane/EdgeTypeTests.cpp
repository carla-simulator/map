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

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
#endif

#include <gtest/gtest.h>
#include <limits>
#include "ad/map/lane/EdgeType.hpp"

TEST(EdgeTypeTests, testFromString)
{
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("UNKNOWN"), ::ad::map::lane::EdgeType::UNKNOWN);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::UNKNOWN"),
            ::ad::map::lane::EdgeType::UNKNOWN);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("CENTER"), ::ad::map::lane::EdgeType::CENTER);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::CENTER"),
            ::ad::map::lane::EdgeType::CENTER);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("ALIGNED"), ::ad::map::lane::EdgeType::ALIGNED);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::ALIGNED"),
            ::ad::map::lane::EdgeType::ALIGNED);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("LEFT_PROJECTED"), ::ad::map::lane::EdgeType::LEFT_PROJECTED);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::LEFT_PROJECTED"),
            ::ad::map::lane::EdgeType::LEFT_PROJECTED);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("RIGHT_PROJECTED"), ::ad::map::lane::EdgeType::RIGHT_PROJECTED);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::RIGHT_PROJECTED"),
            ::ad::map::lane::EdgeType::RIGHT_PROJECTED);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("LEFT"), ::ad::map::lane::EdgeType::LEFT);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::LEFT"), ::ad::map::lane::EdgeType::LEFT);

  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("RIGHT"), ::ad::map::lane::EdgeType::RIGHT);
  ASSERT_EQ(fromString<::ad::map::lane::EdgeType>("::ad::map::lane::EdgeType::RIGHT"),
            ::ad::map::lane::EdgeType::RIGHT);

  EXPECT_ANY_THROW({ fromString<::ad::map::lane::EdgeType>("NOT A VALID ENUM LITERAL"); });
}

TEST(EdgeTypeTests, testToString)
{
  int32_t minValue = std::numeric_limits<int32_t>::max();
  int32_t maxValue = std::numeric_limits<int32_t>::min();

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::UNKNOWN), "::ad::map::lane::EdgeType::UNKNOWN");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::UNKNOWN));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::UNKNOWN));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::CENTER), "::ad::map::lane::EdgeType::CENTER");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::CENTER));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::CENTER));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::ALIGNED), "::ad::map::lane::EdgeType::ALIGNED");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::ALIGNED));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::ALIGNED));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::LEFT_PROJECTED), "::ad::map::lane::EdgeType::LEFT_PROJECTED");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT_PROJECTED));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT_PROJECTED));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::RIGHT_PROJECTED), "::ad::map::lane::EdgeType::RIGHT_PROJECTED");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT_PROJECTED));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT_PROJECTED));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::LEFT), "::ad::map::lane::EdgeType::LEFT");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::LEFT));

  ASSERT_EQ(toString(::ad::map::lane::EdgeType::RIGHT), "::ad::map::lane::EdgeType::RIGHT");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::lane::EdgeType::RIGHT));

  ASSERT_EQ(toString(static_cast<::ad::map::lane::EdgeType>(minValue - 1)), "UNKNOWN ENUM VALUE");
  ASSERT_EQ(toString(static_cast<::ad::map::lane::EdgeType>(maxValue + 1)), "UNKNOWN ENUM VALUE");
}

TEST(EdgeTypeTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::lane::EdgeType value(::ad::map::lane::EdgeType::UNKNOWN);
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
