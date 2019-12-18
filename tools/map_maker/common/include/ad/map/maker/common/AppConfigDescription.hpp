// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include "ad/map/maker/common/AppConfig.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Generic options for all applications
 */
struct AppConfigDescription : ::boost::program_options::options_description
{
  AppConfigDescription();
  AppConfig config;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
