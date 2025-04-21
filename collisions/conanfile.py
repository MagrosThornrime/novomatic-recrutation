from conan import ConanFile


class Collisions(ConanFile):
    name = "Collisions"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("sfml/2.6.2")
        self.requires("jsoncpp/1.9.6")
