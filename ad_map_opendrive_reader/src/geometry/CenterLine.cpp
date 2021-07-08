/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#include "opendrive/geometry/CenterLine.hpp"
#include <boost/array.hpp>
#include <boost/math/tools/rational.hpp>
#include <cmath>
#include <iostream>
#include <spdlog/spdlog.h>
#include "opendrive/geometry/GeometryGenerator.hpp"
#include "opendrive/geometry/LaneUtils.hpp"

namespace opendrive {
namespace geometry {

double laneHeight(ElevationProfileSet const &elevationSet, double s)
{
  return evalPoly3(elevationSet, s);
}

geometry::DirectedPoint CenterLine::eval(double s, bool applyLateralOffset) const
{
  if (s < 0.)
  {
    // as the curve is only defined betwen the range [0 , length], we return the line evaluated at s = 0
    return eval(0.);
  }

  for (auto it = geometry.rbegin(); it != geometry.rend(); it++)
  {
    if (s >= (*it)->GetStartOffset())
    {
      auto directedPoint = (*it)->PosFromDist(s - (*it)->GetStartOffset());

      // This is parametrized as the landmarks positions do not take into account the lateral offset
      if (applyLateralOffset)
      {
        directedPoint.ApplyLateralOffset(calculateOffset(s));
      }

      directedPoint.location.z = laneHeight(elevation, s);
      return directedPoint;
    }
  }

  auto &lastGeometry = geometry.back();
  auto directed_point = lastGeometry->PosFromDist(s - lastGeometry->GetStartOffset());
  directed_point.location.z = laneHeight(elevation, s);
  return directed_point;
}

std::list<double> CenterLine::samplingPoints() const
{
  std::list<double> points;

  points.push_back(length);

  for (auto it = geometry.rbegin(); it != geometry.rend(); it++)
  {
    if ((*it)->GetType() == ::opendrive::GeometryType::ARC)
    {
      auto arc = static_cast<::opendrive::geometry::GeometryArc *>((*it).get());
      double theta = fabs(arc->GetCurvature()) * (*it)->GetLength();

      if (theta < 1e-2)
      {
        points.insert(points.begin(), (*it)->GetStartOffset() + 0.5 * (*it)->GetLength());
      }
      else
      {
        double c = fabs(arc->GetCurvature());
        double dsmax = 2.0 / c * acos(1.0 - c * Geometry::cMaxSamplingError);
        int segments = static_cast<int>((*it)->GetLength() / dsmax);
        for (auto k = segments - 1; k > 0; --k)
        {
          double r = static_cast<double>(k) / static_cast<double>(segments);
          points.insert(points.begin(), (*it)->GetStartOffset() + r * (*it)->GetLength());
        }
      }
    }
    else
    {
      // only start and end point for now
    }

    points.insert(points.begin(), (*it)->GetStartOffset());
  }

  auto const maxErrorSquared = Geometry::cMaxSamplingError * Geometry::cMaxSamplingError;
  // now refine sampling points according to actual points influenced by lateralOffset and elevation
  auto iter = points.begin();
  while (iter != points.end())
  {
    auto nextIter = iter;
    nextIter++;
    if (nextIter == points.end())
    {
      break;
    }
    auto const startPosition = *iter;
    auto const endPosition = *nextIter;
    if (endPosition - startPosition < Geometry::cMaxSamplingError)
    {
      // sampling below the maxError longitudinal distance makes no sense
      ++iter;
      continue;
    }
    auto const centerPosition = 0.5 * startPosition + 0.5 * endPosition;

    auto const start = eval(startPosition).location;
    auto const end = eval(endPosition).location;
    auto const centerLinearInterpolated = 0.5 * start + 0.5 * end;
    auto const centerActual = eval(centerPosition).location;
    auto errorSquared = (centerActual - centerLinearInterpolated).normSquared();
    if (errorSquared > maxErrorSquared)
    {
      points.insert(nextIter, centerPosition);
    }
    else
    {
      iter++;
    }
  }

  return points;
}

double CenterLine::calculateOffset(double s) const
{
  return evalPoly3(laneOffsetSet, s);
}

bool generateCenterLine(RoadInformation &roadInfo, CenterLine &centerLine)
{
  bool ok = true;

  centerLine.geometry.clear();
  centerLine.length = roadInfo.attributes.length;
  centerLine.laneOffsetSet = roadInfo.lanes.lane_offset;
  centerLine.elevation = roadInfo.road_profiles.elevation_profile;

  // Add geometry information
  for (auto &geometry_attribute : roadInfo.geometry_attributes)
  {
    Point start(
      geometry_attribute->start_position_x, geometry_attribute->start_position_y, geometry_attribute->start_position_z);

    try
    {
      switch (geometry_attribute->type)
      {
        case ::opendrive::GeometryType::ARC:
        {
          auto arc = static_cast<GeometryAttributesArc *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(std::make_unique<geometry::GeometryArc>(
            arc->start_position, arc->length, arc->heading, start, arc->curvature));
          break;
        }
        case ::opendrive::GeometryType::LINE:
        {
          auto line = static_cast<GeometryAttributesLine *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(
            std::make_unique<geometry::GeometryLine>(line->start_position, line->length, line->heading, start));
          break;
        }
        break;
        case ::opendrive::GeometryType::SPIRAL:
        {
          // currently not yet supported
          spdlog::error("generateCenterLine() spirals are currently not supported yet");
          ok = false;
          break;
        }
        break;
        case ::opendrive::GeometryType::POLY3:
        {
          auto poly3 = static_cast<GeometryAttributesPoly3 *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(std::make_unique<geometry::GeometryPoly3>(
            poly3->start_position, poly3->length, poly3->heading, start, poly3->a, poly3->b, poly3->c, poly3->d));
          break;
        }
        break;
        case ::opendrive::GeometryType::PARAMPOLY3:
        {
          auto paramPoly3 = static_cast<GeometryAttributesParamPoly3 *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(
            std::make_unique<geometry::GeometryParamPoly3>(paramPoly3->start_position,
                                                           paramPoly3->length,
                                                           paramPoly3->heading,
                                                           start,
                                                           paramPoly3->aU,
                                                           paramPoly3->bU,
                                                           paramPoly3->cU,
                                                           paramPoly3->dU,
                                                           paramPoly3->aV,
                                                           paramPoly3->bV,
                                                           paramPoly3->cV,
                                                           paramPoly3->dV,
                                                           paramPoly3->p_range == "normalized"));
          break;
        }
        break;
        default:
          break;
      }
    }
    catch (...)
    {
      spdlog::error("generateCenterLine() Invalid geometry definition");
      ok = false;
    }
  }

  return ok;
}
} // namespace geometry
} // namespace opendrive
