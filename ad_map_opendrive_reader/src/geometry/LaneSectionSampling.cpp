/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2021-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */
#include "opendrive/geometry/LaneSectionSampling.hpp"
#include <boost/math/tools/rational.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include "opendrive/geometry/LaneUtils.hpp"

namespace opendrive {
namespace geometry {

double laneWidth(LaneWidthSet const &laneWidthSet, double s)
{
  return evalPoly3(laneWidthSet, s);
}

double laneSuperelevation(LateralProfileSuperelevationSet const &superelevationProfiles, double s)
{
  return evalPoly3(superelevationProfiles, s);
}

double laneShapeHeightEval(std::pair<std::map<double, std::set<LateralProfileShape>>::const_iterator,
                                     std::map<double, std::set<LateralProfileShape>>::const_iterator> bounds,
                           double s,
                           double t)
{
  auto const sr1 = bounds.first->first;
  auto const h_sr1 = evalPoly3(bounds.first->second, t);
  auto const sr2 = bounds.second->first;
  auto const h_sr2 = evalPoly3(bounds.second->second, t);
  auto h_s = (h_sr1 + h_sr2) * (s - sr1) / (sr2 - sr1);
  return h_s;
}

std::pair<std::map<double, std::set<LateralProfileShape>>::const_iterator,
          std::map<double, std::set<LateralProfileShape>>::const_iterator>
laneShapeHeightBounds(std::map<double, std::set<LateralProfileShape>> const &shapeProfile, double s)
{
  auto upperBound = shapeProfile.upper_bound(s);
  auto lowerBound = upperBound;
  if (lowerBound != shapeProfile.begin())
  {
    lowerBound--;
  }
  return {lowerBound, upperBound};
}

void normalizeEdge(Id const id, std::string const &what, Edge &edge)
{
  if (edge.size() <= 2u)
  {
    // if edge only consists of 2 points we could only remove the whole edge in case the points are too near to each
    // other
    return;
  }
  std::size_t pointsToDrop = 0u;
  Point previousEdgeDir(0., 0., 0.);
  for (std::size_t i = 1u; i < edge.size(); ++i)
  {
    // i-pointsToDrop > 0
    if (pointsToDrop > 0u)
    {
      edge[i - pointsToDrop] = edge[i];
    }
    // last point must not be dropped
    if (i < edge.size() - 1)
    {
      // eliminate z-component from normalization
      auto from = edge[i - pointsToDrop];
      from.z = 0;
      auto to = edge[i - pointsToDrop - 1];
      to.z = 0;
      if (from == to)
      {
        // drop identical points
        spdlog::trace("normalizeEdge {} dropping identical point from {} edge at index {}", id, what, i);
        pointsToDrop++;
      }
      else
      {
        //  moving the middle line in a narrow curve often leads to artifacts (circles) which are removed by the below
        auto nextEdgeDir = from - to;
        if (previousEdgeDir != Point(0., 0., 0.))
        {
          auto dotProduct = previousEdgeDir.dot(nextEdgeDir);
          if (dotProduct < 0.)
          {
            spdlog::trace("normalizeEdge {} extreme direction changing point from {} edge at index {}", id, what, i);
            pointsToDrop++;
          }
          else
          {
            previousEdgeDir = nextEdgeDir;
          }
        }
        else
        {
          previousEdgeDir = nextEdgeDir;
        }
      }
    }
  }
  if (pointsToDrop > 0u)
  {
    std::size_t const newEdgeSize = std::max(std::size_t(2u), edge.size() - pointsToDrop);
    spdlog::trace("normalizeEdge {} dropping points from {} edge {} remaining {}", id, what, pointsToDrop, newEdgeSize);
    edge.resize(newEdgeSize, Point(0., 0., 0.));
  }
}

void LaneSectionSampling::generateSamples()
{
  try
  {
    auto samplingPoints = centerLine.samplingPoints();

    for (uint64_t i = 0u; i < roadInfo.lanes.lane_sections.size(); i++)
    {
      uint64_t laneSectionIndex = i + 1u;
      addSamples(roadInfo.lanes.lane_sections[i], laneSectionIndex, samplingPoints);
    }
  }
  catch (...)
  {
    spdlog::error("LaneSectionSampling::generateSamples exception in road {}", roadInfo.attributes.id);
  }
}

bool LaneSectionSampling::addSamples(LaneSection const &laneSection,
                                     uint64_t const &laneSectionIndex,
                                     std::list<double> const &laneSamplingPoints)
{
  bool ok = true;
  double s0 = laneSection.start_position;
  double s1 = laneSection.end_position;
  if (std::fabs(s1 - laneSamplingPoints.back()) > Point::cCoordinateTolerance)
  {
    // the tolerance at the end of the lane sections is necessary so that the lane offset applies only to the current
    // lane section
    s1 -= 1e-12;
  }

  if (s1 < s0)
  {
    spdlog::error("Invalid lane section length {} {}", s1, s0);
    ok = false;
  }

  auto inRange = [&s0, &s1](double const &s) { return (s < s1) && (s > s0); };

  std::list<double> localSamplingPoints;
  localSamplingPoints.push_back(s0);
  std::copy_if(laneSamplingPoints.begin(), laneSamplingPoints.end(), std::back_inserter(localSamplingPoints), inRange);
  localSamplingPoints.push_back(s1);

  std::list<LaneSectionProfile> newProfiles;
  for (auto localSamplingPoint : localSamplingPoints)
  {
    auto profile = evalProfile(laneSection, laneSectionIndex, localSamplingPoint);
    if (!profile.laneBorderPoints.empty())
    {
      newProfiles.push_back(profile);
    }
    else
    {
      spdlog::warn("LaneSectionSampling::addSamples: Skipping empty profile {},{}: {} [{},{}]",
                   roadInfo.attributes.id,
                   laneSectionIndex,
                   localSamplingPoint,
                   laneSection.start_position,
                   laneSection.end_position);
    }
  }

  // now refine sampling points according to actual points influenced by laneWidth changes and lateral_profile
  auto iter = newProfiles.begin();
  while (iter != newProfiles.end())
  {
    auto nextIter = iter;
    nextIter++;
    if (nextIter == newProfiles.end())
    {
      break;
    }
    if (nextIter->sLane - iter->sLane < Geometry::cMaxSamplingError)
    {
      // sampling below the Geometry::cMaxSamplingError longitudinal distance makes no sense
      ++iter;
      continue;
    }
    auto const centerLinearInterpolated = interpolateProfile(*iter, *nextIter);
    auto centerActual = evalProfile(laneSection, laneSectionIndex, centerLinearInterpolated.sLane);
    if (centerActual.laneBorderPoints.empty())
    {
      spdlog::warn("LaneSectionSampling::addSamples: Skipping empty refinement {},{}: [{}->{}<-{}] [{},{}]",
                   roadInfo.attributes.id,
                   laneSectionIndex,
                   iter->sLane,
                   centerLinearInterpolated.sLane,
                   nextIter->sLane,
                   laneSection.start_position,
                   laneSection.end_position);
      iter++;
    }
    else
    {
      centerActual.dropPointsWithAcceptedError(centerLinearInterpolated);
      if (!centerActual.laneBorderPoints.empty())
      {
        newProfiles.insert(nextIter, centerActual);
      }
      else
      {
        iter++;
      }
    }
  }

  profiles.insert(profiles.end(), newProfiles.begin(), newProfiles.end());
  return ok;
}

LaneSectionSampling::LaneSectionProfile
LaneSectionSampling::evalProfile(LaneSection const &laneSection, uint64_t const &laneSectionIndex, double const &s)
{
  LaneSectionProfile profile;
  profile.sLane = s;
  auto const sLaneSection = s - laneSection.start_position;
  if (s < laneSection.start_position)
  {
    spdlog::warn("LaneSectionSampling::evalProfile: Lane section start position not yet reached {},{}: {} [{},{}]",
                 roadInfo.attributes.id,
                 laneSectionIndex,
                 s,
                 laneSection.start_position,
                 laneSection.end_position);
    return profile;
  }
  if (s > laneSection.end_position)
  {
    spdlog::warn("LaneSectionSampling::evalProfile: Lane section end position already passed {},{}: {} [{},{}]",
                 roadInfo.attributes.id,
                 laneSectionIndex,
                 s,
                 laneSection.start_position,
                 laneSection.end_position);
    return profile;
  }
  auto const centerPoint = centerLine.eval(s);

  LaneHeight laneHeightSearch;
  laneHeightSearch.start_offset = sLaneSection;

  auto const laneShapeBounds = laneShapeHeightBounds(roadInfo.road_profiles.lateral_profile_shape, s);
  bool const laneShapeBoundsAvailable
    = (laneShapeBounds.first != roadInfo.road_profiles.lateral_profile_shape.end()
       && laneShapeBounds.second != roadInfo.road_profiles.lateral_profile_shape.end());

  auto const angle = laneSuperelevation(roadInfo.road_profiles.lateral_profile_superelevation, s);
  auto const cos_angle = cos(angle);
  auto const sin_angle = sin(angle);

  double t = 0.;
  // store the shift of the outer superelevation operation to be applied to lanes kept at level
  Point superelevationShiftOuterPoint;
  for (auto &laneInfo : laneSection.left)
  {
    auto width = laneWidth(laneInfo.lane_width, sLaneSection);
    LaneBorderPoint point;
    auto const rightT = t;
    auto const leftT = t + width;
    auto const id = laneId(roadInfo.attributes.id, laneSectionIndex, laneInfo.attributes.id);
    try
    {
      // apply lane width
      point.rightEdgePoint = centerPoint.getLateralOffsetPoint(rightT);
      point.leftEdgePoint = centerPoint.getLateralOffsetPoint(leftT);

      // apply lane height
      auto laneHeightIter = laneInfo.lane_height.lower_bound(laneHeightSearch);
      if (laneHeightIter != laneInfo.lane_height.end())
      {
        point.rightEdgePoint.z += laneHeightIter->inner;
        point.leftEdgePoint.z += laneHeightIter->outer;
      }
      if (laneInfo.attributes.level)
      {
        // keep on level: no shape, superelevation level of last outer lane
        point.rightEdgePoint = point.rightEdgePoint + superelevationShiftOuterPoint;
        point.leftEdgePoint = point.leftEdgePoint + superelevationShiftOuterPoint;
      }
      else
      {
        if (laneShapeBoundsAvailable)
        {
          point.rightEdgePoint.z += laneShapeHeightEval(laneShapeBounds, s, rightT);
          point.leftEdgePoint.z += laneShapeHeightEval(laneShapeBounds, s, leftT);
        }

        point.rightEdgePoint
          = calculateSuperelevatedPoint(point.rightEdgePoint, rightT, centerPoint, cos_angle, sin_angle);
        auto const outerPoint
          = calculateSuperelevatedPoint(point.leftEdgePoint, leftT, centerPoint, cos_angle, sin_angle);
        superelevationShiftOuterPoint = outerPoint - point.leftEdgePoint;
        point.leftEdgePoint = outerPoint;
      }
      profile.laneBorderPoints[id] = point;
      t += width;

      point.leftEdgePoint.ensureValid();
      point.rightEdgePoint.ensureValid();
    }
    catch (...)
    {
      spdlog::warn("LaneSectionSampling::evalProfile: Invalid lane point {}:{}({}) ({},{},{})",
                   id,
                   s,
                   sLaneSection,
                   angle,
                   width,
                   t);
    }
  }

  // right lanes
  t = 0.;
  superelevationShiftOuterPoint = Point();
  for (auto &laneInfo : laneSection.right)
  {
    auto width = laneWidth(laneInfo.lane_width, sLaneSection);
    LaneBorderPoint point;
    const auto leftT = t;
    const auto rightT = t - width;
    auto const id = laneId(roadInfo.attributes.id, laneSectionIndex, laneInfo.attributes.id);

    try
    {
      // apply lane width
      point.leftEdgePoint = centerPoint.getLateralOffsetPoint(leftT);
      point.rightEdgePoint = centerPoint.getLateralOffsetPoint(rightT);

      // apply lane height
      auto laneHeightIter = laneInfo.lane_height.lower_bound(laneHeightSearch);
      if (laneHeightIter != laneInfo.lane_height.end())
      {
        point.leftEdgePoint.z += laneHeightIter->inner;
        point.rightEdgePoint.z += laneHeightIter->outer;
      }

      if (laneInfo.attributes.level)
      {
        // keep on level: no shape, superelevation level of last outer lane
        point.leftEdgePoint = point.leftEdgePoint + superelevationShiftOuterPoint;
        point.rightEdgePoint = point.rightEdgePoint + superelevationShiftOuterPoint;
      }
      else
      {
        if (laneShapeBoundsAvailable)
        {
          point.leftEdgePoint.z += laneShapeHeightEval(laneShapeBounds, s, leftT);
          point.rightEdgePoint.z += laneShapeHeightEval(laneShapeBounds, s, rightT);
        }

        point.leftEdgePoint
          = calculateSuperelevatedPoint(point.leftEdgePoint, leftT, centerPoint, cos_angle, sin_angle);
        auto const outerPoint
          = calculateSuperelevatedPoint(point.rightEdgePoint, rightT, centerPoint, cos_angle, sin_angle);
        superelevationShiftOuterPoint = outerPoint - point.rightEdgePoint;
        point.rightEdgePoint = outerPoint;
      }

      profile.laneBorderPoints[id] = point;
      t -= width;

      point.leftEdgePoint.ensureValid();
      point.rightEdgePoint.ensureValid();
    }
    catch (...)
    {
      spdlog::warn("LaneSectionSampling::evalProfile: Invalid lane point {}:{}({}) ({},{},{})",
                   id,
                   s,
                   sLaneSection,
                   angle,
                   width,
                   t);
    }
  }

  return profile;
}

Point LaneSectionSampling::calculateSuperelevatedPoint(
  Point const &point, double t, DirectedPoint const &centerPoint, double const cos_angle, double const sin_angle)
{
  Point resultPoint;
  resultPoint.x = centerPoint.location.x + cos_angle * (point.x - centerPoint.location.x);
  resultPoint.y = centerPoint.location.y + cos_angle * (point.y - centerPoint.location.y);
  resultPoint.z = point.z + sin_angle * t;
  return resultPoint;
}

LaneSectionSampling::LaneSectionProfile LaneSectionSampling::interpolateProfile(LaneSectionProfile const &start,
                                                                                LaneSectionProfile const &end)
{
  LaneSectionProfile profile;
  profile.sLane = 0.5 * (start.sLane + end.sLane);
  try
  {
    for (auto const &startLaneBorderPoint : start.laneBorderPoints)
    {
      auto const findEnd = end.laneBorderPoints.find(startLaneBorderPoint.first);
      if (findEnd != end.laneBorderPoints.end())
      {
        LaneBorderPoint point;
        point.rightEdgePoint = 0.5 * (startLaneBorderPoint.second.rightEdgePoint + findEnd->second.rightEdgePoint);
        point.leftEdgePoint = 0.5 * (startLaneBorderPoint.second.leftEdgePoint + findEnd->second.leftEdgePoint);
        point.rightEdgePoint.ensureValid();
        point.leftEdgePoint.ensureValid();
        profile.laneBorderPoints[startLaneBorderPoint.first] = point;
      }
    }
  }
  catch (...)
  {
    spdlog::warn("LaneSectionSampling::interpolateProfile: exception {} ({}->{}<-{})",
                 roadInfo.attributes.id,
                 start.sLane,
                 profile.sLane,
                 end.sLane);
  }
  return profile;
}

void LaneSectionSampling::LaneSectionProfile::dropPointsWithAcceptedError(
  LaneSectionSampling::LaneSectionProfile const &other)
{
  auto const maxErrorSquared = Geometry::cMaxSamplingError * Geometry::cMaxSamplingError;
  try
  {
    auto iter = laneBorderPoints.begin();
    while (iter != laneBorderPoints.end())
    {
      auto const findOther = other.laneBorderPoints.find(iter->first);
      if (findOther != other.laneBorderPoints.end())
      {
        auto errorSquaredLeft = (iter->second.leftEdgePoint - findOther->second.leftEdgePoint).normSquared();
        auto errorSquaredRight = (iter->second.rightEdgePoint - findOther->second.rightEdgePoint).normSquared();
        if ((errorSquaredLeft >= maxErrorSquared) || (errorSquaredRight >= maxErrorSquared))
        {
          // error too big, keep the point
          ++iter;
          continue;
        }
      }
      // either error acceptable or
      // the lane was already identified as acceptable before and is therefore not present anymore in the interpolated
      // other
      iter = laneBorderPoints.erase(iter);
    }
  }
  catch (...)
  {
    spdlog::warn("LaneSectionSampling::dropPointsWithAcceptedError: exception ({}<->{})", sLane, other.sLane);
  }
}

void LaneSectionSampling::writeLaneMap(LaneMap &laneMap)
{
  std::set<Id> lanesToProcess;
  for (auto const &profile : profiles)
  {
    for (auto const &laneBorderPoint : profile.laneBorderPoints)
    {
      laneMap[laneBorderPoint.first].leftEdge.push_back(laneBorderPoint.second.leftEdgePoint);
      laneMap[laneBorderPoint.first].rightEdge.push_back(laneBorderPoint.second.rightEdgePoint);
      lanesToProcess.insert(laneBorderPoint.first);
    }
  }

  for (auto &lane : laneMap)
  {
    if (lanesToProcess.count(lane.first) > 0u)
    {
      normalizeEdge(lane.first, "left", lane.second.leftEdge);
      normalizeEdge(lane.first, "right", lane.second.rightEdge);
    }
  }
}

} // namespace geometry
} // namespace opendrive
