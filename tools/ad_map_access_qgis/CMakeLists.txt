# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

cmake_minimum_required(VERSION 3.5)

project(ad_map_access_qgis)
include(GNUInstallDirs)

if(BUILD_PYTHON_BINDING)
  #
  # qgis plugin is just installed into the plugin directory
  #
  set(QGIS_PLUGIN_PATH "${CMAKE_INSTALL_PREFIX}/share/qgis/python/plugins")
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION ${QGIS_PLUGIN_PATH})

  MESSAGE("To make use of the installed QGIS plugin ${CURRENT_DIR_NAME}, you have to set your environment variable:\n export QGIS_PLUGINPATH=${QGIS_PLUGIN_PATH}\n See also https://docs.qgis.org/3.10/en/docs/pyqgis_developer_cookbook/plugins/index.html")
endif()
