// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
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

#include "ad/map/maker/osm_converter/OsmStringToTrafficSign.hpp"
#include <ad/map/maker/common/LogChannel.hpp>
#include <ad/map/maker/common/StringHelper.hpp>
#include "ad/map/maker/osm_converter/OsmTrafficSignsDE.hpp"
#include "ad/map/maker/osm_converter/OsmTrafficSignsPL.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/* Some thoughts
 * We could also make this a class which holds a map of country code to the string-enum-map
 */

std::unordered_map<std::string, map_data::LandmarkType> const &trafficSignMap(std::string sign)
{
  if ((sign.c_str()[0] == 'D') && (sign.c_str()[1] == 'E'))
  {
    return getTrafficSignsDE();
  }
  if ((sign.c_str()[0] == 'P') && (sign.c_str()[1] == 'L'))
  {
    return getTrafficSignsPL();
  }
  throw std::runtime_error("No mapping for sign " + sign);
}

map_data::LandmarkType landmarkTypeFromString(std::string const &sign, common::LogChannel &logger)
{
  if (sign.empty())
  {
    return map_data::LandmarkType::SignFreeText;
  }
  if (sign == "city_limit")
  {
    return map_data::LandmarkType::SignCityBegin;
  }
  if (sign == "maxspeed")
  {
    // silently ignored because handled outside?!?
    // otherwise we also have to parse k='maxspeed' v='<value>'
    // same would apply to 'stop', 'yield'
    // We could also query the string-to-enum map which should always return "Unknown"
    // as we expect that no count has a sign with official code "maxspeed" ...
    return map_data::LandmarkType::Unknown;
  }
  std::string query{};
  if (sign.find_first_of(':') != 2) // make sure we have a country code (colon at pos 2)
  {
    logger(common::LogLevel::Warning) << "Missing country code in traffic sign\"" << sign << "\". Assuming DE:\n";
    query = "DE:";
  }

  query = query + sign;
  /* Get the correct map, for now there is only DE */
  try
  {
    auto signMap = trafficSignMap(query);
    /* Try to convert string */
    if (signMap.count(query) == 1)
    {
      return signMap[query];
    }
    logger(common::LogLevel::Warning) << "Unsupported traffic sign " << sign << "\n";
  }
  catch (std::runtime_error &)
  {
    logger(common::LogLevel::Warning) << "Unsupported country code for traffic sign " << sign << "\n";
  }
  return map_data::LandmarkType::Unknown;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
