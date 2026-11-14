// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "gtest/gtest.h"
#include "ad/physics/RangeOperation.hpp"

namespace ad {
namespace physics {

TEST(RangeOperationTests, parametricRangeDisjunctAndIntersection)
{
  ParametricRange const left{ParametricValue(0.1), ParametricValue(0.3)};
  ParametricRange const right{ParametricValue(0.6), ParametricValue(0.9)};

  ASSERT_FALSE(doRangesOverlap(left, right));
  ASSERT_TRUE(areRangesDisjunct(left, right));

  auto const disjointIntersection = getIntersectionRange(left, right);
  ASSERT_FALSE(isRangeValid(disjointIntersection, false));

  ParametricRange mutableLeft = left;
  ASSERT_FALSE(intersectRangeWith(mutableLeft, right));
  ASSERT_FALSE(isRangeValid(mutableLeft, false));

  ParametricRange const mid{ParametricValue(0.2), ParametricValue(0.7)};
  ASSERT_TRUE(doRangesOverlap(left, mid));
  ASSERT_FALSE(areRangesDisjunct(left, mid));

  auto const validIntersection = getIntersectionRange(left, mid);
  ASSERT_TRUE(isRangeValid(validIntersection, false));
  ASSERT_EQ(ParametricValue(0.2), validIntersection.minimum);
  ASSERT_EQ(ParametricValue(0.3), validIntersection.maximum);
}

TEST(RangeOperationTests, subtractConstRanges)
{
  ParametricRange const minuend{ParametricValue(0.1), ParametricValue(0.9)};
  ParametricRange const subtrahend{ParametricValue(0.3), ParametricValue(0.6)};

  auto const parts = subtract(minuend, subtrahend);
  ASSERT_EQ(2u, parts.size());
  ASSERT_EQ(ParametricValue(0.1), parts[0].minimum);
  ASSERT_EQ(ParametricValue(0.3), parts[0].maximum);
  ASSERT_EQ(ParametricValue(0.6), parts[1].minimum);
  ASSERT_EQ(ParametricValue(0.9), parts[1].maximum);

  ParametricRange const disjoint{ParametricValue(0.95), ParametricValue(1.0)};
  auto const unchanged = subtract(minuend, disjoint);
  ASSERT_EQ(1u, unchanged.size());
  ASSERT_EQ(minuend, unchanged[0]);
}

TEST(RangeOperationTests, negativeMetricRangeOverlap)
{
  MetricRange const low{Distance(-20.0), Distance(-5.0)};
  MetricRange const high{Distance(-10.0), Distance(15.0)};
  MetricRange const separate{Distance(0.0), Distance(10.0)};

  ASSERT_TRUE(doRangesOverlap(low, high));
  ASSERT_FALSE(areRangesDisjunct(low, high));
  ASSERT_FALSE(doRangesOverlap(low, separate));
  ASSERT_TRUE(areRangesDisjunct(low, separate));
}

} // namespace physics
} // namespace ad
