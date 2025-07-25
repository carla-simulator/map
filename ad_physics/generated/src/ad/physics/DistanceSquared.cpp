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

#include "ad/physics/DistanceSquared.hpp"
#include "ad/physics/Distance.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

const double DistanceSquared::cMinValue = -1e18;

const double DistanceSquared::cMaxValue = 1e18;

const double DistanceSquared::cPrecisionValue = 1e-6;

} // namespace physics
} // namespace ad
namespace std {

::ad::physics::Distance sqrt(::ad::physics::DistanceSquared const other)
{
  ::ad::physics::Distance result(std::sqrt(other.mDistanceSquared));
  result.restrictToLimitsAndEnsureValid();
  return result;
}

} // namespace std
