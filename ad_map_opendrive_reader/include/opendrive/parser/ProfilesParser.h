/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#pragma once

#include "opendrive/types.hpp"

#include <pugixml.hpp>

namespace opendrive {
namespace parser {

class ProfilesParser
{
private:
  void ParseElevation(const pugi::xml_node &xmlNode, opendrive::ElevationProfileSet &out_elevation_profile);

  void ParseShape(const pugi::xml_node &xmlNode, opendrive::LateralProfileShapeSetMap &out_lateral_profile_shape);
  void ParseSuperelevation(const pugi::xml_node &xmlNode,
                           LateralProfileSuperelevationSet &out_lateral_profile_superelevation);

public:
  static void Parse(const pugi::xml_node &xmlNode, opendrive::RoadProfiles &out_road_profiles);
};
} // namespace parser
} // namespace opendrive
