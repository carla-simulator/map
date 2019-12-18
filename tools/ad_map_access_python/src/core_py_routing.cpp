// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/match/AdMapMatching.hpp>
#include <ad/map/point/Operation.hpp>
#include <ad/map/route/Planning.hpp>
#include <ad/map/route/RouteAStar.hpp>
#include <ad/map/route/RoutePrediction.hpp>
#include "core_py_utils.h"
#include "core_python.h"
#include "py_point.h"
#include "py_utils.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *Route(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  for (;;)
  {
    if (!ExpectArgs(args, 2))
    {
      break;
    }
    point::GeoPoint pt_start = GetGeoPoint(PyTuple_GetItem(args, 0));
    if (!point::isValid(pt_start))
    {
      break;
    }
    point::GeoPoint pt_dest = GetGeoPoint(PyTuple_GetItem(args, 1));
    if (!point::isValid(pt_dest))
    {
      break;
    }
    physics::Distance default_radius(0.05);
    match::AdMapMatching mapMatching;
    auto const mmpts_start = mapMatching.findLanes(pt_start, default_radius);
    if (mmpts_start.empty())
    {
      PyErr_SetString(PyExc_RuntimeError, "Cannot match start point to the network.");
      break;
    }
    auto const mmpts_dest = mapMatching.findLanes(pt_dest, default_radius);
    if (mmpts_dest.empty())
    {
      PyErr_SetString(PyExc_RuntimeError, "Cannot match destination point to the network.");
      break;
    }

    auto const para_start = route::planning::createRoutingPoint(mmpts_start[0].lanePoint.paraPoint);
    auto const para_dest = route::planning::createRoutingPoint(mmpts_dest[0].lanePoint.paraPoint);
    route::planning::RouteAstar route(para_start, para_dest, route::planning::Route::Type::SHORTEST);
    if (!route.calculate())
    {
      PyErr_SetString(PyExc_RuntimeError, "No route found.");
      break;
    }
    return PyVec(route.getFullRoute());
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *Predictions(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  for (;;)
  {
    if (!ExpectArgs(args, 1))
    {
      break;
    }
    point::GeoPoint pt_start = GetGeoPoint(PyTuple_GetItem(args, 0));
    if (!point::isValid(pt_start))
    {
      break;
    }
    physics::Distance default_radius(0.05);
    match::AdMapMatching mapMatching;
    auto const mmpts_start = mapMatching.findLanes(pt_start, default_radius);
    if (mmpts_start.empty())
    {
      PyErr_SetString(PyExc_RuntimeError, "Cannot match start point to the network.");
      break;
    }
    auto const para_start = route::planning::createRoutingPoint(mmpts_start[0].lanePoint.paraPoint);

    physics::Distance default_prediction_length(150.0);
    physics::Duration default_prediction_duration(10.0);

    route::planning::RoutePrediction route(para_start, default_prediction_length, default_prediction_duration);
    if (!route.calculate())
    {
      PyErr_SetString(PyExc_RuntimeError, "Route prediction failure.");
      break;
    }

    return PyVec(route.getFullRoutes());
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
