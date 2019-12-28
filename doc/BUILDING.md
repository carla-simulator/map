# General build instructions

## Building a single library

### Build instructions
The ad_map_access (same applies to the other libraries) library is built with a standard cmake toolchain. Simply run the following commands to build the library:
```bash
 ad_map_access$> mkdir build
 ad_map_access$> cd build
 build$>  cmake ..
 build$>  make
```
#### CMake options
There are some build options available:
 - BUILD_TESTING: Enables unit tests compilation
 - BUILD_APIDOC: Enables API documentation building
 - BUILD_HARDENING: Enables hardening compiler and linker flags

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
 build$>  cmake -DBUILD_HARDENING=1 ..
 build$>  make
```

## Building all libraries
For compiling all libraries (and potentially also some dependencies), it is suggested to use [colcon](https://colcon.readthedocs.io/).
Please use the link above for installation instructions.

Colcon requires a workspace folder, just create / select one, further referenced as _ad_map_ws_.

### Add libraries to workspace
Add at least this repository to the workspace.
```bash
 ad_map_ws$> mkdir src
 ad_map_ws$> cd src
 src$> git clone git clone https://github.com/carla-simulation/map.git
 ...
```
Optionally add some dependencies, e.g. spdlog:
```bash
 src$> git clone git clone https://github.com/gabime/spdlog.git
 ...
```

### Compilation
After going back to the colcon workspace directory, a build can be started with
```bash
 ad_map_ws$> colcon build
```
All components will be compiled respecting the dependencies between them.
The same CMake described above can be applied to all components by appending them to the call (together with the additional --cmake-args):
```bash
 ad_map_ws$> colcon build --cmake-args -DBUILD_TESTING=ON
```
When activating the Unit tests, they all can be executed with:
```bash
 ad_map_ws$> colcon test
```
