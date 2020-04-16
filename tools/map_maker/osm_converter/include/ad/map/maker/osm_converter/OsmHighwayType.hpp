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

/* These are the highway types for which we provide default width,
   all others are mapped Invalid */
enum class OsmHighwayType
{
  Motorway,
  MotorwayLink,
  Primary,
  PrimaryLink,
  Secondary,
  SecondaryLink,
  Tertiary,
  TertiaryLink,
  Trunk,
  TrunkLink,
  Residential,
  Service,
  Unclassified,
  Invalid
};

std::string highwayTypeToString(OsmHighwayType const highwayType);
OsmHighwayType highwayTypeFromString(std::string const &highwayType);

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad

/* The following is required to enable OsmJunctionArm
 * together with std::unordered_set
 */
#include <functional>
namespace std {
template <> struct hash<::ad::map::maker::osm_converter::OsmHighwayType>
{
  std::size_t operator()(::ad::map::maker::osm_converter::OsmHighwayType const &t) const
  {
    return static_cast<std::size_t>(t);
  }
};

template <> struct equal_to<::ad::map::maker::osm_converter::OsmHighwayType>
{
  constexpr bool operator()(::ad::map::maker::osm_converter::OsmHighwayType const &lhs,
                            ::ad::map::maker::osm_converter::OsmHighwayType const &rhs) const
  {
    return (lhs == rhs);
  }
};

} // namespace std
