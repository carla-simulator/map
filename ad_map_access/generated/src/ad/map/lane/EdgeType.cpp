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

#include "ad/map/lane/EdgeType.hpp"
#include <stdexcept>

std::string toString(::ad::map::lane::EdgeType const e)
{
  switch (e)
  {
    case ::ad::map::lane::EdgeType::UNKNOWN:
      return std::string("::ad::map::lane::EdgeType::UNKNOWN"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::CENTER:
      return std::string("::ad::map::lane::EdgeType::CENTER"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::ALIGNED:
      return std::string("::ad::map::lane::EdgeType::ALIGNED"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::LEFT_PROJECTED:
      return std::string("::ad::map::lane::EdgeType::LEFT_PROJECTED"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::RIGHT_PROJECTED:
      return std::string("::ad::map::lane::EdgeType::RIGHT_PROJECTED"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::LEFT:
      return std::string("::ad::map::lane::EdgeType::LEFT"); // LCOV_EXCL_BR_LINE
    case ::ad::map::lane::EdgeType::RIGHT:
      return std::string("::ad::map::lane::EdgeType::RIGHT"); // LCOV_EXCL_BR_LINE
    default:
      return std::string("UNKNOWN ENUM VALUE"); // LCOV_EXCL_BR_LINE
  }
}

template <>::ad::map::lane::EdgeType fromString(std::string const &str)
{
  if (str == std::string("::ad::map::lane::EdgeType::UNKNOWN")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::UNKNOWN;
  }
  if (str == std::string("UNKNOWN")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::UNKNOWN;
  }
  if (str == std::string("::ad::map::lane::EdgeType::CENTER")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::CENTER;
  }
  if (str == std::string("CENTER")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::CENTER;
  }
  if (str == std::string("::ad::map::lane::EdgeType::ALIGNED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::ALIGNED;
  }
  if (str == std::string("ALIGNED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::ALIGNED;
  }
  if (str == std::string("::ad::map::lane::EdgeType::LEFT_PROJECTED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::LEFT_PROJECTED;
  }
  if (str == std::string("LEFT_PROJECTED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::LEFT_PROJECTED;
  }
  if (str == std::string("::ad::map::lane::EdgeType::RIGHT_PROJECTED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::RIGHT_PROJECTED;
  }
  if (str == std::string("RIGHT_PROJECTED")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::RIGHT_PROJECTED;
  }
  if (str == std::string("::ad::map::lane::EdgeType::LEFT")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::LEFT;
  }
  if (str == std::string("LEFT")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::LEFT;
  }
  if (str == std::string("::ad::map::lane::EdgeType::RIGHT")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::RIGHT;
  }
  if (str == std::string("RIGHT")) // LCOV_EXCL_BR_LINE
  {
    return ::ad::map::lane::EdgeType::RIGHT;
  }
  throw std::out_of_range("Invalid enum literal"); // LCOV_EXCL_BR_LINE
}
