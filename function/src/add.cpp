#include <pybind11/pybind11.h>

// 定义一个简单的C++ 函数
int add(int a, int b) {
  return a + b;
}

// 使用pybind11 绑定函数
namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  m.doc() = "Example module that binds C++ functions to Python"; // 模块说明
  m.def("add", &add, "A function that adds two numbers");
}
