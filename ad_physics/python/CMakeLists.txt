# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------


project(ad_physics_python)

include(GNUInstallDirs)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

find_package(spdlog REQUIRED CONFIG)
get_target_property(SPDLOG_INCLUDES spdlog::spdlog INTERFACE_INCLUDE_DIRECTORIES)

list(APPEND INCLUDE_DIRS ${SPDLOG_INCLUDES})

string (REPLACE ";" "\", \"" GENPY_INCLUDE_DIRS "${INCLUDE_DIRS}")

find_python_binding_packages()

configure_file(generate_python_lib.py.in generate_python_lib.py)

generate_python_binding_source_code(${CMAKE_CURRENT_BINARY_DIR})


foreach(binding ${PYTHON_BINDINGS})

  string(REPLACE "." "" binding_string ${binding})

  set(target ad_physics_${binding_string})

  configure_file(ad/__init__.py.in ${binding}/ad/__init__.py)
  configure_file(ad/physics/__init__.py.in ${binding}/ad/physics/__init__.py)

  add_library(${target}
     ${CMAKE_CURRENT_BINARY_DIR}/AdPhysicsPythonWrapper-${binding_string}.cpp
  )
  target_compile_definitions(${target} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
  target_compile_options(${target} PRIVATE ${TARGET_COMPILE_OPTIONS})
  set_property(TARGET ${target} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

  target_include_directories(${target} PRIVATE
    ${PYTHON_BINDING_PACKAGE_INCLUDE_DIRS_${binding}}
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  target_link_libraries(${target} PRIVATE
    ad_physics
    ${PYTHON_BINDING_PACKAGE_LIBRARIES_${binding}}
  )


  ################################################################################
  # Install section
  ################################################################################

  install(DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}/${binding}/ad
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}
    )
  install(TARGETS ${target}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}/ad/physics
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${binding}/ad/physics
    )


  #####################################################################
  # Tests
  #####################################################################
  if (BUILD_TESTING)
    add_test(NAME ${target}_test
      COMMAND ${binding} -m interface_test
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tests
    )
    get_python_test_environment(${binding})
    set_tests_properties(${target}_test PROPERTIES ENVIRONMENT "${PYTHON_TEST_ENVIRONMENT}")
  endif()

endforeach()
