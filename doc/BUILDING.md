# General build instructions

## Dependencies
The components within this repository have some dependencies:

 - **ad_physics**:
   - spdlog: <https://github.com/gabime/spdlog.git>
 - **ad_map_opendrive_reader**:
   - Boost
   - pugixml
   - proj: <https://www.osgeo.org/projects/proj/>
 - **ad_map_access**:
   - spdlog: <https://github.com/gabime/spdlog.git>
   - Boost (including components filesystem and  program_options)
   - *ad_map_opendrive_reader*
   - *ad_physics*
 - **ad_map_access_test_support**:
   - *ad_map_access*
 - **ad_physics_python**:
   - *ad_physics*
   - Python lib
   - castxml, pygccxml and py++
 - **ad_map_access_python**:
   - *ad_map_access*
   - *ad_physics_python*
   - Python lib
   - castxml, pygccxml and py++
 - **ad_map_access_qgis_python (in tools)**:
   - *ad_map_access*
   - Python lib
 - **map_maker** (in tools):
   - *ad_map_access*
   - Osmium >= 2.13: <https://osmcode.org/libosmium/>
 - ***all components when enabling unit tests***:
   - gtest aka. googletests < 1.10 : <https://github.com/google/googletest>

Dependencies provided by Ubunutu (>= 16.04):

 - Boost
 - pugixml
 - proj
 - gtest
 - libpython-dev
 - libosmium2-dev

Those can be installed by calling:
```bash
$>  sudo apt-get install libboost-all-dev libpugixml-dev libproj-dev libgtest-dev libpython-dev libosmium2-dev
```

Additional dependencies for the python bindings:
```bash
$>  sudo apt-get install castxml
$>  pip install --user pygccxml
$>  pip install --user https://bitbucket.org/ompl/pyplusplus/get/1.8.1.zip
```

Remaining dependencies:

 - spdlog

## Building all libraries
For compiling all libraries (and potentially also some dependencies), it is suggested to use [colcon](https://colcon.readthedocs.io/).
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

There are some CMake options affecting what or how the components are built.
These can be applied to all components by appending them to the call (together with the additional --cmake-args):
```bash
 map$> colcon build --cmake-args -DBUILD_TESTING=ON
```
When activating the Unit tests, they all can be executed with:
```bash
 map$> colcon test
```

The python bindings are disable by default. To integrate them into the build you can make use of the prepared
colcon meta file:
```bash
 map$> colcon build --metas colcon_python.meta
```

## Building a single library
The ad_map_access (same applies to the other libraries) library is built with a standard cmake toolchain. Simply run the following commands to build the library:
```bash
 ad_map_access$> mkdir build
 ad_map_access$> cd build
 build$>  cmake ..
 build$>  make
```

## CMake options
There are some build options available:

 - BUILD_TESTING: Enables unit tests compilation
 - BUILD_APIDOC: Enables API documentation building
 - BUILD_HARDENING: Enables hardening compiler and linker flags
 - BUILD_PYTHON_BINDING: Enables the build of the respective python bindings

By default, all options are set to off. Any of these could be activate by adding them to the initial cmake call above as "-D<OPTION>=[ON|OFF]",
e.g. "-DBUILD_TESTING=ON -DBUILD_APIDOC=ON".

#### Unit tests
When BUILD_TESTING is enabled, the "make" call will automatically compile the Unit tests.
They can be executed using CMake's ctest application.
```bash
 build$>  cmake -DBUILD_TESTING=ON ..
 build$>  make
 build$>  ctest
```
#### API documentation
When BUILD_APIDOC is enabled, the "make" call will automatically generate the API documentation.
```bash
 build$>  cmake -BUILD_APIDOC=ON ..
 build$>  make
```
The API documentation is written to the _apidoc_ folder within the _build_ directory.

#### Build hardening
Usually, build hardening is injected by the surrounding build system. Nevertheless, the CMakeLists.txt defines
hardening flags to ensure the code is compatible to respective flags. To enable hardening compiler and linker flags:
```bash
 build$>  cmake -DBUILD_HARDENING=ON ..
 build$>  make
```
