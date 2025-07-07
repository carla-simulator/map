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

#include "ad/map/landmark/ENULandmarkListValidInputRange.hpp"

TEST(ENULandmarkListValidInputRangeTests, testValidInputRangeValidInputRangeMin)
{
  ::ad::map::landmark::ENULandmarkList value;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENULandmarkListValidInputRangeTests, testValidInputRangeElementValid)
{
  ::ad::map::landmark::ENULandmarkList value;
  ::ad::map::landmark::ENULandmark element;
  ::ad::map::landmark::LandmarkId elementId(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
  element.id = elementId;
  ::ad::map::landmark::LandmarkType elementType(::ad::map::landmark::LandmarkType::INVALID);
  element.type = elementType;
  ::ad::map::point::ENUPoint elementPosition;
  ::ad::map::point::ENUCoordinate elementPositionX(-1e8);
  elementPosition.x = elementPositionX;
  ::ad::map::point::ENUCoordinate elementPositionY(-1e8);
  elementPosition.y = elementPositionY;
  ::ad::map::point::ENUCoordinate elementPositionZ(-1e8);
  elementPosition.z = elementPositionZ;
  element.position = elementPosition;
  ::ad::map::point::ENUHeading elementHeading(-3.141592655);
  element.heading = elementHeading;
  ::ad::map::landmark::TrafficLightType elementTraffic_light_type(::ad::map::landmark::TrafficLightType::INVALID);
  element.traffic_light_type = elementTraffic_light_type;
  value.push_back(element);
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(ENULandmarkListValidInputRangeTests, testValidInputRangeElementInvalid)
{
  ::ad::map::landmark::ENULandmarkList value;
  ::ad::map::landmark::ENULandmark element;
  ::ad::map::landmark::LandmarkType elementType(static_cast<::ad::map::landmark::LandmarkType>(-1));
  element.type = elementType;
  value.push_back(element);
  ASSERT_FALSE(withinValidInputRange(value));
}
