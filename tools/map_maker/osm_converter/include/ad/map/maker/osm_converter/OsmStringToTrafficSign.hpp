// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

#include <ad/map/maker/map_data/Landmark.hpp>

namespace ad {
namespace map {
namespace maker {
namespace common {
struct LogChannel;
} // namespace common

namespace osm_converter {

map_data::LandmarkType landmarkTypeFromString(std::string const &sign, common::LogChannel &logger);

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
