// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/**
 * @brief Convert between GCS and metric (WGS84/mercator) coordinates
 *
 * Replicates functionality from liblanelet such that the derived
 * coordinates are scaled based on the latitude of the reference point
 *
 * Encapsulates calls to the mercator_projection of libosmium
 */
class CoordinateTransform
{
public:
  //! reference coordinates are in degree!
  explicit CoordinateTransform(double latRef, double lonRef);

  double lateralReference() const;
  double longitudeReference() const;
  double xReference() const;
  double yReference() const;
  double scale() const;

  /**
   * @brief convert given WGS84 coordinate to metric coordinate (relative to reference point)
   */
  void gcsToMetric(double const latitude, double const longitude, double &x, double &y) const;

  /**
   * @brief convert given metric coordinate (relative to reference point) to WGS84 coordinate
   */
  void metricToGcs(double const x, double const y, double &latitude, double &longitude) const;

private:
  double mLatReference{}; // angle in degree (decimal degrees), northing
  double mLonReference{}; // angle in degree (decimal degrees), easting
  double mScale{};        // the scaling factor based on the reference latitude
  double mXReference{};   // Origin of coordinate system expressed as Mercator coordinate in [m]
  double mYReference{};   // Origin of coordinate system expressed as Mercator coordinate in [m]
};

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
