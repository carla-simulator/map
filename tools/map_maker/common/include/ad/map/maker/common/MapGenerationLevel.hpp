// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

namespace ad {
namespace map {
namespace maker {
namespace common {

enum class MapGenerationLevel
{
  Undefined, //!< Invalid level
  Raw,       //!< do not convert any data
  Skeleton,  //!< create roads inside intersection but do not generate any lanes
  Full       //!< generate complete map
};

MapGenerationLevel mapGenerationLevelFromString(std::string const &source);
std::string mapGenerationLevelToString(MapGenerationLevel const level);

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
