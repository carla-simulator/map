// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "py_point.h"
#include "py_lane.h"

template <> PyObject *Py(const ::ad::map::point::ParaPoint &x)
{
  return PyTuple_Pack(2, Py(x.laneId), Py(x.parametricOffset));
}
