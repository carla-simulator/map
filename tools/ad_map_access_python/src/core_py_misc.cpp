// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/match/AdMapMatching.hpp>
#include <string>
#include "core_py_utils.h"
#include "core_python.h"
#include "py_match.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *GetGeoDistance(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    point::GeoPoint pt0 = GetGeoPoint(PyTuple_GetItem(args, 0));
    if (point::isValid(pt0))
    {
      point::GeoPoint pt1 = GetGeoPoint(PyTuple_GetItem(args, 1));
      if (point::isValid(pt1))
      {
        physics::Distance d = point::distance(pt0, pt1);
        return PyFloat_FromDouble(static_cast<double>(d));
      }
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *FindLanes(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    point::GeoPoint pt_geo = GetGeoPoint(PyTuple_GetItem(args, 0));
    if (point::isValid(pt_geo))
    {
      physics::Distance d = GetDistance(PyTuple_GetItem(args, 1));
      if (d.isValid())
      {
        match::AdMapMatching mapMatching;
        auto const mmposs = mapMatching.findLanes(pt_geo, d);
        return PyVec(mmposs);
      }
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *SetENURefPoint(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  point::GeoPoint enu_ref_point = GetGeoPoint(args);
  if (point::isValid(enu_ref_point))
  {
    access::setENUReferencePoint(enu_ref_point);
    Py_RETURN_TRUE;
  }
  else
  {
    Py_RETURN_FALSE;
  }
}
