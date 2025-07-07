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

#include "ad/map/point/ParaPoint.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace point */
namespace point {

/**
 * @brief create a ParaPoint
 *
 * @param[in] lane_id  the lane id
 * @param[in] parametric_offset the parametric offset
 */
inline ParaPoint createParaPoint(lane::LaneId const &lane_id, physics::ParametricValue const &parametric_offset)
{
  ParaPoint result;
  result.lane_id = lane_id;
  result.parametric_offset = parametric_offset;
  return result;
}

} // namespace point
} // namespace map
} // namespace ad

/**
 * @brief Standard comparison operator.
 * @returns True if left object can be seen as less than right object.
 */
inline bool operator<(const ::ad::map::point::ParaPoint &left, const ::ad::map::point::ParaPoint &right)
{
  if (left.lane_id < right.lane_id)
  {
    return true;
  }
  else if (left.lane_id == right.lane_id)
  {
    return left.parametric_offset < right.parametric_offset;
  }
  else
  {
    return false;
  }
}

/**
 * @brief Standard comparison operator
 * @returns True if left object can be seen as greater than right object.
 */
inline bool operator>(const ::ad::map::point::ParaPoint &left, const ::ad::map::point::ParaPoint &right)
{
  if (left.lane_id > right.lane_id)
  {
    return true;
  }
  else if (left.lane_id == right.lane_id)
  {
    return left.parametric_offset > right.parametric_offset;
  }
  else
  {
    return false;
  }
}

/**
 * @brief Standard comparison operator.
 * @returns True if left object can be seen as less than or equal to right object.
 */
inline bool operator<=(const ::ad::map::point::ParaPoint &left, const ::ad::map::point::ParaPoint &right)
{
  return operator<(left, right) || (left == right);
}

/**
 * @brief Standard comparison operator.
 * @returns True if left object can be seen as greater than or equal to right object.
 */
inline bool operator>=(const ::ad::map::point::ParaPoint &left, const ::ad::map::point::ParaPoint &right)
{
  return operator>(left, right) || (left == right);
}
