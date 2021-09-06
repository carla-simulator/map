# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"Entry point for QGIS plug-ins."

import sys
import os.path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))
import qgis.utils
from qgis.gui import QgsMessageBar
from qgis.core import QgsMessageLog
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QAction, QFileDialog
from qgis.PyQt.QtGui import *
from qgis.PyQt.QtWidgets import *

import ad_map_access as ad
import Globs
import Logger
from .ADMapQgs import ADMapQgs
from .MapRoutingTest import MapRoutingTest
from .MapPredictionTest import MapPredictionTest
from .MapSnapper import MapSnapper
from .MapSnappingTest import MapSnappingTest
from .LaneViewer import LaneViewer
from .QGISUI import QGISUI
from utility import *


def classFactory(iface):  # pylint: disable=invalid-name
    "..."
    Globs.iface = iface
    Globs.log = Logger.LoggerQgs(iface)
    # If the console logger is needed then the below line can be uncommented to observe the log messages on the console.
    # Globs.log = Logger.LoggerConsole(iface)

    Globs.main = Main()
    return Globs.main


class Main(object):

    "..."

    NEW_MAP = "&New map"
    LOAD = "&Load..."
    UNLOAD = "&Unload"
    SET_ALT = "Set snap altitude"
    SNAP = "Snapping test"
    ROUTE = "Routing test"
    RROUTE = "Routing restart"
    PREDICT = "Prediction test"
    ENABLE_ALL_LANE_IDS = "ID"

    def __init__(self):
        "..."
        self.ui = QGISUI(Globs.iface, "&CARLA ad_map_access", True)  # pylint: disable=C0103
        self.actions_map_not_loaded = []
        self.actions_map_loaded = []
        self.action_tool = {}
        self.admap = None
        self.plugin_dir = os.path.dirname(__file__)
        self.file_name = "ADMap.txt"

    def initGui(self):  # pylint: disable=C0103
        "..."
        self.ui.add_separator()
        self.__add_action__(self.LOAD, self.__map_load__, False)
        self.__add_action__(self.UNLOAD, self.__map_unload__)
        self.__add_action__(self.SET_ALT, self.__set_alt__)
        self.__add_action__(self.SNAP, self.__map_snapping__)
        self.__add_action__(self.ROUTE, self.__map_routing__)
        self.__add_action__(self.RROUTE, self.__map_rrouting__)
        self.__add_action__(self.PREDICT, self.__map_predition__)
        self.ui.add_separator()
        self.__add_action__(self.ENABLE_ALL_LANE_IDS, self.__enable_all__)
        self.ui.add_separator()
        self.update_ui()
        Globs.log.info("CARLA ad_map_access Plug-in loaded.")

    def unload(self):
        "..."
        self.__map_unload__()
        self.ui.destroy()
        Globs.log.info("CARLA ad_map_access Plug-in removed.")

    def __open_map__(self, file_name):
        "..."
        init_map_succeeded = False
        if file_name.endswith('.xodr'):
            open_drive_file = open(file_name, 'r')
            open_drive_content = open_drive_file.read()
            open_drive_file.close()
            init_map_succeeded = ad.map.access.initFromOpenDriveContent(
                open_drive_content, 0.2, ad.map.intersection.IntersectionType.Unknown, ad.map.landmark.TrafficLightType.UNKNOWN)
            if init_map_succeeded and not ad.map.access.isENUReferencePointSet():
                ad.map.access.setENUReferencePoint(ad.map.point.createGeoPoint(ad.map.point.Longitude(
                    8.4421163), ad.map.point.Latitude(49.0192671), ad.map.point.Altitude(0.)))
                Globs.log.warning("OpenDrive file '{}' doesn't provide GEO reference point. Setting a default at {}".format(
                    file_name, ad.map.access.getENUReferencePoint()))
        else:
            init_map_succeeded = ad.map.access.init(file_name)

        if init_map_succeeded:
            self.admap = ADMapQgs()
            self.admap.layers.create_all()
            self.admap.data_added()
            self.__create_map_tools__()
            self.update_ui()
            return True
        else:
            Globs.log.error("Failed to init ad_map_access with map file '{}'".format(file_name))

        return False

    def __select_file_name__(self):
        "..."
        title = "Select CARLA ad_map_access file..."
        default_dir = "/"
        self.file_name = QFileDialog.getOpenFileName(None, title, default_dir)

    def __map_load__(self):
        "..."
        self.__select_file_name__()
        if self.file_name:
            Globs.log.info("Loading data from " + self.file_name[0] + " ...")
            if self.__open_map__(self.file_name[0]):
                Globs.log.info("Map loaded from from " + self.file_name[0] + ".")
            else:
                Globs.log.error("Can't load map from  " + self.file_name[0] + ".")

    def __map_unload__(self):
        "..."
        ad.map.access.cleanup()
        self.__destroy_map_tools__()
        if self.admap is not None:
            self.admap.layers.remove_all()
        self.admap = None
        self.update_ui()
        Globs.log.info("Map cleared.")

    def __map_routing__(self):
        "..."
        self.__toggle_tool__(self.ROUTE)

    def __map_rrouting__(self):
        "..."
        tool = self.__toggle_tool__(self.ROUTE, True)
        tool.restart()

    def __map_predition__(self):
        "..."
        self.__toggle_tool__(self.PREDICT)

    def __map_snapping__(self):
        "..."
        self.__toggle_tool__(self.SNAP)

    def __enable_all__(self):
        "..."
        self.__toggle_tool__(self.ENABLE_ALL_LANE_IDS)

    def __set_alt__(self):
        "..."
        self.__toggle_tool__(self.SET_ALT)

    def __toggle_tool__(self, action_name, force=False):
        "..."
        tool = self.action_tool[action_name][1]
        if force:
            Globs.iface.mapCanvas().setMapTool(tool)
        else:
            if Globs.iface.mapCanvas().mapTool() == tool:
                Globs.iface.mapCanvas().unsetMapTool(tool)
            else:
                Globs.iface.mapCanvas().setMapTool(tool)
        self.update_ui()
        return tool

    def map_refresh(self):
        "..."
        self.admap.update_lanes(Globs.dirty_lanes)
        Globs.dirty_lanes = []
        self.admap.remove_lanes(Globs.removed_lanes)
        Globs.removed_lanes = []
        self.admap.remove_partitions(Globs.removed_partitions)
        Globs.removed_partitions = []
        self.update_ui()

    def lane_topo_refresh(self, lane_id):
        "..."
        self.admap.readd_lane_topo(lane_id)

    def update_ui(self):
        "..."
        map_loaded = self.admap is not None
        for action in self.actions_map_not_loaded:
            action.setEnabled(not map_loaded)
            action.setChecked(False)
        for action in self.actions_map_loaded:
            action.setEnabled(map_loaded)
            action.setChecked(False)
        active_map_tool = Globs.iface.mapCanvas().mapTool()
        for action_name in self.action_tool:
            action = self.action_tool[action_name][0]
            if self.action_tool[action_name][1] == active_map_tool:
                action.setChecked(True)
            else:
                action.setChecked(False)
        self.action_tool[self.RROUTE][0].setChecked(False)

    def __add_action__(self, text, callback, when_map_loaded=True):
        "..."
        action = self.ui.add_action(text, callback)
        if when_map_loaded:
            self.actions_map_loaded.append(action)
        else:
            self.actions_map_not_loaded.append(action)
        self.action_tool[text] = (action, None)

    def __create_map_tool__(self, name, xtool, param2=None):
        "..."
        tool = self.action_tool[name][1]
        if tool is None:
            action = self.action_tool[name][0]
            if param2 is None:
                tool = xtool(action)
            else:
                tool = xtool(action, param2)
            self.action_tool[name] = (action, tool)
        return tool

    def __create_map_tools__(self):
        "..."
        snapper = self.__create_map_tool__(self.SET_ALT, MapSnapper)
        routing_test = self.__create_map_tool__(self.ROUTE, MapRoutingTest, snapper)
        prediction_test = self.__create_map_tool__(self.PREDICT, MapPredictionTest, snapper)
        snapping_test = self.__create_map_tool__(self.SNAP, MapSnappingTest, snapper)
        view_test = self.__create_map_tool__(self.ENABLE_ALL_LANE_IDS, LaneViewer)

        routing_test.layer_group = self.admap.layers.layer_group_misc()
        prediction_test.layer_group = self.admap.layers.layer_group_misc()
        snapping_test.layer_group = self.admap.layers.layer_group_misc()

    def __destroy_map_tools__(self):
        "..."
        for action_name in self.action_tool:
            action = self.action_tool[action_name][0]
            if not action.isChecked():
                tool = self.action_tool[action_name][1]
                Globs.iface.mapCanvas().unsetMapTool(tool)
            action.setChecked(False)
            self.action_tool[action_name] = (action, None)
