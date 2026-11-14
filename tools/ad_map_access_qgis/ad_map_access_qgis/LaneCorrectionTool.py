# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2020-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from PyQt5.QtWidgets import QDialog
from PyQt5.Qt import QDialogButtonBox, QVBoxLayout, QStringListModel, QInputDialog, QWidget
from PyQt5.QtGui import QColor

import ad_map_access as ad
from utility import *
import Globs
from qgis._core import QgsVectorLayerSimpleLabeling, Qgis
from qgis.gui import QgsMapToolEmitPoint, QgsMapTool, QgsMessageBar
from qgis.core import QgsField, QgsFeature, QgsProject, QgsPalLayerSettings, QgsTextFormat, QgsPointXY, QgsGeometry, QgsMessageLog
from PyQt5.QtCore import QVariant
from .QGISLayer import WGS84PointLayer, WGS84SurfaceLayer, WGS84PolylineLayer
from .LayerManager import LayerManager


class LaneCorrectionTool(QgsMapToolEmitPoint):
    "..."

    def __init__(self, action):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.action.setChecked(False)

    def activate(self):
        "..."
        super(LaneCorrectionTool, self).activate()

        Globs.log.info("Lane Correction Tool Activated")

        items = [str(lane_id) for lane_id in ad.map.lane.getLanes()]
        if not items:
            Globs.log.warning("No lanes available for correction.")
            return

        from_lane_id, ok_from = QInputDialog.getItem(QWidget(), "Select lane_id of lane to correct LaneBorder",
                                                     "LaneBorderCorrection", items, 0, False)
        if not ok_from or not from_lane_id:
            return
        to_lane_id, ok_to = QInputDialog.getItem(QWidget(), "Select lane_id of lane to connect LaneBorder to by shortening/extending",
                                                 "LaneBorderCorrection", items, 0, False)
        if not ok_to or not to_lane_id:
            return
        from_id = ad.map.lane.LaneId(int(from_lane_id))
        to_id = ad.map.lane.LaneId(int(to_lane_id))
        ad.map.lane.correctLaneBorder(from_id, to_id)
        Globs.dirty_lanes.extend([from_id, to_id])
        Globs.main.map_refresh()

    def deactivate(self):
        "..."
        super(LaneCorrectionTool, self).deactivate()
        self.action.setChecked(False)
