// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/landmark/Types.hpp>
#include <ad/map/maker/map_data/LandmarkType.hpp>

namespace ad {
namespace map {
namespace maker {
namespace admap_generator {

//! @return LandmarkType as traffic sign type if applicable, INVALID otherwise
landmark::TrafficSignType trafficSignToAdMap(map_data::LandmarkType landmarkType);

//! @return Landmarktype as generic landmark (leaving out traffic lights, traffic signs, and crosswalks)
landmark::LandmarkType landmarkTypeToAdMap(map_data::LandmarkType landmarkType);

} // namespace admap_generator
} // namespace maker
} // namespace map
} // namespace ad
