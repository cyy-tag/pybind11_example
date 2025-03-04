#include <pybind11/pybind11.h>
#include <pybind11/functional.h> // std::function绑定支持头文件
#include <functional>

namespace py = pybind11;

class Emitter {
public:
    // 定义一个信号
    void emitSignal(int value) {
        if (slot) {
            slot(value);
        }
    }

    // 绑定一个槽函数
    void setSlot(std::function<void(int)> slot) {
        this->slot = slot;
    }

private:
    std::function<void(int)> slot;
};

PYBIND11_MODULE(example, m) {
    py::class_<Emitter>(m, "Emitter")
        .def(py::init<>())
        .def("emitSignal", &Emitter::emitSignal)
        .def("setSlot", &Emitter::setSlot);
}
