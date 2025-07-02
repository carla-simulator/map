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
#include "ad/map/landmark/LandmarkIdListValidInputRange.hpp"
#include "ad/map/lane/ContactLaneListValidInputRange.hpp"
#include "ad/map/lane/Lane.hpp"
#include "ad/map/lane/LaneDirectionValidInputRange.hpp"
#include "ad/map/lane/LaneIdValidInputRange.hpp"
#include "ad/map/lane/LaneTypeValidInputRange.hpp"
#include "ad/map/point/BoundingSphereValidInputRange.hpp"
#include "ad/map/point/GeometryValidInputRange.hpp"
#include "ad/map/restriction/RestrictionsValidInputRange.hpp"
#include "ad/map/restriction/SpeedLimitListValidInputRange.hpp"
#include "ad/physics/DistanceValidInputRange.hpp"
#include "ad/physics/MetricRangeValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given Lane is within valid input range
 *
 * \param[in] input the Lane as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if Lane is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::lane::Lane const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.id, logErrors) && withinValidInputRange(input.type, logErrors)
    && withinValidInputRange(input.direction, logErrors) && withinValidInputRange(input.restrictions, logErrors)
    && withinValidInputRange(input.length, logErrors) && withinValidInputRange(input.length_range, logErrors)
    && withinValidInputRange(input.width, logErrors) && withinValidInputRange(input.width_range, logErrors)
    && withinValidInputRange(input.speed_limits, logErrors) && withinValidInputRange(input.edge_left, logErrors)
    && withinValidInputRange(input.edge_right, logErrors) && withinValidInputRange(input.contact_lanes, logErrors)
    && withinValidInputRange(input.bounding_sphere, logErrors)
    && withinValidInputRange(input.visible_landmarks, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::lane::Lane)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
