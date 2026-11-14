// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/CubicSpline.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <lapacke.h>

namespace ad {
namespace map {
namespace maker {
namespace geometry {

/**
 * @brief Setup right-hand-side of equation system required for spline interpolation
 * @param[in] points (knotPoints)
 * @param[out] rhs (right-hand-side)
 */
void setupRhs(const std::vector<Point2d> &points, std::vector<double> &rhs)
{
  /**
   * see https://en.wikipedia.org/wiki/Spline_interpolation on how to setup rhs for cubic spline interpolation
   */

  // reset rhs
  rhs.clear();
  rhs.resize(points.size());

  // 1. entry
  double const dx0 = points[1].x - points[0].x;
  rhs[0] = 3. * (points[1].y - points[0].y) / (dx0 * dx0);

  // 2 to last-1 entry
  std::size_t i = 1u;
  for (; i + 1u < points.size(); ++i)
  {
    double const nominator1 = points[i].y - points[i - 1u].y;
    double const nominator2 = points[i + 1u].y - points[i].y;

    double const dx1 = points[i].x - points[i - 1u].x;
    double const dx2 = points[i + 1u].x - points[i].x;
    double const denominator1 = dx1 * dx1;
    double const denominator2 = dx2 * dx2;

    rhs[i] = 3. * ((nominator1 / denominator1) + (nominator2 / denominator2));
  }

  // last entry
  double const dxLast = points[i].x - points[i - 1u].x;
  rhs[i] = 3. * (points[i].y - points[i - 1u].y) / (dxLast * dxLast);
}

/**
 * @brief Solve the tridiagonal cubic spline system Ax = b in O(N) using LAPACKE_dgtsv
 * @param[in] points (knotPoints)
 * @param[in,out] solution (b on input, x on output)
 * @return true on success, false on failure
 */
bool solveTridiagonalSplineSystem(const std::vector<Point2d> &points, std::vector<double> &solution)
{
  std::size_t const n = points.size();
  if ((n < 2u) || (solution.size() != n))
  {
    return false;
  }

  std::vector<double> dl(n - 1u, 0.);
  std::vector<double> d(n, 0.);
  std::vector<double> du(n - 1u, 0.);

  double const invDx0 = 1. / (points[1].x - points[0].x);
  d[0] = 2. * invDx0;
  du[0] = invDx0;

  for (std::size_t i = 1u; i + 1u < n; ++i)
  {
    double const invDxPrev = 1. / (points[i].x - points[i - 1u].x);
    double const invDxNext = 1. / (points[i + 1u].x - points[i].x);
    dl[i - 1u] = invDxPrev;
    d[i] = 2. * (invDxPrev + invDxNext);
    du[i] = invDxNext;
  }

  double const invDxLast = 1. / (points[n - 1u].x - points[n - 2u].x);
  dl[n - 2u] = invDxLast;
  d[n - 1u] = 2. * invDxLast;

  lapack_int const lapackN = static_cast<lapack_int>(n);
  lapack_int const info
    = LAPACKE_dgtsv(LAPACK_COL_MAJOR, lapackN, 1, dl.data(), d.data(), du.data(), solution.data(), lapackN);
  return info == 0;
}

/**
 * @brief Calculate an interpolated point along the cubic spline between \a previousPoint and \a nextPoint given the
 *        x-coordinate of the to be interpolated point (\a interpolationPoint)
 * @param[in] coefficient1   1st coefficient of cubic spline between \a previousPoint and \a nextPoint
 * @param[in] coefficient2   2nd coefficient of cubic spline between \a previousPoint and \a nextPoint
 * @param[in] previousPoint  1st knot of cubic spline
 * @param[in] nextPoint      2nd knot of cubic spline
 * @param[in,out] interpolatedPoint Point between \a previousPoint and \a nextPoint on cubic spline
 */
void stepwiseInterpolationAlongX(const double coefficient1,
                                 const double coefficient2,
                                 const Point2d &previousPoint,
                                 const Point2d &nextPoint,
                                 Point2d &interpolatedPoint)
{
  /**
   * see https://en.wikipedia.org/wiki/Spline_interpolation on cubic spline interpolation
   */
  double t = (interpolatedPoint.x - previousPoint.x) / (nextPoint.x - previousPoint.x);
  double a = coefficient1 * (nextPoint.x - previousPoint.x) - (nextPoint.y - previousPoint.y);
  double b = -coefficient2 * (nextPoint.x - previousPoint.x) + (nextPoint.y - previousPoint.y);
  interpolatedPoint.y = (1 - t) * previousPoint.y + t * nextPoint.y + t * (1 - t) * (a * (1 - t) + b * t);
}

/**
 * @brief Calculate an interpolated point along the cubic spline between \a previousPoint and \a nextPoint
 *        The idea is to calculate a new interpolated point (\a interpolatedPoint), that has \a interpolationDistance
 *        distance from the last calculated interpolated point (\a interpolatedPoint).
 *        Compared to \sa stepwiseInterpolationAlongX() this function should provide points with less distance between
 *        each other.
 * @param[in] coefficient1   1st coefficient of cubic spline between \a previousPoint and \a nextPoint
 * @param[in] coefficient2   2nd coefficient of cubic spline between \a previousPoint and \a nextPoint
 * @param[in] previousPoint  1st knot of cubic spline
 * @param[in] nextPoint      2nd knot of cubic spline
 * @param[in] interpolationDistance Distance between the current interpolatedPoint and the next along the curve
 * @param[in,out] interpolatedPoint Point between \a previousPoint and \a nextPoint on cubic spline
 */
void stepwiseInterpolationAlongCurve(const double coefficient1,
                                     const double coefficient2,
                                     const Point2d &previousPoint,
                                     const Point2d &nextPoint,
                                     const double interpolationDistance,
                                     Point2d &interpolatedPoint)
{
  /**
   * see https://en.wikipedia.org/wiki/Spline_interpolation on cubic spline interpolation
   */
  const double dt = 1. / (nextPoint.x - previousPoint.x);
  const double a = coefficient1 * (nextPoint.x - previousPoint.x) - (nextPoint.y - previousPoint.y);
  const double b = -coefficient2 * (nextPoint.x - previousPoint.x) + (nextPoint.y - previousPoint.y);
  const double stepSize = 0.01;
  const int32_t direction = (previousPoint.x < nextPoint.x) ? 1 : -1;

  double length = 0;
  uint32_t numSteps = 0;
  // estimate curve length (distance between interpolated points along curve) using rectangles around the curve integral
  // length of curve = integral_from_a_to_b sqrt(1+f'(x)*f'(x)) dx
  // here: f(x) is the cubic spline between previousPoint and nextPoint
  while (length < interpolationDistance)
  {
    interpolatedPoint.x += direction * stepSize;
    double t = (interpolatedPoint.x - previousPoint.x) / (nextPoint.x - previousPoint.x);
    double splineDerivative
      = (nextPoint.y - previousPoint.y + a) * dt + 2 * (b - 2 * a) * t * dt + 3 * t * t * dt * (a - b);
    double rectangularArea = 0.01 * std::sqrt(1. + std::pow(splineDerivative, 2));
    length += rectangularArea;
    numSteps++;
  }

  // if the number of intermediate steps is more than 1, go back by one step
  // otherwise, this is not possible, as it would mean that the old and new interpolated points are the same
  if (numSteps > 1)
  {
    interpolatedPoint.x -= direction * stepSize;
  }
  double t = (interpolatedPoint.x - previousPoint.x) / (nextPoint.x - previousPoint.x);

  interpolatedPoint.y = (1 - t) * previousPoint.y + t * nextPoint.y + t * (1 - t) * (a * (1 - t) + b * t);
}

bool CubicSpline::interpolate(bool linearAlongXAxis)
{
  if ((interpolationDistance < 0.001) || (knotPoints.size() < 2u))
  {
    return false;
  }

  bool const increasing = knotPoints[0].x < knotPoints[1].x;
  for (std::size_t i = 0u; i + 1u < knotPoints.size(); ++i)
  {
    if (increasing ? !(knotPoints[i].x < knotPoints[i + 1u].x) : !(knotPoints[i].x > knotPoints[i + 1u].x))
    {
      return false;
    }
  }

  interpolatedPoints.clear();

  std::vector<double> coefficients;
  setupRhs(knotPoints, coefficients);

  if (!solveTridiagonalSplineSystem(knotPoints, coefficients))
  {
    return false;
  }

  for (std::size_t i = 0u; i + 1u < knotPoints.size(); ++i)
  {
    Point2d thisPoint = knotPoints[i];
    Point2d nextPoint = knotPoints[i + 1u];

    // go stepwise from thisPoint to nextPoint
    Point2d interpolatedPoint = thisPoint;
    if (thisPoint.x < nextPoint.x)
    {
      while (interpolatedPoint.x < nextPoint.x)
      {
        interpolatedPoints.push_back(interpolatedPoint);

        if (linearAlongXAxis)
        {
          interpolatedPoint.x += interpolationDistance;
          stepwiseInterpolationAlongX(coefficients[i], coefficients[i + 1], thisPoint, nextPoint, interpolatedPoint);
        }
        else
        {
          stepwiseInterpolationAlongCurve(
            coefficients[i], coefficients[i + 1], thisPoint, nextPoint, interpolationDistance, interpolatedPoint);
        }
      }
    }
    else if (thisPoint.x > nextPoint.x)
    {
      while (interpolatedPoint.x > nextPoint.x)
      {
        interpolatedPoints.push_back(interpolatedPoint);

        if (linearAlongXAxis)
        {
          interpolatedPoint.x -= interpolationDistance;
          stepwiseInterpolationAlongX(coefficients[i], coefficients[i + 1], thisPoint, nextPoint, interpolatedPoint);
        }
        else
        {
          stepwiseInterpolationAlongCurve(
            coefficients[i], coefficients[i + 1], thisPoint, nextPoint, interpolationDistance, interpolatedPoint);
        }
      }
    }
    else
    {
      // thisPoint.x == nextPoint.x
      // this should not happen (no function can go thru the same x-coordinate twice)
      return false;
    }
  }

  interpolatedPoints.push_back(knotPoints.back());

  return true;
}

} // namespace geometry
} // namespace maker
} // namespace map
} // namespace ad
