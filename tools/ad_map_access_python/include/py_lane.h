// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/lane/Types.hpp>
#include "py_utils.h"

template <> PyObject *Py(const ::ad::map::lane::ContactType &x);

template <> PyObject *Py(const ::ad::map::lane::LaneType &x);

template <> PyObject *Py(const ::ad::map::lane::LaneDirection &x);

template <> inline PyObject *Py(const ::ad::map::lane::LaneId &x)
{
  return Py(static_cast<uint64_t>(x));
}

PyObject *Py(::ad::map::lane::Lane::ConstPtr lane);
template <> PyObject *Py(const ::ad::map::lane::ContactLane &contact_lane);
