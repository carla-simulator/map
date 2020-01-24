// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Factory.hpp>
#include <ad/map/access/Operation.hpp>
#include <ad/map/lane/Operation.hpp>
#include <ad/map/point/Operation.hpp>
#include <algorithm>
#include <cctype>
#include "ad/physics/SpeedValidInputRange.hpp"
#include "core_py_utils.h"
#include "core_python.h"
#include "py_lane.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *SetLaneDirection(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      std::string direction;
      if (GetString(PyTuple_GetItem(args, 1), direction))
      {
        lane::LaneDirection dir = fromString<lane::LaneDirection>(direction);
        if (dir != lane::LaneDirection::INVALID)
        {
          access::Factory factory(access::getStore());
          if (factory.set(lane_id, dir))
          {
            Py_RETURN_TRUE;
          }
          else
          {
            Py_RETURN_FALSE;
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Invalid direction string!");
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Expecting direction string parameter!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid lane identifier!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments!");
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *SetLaneType(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      std::string type_name;
      if (GetString(PyTuple_GetItem(args, 1), type_name))
      {
        lane::LaneType typ = fromString<lane::LaneType>(type_name);
        if (typ != lane::LaneType::INVALID)
        {
          access::Factory factory(access::getStore());
          if (factory.set(lane_id, typ))
          {
            Py_RETURN_TRUE;
          }
          else
          {
            Py_RETURN_FALSE;
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Invalid lane type string!");
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Expecting lane type string parameter!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid lane identifier!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments!");
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *SetLaneSpeedLimit(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      double m_per_s;
      if (GetDouble(PyTuple_GetItem(args, 1), m_per_s))
      {
        physics::Speed speed(m_per_s);
        if (withinValidInputRange(speed) && (speed > physics::Speed(0.)))
        {
          access::Factory factory(access::getStore());
          if (factory.set(lane_id, speed))
          {
            Py_RETURN_TRUE;
          }
          else
          {
            Py_RETURN_FALSE;
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Speed limit is out of range!");
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Expecting speed limit numeric parameter!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid lane identifier!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments!");
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *SetLaneComplianceVer(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      uint64_t compliance_ver;
      if (GetUInt64(PyTuple_GetItem(args, 1), compliance_ver))
      {
        access::Factory factory(access::getStore());
        lane::ComplianceVersion cv(compliance_ver);
        if (factory.set(lane_id, cv))
        {
          Py_RETURN_TRUE;
        }
        else
        {
          Py_RETURN_FALSE;
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Expecting compliance integer parameter!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid lane identifier!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Invalid number of arguments!");
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *DeleteLane(PyObject * /*self*/, PyObject *py_lane_id)
{
  PyErr_Clear();
  lane::LaneId lane_id = GetLaneId(py_lane_id);
  if (lane_id.isValid())
  {
    access::Factory factory(access::getStore());
    if (factory.deleteLane(lane_id))
    {
      Py_RETURN_TRUE;
    }
    else
    {
      Py_RETURN_FALSE;
    }
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *DeleteContacts(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      lane::LaneId to_lane_id = GetLaneId(PyTuple_GetItem(args, 1));
      if (to_lane_id.isValid())
      {
        access::Factory factory(access::getStore());
        if (factory.deleteContacts(lane_id, to_lane_id))
        {
          Py_RETURN_TRUE;
        }
        else
        {
          Py_RETURN_FALSE;
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Invalid second lane identifier!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid first lane identifier!");
    }
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *AddContact(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 3))
  {
    lane::LaneId lane_id = GetLaneId(PyTuple_GetItem(args, 0));
    if (lane_id.isValid())
    {
      lane::LaneId to_lane_id = GetLaneId(PyTuple_GetItem(args, 1));
      if (to_lane_id.isValid())
      {
        std::string sz;
        if (GetString(PyTuple_GetItem(args, 2), sz))
        {
          lane::ContactLocation location = fromString<lane::ContactLocation>(sz);
          if (location != lane::ContactLocation::INVALID)
          {
            lane::Lane::ConstPtr lane = lane::getLanePtr(lane_id);
            if (lane)
            {
              lane::ContactLocation curr_loc = lane::getContactLocation(*lane, to_lane_id);
              if (curr_loc == lane::ContactLocation::INVALID)
              {
                access::Factory factory(access::getStore());
                restriction::Restrictions restrs;
                lane::ContactTypeList types = {lane::ContactType::FREE};
                if (factory.add(lane_id, to_lane_id, location, types, restrs))
                {
                  Py_RETURN_TRUE;
                }
                else
                {
                  PyErr_SetString(PyExc_RuntimeError, "Can't connect lanes!");
                }
              }
              else
              {
                PyErr_SetString(PyExc_RuntimeError, "Lanes already connected!");
              }
            }
            else
            {
              PyErr_SetString(PyExc_RuntimeError, "Non-existent 'from' lane!");
            }
          }
          else
          {
            PyErr_SetString(PyExc_RuntimeError, "Invalid topology designator!");
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Expecting string as third argument!");
        }
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Invalid second lane identifier!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Invalid first lane identifier!");
    }
  }
  PyErr_Print();
  Py_RETURN_FALSE;
}

PyObject *AddLane(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  if (ExpectArgs(args, 2))
  {
    point::GeoEdge geo_points_0;
    if (GetGeoPoints(PyTuple_GetItem(args, 0), geo_points_0, true))
    {
      point::GeoEdge geo_points_1;
      if (GetGeoPoints(PyTuple_GetItem(args, 1), geo_points_1, true))
      {
        lane::LaneId lane_id;
        if (!point::haveSameOrientation(geo_points_0, geo_points_1))
        {
          std::reverse(geo_points_1.begin(), geo_points_1.end());
        }
        access::Factory factory(access::getStore());
        access::PartitionId part_id(0);
        if (point::isOnTheLeft(geo_points_0, geo_points_1))
        {
          lane_id = factory.add(part_id, geo_points_0, geo_points_1);
        }
        else
        {
          lane_id = factory.add(part_id, geo_points_1, geo_points_0);
        }
        if (lane_id.isValid())
        {
          return Py(lane_id);
        }
      }
    }
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
