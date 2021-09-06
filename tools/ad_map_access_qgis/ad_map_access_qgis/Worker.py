# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import Globs
from PyQt5 import QtCore
from qgis.core import QgsMessageLog


class Worker(object):

    "..."

    def __init__(self, title, layer, runner):
        self.title = title
        self.layer = layer
        self.runner = runner
        #
        if isinstance(self.layer, list):
            for xlayer in self.layer:
                xlayer.show(False)
        else:
            self.layer.show(False)

    def do_work(self):
        "..."
        Globs.log.info(self.title + " started...")
        result = self.runner.work()
        if result is None:
            Globs.log.warning(self.title + "terminated.")
        else:
            Globs.log.info(self.title + " finished: " + str(result))
        if isinstance(self.layer, list):
            for layer in self.layer:
                layer.show(layer.visible)
                layer.refresh()
        else:
            self.layer.show(self.layer.visible)
            self.layer.refresh()
