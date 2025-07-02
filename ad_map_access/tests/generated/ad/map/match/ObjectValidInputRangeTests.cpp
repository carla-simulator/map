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

#include "ad/map/match/ObjectValidInputRange.hpp"

TEST(ObjectValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::Object value;
  ::ad::map::match::ENUObjectPosition valueEnu_position;
  ::ad::map::point::ENUPoint valueEnu_positionCenter_point;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointX(-1e8);
  valueEnu_positionCenter_point.x = valueEnu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointY(-1e8);
  valueEnu_positionCenter_point.y = valueEnu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointZ(-1e8);
  valueEnu_positionCenter_point.z = valueEnu_positionCenter_pointZ;
  valueEnu_position.center_point = valueEnu_positionCenter_point;
  ::ad::map::point::ENUHeading valueEnu_positionHeading(-3.141592655);
  valueEnu_position.heading = valueEnu_positionHeading;
  ::ad::map::point::GeoPoint valueEnu_positionEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_positionEnu_reference_pointLongitude(-180);
  valueEnu_positionEnu_reference_point.longitude = valueEnu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_positionEnu_reference_pointLatitude(-90);
  valueEnu_positionEnu_reference_point.latitude = valueEnu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_positionEnu_reference_pointAltitude(-11000);
  valueEnu_positionEnu_reference_point.altitude = valueEnu_positionEnu_reference_pointAltitude;
  valueEnu_position.enu_reference_point = valueEnu_positionEnu_reference_point;
  ::ad::physics::Dimension3D valueEnu_positionDimension;
  ::ad::physics::Distance valueEnu_positionDimensionLength(-1e9);
  valueEnu_positionDimension.length = valueEnu_positionDimensionLength;
  ::ad::physics::Distance valueEnu_positionDimensionWidth(-1e9);
  valueEnu_positionDimension.width = valueEnu_positionDimensionWidth;
  ::ad::physics::Distance valueEnu_positionDimensionHeight(-1e9);
  valueEnu_positionDimension.height = valueEnu_positionDimensionHeight;
  valueEnu_position.dimension = valueEnu_positionDimension;
  value.enu_position = valueEnu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox valueMap_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueMap_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id(1);
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  valueMap_matched_bounding_boxLane_occupied_regions.resize(1,
                                                            valueMap_matched_bounding_boxLane_occupied_regionsElement);
  valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueMap_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.type
    = valueMap_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueMap_matched_bounding_boxReference_point_positionsElementElementProbability(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.probability
    = valueMap_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.query_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  valueMap_matched_bounding_boxReference_point_positionsElement.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElementElement);
  valueMap_matched_bounding_boxReference_point_positions.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElement);
  valueMap_matched_bounding_box.reference_point_positions = valueMap_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance valueMap_matched_bounding_boxSampling_distance(-1e9);
  valueMap_matched_bounding_box.sampling_distance = valueMap_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance valueMap_matched_bounding_boxMatch_radius(-1e9);
  valueMap_matched_bounding_box.match_radius = valueMap_matched_bounding_boxMatch_radius;
  value.map_matched_bounding_box = valueMap_matched_bounding_box;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ObjectValidInputRangeTests, testValidInputRangeEnu_positionTooSmall)
{
  ::ad::map::match::Object value;
  ::ad::map::match::ENUObjectPosition valueEnu_position;
  ::ad::map::point::ENUPoint valueEnu_positionCenter_point;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointX(-1e8);
  valueEnu_positionCenter_point.x = valueEnu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointY(-1e8);
  valueEnu_positionCenter_point.y = valueEnu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointZ(-1e8);
  valueEnu_positionCenter_point.z = valueEnu_positionCenter_pointZ;
  valueEnu_position.center_point = valueEnu_positionCenter_point;
  ::ad::map::point::ENUHeading valueEnu_positionHeading(-3.141592655);
  valueEnu_position.heading = valueEnu_positionHeading;
  ::ad::map::point::GeoPoint valueEnu_positionEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_positionEnu_reference_pointLongitude(-180);
  valueEnu_positionEnu_reference_point.longitude = valueEnu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_positionEnu_reference_pointLatitude(-90);
  valueEnu_positionEnu_reference_point.latitude = valueEnu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_positionEnu_reference_pointAltitude(-11000);
  valueEnu_positionEnu_reference_point.altitude = valueEnu_positionEnu_reference_pointAltitude;
  valueEnu_position.enu_reference_point = valueEnu_positionEnu_reference_point;
  ::ad::physics::Dimension3D valueEnu_positionDimension;
  ::ad::physics::Distance valueEnu_positionDimensionLength(-1e9);
  valueEnu_positionDimension.length = valueEnu_positionDimensionLength;
  ::ad::physics::Distance valueEnu_positionDimensionWidth(-1e9);
  valueEnu_positionDimension.width = valueEnu_positionDimensionWidth;
  ::ad::physics::Distance valueEnu_positionDimensionHeight(-1e9);
  valueEnu_positionDimension.height = valueEnu_positionDimensionHeight;
  valueEnu_position.dimension = valueEnu_positionDimension;
  value.enu_position = valueEnu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox valueMap_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueMap_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id(1);
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  valueMap_matched_bounding_boxLane_occupied_regions.resize(1,
                                                            valueMap_matched_bounding_boxLane_occupied_regionsElement);
  valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueMap_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.type
    = valueMap_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueMap_matched_bounding_boxReference_point_positionsElementElementProbability(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.probability
    = valueMap_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.query_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  valueMap_matched_bounding_boxReference_point_positionsElement.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElementElement);
  valueMap_matched_bounding_boxReference_point_positions.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElement);
  valueMap_matched_bounding_box.reference_point_positions = valueMap_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance valueMap_matched_bounding_boxSampling_distance(-1e9);
  valueMap_matched_bounding_box.sampling_distance = valueMap_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance valueMap_matched_bounding_boxMatch_radius(-1e9);
  valueMap_matched_bounding_box.match_radius = valueMap_matched_bounding_boxMatch_radius;
  value.map_matched_bounding_box = valueMap_matched_bounding_box;

  // override member with data type value below input range minimum
  ::ad::map::match::ENUObjectPosition invalidInitializedMember;
  ::ad::map::point::ENUPoint invalidInitializedMemberCenter_point;
  ::ad::map::point::ENUCoordinate invalidInitializedMemberCenter_pointX(-1e8 * 1.1);
  invalidInitializedMemberCenter_point.x = invalidInitializedMemberCenter_pointX;
  invalidInitializedMember.center_point = invalidInitializedMemberCenter_point;
  value.enu_position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ObjectValidInputRangeTests, testValidInputRangeEnu_positionTooBig)
{
  ::ad::map::match::Object value;
  ::ad::map::match::ENUObjectPosition valueEnu_position;
  ::ad::map::point::ENUPoint valueEnu_positionCenter_point;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointX(-1e8);
  valueEnu_positionCenter_point.x = valueEnu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointY(-1e8);
  valueEnu_positionCenter_point.y = valueEnu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointZ(-1e8);
  valueEnu_positionCenter_point.z = valueEnu_positionCenter_pointZ;
  valueEnu_position.center_point = valueEnu_positionCenter_point;
  ::ad::map::point::ENUHeading valueEnu_positionHeading(-3.141592655);
  valueEnu_position.heading = valueEnu_positionHeading;
  ::ad::map::point::GeoPoint valueEnu_positionEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_positionEnu_reference_pointLongitude(-180);
  valueEnu_positionEnu_reference_point.longitude = valueEnu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_positionEnu_reference_pointLatitude(-90);
  valueEnu_positionEnu_reference_point.latitude = valueEnu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_positionEnu_reference_pointAltitude(-11000);
  valueEnu_positionEnu_reference_point.altitude = valueEnu_positionEnu_reference_pointAltitude;
  valueEnu_position.enu_reference_point = valueEnu_positionEnu_reference_point;
  ::ad::physics::Dimension3D valueEnu_positionDimension;
  ::ad::physics::Distance valueEnu_positionDimensionLength(-1e9);
  valueEnu_positionDimension.length = valueEnu_positionDimensionLength;
  ::ad::physics::Distance valueEnu_positionDimensionWidth(-1e9);
  valueEnu_positionDimension.width = valueEnu_positionDimensionWidth;
  ::ad::physics::Distance valueEnu_positionDimensionHeight(-1e9);
  valueEnu_positionDimension.height = valueEnu_positionDimensionHeight;
  valueEnu_position.dimension = valueEnu_positionDimension;
  value.enu_position = valueEnu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox valueMap_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueMap_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id(1);
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  valueMap_matched_bounding_boxLane_occupied_regions.resize(1,
                                                            valueMap_matched_bounding_boxLane_occupied_regionsElement);
  valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueMap_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.type
    = valueMap_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueMap_matched_bounding_boxReference_point_positionsElementElementProbability(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.probability
    = valueMap_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.query_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  valueMap_matched_bounding_boxReference_point_positionsElement.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElementElement);
  valueMap_matched_bounding_boxReference_point_positions.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElement);
  valueMap_matched_bounding_box.reference_point_positions = valueMap_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance valueMap_matched_bounding_boxSampling_distance(-1e9);
  valueMap_matched_bounding_box.sampling_distance = valueMap_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance valueMap_matched_bounding_boxMatch_radius(-1e9);
  valueMap_matched_bounding_box.match_radius = valueMap_matched_bounding_boxMatch_radius;
  value.map_matched_bounding_box = valueMap_matched_bounding_box;

  // override member with data type value above input range maximum
  ::ad::map::match::ENUObjectPosition invalidInitializedMember;
  ::ad::map::point::ENUPoint invalidInitializedMemberCenter_point;
  ::ad::map::point::ENUCoordinate invalidInitializedMemberCenter_pointX(1e8 * 1.1);
  invalidInitializedMemberCenter_point.x = invalidInitializedMemberCenter_pointX;
  invalidInitializedMember.center_point = invalidInitializedMemberCenter_point;
  value.enu_position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ObjectValidInputRangeTests, testValidInputRangeMap_matched_bounding_boxTooSmall)
{
  ::ad::map::match::Object value;
  ::ad::map::match::ENUObjectPosition valueEnu_position;
  ::ad::map::point::ENUPoint valueEnu_positionCenter_point;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointX(-1e8);
  valueEnu_positionCenter_point.x = valueEnu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointY(-1e8);
  valueEnu_positionCenter_point.y = valueEnu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointZ(-1e8);
  valueEnu_positionCenter_point.z = valueEnu_positionCenter_pointZ;
  valueEnu_position.center_point = valueEnu_positionCenter_point;
  ::ad::map::point::ENUHeading valueEnu_positionHeading(-3.141592655);
  valueEnu_position.heading = valueEnu_positionHeading;
  ::ad::map::point::GeoPoint valueEnu_positionEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_positionEnu_reference_pointLongitude(-180);
  valueEnu_positionEnu_reference_point.longitude = valueEnu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_positionEnu_reference_pointLatitude(-90);
  valueEnu_positionEnu_reference_point.latitude = valueEnu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_positionEnu_reference_pointAltitude(-11000);
  valueEnu_positionEnu_reference_point.altitude = valueEnu_positionEnu_reference_pointAltitude;
  valueEnu_position.enu_reference_point = valueEnu_positionEnu_reference_point;
  ::ad::physics::Dimension3D valueEnu_positionDimension;
  ::ad::physics::Distance valueEnu_positionDimensionLength(-1e9);
  valueEnu_positionDimension.length = valueEnu_positionDimensionLength;
  ::ad::physics::Distance valueEnu_positionDimensionWidth(-1e9);
  valueEnu_positionDimension.width = valueEnu_positionDimensionWidth;
  ::ad::physics::Distance valueEnu_positionDimensionHeight(-1e9);
  valueEnu_positionDimension.height = valueEnu_positionDimensionHeight;
  valueEnu_position.dimension = valueEnu_positionDimension;
  value.enu_position = valueEnu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox valueMap_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueMap_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id(1);
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  valueMap_matched_bounding_boxLane_occupied_regions.resize(1,
                                                            valueMap_matched_bounding_boxLane_occupied_regionsElement);
  valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueMap_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.type
    = valueMap_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueMap_matched_bounding_boxReference_point_positionsElementElementProbability(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.probability
    = valueMap_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.query_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  valueMap_matched_bounding_boxReference_point_positionsElement.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElementElement);
  valueMap_matched_bounding_boxReference_point_positions.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElement);
  valueMap_matched_bounding_box.reference_point_positions = valueMap_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance valueMap_matched_bounding_boxSampling_distance(-1e9);
  valueMap_matched_bounding_box.sampling_distance = valueMap_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance valueMap_matched_bounding_boxMatch_radius(-1e9);
  valueMap_matched_bounding_box.match_radius = valueMap_matched_bounding_boxMatch_radius;
  value.map_matched_bounding_box = valueMap_matched_bounding_box;

  // override member with data type value below input range minimum
  ::ad::map::match::MapMatchedObjectBoundingBox invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberSampling_distance(-1e9 * 1.1);
  invalidInitializedMember.sampling_distance = invalidInitializedMemberSampling_distance;
  value.map_matched_bounding_box = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(ObjectValidInputRangeTests, testValidInputRangeMap_matched_bounding_boxTooBig)
{
  ::ad::map::match::Object value;
  ::ad::map::match::ENUObjectPosition valueEnu_position;
  ::ad::map::point::ENUPoint valueEnu_positionCenter_point;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointX(-1e8);
  valueEnu_positionCenter_point.x = valueEnu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointY(-1e8);
  valueEnu_positionCenter_point.y = valueEnu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate valueEnu_positionCenter_pointZ(-1e8);
  valueEnu_positionCenter_point.z = valueEnu_positionCenter_pointZ;
  valueEnu_position.center_point = valueEnu_positionCenter_point;
  ::ad::map::point::ENUHeading valueEnu_positionHeading(-3.141592655);
  valueEnu_position.heading = valueEnu_positionHeading;
  ::ad::map::point::GeoPoint valueEnu_positionEnu_reference_point;
  ::ad::map::point::Longitude valueEnu_positionEnu_reference_pointLongitude(-180);
  valueEnu_positionEnu_reference_point.longitude = valueEnu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude valueEnu_positionEnu_reference_pointLatitude(-90);
  valueEnu_positionEnu_reference_point.latitude = valueEnu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude valueEnu_positionEnu_reference_pointAltitude(-11000);
  valueEnu_positionEnu_reference_point.altitude = valueEnu_positionEnu_reference_pointAltitude;
  valueEnu_position.enu_reference_point = valueEnu_positionEnu_reference_point;
  ::ad::physics::Dimension3D valueEnu_positionDimension;
  ::ad::physics::Distance valueEnu_positionDimensionLength(-1e9);
  valueEnu_positionDimension.length = valueEnu_positionDimensionLength;
  ::ad::physics::Distance valueEnu_positionDimensionWidth(-1e9);
  valueEnu_positionDimension.width = valueEnu_positionDimensionWidth;
  ::ad::physics::Distance valueEnu_positionDimensionHeight(-1e9);
  valueEnu_positionDimension.height = valueEnu_positionDimensionHeight;
  valueEnu_position.dimension = valueEnu_positionDimension;
  value.enu_position = valueEnu_position;
  ::ad::map::match::MapMatchedObjectBoundingBox valueMap_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion valueMap_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id(1);
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(0.);
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  valueMap_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = valueMap_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  valueMap_matched_bounding_boxLane_occupied_regions.resize(1,
                                                            valueMap_matched_bounding_boxLane_occupied_regionsElement);
  valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(1);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType valueMap_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::INVALID);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.type
    = valueMap_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability valueMap_matched_bounding_boxReference_point_positionsElementElementProbability(0.);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.probability
    = valueMap_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(
    -6400000);
  valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  valueMap_matched_bounding_boxReference_point_positionsElementElement.query_point
    = valueMap_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(
    -1e9);
  valueMap_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = valueMap_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  valueMap_matched_bounding_boxReference_point_positionsElement.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElementElement);
  valueMap_matched_bounding_boxReference_point_positions.resize(
    1, valueMap_matched_bounding_boxReference_point_positionsElement);
  valueMap_matched_bounding_box.reference_point_positions = valueMap_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance valueMap_matched_bounding_boxSampling_distance(-1e9);
  valueMap_matched_bounding_box.sampling_distance = valueMap_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance valueMap_matched_bounding_boxMatch_radius(-1e9);
  valueMap_matched_bounding_box.match_radius = valueMap_matched_bounding_boxMatch_radius;
  value.map_matched_bounding_box = valueMap_matched_bounding_box;

  // override member with data type value above input range maximum
  ::ad::map::match::MapMatchedObjectBoundingBox invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberSampling_distance(1e9 * 1.1);
  invalidInitializedMember.sampling_distance = invalidInitializedMemberSampling_distance;
  value.map_matched_bounding_box = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
