// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <string>

#include <ad/map/access/Logging.hpp>
#include "core_python.h"

using ::ad::map::access::getLogger;

PyObject *LogDebug(PyObject * /*self*/, PyObject *py_message)
{
  PyErr_Clear();
  if (py_message != nullptr)
  {
    const char *message = PyString_AsString(py_message);
    if (message != nullptr && *message != '\0')
    {
      getLogger()->debug(message);
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Empty Debug message!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing Debug message!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogInfo(PyObject * /*self*/, PyObject *py_message)
{
  PyErr_Clear();
  if (py_message != nullptr)
  {
    const char *message = PyString_AsString(py_message);
    if (message != nullptr && *message != '\0')
    {
      getLogger()->info(message);
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Empty Info message!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing Info message!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogWarning(PyObject * /*self*/, PyObject *py_message)
{
  PyErr_Clear();
  if (py_message != nullptr)
  {
    const char *message = PyString_AsString(py_message);
    if (message != nullptr && *message != '\0')
    {
      getLogger()->warn(message);
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Empty Warning message!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing Warning message!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogError(PyObject * /*self*/, PyObject *py_message)
{
  PyErr_Clear();
  if (py_message != nullptr)
  {
    const char *message = PyString_AsString(py_message);
    if (message != nullptr && *message != '\0')
    {
      getLogger()->error(message);
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Empty Error message!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing Error message!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogInternalError(PyObject * /*self*/, PyObject *py_message)
{
  PyErr_Clear();
  if (py_message != nullptr)
  {
    const char *message = PyString_AsString(py_message);
    if (message != nullptr && *message != '\0')
    {
      getLogger()->critical(message);
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Empty Internal Error message!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Missing Internal Error message!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogLevel(PyObject * /*self*/, PyObject *py_level)
{
  PyErr_Clear();
  if (py_level != nullptr)
  {
    if (PyInt_Check(py_level))
    {
      spdlog::level::level_enum level = static_cast<spdlog::level::level_enum>(PyInt_AsLong(py_level));
      if (spdlog::level::trace <= level && level < spdlog::level::off)
      {
        getLogger()->set_level(level);
      }
      else
      {
        PyErr_SetString(PyExc_RuntimeError, "Out-of-range argument to LogLevel()!");
      }
    }
    else
    {
      PyErr_SetString(PyExc_RuntimeError, "Expecting integer argument to LogLevel()!");
    }
  }
  else
  {
    PyErr_SetString(PyExc_RuntimeError, "Expecting integer argument to LogLevel()!");
  }
  if (PyErr_Occurred() != nullptr)
  {
    PyErr_Print();
  }
  Py_RETURN_NONE;
}

PyObject *LogFileName(PyObject * /*self*/, PyObject * /*args*/)
{
  static std::string log_file_name;
  return PyString_FromString(log_file_name.c_str());
}
