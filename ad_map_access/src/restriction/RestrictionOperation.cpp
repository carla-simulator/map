// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/restriction/RestrictionOperation.hpp"

#include <algorithm>

namespace ad {
namespace map {
namespace restriction {

bool isAccessOk(Restriction const &restriction, VehicleDescriptor const &vehicle)
{
  if (!isValid(vehicle))
  {
    throw std::runtime_error("isAccessOk: vehicle invalid");
  }
  //* \todo Full implementation.
  if (vehicle.passengers < restriction.passengers_min)
  {
    return restriction.negated;
  }
  if (restriction.road_user_types.empty())
  {
    return !restriction.negated;
  }
  else
  {
    auto it = std::find(restriction.road_user_types.begin(), restriction.road_user_types.end(), vehicle.type);
    if (it != restriction.road_user_types.end())
    {
      return !restriction.negated;
    }
    else
    {
      return restriction.negated;
    }
  }
}

bool isAccessOk(Restrictions const &restrictions, VehicleDescriptor const &vehicle)
{
  //* \todo Improve implenentation based on more complex rules.
  if (restrictions.conjunctions.empty() && restrictions.disjunctions.empty())
  {
    return true;
  }
  else if (!restrictions.conjunctions.empty())
  {
    for (auto const &restriction : restrictions.conjunctions)
    {
      if (!isAccessOk(restriction, vehicle))
      {
        return false;
      }
    }
    return true;
  }
  else if (!restrictions.disjunctions.empty())
  {
    for (auto const &restriction : restrictions.disjunctions)
    {
      if (isAccessOk(restriction, vehicle))
      {
        return true;
      }
    }
    return false;
  }
  else
  {
    throw std::runtime_error("IsAccessOk: conjunctions and disjunctions invalid");
  }
}

PassengerCount getHOV(Restrictions const &restrictions)
{
  PassengerCount hov(0);
  for (auto const &conjunction : restrictions.conjunctions)
  {
    hov = std::max(hov, conjunction.passengers_min);
  }
  for (auto const &disjunction : restrictions.disjunctions)
  {
    hov = std::max(hov, disjunction.passengers_min);
  }
  return hov;
}

} // namespace restriction
} // namespace map
} // namespace ad
