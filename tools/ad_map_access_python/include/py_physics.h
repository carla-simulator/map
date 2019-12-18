// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/physics/Types.hpp>
#include "py_utils.h"

template <> inline PyObject *Py(const ::ad::physics::Speed &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::physics::ParametricValue &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::physics::Distance &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::physics::RatioValue &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}

template <> inline PyObject *Py(const ::ad::physics::Probability &x)
{
  return PyFloat_FromDouble(static_cast<double>(x));
}
