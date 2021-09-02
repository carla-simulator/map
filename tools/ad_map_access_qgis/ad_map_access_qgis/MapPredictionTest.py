# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
from PyQt5.QtWidgets import QDialog
from PyQt5.Qt import QDialogButtonBox, QVBoxLayout, QStringListModel, QInputDialog,\
    QWidget, QComboBox, QSize

from PyQt5 import QtGui, uic, QtWidgets, QtCore
from PyQt5.QtGui import QIcon

import ad_map_access as ad
from utility import *
import Globs
from qgis.gui import QgsMapToolEmitPoint
from qgis.core import QgsField
from PyQt5.QtCore import QVariant
from .QGISLayer import WGS84PointLayer, WGS84SurfaceLayer

# too many instance attrs
# pylint: disable=R0902


class MapPredictionTest(QgsMapToolEmitPoint):

    "..."
    WAYPOINT_TITLE = "Start"
    WAYPOINT_SYMBOL = "star"
    WAYPOINT_COLOR = "64, 255, 64"
    WAYPOINT_SIZE = "8"
    #
    ROUTE_TITLE = "Prediction"

    def __init__(self, action, snapper):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.snapper = snapper
        self.action.setChecked(False)
        self.layer_group = None
        self.layer_waypoints = None
        self.layer_routes = []
        self.pt_start = None
        self.pt_dest = None
        self.mode = None
        self.length = None
        self.duration = None
        self.routes_edges = []

    def destroy(self):
        "..."
        self.layer_waypoints = None
        self.layer_routes = []

    def activate(self):
        "..."
        super(MapPredictionTest, self).activate()
        self.__create_layers__()
        self.action.setChecked(True)
        Globs.log.info("Map Prediction Test Activated")

        items = []
        items.append("Same Driving Direction")
        items.append("All Routable Lanes")
        items.append("All Neighbor Lanes")
        items.append("Undefined")

        widget = QWidget()
        tf = False
        self.mode, tf = QInputDialog.getItem(widget, "Select Route Creation Mode for Prediction Test               ",
                                             "Options for creating Route:                     ", items, 0, False)
        self.length, tf = QInputDialog.getDouble(
            widget, "Enter length for Prediction Test                         ", "Length:                                         ", 150.0, False)
        self.duration, tf = QInputDialog.getDouble(
            widget, "Enter duration for Prediction Test                     ", "Duration:                                       ", 10.0, False)

    def deactivate(self):
        "..."
        super(MapPredictionTest, self).deactivate()
        self.action.setChecked(False)
        self.layer_waypoints = None
        self.routes_edges = None
        self.layer_routes = None
        Globs.log.info("Map Prediction Test Deactivated")

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."
        raw_pt = self.toLayerCoordinates(self.layer_waypoints.layer, event.pos())
        mmpts = self.snapper.snap(raw_pt)
        if mmpts is not None:
            self.__set_start__(mmpts[0])
            self.__calculate_predictions__()
        else:
            Globs.log.error("Please select point closer to the road network!")
        self.layer_waypoints.refresh()
        for layer_route in self.layer_routes:
            layer_route.refresh()

    def __set_start__(self, mmpt):
        "..."
        self.layer_waypoints.remove_all_features()
        for layer_route in self.layer_routes:
            layer_route.remove_all_features()
        self.pt_start = mmpt.matchedPoint
        attrs = ["Start", str(mmpt.lanePoint)]
        self.layer_waypoints.add_ecef(self.pt_start, attrs)

    def __calculate_predictions__(self):
        "..."
        routes = Predictions(self.pt_start, self.mode, self.length, self.duration)
        for each in routes:
            edgeList = ad.map.route.getGeoBorderOfRoute(each)
        if routes is not None:
            self.routes_edges = []
            self.__resize_route_layers__(len(routes))
            for route in routes:
                self.routes_edges.append([])
                for edge in edgeList:
                    self.__add_edge__(edge)
        else:
            Globs.log.error("Cannot predict route.")

    def __add_edge__(self, new_edge):
        "..."
        for edge in self.routes_edges:
            current_prediction_index = len(self.routes_edges) - 1
            self.layer_routes[current_prediction_index].add_lla2(new_edge.left, new_edge.right, [])
            self.routes_edges[current_prediction_index].append(new_edge)

    def __resize_route_layers__(self, required_size):
        while len(self.layer_routes) < required_size:
            color = "0, 255, " + str(((len(self.layer_routes) * 60) % 256))
            self.layer_routes.append(WGS84SurfaceLayer(Globs.iface,
                                                       self.ROUTE_TITLE + str(len(self.layer_routes) + 1),
                                                       color,
                                                       [],
                                                       self.layer_group))
        while len(self.layer_routes) > required_size:
            layer = self.layer_routes.pop()
            layer.remove()
            del layer

    def __create_layers__(self):
        "..."
        if self.layer_waypoints is None:
            attrs = [QgsField("Waypoint", QVariant.String),
                     QgsField("LanePoint", QVariant.String)]
            self.layer_waypoints = WGS84PointLayer(Globs.iface,
                                                   self.WAYPOINT_TITLE,
                                                   self.WAYPOINT_SYMBOL,
                                                   self.WAYPOINT_COLOR,
                                                   self.WAYPOINT_SIZE,
                                                   attrs,
                                                   self.layer_group)
