// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <functional>
#include <set>
#include <sstream>
#include <string>
#include "ad/map/lane/LaneId.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace lane */
namespace lane {

typedef std::set<LaneId> LaneIdSet;

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

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::lane::LaneIdSet> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::lane::LaneIdSet const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};