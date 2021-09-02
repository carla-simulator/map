# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from qgis.core import QgsFeature, QgsFillSymbol, QgsGeometry, QgsLineSymbol, QgsSymbol, QgsSvgMarkerSymbolLayer
from qgis.core import QgsProject, QgsMarkerLineSymbolLayer, QgsWkbTypes
from qgis.core import QgsMarkerSymbol, QgsPoint, QgsVectorLayer
from qgis.core import QgsArrowSymbolLayer, QgsProject,  QgsPointXY
from qgis.core import QgsProperty, QgsLayerTreeGroup, QgsRenderContext
from qgis.core import Qgis, QgsProject, QgsLayerTreeModel, QgsLayerTreeLayer, QgsSymbolLayer
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from qgis.gui import *
import os.path
import Globs
import ad_map_access as ad

# Too many arguments
# pylint: disable=R0913


class WGS84Layer(object):

    "..."

    def __init__(self, iface, layer_name, layer_type, visible, group=None, show_count=True):
        "..."
        self.iface = iface
        self.layer_name = layer_name
        self.visible = visible
        self.layer = QgsVectorLayer(layer_type + "?crs=EPSG:4326", layer_name, "memory")
        self.provider = self.layer.dataProvider()
        self.layer = QgsProject.instance().addMapLayer(self.layer)
        self.canvas = iface.mapCanvas()
        if group is not None:
            layer_t = QgsProject.instance().mapLayersByName(layer_name)[0]
            root = QgsProject.instance().layerTreeRoot()

            myLayer = root.findLayer(layer_t.id())
            myClone = myLayer.clone()
            parent = myLayer.parent()

            group.insertChildNode(0, myClone)
            parent.removeChildNode(myLayer)

            # collapse groups
            for child in QgsProject.instance().layerTreeRoot().children():
                if isinstance(child, QgsLayerTreeGroup):
                    child.setExpanded(False)

        if show_count:
            root = QgsProject.instance().layerTreeRoot()
            leaf = root.findLayer(self.layer.id())
            leaf.setCustomProperty("showFeatureCount", True)

    def show(self, show_it):
        "..."
        node = QgsProject.instance().layerTreeRoot().findLayer(self.layer)
        if node:
            node.setItemVisibilityChecked(show_it)

    def remove(self):
        "..."
        # It seems QGis does already delete the layers
        # Ensure that the layer is still in the registry before calling removeMapLayer
        if self.layer is not None and len(QgsProject.instance().mapLayersByName(self.layer_name)) > 0:
            QgsProject.instance().removeMapLayer(self.layer)
            self.layer = None

    def refresh(self):
        "..."
        if not self.canvas.isDrawing():
            self.layer.triggerRepaint(True)
            self.canvas.refresh()

    def refresh_legend(self):
        "..."
        root = QgsProject.instance().layerTreeRoot().findLayer(self.layer.id())
        self.iface.layerTreeView().layerTreeModel().refreshLayerLegend(root)
        self.iface.mapCanvas().refresh()

    def poly_marker(self, placement, qcolor, width):
        "..."
        marker = QgsMarkerLineSymbolLayer()
        marker.setColor(qcolor)
        marker.setPlacement(placement)
        marker.setWidth(width)
        self.layer.renderer().symbol().appendSymbolLayer(marker)

    def poly_markers(self, qcolor, width):
        "..."
        self.poly_marker(QgsMarkerLineSymbolLayer.Vertex, qcolor, width * 1.33)
        self.poly_marker(QgsMarkerLineSymbolLayer.FirstVertex, qcolor, width * 2.25)
        self.poly_marker(QgsMarkerLineSymbolLayer.LastVertex, qcolor, width * 2.25)

    def set_attributes(self, attributes):
        "..."
        self.provider.addAttributes(attributes)
        self.layer.updateFields()

    def add_feature(self, geometry, attributes):
        "..."
        added_feature = QgsFeature()
        added_feature.setGeometry(geometry)
        added_feature.setAttributes(attributes)
        success, feat = self.provider.addFeatures([added_feature])
        if success:
            self.layer.updateExtents()
            return feat[0]
        return None

    def remove_feature(self, feature):
        "..."
        self.provider.deleteFeatures([feature.id()])

    def remove_all_features(self):
        "..."
        for feature in self.layer.getFeatures():
            self.remove_feature(feature)

    def enable_labeling(self, field, font="Arial", size=10, weight=50, rgb=(0, 0, 0), placement=1):
        "..."
        self.layer.setCustomProperty("labeling", "pal")
        self.layer.setCustomProperty("labeling/enabled", "true")
        self.layer.setCustomProperty("labeling/fontFamily", font)
        self.layer.setCustomProperty("labeling/fontSize", str(size))
        self.layer.setCustomProperty("labeling/fontWeight", str(weight))
        self.layer.setCustomProperty("labeling/textColorR", str(rgb[0]))
        self.layer.setCustomProperty("labeling/textColorG", str(rgb[1]))
        self.layer.setCustomProperty("labeling/textColorB", str(rgb[2]))
        self.layer.setCustomProperty("labeling/placement", str(placement))
        self.layer.setCustomProperty("labeling/fieldName", field)


