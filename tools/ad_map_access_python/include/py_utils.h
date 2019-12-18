// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include <vector>
#include "./core_python.h"

/////////////////////
// Generic Conversion

template <typename T> PyObject *Py(const T &x) = delete;

template <class T> PyObject *PyVec(const std::vector<T> &obj_vec);

template <typename T> PyObject *Py(const std::vector<T> &obj_vec)
{
  return PyVec(obj_vec);
}

template <class T> PyObject *PyVec(const std::vector<T> &obj_vec)
{
  PyObject *list = PyList_New(0);
  for (const T &obj : obj_vec)
  {
    PyObject *py_obj = ::Py(obj);
    if (py_obj != nullptr && py_obj != Py_None)
    {
      PyList_Append(list, py_obj);
    }
  }
  return list;
}

/////////////////
// Built-in Types

template <> inline PyObject *Py(const bool &x)
{
  return PyBool_FromLong(x ? 1 : 0);
}
template <> inline PyObject *Py(const uint16_t &x)
{
  return PyLong_FromLong(x);
}
template <> inline PyObject *Py(const int32_t &x)
{
  return PyLong_FromLong(x);
}
template <> inline PyObject *Py(const uint32_t &x)
{
  return PyLong_FromLong(x);
}
template <> inline PyObject *Py(const int64_t &x)
{
  return PyLong_FromLongLong(x);
}
template <> inline PyObject *Py(const uint64_t &x)
{
  return PyLong_FromUnsignedLongLong(x);
}
template <> inline PyObject *Py(const double &x)
{
  return PyFloat_FromDouble(x);
}
template <> inline PyObject *Py(const std::string &x)
{
  return PyString_FromString(x.c_str());
}

///////////////////////
// Lists & Dictionaries

void PyList(PyObject *list, PyObject *x, bool mandatory = false);
void PyDict(PyObject *dict, const char *key, PyObject *x, bool mandatory = false);

///////////////////////
// Enums

template <typename T> PyObject *PyEnum(const T &x, const std::string &prefix)
{
  auto value = toString(x);
  if (value.find(prefix) == 0)
  {
    return Py(value.substr(prefix.length()));
  }
  return Py(value);
}
