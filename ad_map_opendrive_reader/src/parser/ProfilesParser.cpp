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

void opendrive::parser::ProfilesParser::ParseElevation(const pugi::xml_node &xmlNode,
                                                       std::vector<opendrive::ElevationProfile> &out_elevation_profile)
{
  for (pugi::xml_node laneSection = xmlNode.child("elevation"); laneSection;
       laneSection = laneSection.next_sibling("elevation"))
  {
    opendrive::ElevationProfile elevationProfile;

    elevationProfile.start_position = std::stod(laneSection.attribute("s").value());
    elevationProfile.elevation = std::stod(laneSection.attribute("a").value());
    elevationProfile.slope = std::stod(laneSection.attribute("b").value());
    elevationProfile.vertical_curvature = std::stod(laneSection.attribute("c").value());
    elevationProfile.curvature_change = std::stod(laneSection.attribute("d").value());
    out_elevation_profile.emplace_back(elevationProfile);
  }
}

void opendrive::parser::ProfilesParser::ParseLateral(const pugi::xml_node &xmlNode,
                                                     std::vector<opendrive::LateralProfile> &out_lateral_profile)
{
  for (pugi::xml_node laneSection = xmlNode.child("superelevation"); laneSection;
       laneSection = laneSection.next_sibling("superelevation"))
  {
    opendrive::LateralProfile lateralProfile;

    lateralProfile.start_position = std::stod(laneSection.attribute("s").value());
    lateralProfile.elevation = std::stod(laneSection.attribute("a").value());
    lateralProfile.slope = std::stod(laneSection.attribute("b").value());
    lateralProfile.vertical_curvature = std::stod(laneSection.attribute("c").value());
    lateralProfile.curvature_change = std::stod(laneSection.attribute("d").value());

    out_lateral_profile.emplace_back(lateralProfile);
  }
}

void opendrive::parser::ProfilesParser::Parse(const pugi::xml_node &xmlNode, opendrive::RoadProfiles &out_road_profiles)
{
  opendrive::parser::ProfilesParser profilesParser;

  const pugi::xml_node predecessorNode = xmlNode.child("elevationProfile");
  const pugi::xml_node successorNode = xmlNode.child("lateralProfile");

  if (predecessorNode)
  {
    profilesParser.ParseElevation(xmlNode.child("elevationProfile"), out_road_profiles.elevation_profile);
  }

  if (successorNode)
  {
    profilesParser.ParseLateral(xmlNode.child("lateralProfile"), out_road_profiles.lateral_profile);
  }
}
