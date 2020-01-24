// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Factory.hpp>
#include <ad/map/point/Operation.hpp>
#include <cfloat>
#include "core_py_utils.h"
#include "core_python.h"
#include "py_lane.h"

using namespace ::ad::map;
using namespace ::ad;

///< Maximum length of the created lane.
static physics::Distance g_l_max(300);

static point::ECEFPoint IntersectionPoint(const point::ECEFPoint &p0,
                                          const point::ECEFPoint &p1,
                                          const point::ECEFPoint &q0,
                                          const point::ECEFPoint &q1)
{
  point::CoordinateTransform cf;
  point::GeoPoint gp0 = cf.ECEF2Geo(p0);
  point::GeoPoint gp1 = cf.ECEF2Geo(p1);
  point::GeoPoint gq0 = cf.ECEF2Geo(q0);
  point::GeoPoint gq1 = cf.ECEF2Geo(q1);

  double p0x = static_cast<double>(gp0.longitude) * 1e6;
  double p1x = static_cast<double>(gp1.longitude) * 1e6;
  double q0x = static_cast<double>(gq0.longitude) * 1e6;
  double q1x = static_cast<double>(gq1.longitude) * 1e6;
  double p0y = static_cast<double>(gp0.latitude) * 1e6;
  double p1y = static_cast<double>(gp1.latitude) * 1e6;
  double q0y = static_cast<double>(gq0.latitude) * 1e6;
  double q1y = static_cast<double>(gq1.latitude) * 1e6;

  double a1 = p1y - p0y;
  double b1 = p0x - p1x;
  double c1 = a1 * (p0x) + b1 * (p0y);

  double a2 = q1y - q0y;
  double b2 = q0x - q1x;
  double c2 = a2 * (q0x) + b2 * (q0y);

  double determinant = a1 * b2 - a2 * b1;
  if (std::fabs(determinant) < FLT_EPSILON)
  {
    return point::ECEFPoint();
  }
  else
  {
    double x = (b2 * c1 - b1 * c2) / determinant * 1e-6;
    double y = (a1 * c2 - a2 * c1) / determinant * 1e-6;
    auto a = (gp0.altitude + gq0.altitude) * 0.5;
    return cf.Geo2ECEF(point::createGeoPoint(point::Longitude(x), point::Latitude(y), a));
  }
}

static bool IsCloser(const point::ECEFPoint &p, const point::ECEFPoint &q0, const point::ECEFPoint &q1)
{
  return point::distance(p, q0) < point::distance(p, q1);
}

static point::ECEFEdge
Bezier(const point::ECEFPoint &p0, const point::ECEFPoint &p2, const point::ECEFPoint &p1, size_t steps)
{
  point::ECEFEdge pts;
  pts.reserve(steps + 2);
  pts.push_back(p0);
  if (steps > 0)
  {
    double dt = 1.0 / (static_cast<double>(steps + 1));
    double t = dt;
    for (size_t i = 0; i < steps; i++, t += dt)
    {
      physics::ParametricValue tp(t);
      point::ECEFPoint p01 = point::vectorInterpolate(p0, p1, tp);
      point::ECEFPoint p12 = point::vectorInterpolate(p1, p2, tp);
      point::ECEFPoint p02 = point::vectorInterpolate(p01, p12, tp);
      pts.push_back(p02);
    }
  }
  pts.push_back(p2);
  return pts;
}

static point::ECEFEdge InterEdge(const point::ECEFPoint &p0,
                                 const point::ECEFPoint &p1,
                                 const point::ECEFPoint &q0,
                                 const point::ECEFPoint &q1,
                                 bool straight)
{
  if (straight)
  {
    point::ECEFEdge edge = {p0, q0};
    return edge;
  }
  else
  {
    point::ECEFPoint pi = IntersectionPoint(p0, p1, q0, q1);
    if (point::isValid(pi))
    {
      if (IsCloser(pi, p0, p1) && IsCloser(pi, q0, q1))
      {
        physics::Distance dip = point::distance(pi, p0);
        physics::Distance diq = point::distance(pi, q0);
        if (dip <= g_l_max && diq <= g_l_max)
        {
          physics::Distance d = point::distance(p0, q0);
          size_t steps = static_cast<size_t>(static_cast<double>(d) + 0.5);
          return Bezier(p0, q0, pi, steps);
        }
      }
    }
    return point::ECEFEdge();
  }
}

template <class T> bool IsMin(const T &a, const T &b, const T &c, const T &d)
{
  return a <= b && a <= c && a <= d;
}

static point::ECEFEdge InterEdge(const point::ECEFEdge &e1, const point::ECEFEdge &e2, bool straight)
{
  size_t n1 = e1.size();
  size_t n2 = e2.size();
  if (n1 > 1 && n2 > 1)
  {
    physics::Distance dff = point::distance(e1.front(), e2.front());
    physics::Distance dfb = point::distance(e1.front(), e2.back());
    physics::Distance dbf = point::distance(e1.back(), e2.front());
    physics::Distance dbb = point::distance(e1.back(), e2.back());
    if (IsMin(dff, dfb, dbf, dbb))
    {
      return InterEdge(e1[0], e1[1], e2[0], e2[1], straight);
    }
    else if (IsMin(dfb, dff, dbf, dbb))
    {
      return InterEdge(e1[0], e1[1], e2[n2 - 1], e2[n2 - 2], straight);
    }
    else if (IsMin(dbf, dff, dfb, dbb))
    {
      return InterEdge(e1[n1 - 1], e1[n1 - 2], e2[0], e2[1], straight);
    }
    else if (IsMin(dbb, dff, dfb, dbf))
    {
      return InterEdge(e1[n1 - 1], e1[n1 - 2], e2[n2 - 1], e2[n2 - 2], straight);
    }
    else
    {
      assert(0);
    }
  }
  return point::ECEFEdge();
}

