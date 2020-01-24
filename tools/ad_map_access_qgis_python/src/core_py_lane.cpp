// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/lane/Operation.hpp>
#include "core_py_utils.h"
#include "core_python.h"
#include "py_lane.h"
#include "py_point.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *GetLaneIds(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  lane::LaneIdList lane_ids;
  if (PyTuple_Check(args))
  {
    uint64_t part_id = 0;
    std::string filter;
    bool is_hov = false;
    bool params_ok = true;
    bool b_part_id = false;
    bool b_filter = false;
    bool b_is_hov = false;
    for (Py_ssize_t i = 0; params_ok && i < 3; i++)
    {
      if (PyTuple_Size(args) > static_cast<int>(i))
      {
        if (GetBool(PyTuple_GetItem(args, i), is_hov))
        {
          if (b_is_hov)
          {
            params_ok = false;
            PyErr_SetString(PyExc_RuntimeError, "Duplicated HOV argument.");
          }
          else
          {
            b_is_hov = true;
          }
        }
        else if (GetUInt64(PyTuple_GetItem(args, i), part_id))
        {
          if (b_part_id)
          {
            params_ok = false;
            PyErr_SetString(PyExc_RuntimeError, "Duplicated Tile Id argument.");
          }
          else
          {
            b_part_id = true;
          }
        }
        else if (GetString(PyTuple_GetItem(args, i), filter))
        {
          if (b_filter)
          {
            params_ok = false;
            PyErr_SetString(PyExc_RuntimeError, "Duplicated Filter argument.");
          }
          else
          {
            b_filter = true;
          }
        }
        else
        {
          params_ok = false;
          PyErr_SetString(PyExc_RuntimeError, "Invalid argument type.");
        }
      }
      else
      {
        break;
      }
    }
    if (params_ok)
    {
      PyErr_Clear();
      if (!b_part_id)
      {
        if (!b_filter && !b_is_hov)
        {
          lane_ids = access::getStore().getLanes();
        }
        else
        {
          lane_ids = access::getStore().getLanes(filter.c_str(), is_hov);
        }
      }
      else
      {
        if (!b_filter && !b_is_hov)
        {
          lane_ids = access::getStore().getLanes(access::PartitionId(part_id));
        }
        else
        {
          lane_ids = access::getStore().getLanes(access::PartitionId(part_id), filter.c_str(), is_hov);
        }
      }
    }
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  return PyVec(lane_ids);
}

PyObject *RemovePartition(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  uint64_t part_id;
  if (GetUInt64(args, part_id))
  {
    access::getStore().removePartition(access::PartitionId(part_id));
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *GetLane(PyObject * /*self*/, PyObject *py_lane_id)
{
  PyErr_Clear();
  lane::Lane::ConstPtr lane = GetLane(py_lane_id);
  if (lane)
  {
    return Py(lane);
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *GetLaneEdgeLeft(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, true, CoordSys::LLA);
}

PyObject *GetLaneEdgeRight(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, false, CoordSys::LLA);
}

PyObject *GetLaneSubEdgeLeft(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, true, CoordSys::LLA);
}

PyObject *GetLaneSubEdgeRight(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, false, CoordSys::LLA);
}

PyObject *GetLaneEdgeLeftECEF(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, true, CoordSys::ECEF);
}

PyObject *GetLaneEdgeRightECEF(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, false, CoordSys::ECEF);
}

PyObject *GetLaneSubEdgeLeftECEF(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, true, CoordSys::ECEF);
}

PyObject *GetLaneSubEdgeRightECEF(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, false, CoordSys::ECEF);
}

PyObject *GetLaneEdgeLeftENU(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, true, CoordSys::ENU);
}

PyObject *GetLaneEdgeRightENU(PyObject * /*self*/, PyObject *args)
{
  return GetLaneEdge(args, false, CoordSys::ENU);
}

PyObject *GetLaneSubEdgeLeftENU(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, true, CoordSys::ENU);
}

PyObject *GetLaneSubEdgeRightENU(PyObject * /*self*/, PyObject *args)
{
  return GetLaneSubEdge(args, false, CoordSys::ENU);
}

PyObject *GetLaneParamPoint(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 3))
  {
    physics::ParametricValue tlon = GetParametricValue(PyTuple_GetItem(args, 1));
    if (tlon.isValid())
    {
      physics::ParametricValue tlat = GetParametricValue(PyTuple_GetItem(args, 2));
      if (tlat.isValid())
      {
        lane::Lane::ConstPtr lane = GetLane(PyTuple_GetItem(args, 0));
        if (lane)
        {
          point::ECEFPoint ecef = lane::getParametricPoint(*lane, tlon, tlat);
          if (point::isValid(ecef))
          {
            return Py(point::toGeo(ecef));
          }
          else
          {
            PyErr_SetString(PyExc_RuntimeError, "Can't calculate parametric point.");
          }
        }
      }
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
