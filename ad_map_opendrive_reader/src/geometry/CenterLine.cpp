/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2019-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#include "opendrive/geometry/CenterLine.hpp"
#include <algorithm>
#include <boost/math/tools/rational.hpp>
#include <cmath>
#include <iostream>
#include <spdlog/spdlog.h>
#include "opendrive/geometry/ArrayType.hpp"
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
  if (geometry.empty())
  {
    return DirectedPoint();
  }
  if (s < 0.)
  {
    // as the curve is only defined between the range [0 , length], we return the line evaluated at s = 0
    return eval(0., applyLateralOffset);
  }

  auto it = std::upper_bound(
    geometry.begin(), geometry.end(), s, [](double value, std::unique_ptr<geometry::Geometry> const &elem) {
      return value < elem->GetStartOffset();
    });
  if (it != geometry.begin())
  {
    --it;
  }

  auto directedPoint = (*it)->PosFromDist(s - (*it)->GetStartOffset());

  // This is parametrized as the landmarks positions do not take into account the lateral offset
  if (applyLateralOffset)
  {
    directedPoint.ApplyLateralOffset(calculateOffset(s));
  }

  directedPoint.location.z = laneHeight(elevation, s);
  return directedPoint;
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
        double cosArg = std::max(-1.0, std::min(1.0, 1.0 - c * Geometry::cMaxSamplingError));
        double dsmax = 2.0 / c * acos(cosArg);
        if (dsmax > 0.)
        {
          int segments = static_cast<int>((*it)->GetLength() / dsmax);
          for (auto k = segments - 1; k > 0; --k)
          {
            double r = static_cast<double>(k) / static_cast<double>(segments);
            points.insert(points.begin(), (*it)->GetStartOffset() + r * (*it)->GetLength());
          }
        }
      }
    }
    else
    {
      // only start and end point for now
    }

    points.insert(points.begin(), (*it)->GetStartOffset());
  }

  std::list<Point> pointLocations;
  for (double const s : points)
  {
    pointLocations.push_back(eval(s).location);
  }

  auto const maxErrorSquared = Geometry::cMaxSamplingError * Geometry::cMaxSamplingError;
  // now refine sampling points according to actual points influenced by lateralOffset and elevation
  auto iter = points.begin();
  auto locIter = pointLocations.begin();
  while (iter != points.end())
  {
    auto nextIter = std::next(iter);
    if (nextIter == points.end())
    {
      break;
    }
    auto nextLocIter = std::next(locIter);
    auto const startPosition = *iter;
    auto const endPosition = *nextIter;
    if (endPosition - startPosition < Geometry::cMaxSamplingError)
    {
      // sampling below the maxError longitudinal distance makes no sense
      ++iter;
      ++locIter;
      continue;
    }
    auto const centerPosition = 0.5 * startPosition + 0.5 * endPosition;
    auto const centerLinearInterpolated = 0.5 * (*locIter) + 0.5 * (*nextLocIter);
    auto const centerActual = eval(centerPosition).location;
    auto errorSquared = (centerActual - centerLinearInterpolated).normSquared();
    if (errorSquared > maxErrorSquared)
    {
      points.insert(nextIter, centerPosition);
      pointLocations.insert(nextLocIter, centerActual);
    }
    else
    {
      ++iter;
      ++locIter;
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
        case ::opendrive::GeometryType::SPIRAL:
        {
          auto spiral = static_cast<GeometryAttributesSpiral *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(std::make_unique<geometry::GeometrySpiral>(
            spiral->start_position, spiral->length, spiral->heading, start, spiral->curve_start, spiral->curve_end));
          break;
        }
        case ::opendrive::GeometryType::POLY3:
        {
          auto poly3 = static_cast<GeometryAttributesPoly3 *>(geometry_attribute.get());
          centerLine.geometry.emplace_back(std::make_unique<geometry::GeometryPoly3>(
            poly3->start_position, poly3->length, poly3->heading, start, poly3->a, poly3->b, poly3->c, poly3->d));
          break;
        }
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

  std::stable_sort(centerLine.geometry.begin(),
                   centerLine.geometry.end(),
                   [](std::unique_ptr<geometry::Geometry> const &lhs, std::unique_ptr<geometry::Geometry> const &rhs) {
                     return lhs->GetStartOffset() < rhs->GetStartOffset();
                   });

  return ok;
}
} // namespace geometry
} // namespace opendrive
