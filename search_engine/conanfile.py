from conan import ConanFile


class SearchEngine(ConanFile):
    name = "SearchEngine"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("imgui-sfml/2.6.1")

        self.requires("jsoncpp/1.9.6")
        self.requires("gtest/1.16.0")
