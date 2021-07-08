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

#include "opendrive/parser/ProfilesParser.h"
#include <spdlog/spdlog.h>

namespace opendrive {
namespace parser {

void ProfilesParser::ParseElevation(const pugi::xml_node &xmlNode,
                                    opendrive::ElevationProfileSet &out_elevation_profile)
{
  for (pugi::xml_node laneSection = xmlNode.child("elevation"); laneSection;
       laneSection = laneSection.next_sibling("elevation"))
  {
    opendrive::ElevationProfile elevationProfile;

    elevationProfile.start_offset = std::stod(laneSection.attribute("s").value());
    elevationProfile.a = std::stod(laneSection.attribute("a").value());
    elevationProfile.b = std::stod(laneSection.attribute("b").value());
    elevationProfile.c = std::stod(laneSection.attribute("c").value());
    elevationProfile.d = std::stod(laneSection.attribute("d").value());
    out_elevation_profile.insert(elevationProfile);
  }
}

void ProfilesParser::ParseShape(const pugi::xml_node &xmlNode,
                                opendrive::LateralProfileShapeSetMap &out_lateral_profile_shape)
{
  for (pugi::xml_node laneSection = xmlNode.child("shape"); laneSection;
       laneSection = laneSection.next_sibling("shape"))
  {
    opendrive::LateralProfileShape lateralProfileShape;

    lateralProfileShape.s_position = std::stod(laneSection.attribute("s").value());
    // the lateral profiles polynomial is in t-axis direction
    lateralProfileShape.start_offset = std::stod(laneSection.attribute("t").value());
    lateralProfileShape.a = std::stod(laneSection.attribute("a").value());
    lateralProfileShape.b = std::stod(laneSection.attribute("b").value());
    lateralProfileShape.c = std::stod(laneSection.attribute("c").value());
    lateralProfileShape.d = std::stod(laneSection.attribute("d").value());

    // the LateralPolygonShapeSet at the same s_position are collected in a map
    auto const insertResult
      = out_lateral_profile_shape.insert({lateralProfileShape.s_position, opendrive::LateralProfileShapeSet()});
    insertResult.first->second.insert(lateralProfileShape);
  }
}

void ProfilesParser::ParseSuperelevation(const pugi::xml_node &xmlNode,
                                         opendrive::LateralProfileSuperelevationSet &out_lateral_profile_superelevation)
{
  for (pugi::xml_node laneSection = xmlNode.child("superelevation"); laneSection;
       laneSection = laneSection.next_sibling("superelevation"))
  {
    opendrive::LateralProfileSuperelevation lateralProfileSuperelevation;

    lateralProfileSuperelevation.start_offset = std::stod(laneSection.attribute("s").value());
    lateralProfileSuperelevation.a = std::stod(laneSection.attribute("a").value());
    lateralProfileSuperelevation.b = std::stod(laneSection.attribute("b").value());
    lateralProfileSuperelevation.c = std::stod(laneSection.attribute("c").value());
    lateralProfileSuperelevation.d = std::stod(laneSection.attribute("d").value());
    out_lateral_profile_superelevation.insert(lateralProfileSuperelevation);
  }
}

void ProfilesParser::Parse(const pugi::xml_node &xmlNode, opendrive::RoadProfiles &out_road_profiles)
{
  ProfilesParser profilesParser;

  const pugi::xml_node elevationNode = xmlNode.child("elevationProfile");
  const pugi::xml_node lateralProfileNode = xmlNode.child("lateralProfile");

  if (elevationNode)
  {
    profilesParser.ParseElevation(elevationNode, out_road_profiles.elevation_profile);
  }

  if (lateralProfileNode)
  {
    profilesParser.ParseShape(lateralProfileNode, out_road_profiles.lateral_profile_shape);
    profilesParser.ParseSuperelevation(lateralProfileNode, out_road_profiles.lateral_profile_superelevation);
  }
}

} // namespace parser
} // namespace opendrive
