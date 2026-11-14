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

    def __init__(self, action):
        "..."
        QgsMapTool.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.action.setChecked(False)
        self.layer_group = ["INTERSECTION", "NORMAL", "SHOULDER", "PEDESTRIAN", "BIKE", "OTHER"]
        self.activated = False

    def activate(self):
        "..."
        super(LaneViewer, self).activate()

    def deactivate(self):
        "..."
        super(LaneViewer, self).deactivate()

    def toggle(self):
        if self.activated:
            for each_layer in self.layer_group:
                layers = QgsProject.instance().mapLayersByName(each_layer)
                if not layers:
                    continue
                layer = layers[0]
                layer.setLabelsEnabled(False)
                layer.triggerRepaint(False)
            self.activated = False
            Globs.log.info("Lane IDs disabled")
        else:
            self.__calculate_Lane_IDs__()
            Globs.iface.mapCanvas().refresh()
            self.activated = True
            Globs.log.info("Lane IDs enabled")
        self.action.setChecked(self.activated)

    def __calculate_Lane_IDs__(self):
        "..."
        text_format = QgsTextFormat()
        label = QgsPalLayerSettings()
        label.fieldName = 'Id'
        label.enabled = True
        label.setFormat(text_format)
        label.placement = QgsPalLayerSettings.OverPoint

        for each_layer in self.layer_group:
            layers = QgsProject.instance().mapLayersByName(each_layer)
            if not layers:
                continue
            layer = layers[0]
            labeler = QgsVectorLayerSimpleLabeling(label)
            layer.setLabeling(labeler)
            layer.setLabelsEnabled(True)
            layer.triggerRepaint(True)
