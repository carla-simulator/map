import sys

from setuptools import setup
from setuptools.command.install import install as _install
from setuptools.dist import Distribution


class BinaryDistribution(Distribution):
    """Distribution which always forces a binary package with platform name"""
    def has_ext_modules(self):
        return True


class Install(_install):
    def finalize_options(self):
        _install.finalize_options(self)
        if self.distribution.has_ext_modules():
            self.install_lib = self.install_platlib


setup(
    name="ad-physics",
    packages=["ad_physics"],
    package_dir={"": sys.argv.pop(-1)},
    package_data={"ad_physics": ["*.so"]},
    version="2.4.5",
    description="AD Physics library ",
    distclass=BinaryDistribution,
    cmdclass={'install': Install}
)
