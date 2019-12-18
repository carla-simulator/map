// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <functional>
#include <sstream>
#include <string>
#include <unordered_set>
#include "ad/map/lane/LaneId.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace lane */
namespace lane {

struct LaneIdHash
{
  std::size_t operator()(LaneId const &laneId) const noexcept
  {
    return static_cast<uint64_t>(laneId);
  }
};

using LaneIdSet = std::unordered_set<LaneId, LaneIdHash>;

} // namespace lane
} // namespace map
} // namespace ad

namespace std {

inline std::ostream &operator<<(std::ostream &os, ::ad::map::lane::LaneIdSet const &laneIdSet)
{
  os << "[ ";
  for (auto it = laneIdSet.begin(); it != laneIdSet.end(); ++it)
  {
    if (it != laneIdSet.begin())
    {
      os << ", ";
    }
    os << *it;
  }
  os << "]";
  return os;
}

static inline std::string to_string(::ad::map::lane::LaneIdSet const &laneIdSet)
{
  stringstream sstream;
  sstream << laneIdSet;
  return sstream.str();
}
} // namespace std
