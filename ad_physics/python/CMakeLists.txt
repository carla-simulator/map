# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2020-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------


project(ad_physics_python VERSION ${CARLA-MAP_VERSION})

include(GNUInstallDirs)

find_package(spdlog REQUIRED CONFIG)
get_target_property(SPDLOG_INCLUDES spdlog::spdlog INTERFACE_INCLUDE_DIRECTORIES)

list(APPEND INCLUDE_DIRS ${SPDLOG_INCLUDES})

string (REPLACE ";" "\", \"" GENPY_INCLUDE_DIRS "${INCLUDE_DIRS}")

find_python_binding_packages()

configure_file(generate_python_lib.py.in generate_python_lib.py)

generate_python_binding_source_code(${CMAKE_CURRENT_BINARY_DIR})

configure_file(__init__.py.in ${PYTHON_BINDING_NAME}/ad_physics/__init__.py)

set(target ad_physics_${PYTHON_BINDING_NAME})

add_library(${target} SHARED
  ${CMAKE_CURRENT_BINARY_DIR}/Ad-physics-PythonWrapper.cpp
)
target_compile_definitions(${target} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
target_compile_options(${target} PRIVATE ${TARGET_COMPILE_OPTIONS})
set_property(TARGET ${target} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})
set_target_properties(${target} PROPERTIES PREFIX "")
set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_BINDING_NAME}/ad_physics)

target_include_directories(${target}
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${PYTHON_BINDING_PACKAGE_INCLUDE_DIRS}
)
target_link_libraries(${target} PRIVATE
  ad_physics
  ${PYTHON_BINDING_PACKAGE_LIBRARIES}
)

configure_file(setup.py.in ${CMAKE_CURRENT_BINARY_DIR}/setup.py)

install(CODE "\
  EXECUTE_PROCESS(\
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/setup.py egg_info --egg-base ${CMAKE_CURRENT_BINARY_DIR} build --build-base ${CMAKE_CURRENT_BINARY_DIR} install --prefix ${CMAKE_INSTALL_PREFIX} --record ${CMAKE_CURRENT_BINARY_DIR}/install.log --single-version-externally-managed bdist_wheel --dist-dir ${CMAKE_INSTALL_PREFIX}/dist ${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_BINDING_NAME}\
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}\
  )"
)

#####################################################################
# Tests
#####################################################################
if (BUILD_TESTING)
  add_test(NAME ${PROJECT_NAME}_test_${PYTHON_BINDING_NAME}
    COMMAND ${PYTHON_EXECUTABLE} -m interface_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tests
  )
  get_python_test_environment()
  set_tests_properties(${PROJECT_NAME}_test_${PYTHON_BINDING_NAME} PROPERTIES ENVIRONMENT "${PYTHON_TEST_ENVIRONMENT}")
endif()
