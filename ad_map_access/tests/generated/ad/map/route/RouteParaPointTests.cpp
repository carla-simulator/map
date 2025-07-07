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
#include "ad/map/route/RouteParaPoint.hpp"

class RouteParaPointTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::RouteParaPoint value;
    ::ad::map::route::RoutePlanningCounter valueRoute_planning_counter(
      std::numeric_limits<::ad::map::route::RoutePlanningCounter>::lowest());
    value.route_planning_counter = valueRoute_planning_counter;
    ::ad::map::route::SegmentCounter valueSegment_count_from_destination(
      std::numeric_limits<::ad::map::route::SegmentCounter>::lowest());
    value.segment_count_from_destination = valueSegment_count_from_destination;
    ::ad::physics::ParametricValue valueParametric_offset(0.);
    value.parametric_offset = valueParametric_offset;
    mValue = value;
  }

  ::ad::map::route::RouteParaPoint mValue;
};

TEST_F(RouteParaPointTests, copyConstruction)
{
  ::ad::map::route::RouteParaPoint value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RouteParaPointTests, moveConstruction)
{
  ::ad::map::route::RouteParaPoint tmpValue(mValue);
  ::ad::map::route::RouteParaPoint value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(RouteParaPointTests, copyAssignment)
{
  ::ad::map::route::RouteParaPoint value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(RouteParaPointTests, moveAssignment)
{
  ::ad::map::route::RouteParaPoint tmpValue(mValue);
  ::ad::map::route::RouteParaPoint value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RouteParaPointTests, comparisonOperatorEqual)
{
  ::ad::map::route::RouteParaPoint valueA = mValue;
  ::ad::map::route::RouteParaPoint valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(RouteParaPointTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(RouteParaPointTests, comparisonOperatorRoute_planning_counterDiffers)
{
  ::ad::map::route::RouteParaPoint valueA = mValue;
  ::ad::map::route::RoutePlanningCounter route_planning_counter(
    std::numeric_limits<::ad::map::route::RoutePlanningCounter>::max());
  valueA.route_planning_counter = route_planning_counter;
  ::ad::map::route::RouteParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RouteParaPointTests, comparisonOperatorSegment_count_from_destinationDiffers)
{
  ::ad::map::route::RouteParaPoint valueA = mValue;
  ::ad::map::route::SegmentCounter segment_count_from_destination(
    std::numeric_limits<::ad::map::route::SegmentCounter>::max());
  valueA.segment_count_from_destination = segment_count_from_destination;
  ::ad::map::route::RouteParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RouteParaPointTests, comparisonOperatorParametric_offsetDiffers)
{
  ::ad::map::route::RouteParaPoint valueA = mValue;
  ::ad::physics::ParametricValue parametric_offset(1.);
  valueA.parametric_offset = parametric_offset;
  ::ad::map::route::RouteParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
