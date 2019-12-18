// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/MapGenerationLevel.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

MapGenerationLevel mapGenerationLevelFromString(std::string const &source)
{
  if (source.compare("raw") == 0)
  {
    return MapGenerationLevel::Raw;
  }
  else if (source.compare("skeleton") == 0)
  {
    return MapGenerationLevel::Skeleton;
  }
  else if (source.compare("full") == 0)
  {
    return MapGenerationLevel::Full;
  }
  else
  {
    return MapGenerationLevel::Undefined;
  }
}

std::string mapGenerationLevelToString(MapGenerationLevel const level)
{
  switch (level)
  {
    case MapGenerationLevel::Raw:
      return std::string("raw");
    case MapGenerationLevel::Skeleton:
      return std::string("skeleton");
    case MapGenerationLevel::Full:
      return std::string("full");
    default:
      return std::string("undefined");
  }
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
