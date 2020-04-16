// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/CoordinateTransform.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <osmium/geom/mercator_projection.hpp>
#pragma GCC diagnostic pop

namespace ad {
namespace map {
namespace maker {
namespace geometry {

CoordinateTransform::CoordinateTransform(double latRef, double lonRef)
  : mLatReference(latRef)
  , mLonReference(lonRef)
  , mScale(std::cos(latRef * M_PI / 180.0))
  , mXReference(osmium::geom::detail::lon_to_x(lonRef) * mScale)
  , mYReference(osmium::geom::detail::lat_to_y(latRef) * mScale)
{
}

void CoordinateTransform::gcsToMetric(double const latitude, double const longitude, double &x, double &y) const
{
  double const xAbs = osmium::geom::detail::lon_to_x(longitude) * mScale;
  double const yAbs = osmium::geom::detail::lat_to_y(latitude) * mScale;

  x = xAbs - mXReference;
  y = yAbs - mYReference;
}

void CoordinateTransform::metricToGcs(double const x, double const y, double &latitude, double &longitude) const
{
  double const xAbs = (mXReference + x) / mScale;
  double const yAbs = (mYReference + y) / mScale;

  latitude = osmium::geom::detail::y_to_lat(yAbs);
  longitude = osmium::geom::detail::x_to_lon(xAbs);
}

double CoordinateTransform::lateralReference() const
{
  return mLatReference;
}

double CoordinateTransform::longitudeReference() const
{
  return mLonReference;
}

double CoordinateTransform::xReference() const
{
  return mXReference;
}

double CoordinateTransform::yReference() const
{
  return mYReference;
}

double CoordinateTransform::scale() const
{
  return mScale;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
