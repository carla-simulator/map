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
#include "ad/map/geometry/LaneRegions.hpp"

class LaneRegionsTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::geometry::LaneRegions value;
    ::ad::map::match::LaneOccupiedRegionList valueFully_occluded;
    ::ad::map::match::LaneOccupiedRegion valueFully_occludedElement;
    ::ad::map::lane::LaneId valueFully_occludedElementLane_id(1);
    valueFully_occludedElement.lane_id = valueFully_occludedElementLane_id;
    ::ad::physics::ParametricRange valueFully_occludedElementLongitudinal_range;
    ::ad::physics::ParametricValue valueFully_occludedElementLongitudinal_rangeMinimum(0.);
    valueFully_occludedElementLongitudinal_range.minimum = valueFully_occludedElementLongitudinal_rangeMinimum;
    ::ad::physics::ParametricValue valueFully_occludedElementLongitudinal_rangeMaximum(0.);
    valueFully_occludedElementLongitudinal_range.maximum = valueFully_occludedElementLongitudinal_rangeMaximum;
    valueFully_occludedElementLongitudinal_range.maximum = valueFully_occludedElementLongitudinal_range.minimum;
    valueFully_occludedElementLongitudinal_range.minimum = valueFully_occludedElementLongitudinal_range.maximum;
    valueFully_occludedElement.longitudinal_range = valueFully_occludedElementLongitudinal_range;
    ::ad::physics::ParametricRange valueFully_occludedElementLateral_range;
    ::ad::physics::ParametricValue valueFully_occludedElementLateral_rangeMinimum(0.);
    valueFully_occludedElementLateral_range.minimum = valueFully_occludedElementLateral_rangeMinimum;
    ::ad::physics::ParametricValue valueFully_occludedElementLateral_rangeMaximum(0.);
    valueFully_occludedElementLateral_range.maximum = valueFully_occludedElementLateral_rangeMaximum;
    valueFully_occludedElementLateral_range.maximum = valueFully_occludedElementLateral_range.minimum;
    valueFully_occludedElementLateral_range.minimum = valueFully_occludedElementLateral_range.maximum;
    valueFully_occludedElement.lateral_range = valueFully_occludedElementLateral_range;
    valueFully_occluded.resize(1, valueFully_occludedElement);
    value.fully_occluded = valueFully_occluded;
    ::ad::map::match::LaneOccupiedRegionList valuePartly_occluded;
    ::ad::map::match::LaneOccupiedRegion valuePartly_occludedElement;
    ::ad::map::lane::LaneId valuePartly_occludedElementLane_id(1);
    valuePartly_occludedElement.lane_id = valuePartly_occludedElementLane_id;
    ::ad::physics::ParametricRange valuePartly_occludedElementLongitudinal_range;
    ::ad::physics::ParametricValue valuePartly_occludedElementLongitudinal_rangeMinimum(0.);
    valuePartly_occludedElementLongitudinal_range.minimum = valuePartly_occludedElementLongitudinal_rangeMinimum;
    ::ad::physics::ParametricValue valuePartly_occludedElementLongitudinal_rangeMaximum(0.);
    valuePartly_occludedElementLongitudinal_range.maximum = valuePartly_occludedElementLongitudinal_rangeMaximum;
    valuePartly_occludedElementLongitudinal_range.maximum = valuePartly_occludedElementLongitudinal_range.minimum;
    valuePartly_occludedElementLongitudinal_range.minimum = valuePartly_occludedElementLongitudinal_range.maximum;
    valuePartly_occludedElement.longitudinal_range = valuePartly_occludedElementLongitudinal_range;
    ::ad::physics::ParametricRange valuePartly_occludedElementLateral_range;
    ::ad::physics::ParametricValue valuePartly_occludedElementLateral_rangeMinimum(0.);
    valuePartly_occludedElementLateral_range.minimum = valuePartly_occludedElementLateral_rangeMinimum;
    ::ad::physics::ParametricValue valuePartly_occludedElementLateral_rangeMaximum(0.);
    valuePartly_occludedElementLateral_range.maximum = valuePartly_occludedElementLateral_rangeMaximum;
    valuePartly_occludedElementLateral_range.maximum = valuePartly_occludedElementLateral_range.minimum;
    valuePartly_occludedElementLateral_range.minimum = valuePartly_occludedElementLateral_range.maximum;
    valuePartly_occludedElement.lateral_range = valuePartly_occludedElementLateral_range;
    valuePartly_occluded.resize(1, valuePartly_occludedElement);
    value.partly_occluded = valuePartly_occluded;
    ::ad::map::match::LaneOccupiedRegionList valueFully_visible;
    ::ad::map::match::LaneOccupiedRegion valueFully_visibleElement;
    ::ad::map::lane::LaneId valueFully_visibleElementLane_id(1);
    valueFully_visibleElement.lane_id = valueFully_visibleElementLane_id;
    ::ad::physics::ParametricRange valueFully_visibleElementLongitudinal_range;
    ::ad::physics::ParametricValue valueFully_visibleElementLongitudinal_rangeMinimum(0.);
    valueFully_visibleElementLongitudinal_range.minimum = valueFully_visibleElementLongitudinal_rangeMinimum;
    ::ad::physics::ParametricValue valueFully_visibleElementLongitudinal_rangeMaximum(0.);
    valueFully_visibleElementLongitudinal_range.maximum = valueFully_visibleElementLongitudinal_rangeMaximum;
    valueFully_visibleElementLongitudinal_range.maximum = valueFully_visibleElementLongitudinal_range.minimum;
    valueFully_visibleElementLongitudinal_range.minimum = valueFully_visibleElementLongitudinal_range.maximum;
    valueFully_visibleElement.longitudinal_range = valueFully_visibleElementLongitudinal_range;
    ::ad::physics::ParametricRange valueFully_visibleElementLateral_range;
    ::ad::physics::ParametricValue valueFully_visibleElementLateral_rangeMinimum(0.);
    valueFully_visibleElementLateral_range.minimum = valueFully_visibleElementLateral_rangeMinimum;
    ::ad::physics::ParametricValue valueFully_visibleElementLateral_rangeMaximum(0.);
    valueFully_visibleElementLateral_range.maximum = valueFully_visibleElementLateral_rangeMaximum;
    valueFully_visibleElementLateral_range.maximum = valueFully_visibleElementLateral_range.minimum;
    valueFully_visibleElementLateral_range.minimum = valueFully_visibleElementLateral_range.maximum;
    valueFully_visibleElement.lateral_range = valueFully_visibleElementLateral_range;
    valueFully_visible.resize(1, valueFully_visibleElement);
    value.fully_visible = valueFully_visible;
    ::ad::map::point::BoundingSphere valueReference_position;
    ::ad::map::point::ECEFPoint valueReference_positionCenter;
    ::ad::map::point::ECEFCoordinate valueReference_positionCenterX(-6400000);
    valueReference_positionCenter.x = valueReference_positionCenterX;
    ::ad::map::point::ECEFCoordinate valueReference_positionCenterY(-6400000);
    valueReference_positionCenter.y = valueReference_positionCenterY;
    ::ad::map::point::ECEFCoordinate valueReference_positionCenterZ(-6400000);
    valueReference_positionCenter.z = valueReference_positionCenterZ;
    valueReference_position.center = valueReference_positionCenter;
    ::ad::physics::Distance valueReference_positionRadius(-1e9);
    valueReference_position.radius = valueReference_positionRadius;
    value.reference_position = valueReference_position;
    mValue = value;
  }

  ::ad::map::geometry::LaneRegions mValue;
};

