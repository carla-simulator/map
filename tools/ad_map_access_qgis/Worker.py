# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

import Globs
from PyQt4 import QtCore
from qgis.core import QgsMessageLog


class Worker(object):

    "..."

    def __init__(self, title, layer, runner, next_worker):
        self.title = title
        self.layer = layer
        self.runner = runner
        self.next_worker = next_worker
        self.thread = QtCore.QThread(Globs.iface.mainWindow())
        self.runner.moveToThread(self.thread)
        #
        runner.progress.connect(self.progress)
        runner.finished.connect(self.finished)
        #
        runner.debug.connect(self.debug)
        runner.info.connect(self.info)
        runner.warning.connect(self.warning)
        runner.error.connect(self.error)
        runner.exxception.connect(self.exxception)
        #
        self.thread.started.connect(self.runner.run)
        #
        if isinstance(self.layer, list):
            for xlayer in self.layer:
                xlayer.show(False)
        else:
            self.layer.show(False)

    def start(self):
        "..."
        self.info(self.title + " started...")
        self.thread.start()

    def finished(self, result):
        "..."
        self.runner.deleteLater()
        self.thread.quit()
        self.thread.wait()
        self.thread.deleteLater()
        if result is None:
            self.warning(self.title + "terminated.")
        else:
            self.info(self.title + " finished: " + str(result))
        if isinstance(self.layer, list):
            for layer in self.layer:
                layer.show(layer.visible)
                layer.refresh()
        else:
            self.layer.show(self.layer.visible)
            self.layer.refresh()
        if self.next_worker is not None:
            self.next_worker.start()

    def progress(self, percent):
        "..."

    def debug(self, msg):
        "..."
        Globs.log.debug(msg)

    def info(self, msg):
        "..."
        Globs.log.info(msg)

    def warning(self, msg):
        "..."
        Globs.log.warning(msg)

    def error(self, msg):
        "..."
        Globs.log.error(msg)

    def exxception(self, msg):
        "..."
        self.error("Thread " + self.title + "raised exception! See message log for more info!")
        QgsMessageLog.logMessage("Thread " + self.title + " exception: " + msg)
