// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/TaskTimer.hpp"
#include "ad/map/maker/common/LogChannel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

TaskTimer::TaskTimer(LogChannel &logger)
  : mLog(logger)
{
}

bool TaskTimer::start(std::string const &msg)
{
  if (!mMsg.empty())
  {
    return false;
  }
  mStartOfTask = std::chrono::system_clock::now();
  mMsg = msg;
  mLog(LogLevel::Info) << mMsg << " ...\n";
  return true;
}

bool TaskTimer::stop()
{
  if (mMsg.empty())
  {
    return false;
  }
  auto endOfTask = std::chrono::system_clock::now();
  auto const elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endOfTask - mStartOfTask);
  mLog(LogLevel::Info) << mMsg << " done (" << elapsed.count() << " ms)\n";
  mMsg.clear();
  return true;
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
