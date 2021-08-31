/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-1997
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/map/point/ENUCoordinate.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given ENUCoordinate is within valid input range
 *
 * \param[in] input the ENUCoordinate as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if ENUCoordinate is considered to be within the specified input range
 *
 * \note the specified input range is defined by
 *       std::numeric_limits<::ad::map::point::ENUCoordinate>::lowest() <= \c input <=
 * std::numeric_limits<::ad::map::point::ENUCoordinate>::max()
 *       -1e8 <= \c input <= 1e8
 */
inline bool withinValidInputRange(::ad::map::point::ENUCoordinate const &input, bool const logErrors = true)
{
  // check for generic numeric limits of the type
  bool inValidInputRange = input.isValid() && (std::numeric_limits<::ad::map::point::ENUCoordinate>::lowest() <= input)
    && (input <= std::numeric_limits<::ad::map::point::ENUCoordinate>::max());
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::point::ENUCoordinate)>> {} out of numerical limits [{}, {}]",
                  input,
                  std::numeric_limits<::ad::map::point::ENUCoordinate>::lowest(),
                  std::numeric_limits<::ad::map::point::ENUCoordinate>::max()); // LCOV_EXCL_BR_LINE
  }
  // check for individual input range
  if (inValidInputRange)
  {
    inValidInputRange
      = (::ad::map::point::ENUCoordinate(-1e8) <= input) && (input <= ::ad::map::point::ENUCoordinate(1e8));
    if (!inValidInputRange && logErrors)
    {
      spdlog::error("withinValidInputRange(::ad::map::point::ENUCoordinate)>> {} out of valid input range [{}, {}]",
                    input,
                    ::ad::map::point::ENUCoordinate(-1e8),
                    ::ad::map::point::ENUCoordinate(1e8)); // LCOV_EXCL_BR_LINE
    }
  }
  return inValidInputRange;
}
