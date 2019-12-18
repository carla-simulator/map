// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <functional>
#include <unordered_set>
#include "ad/map/landmark/LandmarkId.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace landmark */
namespace landmark {

/**
 * @brief Hash of a landmark identifier
 */
struct LandmarkIdHash
{
  std::size_t operator()(LandmarkId const &landmarkId) const noexcept
  {
    return static_cast<uint64_t>(landmarkId);
  }
};

/**
 * @brief Set to store hashes for landmark identifiers
 */
using LandmarkIdSet = std::unordered_set<LandmarkId, LandmarkIdHash>;

} // namespace landmark
} // namespace map
} // namespace ad
