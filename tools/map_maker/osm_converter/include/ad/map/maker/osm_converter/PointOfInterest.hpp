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

#include <cmath>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/geometry/Point.hpp>
#include "ad/map/maker/osm_converter/PoiType.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/**
 * @brief Represent point of interest (POI) in coordinate system defined by the line |start-end|
 */
struct PointOfInterest
{
  ::osmium::object_id_type mStart{};
  ::osmium::object_id_type mEnd{};
  ::osmium::object_id_type mPoiId{}; // id of node
  PoiType mPoiType{PoiType::Invalid};

  // mapping.x is the longitudinal offset from the start
  // mapping.y is the lateral offset to the right
  geometry::Point mProjection{};
  bool mIsValid{false};

  void update(::osmium::object_id_type start,
              ::osmium::object_id_type end,
              geometry::Point const &projection,
              PoiType const poiType,
              ::osmium::object_id_type const poiId)
  {
    if ((!mIsValid) || (std::abs(projection.y) < std::abs(mProjection.y)))
    {
      mIsValid = true;
      mProjection = projection;
      mStart = start;
      mEnd = end;
      mPoiType = poiType;
      mPoiId = poiId;
    }
  }
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
