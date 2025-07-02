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

#include "ad/map/restriction/SpeedLimit.hpp"
#include "ad/physics/RangeOperation.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace restriction */
namespace restriction {

/**
 * @brief Compare two speed limit attributes for equality.
 * @param[in] left SpeedLimit object.
 * @param[in] right SpeedLimit object.
 * @returns true if the attributes of the left SpeedLimit and right SpeedLimit can be considered to be equal.
 */
inline bool areAttributesEqual(SpeedLimit const &left, SpeedLimit const &right)
{
  return left.speed_limit == right.speed_limit;
}

/**
 * @brief Tries to combine two RangeAttributes into one.
 * @param[in] left RangeAttributes object.
 * @param[in] right RangeAttributes object.
 * @returns true if left RangeAttributes is extended with right one.
 */
template <typename RangeAttribute> bool combineRangeAttributes(RangeAttribute &left, RangeAttribute const &right)
{
  if (areAttributesEqual(left, right))
  {
    return extendRangeWith(left.lane_piece, right.lane_piece);
  }
  return false;
}

/**
 * @brief Checks if another attribute overlaps any existing element.
 * @param[in] attributeList attribute list to check for overlap
 * @param[in] attribute another attribute.
 * @returns true if another element overlaps any existing element in the attributeList
 */
template <typename RangeAttribute>
bool doesRangeAttributeOverlap(std::vector<RangeAttribute> const &attributeList, RangeAttribute const &attribute)
{
  for (auto const &listEntry : attributeList)
  {
    if (doRangesOverlap(attribute.lane_piece, listEntry.lane_piece)
        && !doesRangePredate(attribute.lane_piece, listEntry.lane_piece)
        && !doesRangeSucceed(attribute.lane_piece, listEntry.lane_piece))
    {
      return true;
    }
  }
  return false;
}

/**
 * @brief Insert attribute and preserve order.
 * @param[in] attributeList attribute list
 * @param[in] attribute attribute to insert
 */
template <typename RangeAttribute>
void insertRangeAttribute(std::vector<RangeAttribute> &attributeList, RangeAttribute const &attribute)
{
  for (auto it = attributeList.begin(); it != attributeList.end(); it++)
  {
    if (attribute.lane_piece <= it->lane_piece)
    {
      attributeList.insert(it, attribute);
      optimizeRangeAttributeList(attributeList);
      return;
    }
  }
  attributeList.push_back(attribute);
  optimizeRangeAttributeList(attributeList);
}

/** @brief Combines multiple elements into one - if possible. */
template <typename RangeAttribute> void optimizeRangeAttributeList(std::vector<RangeAttribute> &attributeList)
{
  for (auto it = attributeList.begin(); it != attributeList.end();)
  {
    auto it1 = it + 1;
    if (it1 == attributeList.end())
    {
      return;
    }
    if (combineRangeAttributes(*it, *it1))
    {
      attributeList.erase(it1);
    }
    else
    {
      it = it1;
    }
  }
}

} // namespace restriction
} // namespace map
} // namespace ad
