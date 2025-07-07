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

#include "ad/map/route/planning/RoutingDirection.hpp"
#include <stdexcept>

std::string toString(::ad::map::route::planning::RoutingDirection const e)
{
  switch (e)
  {
    case ::ad::map::route::planning::RoutingDirection::DONT_CARE:
      return std::string("::ad::map::route::planning::RoutingDirection::DONT_CARE"); // LCOV_EXCL_BR_LINE
    case ::ad::map::route::planning::RoutingDirection::POSITIVE:
      return std::string("::ad::map::route::planning::RoutingDirection::POSITIVE"); // LCOV_EXCL_BR_LINE
    case ::ad::map::route::planning::RoutingDirection::NEGATIVE:
      return std::string("::ad::map::route::planning::RoutingDirection::NEGATIVE"); // LCOV_EXCL_BR_LINE
    default:
      return std::string("UNKNOWN ENUM VALUE"); // LCOV_EXCL_BR_LINE
  }
}

template <>::ad::map::route::planning::RoutingDirection fromString(std::string const &str)
{
  if (str == std::string("::ad::map::route::planning::RoutingDirection::DONT_CARE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::DONT_CARE;
  }
  if (str == std::string("DONT_CARE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::DONT_CARE;
  }
  if (str == std::string("::ad::map::route::planning::RoutingDirection::POSITIVE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::POSITIVE;
  }
  if (str == std::string("POSITIVE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::POSITIVE;
  }
  if (str == std::string("::ad::map::route::planning::RoutingDirection::NEGATIVE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::NEGATIVE;
  }
  if (str == std::string("NEGATIVE")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::route::planning::RoutingDirection::NEGATIVE;
  }
  throw std::out_of_range("Invalid enum literal"); // LCOV_EXCL_BR_LINE
}
