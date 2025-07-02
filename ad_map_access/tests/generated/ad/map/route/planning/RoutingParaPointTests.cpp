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
#include "ad/map/route/planning/RoutingParaPoint.hpp"

class RoutingParaPointTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::route::planning::RoutingParaPoint value;
    ::ad::map::point::ParaPoint valuePoint;
    ::ad::map::lane::LaneId valuePointLane_id(1);
    valuePoint.lane_id = valuePointLane_id;
    ::ad::physics::ParametricValue valuePointParametric_offset(0.);
    valuePoint.parametric_offset = valuePointParametric_offset;
    value.point = valuePoint;
    ::ad::map::route::planning::RoutingDirection valueDirection(
      ::ad::map::route::planning::RoutingDirection::DONT_CARE);
    value.direction = valueDirection;
    mValue = value;
  }

  ::ad::map::route::planning::RoutingParaPoint mValue;
};

TEST_F(RoutingParaPointTests, copyConstruction)
{
  ::ad::map::route::planning::RoutingParaPoint value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RoutingParaPointTests, moveConstruction)
{
  ::ad::map::route::planning::RoutingParaPoint tmpValue(mValue);
  ::ad::map::route::planning::RoutingParaPoint value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(RoutingParaPointTests, copyAssignment)
{
  ::ad::map::route::planning::RoutingParaPoint value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(RoutingParaPointTests, moveAssignment)
{
  ::ad::map::route::planning::RoutingParaPoint tmpValue(mValue);
  ::ad::map::route::planning::RoutingParaPoint value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(RoutingParaPointTests, comparisonOperatorEqual)
{
  ::ad::map::route::planning::RoutingParaPoint valueA = mValue;
  ::ad::map::route::planning::RoutingParaPoint valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(RoutingParaPointTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(RoutingParaPointTests, comparisonOperatorPointDiffers)
{
  ::ad::map::route::planning::RoutingParaPoint valueA = mValue;
  ::ad::map::point::ParaPoint point;
  ::ad::map::lane::LaneId pointLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  point.lane_id = pointLane_id;
  ::ad::physics::ParametricValue pointParametric_offset(1.);
  point.parametric_offset = pointParametric_offset;
  valueA.point = point;
  ::ad::map::route::planning::RoutingParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(RoutingParaPointTests, comparisonOperatorDirectionDiffers)
{
  ::ad::map::route::planning::RoutingParaPoint valueA = mValue;
  ::ad::map::route::planning::RoutingDirection direction(::ad::map::route::planning::RoutingDirection::NEGATIVE);
  valueA.direction = direction;
  ::ad::map::route::planning::RoutingParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
