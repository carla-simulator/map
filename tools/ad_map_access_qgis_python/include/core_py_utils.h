// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/landmark/Types.hpp>
#include <ad/map/lane/Types.hpp>
#include <ad/map/point/Types.hpp>
#include <string>
#include "./core_python.h"
#include "./py_utils.h"

enum class CoordSys
{
  LLA,
  ECEF,
  ENU
};

bool ExpectArgs(PyObject *py_args, Py_ssize_t args);

bool GetBool(PyObject *py_bool, bool &b);
bool GetString(PyObject *py_string, std::string &sz);
bool GetInt64(PyObject *py_int64, int64_t &int64);
bool GetUInt64(PyObject *py_uint64, uint64_t &uint64);
bool GetDouble(PyObject *py_double, double &dbl);
bool GetDouble(PyObject *py_double, double min_val, double max_val, double &dbl);

::ad::physics::ParametricValue GetParametricValue(PyObject *py_arg);
::ad::physics::Distance GetDistance(PyObject *py_arg);
::ad::map::point::Longitude GetLongitude(PyObject *py_arg);
::ad::map::point::Latitude GetLatitude(PyObject *py_arg);
::ad::map::point::Altitude GetAltitude(PyObject *py_arg);

::ad::map::lane::LaneId GetLaneId(PyObject *py_lane_id);

::ad::map::point::GeoPoint GetGeoPoint(PyObject *py_geo_point, bool def_altitude_0 = true);
bool GetGeoPoints(PyObject *py_geo_points, ::ad::map::point::GeoEdge &geo_pts, bool def_a0 = false);
::ad::map::lane::Lane::ConstPtr GetLane(PyObject *py_lane_id);

::ad::map::landmark::LandmarkId GetLandmarkId(PyObject *py_landmark_id);
::ad::map::landmark::Landmark::ConstPtr GetLandmark(PyObject *py_landmark_id);

PyObject *GetLaneEdge(PyObject *py_lane_id, bool left, CoordSys cs);
PyObject *GetLaneSubEdge(PyObject *args, bool left, CoordSys cs);

PyObject *GetLandmarkPosition(PyObject *py_landmark_id, CoordSys cs);
