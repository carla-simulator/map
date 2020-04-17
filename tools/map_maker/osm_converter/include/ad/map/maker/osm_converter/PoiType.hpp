// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

enum class PoiType
{
  Invalid = 0,
  Crosswalk,
  Tree,
  StreetLamp,
  FireHydrant,
  PowerCabinet,
  Bollard,
  PostBox,
  ManHole,
  TrafficLight,
  TrafficSign,
  PelicanCrossing
};

extern std::string poiTypeToString(PoiType poiType);

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad

/**
 * NOTE: we need a hash function to allow PoiType as a key for unordered maps
 * (https://stackoverflow.com/questions/18837857/cant-use-enum-class-as-unordered-map-key)
 * NOTE: we are allowed to extend namespace std (http://en.cppreference.com/w/cpp/language/extending_std)
 */
#include <functional>
namespace std {
template <> struct hash<::ad::map::maker::osm_converter::PoiType>
{
  std::size_t operator()(::ad::map::maker::osm_converter::PoiType const &t) const
  {
    return static_cast<std::size_t>(t);
  }
};
} // namespace std
