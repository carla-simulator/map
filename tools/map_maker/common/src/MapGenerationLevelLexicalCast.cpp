// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/MapGenerationLevelLexicalCast.hpp"

namespace boost {

template <>::ad::map::maker::common::MapGenerationLevel lexical_cast(std::string const &str)
{
  return ::ad::map::maker::common::mapGenerationLevelFromString(str);
}

} // namespace boost
