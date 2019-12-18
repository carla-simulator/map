// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

namespace ad {
namespace map {
namespace maker {
namespace common {

struct InternalToRoad5LaneGeneratorConfig
{
  double widthOfLeftShoulder{-1.}; //! in [m] shoulder is generated if >0
  double widthOfLeftBorder{1.};    //! in [m]
  double widthOfLeftRoadSide{2.5}; //! in [m]

  double widthOfRightShoulder{-1.}; //! in [m] shoulder is generated if >0
  double widthOfRightBorder{1.};    //! in [m]
  double widthOfRightRoadSide{2.5}; //! in [m]
  bool generateShiftedRoads{true};
};

struct InternalToRoad5JunctionConverterConfig
{
  double minDist2JunctionCenter{8.};
  double maxDist2JunctionCenter{12.};
};

struct InternalToRoad5Config
{
  InternalToRoad5JunctionConverterConfig junctionGeneratorConfig;
  InternalToRoad5LaneGeneratorConfig laneGeneratorConfig;
  bool generateFromOsmData{false};
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
