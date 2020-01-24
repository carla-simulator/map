// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
#include "py_landmark.h"
#include <vector>
#include "py_utils.h"

using namespace ::ad::map::landmark;

template <> PyObject *Py(const ::ad::map::landmark::TrafficLightType &x)
{
  return PyEnum(x, "::ad::map::landmark::TrafficLightType::");
}

template <> PyObject *Py(const ::ad::map::landmark::TrafficSignType &x)
{
  return PyEnum(x, "::ad::map::landmark::TrafficSignType::");
}

template <> PyObject *Py(const ::ad::map::landmark::LandmarkType &x)
{
  return PyEnum(x, "::ad::map::landmark::LandmarkType::");
}

PyObject *Py(Landmark::ConstPtr landmark)
{
  if (!landmark)
  {
    Py_RETURN_NONE;
  }

  PyObject *dict = PyDict_New();
  PyDict(dict, "Id", Py(landmark->id));
  PyDict(dict, "Type", Py(landmark->type));
  PyDict(dict, "TrafficLightType", Py(landmark->trafficLightType));
  PyDict(dict, "TrafficSignType", Py(landmark->trafficSignType));
  return dict;
}
