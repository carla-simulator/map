# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

"..."
from PyQt5.QtWidgets import QDialog
from PyQt5.Qt import QDialogButtonBox, QVBoxLayout, QStringListModel, QInputDialog,\
    QWidget


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

class MapRoutingTest(QgsMapToolEmitPoint):

    "..."
    START_SELECTION = 1
    DESTINATION_SELECTION = 2
    #
    WAYPOINT_TITLE = "Start/Destination"
    WAYPOINT_SYMBOL = "star"
    WAYPOINT_COLOR = "64, 255, 64"
    WAYPOINT_SIZE = "8"
    #
    ROUTE_TITLE = "Route"
    ROUTE_COLOR = "0, 255, 0"

    def __init__(self, action, snapper):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.snapper = snapper
        self.action.setChecked(False)
        self.layer_group = None
        self.layer_waypoints = None
        self.layer_route = None
        self.state = self.START_SELECTION
        self.pt_start = None
        self.pt_dest = None
        self.mode = None
        self.route_edges = []

    def destroy(self):
        "..."
        self.layer_waypoints = None
        self.layer_route = None

    def restart(self):
        "..."
        self.state = self.START_SELECTION
        if self.layer_waypoints is not None:
            self.layer_waypoints.remove_all_features()
            self.layer_waypoints.refresh()
        if self.layer_route is not None:
            self.layer_route.remove_all_features()
            self.layer_route.refresh()

    def activate(self):
        "..."
        super(MapRoutingTest, self).activate()
        self.__create_layers__()
        self.action.setChecked(True)
        Globs.log.info("Map Routing Test Activated")

        items = []
        items.append("Same Driving Direction")
        items.append("All Routable Lanes")
        items.append("All Neighbor Lanes")
        items.append("Undefined")

        tf = False
        self.mode, tf = QInputDialog.getItem(QWidget(), "Select Route Creation Mode for Routing Test   ",
                                             "Options for creating Route:                           ", items, 0, False)

    def deactivate(self):
        "..."
        super(MapRoutingTest, self).deactivate()
        self.action.setChecked(False)
        Globs.log.info("Map Routing Test Deactivated")

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."
        raw_pt = self.toLayerCoordinates(self.layer_waypoints.layer, event.pos())
        mmpts = self.snapper.snap(raw_pt)

        if mmpts is not None:
            if self.state == self.START_SELECTION:
                self.__set_start__(mmpts[0])
            elif self.state == self.DESTINATION_SELECTION:
                self.__set_destination__(mmpts[0])
                self.__calculate_route__()
            else:
                Globs.log.error("Invalid Map Matching Test State?!")
        else:
            Globs.log.error("Please select point closer to the road network!")
        self.layer_waypoints.refresh()
        self.layer_route.refresh()

    def __set_start__(self, mmpt):
        "..."
        self.layer_waypoints.remove_all_features()
        self.layer_route.remove_all_features()
        self.pt_start = mmpt.matchedPoint
        attrs = ["Start", str(mmpt.lanePoint)]
        self.layer_waypoints.add_ecef(self.pt_start, attrs)
        self.state = self.DESTINATION_SELECTION

    def __set_destination__(self, mmpt):
        "..."
        self.pt_dest = mmpt.matchedPoint
        attrs = ["Destination", str(mmpt.lanePoint)]
        self.layer_waypoints.add_ecef(self.pt_dest, attrs)
        self.state = self.START_SELECTION

    def __calculate_route__(self):
        "..."
        route = Route(self.pt_start, self.pt_dest, self.mode)
        edgeList = ad.map.route.getGeoBorderOfRoute(route)

        if route is not None:
            self.route_edges = []
            for edge in edgeList:
                self.__add_edge__(edge)
        else:
            Globs.log.error("Cannot calculate route.")

    def __add_edge__(self, new_edge):
        "..."
        self.layer_route.add_lla2(new_edge.left, new_edge.right, [])
        self.route_edges.append(new_edge)

    def __create_layers__(self):
        "..."
        if self.layer_route is None:
            self.layer_route = WGS84SurfaceLayer(Globs.iface,
                                                 self.ROUTE_TITLE,
                                                 self.ROUTE_COLOR,
                                                 [],
                                                 self.layer_group)
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
