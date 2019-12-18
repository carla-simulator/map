// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Global Application configuration
 */
struct AppConfig
{
  bool printStats{false};
  std::string inputFile;
  std::string outputFile;
  std::string loggingConfig{};
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
