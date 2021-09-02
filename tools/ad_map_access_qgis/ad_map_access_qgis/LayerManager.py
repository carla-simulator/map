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
from qgis.core import QgsFeatureRequest


class LayerManager(object):

    "..."

    def __init__(self, layer):
        "..."
        self.layer = layer
        self.lane_id_to_feature_map_1 = {}
        self.lane_id_to_feature_map_2 = {}
        self.feature_id_to_lane_id_map_1 = {}
        self.feature_id_to_lane_id_map_2 = {}
        layer.layer.committedAttributeValuesChanges.connect(self.__changed_attribute_values__)
        layer.layer.committedFeaturesRemoved.connect(self.features_removed)

    def remove_old_feature(self, lane_id, from_layer=True):
        "..."
        if lane_id in self.lane_id_to_feature_map_1:
            feature = self.lane_id_to_feature_map_1[lane_id]
            feature_id = feature.id()
            del self.lane_id_to_feature_map_1[lane_id]
            del self.feature_id_to_lane_id_map_1[feature_id]
            if from_layer:
                self.layer.remove_feature(feature)
        if lane_id in self.lane_id_to_feature_map_2:
            feature = self.lane_id_to_feature_map_2[lane_id]
            feature_id = feature.id()
            del self.lane_id_to_feature_map_2[lane_id]
            del self.feature_id_to_lane_id_map_2[feature_id]
            if from_layer:
                self.layer.remove_feature(feature)

    def add_new_feature(self, lane_id, feature_1, feature_2=None):
        "..."
        if feature_1 is not None:
            self.lane_id_to_feature_map_1[lane_id] = feature_1
            self.feature_id_to_lane_id_map_1[feature_1.id()] = lane_id
        if feature_2 is not None:
            self.lane_id_to_feature_map_2[lane_id] = feature_2
            self.feature_id_to_lane_id_map_2[feature_2.id()] = lane_id

    def add(self, lane):
        "..."
        raise NotImplementedError

    def is_on_layer(self, lane_id):
        "..."
        if lane_id in self.lane_id_to_feature_map_1:
            return True
        if lane_id in self.lane_id_to_feature_map_2:
            return True
        return False

    def refresh(self):
        "..."
        self.layer.refresh()

    def change_attribute_value(self, lane_id, index, val):
        "..."
        Globs.log.error("Unsupported change of column " + str(index) +
                        " for lane " + str(lane_id) +
                        " to " + str(val))
        return False

    def attribute_change_failed(self, lane_id, name, val):
        "..."
        Globs.log.error("Cannot change attribute " + name +
                        "to " + str(val) +
                        " for lane " + str(lane_id))
        return False

    def __changed_attribute_values__(self, _, changed_attribute_values):
        "..."
        lane_changes = 0
        attribute_changes_success = 0
        attribute_changes_fail = 0
        for feature_id in changed_attribute_values:
            request = QgsFeatureRequest()
            request.setFilterFid(feature_id)
            for feature in self.layer.layer.getFeatures(request):
                attributes = feature.attributes()
                lane_id = attributes[0]
                dirty = False
                attribute_map = changed_attribute_values[feature_id]
                for index in attribute_map:
                    val = attribute_map[index]
                    if self.change_attribute_value(lane_id, index, val):
                        dirty = True
                        attribute_changes_success = attribute_changes_success + 1
                    else:
                        attribute_changes_fail = attribute_changes_fail
                if dirty:
                    lane_changes = lane_changes + 1
                    Globs.dirty_lanes.append(lane_id)
        Globs.map_dirty = attribute_changes_success > 0
        Globs.log.info("Changed " + str(lane_changes) + " lanes; " +
                       str(attribute_changes_success) + " attributes ok, " +
                       str(attribute_changes_fail) + " failed")
        Globs.main.map_refresh()

    def features_removed(self, _, deleted_feature_ids):
        "..."
        Globs.log.warning("Feature removal not supported")
        Globs.main.map_refresh()
