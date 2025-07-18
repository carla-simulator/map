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
#include "ad/map/match/LaneOccupiedRegionListValidInputRange.hpp"
#include "ad/map/match/MapMatchedObjectBoundingBox.hpp"
#include "ad/map/match/MapMatchedObjectReferencePositionListValidInputRange.hpp"
#include "ad/physics/DistanceValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given MapMatchedObjectBoundingBox is within valid input range
 *
 * \param[in] input the MapMatchedObjectBoundingBox as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if MapMatchedObjectBoundingBox is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::match::MapMatchedObjectBoundingBox const &input,
                                  bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.lane_occupied_regions, logErrors)
    && withinValidInputRange(input.reference_point_positions, logErrors)
    && withinValidInputRange(input.sampling_distance, logErrors)
    && withinValidInputRange(input.match_radius, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::match::MapMatchedObjectBoundingBox)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
