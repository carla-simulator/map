// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

namespace ad {
namespace map {
namespace maker {
namespace common {

struct OsmToLaneletConfig
{
  double dist2JunctionCenter{8.};
  //!< the width/length of the stripes that make up the crosswalk, cannot be set via cmdline
  double crosswalkLength{4.};
  bool disableTimestamp{false}; // disable writing timestamp=""
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
