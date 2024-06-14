from conan import ConanFile
from conan.tools.cmake import cmake_layout


class RandomMap(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("ftxui/5.0.0")
        self.requires("argparse/3.0")
        self.requires("ncurses/6.5")

    def layout(self):
        cmake_layout(self)
