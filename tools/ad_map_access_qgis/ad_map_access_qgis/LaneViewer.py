# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access as ad
from utility import *
import Globs
from qgis._core import QgsVectorLayerSimpleLabeling
from qgis.gui import QgsMapToolEmitPoint, QgsMapTool
from qgis.core import QgsField, QgsFeature, QgsProject, QgsPalLayerSettings, QgsTextFormat
from PyQt5.QtCore import QVariant
from .QGISLayer import WGS84PointLayer, WGS84SurfaceLayer
from .LayerManager import LayerManager


class LaneViewer(QgsMapTool):

    "..."
    START_SELECTION = 1
    DESTINATION_SELECTION = 2
    #
    WAYPOINT_TITLE = "Start/Destination"
    WAYPOINT_SYMBOL = "star"
    WAYPOINT_COLOR = "64, 255, 64"
    WAYPOINT_SIZE = "8"
    #
    TITLE = "Enable"
    COLOR = "255, 255, 255"

    def __init__(self, action):
        "..."
        QgsMapTool.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.action.setChecked(False)
        self.layer_group = ["INTERSECTION", "NORMAL", "OTHER", "UNKNOWN"]
        self.layer_waypoints = None
        self.layer_route = None

    def activate(self):
        "..."
        super(LaneViewer, self).activate()
        self.__calculate_Lane_IDs__()
        self.action.setChecked(True)
        Globs.log.info("Lane IDs enabled for all layers at once")

    def deactivate(self):
        "..."
        laneList = ad.map.lane.getLanes()
        for each_layer in self.layer_group:
            layer = QgsProject.instance().mapLayersByName(each_layer)[0]
            for each_lane in laneList:
                lane = ad.map.lane.getLane(each_lane)
            layer.setLabelsEnabled(False)
            layer.triggerRepaint(False)

        super(LaneViewer, self).deactivate()
        self.action.setChecked(False)
        Globs.log.info("Lane IDs disabled")

    def __calculate_Lane_IDs__(self):
        "..."

        laneList = ad.map.lane.getLanes()

        for each_layer in self.layer_group:
            layer = QgsProject.instance().mapLayersByName(each_layer)[0]
            for each_lane in laneList:
                lane = ad.map.lane.getLane(each_lane)

                text_format = QgsTextFormat()
                label = QgsPalLayerSettings()
                label.fieldName = 'Id'
                label.__setattr__('Id', lane.id)
                label.enabled = True
                label.setFormat(text_format)
                label.placement = QgsPalLayerSettings.OverPoint

                labeler = QgsVectorLayerSimpleLabeling(label)
                layer.setLabelsEnabled(True)
                layer.setLabeling(labeler)
                layer.triggerRepaint(True)
