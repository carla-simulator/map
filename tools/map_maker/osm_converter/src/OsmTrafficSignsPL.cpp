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

#include "ad/map/maker/osm_converter/OsmTrafficSignsPL.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::unordered_map<std::string, map_data::LandmarkType> const &getTrafficSignsPL()
{
  // Polish signs:
  // https://pl.wikipedia.org/wiki/Wzory_znak%C3%B3w_i_sygna%C5%82%C3%B3w_drogowych_w_Polsce
  //
  // This is just an excerpt of traffic signs appearing in SCN_A6_S3_seagull_intersection.osm
  // clang-format off
  static std::unordered_map<std::string, map_data::LandmarkType> strToTrafficSignMap
  {
    {"PL:B-33", map_data::LandmarkType::SignMaxSpeed},
    {"PL:D-7", map_data::LandmarkType::SignMotorVehicleBegin},
    {"PL:D-9", map_data::LandmarkType::SignMotorwayBegin},
    {"PL:D-10", map_data::LandmarkType::SignMotorwayEnd},
  };
  // clang-format on
  return strToTrafficSignMap;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
