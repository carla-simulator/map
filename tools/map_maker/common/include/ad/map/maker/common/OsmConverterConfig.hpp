// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include "ad/map/maker/common/RightOfWay.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Configuration for reading OSM data
 */
struct OsmConverterConfig
{
  std::string acceptableHighwayTypes{"residential,service,secondary,tertiary,road,unclassified"};
  std::string laneWidthsDefaults{"3,motorway:3.5"};
  RightOfWay defaultPriority{RightOfWay::PriorityToRight};
  bool ignoreLaneInfoFromMap{false};
  bool adjustLateralOffsetOfRoad{false};
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
