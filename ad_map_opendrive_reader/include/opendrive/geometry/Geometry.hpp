/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#pragma once

#include <boost/array.hpp>
#include <boost/math/tools/rational.hpp>
#include "opendrive/types.hpp"

namespace opendrive {
namespace geometry {

/**
 * @brief DirectedPoint is composed of a 3 dimensional position and an orientation
 */
struct DirectedPoint
{
  DirectedPoint();
  DirectedPoint(const Point &point, double t);
  DirectedPoint(double x, double y, double z, double t);

  Point location = {0, 0, 0};
  double tangent = 0.0; // [radians]

  static bool floatCompare(double f1, double f2)
  {
    static constexpr auto epsilon = 1.0e-09f;
    if (std::fabs(f1 - f2) <= epsilon)
      return true;
    return std::fabs(f1 - f2) <= epsilon * std::max(std::fabs(f1), std::fabs(f2));
  }

  /**
   * @brief Shifts the point by lateral_offset meters in the normal direction of the tangent
   */
  void ApplyLateralOffset(double lateral_offset);

  /**
   * @returns the point shifted by lateral_offset meters in the normal direction of the tangent
   */
  Point getLateralOffsetPoint(double lateral_offset) const;

  /**
   * @brief Compares two points, returns true if their parameters are identical
   */
  bool operator==(const DirectedPoint &lhs)
  {
    if ((lhs.location == location) && (floatCompare(lhs.tangent, tangent)))
    {
      return true;
    }
    return false;
  }
};

class Geometry
{
public:
  // max sampling error expected
  static constexpr double cMaxSamplingError = 5e-2;

  /**
   * @brief Returns the GeometryType associated to this geometry.
   */
  GeometryType GetType() const;

  /**
   * @brief Returns the length of the geometry.
   */
  double GetLength() const;

  /**
   * @brief Returns the start offset in s coordinates.
   */
  double GetStartOffset() const;

  /**
   * @brief Returns the heading at the start position.
   */
  double GetHeading() const;

  /**
   * @brief Returns the start position in the global reference frame.
   */
  const Point &GetStartPosition();

  virtual ~Geometry() = default;

  /**
   * @brief Evaluates the geometry at a certain distance from the start position.
   */
  virtual const DirectedPoint PosFromDist(double dist) const = 0;

protected:
  Geometry(GeometryType type, double start_offset, double length, double heading, const Point &start_pos);

protected:
  GeometryType _type; // geometry type
  double _length;     // length of the road section [meters]

  double _start_position_offset; // s-offset [meters]
  double _heading;               // start orientation [radians]

  Point _start_position; // [meters]
};

class GeometryLine : public Geometry
{
public:
  GeometryLine(double start_offset, double length, double heading, const Point &start_pos);

  const DirectedPoint PosFromDist(const double dist) const override;
};

class GeometryArc : public Geometry
{
public:
  GeometryArc(double start_offset, double length, double heading, const Point &start_pos, double curv);

  const DirectedPoint PosFromDist(double dist) const override;

  double GetCurvature() const;

private:
  double _curvature;
};

class GeometryPoly3 : public Geometry
{
public:
  GeometryPoly3(
    double start_offset, double length, double heading, const Point &start_pos, double a, double b, double c, double d);

  const DirectedPoint PosFromDist(const double dist) const override;

private:
  double _a;
  double _b;
  double _c;
  double _d;
};

class GeometryParamPoly3 : public Geometry
{
public:
  GeometryParamPoly3(double start_offset,
                     double length,
                     double heading,
                     const Point &start_pos,
                     double aU,
                     double bU,
                     double cU,
                     double dU,
                     double aV,
                     double bV,
                     double cV,
                     double dV,
                     bool p_range_is_normalized);

  const DirectedPoint PosFromDist(const double dist) const override;

private:
  double _aU;
  double _bU;
  double _cU;
  double _dU;
  double _aV;
  double _bV;
  double _cV;
  double _dV;
  bool _p_range_is_normalized;
};

template <class T> double evalPoly3(std::set<T> const &sOffsetPoly3Set, double s)
{
  T search;
  search.start_offset = s;
  auto smallerOrEqual = sOffsetPoly3Set.upper_bound(search);
  if (smallerOrEqual != sOffsetPoly3Set.begin())
  {
    // upper_bound is first larger element
    smallerOrEqual--;
  }
  if (smallerOrEqual != sOffsetPoly3Set.end())
  {
    auto poly = boost::array<double, 4>{{smallerOrEqual->a, smallerOrEqual->b, smallerOrEqual->c, smallerOrEqual->d}};
    return boost::math::tools::evaluate_polynomial(poly, s - smallerOrEqual->start_offset);
  }
  return 0.0;
}

} // namespace geometry
} // namespace opendrive
