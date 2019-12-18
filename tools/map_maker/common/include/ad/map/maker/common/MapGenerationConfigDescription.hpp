// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <boost/program_options/options_description.hpp>
#include "ad/map/maker/common/MapGenerationConfig.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

/*!
 * \brief Option parsing for MapDataGeneration
 */
struct MapGenerationConfigDescription : ::boost::program_options::options_description
{
  MapGenerationConfigDescription();
  MapGenerationConfig config;
};

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
