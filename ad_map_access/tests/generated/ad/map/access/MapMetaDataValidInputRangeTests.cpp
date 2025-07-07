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

#include "ad/map/access/MapMetaDataValidInputRange.hpp"

TEST(MapMetaDataValidInputRangeTests, testValidInputRange)
{
  ::ad::map::access::MapMetaData value;
  ::ad::map::access::TrafficType valueTraffic_type(::ad::map::access::TrafficType::INVALID);
  value.traffic_type = valueTraffic_type;
  ASSERT_TRUE(withinValidInputRange(value));
}

TEST(MapMetaDataValidInputRangeTests, testValidInputRangeTraffic_typeTooSmall)
{
  ::ad::map::access::MapMetaData value;
  ::ad::map::access::TrafficType valueTraffic_type(::ad::map::access::TrafficType::INVALID);
  value.traffic_type = valueTraffic_type;

  // override member with data type value below input range minimum
  ::ad::map::access::TrafficType invalidInitializedMember(static_cast<::ad::map::access::TrafficType>(-1));
  value.traffic_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}

TEST(MapMetaDataValidInputRangeTests, testValidInputRangeTraffic_typeTooBig)
{
  ::ad::map::access::MapMetaData value;
  ::ad::map::access::TrafficType valueTraffic_type(::ad::map::access::TrafficType::INVALID);
  value.traffic_type = valueTraffic_type;

  // override member with data type value above input range maximum
  ::ad::map::access::TrafficType invalidInitializedMember(static_cast<::ad::map::access::TrafficType>(-1));
  value.traffic_type = invalidInitializedMember;
  ASSERT_FALSE(withinValidInputRange(value));
}
