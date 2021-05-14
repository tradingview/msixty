from conans import ConanFile, CMake, tools
from conans.errors import ConanInvalidConfiguration
import os


class MsixtyConan(ConanFile):
    name = "msixty"
    license = "Proprietary"
    url = "https://github.com/tradingview/msixty"
    description = "Making your MSIX experience ten times better!"
    topics = ("msix", "installer", "bootstrapper")

    settings = "os", "compiler", "build_type", "arch"
    revision_mode = "scm"
    exports_sources = [
        "src/*",
        "CMakeLists.txt"
    ]
    generators = "cmake"

    requires = "wtl/10.0.9163"
    build_requires = "cmake/3.17.1"

    no_copy_source = True

    def configure(self):
        if self.settings.os != "Windows":
            raise ConanInvalidConfiguration("Only Windows is supported at the moment")
        tools.check_min_cppstd(self, "17")

    def _cmake(self):
        cmake = CMake(self)
        cmake.definitions["VERSION"] = self.version
        cmake.configure()
        
        return cmake

    def build(self):
        cmake = self._cmake()
        cmake.build()

    def package(self):
        cmake = self._cmake()
        cmake.install()

    def package_info(self):
        msixty_bin = os.path.join(self.package_folder, "bin")
        self.output.info(f"Appending PATH environment variable: {msixty_bin}")
        self.env_info.PATH.append(msixty_bin)