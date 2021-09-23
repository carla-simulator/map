# General build instructions

## Dependencies
The components within this repository have some dependencies:

 - **ad_physics**:
   - spdlog: <https://github.com/gabime/spdlog.git>
   - **ad_physics_python** (if Python binding build enabled):
     - Python lib
     - castxml, pygccxml and py++
 - **ad_map_opendrive_reader**:
   - Boost
   - pugixml
   - proj: <https://www.osgeo.org/projects/proj/>
 - **ad_map_access**:
   - spdlog: <https://github.com/gabime/spdlog.git>
   - Boost (including components filesystem and  program_options)
   - *ad_map_opendrive_reader*
   - *ad_physics*
   - **ad_map_access_python** (if Python binding build enabled):
     - *ad_physics_python*
     - Python lib
     - castxml, pygccxml and py++
 - **ad_map_access_test_support**:
   - *ad_map_access*
 - **map_maker** (in tools):
   - *ad_map_access*
   - LAPACK
   - Osmium >= 2.13: <https://osmcode.org/libosmium/>
 - ***all components when enabling unit tests***:
   - gtest aka. googletests < 1.10 : <https://github.com/google/googletest>
   - xmlrunner

Dependencies provided by Ubunutu (>= 18.04):

 - Boost
 - pugixml
 - libproj-dev
 - gtest
 - libpython-dev
 - libosmium2-dev
 - liblapacke-dev

Those can be installed by calling:
```bash
$>  sudo apt-get install libboost-all-dev libpugixml-dev libgtest-dev libpython-dev libosmium2-dev liblapacke-dev libproj-dev
```

Additional dependencies for the python bindings:
```bash
$>  sudo apt-get install castxml
$>  pip install --user python-wheel pygccxml pyplusplus xmlrunner
```

Remaining dependencies are present as GIT submodules; also to fix the version of these:

 - spdlog

## Building
For compiling all libraries and the dependencies, colcon is used [colcon](https://colcon.readthedocs.io/).
Please use the link above for installation instructions.

This repository is prepared as colcon workspace including all dependencies not provided as installable packages by the OS.
Those dependencies are part of the __dependencies__ folder as GIT submodules. To properly fetch these, the submodules have to be updated and initialized.
```bash
 map$>  git submodule update --init
```

Once this is done, the full set of dependencies and components can be built calling:
```bash
 map$> colcon build
```
All components will be compiled respecting the dependencies between them.

The python bindings are disabled by default. To integrate them into the build you can make use of the prepared
colcon meta file:
```bash
 map$> colcon build --metas colcon_python.meta
```
__colcon_python.meta__ enables python build (-DBUILD_PYTHON_BINDING=ON). To specify the python version to be used you call e.g.:
```bash
 map$> colcon build --metas colcon_python.meta --cmake-args -DPYTHON_BINDING_VERSION=3.8
```

If cmake isn't able to find the requested python version you can try to specify the python executable explicitly (e.g. under Ubuntu18.04):
```bash
 map$> colcon build --metas colcon_python.meta --cmake-args -DPYTHON_BINDING_VERSION=3.6 -DPYTHON_EXECUTABLE:FILEPATH=/usr/bin/python3.6
```

The QGIS Plugin also requires the python build to be enabled
(you have to adapt to your python version used):
```bash
 map$> colcon build --metas colcon_python.meta
 map$> echo "Setting PYTHONPATH and LD_LIBRARY_PATH:"
 map$> source install/setup.bash
 map$> echo "QGIS plugin built! Let's test it out:"
 map$> export QGIS_PLUGINPATH=<path/to/>map/install/ad_map_access_qgis/share/qgis/python/plugins
 map$> qgis
```
You should have seen 'CARLA ad_map_access Plug-in loaded' on successful loading of the plugin by qgis.

## Build options
There are some CMake options affecting what or how the components are built.

 - BUILD_TESTING: Enables unit tests compilation
 - BUILD_APIDOC: Enables API documentation building
 - BUILD_HARDENING: Enables hardening compiler and linker flags
 - BUILD_PYTHON_BINDING: Enables the build of the respective python bindings
 - PYTHON_BINDING_VERSION: Select the python version to use explicitly e.g. "3.8". (Note: If that's not one of the system installed python versions,
   you have to ensure that the boost-python binding for that python version is available!)

By default, all options are set to off. Any of these could be activate by adding them via the colcon call above as "--cmake-args -D&lt;OPTION&gt;=[ON|OFF]",
e.g.:
```bash
 map$> colcon build --cmake-args -DBUILD_TESTING=ON -DBUILD_APIDOC=ON -DBUILD_PYTHON_BINDING=ON -DPYTHON_BINDING_VERSION=3.8
```

### Unit tests
```bash
 map$> colcon build --cmake-args -DBUILD_TESTING=ON
```
When activating the Unit tests, they all can be executed with:
```bash
 map$> colcon test
```

### API documentation
When BUILD_APIDOC is enabled, the "colcon" call will automatically generate the API documentation.
```bash
 map$> colcon build --cmake-args -DBUILD_APIDOC=ON
```
The API documentation is written to the _apidoc_ folder within the _build_ directory.

### Build hardening
Usually, build hardening is injected by the surrounding build system. Nevertheless, the CMakeLists.txt defines
hardening flags to ensure the code is compatible to respective flags. To enable hardening compiler and linker flags:
```bash
 map$> colcon build --cmake-args -DBUILD_HARDENING=ON
```
