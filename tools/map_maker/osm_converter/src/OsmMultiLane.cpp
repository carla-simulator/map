// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
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
