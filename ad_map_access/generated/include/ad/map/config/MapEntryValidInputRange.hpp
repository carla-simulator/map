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
#include "ad/map/config/MapEntry.hpp"
#include "ad/map/intersection/IntersectionTypeValidInputRange.hpp"
#include "ad/map/landmark/TrafficLightTypeValidInputRange.hpp"
#include "ad/physics/DistanceValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given MapEntry is within valid input range
 *
 * \param[in] input the MapEntry as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if MapEntry is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::config::MapEntry const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.open_drive_overlap_margin, logErrors)
    && withinValidInputRange(input.open_drive_default_intersection_type, logErrors)
    && withinValidInputRange(input.open_drive_default_traffic_light_type, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::config::MapEntry)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
