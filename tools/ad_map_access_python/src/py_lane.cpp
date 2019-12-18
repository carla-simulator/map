// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "py_lane.h"
#include <ad/map/lane/LaneOperation.hpp>
#include <vector>
#include "py_landmark.h"
#include "py_restriction.h"
#include "py_utils.h"

using namespace ::ad::map;

template <> PyObject *Py(const ::ad::map::lane::ContactType &x)
{
  return PyEnum(x, "::ad::map::lane::ContactType::");
}

template <> PyObject *Py(const ::ad::map::lane::LaneType &x)
{
  return PyEnum(x, "::ad::map::lane::LaneType::");
}

template <> PyObject *Py(const ::ad::map::lane::LaneDirection &x)
{
  return PyEnum(x, "::ad::map::lane::LaneDirection::");
}

template <> PyObject *Py(const lane::ContactLane &contact_lane)
{
  const lane::ContactTypeList &types = contact_lane.types;
  PyObject *type_list = PyList_New(0);
  for (auto typ : types)
  {
    PyList(type_list, Py(typ));
  }

  PyObject *dict = PyDict_New();
  PyDict(dict, "ToLane", Py(contact_lane.toLane));
  PyDict(dict, "Type", type_list);
  PyDict(dict, "Restriction", Py(contact_lane.restrictions));
  PyDict(dict, "TrafficLightId", Py(contact_lane.trafficLightId));
  return dict;
}

PyObject *Py(lane::Lane::ConstPtr lane)
{
  if (!lane)
  {
    Py_RETURN_NONE;
  }

  const lane::ContactLaneList lefts = lane::getContactLanes(*lane, lane::ContactLocation::LEFT);
  const lane::ContactLaneList rights = lane::getContactLanes(*lane, lane::ContactLocation::RIGHT);
  const lane::ContactLaneList successors = lane::getContactLanes(*lane, lane::ContactLocation::SUCCESSOR);
  const lane::ContactLaneList predecessors = lane::getContactLanes(*lane, lane::ContactLocation::PREDECESSOR);
  const lane::ContactLaneList overlaps = lane::getContactLanes(*lane, lane::ContactLocation::OVERLAP);

  PyObject *dict = PyDict_New();
  PyDict(dict, "Id", Py(lane->id));
  PyDict(dict, "Type", Py(lane->type));
  PyDict(dict, "Direction", Py(lane->direction));
  PyDict(dict, "Length", Py(lane->length));
  PyDict(dict, "HOV", Py(lane::getHOV(*lane)));
  PyDict(dict, "Restrictions", Py(lane->restrictions));
  PyDict(dict, "SpeedLimit", Py(lane->speedLimits));
  PyDict(dict, "ComplianceVer", Py(lane->complianceVersion));
  PyDict(dict, "Left", PyVec(lefts));
  PyDict(dict, "Right", PyVec(rights));
  PyDict(dict, "Successor", PyVec(successors));
  PyDict(dict, "Predecessor", PyVec(predecessors));
  PyDict(dict, "Overlap", PyVec(overlaps));
  return dict;
}
