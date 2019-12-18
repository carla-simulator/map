// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

namespace ad {
namespace map {
namespace maker {
namespace map_data {

enum class RoadType
{
  Motorway,
  Primary,
  Secondary,
  Tertiary,
  Trunk,
  Residential,
  Link,
  Service,
  Unclassified,
  Intersection,
  Invalid
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
