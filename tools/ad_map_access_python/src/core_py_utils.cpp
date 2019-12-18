// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "core_py_utils.h"
#include <ad/map/access/Logging.hpp>
#include <ad/map/landmark/Operation.hpp>
#include <ad/map/lane/Operation.hpp>
#include <ad/map/point/Operation.hpp>
#include "py_lane.h"
#include "py_point.h"

using namespace ::ad;
using namespace ::ad::map;

bool ExpectArgs(PyObject *py_args, Py_ssize_t args)
{
  if (py_args != nullptr)
  {
    if (PyTuple_Check(py_args))
    {
      Py_ssize_t no_of_args = PyTuple_Size(py_args);
      if (no_of_args == args)
      {
        return true;
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments.");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Expect multiple arguments - only one provided.");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Expect arguments - none provided.");
  }
  return false;
}

bool GetBool(PyObject *py_bool, bool &b)
{
  if (py_bool != nullptr)
  {
    if (PyBool_Check(py_bool))
    {
      b = PyObject_IsTrue(py_bool);
      return true;
    }
  }
  PyErr_SetString(PyExc_RuntimeError, "Expecting boolean argument!");
  return false;
}

bool GetString(PyObject *py_string, std::string &sz)
{
  if (py_string != nullptr)
  {
    if (PyString_Check(py_string))
    {
      sz = PyString_AsString(py_string);
      return true;
    }
  }
  PyErr_SetString(PyExc_RuntimeError, "Expecting string argument!");
  return false;
}

bool GetInt64(PyObject *py_int64, int64_t &int64)
{
  if (py_int64 != nullptr)
  {
    if (PyInt_Check(py_int64))
    {
      int64 = PyInt_AsLong(py_int64);
      return true;
    }
    else if (PyLong_Check(py_int64))
    {
      int64 = PyLong_AsLong(py_int64);
      return true;
    }
  }
  PyErr_SetString(PyExc_RuntimeError, "Expecting numeric argument!");
  return false;
}

bool GetUInt64(PyObject *py_uint64, uint64_t &uint64)
{
  int64_t int64;
  if (GetInt64(py_uint64, int64))
  {
    uint64 = static_cast<uint64_t>(int64);
    return true;
  }
  else
  {
    return false;
  }
}

bool GetDouble(PyObject *py_double, double &dbl)
{
  if (py_double != nullptr)
  {
    if (PyFloat_Check(py_double))
    {
      dbl = PyFloat_AsDouble(py_double);
      return true;
    }
    else
    {
      int64_t int64 = 0;
      if (GetInt64(py_double, int64))
      {
        dbl = static_cast<double>(int64);
        return true;
      }
    }
  }
  PyErr_SetString(PyExc_RuntimeError, "Expecting numeric argument!");
  return false;
}

bool GetDouble(PyObject *py_double, double min_val, double max_val, double &dbl)
{
  if (GetDouble(py_double, dbl))
  {
    if (min_val <= dbl && dbl <= max_val)
    {
      return true;
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Numeric argument out of range!");
    }
  }
  return false;
}

physics::ParametricValue GetParametricValue(PyObject *py_arg)
{
  double raw = 0.0;
  if (GetDouble(py_arg, 0.0, 1.0, raw))
  {
    return physics::ParametricValue(raw);
  }
  return physics::ParametricValue();
}

point::Longitude GetLongitude(PyObject *py_arg)
{
  double raw = 0.0;
  if (GetDouble(py_arg, -180.0, 180.0, raw))
  {
    return point::Longitude(raw);
  }
  return point::Longitude();
}

point::Latitude GetLatitude(PyObject *py_arg)
{
  double raw = 0.0;
  if (GetDouble(py_arg, -90.0, 90, raw))
  {
    return point::Latitude(raw);
  }
  return point::Latitude();
}

point::Altitude GetAltitude(PyObject *py_arg)
{
  double raw = 0.0;
  if (GetDouble(py_arg, raw))
  {
    return point::Altitude(raw);
  }
  return point::Altitude();
}

physics::Distance GetDistance(PyObject *py_arg)
{
  double raw = 0.0;
  if (GetDouble(py_arg, 0, physics::Distance::cMaxValue, raw))
  {
    return physics::Distance(raw);
  }
  return physics::Distance();
}

point::GeoPoint GetGeoPoint(PyObject *py_geo_point, bool def_altitude_0)
{
  if (PyTuple_Check(py_geo_point))
  {
    if (PyTuple_Size(py_geo_point) == 2 || PyTuple_Size(py_geo_point) == 3)
    {
      point::Longitude lon = GetLongitude(PyTuple_GetItem(py_geo_point, 0));
      if (lon.isValid())
      {
        point::Latitude lat = GetLatitude(PyTuple_GetItem(py_geo_point, 1));
        if (lat.isValid())
        {
          if (PyTuple_Size(py_geo_point) == 3)
          {
            point::Altitude alt = GetAltitude(PyTuple_GetItem(py_geo_point, 2));
            return point::createGeoPoint(lon, lat, alt);
          }
          else if (def_altitude_0)
          {
            return point::createGeoPoint(lon, lat, point::Altitude(0));
          }
          else
          {
            return point::createGeoPoint(lon, lat, point::AltitudeUnknown);
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Invalid latitude!");
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Invalid longitude!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Geo-point 2- or 3- touple expected!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Geo-point touple expected!");
  }
  return point::GeoPoint();
}

bool GetGeoPoints(PyObject *py_geo_points, point::GeoEdge &geo_pts, bool def_alt_0)
{
  if (PyList_Check(py_geo_points))
  {
    Py_ssize_t n = PyList_Size(py_geo_points);
    if (n > 1)
    {
      for (Py_ssize_t i = 0; i < n; i++)
      {
        access::getLogger()->debug("Reading point {} of {}", i, n);
        PyObject *py_geo_point = PyList_GetItem(py_geo_points, i);
        point::GeoPoint geo_point = GetGeoPoint(py_geo_point, def_alt_0);
        if (point::isValid(geo_point))
        {
          geo_pts.push_back(geo_point);
        }
        else
        {
          return false;
        }
      }
      return true;
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Expecting list of 2 or more Geo-points!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Expecting list of Geo-points!");
  }
  return false;
}

lane::LaneId GetLaneId(PyObject *py_lane_id)
{
  if (py_lane_id != nullptr)
  {
    uint64_t lane_id_raw = 0;
    if (PyLong_Check(py_lane_id))
    {
      lane_id_raw = PyLong_AsUnsignedLongLong(py_lane_id);
    }
    else if (PyInt_Check(py_lane_id))
    {
      lane_id_raw = static_cast<uint64_t>(PyInt_AsLong(py_lane_id));
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Expecting integer argument as Lane Identifier!");
      return lane::LaneId();
    }
    return lane::LaneId(lane_id_raw);
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Expecting Lane Identifier!");
    return lane::LaneId();
  }
}

lane::Lane::ConstPtr GetLane(PyObject *py_lane_id)
{
  lane::LaneId lane_id = GetLaneId(py_lane_id);
  if (lane_id.isValid())
  {
    try
    {
      lane::Lane::ConstPtr lane = lane::getLanePtr(lane_id);
      if (lane)
      {
        return lane;
      }
    }
    catch (std::invalid_argument)
    {
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid lane identifier!");
  }
  return lane::Lane::Ptr();
}

PyObject *GetLaneEdge(PyObject *py_lane_id, bool left, CoordSys cs)
{
  PyErr_Clear();
  lane::Lane::ConstPtr lane = GetLane(py_lane_id);
  if (lane)
  {
    const point::Geometry &geom = left ? lane->edgeLeft : lane->edgeRight;
    switch (cs)
    {
      case CoordSys::ECEF:
      {
        return Py(geom.ecefEdge);
      }
      case CoordSys::ENU:
        if (access::isENUReferencePointSet())
        {
          return Py(point::getCachedENUEdge(geom));
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "ENU Reference Point not set!");
          break;
        }
      case CoordSys::LLA:
      {
        point::GeoEdge geos;
        access::getCoordinateTransform()->convert(geom.ecefEdge, geos);
        return Py(geos);
      }
      default:
        PyErr_SetString(PyExc_RuntimeError, "Internal error!");
        break;
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *GetLaneSubEdge(PyObject *args, bool left, CoordSys cs)
{
  PyErr_Clear();
  if (PyTuple_Check(args) && PyTuple_Size(args) == 3)
  {
    physics::ParametricValue tstart = GetParametricValue(PyTuple_GetItem(args, 1));
    if (tstart.isValid())
    {
      physics::ParametricValue tend = GetParametricValue(PyTuple_GetItem(args, 2));
      if (tend.isValid())
      {
        if (tstart < tend)
        {
          lane::Lane::ConstPtr lane = GetLane(PyTuple_GetItem(args, 0));
          if (lane)
          {
            physics::ParametricRange trange;
            trange.minimum = tstart;
            trange.maximum = tend;
            const point::Geometry &geometry = left ? lane->edgeLeft : lane->edgeRight;
            point::ECEFEdge ecefs;
            point::getParametricRange(geometry, trange, ecefs);
            if (!ecefs.empty())
            {
              switch (cs)
              {
                case CoordSys::ECEF:
                {
                  return Py(ecefs);
                }
                case CoordSys::ENU:
                  if (access::isENUReferencePointSet())
                  {
                    return Py(point::toENU(ecefs));
                  }
                  else
                  {
                    PyErr_SetString(PyExc_RuntimeError, "ENU Reference Point not set!");
                    break;
                  }
                case CoordSys::LLA:
                {
                  return Py(point::toGeo(ecefs));
                }
                default:
                  PyErr_SetString(PyExc_RuntimeError, "Internal error!");
                  break;
              }
            }
            else
            {
              PyErr_SetString(PyExc_RuntimeError, "Empty sub-edge?");
            }
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "t-start greater than t-end.");
        }
      }
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments.");
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

landmark::LandmarkId GetLandmarkId(PyObject *py_landmark_id)
{
  if (py_landmark_id != nullptr)
  {
    uint64_t landmark_id_raw = 0;
    if (PyLong_Check(py_landmark_id))
    {
      landmark_id_raw = PyLong_AsUnsignedLongLong(py_landmark_id);
    }
    else if (PyInt_Check(py_landmark_id))
    {
      landmark_id_raw = static_cast<uint64_t>(PyInt_AsLong(py_landmark_id));
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Expecting integer argument as Landmark Id!");
      return landmark::LandmarkId();
    }
    return landmark::LandmarkId(landmark_id_raw);
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Expecting Landmark Identifier!");
    return landmark::LandmarkId();
  }
}

landmark::Landmark::ConstPtr GetLandmark(PyObject *py_landmark_id)
{
  landmark::LandmarkId landmark_id = GetLandmarkId(py_landmark_id);
  if (landmark_id.isValid())
  {
    try
    {
      landmark::Landmark::ConstPtr landmark = landmark::getLandmarkPtr(landmark_id);
      if (landmark)
      {
        return landmark;
      }
    }
    catch (std::invalid_argument)
    {
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid landmark identifier!");
  }
  return landmark::Landmark::ConstPtr();
}

PyObject *GetLandmarkPosition(PyObject *py_landmark_id, CoordSys cs)
{
  PyErr_Clear();
  landmark::Landmark::ConstPtr landmark = GetLandmark(py_landmark_id);
  if (landmark)
  {
    point::ECEFPoint ecef = landmark->position;
    switch (cs)
    {
      case CoordSys::ECEF:
      {
        return Py(ecef);
      }
      case CoordSys::ENU:
        if (access::isENUReferencePointSet())
        {
          return Py(point::toENU(ecef));
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "ENU Reference Point not set!");
          break;
        }
      case CoordSys::LLA:
      {
        return Py(point::toGeo(ecef));
      }
      default:
        PyErr_SetString(PyExc_RuntimeError, "Internal error!");
        break;
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
