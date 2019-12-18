// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

namespace ad {
namespace map {
namespace maker {
namespace common {

enum class RightOfWay
{
  Undefined,
  Stop,
  GiveWay,
  HasWay,
  AllWayStop,
  PriorityToRight,
  Crosswalk,
  Ramp
};

RightOfWay rowFromString(std::string const &source);
std::string rowToString(RightOfWay const row);

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
