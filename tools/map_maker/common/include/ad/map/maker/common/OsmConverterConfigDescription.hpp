// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include "ad/map/maker/common/OsmConverterConfig.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Option parsing for OsmConverterConfig
 */
struct OsmConverterConfigDescription : ::boost::program_options::options_description
{
  OsmConverterConfigDescription();
  OsmConverterConfig config;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
