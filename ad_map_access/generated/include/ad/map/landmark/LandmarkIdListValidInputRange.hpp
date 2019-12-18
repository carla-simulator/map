/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 10.6.1-1904
 */

#pragma once

#include <cmath>
#include <limits>
#include "ad/map/landmark/LandmarkIdList.hpp"
#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

/*!
 * \brief check if the given LandmarkIdList is within valid input range
 *
 * \param[in] input the LandmarkIdList as an input value
 * \param[in] logErrors enables error logging
 *
 * \returns \c true if LandmarkIdList is considered to be within the specified input range
 *
 * \note the specified input range is defined by
 *       0 <= \c input.size() <= 0
 *       and the ranges of all vector elements
 */
inline bool withinValidInputRange(::ad::map::landmark::LandmarkIdList const &input, bool const logErrors = true)
{
  (void)input;
  (void)logErrors;
  bool inValidInputRange = true;

  return inValidInputRange;
}
