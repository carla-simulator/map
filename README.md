# Map support for Automated Driving

[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub tag (latest SemVer)](https://img.shields.io/github/tag/carla-simulator/map.svg)](https://github.com/carla-simulator/map/releases/latest)
[![Build Status](https://github.com/carla-simulator/map/workflows/Build%20and%20Test%20of%20AD-Map%20Library/badge.svg?branch=master)](https://github.com/carla-simulator/map/actions?query=workflow%3A%22Build+and+Test+of+AD-Map+Library%22)

#### Table of contents
1. [Introduction](#introduction)
2. [License](#license)
3. [Releases](#releases)
3. [Getting Started](#started)
   1. [Supported Systems](#systems)
4. [Building the libraries](#building)
6. [Contributing](#contributing)

## Introduction <a name="introduction"></a>
This repository provides a set of libraries and tools to support the handling of maps for Automated Driving. This includes the following:

- C++ library for automated driving physics data types (ad_physics)
- C++ library for reading OpenDRIVE XML data (ad_map_opendrive_reader)
- C++ library for accessing automated driving maps (ad_map_access)
- MapMaker tools for basic offline conversion from [OpenStreetMap](https://www.openstreetmap.org/) data into the internal ad_map_access
binary format.
- A a plugin for the free [QGIS](https://qgis.org/) tool to visualize and inspect the ad map data

## License <a name="license"></a>
This software library is provided under the MIT open-source license: https://opensource.org/licenses/MIT.

In addition, the terms in the following apply:
[RELEASE NOTES AND DISCLAIMERS](./RELEASE_NOTES_AND_DISCLAIMERS.md).

## Documentation
Visit the project's [Documentation page](https://ad-map-access.readthedocs.io/en/latest/) to access the online version of the full documentation of this library.

## Releases <a name="releases"></a>
General release notes and changes can be found in the [Changelog](https://ad-map-access.readthedocs.io/en/latest/CHANGELOG/index.html)

#### Release 2.0.0 <a name="release_2_0"></a>
Improved route and especially connected route handling.

#### Release 1.1.0 <a name="release_1_1"></a>
Added python bindings.

#### Release 1.0.0 <a name="release_1"></a>
The initial release of the map C++ software libraries.

## Getting started <a name="started"></a>

#### Installation of dependencies
Currently, the focused operating system is Ubuntu 22.04. Nevertheless, the library should work in a similar way for any other Linux OS.
To install the dependencies for Ubuntu 22.04 execute the following command:
```bash
 user$> sudo apt-get install git build-essential cmake
```

If you want to use doxygen for API documentation, please also install:
```bash
 user$> sudo apt-get install doxygen graphviz
```

#### Get the library
To download the library, you may run:
```bash
 user$> git clone https://github.com/carla-simulator/map.git
 user$> cd map
```

#### Supported systems <a name="systems"></a>
Development systems are Ubuntu 22.04 and 24.04 
Following compiler and Python combinations are [tested continously](.github/workflows/build_test.yml):

|                 | Ubuntu 22.04 | Ubuntu 24.04 |
|:---------------:|:------------:|:------------:|
|   GCC 11        |       x      |              |
|   GCC 13        |              |       x      |
|  Clang 14       |       x      |              |
|  Clang 18       |              |       x      |
|  Python 3.10    |       x      |              |
|  Python 3.11    |       x      |       x      |
|  Python 3.12    |              |       x      |

Important: cmake is required to be at least version 3.10!

## Building the library <a name="building"></a>
See the detailed [Build instructions](https://ad-map-access.readthedocs.io/en/latest/BUILDING/index.html).

## Contributing <a name="contributing"></a>
Contibutions are very welcome!

Before submitting a pull request, please ensure that your code compiles successfully and that the tests run successfully.
Please also check that your code formatting complies to the provided clang style. To do so, you can run:
```bash
map$> sudo apt-get install clang-format-14
map$> find -iname *.cpp -o -iname *.hpp | xargs clang-format-14 -style=file -i
```
This command will automatically update the code formatting to be compliant with our style.

In addition, please perform a static code analysis, if possible.
```bash
map$> sudo apt-get install clang-tidy
map$> cmake -DBUILD_STATIC_ANALYSIS=ON
map$> make clang-tidy
```
This may provide a list of possible improvements that you would like to consider in your pull request.
