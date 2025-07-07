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

#include "ad/physics/SpeedSquared.hpp"
#include "ad/physics/Speed.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

const double SpeedSquared::cMinValue = -1e6;

const double SpeedSquared::cMaxValue = 1e6;

const double SpeedSquared::cPrecisionValue = 1e-6;

} // namespace physics
} // namespace ad
namespace std {

::ad::physics::Speed sqrt(::ad::physics::SpeedSquared const other)
{
  ::ad::physics::Speed result(std::sqrt(other.mSpeedSquared));
  result.restrictToLimitsAndEnsureValid();
  return result;
}

} // namespace std
