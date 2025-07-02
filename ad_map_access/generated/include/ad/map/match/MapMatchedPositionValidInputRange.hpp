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
#include "ad/map/match/LanePointValidInputRange.hpp"
#include "ad/map/match/MapMatchedPosition.hpp"
#include "ad/map/match/MapMatchedPositionTypeValidInputRange.hpp"
#include "ad/map/point/ECEFPointValidInputRange.hpp"
#include "ad/physics/DistanceValidInputRange.hpp"
#include "ad/physics/ProbabilityValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given MapMatchedPosition is within valid input range
 *
 * \param[in] input the MapMatchedPosition as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if MapMatchedPosition is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::match::MapMatchedPosition const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.lane_point, logErrors) && withinValidInputRange(input.type, logErrors)
    && withinValidInputRange(input.matched_point, logErrors) && withinValidInputRange(input.probability, logErrors)
    && withinValidInputRange(input.query_point, logErrors)
    && withinValidInputRange(input.matched_point_distance, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::match::MapMatchedPosition)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
