#include <pybind11/pybind11.h>

namespace py = pybind11;

class MyClass {
public:
  static int static_method(int a, int b) {
    return a + b;
  }
};

PYBIND11_MODULE(example, m) {
  py::class_<MyClass>(m, "MyClass")
      .def_static("static_method", &MyClass::static_method);
}
