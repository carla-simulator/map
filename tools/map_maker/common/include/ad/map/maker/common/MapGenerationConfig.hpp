// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/maker/common/MapGenerationLevel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

struct MapGenerationConfig
{
  double interpolationStepsBezier{10.}; //!< number of steps for bezier interpolation
  double defaultIntersectionRadius{8.}; //!< default distance between arm and center of intersection
  bool interpolateRawRoads{false};      //!< interpolate raw data with cubic splines?
  bool leftHandTraffic{false};          //!< use left-hand traffic regulation
  bool prioToRightAndStraight{false};   //!< use prio_to_right_and_straight traffic regulation instead of prio_to_right
  MapGenerationLevel generationLevel{MapGenerationLevel::Full}; //!< level of generation
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
