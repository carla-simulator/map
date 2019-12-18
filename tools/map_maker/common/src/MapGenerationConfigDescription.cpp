// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/MapGenerationConfigDescription.hpp"
#include "ad/map/maker/common/MapGenerationLevelLexicalCast.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

MapGenerationConfigDescription::MapGenerationConfigDescription()
  : ::boost::program_options::options_description("MapGeneration specific options")
{
  namespace po = ::boost::program_options;

  // Used to check that if we got a valid level of detail for map generation
  auto notifier = []() {
    return [](MapGenerationLevel value) {
      if (value == MapGenerationLevel::Undefined)
        throw po::validation_error(po::validation_error::invalid_option_value,
                                   "Invalid level for map generation",
                                   mapGenerationLevelToString(value));
    };
  };

  // clang-format off
  add_options()
      ("interpolation-steps",
       po::value<double>(&config.interpolationStepsBezier)->default_value(config.interpolationStepsBezier),
       "number of interpolation steps for bezier interpolation inside intersections")
      ("default-intersection-radius",
       po::value<double>(&config.defaultIntersectionRadius)->default_value(config.defaultIntersectionRadius),
       "junction area radius in [m]")
      ("interpolate-raw-roads", po::bool_switch(&config.interpolateRawRoads),
       "Interpolate original road data with cubic spline")
      ("leftHandTraffic", po::bool_switch(&config.leftHandTraffic),
       "Use left-hand traffic regulation")
      ("prioToRightAndStraight", po::bool_switch(&config.prioToRightAndStraight),
       "Use prio_to_right_and_straight traffic regulation instead of prio_to_right")
      ("generation-level", po::value<MapGenerationLevel>(&config.generationLevel)->notifier(notifier()),
       "Level of detail of resulting map, one of [raw,skeleton,full], default: full");
  // clang-format on
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
