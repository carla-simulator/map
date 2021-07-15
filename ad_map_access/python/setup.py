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
    name="ad-map-access",
    packages=["ad_map_access"],
    package_dir={"": sys.argv.pop(-1)},
    package_data={"ad_map_access": ["*.so"]},
    version="2.4.5",
    maintainer='CARLA Simulator Team',
    maintainer_email='carla.simulator@gmail.com',
    license='MIT',
    url="https://ad-map-access.readthedocs.io/en/latest/",
    description="python binding of the C++ Library for Accessing Automated Driving Maps",
    install_requires=["ad_physics>=2.4.5"],
    distclass=BinaryDistribution,
    cmdclass={'install': Install}
)
