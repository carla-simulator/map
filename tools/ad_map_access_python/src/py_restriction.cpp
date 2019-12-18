// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "py_restriction.h"
#include "py_utils.h"

using namespace ::ad::map;

template <> PyObject *Py(const ::ad::map::restriction::RoadUserType &x)
{
  return PyEnum(x, "::ad::map::restriction::RoadUserTypeList::");
}

template <> PyObject *Py(const restriction::Restriction &restriction)
{
  PyObject *type_list = PyList_New(0);
  for (auto typ : restriction.roadUserTypes)
  {
    PyList(type_list, Py(typ));
  }
  PyObject *dict = PyDict_New();
  PyDict(dict, "RoadUsers", type_list);
  PyDict(dict, "HOV", Py(restriction.passengersMin));
  PyDict(dict, "Not", Py(restriction.negated));
  return dict;
}

template <> PyObject *Py(const restriction::Restrictions &restrictions)
{
  PyObject *dict = PyDict_New();
  PyDict(dict, "And", PyVec(restrictions.conjunctions));
  PyDict(dict, "Or", PyVec(restrictions.disjunctions));
  return dict;
}
