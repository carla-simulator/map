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

#include "ad/physics/DurationSquared.hpp"
#include "ad/physics/Duration.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

const double DurationSquared::cMinValue = -1e12;

const double DurationSquared::cMaxValue = 1e12;

const double DurationSquared::cPrecisionValue = 1e-6;

} // namespace physics
} // namespace ad
namespace std {

::ad::physics::Duration sqrt(::ad::physics::DurationSquared const other)
{
  ::ad::physics::Duration result(std::sqrt(other.mDurationSquared));
  result.restrictToLimitsAndEnsureValid();
  return result;
}

} // namespace std
