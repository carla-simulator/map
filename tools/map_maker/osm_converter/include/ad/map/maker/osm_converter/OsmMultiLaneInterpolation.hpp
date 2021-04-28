// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "ad/map/maker/osm_converter/OsmMultiLane.hpp"

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

/**
 * @brief Generate transitions (in the number of lanes as well as in the widths of the lanes)
 *
 * Example for increasing number of lanes:
 * A change in the number of lanes (from S with one lane to E with three lanes
 *
 * S0___E0___E0
 *     \E1___E1
 *         \_E2
 *
 * After construction, from = [S0, 0], to = [E0, E1]
 * hasNext() == true
 * After next(): from = [E0, E1, 0], to = [E0, E1, E2]
 * hasNext() == false
 *
 *
 * Example for decreasing number of lanes:
 * A change in the number of lanes (from S with one lane to E with three lanes
 *
 * (easier?!? code, symmetric to increasing lanes)
 * S0___ S0 ___ S0 ___ E0
 * S1___ S1 ___ S1 ___ E1
 * S2___ S2 __/
 * S3__/
 *
 * (saving one transition)
 * Alternatively:
 * S0___ E0 ___ E0
 * S1___ E1 ___ E1
 * S2___ S2 __/
 * S3__/
 *
 * Going with alternative:
 * After construction, from = [S0, S1, S2, S3], to = [E0, E1, S2, 0]
 * hasNext() == true
 * After next(): from = [E0, E1, S2], to = [E0, E1, 0]
 * hasNext() == false (?!?)
 */
class OsmMultiLaneInterpolation
{
public:
  /**
   * @brief OsmMultiLaneInterpolation
   * @param start setup of lanes at start
   * @param end setup of lanes at end
   *
   * Provide an interpolation over the widths of a road segment.
   */
  OsmMultiLaneInterpolation(OsmMultiLane const &start, OsmMultiLane const &end);

  bool hasNext() const;
  void next();

  OsmMultiLane from() const;
  OsmMultiLane to() const;

private:
  OsmMultiLane mStart;
  OsmMultiLane mEnd;

  OsmMultiLane mFrom{};
  OsmMultiLane mTo{};

  int64_t mNumberOfLanesDifference{0};
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad
