// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

/**
 * @file
 */

#pragma once

#include "ad/physics/AngleOperation.hpp"
#include "ad/physics/ParametricOperation.hpp"
#include "ad/physics/PhysicsOperation.hpp"
#include "ad/physics/RangeOperation.hpp"
#include "ad/physics/RatioOperation.hpp"
#include "ad/physics/Types.hpp"

/*!
 * @brief Multiplication of two probabilities
 *
 * @param[in] p1 a probability
 * @param[in] p2 another probability
 *
 * @returns p = p1 * p2 as probability value
 *
 * \note throws a std::out_of_range exception if one of the two operands or the result of
 *   the operation is not valid
 */
inline ad::physics::Probability operator*(ad::physics::Probability const &p1, ad::physics::Probability const &p2)
{
  p1.ensureValid();
  p2.ensureValid();
  ad::physics::Probability p(p1.mProbability * p2.mProbability);
  p.restrictToLimitsAndEnsureValid();
  return p;
}

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace for physics datatypes and operations
 */
namespace physics {

/*!
 * @brief ensure the physics operators defined at global scope are also found within ad::physics namespace
 */
using ::operator*;

/*!
 * @brief ensure the physics operators defined at global scope are also found within ad::physics namespace
 */
using ::operator/;

} // namespace physics
} // namespace ad
