// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/match/Types.hpp>
#include "py_point.h"
#include "py_utils.h"

template <> inline PyObject *Py(const ::ad::map::match::MapMatchedPositionType &x)
{
  return PyEnum(x, "::ad::map::match::MapMatchedPositionType::");
}

template <> inline PyObject *Py(const ::ad::map::match::MapMatchedPosition &x)
{
  return PyTuple_Pack(8,
                      Py(x.lanePoint.paraPoint),
                      Py(x.type),
                      Py(x.lanePoint.lateralT),
                      Py(x.lanePoint.laneWidth),
                      Py(x.lanePoint.laneLength),
                      PyConv(x.matchedPoint),
                      PyConv(x.queryPoint),
                      Py(x.probability));
}

template <> inline PyObject *Py(const ::ad::map::match::MapMatchedPositionConfidenceList &x)
{
  return PyVec(x);
}
