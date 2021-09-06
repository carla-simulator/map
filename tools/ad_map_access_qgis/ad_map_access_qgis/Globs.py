# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

# pylint: disable=C0103
map_dirty = False
dirty_lanes = []
dirty_landmarks = []
removed_lanes = []
removed_landmarks = []
removed_partitions = []
log = None
iface = None
main = None


def geo_str(pts):
    "..."
    s = None
    for pt in pts:
        if s is None:
            s = "["
        else:
            s += ", "
        s += "(%.6f, %.6f)" % pt
    s += "]"
    return s
