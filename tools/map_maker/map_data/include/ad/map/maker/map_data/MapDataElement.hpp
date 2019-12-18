// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/maker/map_data/MapDataId.hpp"

namespace ad {
namespace map {
namespace maker {
namespace map_data {

/**
 * @brief The base for types that can be stored in a MapDataStore
 */
struct MapDataElement
{
  MapDataId mId{InvalidId};
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
