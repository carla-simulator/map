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
#include "ad/map/point/ENUPointCache.hpp"

class ENUPointCacheTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::point::ENUPointCache value;
    ::ad::map::point::ENUPointList valueEnu_points;
    ::ad::map::point::ENUPoint valueEnu_pointsElement;
    ::ad::map::point::ENUCoordinate valueEnu_pointsElementX(-1e8);
    valueEnu_pointsElement.x = valueEnu_pointsElementX;
    ::ad::map::point::ENUCoordinate valueEnu_pointsElementY(-1e8);
    valueEnu_pointsElement.y = valueEnu_pointsElementY;
    ::ad::map::point::ENUCoordinate valueEnu_pointsElementZ(-1e8);
    valueEnu_pointsElement.z = valueEnu_pointsElementZ;
    valueEnu_points.resize(1, valueEnu_pointsElement);
    value.enu_points = valueEnu_points;
    uint64_t valueEnu_version{std::numeric_limits<uint64_t>::min()};
    value.enu_version = valueEnu_version;
    mValue = value;
  }

  ::ad::map::point::ENUPointCache mValue;
};

TEST_F(ENUPointCacheTests, copyConstruction)
{
  ::ad::map::point::ENUPointCache value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUPointCacheTests, moveConstruction)
{
  ::ad::map::point::ENUPointCache tmpValue(mValue);
  ::ad::map::point::ENUPointCache value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUPointCacheTests, copyAssignment)
{
  ::ad::map::point::ENUPointCache value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUPointCacheTests, moveAssignment)
{
  ::ad::map::point::ENUPointCache tmpValue(mValue);
  ::ad::map::point::ENUPointCache value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ENUPointCacheTests, comparisonOperatorEqual)
{
  ::ad::map::point::ENUPointCache valueA = mValue;
  ::ad::map::point::ENUPointCache valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ENUPointCacheTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ENUPointCacheTests, comparisonOperatorEnu_pointsDiffers)
{
  ::ad::map::point::ENUPointCache valueA = mValue;
  ::ad::map::point::ENUPointList enu_points;
  ::ad::map::point::ENUPoint enu_pointsElement;
  ::ad::map::point::ENUCoordinate enu_pointsElementX(1e8);
  enu_pointsElement.x = enu_pointsElementX;
  ::ad::map::point::ENUCoordinate enu_pointsElementY(1e8);
  enu_pointsElement.y = enu_pointsElementY;
  ::ad::map::point::ENUCoordinate enu_pointsElementZ(1e8);
  enu_pointsElement.z = enu_pointsElementZ;
  enu_points.resize(2, enu_pointsElement);
  valueA.enu_points = enu_points;
  ::ad::map::point::ENUPointCache valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ENUPointCacheTests, comparisonOperatorEnu_versionDiffers)
{
  ::ad::map::point::ENUPointCache valueA = mValue;
  uint64_t enu_version{std::numeric_limits<uint64_t>::max()};
  valueA.enu_version = enu_version;
  ::ad::map::point::ENUPointCache valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
