# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from qgis.core import QgsFeature, QgsFillSymbolV2, QgsGeometry, QgsLineSymbolV2, QgsSymbolV2, QgsSvgMarkerSymbolLayerV2
from qgis.core import QgsMapLayerRegistry, QgsMarkerLineSymbolLayerV2
from qgis.core import QgsMarkerSymbolV2, QgsPoint, QgsVectorLayer
from qgis.core import QgsArrowSymbolLayer, QgsProject
from qgis.core import QgsDataDefined, QgsLayerTreeGroup
from qgis.core import QGis
import os.path

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
        self.layer = QgsMapLayerRegistry.instance().addMapLayer(self.layer)
        self.canvas = iface.mapCanvas()
        if group is not None:
            # move layer to group
            self.iface.legendInterface().moveLayer(self.layer, group)

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
        legend = self.iface.legendInterface()
        legend.setLayerVisible(self.layer, show_it)

    def remove(self):
        "..."
        # It seems QGis does already delete the layers
        # Ensure that the layer is still in the registry before calling removeMapLayer
        if self.layer is not None and len(QgsMapLayerRegistry.instance().mapLayersByName(self.layer_name)) > 0:
            QgsMapLayerRegistry.instance().removeMapLayer(self.layer)
            self.layer = None

    def refresh(self):
        "..."
        if not self.canvas.isDrawing():
            self.layer.setCacheImage(None)
            self.layer.triggerRepaint()
            self.canvas.refresh()

    def refresh_legend(self):
        "..."
        self.iface.legendInterface().refreshLayerSymbology(self.layer)
        self.iface.mapCanvas().refresh()

    def poly_marker(self, placement, qcolor, width):
        "..."
        marker = QgsMarkerLineSymbolLayerV2()
        marker.setColor(qcolor)
        marker.setPlacement(placement)
        marker.setWidth(width)
        self.layer.rendererV2().symbol().appendSymbolLayer(marker)

    def poly_markers(self, qcolor, width):
        "..."
        self.poly_marker(QgsMarkerLineSymbolLayerV2.Vertex, qcolor, width * 1.33)
        self.poly_marker(QgsMarkerLineSymbolLayerV2.FirstVertex, qcolor, width * 2.25)
        self.poly_marker(QgsMarkerLineSymbolLayerV2.LastVertex, qcolor, width * 2.25)

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

        props = self.layer.rendererV2().symbol().symbolLayer(0).properties()
        svgStyle = {}
        svgStyle['name'] = self.svg_path + svg_resource
        svgStyle['outline'] = '#00000'
        svgStyle['outline-width'] = '0'
        svgStyle['size'] = svg_size
        symbol_layer = QgsSvgMarkerSymbolLayerV2.create(svgStyle)

        # Rotate the svg to reflect the orientation of a landmark
        # admap uses a counter-clockwise orientation with radians, qgis a clockwise and degrees
        dataDefinedAngle = QgsDataDefined(True, True, '(-("Orientation" * 180 / pi()) - 90) % 360')
        symbol_layer.setDataDefinedProperty('angle', dataDefinedAngle)

        # Make the SVG size scalable with the zoom level of the map
        # i.e. less zoom, smaller SVG
        dataDefinedSize = QgsDataDefined(True, True, 'CASE WHEN @map_scale < 500 THEN 1000 / @map_scale ELSE 2 END')
        symbol_layer.setDataDefinedProperty('size', dataDefinedSize)
        self.layer.rendererV2().symbols()[0].changeSymbolLayer(0, symbol_layer)

        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, point, attributes):
        "..."
        qgs_point = QgsPoint(point[0], point[1])
        geometry = QgsGeometry.fromPoint(qgs_point)
        return self.add_feature(geometry, attributes)


class WGS84PointLayer(WGS84Layer):

    "..."

    def __init__(self, iface, layer_name, symbol, color, size, attributes, group=None, visible=True):
        "..."
        WGS84Layer.__init__(self, iface, layer_name, "Point", visible, group)
        props = self.layer.rendererV2().symbol().symbolLayer(0).properties()
        symbol = QgsSymbolV2.defaultSymbol(QGis.Point)
        symbol.setSize(1.5)
        self.layer.rendererV2().setSymbol(symbol)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, point, attributes):
        "..."
        qgs_point = QgsPoint(point[0], point[1])
        geometry = QgsGeometry.fromPoint(qgs_point)
        return self.add_feature(geometry, attributes)


class WGS84PolylineLayer(WGS84Layer):

    "..."

    def __init__(self, iface, layer_name, color, width, qcolor, attributes, layer_group=None, visible=True):
        "..."
        WGS84Layer.__init__(self, iface, layer_name, "LineString", visible, layer_group)
        props = self.layer.rendererV2().symbol().symbolLayer(0).properties()
        props['line_color'] = color
        props['line_width'] = width
        line = QgsLineSymbolV2.createSimple(props)
        self.layer.rendererV2().setSymbol(line)
        self.poly_markers(qcolor, float(width))
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, polyline, attributes):
        "..."
        if len(polyline) > 1:
            poly = []
            for point in polyline:
                poly.append(QgsPoint(point[0], point[1]))
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
        self.layer.rendererV2().symbol().changeSymbolLayer(0, arrow_layer)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, pt_from, pt_to, attributes):
        "..."
        poly = [QgsPoint(pt_from[0], pt_from[1]), QgsPoint(pt_to[0], pt_to[1])]
        geometry = QgsGeometry.fromPolyline(poly)
        return self.add_feature(geometry, attributes)


class WGS84SurfaceLayer(WGS84Layer):

    "..."

    def __init__(self, iface, name, color, attributes, layer_group=None, out_color=None, w="0.1", visible=True):
        "..."
        if out_color is None:
            out_color = color
        WGS84Layer.__init__(self, iface, name, "Polygon", visible, layer_group)
        props = self.layer.rendererV2().symbol().symbolLayer(0).properties()
        props['color'] = color
        props['outline_color'] = out_color
        props['outline_width'] = w
        fill_symbol = QgsFillSymbolV2.createSimple(props)
        self.layer.rendererV2().setSymbol(fill_symbol)
        WGS84Layer.refresh_legend(self)
        self.set_attributes(attributes)

    def add_lla(self, polygon, attrs):
        "..."
        if len(polygon) > 1:
            poly = []
            for point in polygon:
                poly.append(QgsPoint(point[0], point[1]))
            poly.append(poly[0])
            geom = QgsGeometry.fromPolygon([poly])
            return self.add_feature(geom, attrs)
        return None

    def add_lla2(self, edge, another_edge, attrs):
        "..."
        if len(edge) > 1 and len(another_edge) > 1:
            another_edge.reverse()
            edge.extend(another_edge)
            return self.add_lla(edge, attrs)
        return None