static physics::Distance FindShort(const point::ECEFEdge &geom_0, const point::ECEFEdge &geom_1)
{
  if (!geom_0.empty() && !geom_1.empty())
  {
    physics::Distance dff = point::distance(geom_0.front(), geom_1.front());
    physics::Distance dfe = point::distance(geom_0.front(), geom_1.back());
    physics::Distance def = point::distance(geom_0.back(), geom_1.front());
    physics::Distance dee = point::distance(geom_0.back(), geom_1.back());
    if (IsMin(dff, dfe, def, dee))
    {
      return dff;
    }
    else if (IsMin(dfe, dff, def, dee))
    {
      return dfe;
    }
    else if (IsMin(def, dff, dfe, dee))
    {
      return def;
    }
    else if (IsMin(dee, dff, dfe, def))
    {
      return dee;
    }
    else
    {
      assert(0);
    }
  }
  return physics::Distance();
}

static lane::LaneId MakeIntersectionLane(lane::Lane::ConstPtr lane_0,
                                         lane::Lane::ConstPtr lane_1,
                                         const point::ECEFEdge &geom_0,
                                         const point::ECEFEdge &geom_1)
{
  if (!geom_0.empty() && !geom_1.empty())
  {
    point::CoordinateTransform cf;
    point::GeoEdge ggeom_0, ggeom_1;
    cf.convert(geom_0, ggeom_0);
    cf.convert(geom_1, ggeom_1);
    if (point::isOnTheLeft(ggeom_0, ggeom_1))
    {
      access::Factory factory(access::getStore());
      return factory.add(access::PartitionId(0), geom_0, geom_1, lane_0->id, lane_1->id);
    }
    else
    {
      access::Factory factory(access::getStore());
      return factory.add(access::PartitionId(0), geom_1, geom_0, lane_0->id, lane_1->id);
    }
  }
  else
  {
    return lane::LaneId();
  }
}

static lane::LaneId MakeIntersectionLane(lane::Lane::ConstPtr lane_0, lane::Lane::ConstPtr lane_1, bool straight)
{
  const point::ECEFEdge &geom_0_left = lane_0->edgeLeft.ecefEdge;
  const point::ECEFEdge &geom_0_right = lane_0->edgeRight.ecefEdge;
  const point::ECEFEdge &geom_1_left = lane_1->edgeLeft.ecefEdge;
  const point::ECEFEdge &geom_1_right = lane_1->edgeRight.ecefEdge;
  physics::Distance dll = FindShort(geom_0_left, geom_1_left);
  physics::Distance dlr = FindShort(geom_0_left, geom_1_right);
  physics::Distance drl = FindShort(geom_0_right, geom_1_left);
  physics::Distance drr = FindShort(geom_0_right, geom_1_right);
  if (dll.isValid() && dlr.isValid() && drl.isValid() && drr.isValid())
  {
    if (dll <= g_l_max || dlr <= g_l_max || drl <= g_l_max || drr <= g_l_max)
    {
      if (IsMin(dll, drr, dlr, drl) || IsMin(drr, dll, dlr, drl))
      {
        point::ECEFEdge new_geom_0 = InterEdge(geom_0_left, geom_1_left, straight);
        point::ECEFEdge new_geom_1 = InterEdge(geom_0_right, geom_1_right, straight);
        return MakeIntersectionLane(lane_0, lane_1, new_geom_0, new_geom_1);
      }
      else if (IsMin(dlr, drl, dll, drr) || IsMin(drl, dlr, dll, drr))
      {
        point::ECEFEdge new_geom_0 = InterEdge(geom_0_left, geom_1_right, straight);
        point::ECEFEdge new_geom_1 = InterEdge(geom_0_right, geom_1_left, straight);
        return MakeIntersectionLane(lane_0, lane_1, new_geom_0, new_geom_1);
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Inconsistent lane geometries?!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Lanes too far apart.");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, __FILE__);
  }
  return lane::LaneId();
}

PyObject *MakeIntersectionLane(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 3))
  {
    lane::Lane::ConstPtr lane_0 = GetLane(PyTuple_GetItem(args, 0));
    if (lane_0)
    {
      lane::Lane::ConstPtr lane_1 = GetLane(PyTuple_GetItem(args, 1));
      if (lane_1)
      {
        bool straight = false;
        if (GetBool(PyTuple_GetItem(args, 2), straight))
        {
          lane::LaneId new_lane_id = MakeIntersectionLane(lane_0, lane_1, straight);
          if (new_lane_id.isValid())
          {
            return Py(new_lane_id);
          }
        }
      }
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
