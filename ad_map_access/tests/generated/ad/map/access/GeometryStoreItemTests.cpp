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
#include "ad/map/access/GeometryStoreItem.hpp"

class GeometryStoreItemTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::access::GeometryStoreItem value;
    uint32_t valueLeft_edge_offset{std::numeric_limits<uint32_t>::min()};
    value.left_edge_offset = valueLeft_edge_offset;
    uint32_t valueRight_edge_offset{std::numeric_limits<uint32_t>::min()};
    value.right_edge_offset = valueRight_edge_offset;
    uint32_t valueLeft_edge_points{std::numeric_limits<uint32_t>::min()};
    value.left_edge_points = valueLeft_edge_points;
    uint32_t valueRight_edge_points{std::numeric_limits<uint32_t>::min()};
    value.right_edge_points = valueRight_edge_points;
    mValue = value;
  }

  ::ad::map::access::GeometryStoreItem mValue;
};

TEST_F(GeometryStoreItemTests, copyConstruction)
{
  ::ad::map::access::GeometryStoreItem value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryStoreItemTests, moveConstruction)
{
  ::ad::map::access::GeometryStoreItem tmpValue(mValue);
  ::ad::map::access::GeometryStoreItem value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryStoreItemTests, copyAssignment)
{
  ::ad::map::access::GeometryStoreItem value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryStoreItemTests, moveAssignment)
{
  ::ad::map::access::GeometryStoreItem tmpValue(mValue);
  ::ad::map::access::GeometryStoreItem value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(GeometryStoreItemTests, comparisonOperatorEqual)
{
  ::ad::map::access::GeometryStoreItem valueA = mValue;
  ::ad::map::access::GeometryStoreItem valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(GeometryStoreItemTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(GeometryStoreItemTests, comparisonOperatorLeft_edge_offsetDiffers)
{
  ::ad::map::access::GeometryStoreItem valueA = mValue;
  uint32_t left_edge_offset{std::numeric_limits<uint32_t>::max()};
  valueA.left_edge_offset = left_edge_offset;
  ::ad::map::access::GeometryStoreItem valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryStoreItemTests, comparisonOperatorRight_edge_offsetDiffers)
{
  ::ad::map::access::GeometryStoreItem valueA = mValue;
  uint32_t right_edge_offset{std::numeric_limits<uint32_t>::max()};
  valueA.right_edge_offset = right_edge_offset;
  ::ad::map::access::GeometryStoreItem valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryStoreItemTests, comparisonOperatorLeft_edge_pointsDiffers)
{
  ::ad::map::access::GeometryStoreItem valueA = mValue;
  uint32_t left_edge_points{std::numeric_limits<uint32_t>::max()};
  valueA.left_edge_points = left_edge_points;
  ::ad::map::access::GeometryStoreItem valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(GeometryStoreItemTests, comparisonOperatorRight_edge_pointsDiffers)
{
  ::ad::map::access::GeometryStoreItem valueA = mValue;
  uint32_t right_edge_points{std::numeric_limits<uint32_t>::max()};
  valueA.right_edge_points = right_edge_points;
  ::ad::map::access::GeometryStoreItem valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
