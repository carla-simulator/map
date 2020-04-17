// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
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
