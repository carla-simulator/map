// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/AppConfigDescription.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

namespace po = boost::program_options;

AppConfigDescription::AppConfigDescription()
  : ::boost::program_options::options_description("Common options")
{
  // clang-format off
  add_options()
      ("print-stats", po::bool_switch(&config.printStats),
       "Print additional info on how many nodes, ways are processed.")
      ("logging,l", po::value<std::string>(&config.loggingConfig)->default_value(config.loggingConfig),
       "Configuration for logChannels defined as: config1,config2,... "
       "An item of the config-string has the form: <modulename>:<threshold>:<output>[:<target>]")
      ("output,o", po::value<std::string>(&config.outputFile)->default_value(config.outputFile),
       "Specify the path to output file.")
      ("input-file", po::value<std::string>(&config.inputFile),
       "Input file");
  // clang-format on
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
