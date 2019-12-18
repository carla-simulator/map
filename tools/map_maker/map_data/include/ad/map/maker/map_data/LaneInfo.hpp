// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <inttypes.h>

namespace ad {
namespace map {
namespace maker {
namespace map_data {
class MapDataStore;
struct IntersectionArm;
struct Road;

struct LaneInfo
{
  uint64_t lanesIn{0u};      //!< number of lanes that go into the intersection
  uint64_t lanesOut{0u};     //!< number of lanes that go out of the intersection
  uint64_t usedLanesIn{0u};  //!< number of lanes that were already _used_ for settings up roads
  uint64_t usedLanesOut{0u}; //!< number of lanes that were already _used_ for settings up roads
  Road const &road;

  LaneInfo(MapDataStore const &store, IntersectionArm const &arm);

  //! calculate offset of lanes at exit/entry
  double forwardLaneOffset(bool const useLanesIn, bool isEntry) const;

  //! update number of used lanes (in) such that numLanes can be added later without exceeding lanesIn
  void adjustUsedLanesIn(uint64_t const numLanes);
  //! update number of used lanes (out) such that numLanes can be added later without exceeding lanesOut
  void updateUsedLanesOut(uint64_t const numLanes);
};

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
