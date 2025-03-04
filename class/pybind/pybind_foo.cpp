#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../include/foo.h"

namespace py = pybind11;

PYBIND11_MODULE(pymodule, m) {
  py::class_<Foo>(m, "Foo")
      .def(py::init<float>())
      .def("getData", &Foo::get_data)
      .def("setData", &Foo::set_data)
      .def("compute", &Foo::compute)
      .def("cube", &Foo::cube);
}
