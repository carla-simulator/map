/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#include "opendrive/parser/GeoReferenceParser.h"
#include "opendrive/types.hpp"

#include <boost/algorithm/string.hpp>
#include <iostream>
#include <limits>
#include <vector>

#define ACCEPT_USE_OF_DEPRECATED_PROJ_API_H
#include <proj_api.h>

namespace opendrive {
namespace parser {

::opendrive::geom::GeoLocation GeoReferenceParser::Parse(const std::string &geo_reference_string)
{
  ::opendrive::geom::GeoLocation result{
    std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), 0.0, ""};
  result.projection = geo_reference_string;

  auto projPtr = pj_init_plus(geo_reference_string.c_str());

  if (projPtr != nullptr)
  {
    projXY refPoint;
    refPoint.u = 0;
    refPoint.v = 0;
    const auto geoPoint = pj_inv(refPoint, projPtr);
    result.longitude = geoPoint.u * RAD_TO_DEG;
    result.latitude = geoPoint.v * RAD_TO_DEG;
  }
  else
  {
    std::vector<std::string> geo_ref_splitted;
    boost::split(geo_ref_splitted, geo_reference_string, boost::is_any_of(" "));
    for (auto const &element : geo_ref_splitted)
    {
      std::vector<std::string> geo_ref_key_value;
      boost::split(geo_ref_key_value, element, boost::is_any_of("="));
      if (geo_ref_key_value.size() != 2u)
      {
        continue;
      }

      if (geo_ref_key_value[0] == "+lat_0")
      {
        result.latitude = std::stod(geo_ref_key_value[1]);
      }
      else if (geo_ref_key_value[0] == "+lon_0")
      {
        result.longitude = std::stod(geo_ref_key_value[1]);
      }
    }
  }

  return result;
}

} // namespace parser
} // namespace opendrive
