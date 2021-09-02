# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."
import ad_map_access as ad
import Globs
from qgis.gui import QgsMapToolEmitPoint
from qgis.core import QgsField
from PyQt5.QtCore import QVariant
import qgis.PyQt.QtCore
from .QGISLayer import WGS84PointLayer


class MapSnappingTest(QgsMapToolEmitPoint):

    "..."
    TITLE = "Map-Snapped"
    SYMBOL = "diamond"
    COLOR = "226, 226, 0"
    SIZE = "5"

    def __init__(self, action, snapper):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.snapper = snapper
        self.action.setChecked(False)
        self.layer_group = None
        self.layer = None

    def destroy(self):
        "..."
        self.layer = None

    def activate(self):
        "..."
        super(MapSnappingTest, self).activate()
        self.__create_layer__()
        self.action.setChecked(True)
        Globs.log.info("Map Snapping Test Activated")

    def deactivate(self):
        "..."
        super(MapSnappingTest, self).deactivate()
        self.action.setChecked(False)
        self.layer.remove_all_features()
        self.layer.refresh()
        Globs.log.info("Map Snapping Test Deactivated")

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."
        self.layer.remove_all_features()
        raw_pt = self.toLayerCoordinates(self.layer.layer, event.pos())
        pt_geo = ad.map.point.createGeoPoint(raw_pt.x(), raw_pt.y(), 0)
        enu_pt = ad.map.point.toENU(pt_geo)
        mmpts = self.snapper.snap(raw_pt)
        Globs.log.info("{} -> {}".format(pt_geo, enu_pt))
        if mmpts is not None:
            for mmpt in mmpts:
                self.layer.add_ecef(mmpt.matchedPoint, [
                                    int(mmpt.lanePoint.paraPoint.laneId), str(mmpt.type), float(mmpt.lanePoint.lateralT), float(mmpt.lanePoint.laneWidth), float(mmpt.lanePoint.laneLength), str(enu_pt)])
        self.layer.refresh()

    def __create_layer__(self):
        "..."
        if self.layer is None:
            attrs = [QgsField("Lane Id", QVariant.LongLong),
                     QgsField("Pos Type", QVariant.String),
                     QgsField("Lateral-T", QVariant.Double),
                     QgsField("Lane-Width", QVariant.Double),
                     QgsField("Lane-Length", QVariant.Double),
                     QgsField("ENU Point", QVariant.String)]
            self.layer = WGS84PointLayer(Globs.iface,
                                         self.TITLE,
                                         self.SYMBOL,
                                         self.COLOR,
                                         self.SIZE,
                                         attrs,
                                         self.layer_group)
