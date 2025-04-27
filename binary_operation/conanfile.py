from conan import ConanFile


class Collisions(ConanFile):
    name = "Collisions"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("gtest/1.16.0")
