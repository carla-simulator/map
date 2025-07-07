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
from qgis.gui import QgsMapToolEmitPoint
from qgis.core import QgsFeatureRequest, QgsRectangle, QgsProject


class MapSnapper(QgsMapToolEmitPoint):

    "..."
    DEFAULT_ALTITUDE = 0
    DEFAULT_SEARCH_RADIUS = 2.

    def __init__(self, action):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.action.setChecked(False)
        self.altitude = self.DEFAULT_ALTITUDE
        self.altitude_setter_active = False
        self.search_radius = self.DEFAULT_SEARCH_RADIUS

    def destroy(self):
        "..."

    def activate(self):
        "..."
        super(MapSnapper, self).activate()

    def deactivate(self):
        "..."
        super(MapSnapper, self).deactivate()

    def toggle(self):
        if self.altitude_setter_active:
            self.altitude_setter_active = False
            Globs.log.info("Altitude Setter Deactivated")
        else:
            self.altitude_setter_active = True
            Globs.log.info("Altitude Setter Activated")
        self.action.setChecked(self.altitude_setter_active)

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."
        if self.altitude_setter_active:
            lane_ids_int = self.__find_lane_ids_at_point__(event.pos())
            if len(lane_ids_int) > 0:
                lla_left = GetLaneEdgeLeft(ad.map.lane.LaneId(lane_ids_int[0]))
                if lla_left is not None:
                    alt_sum = 0
                    for lla in lla_left:
                        alt_sum = alt_sum + lla.altitude.mAltitude
                    self.altitude = alt_sum / len(lla_left)
                    Globs.log.info("Default altitude set to " + str(self.altitude))
                else:
                    Globs.log.error("Cannot get edge for lane " + str(lane_id_int))
            else:
                Globs.log.error("Cannot find any lane at that point.")

    def getGeoPointFromRaw(self, raw_pt):
        if self.altitude_setter_active:
            pt_geo = ad.map.point.createGeoPoint(raw_pt.x(), raw_pt.y(), self.altitude)
        else:
            pt_geo = ad.map.point.createGeoPoint(raw_pt.x(), raw_pt.y(), ad.map.point.AltitudeUnknown)
        return pt_geo

    def snap(self, raw_pt):
        "..."
        pt_geo = self.getGeoPointFromRaw(raw_pt)
        d = ad.physics.Distance(self.search_radius)
        mmpts = ad.map.match.AdMapMatching.findLanes(pt_geo, d)
        if len(mmpts) == 0:
            Globs.log.error("Please select point closer to the road network!")
            return None
        return mmpts

    def __find_lane_ids_at_point__(self, pos):
        "..."
        lane_ids = []
        registry = QgsProject.instance()
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
                    attr2_name = layer.attributeDisplayName(2)
                    if attr0_name == "Id" and attr2_name == "HOV":
                        feats = layer.getFeatures(request)
                        for feat in feats:
                            attrs = feat.attributes()
                            lane_ids.append(attrs[0])
            except AttributeError:
                pass
        return lane_ids
