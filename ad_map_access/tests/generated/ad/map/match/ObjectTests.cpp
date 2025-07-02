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
#include "ad/map/match/Object.hpp"

class ObjectTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
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
    ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(
      0.);
    valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
      = valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
    ::ad::physics::ParametricValue valueMap_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(
      0.);
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
    valueMap_matched_bounding_boxLane_occupied_regions.resize(
      1, valueMap_matched_bounding_boxLane_occupied_regionsElement);
    valueMap_matched_bounding_box.lane_occupied_regions = valueMap_matched_bounding_boxLane_occupied_regions;
    ::ad::map::match::MapMatchedObjectReferencePositionList valueMap_matched_bounding_boxReference_point_positions;
    ::ad::map::match::MapMatchedPositionConfidenceList valueMap_matched_bounding_boxReference_point_positionsElement;
    ::ad::map::match::MapMatchedPosition valueMap_matched_bounding_boxReference_point_positionsElementElement;
    ::ad::map::match::LanePoint valueMap_matched_bounding_boxReference_point_positionsElementElementLane_point;
    ::ad::map::point::ParaPoint
      valueMap_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
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
    mValue = value;
  }

  ::ad::map::match::Object mValue;
};

TEST_F(ObjectTests, copyConstruction)
{
  ::ad::map::match::Object value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ObjectTests, moveConstruction)
{
  ::ad::map::match::Object tmpValue(mValue);
  ::ad::map::match::Object value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(ObjectTests, copyAssignment)
{
  ::ad::map::match::Object value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(ObjectTests, moveAssignment)
{
  ::ad::map::match::Object tmpValue(mValue);
  ::ad::map::match::Object value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(ObjectTests, comparisonOperatorEqual)
{
  ::ad::map::match::Object valueA = mValue;
  ::ad::map::match::Object valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(ObjectTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(ObjectTests, comparisonOperatorEnu_positionDiffers)
{
  ::ad::map::match::Object valueA = mValue;
  ::ad::map::match::ENUObjectPosition enu_position;
  ::ad::map::point::ENUPoint enu_positionCenter_point;
  ::ad::map::point::ENUCoordinate enu_positionCenter_pointX(1e8);
  enu_positionCenter_point.x = enu_positionCenter_pointX;
  ::ad::map::point::ENUCoordinate enu_positionCenter_pointY(1e8);
  enu_positionCenter_point.y = enu_positionCenter_pointY;
  ::ad::map::point::ENUCoordinate enu_positionCenter_pointZ(1e8);
  enu_positionCenter_point.z = enu_positionCenter_pointZ;
  enu_position.center_point = enu_positionCenter_point;
  ::ad::map::point::ENUHeading enu_positionHeading(3.141592655);
  enu_position.heading = enu_positionHeading;
  ::ad::map::point::GeoPoint enu_positionEnu_reference_point;
  ::ad::map::point::Longitude enu_positionEnu_reference_pointLongitude(180);
  enu_positionEnu_reference_point.longitude = enu_positionEnu_reference_pointLongitude;
  ::ad::map::point::Latitude enu_positionEnu_reference_pointLatitude(90);
  enu_positionEnu_reference_point.latitude = enu_positionEnu_reference_pointLatitude;
  ::ad::map::point::Altitude enu_positionEnu_reference_pointAltitude(9000);
  enu_positionEnu_reference_point.altitude = enu_positionEnu_reference_pointAltitude;
  enu_position.enu_reference_point = enu_positionEnu_reference_point;
  ::ad::physics::Dimension3D enu_positionDimension;
  ::ad::physics::Distance enu_positionDimensionLength(1e9);
  enu_positionDimension.length = enu_positionDimensionLength;
  ::ad::physics::Distance enu_positionDimensionWidth(1e9);
  enu_positionDimension.width = enu_positionDimensionWidth;
  ::ad::physics::Distance enu_positionDimensionHeight(1e9);
  enu_positionDimension.height = enu_positionDimensionHeight;
  enu_position.dimension = enu_positionDimension;
  valueA.enu_position = enu_position;
  ::ad::map::match::Object valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(ObjectTests, comparisonOperatorMap_matched_bounding_boxDiffers)
{
  ::ad::map::match::Object valueA = mValue;
  ::ad::map::match::MapMatchedObjectBoundingBox map_matched_bounding_box;
  ::ad::map::match::LaneOccupiedRegionList map_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::LaneOccupiedRegion map_matched_bounding_boxLane_occupied_regionsElement;
  ::ad::map::lane::LaneId map_matched_bounding_boxLane_occupied_regionsElementLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  map_matched_bounding_boxLane_occupied_regionsElement.lane_id
    = map_matched_bounding_boxLane_occupied_regionsElementLane_id;
  ::ad::physics::ParametricRange map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricValue map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum(1.);
  map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMinimum;
  ::ad::physics::ParametricValue map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum(1.);
  map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_rangeMaximum;
  map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum
    = map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum;
  map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.minimum
    = map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range.maximum;
  map_matched_bounding_boxLane_occupied_regionsElement.longitudinal_range
    = map_matched_bounding_boxLane_occupied_regionsElementLongitudinal_range;
  ::ad::physics::ParametricRange map_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  ::ad::physics::ParametricValue map_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum(1.);
  map_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = map_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMinimum;
  ::ad::physics::ParametricValue map_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum(1.);
  map_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = map_matched_bounding_boxLane_occupied_regionsElementLateral_rangeMaximum;
  map_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum
    = map_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum;
  map_matched_bounding_boxLane_occupied_regionsElementLateral_range.minimum
    = map_matched_bounding_boxLane_occupied_regionsElementLateral_range.maximum;
  map_matched_bounding_boxLane_occupied_regionsElement.lateral_range
    = map_matched_bounding_boxLane_occupied_regionsElementLateral_range;
  map_matched_bounding_boxLane_occupied_regions.resize(2, map_matched_bounding_boxLane_occupied_regionsElement);
  map_matched_bounding_box.lane_occupied_regions = map_matched_bounding_boxLane_occupied_regions;
  ::ad::map::match::MapMatchedObjectReferencePositionList map_matched_bounding_boxReference_point_positions;
  ::ad::map::match::MapMatchedPositionConfidenceList map_matched_bounding_boxReference_point_positionsElement;
  ::ad::map::match::MapMatchedPosition map_matched_bounding_boxReference_point_positionsElementElement;
  ::ad::map::match::LanePoint map_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::point::ParaPoint map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::map::lane::LaneId map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id(
    std::numeric_limits<::ad::map::lane::LaneId>::max());
  map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.lane_id
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue
    map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset(1.);
  map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point.parametric_offset
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_pointParametric_offset;
  map_matched_bounding_boxReference_point_positionsElementElementLane_point.para_point
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointPara_point;
  ::ad::physics::RatioValue map_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t(
    std::numeric_limits<::ad::physics::RatioValue>::max());
  map_matched_bounding_boxReference_point_positionsElementElementLane_point.lateral_t
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointLateral_t;
  ::ad::physics::Distance map_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length(1e9);
  map_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_length
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_length;
  ::ad::physics::Distance map_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width(1e9);
  map_matched_bounding_boxReference_point_positionsElementElementLane_point.lane_width
    = map_matched_bounding_boxReference_point_positionsElementElementLane_pointLane_width;
  map_matched_bounding_boxReference_point_positionsElementElement.lane_point
    = map_matched_bounding_boxReference_point_positionsElementElementLane_point;
  ::ad::map::match::MapMatchedPositionType map_matched_bounding_boxReference_point_positionsElementElementType(
    ::ad::map::match::MapMatchedPositionType::LANE_RIGHT);
  map_matched_bounding_boxReference_point_positionsElementElement.type
    = map_matched_bounding_boxReference_point_positionsElementElementType;
  ::ad::map::point::ECEFPoint map_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementMatched_pointX(
    6400000);
  map_matched_bounding_boxReference_point_positionsElementElementMatched_point.x
    = map_matched_bounding_boxReference_point_positionsElementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementMatched_pointY(
    6400000);
  map_matched_bounding_boxReference_point_positionsElementElementMatched_point.y
    = map_matched_bounding_boxReference_point_positionsElementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ(
    6400000);
  map_matched_bounding_boxReference_point_positionsElementElementMatched_point.z
    = map_matched_bounding_boxReference_point_positionsElementElementMatched_pointZ;
  map_matched_bounding_boxReference_point_positionsElementElement.matched_point
    = map_matched_bounding_boxReference_point_positionsElementElementMatched_point;
  ::ad::physics::Probability map_matched_bounding_boxReference_point_positionsElementElementProbability(1.);
  map_matched_bounding_boxReference_point_positionsElementElement.probability
    = map_matched_bounding_boxReference_point_positionsElementElementProbability;
  ::ad::map::point::ECEFPoint map_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementQuery_pointX(6400000);
  map_matched_bounding_boxReference_point_positionsElementElementQuery_point.x
    = map_matched_bounding_boxReference_point_positionsElementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementQuery_pointY(6400000);
  map_matched_bounding_boxReference_point_positionsElementElementQuery_point.y
    = map_matched_bounding_boxReference_point_positionsElementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate map_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ(6400000);
  map_matched_bounding_boxReference_point_positionsElementElementQuery_point.z
    = map_matched_bounding_boxReference_point_positionsElementElementQuery_pointZ;
  map_matched_bounding_boxReference_point_positionsElementElement.query_point
    = map_matched_bounding_boxReference_point_positionsElementElementQuery_point;
  ::ad::physics::Distance map_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance(1e9);
  map_matched_bounding_boxReference_point_positionsElementElement.matched_point_distance
    = map_matched_bounding_boxReference_point_positionsElementElementMatched_point_distance;
  map_matched_bounding_boxReference_point_positionsElement.resize(
    2, map_matched_bounding_boxReference_point_positionsElementElement);
  map_matched_bounding_boxReference_point_positions.resize(2, map_matched_bounding_boxReference_point_positionsElement);
  map_matched_bounding_box.reference_point_positions = map_matched_bounding_boxReference_point_positions;
  ::ad::physics::Distance map_matched_bounding_boxSampling_distance(1e9);
  map_matched_bounding_box.sampling_distance = map_matched_bounding_boxSampling_distance;
  ::ad::physics::Distance map_matched_bounding_boxMatch_radius(1e9);
  map_matched_bounding_box.match_radius = map_matched_bounding_boxMatch_radius;
  valueA.map_matched_bounding_box = map_matched_bounding_box;
  ::ad::map::match::Object valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
