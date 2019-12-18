/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2019 Intel Corporation
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
#include "ad/map/point/GeoEdge.hpp"

TEST(GeoEdgeTests, ostreamOperatorTest)
{
  std::stringstream stream;
  ::ad::map::point::GeoEdge value;
  stream << value;
  ASSERT_GT(stream.str().size(), 0);
}
