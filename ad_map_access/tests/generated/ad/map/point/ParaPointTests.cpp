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
#include "ad/map/point/ParaPoint.hpp"

class ParaPointTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::point::ParaPoint value;
    ::ad::map::lane::LaneId valueLane_id(1);
    value.lane_id = valueLane_id;
    ::ad::physics::ParametricValue valueParametric_offset(0.);
    value.parametric_offset = valueParametric_offset;
    mValue = value;
  }

  ::ad::map::point::ParaPoint mValue;
};

TEST_F(ParaPointTests, copyConstruction)
{
  ::ad::map::point::ParaPoint value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ParaPointTests, moveConstruction)
{
  ::ad::map::point::ParaPoint tmpValue(mValue);
  ::ad::map::point::ParaPoint value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ParaPointTests, copyAssignment)
{
  ::ad::map::point::ParaPoint value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ParaPointTests, moveAssignment)
{
  ::ad::map::point::ParaPoint tmpValue(mValue);
  ::ad::map::point::ParaPoint value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ParaPointTests, comparisonOperatorEqual)
{
  ::ad::map::point::ParaPoint valueA = mValue;
  ::ad::map::point::ParaPoint valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ParaPointTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ParaPointTests, comparisonOperatorLane_idDiffers)
{
  ::ad::map::point::ParaPoint valueA = mValue;
  ::ad::map::lane::LaneId lane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  valueA.lane_id = lane_id;
  ::ad::map::point::ParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ParaPointTests, comparisonOperatorParametric_offsetDiffers)
{
  ::ad::map::point::ParaPoint valueA = mValue;
  ::ad::physics::ParametricValue parametric_offset(1.);
  valueA.parametric_offset = parametric_offset;
  ::ad::map::point::ParaPoint valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
