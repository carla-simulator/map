// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/landmark/Types.hpp>
#include "py_utils.h"

template <> PyObject *Py(const ::ad::map::landmark::TrafficLightType &x);

template <> PyObject *Py(const ::ad::map::landmark::TrafficSignType &x);

template <> PyObject *Py(const ::ad::map::landmark::LandmarkType &x);

template <> inline PyObject *Py(const ::ad::map::landmark::LandmarkId &x)
{
  return Py(static_cast<uint64_t>(x));
}

PyObject *Py(::ad::map::landmark::Landmark::ConstPtr landmark);
