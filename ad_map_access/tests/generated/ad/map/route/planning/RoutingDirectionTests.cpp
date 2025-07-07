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
#include "ad/map/route/planning/RoutingDirection.hpp"

TEST(RoutingDirectionTests, testFromString)
{
  ASSERT_EQ(fromString<::ad::map::route::planning::RoutingDirection>("DONT_CARE"),
            ::ad::map::route::planning::RoutingDirection::DONT_CARE);
  ASSERT_EQ(
    fromString<::ad::map::route::planning::RoutingDirection>("::ad::map::route::planning::RoutingDirection::DONT_CARE"),
    ::ad::map::route::planning::RoutingDirection::DONT_CARE);

  ASSERT_EQ(fromString<::ad::map::route::planning::RoutingDirection>("POSITIVE"),
            ::ad::map::route::planning::RoutingDirection::POSITIVE);
  ASSERT_EQ(
    fromString<::ad::map::route::planning::RoutingDirection>("::ad::map::route::planning::RoutingDirection::POSITIVE"),
    ::ad::map::route::planning::RoutingDirection::POSITIVE);

  ASSERT_EQ(fromString<::ad::map::route::planning::RoutingDirection>("NEGATIVE"),
            ::ad::map::route::planning::RoutingDirection::NEGATIVE);
  ASSERT_EQ(
    fromString<::ad::map::route::planning::RoutingDirection>("::ad::map::route::planning::RoutingDirection::NEGATIVE"),
    ::ad::map::route::planning::RoutingDirection::NEGATIVE);

  EXPECT_ANY_THROW({ fromString<::ad::map::route::planning::RoutingDirection>("NOT A VALID ENUM LITERAL"); });
}

TEST(RoutingDirectionTests, testToString)
{
  int32_t minValue = std::numeric_limits<int32_t>::max();
  int32_t maxValue = std::numeric_limits<int32_t>::min();

  ASSERT_EQ(toString(::ad::map::route::planning::RoutingDirection::DONT_CARE),
            "::ad::map::route::planning::RoutingDirection::DONT_CARE");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::DONT_CARE));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::DONT_CARE));

  ASSERT_EQ(toString(::ad::map::route::planning::RoutingDirection::POSITIVE),
            "::ad::map::route::planning::RoutingDirection::POSITIVE");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::POSITIVE));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::POSITIVE));

  ASSERT_EQ(toString(::ad::map::route::planning::RoutingDirection::NEGATIVE),
            "::ad::map::route::planning::RoutingDirection::NEGATIVE");
  minValue = std::min(minValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::NEGATIVE));
  maxValue = std::max(maxValue, static_cast<int32_t>(::ad::map::route::planning::RoutingDirection::NEGATIVE));

  ASSERT_EQ(toString(static_cast<::ad::map::route::planning::RoutingDirection>(minValue - 1)), "UNKNOWN ENUM VALUE");
  ASSERT_EQ(toString(static_cast<::ad::map::route::planning::RoutingDirection>(maxValue + 1)), "UNKNOWN ENUM VALUE");
}

TEST(RoutingDirectionTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::route::planning::RoutingDirection value(::ad::map::route::planning::RoutingDirection::DONT_CARE);
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
