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

class RoadLinkParser
{
private:
  void ParseLink(const pugi::xml_node &xmlNode, opendrive::RoadLinkInformation *out_link_information);

public:
  static void Parse(const pugi::xml_node &xmlNode, opendrive::RoadLink &out_road_link);
};
} // namespace parser
} // namespace opendrive
