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

#include <gtest/gtest.h>

#include <limits>

#include "ad/map/geometry/LaneRegionsValidInputRange.hpp"

TEST(LaneRegionsValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LaneRegionsValidInputRangeTests, testValidInputRangeReference_positionTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(-6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.reference_position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LaneRegionsValidInputRangeTests, testValidInputRangeReference_positionTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::BoundingSphere invalidInitializedMember;
  ::ad::map::point::ECEFPoint invalidInitializedMemberCenter;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberCenterX(6400000 * 1.1);
  invalidInitializedMemberCenter.x = invalidInitializedMemberCenterX;
  invalidInitializedMember.center = invalidInitializedMemberCenter;
  value.reference_position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
