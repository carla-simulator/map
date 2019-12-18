// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/maker/common/RightOfWay.hpp>
#include "ad/map/maker/map_data/MapDataElement.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

/*
 * @brief Representation of one arm of an intersection
 *
 * Is derived from MapDataElement to inherit the member mId although it is never added to the MapDataStore
 */
struct IntersectionArm : MapDataElement
{
  MapDataId connectionPoint{InvalidId}; //! Id of contact point between outside road and intersection
  MapDataId connectedRoad{InvalidId};   //! Id of road that leads out/into the intersection at this point
  bool isEntry{true};                   //!< true if _connectedRoad_ leads into the intersection at _connectionPoint_
  common::RightOfWay rightOfWay{common::RightOfWay::Undefined}; //! traffic rule at this arm
  double orientation{};                                         //! in radians
  double distanceToCenter{0.0};
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
