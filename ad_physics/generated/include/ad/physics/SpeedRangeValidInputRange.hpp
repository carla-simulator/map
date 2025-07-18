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
#include "ad/physics/SpeedRange.hpp"
#include "ad/physics/SpeedValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given SpeedRange is within valid input range
 *
 * \param[in] input the SpeedRange as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if SpeedRange is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members, plus:
 *       ::ad::physics::Speed(-100.) <= minimum <= maximum
 *       minimum <= maximum <= ::ad::physics::Speed(100.)
 */
inline bool withinValidInputRange(::ad::physics::SpeedRange const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange
    = withinValidInputRange(input.minimum, logErrors) && withinValidInputRange(input.maximum, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::physics::SpeedRange)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  // check for individual input ranges
  if (inValidInputRange)
  {
    inValidInputRange = (::ad::physics::Speed(-100.) <= input.minimum) && (input.minimum <= input.maximum);
    if (!inValidInputRange && logErrors)
    {
      spdlog::error(
        "withinValidInputRange(::ad::physics::SpeedRange)>> {} element {} out of valid input range [{}, {}]",
        input,
        input.minimum,
        ::ad::physics::Speed(-100.),
        input.maximum); // LCOV_EXCL_BR_LINE
    }
  }

  if (inValidInputRange)
  {
    inValidInputRange = (input.minimum <= input.maximum) && (input.maximum <= ::ad::physics::Speed(100.));
    if (!inValidInputRange && logErrors)
    {
      spdlog::error(
        "withinValidInputRange(::ad::physics::SpeedRange)>> {} element {} out of valid input range [{}, {}]",
        input,
        input.maximum,
        input.minimum,
        ::ad::physics::Speed(100.)); // LCOV_EXCL_BR_LINE
    }
  }

  return inValidInputRange;
}
