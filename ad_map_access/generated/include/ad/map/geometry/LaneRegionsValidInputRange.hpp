/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-2046
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/map/geometry/LaneRegions.hpp"
#include "ad/map/match/LaneOccupiedRegionListValidInputRange.hpp"
#include "ad/map/point/BoundingSphereValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given LaneRegions is within valid input range
 *
 * \param[in] input the LaneRegions as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if LaneRegions is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::geometry::LaneRegions const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.fully_occluded, logErrors)
    && withinValidInputRange(input.partly_occluded, logErrors) && withinValidInputRange(input.fully_visible, logErrors)
    && withinValidInputRange(input.reference_position, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::geometry::LaneRegions)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
