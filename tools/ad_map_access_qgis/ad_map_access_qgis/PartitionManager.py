# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import Globs


class PartitionManager(object):

    "..."

    def __init__(self):
        "..."
        self.part_map = {}
        self.part_landmark_map = {}
        self.added_lane_ids = []
        self.added_landmark_ids = []
        self.removed_lane_ids = []
        self.removed_landmark_ids = []
        self.added_partitions = []
        self.removed_partitions = []

    def reset(self):
        "..."
        self.added_lane_ids = []
        self.added_landmark_ids = []
        self.removed_lane_ids = []
        self.removed_landmark_ids = []
        self.added_partitions = []
        self.removed_partitions = []

    def clear(self):
        "..."
        self.part_map = {}
        self.part_landmark_map = {}
        self.reset()

    def add_lane(self, part, lane_id):
        "..."
        if part in self.part_map:
            self.part_map[part].append(lane_id)
        else:
            self.part_map[part] = [lane_id]

    def remove_lane(self, lane_id):
        "..."
        for part in self.part_map:
            if lane_id in self.part_map[part]:
                self.part_map[part].remove(lane_id)
                return
        Globs.log.error("Lane " + str(lane_id) + " not found in partitions!?")

    def debug_print(self):
        "..."
        for part in self.part_map:
            lanes = self.part_map[part]
            print ("Partition " + str(part) + ": Lanes " + str(len(lanes)))
        print ("Added lane ids: " + str(len(self.added_lane_ids)))
        print ("Removed lane ids: " + str(len(self.removed_lane_ids)))
        print ("Added partitions: " + str(self.added_partitions))
        print ("Removed partitions: " + str(self.removed_partitions))
