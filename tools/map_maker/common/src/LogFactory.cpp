// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/LogFactory.hpp"
#include "ad/map/maker/common/LogChannel.hpp"
#include "ad/map/maker/common/StringHelper.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

LogFactory::LogFactory(std::string const &configSettings)
{
  LogSetting defaultSetting;
  mConfigSetting.insert(std::make_pair("", defaultSetting));
  if (!configSettings.empty())
  {
    parseSettings(configSettings);
  }
}

LogFactory::~LogFactory()
{
  // do we need to flush and close all file based sinks?
}

void LogFactory::parseSettings(std::string const &configSettings)
{
  auto listOfItems = splitString(configSettings, ',');
  for (auto item : listOfItems)
  {
    if (!item.empty())
    {
      extractSetting(item);
    }
  }
}

void LogFactory::extractSetting(std::string const &setting)
{
  auto entries = splitString(setting, ':');
  if ((entries.size() == 3) || (entries.size() == 4))
  {
    // module name
    LogSetting ls;
    ls.threshold = entries[1].empty() ? LogLevel::Default : fromString(entries[1]);
    ls.output = entries[2];
    if (entries.size() == 4)
    {
      ls.target = entries[3];
    }
    if (validSetting(ls))
    {
      updateSetting(entries[0], ls);
    }
    else
    {
      std::cerr << "Error parsing setting: " << setting << "\n";
    }
  }
  else
  {
    std::cerr << "Unable to parse setting \"" << setting << "\"\n";
  }
}

bool LogFactory::validSetting(LogSetting const &ls) const
{
  if (ls.threshold == LogLevel::Invalid)
  {
    std::cerr << "Invalid threshold given\n";
    return false;
  }

  if ((ls.output == "console") || (ls.output == ""))
  {
    // warn if ls.target is set
    if (!ls.target.empty())
    {
      std::cout << "Warning! The target \"" << ls.target << "\" is set for output type " << ls.output << "\n";
    }
    // no real error
  }
  else if ((ls.output == "file") || (ls.output == "buffer"))
  {
    if (ls.target == "")
    {
      std::cerr << "Missing target name for output " << ls.output << "\n";
      return false;
    }
  }
  else
  {
    std::cerr << "Invalid output type: " << ls.output << "\n";
    return false;
  }

  return true;
}

void LogFactory::updateSetting(std::string const &moduleName, LogSetting const &ls)
{
  if (mConfigSetting.count(moduleName) == 0)
  {
    LogSetting update;
    mConfigSetting.insert(std::make_pair(moduleName, update));
  }

  if (ls.threshold != LogLevel::Default)
  {
    mConfigSetting[moduleName].threshold = ls.threshold;
  }

  if (!ls.output.empty())
  {
    mConfigSetting[moduleName].output = ls.output;
    mConfigSetting[moduleName].target = ls.target;
  }
}

LogFactory::LogSetting LogFactory::getLogSettingForModule(std::string const &moduleName) const
{
  LogSetting result;
  auto const &storedSetting = mConfigSetting.find(moduleName);
  if (storedSetting != mConfigSetting.end())
  {
    result = storedSetting->second;
    // do we need for Default as threshold?
    if (result.threshold == LogLevel::Default)
    {
      result.threshold = mConfigSetting.at("").threshold;
    }
  }
  else
  {
    result = mConfigSetting.at(""); // use default
  }

  return result;
}

std::shared_ptr<std::ostream> LogFactory::getOrCreateBufferSink(std::string const &target)
{
  if (mBufferSink.count(target) == 0)
  {
    auto bufferSink = std::make_shared<std::ostringstream>();
    mBufferSink.insert(std::make_pair(target, bufferSink));
    return bufferSink;
  }
  else
  {
    return mBufferSink[target];
  }
}

std::shared_ptr<std::ostream> LogFactory::getOrCreateFileSink(std::string const &target)
{
  if (mFileSink.count(target) == 0)
  {
    auto fileSink = std::make_shared<std::ofstream>(target);
    if (fileSink->is_open())
    {
      mFileSink.insert(std::make_pair(target, fileSink));
      return fileSink;
    }
    else
    {
      std::cerr << "Unable to open " << target << "for logging. Falling back to stdout instead!\n";
      return std::shared_ptr<std::ostream>(&std::cout, [](void *) {});
    }
  }
  else
  {
    return mFileSink[target];
  }
}

std::shared_ptr<std::ostream> LogFactory::getSinkForSetting(LogSetting const &setting)
{
  if (setting.output == "console")
  {
    // the shared_ptr must not release std::cout, see
    // https://stackoverflow.com/questions/17220154/c11-stdshared-ptrstdostream-from-stdcout
    return std::shared_ptr<std::ostream>(&std::cout, [](void *) {});
  }
  else if (setting.output == "buffer")
  {
    return getOrCreateBufferSink(setting.target);
  }
  else if (setting.output == "file")
  {
    return getOrCreateFileSink(setting.target);
  }
  // no else intended here!

  throw std::out_of_range("Unsupported sink type " + setting.output);
}

LogChannel LogFactory::createChannel(std::string const &moduleName)
{
  LogSetting ls = getLogSettingForModule(moduleName);
  auto sink = getSinkForSetting(ls);
  auto result = LogChannel(sink, ls.threshold, moduleName);
  return result;
}

LogChannel &LogFactory::logChannel(std::string const &moduleName)
{
  if (mCreatedChannels.count(moduleName) == 0)
  {
    auto result = createChannel(moduleName);
    mCreatedChannels.insert(std::make_pair(moduleName, result));
    return mCreatedChannels.at(moduleName);
  }
  else
  {
    return mCreatedChannels.at(moduleName);
  }
}

std::shared_ptr<std::ostringstream> LogFactory::bufferForName(std::string const &bufferName) const
{
  if (mBufferSink.count(bufferName))
  {
    return mBufferSink.at(bufferName);
  }

  return std::shared_ptr<std::ostringstream>();
}

std::shared_ptr<std::ofstream> LogFactory::fileForName(std::string const &fileName) const
{
  if (mFileSink.count(fileName))
  {
    return mFileSink.at(fileName);
  }

  return std::shared_ptr<std::ofstream>();
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
