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
#include "ad/map/landmark/LandmarkId.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace landmark */
namespace landmark {

/**
 * @brief Set to store landmark identifiers
 */
typedef std::set<LandmarkId> LandmarkIdSet;

} // namespace landmark
} // namespace map
} // namespace ad

namespace std {

inline std::ostream &operator<<(std::ostream &os, ::ad::map::landmark::LandmarkIdSet const &landmarkIdSet)
{
  os << "[ ";
  for (auto it = landmarkIdSet.begin(); it != landmarkIdSet.end(); ++it)
  {
    if (it != landmarkIdSet.begin())
    {
      os << ", ";
    }
    os << *it;
  }
  os << "]";
  return os;
}

static inline std::string to_string(::ad::map::landmark::LandmarkIdSet const &landmarkIdSet)
{
  stringstream sstream;
  sstream << landmarkIdSet;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::landmark::LandmarkIdSet> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::landmark::LandmarkIdSet const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};