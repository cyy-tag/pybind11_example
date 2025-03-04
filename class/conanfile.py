from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class Pybind11Example(ConanFile):
    name = "pybind11_example"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("pybind11/2.13.6") # 指定 pybind11 的版本[^3^]
    
    def layout(self):
        cmake_layout(self)
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
    
    def package(self):
        cmake = CMake(self)
        cmake.install()
