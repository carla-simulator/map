// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/RightOfWay.hpp"

namespace ad {
namespace map {
namespace maker {
namespace common {

RightOfWay rowFromString(std::string const &source)
{
  if (source.compare("stop") == 0)
  {
    return RightOfWay::Stop;
  }
  else if (source.compare("give_way") == 0)
  {
    return RightOfWay::GiveWay;
  }
  else if (source.compare("has_way") == 0)
  {
    return RightOfWay::HasWay;
  }
  else if (source.compare("priority_to_right") == 0)
  {
    return RightOfWay::PriorityToRight;
  }
  else if (source.compare("all_way_stop") == 0)
  {
    return RightOfWay::AllWayStop;
  }
  else if (source.compare("crosswalk") == 0)
  {
    return RightOfWay::Crosswalk;
  }
  else if (source.compare("ramp") == 0)
  {
    return RightOfWay::Ramp;
  }
  else
  {
    return RightOfWay::Undefined;
  }
}

std::string rowToString(RightOfWay const row)
{
  switch (row)
  {
    case RightOfWay::Stop:
      return std::string("stop");
    case RightOfWay::GiveWay:
      return std::string("give_way");
    case RightOfWay::HasWay:
      return std::string("has_way");
    case RightOfWay::PriorityToRight:
      return std::string("priority_to_right");
    case RightOfWay::AllWayStop:
      return std::string("all_way_stop");
    case RightOfWay::Crosswalk:
      return std::string("crosswalk");
    case RightOfWay::Ramp:
      return std::string("ramp");
    default:
      return std::string("undefined");
  }
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
