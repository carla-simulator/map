# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"Logging for Python"

from abc import ABCMeta, abstractmethod
from qgis.core import QgsMessageLog, Qgis
from qgis.gui import QgsMessageBar
from PyQt5.QtCore import QThread, QObject


class Logger(object):

    "Logging for Python"
    __metalcass__ = ABCMeta

    def __init__(self, level=4):
        "level: 0: errors,\n" \
            "       1: errors, warnings,\n" \
            "       2: errors, warnings, infos,\n" \
            "       3: errors, warnings, infos, debug.\n"
        self.level = level

    @abstractmethod
    def log(self, level, msg):
        "Logs the msg.\n" \
            "level: 'ERROR', 'WARN.', 'INFO.', 'DEBUG'\n" \
            "msg:   msg to be written."
        pass

    def error(self, msg):
        "Logs an Error.\n" \
            "msg: message.\n" \
            "Returns False."
        if self.level >= 0:
            self.log("ERROR", msg)
        return False

    def warning(self, msg):
        "Logs an Warning.\n" \
            "msg: message.\n" \
            "Returns False."
        if self.level >= 1:
            self.log("WARN.", msg)
        return False

    def info(self, msg):
        "Logs an Info.\n" \
            "msg: message.\n" \
            "Returns False."
        if self.level >= 2:
            self.log("INFO.", msg)
        return False

    def debug(self, msg):
        "Logs an Debug message.\n" \
            "msg: message.\n" \
            "Returns False."
        if self.level >= 3:
            self.log("DEBUG", msg)
        return False


class LoggerConsole(Logger):

    "Logs to the console."

    def __init__(self, iface, reporting_level=4):
        "iface: QGIS interface object.\n" \
            "level: 0: errors,\n" \
            "       1: errors, warnings,\n" \
            "       2: errors, warnings, infos,\n" \
            "       3: errors, warnings, infos, debug.\n" \
            "       4: errors, warning,s infos and debug infos.\n"
        Logger.__init__(self, reporting_level)

    def log(self, level, msg):
        "Logger implementation."
        print ("[" + str(QThread.currentThreadId()) + "]" + level + ": " + msg)


class LoggerQgs(Logger):

    "Logs to the QGIS GUI."

    def __init__(self, iface, reporting_level=4):
        "iface: QGIS interface object.\n" \
            "level: 0: errors,\n" \
            "       1: errors, warnings,\n" \
            "       2: errors, warnings, infos,\n" \
            "       3: errors, warnings, infos, debug.\n" \
            "       4: errors, warning,s infos and debug infos.\n"
        Logger.__init__(self, reporting_level)
        self.message_bar = iface.messageBar()
        self.title = "CARLA ad_map_access"

    def log(self, level, msg):
        "Logger implementation."
        if level == "ERROR":
            self.message_bar.clearWidgets()
            self.message_bar.pushMessage(level, msg, Qgis.Critical, 5)
            QgsMessageLog.logMessage(msg, self.title, level=Qgis.Critical)
        elif level == "WARN.":
            self.message_bar.clearWidgets()
            self.message_bar.pushMessage(level, msg, Qgis.Warning, 5)
            QgsMessageLog.logMessage(msg, self.title, level=Qgis.Warning)
        elif level == "INFO.":
            self.message_bar.clearWidgets()
            self.message_bar.pushMessage(level, msg, Qgis.Info, 5)
            QgsMessageLog.logMessage(msg, self.title, level=Qgis.Info)
        elif level == "DEBUG":
            self.message_bar.clearWidgets()
            self.message_bar.pushMessage(level, msg, Qgis.Success, 5)
            QgsMessageLog.logMessage(msg, self.title, level=Qgis.Info)
        else:
            self.message_bar.clearWidgets()
            self.message_bar.pushMessage(level, msg, Qgis.Success, 5)
            QgsMessageLog.logMessage(msg, self.title, level=Qgis.Info)
