// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/BoundingSphereOperation.hpp"

namespace ad {
namespace map {
namespace point {

void expandBounds(point::ECEFPoint &upperBound, point::ECEFPoint &lowerBound, point::ECEFPoint const &point)
{
  upperBound.x = std::max(upperBound.x, point.x);
  upperBound.y = std::max(upperBound.y, point.y);
  upperBound.z = std::max(upperBound.z, point.z);
  lowerBound.x = std::min(lowerBound.x, point.x);
  lowerBound.y = std::min(lowerBound.y, point.y);
  lowerBound.z = std::min(lowerBound.z, point.z);
}

point::BoundingSphere calcBoundingSphere(Geometry const &geometryLeft, Geometry const &geometryRight)
{
  point::BoundingSphere bounding_sphere;

  if (geometryLeft.ecef_points.empty() && geometryRight.ecef_points.empty())
  {
    return bounding_sphere;
  }

  point::ECEFPoint upperBound;
  point::ECEFPoint lowerBound;
  if (geometryLeft.ecef_points.empty())
  {
    upperBound = geometryRight.ecef_points.front();
  }
  else
  {
    upperBound = geometryLeft.ecef_points.front();
  }
  lowerBound = upperBound;

  for (auto const &point : geometryLeft.ecef_points)
  {
    expandBounds(upperBound, lowerBound, point);
  }
  for (auto const &point : geometryRight.ecef_points)
  {
    expandBounds(upperBound, lowerBound, point);
  }

  point::ECEFPoint const diagonalVector = upperBound - lowerBound;
  auto diagonalVectorLength = point::vectorLength(diagonalVector);

  bounding_sphere.radius = 0.5 * diagonalVectorLength;
  bounding_sphere.center = lowerBound + 0.5 * diagonalVector;

  return bounding_sphere;
}

} // namespace point
} // namespace map
} // namespace ad

::ad::map::point::BoundingSphere operator+(::ad::map::point::BoundingSphere const &a,
                                           ::ad::map::point::BoundingSphere const &b)
{
  ::ad::map::point::BoundingSphere result;
  ::ad::map::point::BoundingSphere const *small;
  ::ad::map::point::BoundingSphere const *large;
  if (a.radius < b.radius)
  {
    small = &a;
    large = &b;
  }
  else
  {
    small = &b;
    large = &a;
  }

  auto const fromLargeToSmallCenter = small->center - large->center;
  auto const sphereCenterDistance = ::ad::map::point::vectorLength(fromLargeToSmallCenter);

  // move the center of the larger sphere in direction of the smaller one
  // and increase the larger radius by the moving distance
  auto const displacement = 0.5 * (sphereCenterDistance - large->radius + small->radius);
  if (displacement <= ::ad::physics::Distance(0.))
  {
    // small is already within large
    result = *large;
  }
  else if (sphereCenterDistance == ::ad::physics::Distance(0.))
  {
    // tiny center distance
    result = *large;
  }
  else
  {
    result.center
      = large->center + ::ad::physics::Distance(displacement / sphereCenterDistance) * (fromLargeToSmallCenter);
    result.radius = large->radius + displacement;
  }
  return result;
}
