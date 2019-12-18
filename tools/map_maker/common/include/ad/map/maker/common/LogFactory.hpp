// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <fstream>  // needed here?
#include <iostream> // needed here?
#include <memory>
#include <sstream>
#include <unordered_map>
#include "ad/map/maker/common/LogChannel.hpp"
#include "ad/map/maker/common/LogLevel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/**
 * @brief The LogFactory keeps track of all existing LogChannels
 *
 * The LogFactory configures LogChannels per request and keeps track of all already created LogChannels
 * (more precisely: the underlying sinks). All LogChannels are requested by name. This means if different
 * entities/modules request a LogChannel with the same name they will both use the same LogChannel.
 *
 * Be aware that the LogChannels are not thread safe.
 *
 * A LogChannel is defined by
 * - the sink (where the logs are streamed)
 * - a threshold above which logs are really created
 * - and a module name (which also identifies the LogChannels within the factory)
 *
 * The configuration of the LogChannels is defined through a settings-strings of
 * the form:
 * config1,config2,...
 * An item of the config-string has the form:
 * <modulename>:<threshold>:<output>[:<target>]
 *
 * modulename: the name of the module, this string is prepended to every log, and it is also
 *             used for looking up the settings of the LogChannel inside the factory. Therefore, different
 *             LogChannels must be named differently. If no module name is given in the config
 *             the setting applies to all LogChannels.
 * threshold:  The threshold used for logging. If none is given, default=Warning is assumed
 * output:     The target of the logs. Must be one of:
 *             - console (logs forwarded to stdout)
 *             - file (requires additional information "target", i.e. the file name)
 *             - buffer (only useful within Unit Tests)
 *             If no output is given, stdout is taken as default
 *
 * Precedence of settings:
 * If no setting is given for a specific modulename, the default values are taken
 * If no default settings are given in the configuration, the built-in values are taken (Warning, and stdout)
 *
 * Examples:
 * setting=ModuleA:Info:buffer:module_buffer
 * The LogChannel for ModuleA will filter at level "Info" and will output into a buffer, all other LogChannels
 * will use the built-in default values
 *
 * setting=ModuleA:Info:buffer,:Warning:file:/tmp/log.txt
 * The LogChannel for ModuleA will filter at level "Info" and will output into a buffer, all other LogChannels
 * will use the provided default values Warning as threshold and output to the file /tmp/log.txt
 *
 * Usage in programs:
 * There should be only one instance of LogFactory which has to be configured with the desired config-settings:
 * @code
    auto logFactory = std::make_shared<LogFactory>(myLogSettingsString);
 * @endcode
 *
 * To create/use a log-channel, simply ask the factory for one:
 * @code
    auto logFactory = std::make_shared<LogFactory>(myLogSettingsString);
    auto logChannel = logFactory->logChannel(myChannelName);
    logChannel(LogLevel::Warning) << "A log\n";
 * @endcode
 *
 * Usage in unit-tests
 * The LogFactory allows to specify a ostringstream as sink for a LogChannel. This can be used within unit test
 * to test for the expected output of a specific module. E.g.:
 * @code
    map_common::LogFactory factory("module:Info:buffer:common_buf,another:Warning:buffer:common_buf");
    // factory now has three settings: two as stated above and the default setting
    auto logChannel = factory.logChannel("module");
    auto anotherLogChannel = factory.logChannel("another");
    logChannel(map_common::LogLevel::Warning) << "Log1\n";
    anotherLogChannel(map_common::LogLevel::Warning) << "AnotherLog2\n";
    auto bufferSink = factory.bufferForName("common_buf");

    char expectedLog[] =
        "[module|Warn] Log1\n"
        "[another|Warn] AnotherLog2\n";
    ASSERT_STREQ(expectedLog, bufferSink->str().c_str());
 * @endcode
 *
 */
class LogFactory
{
public:
  explicit LogFactory(std::string const &configSettings);
  ~LogFactory();

  /**
   * @brief Create/Configure or reuse LogChannel for given module name
   * @return configured LogChannel
   */
  LogChannel &logChannel(std::string const &moduleName);

  std::shared_ptr<std::ostringstream> bufferForName(std::string const &bufferName) const;
  std::shared_ptr<std::ofstream> fileForName(std::string const &fileName) const;

private:
  struct LogSetting
  {
    LogLevel threshold{LogLevel::Warning};
    std::string output{"console"};
    std::string target{""}; // use for name of file or name of buffer
  };
  std::unordered_map<std::string, LogSetting> mConfigSetting;

  std::unordered_map<std::string, std::shared_ptr<std::ofstream>> mFileSink;
  std::unordered_map<std::string, std::shared_ptr<std::ostringstream>> mBufferSink;

  std::unordered_map<std::string, LogChannel> mCreatedChannels;

  void parseSettings(std::string const &configSettings);
  void extractSetting(std::string const &setting);
  bool validSetting(LogSetting const &ls) const;
  void updateSetting(std::string const &moduleName, LogSetting const &ls);

  std::shared_ptr<std::ostream> getOrCreateBufferSink(std::string const &target);
  std::shared_ptr<std::ostream> getOrCreateFileSink(std::string const &target);

  LogSetting getLogSettingForModule(std::string const &moduleName) const;
  std::shared_ptr<std::ostream> getSinkForSetting(LogSetting const &setting);
  LogChannel createChannel(std::string const &moduleName);
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
