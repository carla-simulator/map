/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
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
#include "ad/map/restriction/RoadUserTypeList.hpp"

TEST(RoadUserTypeListTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::restriction::RoadUserTypeList value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}
