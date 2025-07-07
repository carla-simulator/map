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
#include "ad/map/lane/ECEFEdge.hpp"
#include "ad/map/lane/EdgeTypeValidInputRange.hpp"
#include "ad/map/point/ECEFPointListValidInputRange.hpp"
#include "ad/physics/ParametricValueValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given ECEFEdge is within valid input range
 *
 * \param[in] input the ECEFEdge as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if ECEFEdge is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::lane::ECEFEdge const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.points, logErrors)
    && withinValidInputRange(input.edge_type, logErrors) && withinValidInputRange(input.lateral_alignment, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::lane::ECEFEdge)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
