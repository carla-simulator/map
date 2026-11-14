# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import Globs
import ad_map_access as ad
from PyQt5 import QtCore

from .ADMapQgsLayers import ADMapQgsLayers
from .Worker import Worker
from .LaneRunnerGeneric import LaneRunnerGeneric
from .LaneRunnerSpeed import LaneRunnerSpeed
from .LaneRunnerSurface import LaneRunnerSurface
from .LandmarkRunnerGeneric import LandmarkRunnerGeneric

#
# ADMapQgs Class
# pylint: disable=C0103, R0902


class ADMapQgs(QtCore.QObject):

    "..."

    worker_finished = QtCore.pyqtSlot()

    def __init__(self):
        "..."
        super().__init__()
        self.workers = []
        self.worker_threads = []
        self.layers = ADMapQgsLayers()

    def data_added(self):
        "..."
        Globs.log.info("Start adding data to layers.")
        self.workers = []
        self.worker_threads = []

        all_layers = list(self.layers.layer.values())
        for qgs_layer in all_layers:
            if qgs_layer is not None:
                qgs_layer.show(False)
                qgs_layer.begin_batch()

        try:
            dir_mgr = self.layers.layer_managers[self.layers.LANE_DIRECTION]
            orient_mgr = self.layers.layer_managers[self.layers.LANE_ORIENTATION]
            tl_mgr = self.layers.layer_managers[self.layers.CONTACT_TRAFFIC_LIGHT]
            edge_mgr = self.layers.layer_managers[self.layers.LANE_EDGE]
            contact_mgrs = [self.layers.layer_managers["Contact " + ct] for ct in self.layers.LANE_CONTACT_TYPE]
            topo_mgrs = [self.layers.layer_managers["Lane " + topo] for topo in self.layers.LANE_TOPO]

            for lane_id in ad.map.lane.getLanes():
                lane = ad.map.lane.getLane(lane_id)
                if lane is None:
                    Globs.log.error("Failed to GetLane(" + str(lane_id) + ")")
                    continue
                dir_mgr.add(lane)
                orient_mgr.add(lane)
                tl_mgr.add(lane)
                edge_mgr.add(lane)
                surface_title = self.layers.lane_surface_layer_name(str(lane.type), False)
                self.layers.layer_managers[surface_title].add(lane)
                for speed_limit in lane.speed_limits:
                    self.layers.speed_layer_manager(speed_limit.speed_limit).add_speed_limit(lane, speed_limit)
                for contact_mgr in contact_mgrs:
                    contact_mgr.add(lane)
                for topo_mgr in topo_mgrs:
                    topo_mgr.add(lane)

            for landmark_id in ad.map.landmark.getLandmarks():
                landmark = ad.map.landmark.getLandmark(landmark_id)
                if landmark is None:
                    Globs.log.error("Failed to GetLandmark(" + str(landmark_id) + ")")
                    continue
                typ_str = str(landmark.type)
                target_type = str(landmark.traffic_sign_type) if typ_str == "TRAFFIC_SIGN" else typ_str
                if target_type not in self.layers.LANDMARK_TYPE:
                    target_type = "LANDMARK"
                self.layers.layer_managers[target_type].add(landmark)
        finally:
            for qgs_layer in all_layers:
                if qgs_layer is not None:
                    qgs_layer.end_batch()
                    qgs_layer.show(qgs_layer.visible)
                    qgs_layer.refresh()

        Globs.log.info("All layer data added")

    def __add_landmark_worker__(self, landmark_type):
        "..."
        title = landmark_type
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LandmarkRunnerGeneric(layer_manager, ad.map.landmark.getLandmarks())
        self.workers.append(Worker(title, layer, runner))

    def __add_lane_edge_worker__(self):
        "..."
        title = self.layers.LANE_EDGE
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __add_lane_surface_workers__(self, hov):
        "..."
        lane_collection = {}

        for lane_id in ad.map.lane.getLanes():
            lane = ad.map.lane.getLane(lane_id)
            typ = str(lane.type)

            # check lane type and put it in corresponding collection
            if typ not in self.layers.lane_types():
                if "OTHER" in lane_collection:
                    lane_collection["OTHER"].append(lane_id)
                else:
                    lane_collection["OTHER"] = [lane_id]
            else:
                if typ in lane_collection:
                    lane_collection[typ].append(lane_id)
                else:
                    lane_collection[typ] = [lane_id]

        # go over collections and add workers
        for typ, lane_ids in lane_collection.items():
            title = self.layers.lane_surface_layer_name(typ, hov)
            layer = self.layers.layer[title]
            layer_manager = self.layers.layer_managers[title]
            runner = LaneRunnerSurface(layer_manager, lane_ids)
            self.workers.append(Worker(title, layer, runner))

    def __add_lane_speed_worker__(self):
        "..."
        layers = self.layers.lane_speed_layers()
        runner = LaneRunnerSpeed(self, ad.map.lane.getLanes())
        self.workers.append(Worker("Speed Limit", layers, runner))

    def __add_lane_contact_type_worker__(self, contact_type):
        "..."
        title = "Contact " + contact_type
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __add_lane_topo_worker__(self, position):
        "..."
        title = "Lane " + position
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __add_lane_dir_worker__(self):
        "..."
        title = self.layers.LANE_DIRECTION
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __add_lane_orientation_worker__(self):
        "..."
        title = self.layers.LANE_ORIENTATION
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __add_contact_to_trafficLight_worker__(self):
        "..."
        title = self.layers.CONTACT_TRAFFIC_LIGHT
        layer = self.layers.layer[title]
        layer_manager = self.layers.layer_managers[title]
        runner = LaneRunnerGeneric(layer_manager, ad.map.lane.getLanes())
        self.workers.append(Worker(title, layer, runner))

    def __draw_new_lane__(self, new_lane_id):
        "..."
        if new_lane_id is not None:
            self.update_lanes([new_lane_id])
            self.readd_lane_topo(new_lane_id)
            to_refresh = self.layers.update_lane_layers(new_lane_id)
            self.layers.refresh_layers(to_refresh)
            Globs.map_dirty = True
            Globs.main.update_ui()

    def create_new_lane(self):
        "..."
        Globs.log.error("Creating new lanes is not supported.")

    def make_intersection_lane(self, straight):
        "..."
        Globs.log.error("Creating intersection lanes is not supported.")

    def update_lanes(self, lane_ids):
        "..."
        to_refresh = []
        for lane_id in lane_ids:
            to_refresh += self.layers.update_lane_layers(lane_id)
        self.layers.refresh_layers(to_refresh)

    def update_landmarks(self, landmark_ids):
        "..."
        to_refresh = []
        for landmark_id in landmark_ids:
            to_refresh += self.layers.update_landmark_layers(landmark_id)
        self.layers.refresh_layers(to_refresh)

    def remove_lanes(self, lane_ids):
        "..."
        to_refresh = []
        for lane_id in lane_ids:
            for layer_manager_name in self.layers.layer_managers:
                layer_manager = self.layers.layer_managers[layer_manager_name]
                if layer_manager.is_on_layer(lane_id):
                    layer_manager.remove_old_feature(lane_id)
                    to_refresh.append(layer_manager)
            to_refresh += self.layers.update_lane_topo_layers(lane_id, True)
        for layer_manager in list(set(to_refresh)):
            layer_manager.refresh()

    def readd_lane_topo(self, lane_id):
        "..."
        to_refresh = self.layers.update_lane_topo_layers(lane_id)
        self.layers.refresh_layers(to_refresh)
