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

from .ADMapQgsLayers import ADMapQgsLayers
from .Worker import Worker
from .LaneRunnerGeneric import LaneRunnerGeneric
from .LaneRunnerSpeed import LaneRunnerSpeed
from .LaneRunnerSurface import LaneRunnerSurface
from .LandmarkRunnerGeneric import LandmarkRunnerGeneric
from .PartitionManager import PartitionManager

#
# ADMapQgs Class
# pylint: disable=C0103, R0902


class ADMapQgs(object):

    "..."

    def __init__(self):
        "..."
        self.workers = []
        self.layers = ADMapQgsLayers()

    def data_added(self):
        "..."

        self.workers = []
        self.__add_lane_dir_worker__()
        self.__add_lane_orientation_worker__()
        for contact_type in self.layers.LANE_CONTACT_TYPE:
            self.__add_lane_contact_type_worker__(contact_type)
        for topo in self.layers.LANE_TOPO:
            self.__add_lane_topo_worker__(topo)
        self.__add_lane_speed_worker__()
        self.__add_lane_surface_workers__(False)
        self.__add_lane_edge_worker__()
        for landmark_type in self.layers.LANDMARK_TYPE:
            self.__add_landmark_worker__(landmark_type)
        for worker in self.workers:
            worker.do_work()

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

    def __draw_new_lane__(self, new_lane_id):
        "..."
        if new_lane_id is not None:
            self.update_lanes([new_lane_id])
            self.readd_lane_topo(new_lane_id)
            self.partition_manager.add_lane(0, new_lane_id)
            to_refresh = self.layers.update_lane_layers(new_lane_id)
            self.layers.refresh_layers(to_refresh)
            Globs.map_dirty = True
            Globs.main.update_ui()

    def create_new_lane(self):
        "..."
        lane_adder = LaneAdder(self.layers.layer_new_lane)
        new_lane_id = lane_adder.add_new_lane()
        self.__draw_new_lane__(new_lane_id)

    def make_intersection_lane(self, straight):
        "..."
        inter_lane_maker = IntersectionLaneMaker(self.layers)
        new_lane_id = inter_lane_maker.make_intersection_lane(straight)
        if new_lane_id is not None:
            self.__draw_new_lane__(new_lane_id)
        else:
            Globs.log.error("Failed to create intersection lane.")

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

    def remove_lanes(self, lane_ids, from_partition_manager_too=True):
        "..."
        to_refresh = []
        for lane_id in lane_ids:
            if from_partition_manager_too:
                self.partition_manager.remove_lane(lane_id)
            for layer_manager_name in self.layers.layer_managers:
                layer_manager = self.layers.layer_managers[layer_manager_name]
                if layer_manager.is_on_layer(lane_id):
                    layer_manager.remove_old_feature(lane_id)
                    to_refresh.append(layer_manager)
            to_refresh += self.layers.update_lane_topo_layers(lane_id, True)
        for layer_manager in list(set(to_refresh)):
            layer_manager.refresh()

    def remove_partitions(self, partitions):
        "..."
        for partition in partitions:
            Globs.map_dirty = True
        self.partition_manager.update()
        removed_lane_ids = self.partition_manager.removed_lane_ids
        self.remove_lanes(removed_lane_ids, False)

    def readd_lane_topo(self, lane_id):
        "..."
        to_refresh = self.layers.update_lane_topo_layers(lane_id)
        self.layers.refresh_layers(to_refresh)
