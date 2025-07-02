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
#include "ad/map/geometry/PolygonIntersection.hpp"
#include "ad/map/point/ENUPointListVectorValidInputRange.hpp"

/*!
 * \brief check if the given PolygonIntersection is within valid input range
 *
 * \param[in] input the PolygonIntersection as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if PolygonIntersection is considered to be within the specified input range
 *
 * \note the specified input range is defined by the ranges of all members
 */
inline bool withinValidInputRange(::ad::map::geometry::PolygonIntersection const &input, bool const logErrors = true)
{
  // check for generic member input ranges
  (void)input;
  (void)logErrors;
  bool inValidInputRange = true;
  return inValidInputRange;
}
