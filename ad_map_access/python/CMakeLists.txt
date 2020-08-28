# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

project(ad_map_access_python)

include(GNUInstallDirs)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

find_package(ad_map_opendrive_reader REQUIRED CONFIG)
get_target_property(OPENDRIVE_READER_INCLUDES ad_map_opendrive_reader INTERFACE_INCLUDE_DIRECTORIES)

find_package(ad_physics REQUIRED CONFIG)
get_target_property(AD_PHYSICS_INCLUDES ad_physics INTERFACE_INCLUDE_DIRECTORIES)

find_package(spdlog REQUIRED CONFIG)
get_target_property(SPDLOG_INCLUDES spdlog::spdlog INTERFACE_INCLUDE_DIRECTORIES)

list(APPEND INCLUDE_DIRS ${OPENDRIVE_READER_INCLUDES} ${AD_PHYSICS_INCLUDES} ${SPDLOG_INCLUDES})

string (REPLACE ";" "\", \"" GENPY_INCLUDE_DIRS "${INCLUDE_DIRS}")

find_python_binding_packages()

configure_file(generate_python_lib.py.in generate_python_lib.py)

generate_python_binding_source_code(${CMAKE_CURRENT_BINARY_DIR})

foreach(binding ${PYTHON_BINDINGS})

  string(REPLACE "." "" binding_string ${binding})

  configure_file(ad/__init__.py.in ${binding}/ad/__init__.py)
  configure_file(ad/map/__init__.py.in ${binding}/ad/map/__init__.py)

  set(target ad_map_access_${binding_string})

  configure_file(AdMapAccessPython.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/AdMapAccessPython-${binding_string}.cpp)

  add_library(${target} SHARED
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-access-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-config-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-intersection-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-landmark-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-lane-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-match-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-point-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-restriction-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMap-route-PythonWrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/AdMapAccessPython-${binding_string}.cpp
    )
  target_compile_definitions(${target} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
  target_compile_options(${target} PRIVATE ${TARGET_COMPILE_OPTIONS})
  set_property(TARGET ${target} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

  target_include_directories(${target} PRIVATE
    ${PYTHON_BINDING_PACKAGE_INCLUDE_DIRS_${binding}}
    ${CMAKE_CURRENT_BINARY_DIR}
    )

  target_link_libraries(${target} PRIVATE
    ad_map_access
    ad_map_opendrive_reader
    ad_physics
    spdlog::spdlog
    ${PYTHON_BINDING_PACKAGE_LIBRARIES_${binding}}
    )

  ################################################################################
  # Install section
  ################################################################################
  install(TARGETS ${target}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}/ad/map
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}/ad/map
    )

  install(DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}/${binding}/ad
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}/
    )

  #####################################################################
  # Tests
  #####################################################################
  if (BUILD_TESTING)
    add_test(NAME ${PROJECT_NAME}_test_${binding}
      COMMAND ${binding} -m interface_test
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tests
    )
    get_python_test_environment(${binding} ad_physics ad_map_opendrive_reader)
    set_tests_properties(${PROJECT_NAME}_test_${binding} PROPERTIES ENVIRONMENT "${PYTHON_TEST_ENVIRONMENT}")
  endif()

endforeach()
