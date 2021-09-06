# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
"..."

from PyQt5.QtCore import QVariant
from PyQt5.QtGui import QColor
from qgis.core import QgsField, QgsProject

import ad_map_access as ad
import Globs
from .QGISLayer import WGS84ArrowLayer, WGS84PolylineLayer, WGS84SurfaceLayer, WGS84PointLayer, WGS84SVGPointLayer
from .LayerManagerLaneEdge import LayerManagerLaneEdge
from .LayerManagerLaneSurface import LayerManagerLaneSurface
from .LayerManagerLaneDirection import LayerManagerLaneDirection
from .LayerManagerLaneOrientation import LayerManagerLaneOrientation
from .LayerManagerLaneSpeed import LayerManagerLaneSpeed
from .LayerManagerLaneTopology import LayerManagerLaneTopology
from .LayerManagerLaneContactType import LayerManagerLaneContactType
from .LayerManagerLandmark import LayerManagerLandmark

#
# ADMapQgs Class
# pylint: disable=C0103, R0902


class ADMapQgsLayers(object):

    "..."

    # constants
    MISC = "Miscellaneous"
    GEOM = "Lane Geometry"
    LANES = "Lane Types"
    SPEEDS = "Speed Limits"
    TOPO = "Topology"
    LANDMARK = "Landmarks"
    LANE_EDGE = "Lane Edge"
    LANE_DIRECTION = "Lane Direction"
    LANE_ORIENTATION = "Lane Orientation"
    CONTACT_TYPE = "Contact Type"
    #
    LANE_EDGE_COLOR = "255, 0, 0"
    LANE_EDGE_WIDTH = "1.0"
    LANE_EDGE_MARKER_QCOLOR = QColor(0, 0, 0)
    #
    NEW_LANE_EDGE_COLOR = "0, 0, 255"
    NEW_LANE_EDGE_WIDTH = "1.0"
    NEW_LANE_EDGE_MARKER_QCOLOR = QColor(255, 0, 0)
    #
    TOPOLOGY_ARROW_WIDTH = 1
    DIRECTION_ARROW_WIDTH = 0.5
    ORIENTATION_ARROW_WIDTH = 0.3
    #
    QCOLOR_DIRECTION = QColor(255, 255, 0)
    QCOLOR_ORIENTATION = QColor(128, 128, 128)
    #
    LANE_SURFACE_COLOR_HOV = "255, 128, 192, 33"
    #
    LANE_SURFACE_COLOR = {
        "UNKNOWN":      "255, 128,   0, 50",
        "NORMAL":       "  0,   0, 192, 50",
        "INTERSECTION": " 64, 160,  64, 33",
        "OTHER":        "  0,   0,   0, 50"}
    #
    LANE_SPEED_COLOR = {
        "Not set":      "224, 224, 224, 50",
        "Set":       " 32, 255, 255, 50"}
    #
    LANE_TOPO = {
        "Left":         (QColor(0, 255, 0), 0.4, 0.5),
        "Right":       (QColor(0, 0, 255), 0.6, 0.5),
        "Successor":   (QColor(255, 255, 0), 0.95, 0.2),
        "Predecessor": (QColor(0, 255, 255), 0.05, 0.8),
        "Overlap":      (QColor(255, 0, 255), 0.5, 0.5)}

    LANE_CONTACT_TYPE = {
        "STOP":               "stop.svg",
        "STOP_ALL":           "stop_all.svg",
        "YIELD":              "yield.svg",
        "TRAFFIC_LIGHT":      "traffic_light.svg",
        "CROSSWALK":          "crosswalk.svg",
        "PRIO_TO_RIGHT":      "prio_to_right.svg",
        "RIGHT_OF_WAY":       "right_of_way.svg",
        "PRIO_TO_RIGHT_AND_STRAIGHT":      "prio_to_right_and_straight.svg"}
    LANDMARK_TYPE = {
        "LANDMARK": "map_marker.svg",
        "TREE": "tree.svg",
                "STREET_LAMP": "streetlamp.svg",
                "TRAFFIC_LIGHT": "traffic_light_landmark.svg",
                "DANGER": "Zeichen_101_-_Gefahrstelle_StVO_1970.svg",
                "LANES_MERGING": "Zeichen_120_-_Verengte_Fahrbahn_StVO_1970.svg",
                "CAUTION_PEDESTRIAN": "Zeichen_133-10_-_Fussgaenger_Aufstellung_rechts_StVO_1992.svg",
                "CAUTION_CHILDREN": "Zeichen_136-10_-_Kinder_Aufstellung_rechts_StVO_1992.svg",
                "CAUTION_BICYCLE": "Zeichen_138-10_-_Radverkehr_StVO_2013.svg",
                "CAUTION_ANIMALS": "Zeichen_142-10_-_Wildwechsel_Aufstellung_rechts_StVO_1992.svg",
                "CAUTION_RAIL_CROSSING_WITH_BARRIER": "Zeichen_150_-_Beschrankter_Bahnuebergang_StVO_1992.svg",
                "CAUTION_RAIL_CROSSING": "Zeichen_151_-_Bahnuebergang_StVO_2013.svg",
                "YIELD_TRAIN": "Zeichen_201-51_-_Andreaskreuz_stehend_mit_Blitzpfeil_StVO_1992.svg",
                "YIELD": "Zeichen_205_-_Vorfahrt_gewaehren_StVO_1970.svg",
                "STOP": "Zeichen_206_-_Halt_Vorfahrt_gewaehren_StVO_1970.svg",
                "REQUIRED_LEFT_TURN": "Zeichen_209-10_-_Vorgeschriebene_Fahrtrichtung_links_StVO_2017.svg",
                "REQUIRED_STRAIGHT": "Zeichen_209-30_-_Vorgeschriebene_Fahrtrichtung_Geradeaus_StVO_2017.svg",
                "REQUIRED_RIGHT_TURN": "Zeichen_209_-_Vorgeschriebene_Fahrtrichtung_rechts_StVO_2017.svg",
                "REQUIRED_STRAIGHT_OR_LEFT_TURN": "Zeichen_214-10_-_Vorgeschriebene_Fahrtrichtung_Geradeaus_oder_links_StVO_2017.svg",
                "REQUIRED_STRAIGHT_OR_RIGHT_TURN": "Zeichen_214_-_Vorgeschriebene_Fahrtrichtung_Geradeaus_oder_rechts_StVO_2017.svg",
                "ROUNDABOUT": "Zeichen_215_-_Kreisverkehr_StVO_2000.svg",
                "PASS_LEFT": "Zeichen_222-10_-_Vorgeschriebene_Vorbeifahrt_Links_vorbei_StVO_2017.svg",
                "PASS_RIGHT": "Zeichen_222_-_Vorgeschriebene_Vorbeifahrt_Rechts_vorbei_StVO_2017.svg",
                "BYBICLE_PATH": "Zeichen_237_-_Sonderweg_Radfahrer_StVO_1992.svg",
                "FOOTWALK": "Zeichen_239_-_Sonderweg_Fussgaenger_StVO_1992.svg",
                "FOOTWALK_BICYCLE_SHARED": "Zeichen_240_-_Gemeinsamer_Fuss-_und_Radweg_StVO_1992.svg",
                "FOOTWALK_BICYCLE_SEP_LEFT": "Zeichen_241-30_-_getrennter_Rad-_und_Fussweg_StVO_1992.svg",
                "FOOTWALK_BICYCLE_SEP_RIGHT": "Zeichen_241-31_-_getrennter_Fuss-_und_Radweg_StVO_1992.svg",
                "PEDESTRIAN_AREA_BEGIN": "Zeichen_242.1_-_Beginn_einer_Fussgaengerzone_StVO_2009.svg",
                "ACCESS_FORBIDDEN": "Zeichen_250_-_Verbot_fuer_Fahrzeuge_aller_Art_StVO_1970.svg",
                "ACCESS_FORBIDDEN_TRUCKS": "Zeichen_253_-_Verbot_fuer_Kraftfahrzeuge_mit_einem_zulaessigen_Gesamtgewicht_StVO_1992.svg",
                "ACCESS_FORBIDDEN_BICYCLE": "Zeichen_254_-_Verbot_fuer_Radfahrer_StVO_1992.svg",
                "ACCESS_FORBIDDEN_MOTORVEHICLES": "Zeichen_260_-_Verbot_fuer_Kraftraeder_und_Mofas_und_sonstige_mehrspurige_Kraftfahrzeuge_StVO_1992.svg",
                "ACCESS_FORBIDDEN_WEIGHT": "Zeichen_262-5_5_-_Verbot_fuer_Fahrzeuge_ueber_angegebene_tatsaechliche_Masse_StVO_2017.svg",
                "ACCESS_FORBIDDEN_WIDTH": "Zeichen_264-2_-_Verbot_fuer_Fahrzeuge_ueber_angegebene_tatsaechliche_Breite_StVO_2017.svg",
                "ACCESS_FORBIDDEN_HEIGHT": "Zeichen_265-3_8_-_Verbot_fuer_Fahrzeuge_ueber_angegebene_tatsaechliche_Hoehe_StVO_2017.svg",
                "ACCESS_FORBIDDEN_WRONG_DIR": "Zeichen_267_-_Verbot_der_Einfahrt_StVO_1970.svg",
                "ENVIORNMENT_ZONE_BEGIN": "Zeichen_270.1_-_Beginn_eines_Verkehrsverbots_zur_Verminderung_schaedlicher_Luftverunreinigungen_in_einer_Zone_I_StVO_2007.svg",
                "ENVIORNMENT_ZONE_END": "Zeichen_270.2_-_Ende_einer_Verkehrsverbotszone_zur_Verminderung_schaedlicher_Luftverunreinigungen_in_einer_Zone_StVO_2007.svg",
                "SPEED_ZONE_30_BEGIN": "Zeichen_274.1_-_Beginn_einer_Tempo_30-Zone_StVO_2013.svg",
                "SPEED_ZONE_30_END": "Zeichen_274.2_-_Ende_einer_Tempo_30-Zone_einseitig_StVO_2013.svg",
                "MAX_SPEED": "Zeichen_274-50_-_Zulaessige_Hoechstgeschwindigkeit_StVO_2017.svg",
                "HAS_WAY_NEXT_INTERSECTION": "Zeichen_301_-_Vorfahrt_StVO_1970.svg",
                "PRIORITY_WAY": "Zeichen_306_-_Vorfahrtstrasse_StVO_1970.svg",
                "CITY_BEGIN": "Zeichen_310_-_Ortstafel_Vorderseite_StVO_2017.svg",
                "CITY_END": "Zeichen_311_-_Ortstafel_Rueckseite_StVO_2017.svg",
                "MOTORWAY_BEGIN": "Zeichen_330.1_-_Autobahn_StVO_2013.svg",
                "MOTORWAY_END": "Zeichen_330.2_-_Ende_der_Autobahn_StVO_2013.svg",
                "MOTORVEHICLE_BEGIN": "Zeichen_331.1_-_Kraftfahrstrasse_StVO_2013.svg",
                "MOTORVEHICLE_END": "Zeichen_331.2_-_Ende_der_Kraftfahrstrasse_StVO_2013.svg",
                "INFO_MOTORWAY_INFO": "Zeichen_332_-_Ausfahrt_von_der_Autobahn_StVO_1981.svg",
                "CUL_DE_SAC_EXCEPT_PED_BICYCLE": "Zeichen_357-50_-_Durchlaessige_Sackgasse_fuer_Fussgaenger_und_Radverkehr_StVO_2009.svg",
                "CUL_DE_SAC": "Zeichen_357_-_Sackgasse_StVO_1992.svg",
                "INFO_NUMBER_OF_AUTOBAHN": "Zeichen_405_-_Nummernschild_fuer_Autobahnen_StVO_1992.svg",
                "DIRECTION_TURN_TO_AUTOBAHN": "Zeichen_430-20_-_Wegweiser_zur_Autobahn_StVO_1992.svg",
                "DIRECTION_TURN_TO_LOCAL": "Zeichen_432-20_-_Wegweiser_zu_inneroertlichen_Zielen_und_zu_Einrichtungen_mit_erheblicher_Verkehrsbedeutung_rechtsweisend_nach_RWB_StVO_1992.svg",
                "DESTINATION_BOARD": "Zeichen_438_-_Vorwegweiser_StVO_1992.svg",
                "SUPPLEMENT_ARROW_APPLIES_LEFT": "Zusatzzeichen_1000-11_-_Richtung_der_Gefahrstelle_linksweisend_StVO_1992.svg",
                "SUPPLEMENT_ARROW_APPLIES_RIGHT": "Zusatzzeichen_1000-21_-_Richtung_der_Gefahrstelle_rechtsweisend_StVO_1992.svg",
                "SUPPLEMENT_ARROW_APPLIES_LEFT_RIGHT": "Zusatzzeichen_1000-30_-_beide_Richtungen_zwei_gegengerichtete_waagerechte_Pfeile_StVO_1992.svg",
                "SUPPLEMENT_ARROW_APPLIES_UP_DOWN": "Zusatzzeichen_1000-31_-_beide_Richtungen_zwei_gegengerichtete_senkrechte_Pfeile_StVO_1992.svg",
                "SUPPLEMENT_ARROW_APPLIES_LEFT_RIGHT_BICYCLE": "Zusatzzeichen_1000-32_-_Radfahrer_kreuzen_von_rechts_und_links_StVO_1997.svg",
                "SUPPLEMENT_ARROW_APPLIES_UP_DOWN_BICYCLE": "Zusatzzeichen_1000-33_-_Radverkehr_im_Gegenverkehr_StVO_1997.svg",
                "SUPPLEMENT_APPLIES_NEXT_N_KM": "Zusatzzeichen_1001-31_-_auf_..._km_600x330_StVO_1992.svg",
                "SUPPLEMENT_ENDS": "Zusatzzeichen_1012-31_-_Ende_600x330_StVO_1992.svg",
                "SUPPLEMENT_RESIDENTS_ALLOWED": "Zusatzzeichen_1020-30_-_Anlieger_frei_600x330_StVO_1992.svg",
                "SUPPLEMENT_BICYCLE_ALLOWED": "Zusatzzeichen_1022-10_-_Radfahrer_frei_StVO_1992.svg",
                "SUPPLEMENT_MOPED_ALLOWED": "Zusatzzeichen_1022-11_-_Mofas_frei_600x450_StVO_1992.svg",
                "SUPPLEMENT_TRAM_ALLOWED": "Zusatzzeichen_1024-16_-_Strassenbahn_frei_StVO_1992.svg",
                "SUPPLEMENT_FORESTAL_ALLOWED": "Zusatzzeichen_1026-37_-_Forstwirtschaflicher_Verkehr_frei_StVO_1992.svg",
                "SUPPLEMENT_CONSTRUCTION_VEHICLE_ALLOWED": "Zusatzzeichen_1028-30_-_Baustellenfahrzeuge_frei_450x600_StVO_1992.svg",
                "SUPPLEMENT_ENVIRONMENT_ZONE_YELLOW_GREEN": "Zusatzzeichen_1031-51_-_Freistellung_vom_Verkehrsverbot_nach_para_40_Abs._1_BlmSchG_gelbe_und_gruene_Plakette_StVO_2017.svg",
                "SUPPLEMENT_RAILWAY_ONLY": "Zusatzzeichen_1048-18_-_nur_Schienenbahn_600x450_StVO_1992.svg",
                "SUPPLEMENT_APPLIES_FOR_WEIGHT": "Zusatzzeichen_1053-33_-_Massenangabe_7_5_t_420x231_StVO_2017.svg"}

    def __init__(self):
        "..."
        self.layer = {}
        self.layer_managers = {}
        self.layer_managers_speed = []
        self.layer_managers_surface = []
        self.layer_managers_topology = []
        self.layer_managers_landmark = []
        self.layer_managers_contact_type = []
        self.layer_groups = {}
        self.layer_new_lane = None

    def create_all(self):
        "..."
        if not self.layer:
            self.__create_layer_groups__()
            self.__create_layers__()

    def remove_all(self):
        "..."
        for layer_name in self.layer:
            if self.layer[layer_name] is not None:
                self.layer[layer_name].remove()
                self.layer[layer_name] = None
        self.layer = {}
        self.layer_managers = {}
        self.layer_managers_speed = []
        self.layer_managers_surface = []
        self.layer_managers_topology = []
        self.layer_managers_landmark = []
        self.layer_managers_contact_type = []
        QgsProject.instance().clear()

    def __create_layer_groups__(self):
        "..."

        legend = QgsProject.instance().layerTreeRoot()
        self.layer_groups[self.GEOM] = legend.addGroup(self.GEOM)
        self.layer_groups[self.LANES] = legend.addGroup(self.LANES)
        self.layer_groups[self.SPEEDS] = legend.addGroup(self.SPEEDS)
        self.layer_groups[self.CONTACT_TYPE] = legend.addGroup(self.CONTACT_TYPE)
        self.layer_groups[self.TOPO] = legend.addGroup(self.TOPO)
        self.layer_groups[self.MISC] = legend.addGroup(self.MISC)
        self.layer_groups[self.LANDMARK] = legend.addGroup(self.LANDMARK)

    def __create_layers__(self):
        "..."
        self.__add_lane_dir_layer__()
        self.__add_lane_orientation_layer__()
        for contact_type in self.LANE_CONTACT_TYPE:
            self.__add_lane_contact_type_layer__(contact_type)
        for topo in self.LANE_TOPO:
            self.__add_lane_topo_layer__(topo)
        self.__add_lane_speed_layer__()
        lane_types = self.lane_types()
        for lane_type in lane_types:
            color = ADMapQgsLayers.LANE_SURFACE_COLOR[lane_type]
            self.__add_lane_surface_layer__(lane_type, False, color)
        self.__add_lane_edge_layer__()
        for landmark_type in sorted(self.LANDMARK_TYPE):
            self.__add_landmark_layer__(landmark_type)
        self.__create_new_lane_layer__()

    def __add_landmark_layer__(self, landmark_type):
        "..."
        title = landmark_type
        svg_resource = self.LANDMARK_TYPE[landmark_type]
        group = self.layer_groups[self.LANDMARK]
        svg_size = '8'
        attrs = [QgsField("Id", QVariant.LongLong), QgsField(
            "Type", QVariant.String), QgsField("Orientation", QVariant.Double)]
        layer = WGS84SVGPointLayer(Globs.iface, title, svg_size, attrs, svg_resource, group)
        layer_manager = LayerManagerLandmark(layer, landmark_type)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager
        self.layer_managers_landmark.append(layer_manager)

    def __add_lane_edge_layer__(self):
        "..."
        title = self.LANE_EDGE
        attr_keys = []
        attr_keys.append(QgsField("Id", QVariant.LongLong))
        attr_keys.append(QgsField("Side", QVariant.String))
        layer = WGS84PolylineLayer(Globs.iface, title,
                                   ADMapQgsLayers.LANE_EDGE_COLOR,
                                   ADMapQgsLayers.LANE_EDGE_WIDTH,
                                   ADMapQgsLayers.LANE_EDGE_MARKER_QCOLOR,
                                   attr_keys, self.layer_groups[self.GEOM])
        layer_manager = LayerManagerLaneEdge(layer)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager

    def __add_lane_surface_layer__(self, typ, hov, color):
        "..."
        lane_ids = []
        lane_list = ad.map.lane.getLanes()
        for lane_id in lane_list:
            lane = ad.map.lane.getLane(lane_id)
            if(ad.map.lane.satisfiesFilter(lane, typ, hov)):
                lane_ids.append(lane_id)

        attr_keys = []
        attr_keys.append(QgsField("Id", QVariant.LongLong))
        attr_keys.append(QgsField("Type", QVariant.String))
        attr_keys.append(QgsField("HOV", QVariant.String))
        attr_keys.append(QgsField("Road ID", QVariant.Int))
        attr_keys.append(QgsField("Lane Section Index", QVariant.Int))
        attr_keys.append(QgsField("Lane Index", QVariant.Int))
        if lane_ids is not None:
            title = self.lane_surface_layer_name(typ, hov)
            group = self.layer_groups[self.LANES]
            layer = WGS84SurfaceLayer(Globs.iface, title, color, attr_keys, group)
            layer_manager = LayerManagerLaneSurface(layer)
            self.layer[title] = layer
            self.layer_managers[title] = layer_manager
            self.layer_managers_surface.append(layer_manager)

    def __add_lane_speed_layer__(self):
        "..."
        layers = []
        attr_keys = []
        attr_keys.append(QgsField("Id", QVariant.LongLong))
        attr_keys.append(QgsField("Start", QVariant.Double))
        attr_keys.append(QgsField("End", QVariant.Double))
        attr_keys.append(QgsField("Speed Limit", QVariant.Double))
        lane_speeds = self.lane_speeds()
        for lane_speed in lane_speeds:
            color = self.LANE_SPEED_COLOR[lane_speed]
            group = self.layer_groups[self.SPEEDS]
            layer = WGS84SurfaceLayer(Globs.iface, lane_speed, color, attr_keys, group)
            layer_manager = LayerManagerLaneSpeed(layer)
            self.layer[lane_speed] = layer
            self.layer_managers[lane_speed] = layer_manager
            self.layer_managers_speed.append(layer_manager)
            layers.append(layer)

    def __add_lane_topo_layer__(self, position):
        "..."
        title = "Lane " + position
        qcolor = self.LANE_TOPO[position][0]
        tlon = self.LANE_TOPO[position][1]
        tlat = self.LANE_TOPO[position][2]
        attrs = [QgsField("From Lane", QVariant.LongLong),
                 QgsField("To Lane", QVariant.LongLong),
                 QgsField("Types", QVariant.String)]
        width = ADMapQgsLayers.TOPOLOGY_ARROW_WIDTH
        group = self.layer_groups[self.TOPO]
        visible = False
        layer = WGS84ArrowLayer(Globs.iface, title, qcolor, width, attrs, group, visible)
        layer_manager = LayerManagerLaneTopology(layer, position, tlon, tlat)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager
        self.layer_managers_topology.append(layer_manager)

    def __add_lane_contact_type_layer__(self, contact_type):
        "..."
        title = "Contact " + contact_type
        svg_resource = self.LANE_CONTACT_TYPE[contact_type]
        group = self.layer_groups[self.CONTACT_TYPE]
        svg_size = '10'
        attrs = [QgsField("From Lane", QVariant.LongLong),
                 QgsField("To Lane", QVariant.LongLong),
                 QgsField("Contact Type", QVariant.String)]
        layer = WGS84SVGPointLayer(Globs.iface, title, svg_size, attrs, svg_resource, group)
        layer_manager = LayerManagerLaneContactType(layer, contact_type)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager
        self.layer_managers_contact_type.append(layer_manager)

    def __add_lane_dir_layer__(self):
        "..."
        title = self.LANE_DIRECTION
        attrs = [QgsField("Lane Id", QVariant.LongLong), QgsField("Direction", QVariant.String)]
        color = ADMapQgsLayers.QCOLOR_DIRECTION
        width = ADMapQgsLayers.DIRECTION_ARROW_WIDTH
        group = self.layer_groups[self.GEOM]
        layer = WGS84ArrowLayer(Globs.iface, title, color, width, attrs, group)
        layer_manager = LayerManagerLaneDirection(layer)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager

    def __add_lane_orientation_layer__(self):
        "..."
        title = self.LANE_ORIENTATION
        attrs = [QgsField("Lane Id", QVariant.LongLong)]
        color = ADMapQgsLayers.QCOLOR_ORIENTATION
        width = ADMapQgsLayers.ORIENTATION_ARROW_WIDTH
        group = self.layer_groups[self.GEOM]
        visible = False
        layer = WGS84ArrowLayer(Globs.iface, title, color, width, attrs, group, visible)
        layer_manager = LayerManagerLaneOrientation(layer)
        self.layer[title] = layer
        self.layer_managers[title] = layer_manager

    def __create_new_lane_layer__(self):
        "..."
        title = "New Lane Edges"
        layer = WGS84PolylineLayer(Globs.iface, title,
                                   ADMapQgsLayers.NEW_LANE_EDGE_COLOR,
                                   ADMapQgsLayers.NEW_LANE_EDGE_WIDTH,
                                   ADMapQgsLayers.NEW_LANE_EDGE_MARKER_QCOLOR,
                                   [], self.layer_group_misc())
        self.layer[title] = layer
        self.layer_new_lane = layer

    def __remove_lane_from__(self, lane_id, layer_managers):
        "..."
        to_refresh = []
        for layer_manager in layer_managers:
            if layer_manager.is_on_layer(lane_id):
                layer_manager.remove_old_feature(lane_id)
                to_refresh.append(layer_manager)
        return to_refresh

    def refresh_layers(self, to_refresh):
        "..."
        for layer_manager in list(set(to_refresh)):
            layer_manager.refresh()

    def update_landmark_layers(self, landmark_id):
        "..."
        to_refresh = []
        landmark = ad.map.landmark.getLandmark(landmark_id)
        for layer_name in layer_managers_landmark:
            layer = self.layer[layer_name]
            manager = self.layer_managers[layer_name]
            manager.add(landmark)
            to_refresh.append(layer)
        return to_refresh

    def update_lane_layers(self, lane_id):
        "..."
        to_refresh = []
        to_refresh += self.update_lane_main_layers(lane_id)
        to_refresh += self.update_lane_surface_layers(lane_id)
        to_refresh += self.update_lane_speed_layers(lane_id)
        to_refresh += self.update_lane_topo_layers(lane_id)
        to_refresh += self.update_lane_other_layers(lane_id)
        return to_refresh

    def update_lane_on_layers(self, lane_id, layer_names):
        "..."
        to_refresh = []
        lane = ad.map.lane.getLane(lane_id)
        for layer_name in layer_names:
            layer = self.layer[layer_name]
            manager = self.layer_managers[layer_name]
            manager.add(lane)
            to_refresh.append(layer)
        return to_refresh

    def update_lane_main_layers(self, lane_id):
        "..."
        layer_names = [self.LANE_EDGE, self.LANE_DIRECTION, self.LANE_ORIENTATION]
        return self.update_lane_on_layers(lane_id, layer_names)

    def update_lane_topo_layers(self, lane_id, remove_only=False):
        "..."
        to_refresh = []
        for layer_manager in self.layer_managers_topology:
            if remove_only:
                layer_manager.remove(lane_id)
            else:
                layer_manager.readd(lane_id)
            to_refresh.append(layer_manager)
        return to_refresh

    def update_lane_speed_layers(self, lane_id):
        "..."
        lane = ad.map.lane.getLane(lane_id)
        to_refresh = self.__remove_lane_from__(lane_id, self.layer_managers_speed)
        if "SpeedLimit" in lane.keys():
            for speed_limit in lane.speedLimits:
                limit = speed_limit.speedLimit
                layer_manager = self.speed_layer_manager(limit)
                layer_manager.add_speed_limit(lane, speed_limit)
                to_refresh.append(layer_manager)
        return to_refresh

    def update_lane_surface_layers(self, lane_id):
        "..."
        lane = ad.map.lane.getLane(lane_id)
        to_refresh = self.__remove_lane_from__(lane_id, self.layer_managers_surface)
        typ = lane.type
        hov = ad.map.lane.getHOV() > 1
        layer_manager_name = self.lane_surface_layer_name(typ, hov)
        layer_manager = self.layer_managers[layer_manager_name]
        layer_manager.add(lane)
        to_refresh.append(layer_manager)
        return to_refresh

    def update_lane_other_layers(self, lane_id):
        "..."
        to_refresh = []
        for layer_manager_name in self.layer_managers:
            layer_manager = self.layer_managers[layer_manager_name]
            if not layer_manager in self.layer_managers_speed:
                if not layer_manager in self.layer_managers_surface:
                    if layer_manager.is_on_layer(lane_id):
                        lane = ad.map.lane.getLane(lane_id)
                        layer_manager.add(lane)
                        to_refresh.append(layer_manager)
        return to_refresh

    def lane_types(self):
        "..."
        lane_types = list(self.LANE_SURFACE_COLOR.keys())
        lane_types.sort()
        lane_types.reverse()
        return lane_types

    def lane_speeds(self):
        "..."
        lane_speeds = list(self.LANE_SPEED_COLOR.keys())
        lane_speeds.sort()
        lane_speeds.reverse()
        return lane_speeds

    def lane_speed_layers(self):
        "..."
        layers = []
        lane_speeds = self.lane_speeds()
        for lane_speed in lane_speeds:
            layer = self.layer[lane_speed]
            layers.append(layer)
        return layers

    def lane_surface_layer_name(self, typ, hov):
        "..."
        if typ not in self.lane_types():
            title = "OTHER"
        else:
            title = typ
        return title

    def speed_layer_manager(self, mpers):
        "..."
        mph = mpers * 2.23694
        index = "Set"
        if mph < 0.5:
            index = "Not set"
        return self.layer_managers[index]

    def layer_group_misc(self):
        "..."
        return self.layer_groups[self.MISC]
