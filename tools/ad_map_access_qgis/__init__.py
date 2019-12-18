# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"Entry point for QGIS plug-ins."

import os.path
from qgis.gui import QgsMessageBar
from qgis.core import QgsMessageLog
from PyQt4.QtGui import QAction, QFileDialog, QIcon

import ad_map_access_python as admap
import Globs
import Logger
from .ADMapQgs import ADMapQgs
from .MapRoutingTest import MapRoutingTest
from .MapPredictionTest import MapPredictionTest
from .MapSnapper import MapSnapper
from .MapSnappingTest import MapSnappingTest
from .QGISUI import QGISUI


def classFactory(iface):  # pylint: disable=invalid-name
    "..."
    Globs.iface = iface
    # @todo: the LoggerQgs is currently not thread safe. It has to be ensured, that the updates of the log messages are
    #  published within the QT GUI thread. Otherwhise it will crash depending on the timing!
    #  for the time beeing we take therefore the console logger
    # Globs.log = Logger.LoggerQgs(iface)
    Globs.log = Logger.LoggerConsole(iface)
    Globs.main = Main()
    return Globs.main


class Main(object):

    "..."

    NEW_MAP = "&New map"
    LOAD = "&Load..."
    LOAD_ADD = "&Add..."
    UNLOAD = "&Unload"
    SET_ALT = "Set snap altitude"
    SNAP = "Snapping test"
    ROUTE = "Routing test"
    RROUTE = "Routing restart"
    PREDICT = "Prediction test"

    def __init__(self):
        "..."
        self.ui = QGISUI(Globs.iface, "&Intel AD Map", True)  # pylint: disable=C0103
        self.actions_map_not_loaded = []
        self.actions_map_loaded = []
        self.action_tool = {}
        self.admap = None
        self.plugin_dir = os.path.dirname(__file__)
        self.file_name = "ADMap.admap"

    def initGui(self):  # pylint: disable=C0103
        "..."
        self.__add_action__(self.NEW_MAP, self.__map_new__, False)
        self.ui.add_separator()
        self.__add_action__(self.LOAD, self.__map_load__, False)
        self.__add_action__(self.LOAD_ADD, self.__map_load_add__)
        self.__add_action__(self.UNLOAD, self.__map_unload__)
        self.ui.add_separator()
        self.__add_action__(self.SET_ALT, self.__set_alt__)
        self.__add_action__(self.SNAP, self.__map_snapping__)
        self.__add_action__(self.ROUTE, self.__map_routing__)
        self.__add_action__(self.RROUTE, self.__map_rrouting__)
        self.__add_action__(self.PREDICT, self.__map_predition__)
        self.ui.add_separator()
        self.update_ui()
        Globs.log.info("Intel AD Map Plug-in loaded.")

    def unload(self):
        "..."
        self.__map_unload__()
        self.ui.destroy()
        Globs.log.info("Intel AD Map Plug-in removed.")

    def __open_first_map__(self, file_name):
        "..."
        if admap.Open(file_name):
            self.admap = ADMapQgs()
            self.admap.layers.create_all()
            self.admap.data_added()
            self.__create_map_tools__()
            self.update_ui()
            return True
        return False

    def __open_next_map__(self, file_name):
        "..."
        if admap.Open(file_name):
            Globs.map_dirty = True
            self.admap.data_added()
            self.update_ui()
            return True
        return False

    def __map_new__(self):
        "..."
        if self.admap is None:
            if self.__open_first_map__(""):
                Globs.log.info("Empty map created.")
            else:
                Globs.log.error("Can't create empty map?!")
        else:
            Globs.log.error("Map data already loaded.")

    def __select_file_name__(self):
        "..."
        title = "Select Intel ADM file..."
        default_dir = "/"
        self.file_name = QFileDialog.getOpenFileName(None, title, default_dir)

    def __map_load__(self):
        "..."
        self.__select_file_name__()
        if self.file_name:
            Globs.log.info("Loading data from " + self.file_name + " ...")
            if self.__open_first_map__(self.file_name):
                Globs.log.info("Map loaded from from " + self.file_name + ".")
            else:
                Globs.log.error("Can't load map from  " + self.file_name + ".")

    def __map_load_add__(self):
        "..."
        self.__select_file_name__()
        if self.file_name:
            Globs.log.info("Loading data from " + self.file_name + " ...")
            if self.__open_next_map__(self.file_name):
                Globs.log.info("Added map dataloaded from from " + self.file_name + ".")
            else:
                Globs.log.error("Can't add map from  " + self.file_name + ".")

    def __map_unload__(self):
        "..."
        admap.Close()
        self.__destroy_map_tools__()
        if self.admap is not None:
            self.admap.layers.remove_all()
            self.admap.partition_manager.clear()
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
