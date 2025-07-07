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
#include "ad/map/geometry/PolygonIntersection.hpp"

class PolygonIntersectionTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::geometry::PolygonIntersection value;
    ::ad::map::point::ENUPointListVector valueIntersection_lines;
    ::ad::map::point::ENUPointList valueIntersection_linesElement;
    ::ad::map::point::ENUPoint valueIntersection_linesElementElement;
    ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementX(-1e8);
    valueIntersection_linesElementElement.x = valueIntersection_linesElementElementX;
    ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementY(-1e8);
    valueIntersection_linesElementElement.y = valueIntersection_linesElementElementY;
    ::ad::map::point::ENUCoordinate valueIntersection_linesElementElementZ(-1e8);
    valueIntersection_linesElementElement.z = valueIntersection_linesElementElementZ;
    valueIntersection_linesElement.resize(1, valueIntersection_linesElementElement);
    valueIntersection_lines.resize(1, valueIntersection_linesElement);
    value.intersection_lines = valueIntersection_lines;
    bool valueIs_within{true};
    value.is_within = valueIs_within;
    mValue = value;
  }

  ::ad::map::geometry::PolygonIntersection mValue;
};

TEST_F(PolygonIntersectionTests, copyConstruction)
{
  ::ad::map::geometry::PolygonIntersection value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(PolygonIntersectionTests, moveConstruction)
{
  ::ad::map::geometry::PolygonIntersection tmpValue(mValue);
  ::ad::map::geometry::PolygonIntersection value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(PolygonIntersectionTests, copyAssignment)
{
  ::ad::map::geometry::PolygonIntersection value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(PolygonIntersectionTests, moveAssignment)
{
  ::ad::map::geometry::PolygonIntersection tmpValue(mValue);
  ::ad::map::geometry::PolygonIntersection value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(PolygonIntersectionTests, comparisonOperatorEqual)
{
  ::ad::map::geometry::PolygonIntersection valueA = mValue;
  ::ad::map::geometry::PolygonIntersection valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(PolygonIntersectionTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(PolygonIntersectionTests, comparisonOperatorIntersection_linesDiffers)
{
  ::ad::map::geometry::PolygonIntersection valueA = mValue;
  ::ad::map::point::ENUPointListVector intersection_lines;
  ::ad::map::point::ENUPointList intersection_linesElement;
  ::ad::map::point::ENUPoint intersection_linesElementElement;
  ::ad::map::point::ENUCoordinate intersection_linesElementElementX(1e8);
  intersection_linesElementElement.x = intersection_linesElementElementX;
  ::ad::map::point::ENUCoordinate intersection_linesElementElementY(1e8);
  intersection_linesElementElement.y = intersection_linesElementElementY;
  ::ad::map::point::ENUCoordinate intersection_linesElementElementZ(1e8);
  intersection_linesElementElement.z = intersection_linesElementElementZ;
  intersection_linesElement.resize(2, intersection_linesElementElement);
  intersection_lines.resize(2, intersection_linesElement);
  valueA.intersection_lines = intersection_lines;
  ::ad::map::geometry::PolygonIntersection valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(PolygonIntersectionTests, comparisonOperatorIs_withinDiffers)
{
  ::ad::map::geometry::PolygonIntersection valueA = mValue;
  bool is_within{false};
  valueA.is_within = is_within;
  ::ad::map::geometry::PolygonIntersection valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
