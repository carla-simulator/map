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
