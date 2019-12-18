// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/map_data/LandmarkType.hpp>
#include <ad/map/maker/map_data/MapDataElement.hpp>
#include <unordered_set>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

struct Landmark : MapDataElement
{
  MapDataId location{InvalidId};
  LandmarkType type{LandmarkType::Unknown};
  double orientation{0.};                        //!< in radians around up-axis
  bool alongRoadDirection{false};                //!< orientation of the traffic light w.r.t to road it belongs to
  double heightOverGround{0.};                   //!< height over ground in meters
  std::string supplement{};                      //!< free form text to specify the landmark, e.g.
                                                 //!< a number for the speed limit
                                                 //!< or the content of a traffic light (arrow, pedestrian, bike)
  std::unordered_set<int32_t> laneAssignments{}; //!< Set of all lanes this landmark applies to
                                                 //!  may be empty for trees, street lights, etc.
                                                 //!  can be used for traffic signs, traffic lights etc.
  uint64_t index{0u};                            //!< identifier which is used when writing rd5 and adm
                                                 //!  defaults to the id of the landmark except for traffic lights
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
