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

class TrafficSignalsParser
{
private:
  static opendrive::Validity AddValidity(const pugi::xml_node &parent_node, const std::string &node_name);

public:
  static void Parse(const pugi::xml_node &xmlNode,
                    std::vector<opendrive::TrafficSignalInformation> &out_traffic_signals,
                    std::vector<opendrive::TrafficSignalReference> &out_traffic_signal_references);
};

} // namespace parser
} // namespace opendrive
