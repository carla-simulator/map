# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

project(ad_map_access_qgis)

include(../../cmake/carla-map-version.cmake)
include(../../cmake/python-binding.cmake)
include(GNUInstallDirs)

if(BUILD_PYTHON_BINDING)
  #
  # qgis plugin is just installed into the plugin directory
  #
  set(QGIS_PLUGIN_PATH "${CMAKE_INSTALL_PREFIX}/share/qgis/python/plugins")
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME} DESTINATION ${QGIS_PLUGIN_PATH})
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/metadata.txt.in ${CMAKE_CURRENT_BINARY_DIR}/metadata.txt)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/metadata.txt DESTINATION ${QGIS_PLUGIN_PATH}/${PROJECT_NAME})

  MESSAGE("To make use of the installed QGIS plugin ${PROJECT_NAME}, you have to set your environment variable:\n export QGIS_PLUGINPATH=${QGIS_PLUGIN_PATH}\n See also https://docs.qgis.org/3.10/en/docs/pyqgis_developer_cookbook/plugins/index.html")
else()
  install(CODE "MESSAGE(STATUS \"No Python build configured. Skipping.\")")
endif()
