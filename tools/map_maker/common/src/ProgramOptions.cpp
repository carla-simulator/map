// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/ProgramOptions.hpp"
#include <ad_map_access/Version.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <fstream>
#include <iostream>
#include "ad/map/maker/common/StringHelper.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

namespace po = ::boost::program_options;

std::string getNameOfExecutable(char *executableCallingName)
{
  ::boost::filesystem::path pathAndNameOfExecutable(executableCallingName);
  return pathAndNameOfExecutable.filename().string();
}

ProgramOptions::ProgramOptions(const std::string &briefDescription)
  : mConfiguration()
  , mProgramBrief(briefDescription)
  , mAllOptions("")
  , mSharedOptions("")
{
}

bool ProgramOptions::parseOptions(int argc, char *argv[])
{
  std::string configFileName;

  // options that can be used only on the command-line
  po::options_description cmdOptions("Command line options");
  // clang-format off
  cmdOptions.add_options()
      ("help,h", po::bool_switch(&mConfiguration.printHelp), "Print this help and exit")
      ("version", po::bool_switch(&mConfiguration.printVersion), "Print version and exit")
      ("config-file,c", po::value<std::string>(&configFileName), "Read options from config-file");
  // clang-format on

  po::positional_options_description freeArgument;
  freeArgument.add("input-file", 1);

  mAllOptions.add(cmdOptions).add(mSharedOptions);

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).options(mAllOptions).positional(freeArgument).run(), vm);
  po::notify(vm);

  mConfiguration.execName = getNameOfExecutable(argv[0]);
  if (mConfiguration.printVersion)
  {
    dumpVersion();
    return false;
  }

  if (mConfiguration.printHelp)
  {
    printHelp();
    return false;
  }

  if (vm.count("config-file"))
  {
    std::ifstream settingsFile(configFileName);
    std::cout << "Reading config-file \"" << configFileName << "\"\n";
    po::store(po::parse_config_file(settingsFile, mSharedOptions), vm);
    po::notify(vm);
  }

  if (vm.count("input-file") == 0)
  {
    std::cerr << "Error: No input file provided\n\n";
    printHelp();
    return false;
  }

  return true;
}

void ProgramOptions::addOptionGroup(::boost::program_options::options_description &optionExtension)
{
  mSharedOptions.add(optionExtension);
}

void ProgramOptions::printHelp() const
{
  std::cout << mConfiguration.execName + " " + AD_MAP_ACCESS_VERSION_STRING;
  if (!mProgramBrief.empty())
  {
    std::cout << " - " << mProgramBrief;
  }
  std::cout << "\n\nUsage:\n";
  std::cout << mConfiguration.execName << " [options] <input file>\n";
  std::cout << mAllOptions << "\n";
}

void ProgramOptions::dumpVersion() const
{
  std::cout << mConfiguration.execName + " - " + AD_MAP_ACCESS_VERSION_STRING << "\n";
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
