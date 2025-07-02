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

#include "ad/map/match/MapMatchedPositionValidInputRange.hpp"

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRange)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeLane_pointTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::map::match::LanePoint invalidInitializedMember;
  ::ad::map::point::ParaPoint invalidInitializedMemberPara_point;
  ::ad::physics::ParametricValue invalidInitializedMemberPara_pointParametric_offset(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  invalidInitializedMemberPara_point.parametric_offset = invalidInitializedMemberPara_pointParametric_offset;
  invalidInitializedMember.para_point = invalidInitializedMemberPara_point;
  value.lane_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeLane_pointTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::map::match::LanePoint invalidInitializedMember;
  ::ad::map::point::ParaPoint invalidInitializedMemberPara_point;
  ::ad::physics::ParametricValue invalidInitializedMemberPara_pointParametric_offset(1. * 1.1);
  invalidInitializedMemberPara_point.parametric_offset = invalidInitializedMemberPara_pointParametric_offset;
  invalidInitializedMember.para_point = invalidInitializedMemberPara_point;
  value.lane_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeTypeTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::map::match::MapMatchedPositionType invalidInitializedMember(
    static_cast<::ad::map::match::MapMatchedPositionType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeTypeTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::map::match::MapMatchedPositionType invalidInitializedMember(
    static_cast<::ad::map::match::MapMatchedPositionType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeMatched_pointTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(-6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.matched_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeMatched_pointTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.matched_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeProbabilityTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::physics::Probability invalidInitializedMember(0. - ::ad::physics::Probability::cPrecisionValue);
  value.probability = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeProbabilityTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::physics::Probability invalidInitializedMember(1. * 1.1);
  value.probability = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeprobabilityDefault)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::physics::Probability valueDefault;
  value.probability = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeQuery_pointTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(-6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.query_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeQuery_pointTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.query_point = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeMatched_point_distanceTooSmall)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.matched_point_distance = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangeMatched_point_distanceTooBig)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::map::match::LanePoint valueLane_point;
  ::ad::map::point::ParaPoint valueLane_pointPara_point;
  ::ad::map::lane::LaneId valueLane_pointPara_pointLane_id(1);
  valueLane_pointPara_point.lane_id = valueLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue valueLane_pointPara_pointParametric_offset(0.);
  valueLane_pointPara_point.parametric_offset = valueLane_pointPara_pointParametric_offset;
  valueLane_point.para_point = valueLane_pointPara_point;
  ::ad::physics::RatioValue valueLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  valueLane_point.lateral_t = valueLane_pointLateral_t;
  ::ad::physics::Distance valueLane_pointLane_length(-1e9);
  valueLane_point.lane_length = valueLane_pointLane_length;
  ::ad::physics::Distance valueLane_pointLane_width(-1e9);
  valueLane_point.lane_width = valueLane_pointLane_width;
  value.lane_point = valueLane_point;
  ::ad::map::match::MapMatchedPositionType valueType(::ad::map::match::MapMatchedPositionType::INVALID);
  value.type = valueType;
  ::ad::map::point::ECEFPoint valueMatched_point;
  ::ad::map::point::ECEFCoordinate valueMatched_pointX(-6400000);
  valueMatched_point.x = valueMatched_pointX;
  ::ad::map::point::ECEFCoordinate valueMatched_pointY(-6400000);
  valueMatched_point.y = valueMatched_pointY;
  ::ad::map::point::ECEFCoordinate valueMatched_pointZ(-6400000);
  valueMatched_point.z = valueMatched_pointZ;
  value.matched_point = valueMatched_point;
  ::ad::physics::Probability valueProbability(0.);
  value.probability = valueProbability;
  ::ad::map::point::ECEFPoint valueQuery_point;
  ::ad::map::point::ECEFCoordinate valueQuery_pointX(-6400000);
  valueQuery_point.x = valueQuery_pointX;
  ::ad::map::point::ECEFCoordinate valueQuery_pointY(-6400000);
  valueQuery_point.y = valueQuery_pointY;
  ::ad::map::point::ECEFCoordinate valueQuery_pointZ(-6400000);
  valueQuery_point.z = valueQuery_pointZ;
  value.query_point = valueQuery_point;
  ::ad::physics::Distance valueMatched_point_distance(-1e9);
  value.matched_point_distance = valueMatched_point_distance;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.matched_point_distance = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMatchedPositionValidInputRangeTests, testValidInputRangematched_point_distanceDefault)
{
  ::ad::map::match::MapMatchedPosition value;
  ::ad::physics::Distance valueDefault;
  value.matched_point_distance = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}
