# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"Handling of QGIS Menus and Toolbars"

import os.path
from PyQt5.QtWidgets import QAction
from PyQt5.QtGui import QIcon
import qgis.PyQt.QtCore


class QGISUI(object):

    "..."

    def __init__(self, iface, title, toolbar_too=False):
        "..."
        self.iface = iface
        self.menu = title
        self.actions = {}
        self.separators = []
        self.toolbar = None
        if toolbar_too:
            self.toolbar = self.iface.addToolBar(title)
            self.toolbar.setObjectName(title)

    def destroy(self):
        "..."
        for i in self.actions:
            self.iface.removePluginDatabaseMenu(self.menu, self.actions[i])
        for i in self.separators:
            self.iface.removePluginDatabaseMenu(self.menu, i)
        if self.toolbar is not None:
            del self.toolbar
            self.toolbar = None

    def add_action(self, text, callback):
        "..."
        parent = self.iface.mainWindow()
        icon = self.__icon__(text)
        action = QAction(icon, text, parent)
        action.triggered.connect(callback)
        action.setCheckable(True)
        action.setChecked(False)
        self.iface.addPluginToDatabaseMenu(self.menu, action)
        if self.toolbar is not None:
            self.toolbar.addAction(action)
        self.actions[text] = action
        return action

    def add_separator(self):
        "..."
        parent = self.iface.mainWindow()
        action = QAction(QIcon(), "separator", parent)
        action.setSeparator(True)
        self.iface.addPluginToDatabaseMenu(self.menu, action)
        self.separators.append(action)
        if self.toolbar is not None:
            self.toolbar.addAction(action)
        return action

    def __icon__(self, text):
        "..."
        name = os.path.dirname(__file__) + "/icons/"
        for char in text:
            if char.isalpha():
                name = name + char
        name = name + ".png"
        if os.path.exists(name):
            icon = QIcon(name)
            if icon is not None:
                return icon
        return QIcon()
