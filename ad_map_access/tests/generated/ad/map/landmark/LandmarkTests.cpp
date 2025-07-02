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
#include "ad/map/landmark/Landmark.hpp"

class LandmarkTests : public testing::Test
{
protected:
  virtual void SetUp() override
  {
    // valid initialization
    ::ad::map::landmark::Landmark value;
    std::string valueName{"min"};
    value.name = valueName;
    ::ad::map::landmark::LandmarkId valueId(std::numeric_limits<::ad::map::landmark::LandmarkId>::lowest());
    value.id = valueId;
    ::ad::map::landmark::LandmarkType valueType(::ad::map::landmark::LandmarkType::INVALID);
    value.type = valueType;
    ::ad::map::point::ECEFPoint valuePosition;
    ::ad::map::point::ECEFCoordinate valuePositionX(-6400000);
    valuePosition.x = valuePositionX;
    ::ad::map::point::ECEFCoordinate valuePositionY(-6400000);
    valuePosition.y = valuePositionY;
    ::ad::map::point::ECEFCoordinate valuePositionZ(-6400000);
    valuePosition.z = valuePositionZ;
    value.position = valuePosition;
    ::ad::map::point::ECEFPoint valueOrientation;
    ::ad::map::point::ECEFCoordinate valueOrientationX(-6400000);
    valueOrientation.x = valueOrientationX;
    ::ad::map::point::ECEFCoordinate valueOrientationY(-6400000);
    valueOrientation.y = valueOrientationY;
    ::ad::map::point::ECEFCoordinate valueOrientationZ(-6400000);
    valueOrientation.z = valueOrientationZ;
    value.orientation = valueOrientation;
    ::ad::map::point::Geometry valueBounding_box;
    bool valueBounding_boxIs_valid{true};
    valueBounding_box.is_valid = valueBounding_boxIs_valid;
    bool valueBounding_boxIs_closed{true};
    valueBounding_box.is_closed = valueBounding_boxIs_closed;
    ::ad::map::point::ECEFPointList valueBounding_boxEcef_points;
    ::ad::map::point::ECEFPoint valueBounding_boxEcef_pointsElement;
    ::ad::map::point::ECEFCoordinate valueBounding_boxEcef_pointsElementX(-6400000);
    valueBounding_boxEcef_pointsElement.x = valueBounding_boxEcef_pointsElementX;
    ::ad::map::point::ECEFCoordinate valueBounding_boxEcef_pointsElementY(-6400000);
    valueBounding_boxEcef_pointsElement.y = valueBounding_boxEcef_pointsElementY;
    ::ad::map::point::ECEFCoordinate valueBounding_boxEcef_pointsElementZ(-6400000);
    valueBounding_boxEcef_pointsElement.z = valueBounding_boxEcef_pointsElementZ;
    valueBounding_boxEcef_points.resize(1, valueBounding_boxEcef_pointsElement);
    valueBounding_box.ecef_points = valueBounding_boxEcef_points;
    ::ad::physics::Distance valueBounding_boxLength(-1e9);
    valueBounding_box.length = valueBounding_boxLength;
    ::ad::map::point::ENUPointCache valueBounding_boxPrivate_enu_points_cache;
    ::ad::map::point::ENUPointList valueBounding_boxPrivate_enu_points_cacheEnu_points;
    ::ad::map::point::ENUPoint valueBounding_boxPrivate_enu_points_cacheEnu_pointsElement;
    ::ad::map::point::ENUCoordinate valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementX(-1e8);
    valueBounding_boxPrivate_enu_points_cacheEnu_pointsElement.x
      = valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementX;
    ::ad::map::point::ENUCoordinate valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementY(-1e8);
    valueBounding_boxPrivate_enu_points_cacheEnu_pointsElement.y
      = valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementY;
    ::ad::map::point::ENUCoordinate valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementZ(-1e8);
    valueBounding_boxPrivate_enu_points_cacheEnu_pointsElement.z
      = valueBounding_boxPrivate_enu_points_cacheEnu_pointsElementZ;
    valueBounding_boxPrivate_enu_points_cacheEnu_points.resize(
      1, valueBounding_boxPrivate_enu_points_cacheEnu_pointsElement);
    valueBounding_boxPrivate_enu_points_cache.enu_points = valueBounding_boxPrivate_enu_points_cacheEnu_points;
    uint64_t valueBounding_boxPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::min()};
    valueBounding_boxPrivate_enu_points_cache.enu_version = valueBounding_boxPrivate_enu_points_cacheEnu_version;
    valueBounding_box.private_enu_points_cache = valueBounding_boxPrivate_enu_points_cache;
    value.bounding_box = valueBounding_box;
    std::string valueSupplementary_text{"min"};
    value.supplementary_text = valueSupplementary_text;
    ::ad::map::landmark::TrafficLightType valueTraffic_light_type(::ad::map::landmark::TrafficLightType::INVALID);
    value.traffic_light_type = valueTraffic_light_type;
    ::ad::map::landmark::TrafficSignType valueTraffic_sign_type(::ad::map::landmark::TrafficSignType::INVALID);
    value.traffic_sign_type = valueTraffic_sign_type;
    mValue = value;
  }

  ::ad::map::landmark::Landmark mValue;
};