TEST_F(LaneRegionsTests, copyConstruction)
{
  ::ad::map::geometry::LaneRegions value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneRegionsTests, moveConstruction)
{
  ::ad::map::geometry::LaneRegions tmpValue(mValue);
  ::ad::map::geometry::LaneRegions value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneRegionsTests, copyAssignment)
{
  ::ad::map::geometry::LaneRegions value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneRegionsTests, moveAssignment)
{
  ::ad::map::geometry::LaneRegions tmpValue(mValue);
  ::ad::map::geometry::LaneRegions value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LaneRegionsTests, comparisonOperatorEqual)
{
  ::ad::map::geometry::LaneRegions valueA = mValue;
  ::ad::map::geometry::LaneRegions valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LaneRegionsTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LaneRegionsTests, comparisonOperatorFully_occludedDiffers)
{
  ::ad::map::geometry::LaneRegions valueA = mValue;
  ::ad::map::match::LaneOccupiedRegionList fully_occluded;
  ::ad::map::match::LaneOccupiedRegion fully_occludedElement;
  ::ad::map::lane::LaneId fully_occludedElementLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  fully_occludedElement.lane_id = fully_occludedElementLane_id;
  ::ad::physics::ParametricRange fully_occludedElementLongitudinal_range;
  ::ad::physics::ParametricValue fully_occludedElementLongitudinal_rangeMinimum(1.);
  fully_occludedElementLongitudinal_range.minimum = fully_occludedElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue fully_occludedElementLongitudinal_rangeMaximum(1.);
  fully_occludedElementLongitudinal_range.maximum = fully_occludedElementLongitudinal_rangeMaximum;
  fully_occludedElementLongitudinal_range.maximum = fully_occludedElementLongitudinal_range.minimum;
  fully_occludedElementLongitudinal_range.minimum = fully_occludedElementLongitudinal_range.maximum;
  fully_occludedElement.longitudinal_range = fully_occludedElementLongitudinal_range;
  ::ad::physics::ParametricRange fully_occludedElementLateral_range;
  ::ad::physics::ParametricValue fully_occludedElementLateral_rangeMinimum(1.);
  fully_occludedElementLateral_range.minimum = fully_occludedElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue fully_occludedElementLateral_rangeMaximum(1.);
  fully_occludedElementLateral_range.maximum = fully_occludedElementLateral_rangeMaximum;
  fully_occludedElementLateral_range.maximum = fully_occludedElementLateral_range.minimum;
  fully_occludedElementLateral_range.minimum = fully_occludedElementLateral_range.maximum;
  fully_occludedElement.lateral_range = fully_occludedElementLateral_range;
  fully_occluded.resize(2, fully_occludedElement);
  valueA.fully_occluded = fully_occluded;
  ::ad::map::geometry::LaneRegions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneRegionsTests, comparisonOperatorPartly_occludedDiffers)
{
  ::ad::map::geometry::LaneRegions valueA = mValue;
  ::ad::map::match::LaneOccupiedRegionList partly_occluded;
  ::ad::map::match::LaneOccupiedRegion partly_occludedElement;
  ::ad::map::lane::LaneId partly_occludedElementLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  partly_occludedElement.lane_id = partly_occludedElementLane_id;
  ::ad::physics::ParametricRange partly_occludedElementLongitudinal_range;
  ::ad::physics::ParametricValue partly_occludedElementLongitudinal_rangeMinimum(1.);
  partly_occludedElementLongitudinal_range.minimum = partly_occludedElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue partly_occludedElementLongitudinal_rangeMaximum(1.);
  partly_occludedElementLongitudinal_range.maximum = partly_occludedElementLongitudinal_rangeMaximum;
  partly_occludedElementLongitudinal_range.maximum = partly_occludedElementLongitudinal_range.minimum;
  partly_occludedElementLongitudinal_range.minimum = partly_occludedElementLongitudinal_range.maximum;
  partly_occludedElement.longitudinal_range = partly_occludedElementLongitudinal_range;
  ::ad::physics::ParametricRange partly_occludedElementLateral_range;
  ::ad::physics::ParametricValue partly_occludedElementLateral_rangeMinimum(1.);
  partly_occludedElementLateral_range.minimum = partly_occludedElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue partly_occludedElementLateral_rangeMaximum(1.);
  partly_occludedElementLateral_range.maximum = partly_occludedElementLateral_rangeMaximum;
  partly_occludedElementLateral_range.maximum = partly_occludedElementLateral_range.minimum;
  partly_occludedElementLateral_range.minimum = partly_occludedElementLateral_range.maximum;
  partly_occludedElement.lateral_range = partly_occludedElementLateral_range;
  partly_occluded.resize(2, partly_occludedElement);
  valueA.partly_occluded = partly_occluded;
  ::ad::map::geometry::LaneRegions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneRegionsTests, comparisonOperatorFully_visibleDiffers)
{
  ::ad::map::geometry::LaneRegions valueA = mValue;
  ::ad::map::match::LaneOccupiedRegionList fully_visible;
  ::ad::map::match::LaneOccupiedRegion fully_visibleElement;
  ::ad::map::lane::LaneId fully_visibleElementLane_id(std::numeric_limits<::ad::map::lane::LaneId>::max());
  fully_visibleElement.lane_id = fully_visibleElementLane_id;
  ::ad::physics::ParametricRange fully_visibleElementLongitudinal_range;
  ::ad::physics::ParametricValue fully_visibleElementLongitudinal_rangeMinimum(1.);
  fully_visibleElementLongitudinal_range.minimum = fully_visibleElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue fully_visibleElementLongitudinal_rangeMaximum(1.);
  fully_visibleElementLongitudinal_range.maximum = fully_visibleElementLongitudinal_rangeMaximum;
  fully_visibleElementLongitudinal_range.maximum = fully_visibleElementLongitudinal_range.minimum;
  fully_visibleElementLongitudinal_range.minimum = fully_visibleElementLongitudinal_range.maximum;
  fully_visibleElement.longitudinal_range = fully_visibleElementLongitudinal_range;
  ::ad::physics::ParametricRange fully_visibleElementLateral_range;
  ::ad::physics::ParametricValue fully_visibleElementLateral_rangeMinimum(1.);
  fully_visibleElementLateral_range.minimum = fully_visibleElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue fully_visibleElementLateral_rangeMaximum(1.);
  fully_visibleElementLateral_range.maximum = fully_visibleElementLateral_rangeMaximum;
  fully_visibleElementLateral_range.maximum = fully_visibleElementLateral_range.minimum;
  fully_visibleElementLateral_range.minimum = fully_visibleElementLateral_range.maximum;
  fully_visibleElement.lateral_range = fully_visibleElementLateral_range;
  fully_visible.resize(2, fully_visibleElement);
  valueA.fully_visible = fully_visible;
  ::ad::map::geometry::LaneRegions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LaneRegionsTests, comparisonOperatorReference_positionDiffers)
{
  ::ad::map::geometry::LaneRegions valueA = mValue;
  ::ad::map::point::BoundingSphere reference_position;
  ::ad::map::point::ECEFPoint reference_positionCenter;
  ::ad::map::point::ECEFCoordinate reference_positionCenterX(6400000);
  reference_positionCenter.x = reference_positionCenterX;
  ::ad::map::point::ECEFCoordinate reference_positionCenterY(6400000);
  reference_positionCenter.y = reference_positionCenterY;
  ::ad::map::point::ECEFCoordinate reference_positionCenterZ(6400000);
  reference_positionCenter.z = reference_positionCenterZ;
  reference_position.center = reference_positionCenter;
  ::ad::physics::Distance reference_positionRadius(1e9);
  reference_position.radius = reference_positionRadius;
  valueA.reference_position = reference_position;
  ::ad::map::geometry::LaneRegions valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
