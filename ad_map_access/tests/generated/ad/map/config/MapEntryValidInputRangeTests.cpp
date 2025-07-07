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

#include "ad/map/config/MapEntryValidInputRange.hpp"

TEST(MapEntryValidInputRangeTests, testValidInputRange)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_overlap_marginTooSmall)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value below input range minimum
  ::ad::physics::Distance invalidInitializedMember(-1e9 * 1.1);
  value.open_drive_overlap_margin = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_overlap_marginTooBig)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value above input range maximum
  ::ad::physics::Distance invalidInitializedMember(1e9 * 1.1);
  value.open_drive_overlap_margin = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeopen_drive_overlap_marginDefault)
{
  ::ad::map::config::MapEntry value;
  ::ad::physics::Distance valueDefault;
  value.open_drive_overlap_margin = valueDefault;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_default_intersection_typeTooSmall)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value below input range minimum
  ::ad::map::intersection::IntersectionType invalidInitializedMember(
    static_cast<::ad::map::intersection::IntersectionType>(-1));
  value.open_drive_default_intersection_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_default_intersection_typeTooBig)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value above input range maximum
  ::ad::map::intersection::IntersectionType invalidInitializedMember(
    static_cast<::ad::map::intersection::IntersectionType>(-1));
  value.open_drive_default_intersection_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_default_traffic_light_typeTooSmall)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value below input range minimum
  ::ad::map::landmark::TrafficLightType invalidInitializedMember(
    static_cast<::ad::map::landmark::TrafficLightType>(-1));
  value.open_drive_default_traffic_light_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapEntryValidInputRangeTests, testValidInputRangeOpen_drive_default_traffic_light_typeTooBig)
{
  ::ad::map::config::MapEntry value;
  std::string valueFilename{"min"};
  value.filename = valueFilename;
  ::ad::physics::Distance valueOpen_drive_overlap_margin(-1e9);
  value.open_drive_overlap_margin = valueOpen_drive_overlap_margin;
  ::ad::map::intersection::IntersectionType valueOpen_drive_default_intersection_type(
    ::ad::map::intersection::IntersectionType::Unknown);
  value.open_drive_default_intersection_type = valueOpen_drive_default_intersection_type;
  ::ad::map::landmark::TrafficLightType valueOpen_drive_default_traffic_light_type(
    ::ad::map::landmark::TrafficLightType::INVALID);
  value.open_drive_default_traffic_light_type = valueOpen_drive_default_traffic_light_type;

  // override member with data type value above input range maximum
  ::ad::map::landmark::TrafficLightType invalidInitializedMember(
    static_cast<::ad::map::landmark::TrafficLightType>(-1));
  value.open_drive_default_traffic_light_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
