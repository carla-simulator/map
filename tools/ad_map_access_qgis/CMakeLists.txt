# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

project(ad_map_access_qgis)
include(GNUInstallDirs)

if (NOT BUILD_QGPIS_PLUGIN)
  return()
endif()

#
# qgis plugin is just installed into the plugin directory
#
set(QGIS_PLUGIN_PATH "${CMAKE_INSTALL_PREFIX}/share/qgis/python/plugins")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION ${QGIS_PLUGIN_PATH})

# and the ad_map_access_python library is required, so just try to put it in there, too
find_package(ad_map_access_python QUIET)
if ( ad_map_access_python_FOUND )
  set(AD_MAP_ACCESS_PYTHON_LIBRARY ${ad_map_access_python_LIBRARIES})
else()
  get_filename_component(AD_MAP_ACCESS_PYTHON_HINT_BASE ${CMAKE_INSTALL_PREFIX} DIRECTORY)
  find_library(AD_MAP_ACCESS_PYTHON_LIBRARY ad_map_access_python.so
    HINTS ${AD_MAP_ACCESS_PYTHON_HINT_BASE}/ad_map_access_python/lib/python2.7 )
endif()
if (AD_MAP_ACCESS_PYTHON_LIBRARY)
  get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  install(FILES ${AD_MAP_ACCESS_PYTHON_LIBRARY} DESTINATION ${QGIS_PLUGIN_PATH}/${CURRENT_DIR_NAME})
endif()

MESSAGE("To make use of the installed QGIS plugin ${CURRENT_DIR_NAME}, you have to set your environment variable:\n export QGIS_PLUGINPATH=${QGIS_PLUGIN_PATH}\n See also https://docs.qgis.org/2.18/en/docs/pyqgis_developer_cookbook/plugins.html#developing-plugins")
