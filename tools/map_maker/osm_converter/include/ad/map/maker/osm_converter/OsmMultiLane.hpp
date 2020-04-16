// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include "ad/map/maker/osm_converter/OsmTurnDirection.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/**
 * @brief represent widths of lanes of one direction (forward or backward)
 *
 * Wish: Rename into OsmRoad (or OsmLink) because it represents all data of all lanes
 *       Create a struct that holds all the data, i.e.
 *       - width
 *       - vector of turn directions
 *
 * A note about MaxSpeed:
 * We only maintain one speed limit per direction although it is clear that this is not
 * reality. Strictly speaking we have to maintain a speed limit per lane. And such a
 * speed limit could have additional attributes like vehicle type (e.g. 60 km/h for trucks,
 * 80 km/h for cars with trailer, and also temporal attributes like when raining, or for
 * a given time period.
 */
struct OsmMultiLane
{
  std::vector<double> mWidths;
  std::vector<std::vector<OsmTurnDirection>> mTurnDirection;
  double mMaxSpeed{-1.}; //! in km/h, applies to all lanes in the given direction

  /**
   * @brief return true if lanes have different lanes (number, widths) or speed limits
   * @param other
   */
  bool hasDifferentAttributes(OsmMultiLane const &other) const;

  /**
   * @brief return summed width of all lanes
   */
  double width() const;
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
