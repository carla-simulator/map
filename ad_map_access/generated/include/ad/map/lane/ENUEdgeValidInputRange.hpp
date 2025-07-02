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
#include "ad/map/lane/ENUEdge.hpp"
#include "ad/map/lane/EdgeTypeValidInputRange.hpp"
#include "ad/map/point/ENUPointListValidInputRange.hpp"
#include "ad/physics/ParametricValueValidInputRange.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given ENUEdge is within valid input range
 *
 * \param[in] input the ENUEdge as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if ENUEdge is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::lane::ENUEdge const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  bool inValidInputRange = true;
  inValidInputRange = withinValidInputRange(input.lateral_alignment, logErrors)
    && withinValidInputRange(input.points, logErrors) && withinValidInputRange(input.edge_type, logErrors);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::lane::ENUEdge)>> {} has invalid member",
                  input); // LCOV_EXCL_BR_LINE
  }

  return inValidInputRange;
}
