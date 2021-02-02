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
 - **ad_map_access_qgis_python (in tools)**:
   - *ad_map_access*
   - Python lib
 - **map_maker** (in tools):
   - *ad_map_access*
   - LAPACK
   - Osmium >= 2.13: <https://osmcode.org/libosmium/>
 - ***all components when enabling unit tests***:
   - gtest aka. googletests < 1.10 : <https://github.com/google/googletest>
   - xmlrunner

Dependencies provided by Ubunutu (>= 16.04):

 - Boost
 - pugixml
 - gtest
 - libpython-dev
 - libosmium2-dev
 - liblapacke-dev

Those can be installed by calling:
```bash
$>  sudo apt-get install libboost-all-dev libpugixml-dev libgtest-dev libpython-dev libosmium2-dev liblapacke-dev
```

Additional dependencies for the python bindings:
```bash
$>  sudo apt-get install castxml
$>  pip install --user pygccxml pyplusplus xmlrunner
```

Remaining dependencies are present as GIT submodules; also to fix the version of these:

 - spdlog
 - proj

## Building
For compiling all libraries (and potentially also some dependencies), it is suggested to use [colcon](https://colcon.readthedocs.io/).
Please use the link above for installation instructions.

This repository is prepared as colcon workspace including all dependencies not provided as installable packages by the OS.
Those dependencies are part of the __dependencies__ folder as GIT submodules. To properly fetch these, the submodules have to be updated and initialized.
```bash
 map$>  git submodule update --init
```

### Colcon build
Once this is done, the full set of dependencies and components can be built calling:
```bash
 map$> colcon build
```
All components will be compiled respecting the dependencies between them.

There are some CMake options affecting what or how the components are built.
These can be applied to all components by appending them to the call (together with the additional --cmake-args):
```bash
 map$> colcon build --cmake-args -DBUILD_TESTING=ON
```
When activating the Unit tests, they all can be executed with:
```bash
 map$> colcon test
```

The python bindings are disabled by default. To integrate them into the build you can make use of the prepared
colcon meta file:
```bash
 map$> colcon build --metas colcon_python.meta
```
__colcon_python.meta__ enables python build (-DBUILD_PYTHON_BINDING=ON) and
as well static build (-DBUILD_SHARED_LIBS=OFF) to ease the usage of the python modules
as they don't require extending the LD_LIBRARY_PATH when linked statically against its non-system dependencies.

Furthermore, building the QGIS Plugin is also encouraged with static libraries for the same reason. To build this one you might want to call
(you have to adapt to your python version used):
```bash
 map$> colcon build --metas colcon_python.meta --packages-up-to ad_map_access_qgis --build-base build-static --install-base install-static
 map$> echo "QGIS plugin built! Let's test it out:"
 map$> export PYTHONPATH=<path/to/>map/install-static/ad_map_access/lib/python3.6
 map$> export QGIS_PLUGINPATH=<path/to/>map/install-static/ad_map_access_qgis/share/qgis/python/plugins
 map$> qgis
```
You should have seen 'Intel AD Map Plug-in loaded' on successful loading of the plugin by qgis. For sure you don't require to change build and install folders.
But like this, you can have the pure-static (python) builds separated from the standard shared library builds.

### Plain CMake build
The ad_map_access (same applies to the other libraries) library is built with a standard cmake toolchain.

!!! Note
  To enable Python bindings, you will need to set ```-DBUILD_PYTHON_BINDING=ON``` for ```ad_physics``` and ```ad_map_access```. See [Python Bindings](#python-binding) for more info.

Therefore, a full list of step by step calls could look like e.g.:

```bash
 # Creating directories
 map$> mkdir install
 map$> mkdir -p build/{proj,spdlog,ad_physics,ad_map_opendrive_reader,ad_map_access}

 # Build proj
 map$> cd build/proj
 map/build/proj$> cmake ../../dependencies/PROJ -DCMAKE_INSTALL_PREFIX=../../install/proj -DCMAKE_POSITION_INDEPENDENT_CODE=ON
 map/build/proj$> make install

 # Build spdlog
 map$> cd ../spdlog
 map/build/spdlog$> cmake ../../dependencies/spdlog -DCMAKE_INSTALL_PREFIX=../../install/spdlog -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DSPDLOG_BUILD_TESTS=OFF -DSPDLOG_BUILD_EXAMPLE=OFF
 map/build/spdlog$> make install

 # Build ad_physics
 map/build/spdlog$> cd ../ad_physics
 map/build/ad_physics$> cmake ../../ad_physics -DCMAKE_INSTALL_PREFIX=../../install/ad_physics -DCMAKE_PREFIX_PATH=../../install/spdlog
 map/build/ad_physics$> make install

 # Build ad_map_opendrive_reader
 map/build/ad_physics$> cd ../ad_map_opendrive_reader
 map/build/ad_map_opendrive_reader$> cmake ../../ad_map_opendrive_reader -DCMAKE_INSTALL_PREFIX=../../install/ad_map_opendrive_reader -DCMAKE_PREFIX_PATH="../../install/proj;../../install/spdlog;../../install/ad_physics"
 map/build/ad_map_opendrive_reader$> make install

 # Build ad_map_access
 map/build/ad_map_opendrive_reader$> cd ../ad_map_access
 map/build/ad_map_access$> cmake ../../ad_map_access -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access -DCMAKE_PREFIX_PATH="../../install/proj;../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader"
 map/build/ad_map_access$> make install
 map/build/ad_map_access$> cd ../..
 map$> echo "Hurray, all built!"
```

#### map_maker tools
Building the map_maker tools in addition then looks like:
```bash
 map$> mkdir -p build/map_maker
 map$> cd build/map_maker
 map/build/map_maker$> cmake ../../tools/map_maker -DCMAKE_INSTALL_PREFIX=../../install/map_maker -DCMAKE_PREFIX_PATH="../../install/ad_map_access;../../install/ad_map_opendrive_reader;../../install/ad_physics;../../install/spdlog"
 map/build/map_maker$> make install
 map/build/map_maker$> cd ../..
 map$> echo "Hurray, map maker tools built!"
```

#### QGIS plugin
Building the QGIS plugin in addition then looks like:
```bash
 map$> mkdir -p build/{ad_map_access_qgis_python,ad_map_access_qgis}
 map$> cd build/ad_map_access_qgis_python
 map/build/ad_map_access_qgis_python$> cmake ../../tools/ad_map_access_qgis_python -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access_qgis_python -DCMAKE_PREFIX_PATH="../../install/proj;../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader;../../install/ad_map_access"
 map/build/ad_map_access_qgis_python$> make install
 map/build/ad_map_access_qgis_python$> cd ../ad_map_access_qgis
 map/build/ad_map_access_qgis$> cmake ../../tools/ad_map_access_qgis -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access_qgis
 map/build/ad_map_access_qgis$> make install
 map/build/ad_map_access_qgis$> cd ../..
 map$> echo "Hurray, QGIS plugin built! Let's try to run it:"
 map$> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<path/to/>map/install/spdlog/lib:<path/to/>map/install/ad_physics/lib:<path/to/>map/install/ad_map_opendrive_reader/lib:<path/to/>map/install/ad_map_access/lib:<path/to/>map/install/ad_map_access_qgis_python/lib
 map$> export QGIS_PLUGINPATH=<path/to/>map/install/ad_map_access_qgis/share/qgis/python/plugins
 map$> qgis
 map$> echo "We should have seen 'Intel AD Map Plug-in loaded' on success"
```

If building all libraries (ad_physics,ad_map_opendrive_reader,ad_map_access) with static build option "-DBUILD_SHARED_LIBS=OFF", the LD_LIBRARY_PATH can be left out. Sometimes we observed that the integrated copy step of the 'ad_map_access_qgis_python.so' fails, so that in addition setting of the 'export PYTHONPATH=$PYTHONPATH:<path/to/>map/install/lib/ad_map_access_qgis/python2.7/' coud become necessary.

## CMake options
There are some build options available:

 - BUILD_TESTING: Enables unit tests compilation
 - BUILD_APIDOC: Enables API documentation building
 - BUILD_HARDENING: Enables hardening compiler and linker flags
 - BUILD_PYTHON_BINDING: Enables the build of the respective python bindings
 - PYTHON_BINDING_VERSIONS: standard search for python boost bindings is for multiple versions e.g. "2.7 3.5 3.6. 3.7" (see cmake/python-binding.cmake for details); this search can be restricted from outside if this variable is set

By default, all options are set to off. Any of these could be activate by adding them to the initial cmake call above as "-D<OPTION>=[ON|OFF]",
e.g. "-DBUILD_TESTING=ON -DBUILD_APIDOC=ON".

#### Unit tests
When BUILD_TESTING is enabled, the "make" call will automatically compile the Unit tests.
They can be executed using CMake's ctest application.
```bash
 map/build/ad_map_access$> cmake ../../ad_map_access -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access -DCMAKE_PREFIX_PATH="../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader" -DBUILD_TESTING=ON
 map/build/ad_map_access$> make install
 map/build/ad_map_access$> ctest
```
#### API documentation
When BUILD_APIDOC is enabled, the "make" call will automatically generate the API documentation.
```bash
 map/build/ad_map_access$> cmake ../../ad_map_access -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access -DCMAKE_PREFIX_PATH="../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader" -DBUILD_APIDOC=ON
 map/build/ad_map_access$> make install
```
The API documentation is written to the _apidoc_ folder within the _build_ directory.

#### Build hardening
Usually, build hardening is injected by the surrounding build system. Nevertheless, the CMakeLists.txt defines
hardening flags to ensure the code is compatible to respective flags. To enable hardening compiler and linker flags:
```bash
 map/build/ad_map_access$> cmake ../../ad_map_access -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access -DCMAKE_PREFIX_PATH="../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader" -DBUILD_HARDENING=ON
 map/build/ad_map_access$> make install
```

#### Python binding
With this option enabled, Python bindings are generated and compiled.
When compiling Python bindings it's recommended to build and link the other
libraries statically to prevent from dependencies on the LD_LIBRARY_PATH at execution time.
This option is disabled by default.
You have to enable the python binding also on the respective dependent component. ad_physics in this case.
```bash
 map/build/ad_map_access$> cmake ../../ad_map_access -DCMAKE_INSTALL_PREFIX=../../install/ad_map_access -DCMAKE_PREFIX_PATH="../../install/spdlog;../../install/ad_physics;../../install/ad_map_opendrive_reader" -DBUILD_PYTHON_BINDING=ON -DBUILD_SHARED_LIBS=OFF
 map/build/ad_map_access$> make install
```

## **FAQ**
### **Error "relocation R_X86_64_PC32 against symbol '...' can not be used when making a shared object; recompile with -fPIC" when building**
Try adding the flag ```-DCMAKE_POSITION_INDEPENDENT_CODE=ON``` to cmake
