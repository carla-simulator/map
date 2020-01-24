// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad/map/access/Operation.hpp>
#include <ad/map/landmark/Operation.hpp>
#include "core_py_utils.h"
#include "core_python.h"
#include "py_landmark.h"
#include "py_point.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *GetLandmarkIds(PyObject * /*self*/, PyObject *args)
{
  PyErr_Clear();
  landmark::LandmarkIdList landmark_ids;
  if (PyTuple_Check(args))
  {
    uint64_t part_id = 0;
    bool params_ok = true;
    bool b_part_id = false;
    for (Py_ssize_t i = 0; params_ok && i < 3; i++)
    {
      if (PyTuple_Size(args) > static_cast<int>(i))
      {
        if (GetUInt64(PyTuple_GetItem(args, i), part_id))
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
        landmark_ids = landmark::getLandmarks();
      }
      else
      {
        landmark_ids = access::getStore().getLandmarks(access::PartitionId(part_id));
      }
    }
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  return PyVec(landmark_ids);
}

PyObject *GetLandmark(PyObject * /*self*/, PyObject *py_landmark_id)
{
  PyErr_Clear();
  landmark::Landmark::ConstPtr landmark = GetLandmark(py_landmark_id);
  if (landmark)
  {
    return Py(landmark);
  }
  PyErr_Print();
  Py_RETURN_NONE;
}

PyObject *GetLandmarkPosition(PyObject * /*self*/, PyObject *py_landmark_id)
{
  return GetLandmarkPosition(py_landmark_id, CoordSys::LLA);
}

PyObject *GetLandmarkPositionECEF(PyObject * /*self*/, PyObject *py_landmark_id)
{
  return GetLandmarkPosition(py_landmark_id, CoordSys::ECEF);
}

PyObject *GetLandmarkPositionENU(PyObject * /*self*/, PyObject *py_landmark_id)
{
  return GetLandmarkPosition(py_landmark_id, CoordSys::ENU);
}

PyObject *GetLandmarkOrientationAngle(PyObject * /*self*/, PyObject *py_landmark_id)
{
  PyErr_Clear();
  landmark::Landmark::ConstPtr landmark = GetLandmark(py_landmark_id);
  if (landmark)
  {
    auto orientation = landmark::getENUHeading(*landmark);
    return Py(orientation);
  }
  PyErr_Print();
  Py_RETURN_NONE;
}
