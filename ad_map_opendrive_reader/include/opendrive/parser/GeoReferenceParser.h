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

#include <string>
#include <pugixml.hpp>

#include "opendrive/types.hpp"

namespace opendrive {
namespace parser {

class GeoReferenceParser
{
public:
  static ::opendrive::geom::GeoLocation Parse(const std::string &geo_reference_string, const pugi::xml_node &geo_offset = pugi::xml_node());
};

} // namespace parser
} // namespace opendrive
