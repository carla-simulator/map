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
#include "ad/map/route/LaneSegmentList.hpp"

TEST(LaneSegmentListTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::route::LaneSegmentList value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0u);
}
