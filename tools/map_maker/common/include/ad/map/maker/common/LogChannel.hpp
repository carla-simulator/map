// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <memory>
#include <ostream>
#include "ad/map/maker/common/LogLevel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/**
 * @brief provide a stream-like logging facility
 *
 * Allows to trigger logs with a log-level as threshold for filtering, e.g.
 * @code
 * auto sink; // not relevant here how this one looks like, could be stdout
 * LogChannel channel(sink, LogLevel::Info, "MyModule");
 * channel(LogLevel::Warning) << "A warning log\n";
 * @endcode
 *
 * The stream's arguments will not be evaluated if no log has to be written, e.g.
 * @code
 * struct Foo { int myVal; };
 *
 * std::ostream& operator<<(std::ostream &os, Foo const &f) { return os << f.myVal' }
 *
 * auto sink; // not relevant here how this one looks like, could be stdout
 * LogChannel channel(sink, LogLevel::Info, "MyModule");
 * Foo f;
 * channel(LogLevel::Info) << "Foo" << f << "\n";
 * @endcode
 * Foo.operator<< will not be called. Nevertheless LogChannel.operator<< will be called
 * for all arguments. If you want to avoid this, use willLogBeWrittenAtLevel(LogLevel).
 *
 * @attention Be aware that the class is not thread-safe!
 */
struct LogChannel
{
  /**
   * @brief Construct a log channel for module "moduleName"
   * @param sink where all log messages will end up
   * @param threshold used to filter logs at creation side
   * @param moduleName the name of the module
   */
  LogChannel(std::shared_ptr<std::ostream> sink, LogLevel threshold, std::string const &moduleName);
  LogChannel() = delete;

  LogChannel &operator()(LogLevel logLevel);

  /**
   * @brief Will a log be written with the given log level?
   *
   * Use this function before triggering a time consuming log
   */
  bool willLogBeWrittenAtLevel(LogLevel logLevel) const
  {
    return ((mThreshold > LogLevel::Off) && (logLevel <= mThreshold) && (logLevel > LogLevel::Off));
  }

  // @todo what happens to friends of iomanip?
  template <typename T> LogChannel &operator<<(T const &data)
  {
    if (mWriteLog)
    {
      *mSink << data;
    }

    return *this;
  }

  // maybe we will introduce settings such as printModuleName, printTimestamp, etc..
  // but for now we provide only a minimalistic set of features

private:
  LogLevel mThreshold{LogLevel::Warning};
  //! the facility to use when the log passed the threshold
  std::shared_ptr<std::ostream> mSink;
  //! write the message (did it pass the threshold?)
  bool mWriteLog{false};
  std::string mModuleName;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
