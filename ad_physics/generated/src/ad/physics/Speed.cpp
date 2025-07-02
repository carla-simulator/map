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

#include "ad/physics/Speed.hpp"
#include "ad/physics/SpeedSquared.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

const double Speed::cMinValue = -1e3;

const double Speed::cMaxValue = 1e3;

const double Speed::cPrecisionValue = 1e-3;

} // namespace physics
} // namespace ad
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace physics
 */
namespace physics {

::ad::physics::SpeedSquared Speed::operator*(const Speed &other) const
{
  ensureValid();
  other.ensureValid();
  ::ad::physics::SpeedSquared result(mSpeed * other.mSpeed);
  result.restrictToLimitsAndEnsureValid(); // LCOV_EXCL_BR_LINE On correct definition of squarerooted type, this cannot
                                           // not happen
  return result;
}

} // namespace physics
} // namespace ad
