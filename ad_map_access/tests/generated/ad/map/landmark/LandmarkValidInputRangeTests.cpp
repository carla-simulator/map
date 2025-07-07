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

#include "ad/map/landmark/LandmarkValidInputRange.hpp"

TEST(LandmarkValidInputRangeTests, testValidInputRange)
{
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
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTypeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::landmark::LandmarkType invalidInitializedMember(static_cast<::ad::map::landmark::LandmarkType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTypeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::landmark::LandmarkType invalidInitializedMember(static_cast<::ad::map::landmark::LandmarkType>(-1));
  value.type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangePositionTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(-6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangePositionTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.position = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeOrientationTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(-6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.orientation = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeOrientationTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::ECEFPoint invalidInitializedMember;
  ::ad::map::point::ECEFCoordinate invalidInitializedMemberX(6400000 * 1.1);
  invalidInitializedMember.x = invalidInitializedMemberX;
  value.orientation = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeBounding_boxTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(-1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.bounding_box = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeBounding_boxTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::point::Geometry invalidInitializedMember;
  ::ad::physics::Distance invalidInitializedMemberLength(1e9 * 1.1);
  invalidInitializedMember.length = invalidInitializedMemberLength;
  value.bounding_box = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTraffic_light_typeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::landmark::TrafficLightType invalidInitializedMember(
    static_cast<::ad::map::landmark::TrafficLightType>(-1));
  value.traffic_light_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTraffic_light_typeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::landmark::TrafficLightType invalidInitializedMember(
    static_cast<::ad::map::landmark::TrafficLightType>(-1));
  value.traffic_light_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTraffic_sign_typeTooSmall)
{
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

  // override member with data type value below input range minimum
  ::ad::map::landmark::TrafficSignType invalidInitializedMember(static_cast<::ad::map::landmark::TrafficSignType>(-1));
  value.traffic_sign_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(LandmarkValidInputRangeTests, testValidInputRangeTraffic_sign_typeTooBig)
{
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

  // override member with data type value above input range maximum
  ::ad::map::landmark::TrafficSignType invalidInitializedMember(static_cast<::ad::map::landmark::TrafficSignType>(-1));
  value.traffic_sign_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
