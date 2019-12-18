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

#include "ad/map/maker/osm_converter/OsmHighwayType.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

std::string highwayTypeToString(OsmHighwayType const highwayType)
{
  switch (highwayType)
  {
    case OsmHighwayType::Motorway:
      return "motorway";
    case OsmHighwayType::MotorwayLink:
      return "motorway_link";
    case OsmHighwayType::Primary:
      return "primary";
    case OsmHighwayType::PrimaryLink:
      return "primary_link";
    case OsmHighwayType::Secondary:
      return "secondary";
    case OsmHighwayType::SecondaryLink:
      return "secondary_link";
    case OsmHighwayType::Tertiary:
      return "tertiary";
    case OsmHighwayType::TertiaryLink:
      return "tertiary_link";
    case OsmHighwayType::Trunk:
      return "trunk";
    case OsmHighwayType::TrunkLink:
      return "trunk_link";
    case OsmHighwayType::Residential:
      return "residential";
    case OsmHighwayType::Service:
      return "service";
    case OsmHighwayType::Unclassified:
      return "unclassified";
    case OsmHighwayType::Invalid:
    default:
      return "Invalid";
  }
}

OsmHighwayType highwayTypeFromString(std::string const &highwayType)
{
  if (highwayType == "motorway")
  {
    return OsmHighwayType::Motorway;
  }
  else if (highwayType == "motorway_link")
  {
    return OsmHighwayType::MotorwayLink;
  }
  else if (highwayType == "primary")
  {
    return OsmHighwayType::Primary;
  }
  else if (highwayType == "primary_link")
  {
    return OsmHighwayType::PrimaryLink;
  }
  else if (highwayType == "secondary")
  {
    return OsmHighwayType::Secondary;
  }
  else if (highwayType == "secondary_link")
  {
    return OsmHighwayType::SecondaryLink;
  }
  else if (highwayType == "tertiary")
  {
    return OsmHighwayType::Tertiary;
  }
  else if (highwayType == "tertiary_link")
  {
    return OsmHighwayType::TertiaryLink;
  }
  else if (highwayType == "trunk")
  {
    return OsmHighwayType::Trunk;
  }
  else if (highwayType == "trunk_link")
  {
    return OsmHighwayType::TrunkLink;
  }
  else if (highwayType == "residential")
  {
    return OsmHighwayType::Residential;
  }
  else if (highwayType == "service")
  {
    return OsmHighwayType::Service;
  }
  else if (highwayType == "unclassified")
  {
    return OsmHighwayType::Unclassified;
  }
  else
  {
    return OsmHighwayType::Invalid;
  }
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
