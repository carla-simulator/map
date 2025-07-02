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

#include "ad/map/match/MapMatchedPositionConfidenceListValidInputRange.hpp"

TEST(MapMatchedPositionConfidenceListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::match::MapMatchedPositionConfidenceList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMatchedPositionConfidenceListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::match::MapMatchedPositionConfidenceList value;
  ::ad::map::match::MapMatchedPosition element;
  ::ad::map::match::LanePoint elementLane_point;
  ::ad::map::point::ParaPoint elementLane_pointPara_point;
  ::ad::map::lane::LaneId elementLane_pointPara_pointLane_id(1);
  elementLane_pointPara_point.lane_id = elementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue elementLane_pointPara_pointParametric_offset(0.);
  elementLane_pointPara_point.parametric_offset = elementLane_pointPara_pointParametric_offset;
  elementLane_point.para_point = elementLane_pointPara_point;
  ::ad::physics::RatioValue elementLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  elementLane_point.lateral_t = elementLane_pointLateral_t;
  ::ad::physics::Distance elementLane_pointLane_length(-1e9);
  elementLane_point.lane_length = elementLane_pointLane_length;
  ::ad::physics::Distance elementLane_pointLane_width(-1e9);
  elementLane_point.lane_width = elementLane_pointLane_width;
  element.lane_point = elementLane_point;
  ::ad::map::match::MapMatchedPositionType elementType(::ad::map::match::MapMatchedPositionType::INVALID);
  element.type = elementType;
  ::ad::map::point::ECEFPoint elementMatched_point;
  ::ad::map::point::ECEFCoordinate elementMatched_pointX(-6400000);
  elementMatched_point.x = elementMatched_pointX;
  ::ad::map::point::ECEFCoordinate elementMatched_pointY(-6400000);
  elementMatched_point.y = elementMatched_pointY;
  ::ad::map::point::ECEFCoordinate elementMatched_pointZ(-6400000);
  elementMatched_point.z = elementMatched_pointZ;
  element.matched_point = elementMatched_point;
  ::ad::physics::Probability elementProbability(0.);
  element.probability = elementProbability;
  ::ad::map::point::ECEFPoint elementQuery_point;
  ::ad::map::point::ECEFCoordinate elementQuery_pointX(-6400000);
  elementQuery_point.x = elementQuery_pointX;
  ::ad::map::point::ECEFCoordinate elementQuery_pointY(-6400000);
  elementQuery_point.y = elementQuery_pointY;
  ::ad::map::point::ECEFCoordinate elementQuery_pointZ(-6400000);
  elementQuery_point.z = elementQuery_pointZ;
  element.query_point = elementQuery_point;
  ::ad::physics::Distance elementMatched_point_distance(-1e9);
  element.matched_point_distance = elementMatched_point_distance;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMatchedPositionConfidenceListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::match::MapMatchedPositionConfidenceList value;
  ::ad::map::match::MapMatchedPosition element;
  ::ad::map::match::LanePoint elementLane_point;
  ::ad::map::point::ParaPoint elementLane_pointPara_point;
  ::ad::physics::ParametricValue elementLane_pointPara_pointParametric_offset(
    0. - ::ad::physics::ParametricValue::cPrecisionValue);
  elementLane_pointPara_point.parametric_offset = elementLane_pointPara_pointParametric_offset;
  elementLane_point.para_point = elementLane_pointPara_point;
  element.lane_point = elementLane_point;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
