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
#include "ad/map/point/ENUPointCache.hpp"
#include "ad/map/point/ENUPointListValidInputRange.hpp"

/*!
 * \brief check if the given ENUPointCache is within valid input range
 *
 * \param[in] input the ENUPointCache as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if ENUPointCache is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::point::ENUPointCache const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  (void)input;
  (void)logErrors;
  bool inValidInputRange = true;
  return inValidInputRange;
}
