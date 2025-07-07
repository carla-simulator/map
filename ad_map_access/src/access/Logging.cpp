// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/access/Logging.hpp"
#include "AdMapAccess.hpp"

namespace ad {
namespace map {
namespace access {

std::shared_ptr<spdlog::logger> getLogger()
{
  return AdMapAccess::getAdMapAccessInstance().mLogger;
}

spdlog::level::level_enum getLogLevel()
{
  return getLogger()->level();
}

void setLogLevel(spdlog::level::level_enum const logLevel)
{
  getLogger()->set_level(logLevel);
}

void setLogLevel(std::string const &logLevel)
{
  getLogger()->set_level(spdlog::level::from_str(logLevel));
}

} // namespace access
} // namespace map
} // namespace ad
