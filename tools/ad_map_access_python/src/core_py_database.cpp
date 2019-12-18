// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <string>

#include <ad/map/access/Operation.hpp>
#include <ad/map/opendrive/AdMapFactory.hpp>
#include <ad/map/serialize/SerializerFileCRC32.hpp>
#include "core_python.h"
#include "py_access.h"
#include "py_utils.h"

using namespace ::ad;
using namespace ::ad::map;

PyObject *Open(PyObject * /*self*/, PyObject *py_config_string)
{
  PyErr_Clear();
  if (py_config_string != nullptr)
  {
    const char *config_string = PyString_AsString(py_config_string);
    if (config_string != nullptr && *config_string != '\0')
    {
      access::Store::Ptr store(new access::Store());
      bool storeFilled = false;
      if (ad::map::opendrive::AdMapFactory::isOpenDriveMap(config_string))
      {
        ad::map::opendrive::AdMapFactory factory(*store);
        double const overlapMargin = 0.2;
        auto const defaultIntersectionType = ad::map::intersection::IntersectionType::Unknown;
        storeFilled = factory.createAdMap(config_string, overlapMargin, defaultIntersectionType);
        if (!storeFilled)
        {
          PyErr_SetString(PyExc_RuntimeError, "Reading OpenDRIVE map failed!");
        }
      }
      else
      {
        serialize::SerializerFileCRC32 serializer(false);
        size_t version_major = 0, version_minor = 0;
        if (serializer.open(config_string, version_major, version_minor))
        {
          if (store->load(serializer))
          {
            storeFilled = serializer.close();
            if (!storeFilled)
            {
              PyErr_SetString(PyExc_RuntimeError, "CRC-32 Checksum Mismatch!");
            }
          }
          else
          {
            PyErr_SetString(PyExc_RuntimeError, "Error while deserializing Map.");
          }
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Can't open Map file.");
        }
      }

      if (storeFilled)
      {
        if (access::init(store))
        {
          Py_RETURN_TRUE;
        }
        else
        {
          PyErr_SetString(PyExc_RuntimeError, "Initialization from store failed!");
        }
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "No mapfilename given!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing configuration string!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_FALSE;
}

PyObject *Close(PyObject * /*self*/, PyObject * /*args*/)
{
  PyErr_Clear();
  access::cleanup();
  Py_RETURN_NONE;
}

PyObject *GetMetaData(PyObject * /*self*/, PyObject * /*args*/)
{
  PyErr_Clear();
  access::MapMetaData map_meta_data = access::getStore().getMetaData();
  return Py(map_meta_data);
}

PyObject *GetPartitions(PyObject * /*self*/, PyObject * /*args*/)
{
  PyErr_Clear();
  access::PartitionIdList part_ids = access::getStore().getPartitions();
  return PyVec(part_ids);
}
