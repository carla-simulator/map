// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include "ad/map/maker/common/OsmToLaneletConfig.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Option parsing for OsmToLanelet
 */
struct OsmToLaneletConfigDescription : ::boost::program_options::options_description
{
  OsmToLaneletConfigDescription();
  OsmToLaneletConfig config;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
