// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include <string>

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief ProgramOptions configuration parser
 */
class ProgramOptions
{
public:
  ProgramOptions(std::string const &briefDescription);

  bool parseOptions(int argc, char *argv[]);

  void addOptionGroup(::boost::program_options::options_description &optionExtension);

  /*!
   * @brief Print program options help.
   */
  void printHelp() const;

private:
  struct
  {
    bool printVersion{false};
    bool printHelp{false};
    std::string execName;
  } mConfiguration;

  std::string mProgramBrief{};

  ::boost::program_options::options_description mAllOptions;    // collection of all options, used for printHelp
  ::boost::program_options::options_description mSharedOptions; // used for file and cmdline

  /*!
   * @brief Print program version.
   */
  void dumpVersion() const;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
