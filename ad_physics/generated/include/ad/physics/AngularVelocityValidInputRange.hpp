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
#include "ad/physics/AngularVelocity.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given AngularVelocity is within valid input range
 *
 * \param[in] input the AngularVelocity as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if AngularVelocity is considered to be within the specified input range
 *
 * \note the specified input range is defined by
 *       std::numeric_limits<::ad::physics::AngularVelocity>::lowest() <= \c input <=
 * std::numeric_limits<::ad::physics::AngularVelocity>::max() -100. <= \c input <= 100.
 */
inline bool withinValidInputRange(::ad::physics::AngularVelocity const &input, bool const logErrors = true)
{
  // check for generic numeric limits of the type
  bool inValidInputRange = input.isValid() && (std::numeric_limits<::ad::physics::AngularVelocity>::lowest() <= input)
    && (input <= std::numeric_limits<::ad::physics::AngularVelocity>::max());
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::physics::AngularVelocity)>> {} out of numerical limits [{}, {}]",
                  input,
                  std::numeric_limits<::ad::physics::AngularVelocity>::lowest(),
                  std::numeric_limits<::ad::physics::AngularVelocity>::max()); // LCOV_EXCL_BR_LINE
  }
  // check for individual input range
  if (inValidInputRange)
  {
    inValidInputRange
      = (::ad::physics::AngularVelocity(-100.) <= input) && (input <= ::ad::physics::AngularVelocity(100.));
    if (!inValidInputRange && logErrors)
    {
      spdlog::error("withinValidInputRange(::ad::physics::AngularVelocity)>> {} out of valid input range [{}, {}]",
                    input,
                    ::ad::physics::AngularVelocity(-100.),
                    ::ad::physics::AngularVelocity(100.)); // LCOV_EXCL_BR_LINE
    }
  }
  return inValidInputRange;
}
