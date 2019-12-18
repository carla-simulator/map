// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIPLNTIAL
//
// Copyright (c) 2018-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include <unordered_map>

#include <ad/map/maker/map_data/LandmarkType.hpp>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::unordered_map<std::string, map_data::LandmarkType> const &getTrafficSignsPL();

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
