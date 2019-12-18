// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ostream>

namespace ad {
namespace map {
namespace maker {
namespace common {

/**
 * @brief The available log-levels
 *
 * LogLevel::Off and below are only useful as a threshold in the settings
 */
enum class LogLevel
{
  Invalid = -2,
  Default = -1,
  Off = 0,
  Error = 1,
  Warning = 2,
  Info = 3,
  Verbose = 4
};

LogLevel fromString(std::string const &logLevelString);
std::ostream &operator<<(std::ostream &os, LogLevel const &l);

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
