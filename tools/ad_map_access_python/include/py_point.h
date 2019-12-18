// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/point/Operation.hpp>
#include <ad/map/point/Types.hpp>
#include "py_physics.h"
#include "py_utils.h"

template <> PyObject *Py(const ::ad::map::point::ParaPoint &x);

template <> inline PyObject *Py(const ::ad::map::point::ParaPointList &x)
{
  return PyVec(x);
}

template <> inline PyObject *Py(const std::vector<::ad::map::point::ParaPointList> &x)
{
  return PyVec(x);
}

template <> inline PyObject *Py(const ::ad::map::point::ENUCoordinate &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::ENUHeading &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::ENUPoint &p)
{
  return PyTuple_Pack(3, Py(p.x), Py(p.y), Py(p.z));
}

template <> inline PyObject *Py(const ::ad::map::point::ENUEdge &x)
{
  return PyVec(x);
}

template <> inline PyObject *Py(const ::ad::map::point::Longitude &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::Latitude &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::Altitude &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::GeoPoint &x)
{
  return PyTuple_Pack(3, Py(x.longitude), Py(x.latitude), Py(x.altitude));
}

template <> inline PyObject *Py(const ::ad::map::point::GeoEdge &x)
{
  return PyVec(x);
}

template <> inline PyObject *Py(const ::ad::map::point::ECEFCoordinate &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::map::point::ECEFPoint &p)
{
  return PyTuple_Pack(3, Py(p.x), Py(p.y), Py(p.z));
}

template <> inline PyObject *Py(const ::ad::map::point::ECEFEdge &x)
{
  return PyVec(x);
}

inline PyObject *PyConv(const ::ad::map::point::ECEFPoint &x)
{
  ::ad::map::point::GeoPoint geo = ::ad::map::point::toGeo(x);
  return Py(geo);
}
