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
#include "ad/map/point/Geometry.hpp"

class GeometryTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::point::Geometry value;
    bool valueIs_valid{true};
    value.is_valid = valueIs_valid;
    bool valueIs_closed{true};
    value.is_closed = valueIs_closed;
    ::ad::map::point::ECEFPointList valueEcef_points;
    ::ad::map::point::ECEFPoint valueEcef_pointsElement;
    ::ad::map::point::ECEFCoordinate valueEcef_pointsElementX(-6400000);
    valueEcef_pointsElement.x = valueEcef_pointsElementX;
    ::ad::map::point::ECEFCoordinate valueEcef_pointsElementY(-6400000);
    valueEcef_pointsElement.y = valueEcef_pointsElementY;
    ::ad::map::point::ECEFCoordinate valueEcef_pointsElementZ(-6400000);
    valueEcef_pointsElement.z = valueEcef_pointsElementZ;
    valueEcef_points.resize(1, valueEcef_pointsElement);
    value.ecef_points = valueEcef_points;
    ::ad::physics::Distance valueLength(-1e9);
    value.length = valueLength;
    ::ad::map::point::ENUPointCache valuePrivate_enu_points_cache;
    ::ad::map::point::ENUPointList valuePrivate_enu_points_cacheEnu_points;
    ::ad::map::point::ENUPoint valuePrivate_enu_points_cacheEnu_pointsElement;
    ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementX(-1e8);
    valuePrivate_enu_points_cacheEnu_pointsElement.x = valuePrivate_enu_points_cacheEnu_pointsElementX;
    ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementY(-1e8);
    valuePrivate_enu_points_cacheEnu_pointsElement.y = valuePrivate_enu_points_cacheEnu_pointsElementY;
    ::ad::map::point::ENUCoordinate valuePrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
    valuePrivate_enu_points_cacheEnu_pointsElement.z = valuePrivate_enu_points_cacheEnu_pointsElementZ;
    valuePrivate_enu_points_cacheEnu_points.resize(1, valuePrivate_enu_points_cacheEnu_pointsElement);
    valuePrivate_enu_points_cache.enu_points = valuePrivate_enu_points_cacheEnu_points;
    uint64_t valuePrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
    valuePrivate_enu_points_cache.enu_version = valuePrivate_enu_points_cacheEnu_version;
    value.private_enu_points_cache = valuePrivate_enu_points_cache;
    mValue = value;
  }

  ::ad::map::point::Geometry mValue;
};

TEST_F(GeometryTests, copyConstruction)
{
  ::ad::map::point::Geometry value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryTests, moveConstruction)
{
  ::ad::map::point::Geometry tmpValue(mValue);
  ::ad::map::point::Geometry value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryTests, copyAssignment)
{
  ::ad::map::point::Geometry value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryTests, moveAssignment)
{
  ::ad::map::point::Geometry tmpValue(mValue);
  ::ad::map::point::Geometry value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryTests, comparisonOperatorEqual)
{
  ::ad::map::point::Geometry valueA = mValue;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(GeometryTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(GeometryTests, comparisonOperatorIs_validDiffers)
{
  ::ad::map::point::Geometry valueA = mValue;
  bool is_valid{false};
  valueA.is_valid = is_valid;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryTests, comparisonOperatorIs_closedDiffers)
{
  ::ad::map::point::Geometry valueA = mValue;
  bool is_closed{false};
  valueA.is_closed = is_closed;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryTests, comparisonOperatorEcef_pointsDiffers)
{
  ::ad::map::point::Geometry valueA = mValue;
  ::ad::map::point::ECEFPointList ecef_points;
  ::ad::map::point::ECEFPoint ecef_pointsElement;
  ::ad::map::point::ECEFCoordinate ecef_pointsElementX(6400000);
  ecef_pointsElement.x = ecef_pointsElementX;
  ::ad::map::point::ECEFCoordinate ecef_pointsElementY(6400000);
  ecef_pointsElement.y = ecef_pointsElementY;
  ::ad::map::point::ECEFCoordinate ecef_pointsElementZ(6400000);
  ecef_pointsElement.z = ecef_pointsElementZ;
  ecef_points.resize(2, ecef_pointsElement);
  valueA.ecef_points = ecef_points;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryTests, comparisonOperatorLengthDiffers)
{
  ::ad::map::point::Geometry valueA = mValue;
  ::ad::physics::Distance length(1e9);
  valueA.length = length;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryTests, comparisonOperatorPrivate_enu_points_cacheDiffers)
{
  ::ad::map::point::Geometry valueA = mValue;
  ::ad::map::point::ENUPointCache private_enu_points_cache;
  ::ad::map::point::ENUPointList private_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint private_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate private_enu_points_cacheEnu_pointsElementX(1e8);
  private_enu_points_cacheEnu_pointsElement.x = private_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate private_enu_points_cacheEnu_pointsElementY(1e8);
  private_enu_points_cacheEnu_pointsElement.y = private_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate private_enu_points_cacheEnu_pointsElementZ(1e8);
  private_enu_points_cacheEnu_pointsElement.z = private_enu_points_cacheEnu_pointsElementZ;
  private_enu_points_cacheEnu_points.resize(2, private_enu_points_cacheEnu_pointsElement);
  private_enu_points_cache.enu_points = private_enu_points_cacheEnu_points;
  uint64_t private_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::max()};
  private_enu_points_cache.enu_version = private_enu_points_cacheEnu_version;
  valueA.private_enu_points_cache = private_enu_points_cache;
  ::ad::map::point::Geometry valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
