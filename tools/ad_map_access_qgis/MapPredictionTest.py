# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access_python as admap
import Globs
from qgis.gui import QgsMapToolEmitPoint
from qgis.core import QgsField
from PyQt4.QtCore import QVariant
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

    def deactivate(self):
        "..."
        super(MapPredictionTest, self).deactivate()
        self.action.setChecked(False)
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
        self.pt_start = mmpt[5]
        attrs = ["Start", mmpt[0], mmpt[1], mmpt[2], mmpt[3], mmpt[4]]
        self.layer_waypoints.add_lla(self.pt_start, attrs)

    def __calculate_predictions__(self):
        "..."
        routes = admap.Predictions(self.pt_start)
        if routes is not None:
            self.routes_edges = []
            self.__resize_route_layers__(len(routes))
            for route in routes:
                self.routes_edges.append([])
                for lanes in route:
                    for edge in lanes:
                        self.__add_edge__(edge)
        else:
            Globs.log.error("Cannot predict route.")

    def __add_edge__(self, new_edge):
        "..."
        current_prediction_index = len(self.routes_edges) - 1
        lane_id_1 = new_edge[0]
        lane_t_1 = new_edge[1]
        for edge in self.routes_edges[current_prediction_index]:
            lane_id_0 = edge[0]
            lane_t_0 = edge[1]
            if lane_id_0 == lane_id_1:
                t_start = min(lane_t_0, lane_t_1)
                t_end = max(lane_t_0, lane_t_1)
                lla_left = admap.GetLaneSubEdgeLeft(lane_id_0, t_start, t_end)
                lla_right = admap.GetLaneSubEdgeRight(lane_id_0, t_start, t_end)
                self.layer_routes[current_prediction_index].add_lla2(lla_left, lla_right, [])
                self.routes_edges[current_prediction_index].remove(edge)
                return
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
                     QgsField("Lane Id", QVariant.LongLong),
                     QgsField("Pos Type", QVariant.String),
                     QgsField("Long-T-Left", QVariant.Double),
                     QgsField("Long-T-Right", QVariant.Double),
                     QgsField("Lateral-T", QVariant.Double)]
            self.layer_waypoints = WGS84PointLayer(Globs.iface,
                                                   self.WAYPOINT_TITLE,
                                                   self.WAYPOINT_SYMBOL,
                                                   self.WAYPOINT_COLOR,
                                                   self.WAYPOINT_SIZE,
                                                   attrs,
                                                   self.layer_group)