TEST_F(LandmarkTests, copyConstruction)
{
  ::ad::map::landmark::Landmark value(mValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LandmarkTests, moveConstruction)
{
  ::ad::map::landmark::Landmark tmpValue(mValue);
  ::ad::map::landmark::Landmark value(std::move(tmpValue));
  EXPECT_EQ(mValue, value);
}

TEST_F(LandmarkTests, copyAssignment)
{
  ::ad::map::landmark::Landmark value;
  value = mValue;
  EXPECT_EQ(mValue, value);
}

TEST_F(LandmarkTests, moveAssignment)
{
  ::ad::map::landmark::Landmark tmpValue(mValue);
  ::ad::map::landmark::Landmark value;
  value = std::move(tmpValue);
  EXPECT_EQ(mValue, value);
}

TEST_F(LandmarkTests, comparisonOperatorEqual)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_TRUE(valueA == valueB);
  EXPECT_FALSE(valueA != valueB);
}

TEST_F(LandmarkTests, stringConversionTest)
{
  std::stringstream stream;
  stream << mValue;
  std::string ostreamStr = stream.str();
  std::string toStr = std::to_string(mValue);
  ASSERT_EQ(ostreamStr, toStr);
}

TEST_F(LandmarkTests, comparisonOperatorNameDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  std::string name{"max"};
  valueA.name = name;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorIdDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::landmark::LandmarkId id(std::numeric_limits<::ad::map::landmark::LandmarkId>::max());
  valueA.id = id;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorTypeDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::landmark::LandmarkType type(::ad::map::landmark::LandmarkType::OTHER);
  valueA.type = type;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorPositionDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::point::ECEFPoint position;
  ::ad::map::point::ECEFCoordinate positionX(6400000);
  position.x = positionX;
  ::ad::map::point::ECEFCoordinate positionY(6400000);
  position.y = positionY;
  ::ad::map::point::ECEFCoordinate positionZ(6400000);
  position.z = positionZ;
  valueA.position = position;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorOrientationDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::point::ECEFPoint orientation;
  ::ad::map::point::ECEFCoordinate orientationX(6400000);
  orientation.x = orientationX;
  ::ad::map::point::ECEFCoordinate orientationY(6400000);
  orientation.y = orientationY;
  ::ad::map::point::ECEFCoordinate orientationZ(6400000);
  orientation.z = orientationZ;
  valueA.orientation = orientation;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorBounding_boxDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::point::Geometry bounding_box;
  bool bounding_boxIs_valid{false};
  bounding_box.is_valid = bounding_boxIs_valid;
  bool bounding_boxIs_closed{false};
  bounding_box.is_closed = bounding_boxIs_closed;
  ::ad::map::point::ECEFPointList bounding_boxEcef_points;
  ::ad::map::point::ECEFPoint bounding_boxEcef_pointsElement;
  ::ad::map::point::ECEFCoordinate bounding_boxEcef_pointsElementX(6400000);
  bounding_boxEcef_pointsElement.x = bounding_boxEcef_pointsElementX;
  ::ad::map::point::ECEFCoordinate bounding_boxEcef_pointsElementY(6400000);
  bounding_boxEcef_pointsElement.y = bounding_boxEcef_pointsElementY;
  ::ad::map::point::ECEFCoordinate bounding_boxEcef_pointsElementZ(6400000);
  bounding_boxEcef_pointsElement.z = bounding_boxEcef_pointsElementZ;
  bounding_boxEcef_points.resize(2, bounding_boxEcef_pointsElement);
  bounding_box.ecef_points = bounding_boxEcef_points;
  ::ad::physics::Distance bounding_boxLength(1e9);
  bounding_box.length = bounding_boxLength;
  ::ad::map::point::ENUPointCache bounding_boxPrivate_enu_points_cache;
  ::ad::map::point::ENUPointList bounding_boxPrivate_enu_points_cacheEnu_points;
  ::ad::map::point::ENUPoint bounding_boxPrivate_enu_points_cacheEnu_pointsElement;
  ::ad::map::point::ENUCoordinate bounding_boxPrivate_enu_points_cacheEnu_pointsElementX(1e8);
  bounding_boxPrivate_enu_points_cacheEnu_pointsElement.x = bounding_boxPrivate_enu_points_cacheEnu_pointsElementX;
  ::ad::map::point::ENUCoordinate bounding_boxPrivate_enu_points_cacheEnu_pointsElementY(1e8);
  bounding_boxPrivate_enu_points_cacheEnu_pointsElement.y = bounding_boxPrivate_enu_points_cacheEnu_pointsElementY;
  ::ad::map::point::ENUCoordinate bounding_boxPrivate_enu_points_cacheEnu_pointsElementZ(1e8);
  bounding_boxPrivate_enu_points_cacheEnu_pointsElement.z = bounding_boxPrivate_enu_points_cacheEnu_pointsElementZ;
  bounding_boxPrivate_enu_points_cacheEnu_points.resize(2, bounding_boxPrivate_enu_points_cacheEnu_pointsElement);
  bounding_boxPrivate_enu_points_cache.enu_points = bounding_boxPrivate_enu_points_cacheEnu_points;
  uint64_t bounding_boxPrivate_enu_points_cacheEnu_version{std::numeric_limits<uint64_t>::max()};
  bounding_boxPrivate_enu_points_cache.enu_version = bounding_boxPrivate_enu_points_cacheEnu_version;
  bounding_box.private_enu_points_cache = bounding_boxPrivate_enu_points_cache;
  valueA.bounding_box = bounding_box;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorSupplementary_textDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  std::string supplementary_text{"max"};
  valueA.supplementary_text = supplementary_text;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorTraffic_light_typeDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::landmark::TrafficLightType traffic_light_type(
    ::ad::map::landmark::TrafficLightType::BIKE_PEDESTRIAN_RED_YELLOW_GREEN);
  valueA.traffic_light_type = traffic_light_type;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

TEST_F(LandmarkTests, comparisonOperatorTraffic_sign_typeDiffers)
{
  ::ad::map::landmark::Landmark valueA = mValue;
  ::ad::map::landmark::TrafficSignType traffic_sign_type(::ad::map::landmark::TrafficSignType::UNKNOWN);
  valueA.traffic_sign_type = traffic_sign_type;
  ::ad::map::landmark::Landmark valueB = mValue;

  EXPECT_FALSE(valueA == valueB);
  EXPECT_TRUE(valueA != valueB);
}

#if defined(__clang__) && (__clang_major__ >= 7)
#pragma GCC diagnostic pop
#endif
