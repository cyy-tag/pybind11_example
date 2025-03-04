#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../include/animal.h"

namespace py = pybind11;

// 为了在 Python 中重载虚函数，需要定义一个跳板类 PyAnimal
class PyAnimal : public Animal {
public:
    using Animal::Animal; // 继承构造函数

    std::string go(int n_times) override {
        PYBIND11_OVERRIDE_PURE(
            std::string,  // 返回类型
            Animal,       // 父类
            go,           // 虚函数名称
            n_times       // 参数
        );
    }
};


PYBIND11_MODULE(example, m) {
  py::class_<Animal, PyAnimal>(m, "Animal")
      .def(py::init<>())
      .def("go", &Animal::go);

  py::class_<Dog, Animal>(m, "Dog")
      .def(py::init<>());
}