class WGS84SVGPointLayer(WGS84Layer):

    "..."

    def __init__(self, iface, layer_name, svg_size, attributes, svg_resource, group=None, visible=True):
        "..."
        self.svg_path = os.path.dirname(__file__) + "/icons/"
        WGS84Layer.__init__(self, iface, layer_name, "Point", visible, group)

        symbol = QgsSymbol.defaultSymbol(self.layer.geometryType())
        svgStyle = {}
        svgStyle['name'] = self.svg_path + svg_resource
        svgStyle['outline'] = '#00000'
        svgStyle['outline-width'] = '0'
        svgStyle['size'] = svg_size
        symbol_layer = QgsSvgMarkerSymbolLayer.create(svgStyle)

        # Rotate the svg to reflect the orientation of a landmark
        # admap uses a counter-clockwise orientation with radians, qgis a clockwise and degrees
        dataDefinedAngle = QgsProperty.fromExpression('(-("Orientation" * 180 / pi()) - 90) % 360', True)
        symbol_layer.setDataDefinedProperty(QgsSymbolLayer.PropertyAngle, dataDefinedAngle)

        # Make the SVG size scalable with the zoom level of the map
        # i.e. less zoom, smaller SVG
        dataDefinedSize = QgsProperty.fromExpression(
            'CASE WHEN @map_scale < 500 THEN 1000 / @map_scale ELSE 2 END', True)
        symbol_layer.setDataDefinedProperty(QgsSymbolLayer.PropertySize, dataDefinedSize)

        if symbol_layer is not None:
            symbols = self.layer.renderer().symbols(QgsRenderContext())
            sym = symbols[0]
            sym.changeSymbolLayer(0, symbol_layer)

        self.layer.triggerRepaint()
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, point, attributes):
        "..."
        qgs_point = QgsPointXY(point.longitude, point.latitude)
        geometry = QgsGeometry.fromPointXY(qgs_point)
        return self.add_feature(geometry, attributes)


class WGS84PointLayer(WGS84Layer):

    "..."

    def __init__(self, iface, layer_name, symbol, color, size, attributes, group=None, visible=True):
        "..."
        WGS84Layer.__init__(self, iface, layer_name, "Point", visible, group)
        props = self.layer.renderer().symbol().symbolLayer(0).properties()
        symbol = QgsSymbol.defaultSymbol(QgsWkbTypes.PointGeometry)
        symbol.setSize(1.5)
        self.layer.renderer().setSymbol(symbol)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, point, attributes):
        "..."
        qgs_point = QgsPointXY(point.x, point.y)
        geometry = QgsGeometry.fromPointXY(qgs_point)
        return self.add_feature(geometry, attributes)

    def add_ecef(self, point, attributes):
        "..."
        geo_point = ad.map.point.toGeo(point)
        qgs_point = QgsPointXY(float(geo_point.longitude), float(geo_point.latitude))
        geometry = QgsGeometry.fromPointXY(qgs_point)
        return self.add_feature(geometry, attributes)


class WGS84PolylineLayer(WGS84Layer):

    "..."

    def __init__(self, iface, layer_name, color, width, qcolor, attributes, layer_group=None, visible=True):
        "..."
        WGS84Layer.__init__(self, iface, layer_name, "LineString", visible, layer_group)
        props = self.layer.renderer().symbol().symbolLayer(0).properties()
        props['line_color'] = color
        props['line_width'] = width
        line = QgsLineSymbol.createSimple(props)
        self.layer.renderer().setSymbol(line)
        self.poly_markers(qcolor, float(width))
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, polyline, attributes):
        "..."
        if len(polyline) > 1:
            poly = []
            for point in polyline:
                poly.append(QgsPoint(point.longitude, point.latitude, point.altitude))
            geometry = QgsGeometry.fromPolyline(poly)
            return self.add_feature(geometry, attributes)
        return None


class WGS84ArrowLayer(WGS84Layer):

    "..."

    def __init__(self, iface, name, qcolor, width, attributes, layer_group=None, visible=True):
        "..."
        WGS84Layer.__init__(self, iface, name, "LineString", visible, layer_group)
        arrow_layer = QgsArrowSymbolLayer()
        arrow_layer.setColor(qcolor)
        arrow_layer.setArrowWidth(width)
        arrow_layer.setArrowStartWidth(width)
        arrow_layer.setHeadThickness(width * 2.0)
        self.layer.renderer().symbol().changeSymbolLayer(0, arrow_layer)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, pt_from, pt_to, attributes):
        "..."
        poly = []
        pt = QgsPoint(pt_from.longitude, pt_from.latitude, pt_from.altitude)
        poly.append(pt)
        pt1 = QgsPoint(pt_to.longitude, pt_to.latitude, pt_to.altitude)
        poly.append(pt1)
        geometry = QgsGeometry.fromPolyline(poly)
        return self.add_feature(geometry, attributes)


class WGS84SurfaceLayer(WGS84Layer):

    "..."

    def __init__(self, iface, name, color, attributes, layer_group=None, out_color=None, w="0.1", visible=True):
        "..."
        if out_color is None:
            out_color = color
        WGS84Layer.__init__(self, iface, name, "Polygon", visible, layer_group)
        props = self.layer.renderer().symbol().symbolLayer(0).properties()
        props['color'] = color
        props['outline_color'] = out_color
        props['outline_width'] = w
        fill_symbol = QgsFillSymbol.createSimple(props)
        self.layer.renderer().setSymbol(fill_symbol)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, polygon, attrs):
        "..."
        if len(polygon) > 1:
            poly = []
            for point in polygon:
                poly.append(QgsPointXY(point.longitude, point.latitude))
            poly.append(poly[0])
            geom = QgsGeometry.fromPolygonXY([poly])
            return self.add_feature(geom, attrs)
        return None

    def add_lla2(self, edge, another_edge, attrs):
        "..."
        if len(edge) > 1 and len(another_edge) > 1:
            another_edge.reverse()
            for point in another_edge:
                edge.append(point)
            return self.add_lla(edge, attrs)
        return None
