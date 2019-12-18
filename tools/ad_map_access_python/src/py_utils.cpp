// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "py_utils.h"

///////////////////////
// List & Dictionaries

void PyList(PyObject *list, PyObject *x, bool mandatory)
{
  if (x == Py_None)
  {
    if (mandatory)
    {
      PyList_Append(list, Py_None);
    }
  }
  else if (x == nullptr)
  {
    if (mandatory)
    {
      PyList_Append(list, Py(std::string("<null>")));
    }
  }
  else
  {
    PyList_Append(list, x);
  }
}

void PyDict(PyObject *dict, const char *key, PyObject *x, bool mandatory)
{
  if (x == Py_None)
  {
    if (mandatory)
    {
      PyDict_SetItemString(dict, key, Py_None);
    }
  }
  else if (x == nullptr)
  {
    if (mandatory)
    {
      PyDict_SetItemString(dict, key, Py(std::string("<null>")));
    }
  }
  else
  {
    PyDict_SetItemString(dict, key, x);
  }
}
