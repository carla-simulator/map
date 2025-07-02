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
#include "ad/map/lane/EdgeType.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given EdgeType is within valid input range
 *
 * \param[in] input the EdgeType as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if EdgeType is considered to be within the specified input range
 *
 * \note the specified input range is defined by the valid enum literals.
 */
inline bool withinValidInputRange(::ad::map::lane::EdgeType const &input, bool const logErrors = true)
{
  bool inValidInputRange = (input == ::ad::map::lane::EdgeType::UNKNOWN) || (input == ::ad::map::lane::EdgeType::CENTER)
    || (input == ::ad::map::lane::EdgeType::ALIGNED) || (input == ::ad::map::lane::EdgeType::LEFT_PROJECTED)
    || (input == ::ad::map::lane::EdgeType::RIGHT_PROJECTED) || (input == ::ad::map::lane::EdgeType::LEFT)
    || (input == ::ad::map::lane::EdgeType::RIGHT);
  if (!inValidInputRange && logErrors)
  {
    spdlog::error("withinValidInputRange(::ad::map::lane::EdgeType)>> {}, raw value: {} ",
                  input,
                  static_cast<int32_t>(input)); // LCOV_EXCL_BR_LINE
  }
  return inValidInputRange;
}
