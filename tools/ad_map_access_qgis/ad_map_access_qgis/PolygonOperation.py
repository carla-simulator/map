# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2020-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from PyQt5.QtWidgets import QDialog
from PyQt5.Qt import QDialogButtonBox, QVBoxLayout, QStringListModel, QInputDialog, QWidget
from PyQt5.QtGui import QColor

import ad_map_access as ad
from utility import *
import Globs
from qgis._core import QgsVectorLayerSimpleLabeling, Qgis
from qgis.gui import QgsMapToolEmitPoint, QgsMapTool, QgsMessageBar
from qgis.core import QgsField, QgsFeature, QgsProject, QgsPalLayerSettings, QgsTextFormat, QgsPointXY, QgsGeometry, QgsMessageLog
from PyQt5.QtCore import QVariant
from .QGISLayer import WGS84PointLayer, WGS84SurfaceLayer, WGS84PolylineLayer
from .LayerManager import LayerManager


class PolygonOperation(QgsMapTool):
    "..."
    WAYPOINT_TITLE = "Waypoint"
    WAYPOINT_SYMBOL = "star"
    WAYPOINT_COLOR = "64, 255, 64"
    WAYPOINT_SIZE = "8"
    #
    FULLY_VISIBLE_TITLE = "Visible Region"
    FULLY_VISIBLE_COLOR = "0, 204, 204, 70"
    #
    FULLY_INVISIBLE_TITLE = "Invisible Region"
    FULLY_INVISIBLE_COLOR = "153, 50, 204, 90"
    #
    PARTLY_INVISIBLE_TITLE = "Partly Invisible Region"
    PARTLY_INVISIBLE_COLOR = "153, 150, 150, 90"
    #
    #
    INPUT_POLYGON_TITLE = "Input Polygon"
    INPUT_POLYGON_COLOR = "255, 153, 51, 50"
    INPUT_POLYGON_WIDTH = "0.8"
    #
    INPUT_POINTS_TITLE = "Input Polygon Points"
    INPUT_POINTS_SYMBOL = "diamond"
    INPUT_POINTS_COLOR = "255, 153, 51"
    INPUT_POINTS_SIZE = "10"
    #
    REFERENCE_TITLE = "Reference Point"
    REFERENCE_SYMBOL = "star"
    REFERENCE_COLOR = "0, 0, 0"
    REFERENCE_SIZE = "15"

    def __init__(self, action, snapper):
        "..."
        QgsMapToolEmitPoint.__init__(self, Globs.iface.mapCanvas())
        self.action = action
        self.snapper = snapper
        self.action.setChecked(False)
        self.layer_group = None
        self.layer_reference = None
        self.layer_fully_visible = None
        self.layer_input_polygon_points = None
        self.layer_drawing_polygon = None
        self.layer_fully_invisible = None
        self.layer_partly_invisible = None
        self.freespacePolygon = None
        self.secondFreespacePolygon = None
        self.current_mmpt = None
        self.intersection_points = None
        self.reference_point = None
        self.influence_distance = None
        self.flag = None

    def activate(self):
        "..."
        super(PolygonOperation, self).activate()
        if self.layer_fully_visible is not None:
            self.layer_fully_visible.remove_all_features()
            self.layer_fully_visible.refresh()
        if self.layer_drawing_polygon is not None:
            self.layer_drawing_polygon.remove_all_features()
            self.layer_drawing_polygon.refresh()
        if self.layer_input_polygon_points is not None:
            self.layer_input_polygon_points.remove_all_features()
            self.layer_input_polygon_points.refresh()
        if self.layer_reference is not None:
            self.layer_reference.remove_all_features()
            self.layer_reference.refresh()
        if self.layer_fully_invisible is not None:
            self.layer_fully_invisible.remove_all_features()
            self.layer_fully_invisible.refresh()
        if self.layer_partly_invisible is not None:
            self.layer_partly_invisible.remove_all_features()
            self.layer_partly_invisible.refresh()

        self.__create_layers__()
        self.action.setChecked(True)
        self.secondFreespacePolygon = self.freespacePolygon
        self.freespacePolygon = ad.geometry.Polygon()
        Globs.iface.messageBar().pushMessage("Click somewhere on the map to select it as reference point", level=Qgis.Info, duration=3)
        self.flag = True

    def deactivate(self):
        "..."
        super(PolygonOperation, self).deactivate()
        self.action.setChecked(False)

        if self.freespacePolygon:
            Globs.log.info("Polygon creation complete")
            ad.map.geometry.correctPolygon(self.freespacePolygon)
            self.__draw_polygon__(self.freespacePolygon)
            if self.secondFreespacePolygon is not None:
                Globs.log.info("Use old polygon to test multi polygon support")
                polygonList = ad.geometry.PolygonVector()
                polygonList.append(self.freespacePolygon)
                polygonList.append(self.secondFreespacePolygon)
                self.__calculate_regions(polygonList)
            else:
                self.__calculate_regions(self.freespacePolygon)

    def canvasReleaseEvent(self, event):  # pylint: disable=invalid-name
        "..."

        if self.flag == True:
            raw_point = self.toLayerCoordinates(self.layer_reference.layer, event.pos())
            mmpts = self.snapper.snap(raw_point)

            if mmpts is not None and mmpts[0] is not None:
                self.reference_point = mmpts[0].matched_point

                attrs = [str(self.reference_point)]

                self.layer_reference.add_QgsPointXY(raw_point, attrs)
                self.layer_reference.refresh()

                widget = QWidget()
                tf = False
                self.influence_distance, tf = QInputDialog.getDouble(
                    widget, "Enter influence distance                                      ", "Distance:                                           ", 100.0, False)

                Globs.log.info("Create polygon by clicking points on the map.. Click again to complete polygon")
                self.flag = False
        else:
            raw_pt = self.toLayerCoordinates(self.layer_input_polygon_points.layer, event.pos())
            attrs = [str(raw_pt.x)]
            self.layer_input_polygon_points.add_QgsPointXY(raw_pt, attrs)
            self.layer_input_polygon_points.refresh()

            geo_point_clicked = ad.map.point.createGeoPoint(raw_pt.x(), raw_pt.y(), 0.0)
            self.__add_points_to_polygon__(geo_point_clicked)

    def __draw_polygon__(self, input_polygon):

        debug_drawer = ad.geometry.DebugDrawing.DebugPolygon(input_polygon, "red", "Input")
        output_drawing = debug_drawer.getVector()
        geo_point_list = ad.map.point.GeoPointList()
        attrs = []
        for each_point in output_drawing:
            enu_point = ad.map.point.createENUPoint(each_point.x, each_point.y, 0.0)
            geo_point = ad.map.point.toGeo(enu_point)
            geo_point_list.append(geo_point)
        self.layer_drawing_polygon.add_lla(geo_point_list, attrs)
        self.layer_drawing_polygon.refresh()

    def __add_points_to_polygon__(self, geo):

        enu_point = ad.map.point.toENU(geo)
        point = ad.geometry.Point()
        point = ad.geometry.toPoint(enu_point.x.mENUCoordinate, enu_point.y.mENUCoordinate)
        ad.map.geometry.appendToPolygon(self.freespacePolygon, point)

    def __add_occupied_regions_to_layer__(self, layer, occupied_regions):
        for each_region in occupied_regions:

            LongitudinalLaneInterval = ad.map.route.LaneInterval()
            LongitudinalLaneInterval.lane_id = each_region.lane_id
            LongitudinalLaneInterval.start = each_region.longitudinal_range.minimum
            LongitudinalLaneInterval.end = each_region.longitudinal_range.maximum

            enu_border = ad.map.route.getENUBorder(LongitudinalLaneInterval)

            leftPoints = ad.map.lane.getLateralAlignmentEdge(
                enu_border, (ad.physics.ParametricValue(1.0) - each_region.lateral_range.maximum))
            rightPoints = ad.map.lane.getLateralAlignmentEdge(
                enu_border, (ad.physics.ParametricValue(1.0) - each_region.lateral_range.minimum))

            leftBorderPoints = ad.map.point.toGeo(leftPoints.points)
            rightBorderPoints = ad.map.point.toGeo(rightPoints.points)

            layer.add_lla2(leftBorderPoints, rightBorderPoints, [])
            layer.refresh()

    def __calculate_regions(self, visible_area):

        lane_regions = ad.map.geometry.extractRegions(
            visible_area, self.reference_point, self.influence_distance)

        self.__add_occupied_regions_to_layer__(self.layer_fully_invisible, lane_regions.fully_occluded)
        self.__add_occupied_regions_to_layer__(self.layer_partly_invisible, lane_regions.partly_occluded)
        self.__add_occupied_regions_to_layer__(self.layer_fully_visible, lane_regions.fully_visible)

    def __create_layers__(self):
        "..."
        if self.layer_fully_visible is None:
            self.layer_fully_visible = WGS84SurfaceLayer(Globs.iface,
                                                         self.FULLY_VISIBLE_TITLE,
                                                         self.FULLY_VISIBLE_COLOR,
                                                         [],
                                                         self.layer_group)

        if self.layer_drawing_polygon is None:
            self.layer_drawing_polygon = WGS84SurfaceLayer(Globs.iface,
                                                           self.INPUT_POLYGON_TITLE,
                                                           self.INPUT_POLYGON_COLOR,
                                                           [],
                                                           self.layer_group)
        if self.layer_fully_invisible is None:
            self.layer_fully_invisible = WGS84SurfaceLayer(Globs.iface,
                                                           self.FULLY_INVISIBLE_TITLE,
                                                           self.FULLY_INVISIBLE_COLOR,
                                                           [],
                                                           self.layer_group)

        if self.layer_partly_invisible is None:
            self.layer_partly_invisible = WGS84SurfaceLayer(Globs.iface,
                                                            self.PARTLY_INVISIBLE_TITLE,
                                                            self.PARTLY_INVISIBLE_COLOR,
                                                            [],
                                                            self.layer_group)

        if self.layer_input_polygon_points is None:
            attrs = [QgsField("Input polygon points", QVariant.String)]
            self.layer_input_polygon_points = WGS84PointLayer(Globs.iface,
                                                              self.INPUT_POINTS_TITLE,
                                                              self.INPUT_POINTS_SYMBOL,
                                                              self.INPUT_POINTS_COLOR,
                                                              self.INPUT_POINTS_SIZE,
                                                              attrs,
                                                              self.layer_group)

        if self.layer_reference is None:
            attrs = [QgsField("Reference Point", QVariant.String)]
            self.layer_reference = WGS84PointLayer(Globs.iface,
                                                   self.REFERENCE_TITLE,
                                                   self.REFERENCE_SYMBOL,
                                                   self.REFERENCE_COLOR,
                                                   self.REFERENCE_SIZE,
                                                   attrs,
                                                   self.layer_group)
