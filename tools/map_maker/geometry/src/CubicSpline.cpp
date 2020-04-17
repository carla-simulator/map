// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/geometry/CubicSpline.hpp"
#include <cmath>
#include <cstdint>
#include <lapacke.h>
#include <malloc.h>

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
  rhs[0] = 3. * (points[1].y - points[0].y) / ((points[1].x - points[0].x) * (points[1].x - points[0].x));

  // 2 to last-1 entry
  uint32_t i = 1;
  for (; i < points.size() - 1; i++)
  {
    double nominator1 = points[i].y - points[i - 1].y;
    double nominator2 = points[i + 1].y - points[i].y;

    double denominator1 = (points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x);
    double denominator2 = (points[i + 1].x - points[i].x) * (points[i + 1].x - points[i].x);

    rhs[i] = 3. * ((nominator1 / denominator1) + (nominator2 / denominator2));
  }

  // last entry
  rhs[i] = 3. * (points[i].y - points[i - 1].y) / ((points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x));
}

/**
 * @brief Setup matrix of equation system required for spline interpolation
 * @param[in] points (knotPoints)
 * @param[out] matrix
 */
void setupMatrix(const std::vector<Point2d> &points, std::vector<double> &matrix)
{
  /**
   * see https://en.wikipedia.org/wiki/Spline_interpolation on how to setup matrix for cubic spline interpolation
   */

  // reset matrix
  matrix.clear();
  matrix.resize(points.size() * points.size());
  std::fill(matrix.begin(), matrix.end(), 0.);

  // 1. row
  matrix[0] = 2. / (points[1].x - points[0].x);
  matrix[1] = 1. / (points[1].x - points[0].x);

  // 2. row to last-1 row
  uint32_t i = 1;
  for (; i < points.size() - 1; i++)
  {
    double denominator1 = (points[i].x - points[i - 1].x);
    double denominator2 = (points[i + 1].x - points[i].x);

    matrix[i * points.size() + i - 1] = 1. / (denominator1);
    matrix[i * points.size() + i] = 2. * ((1. / denominator1) + (1. / denominator2));
    matrix[i * points.size() + i + 1] = 1. / (denominator2);
  }

  // last row
  matrix[i * points.size() + i - 1] = 1. / (points[i].x - points[i - 1].x);
  matrix[i * points.size() + i] = 2. / (points[i].x - points[i - 1].x);
}

/**
 * @brief Solve Ax = b using LU decomposition and pivoting
 * @param[in] Size of b
 * @param[in,out] matrix (A) as input and output (after internal pivoting)
 * @param[in,out] solution (x) as output, and b as input
 * @return true on success, false on failure
 */
bool solveLinearSystem(const size_t size, double *matrix, double *solution)
{
  if ((matrix == nullptr) || (solution == nullptr))
  {
    return false;
  }

  int32_t *ipiv;
  ipiv = (int32_t *)malloc(sizeof(int32_t) * size);

  // Factorize matrix into P*L*U with P being a pivot matrix \sa ipiv,
  // L is a lower triangular matrix and U an upper triangluar matrix
  // matrix is square (i.e. nxn)
  int32_t info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR /* we use row_major */,
                                static_cast<int>(size) /* size of rhs */,
                                static_cast<int>(size) /* size of rhs */,
                                matrix,
                                static_cast<int>(size) /* size of rhs */,
                                ipiv /* pivot vector */);

  // solve linear system (Ax=b) with A=P*L*U
  info += LAPACKE_dgetrs(LAPACK_ROW_MAJOR /* we use row_major */,
                         'N' /* matrix is not transposed */,
                         static_cast<int>(size) /* size of rhs */,
                         1 /* only one rhs */,
                         matrix,
                         static_cast<int>(size) /* size of rhs */,
                         ipiv /* pivot vector */,
                         solution /* input: rhs, output: solution */,
                         1 /* only one rhs */);

  free(ipiv);

  if (info > 0)
  {
    return false;
  }

  return true;
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
  if (interpolationDistance < 0.001)
  {
    return false;
  }
  interpolatedPoints.clear();

  std::vector<double> rhs;
  setupRhs(knotPoints, rhs);

  std::vector<double> matrix;
  setupMatrix(knotPoints, matrix);

  std::vector<double> coefficients(rhs);

  if (!solveLinearSystem(coefficients.size(), &matrix[0], &coefficients[0]))
  {
    return false;
  }

  for (uint32_t i = 0; i < knotPoints.size() - 1; i++)
  {
    Point2d thisPoint = knotPoints[i];
    Point2d nextPoint = knotPoints[i + 1];

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
