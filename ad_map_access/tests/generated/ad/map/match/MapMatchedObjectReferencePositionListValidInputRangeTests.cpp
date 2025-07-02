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

#include "ad/map/match/MapMatchedObjectReferencePositionListValidInputRange.hpp"

TEST(MapMatchedObjectReferencePositionListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::match::MapMatchedObjectReferencePositionList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMatchedObjectReferencePositionListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::match::MapMatchedObjectReferencePositionList value;
  ::ad::map::match::MapMatchedPositionConfidenceList element;
  ::ad::map::match::MapMatchedPosition elementElement;
  ::ad::map::match::LanePoint elementElementLane_point;
  ::ad::map::point::ParaPoint elementElementLane_pointPara_point;
  ::ad::map::lane::LaneId elementElementLane_pointPara_pointLane_id(1);
  elementElementLane_pointPara_point.lane_id = elementElementLane_pointPara_pointLane_id;
  ::ad::physics::ParametricValue elementElementLane_pointPara_pointParametric_offset(0.);
  elementElementLane_pointPara_point.parametric_offset = elementElementLane_pointPara_pointParametric_offset;
  elementElementLane_point.para_point = elementElementLane_pointPara_point;
  ::ad::physics::RatioValue elementElementLane_pointLateral_t(std::numeric_limits<::ad::physics::RatioValue>::lowest());
  elementElementLane_point.lateral_t = elementElementLane_pointLateral_t;
  ::ad::physics::Distance elementElementLane_pointLane_length(-1e9);
  elementElementLane_point.lane_length = elementElementLane_pointLane_length;
  ::ad::physics::Distance elementElementLane_pointLane_width(-1e9);
  elementElementLane_point.lane_width = elementElementLane_pointLane_width;
  elementElement.lane_point = elementElementLane_point;
  ::ad::map::match::MapMatchedPositionType elementElementType(::ad::map::match::MapMatchedPositionType::INVALID);
  elementElement.type = elementElementType;
  ::ad::map::point::ECEFPoint elementElementMatched_point;
  ::ad::map::point::ECEFCoordinate elementElementMatched_pointX(-6400000);
  elementElementMatched_point.x = elementElementMatched_pointX;
  ::ad::map::point::ECEFCoordinate elementElementMatched_pointY(-6400000);
  elementElementMatched_point.y = elementElementMatched_pointY;
  ::ad::map::point::ECEFCoordinate elementElementMatched_pointZ(-6400000);
  elementElementMatched_point.z = elementElementMatched_pointZ;
  elementElement.matched_point = elementElementMatched_point;
  ::ad::physics::Probability elementElementProbability(0.);
  elementElement.probability = elementElementProbability;
  ::ad::map::point::ECEFPoint elementElementQuery_point;
  ::ad::map::point::ECEFCoordinate elementElementQuery_pointX(-6400000);
  elementElementQuery_point.x = elementElementQuery_pointX;
  ::ad::map::point::ECEFCoordinate elementElementQuery_pointY(-6400000);
  elementElementQuery_point.y = elementElementQuery_pointY;
  ::ad::map::point::ECEFCoordinate elementElementQuery_pointZ(-6400000);
  elementElementQuery_point.z = elementElementQuery_pointZ;
  elementElement.query_point = elementElementQuery_point;
  ::ad::physics::Distance elementElementMatched_point_distance(-1e9);
  elementElement.matched_point_distance = elementElementMatched_point_distance;
  element.resize(1, elementElement);
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}
