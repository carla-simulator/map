// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <ad/map/access/Types.hpp>
#include "py_utils.h"

template <> inline PyObject *Py(const ::ad::map::access::TrafficType &x)
{
  return PyEnum(x, "::ad::map::access::TrafficType::");
}

template <> inline PyObject *Py(const ::ad::map::access::MapMetaData &x)
{
  return PyTuple_Pack(1, Py(x.trafficType));
}

template <> inline PyObject *Py(const ::ad::map::access::PartitionId &x)
{
  return Py(static_cast<uint64_t>(x));
}
