// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include <vector>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

enum class OsmTurnDirection
{
  Left,
  SlightLeft,
  SharpLeft,
  Through,
  Right,
  SlightRight,
  SharpRight,
  Reverse,
  MergeToLeft,
  MergeToRight,
  None,
  Invalid
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad

template <typename T> std::vector<T> fromString(std::string const &str);

template <> std::vector<::ad::map::maker::osm_converter::OsmTurnDirection> fromString(std::string const &str);

#include <functional>
namespace std {
template <> struct hash<::ad::map::maker::osm_converter::OsmTurnDirection>
{
  std::size_t operator()(::ad::map::maker::osm_converter::OsmTurnDirection const &t) const
  {
    return static_cast<std::size_t>(t);
  }
};
} // namespace std
