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

#include "ad/map/maker/osm_converter/OsmHighwayType.hpp"
#include "ad/map/maker/osm_converter/OsmMultiLane.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

struct OsmWay
{
  ::osmium::object_id_type mWayId{};
  //! order is from left to right (seen in driving direction), index=0 is the leftmost forward lane
  OsmMultiLane mForwardLanes;
  //! order is from right to left (seen in driving direction), index=0 is the rightmost backward lane
  OsmMultiLane mBackwardLanes;
  OsmHighwayType mHighwayType{OsmHighwayType::Invalid};
  int32_t mLayer{0};

  double width() const
  {
    return mForwardLanes.width() + mBackwardLanes.width();
  }
  double offset() const
  {
    return (mForwardLanes.width() - mBackwardLanes.width()) / 2.;
  }
  bool hasDifferentAttributes(OsmWay const &other) const
  {
    return ((mLayer != other.mLayer) || (mForwardLanes.hasDifferentAttributes(other.mForwardLanes))
            || (mBackwardLanes.hasDifferentAttributes(other.mBackwardLanes)));
  }
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
