# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."


import ad_map_access_qgis_python as admap
import Globs
from qgis.gui import QgsMapToolEmitPoint
from qgis.core import QgsFeatureRequest, QgsRectangle, QgsMapLayerRegistry


class MapSnapper(QgsMapToolEmitPoint):

    "..."
    DEFAULT_ALTITUDE = 0
    DEFAULT_SEARCH_RADIUS = 0.025

    def __init__(self, action):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.action.setChecked(False)
        self.altitude = self.DEFAULT_ALTITUDE
        self.search_radius = self.DEFAULT_SEARCH_RADIUS

    def destroy(self):
        "..."

    def activate(self):
        "..."
        super(MapSnapper, self).activate()
        self.action.setChecked(True)
        Globs.log.info("Altitude Setter Activated")

    def deactivate(self):
        "..."
        super(MapSnapper, self).deactivate()
        self.action.setChecked(False)
        Globs.log.info("Altitude Setter Deactivated")

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."
        lane_id = self.__find_lane_id_at_point__(event.pos())
        if lane_id is not None:
            lla_left = admap.GetLaneEdgeLeft(lane_id)
            if lla_left is not None:
                alt_sum = 0
                for lla in lla_left:
                    alt_sum = alt_sum + lla[2]
                self.altitude = alt_sum / len(lla_left)
                Globs.log.info("Default altitude set to " + str(self.altitude))
            else:
                Globs.log.error("Cannot get edge for lane " + str(lane_id))
        else:
            Globs.log.error("Cannot find any lane at that point.")

    def snap(self, raw_pt):
        "..."
        geo_pt = (raw_pt.x(), raw_pt.y(), self.altitude)
        mmpts = admap.FindLanes(geo_pt, self.search_radius)
        if mmpts is None:
            Globs.log.error("Please select point closer to the road network!")
        return mmpts

    def __find_lane_id_at_point__(self, pos):
        "..."
        registry = QgsMapLayerRegistry.instance()
        layers = registry.mapLayers()
        for layer_name in layers:
            layer = layers[layer_name]
            point = self.toLayerCoordinates(layer, pos)
            request = QgsFeatureRequest()
            rect = QgsRectangle(point[0], point[1], point[0], point[1])
            request.setFilterRect(rect)
            try:
                layer_attrs = layer.attributeList()
                if layer_attrs is not None:
                    attr0_name = layer.attributeDisplayName(0)
                    if attr0_name == "Id":
                        feats = layer.getFeatures(request)
                        for feat in feats:
                            attrs = feat.attributes()
                            return attrs[0]
            except AttributeError:
                pass
        return None
