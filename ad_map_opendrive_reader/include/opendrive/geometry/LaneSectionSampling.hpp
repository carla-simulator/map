/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#pragma once

#include <list>
#include <map>
#include "opendrive/geometry/CenterLine.hpp"
#include "opendrive/types.hpp"

namespace opendrive {
namespace geometry {

class LaneSectionSampling
{
public:
  LaneSectionSampling(RoadInformation const &roadInfo_, CenterLine const &centerLine_)
    : roadInfo(roadInfo_)
    , centerLine(centerLine_)
  {
  }

  void generateSamples();
  void writeLaneMap(LaneMap &laneMap);

private:
  struct LaneBorderPoint
  {
    Point leftEdgePoint;
    Point rightEdgePoint;
  };

  struct LaneSectionProfile
  {
    double sLane;
    std::map<Id, LaneBorderPoint> laneBorderPoints;

    void dropPointsWithAcceptedError(LaneSectionProfile const &other);
  };

  Point calculateSuperelevatedPoint(
    Point const &point, double t, DirectedPoint const &centerPoint, double const cos_angle, double const sin_angle);
  LaneSectionProfile evalProfile(LaneSection const &laneSection, uint64_t const &laneSectionIndex, double const &s);
  bool addSamples(LaneSection const &laneSection,
                  uint64_t const &laneSectionIndex,
                  std::list<double> const &laneSamplingPoints);
  LaneSectionProfile interpolateProfile(LaneSectionProfile const &start, LaneSectionProfile const &end);

  RoadInformation const &roadInfo;
  CenterLine const &centerLine;
  std::list<LaneSectionProfile> profiles;
};

} // namespace geometry
} // namespace opendrive
