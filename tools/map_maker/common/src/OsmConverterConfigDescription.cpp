// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/OsmConverterConfigDescription.hpp"
#include "ad/map/maker/common/RightOfWayLexicalCast.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

namespace po = ::boost::program_options;

OsmConverterConfigDescription::OsmConverterConfigDescription()
  : ::boost::program_options::options_description("Reading OSM data")
{
  // Used to check that if we got a valid traffic regulation
  auto notifier = []() {
    return [](RightOfWay value) {
      if ((value != RightOfWay::AllWayStop) && (value != RightOfWay::PriorityToRight) && (value != RightOfWay::Stop))
        throw po::validation_error(
          po::validation_error::invalid_option_value, "Invalid default right of way", rowToString(value));
    };
  };

  // clang-format off
  add_options()
      ("acceptable-highway-types,t",
       po::value<std::string>(&config.acceptableHighwayTypes)->default_value(config.acceptableHighwayTypes),
       "Comma-separated list of highway types to be accepted, e.g. residential,tertiary,service")
      ("ignore-lane-info", po::bool_switch(&config.ignoreLaneInfoFromMap),
       "Do not extract lane information from map (number of lanes, widths of lanes)")
      ("adjust-lateral-offset", po::bool_switch(&config.adjustLateralOffsetOfRoad),
       "Adjust lateral offset of roads")
      ("default-priority", po::value<RightOfWay>(&config.defaultPriority)->notifier(notifier()),
       "Default priority rule on intersections if none is specified in the map, one of stop, priority_to_right, all_way_stop. Default: all_way_stop")
      ("default-lane-width", po::value<std::string>(&config.laneWidthsDefaults)->default_value(config.laneWidthsDefaults),
       "Comma-separated list of default width of lanes used to generate lanes, e.g. 3,residential:2.5 "
       "uses 2.5 m for residential ways and 3 for all other ways");
  // clang-format on
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
