// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include "SyntheticIntersectionTestBase.hpp"

namespace ad {
namespace map {

struct IntersectionTown01WestToSouthTest : virtual SyntheticIntersectionTestBase
{
  virtual point::GeoPoint getGeoFromSouth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00490650359), point::Latitude(49.0000165612), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToSouth() const override
  {
    return point::createGeoPoint(point::Longitude(8.0048934219), point::Latitude(48.9999830507), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromWest() const override
  {
    return point::createGeoPoint(point::Longitude(8.00462843722), point::Latitude(48.9997976038), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToWest() const override
  {
    return point::createGeoPoint(point::Longitude(8.0045717552), point::Latitude(48.9997433894), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromNorth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00424859652), point::Latitude(48.9999829343), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoToNorth() const override
  {
    return point::createGeoPoint(point::Longitude(8.00423629191), point::Latitude(49.0000237813), point::Altitude(0));
  }

  virtual point::GeoPoint getGeoFromEast() const override
  {
    return point::GeoPoint();
  }

  virtual point::GeoPoint getGeoToEast() const override
  {
    return point::GeoPoint();
  }
};

} // namespace map
} // namespace ad
