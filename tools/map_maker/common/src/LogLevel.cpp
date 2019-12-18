// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <iostream>
#include "ad/map/maker/common/LogChannel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

LogLevel fromString(std::string const &logLevelString)
{
  if (logLevelString == "Off")
  {
    return LogLevel::Off;
  }
  else if (logLevelString == "Error")
  {
    return LogLevel::Error;
  }
  else if (logLevelString == "Warning")
  {
    return LogLevel::Warning;
  }
  else if (logLevelString == "Info")
  {
    return LogLevel::Info;
  }
  else if (logLevelString == "Verbose")
  {
    return LogLevel::Verbose;
  }
  else if (logLevelString == "Default")
  {
    return LogLevel::Default;
  }
  else
  {
    return LogLevel::Invalid;
  }
}

std::ostream &operator<<(std::ostream &os, LogLevel const &logLevel)
{
  switch (logLevel)
  {
    case LogLevel::Off:
      return os << "Off ";
    case LogLevel::Error:
      return os << "Error";
    case LogLevel::Warning:
      return os << "Warn";
    case LogLevel::Info:
      return os << "Info";
    case LogLevel::Verbose:
      return os << "Verbose";
    case LogLevel::Default:
      return os << "Default";
    default:
      return os << "Invalid";
  }
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
