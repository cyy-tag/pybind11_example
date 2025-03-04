#include <pybind11/pybind11.h>
#include <iostream>

namespace py = pybind11;

class Foo {
public:
  explicit Foo(float initial_data): data(initial_data) {
    std::cout << "Foo created with data: " << data << std::endl;
  }

  float get_data() const {
    return data;
  }

  void set_data(float new_data) {
    data = new_data;
  }

  void compute() const {
    std::cout << "Computing data squared: " << data * data << std::endl;
  }

  void cube() const {
    std::cout << "Computing data cube: " << data * data * data << std::endl;
  }

private:
  float data;
};
