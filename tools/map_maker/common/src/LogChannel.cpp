// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/LogChannel.hpp"
#include <iostream>

namespace ad {
namespace map {
namespace maker {
namespace common {

LogChannel::LogChannel(std::shared_ptr<std::ostream> sink, LogLevel threshold, std::string const &moduleName)
  : mThreshold(threshold)
  , mSink(sink)
  , mModuleName(moduleName)
{
}

LogChannel &LogChannel::operator()(LogLevel logLevel)
{
  if (willLogBeWrittenAtLevel(logLevel))
  {
    mWriteLog = true;
    *mSink << "[" << mModuleName << "|" << logLevel << "] ";
  }
  else
  {
    mWriteLog = false;
  }

  return *this;
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
