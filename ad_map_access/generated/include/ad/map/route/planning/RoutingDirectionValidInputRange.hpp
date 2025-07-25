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
#include "ad/map/route/planning/RoutingDirection.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given RoutingDirection is within valid input range
 *
 * \param[in] input the RoutingDirection as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if RoutingDirection is considered to be within the specified input range
 *
 * \note the specified input range is defined by the valid enum literals.
 */
inline bool withinValidInputRange(::ad::map::route::planning::RoutingDirection const &input,
                                  bool const logErrors = true)
{
  bool inValidInputRange = (input == ::ad::map::route::planning::RoutingDirection::DONT_CARE)
    || (input == ::ad::map::route::planning::RoutingDirection::POSITIVE)
    || (input == ::ad::map::route::planning::RoutingDirection::NEGATIVE);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::route::planning::RoutingDirection)>> {}, raw value: {} ",
                  input,
                  static_cast<int32_t>(input)); // LCOV_EXCL_BR_LINE
  }
  return inValidInputRange;
}
