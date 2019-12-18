// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2017-2019 Intel Corporation
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

#include "ad/map/maker/osm_converter/PoiType.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::string poiTypeToString(PoiType poiType)
{
  switch (poiType)
  {
    case PoiType::Crosswalk:
      return "Crosswalk";
    case PoiType::Tree:
      return "Tree";
    case PoiType::StreetLamp:
      return "StreetLamp";
    case PoiType::FireHydrant:
      return "FireHydrant";
    case PoiType::PowerCabinet:
      return "PowerCabinet";
    case PoiType::Bollard:
      return "RoadBollard";
    case PoiType::PostBox:
      return "Postbox";
    case PoiType::ManHole:
      return "ManHole";
    case PoiType::TrafficLight:
      return "TrafficLight";
    case PoiType::PelicanCrossing:
      return "PelicanCrossing";
    case PoiType::Invalid:
    default:
      return "Invalid";
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
