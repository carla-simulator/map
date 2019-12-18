// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <vector>

namespace ad {
namespace map {
namespace maker {
namespace map_data {

enum class TurnDirection
{
  Left,
  SlightLeft,
  SharpLeft,
  Through,
  Right,
  SlightRight,
  SharpRight,
  MergeToLeft,
  MergeToRight,
  None
};

typedef std::vector<TurnDirection> TurnDirections;

} // namespace map_data
} // namespace maker
} // namespace map
} // namespace ad
