/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2020-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#include <chrono>
#include <iostream>
#include "boost/python.hpp"

namespace bp = boost::python;

static int64_t get_seconds(const ::std::chrono::system_clock::time_point &self)
{
  auto nanoseconds = std::chrono::nanoseconds(self.time_since_epoch()).count();
  return nanoseconds / std::nano::den;
}

static int64_t get_nanoseconds(const ::std::chrono::system_clock::time_point &self)
{
  auto nanoseconds = std::chrono::nanoseconds(self.time_since_epoch()).count();
  return nanoseconds % std::nano::den;
}

static void set_time(::std::chrono::system_clock::time_point &self, int64_t seconds, int64_t nanoseconds)
{
  self = std::chrono::system_clock::time_point(std::chrono::seconds(seconds) + std::chrono::nanoseconds(nanoseconds));
}

static void set_time_double(::std::chrono::system_clock::time_point &self, double seconds_since_epoch)
{
  int64_t seconds = int64_t(seconds_since_epoch);
  int64_t nanoseconds = int64_t((seconds_since_epoch - (double)seconds) * std::nano::den);
  self = std::chrono::system_clock::time_point(std::chrono::seconds(seconds) + std::chrono::nanoseconds(nanoseconds));
}

namespace std {
namespace chrono {

std::ostream &operator<<(std::ostream &out, const ::std::chrono::system_clock::time_point &self)
{
  out << "seconds:" << get_seconds(self) << " nanoseconds:" << get_nanoseconds(self);
  return out;
}
} // namespace chrono
} // namespace std

void export_time_point()
{
  bp::object ad_physics_module(bp::handle<>(bp::borrowed(PyImport_AddModule("physics"))));
  bp::scope().attr("physics") = ad_physics_module;
  bp::scope submodule_scope = ad_physics_module;

  bp::class_<::std::chrono::system_clock::time_point>("time_point")
    .add_property("seconds", &get_seconds)
    .add_property("nanoseconds", &get_nanoseconds)
    .def("set_time", &set_time, (bp::arg("seconds"), bp::arg("nanoseconds")))
    .def("set_time", &set_time_double, (bp::arg("seconds_since_epoch")))
    .def(bp::self_ns::str(bp::self_ns::self));
}
