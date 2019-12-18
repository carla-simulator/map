// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <chrono> /* for std::chrono::systemclock::time_point */
#include <string>

namespace ad {
namespace map {
namespace maker {
namespace common {

struct LogChannel;

/**
 * @brief Measure time of tasks and log
 */
struct TaskTimer
{
  explicit TaskTimer(LogChannel &logger);

  //! return false if a task is already started
  bool start(std::string const &msg);
  //! return false if no task was started
  bool stop();

private:
  LogChannel &mLog;
  std::chrono::system_clock::time_point mStartOfTask;
  std::string mMsg;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
