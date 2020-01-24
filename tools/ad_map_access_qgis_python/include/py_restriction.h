// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/restriction/Types.hpp>
#include "py_physics.h"
#include "py_utils.h"

template <> PyObject *Py(const ::ad::map::restriction::RoadUserType &x);

template <> PyObject *Py(const ::ad::map::restriction::Restriction &restriction);

template <> inline PyObject *Py(const ::ad::map::restriction::RestrictionList &x)
{
  return PyVec(x);
}

template <> PyObject *Py(const ::ad::map::restriction::Restrictions &restrictions);

template <> inline PyObject *Py(const ::ad::map::restriction::SpeedLimit &x)
{
  return PyTuple_Pack(3, Py(x.speedLimit), Py(x.lanePiece.minimum), Py(x.lanePiece.maximum));
}

template <> inline PyObject *Py(const ::ad::map::restriction::SpeedLimitList &x)
{
  return PyVec(x);
}
