// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include <unordered_map>

#include <ad/map/maker/map_data/LandmarkType.hpp>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::unordered_map<std::string, map_data::LandmarkType> const &getTrafficSignsPL();

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
