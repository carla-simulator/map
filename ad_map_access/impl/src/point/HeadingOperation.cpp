// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/point/HeadingOperation.hpp"
#include <ad/map/point/ECEFOperation.hpp>

#include <cmath>

#include "ad/map/access/Operation.hpp"
#include "ad/map/point/ENUOperation.hpp"
#include "ad/map/point/Transform.hpp"

namespace ad {
namespace map {
namespace point {

ECEFHeading createECEFHeading(ECEFPoint const &start, ECEFPoint const &end)
{
  ECEFPoint const heading = vectorNorm(end - start);
  ECEFHeading result;
  result.x = heading.x;
  result.y = heading.y;
  result.z = heading.z;
  return result;
}

ECEFHeading createECEFHeading(ENUHeading const &yaw, GeoPoint const &enuReferencePoint)
{
  ECEFPoint const start = toECEF(enuReferencePoint);
  ENUPoint const enuEndPoint = getDirectionalVectorZPlane(yaw);
  ECEFPoint const end = toECEF(enuEndPoint, enuReferencePoint);
  return createECEFHeading(start, end);
}

double normalizeAngle(double yaw)
{
  double normalizedAngle = std::fmod(yaw + static_cast<double>(M_PI), 2. * static_cast<double>(M_PI));
  if (normalizedAngle <= 0)
  {
    normalizedAngle += static_cast<double>(M_PI);
  }
  else
  {
    normalizedAngle -= static_cast<double>(M_PI);
  }
  return normalizedAngle;
}

ENUHeading normalizeENUHeading(ENUHeading const &heading)
{
  return ENUHeading(normalizeAngle(static_cast<double>(heading)));
}

ENUHeading createENUHeading(double yawAngleRadian)
{
  return ENUHeading(normalizeAngle(yawAngleRadian));
}

ENUHeading createENUHeading(ECEFHeading const &ecefHeading)
{
  return createENUHeading(ecefHeading, access::getENUReferencePoint());
}

ENUHeading createENUHeading(ECEFHeading const &ecefHeading, ECEFPoint const &enuReferencePoint)
{
  return createENUHeading(ecefHeading, toGeo(enuReferencePoint));
}

ENUHeading createENUHeading(ECEFHeading const &ecefHeading, GeoPoint const &enuReferencePoint)
{
  ECEFPoint const enuZero = toECEF(enuReferencePoint);
  ECEFPoint const enuEastAxis = toECEF(getEnuEastAxis(), enuReferencePoint);
  ECEFPoint const enuUpAxis = toECEF(getEnuUpAxis(), enuReferencePoint);

  ECEFHeading const toEast = createECEFHeading(enuZero, enuEastAxis);
  ECEFHeading const toUp = createECEFHeading(enuZero, enuUpAxis);

  double const cosHeading = vectorDotProduct(toEast, ecefHeading);

  ECEFHeading const crossProductVector(vectorCrossProduct(toEast, ecefHeading));
  double const sinHeadingAbs = static_cast<double>(vectorLength(crossProductVector));

  // determine the sign of sine
  ENUHeading result;
  if (std::signbit(vectorDotProduct(crossProductVector, toUp)))
  {
    result = ENUHeading(std::atan2(-sinHeadingAbs, cosHeading));
  }
  else
  {
    result = ENUHeading(std::atan2(sinHeadingAbs, cosHeading));
  }
  // atan2 seems to allow -M_PI, so normalize that one
  if (result == ENUHeading(-M_PI))
  {
    result = ENUHeading(M_PI);
  }
  return result;
}

} // namespace point
} // namespace map
} // namespace ad
