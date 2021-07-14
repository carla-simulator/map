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

class LaneParser
{
private:
  void ParseLane(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneInfo> &out_lane);

  void ParseLaneSpeed(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneSpeed> &out_lane_speed);

  void ParseLaneLink(const pugi::xml_node &xmlNode, std::unique_ptr<opendrive::LaneLink> &out_lane_link);

  void ParseLaneOffset(const pugi::xml_node &xmlNode, opendrive::LaneOffsetSet &out_lane_offset);

  void ParseLaneWidth(const pugi::xml_node &xmlNode, opendrive::LaneWidthSet &out_lane_width);

  void ParseLaneRoadMark(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneRoadMark> &out_lane_mark);

  void ParseLaneRoadMarkLine(const pugi::xml_node &xmlNode,
                             std::vector<opendrive::LaneRoadMarkLine> &out_lane_mark_line);

  void ParseLaneRoadMarkType(const pugi::xml_node &xmlNode,
                             std::vector<opendrive::LaneRoadMarkType> &out_lane_mark_type);

  void ParseLaneMaterial(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneMaterial> &out_lane_material);

  void ParseLaneBorder(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneBorder> &out_lane_border);

  void ParseLaneVisibility(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneVisibility> &out_lane_visibility);

  void ParseLaneAccess(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneAccess> &out_lane_access);

  void ParseLaneHeight(const pugi::xml_node &xmlNode, opendrive::LaneHeightSet &out_lane_height);

  void ParseLaneRule(const pugi::xml_node &xmlNode, std::vector<opendrive::LaneRule> &out_lane_rule);

public:
  static void Parse(const pugi::xml_node &xmlNode, Lanes &out_lanes);
};

} // namespace parser
} // namespace opendrive
