// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>
#include "ad/map/maker/map_data/MapDataElement.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

/**
 * @brief an ordered list of points which can be seen as a polyline
 */
struct PolyLine : MapDataElement
{
  std::vector<MapDataId> mNodes;
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
