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
#include "ad/map/point/ParaPointValidInputRange.hpp"
#include "ad/map/route/planning/RoutingDirectionValidInputRange.hpp"
#include "ad/map/route/planning/RoutingParaPoint.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given RoutingParaPoint is within valid input range
 *
 * \param[in] input the RoutingParaPoint as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if RoutingParaPoint is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::route::planning::RoutingParaPoint const &input,
                                  bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange
    = withinValidInputRange(input.point, logErrors) && withinValidInputRange(input.direction, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::route::planning::RoutingParaPoint)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
