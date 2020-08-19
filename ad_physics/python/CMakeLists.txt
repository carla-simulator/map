# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (c) 2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------


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
  string(TOLOWER ${binding} lc_binding)

  project(ad_physics_${lc_binding})

  add_library(${PROJECT_NAME}
     ${CMAKE_CURRENT_BINARY_DIR}/AdPhysicsPythonWrapper${binding}.cpp
  )
  target_compile_definitions(${PROJECT_NAME} PUBLIC ${TARGET_COMPILE_DEFINITIONS})
  target_compile_options(${PROJECT_NAME} PRIVATE ${TARGET_COMPILE_OPTIONS})
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${TARGET_LINK_FLAGS})

  target_include_directories(${PROJECT_NAME} PRIVATE
    ${PYTHON_BINDING_PACKAGE_INCLUDE_DIRS_${binding}}
    ${CMAKE_CURRENT_BINARY_DIR}
  )

  target_link_libraries(${PROJECT_NAME} PRIVATE
    ad_physics
    ${PYTHON_BINDING_PACKAGE_LIBRARIES_${binding}}
  )

  ################################################################################
  # Install section
  ################################################################################

  install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}_EXPORT
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

  set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

  install(EXPORT ${PROJECT_NAME}_EXPORT
    FILE ${PROJECT_NAME}Targets.cmake
    DESTINATION ${CMAKECONFIG_INSTALL_DIR}
    )

  configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR}
    )

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/install/${PROJECT_NAME}Config.cmake
    DESTINATION ${CMAKECONFIG_INSTALL_DIR}
    )

  #####################################################################
  # Tests
  #####################################################################
  if (BUILD_TESTING)
    add_test(NAME ${PROJECT_NAME}_test
      COMMAND ${lc_binding} -m interface_test
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/tests
    )
    get_python_test_environment()
    set_tests_properties(${PROJECT_NAME}_test PROPERTIES ENVIRONMENT "${PYTHON_TEST_ENVIRONMENT}")
  endif()

endforeach()
