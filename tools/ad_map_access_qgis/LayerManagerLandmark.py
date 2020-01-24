# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import ad_map_access_qgis_python as admap
from .LayerManager import LayerManager


class LayerManagerLandmark(LayerManager):

    "..."

    def __init__(self, layer, landmark_type):
        "..."
        LayerManager.__init__(self, layer)
        self.layer = layer
        self.landmark_type = landmark_type
        if landmark_type == "LANDMARK":
            self.landmark_types = ["UNKNOWN", "POLE", "OTHER", "GUIDE_POST",
                                   "POSTBOX", "MANHOLE", "POWERCABINET", "FIRE_HYDRANT", "BOLLARD"]
        else:
            self.landmark_types = [landmark_type]

    def add(self, landmark):
        "..."
        landmark_id = landmark['Id']
        pt0 = admap.GetLandmarkPosition(landmark_id)
        landmark_attrs = admap.GetLandmark(landmark_id)
        typ = landmark_attrs['Type']
        if typ == "TRAFFIC_SIGN":
            typ = landmark_attrs['TrafficSignType']
        if pt0 is None or landmark_attrs is None:
            return
        if typ not in self.landmark_types:
            return

        heading = admap.GetLandmarkOrientationAngle(landmark_id)
        orientation = round(heading, 5)
        attrs = [landmark_id, typ, orientation]
        feature_1 = self.layer.add_lla(pt0, attrs)
        LayerManager.add_new_feature(self, landmark_id, feature_1)
