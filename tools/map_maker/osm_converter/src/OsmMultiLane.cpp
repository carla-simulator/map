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

#include "ad/map/maker/osm_converter/OsmMultiLane.hpp"
#include <cmath>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

bool OsmMultiLane::hasDifferentAttributes(OsmMultiLane const &other) const
{
  if (mWidths.size() != other.mWidths.size())
  {
    return true;
  }

  for (uint32_t i = 0u; i < mWidths.size(); ++i)
  {
    if (std::abs(mWidths[i] - other.mWidths[i]) > 0.01)
    {
      return true;
    }
  }

  if (std::abs(mMaxSpeed - other.mMaxSpeed) > 0.01)
  {
    return true;
  }

  return false;
}

double OsmMultiLane::width() const
{
  double totalWidth = 0.;
  for (auto w : mWidths)
  {
    totalWidth += w;
  }

  return totalWidth;
}

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
