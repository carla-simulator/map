// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include <ad_map_access/Version.hpp>
#include <string>
#include "core_python.h"

PyObject *Open(PyObject *self, PyObject *args);
PyObject *Close(PyObject *self, PyObject *args);
PyObject *GetMetaData(PyObject *self, PyObject *args);
PyObject *GetPartitions(PyObject *self, PyObject *args);
PyObject *GetLaneIds(PyObject *self, PyObject *args);
PyObject *GetLane(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeLeft(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeRight(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeLeft(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeRight(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeLeftECEF(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeRightECEF(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeLeftECEF(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeRightECEF(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeLeftENU(PyObject *self, PyObject *args);
PyObject *GetLaneEdgeRightENU(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeLeftENU(PyObject *self, PyObject *args);
PyObject *GetLaneSubEdgeRightENU(PyObject *self, PyObject *args);
PyObject *GetLaneParamPoint(PyObject *self, PyObject *args);
PyObject *GetGeoDistance(PyObject *self, PyObject *args);
PyObject *FindLanes(PyObject *self, PyObject *args);
PyObject *GetLandmarkIds(PyObject *self, PyObject *args);
PyObject *GetLandmark(PyObject *self, PyObject *args);
PyObject *GetLandmarkPosition(PyObject *self, PyObject *args);
PyObject *GetLandmarkPositionECEF(PyObject *self, PyObject *args);
PyObject *GetLandmarkPositionENU(PyObject *self, PyObject *args);
PyObject *GetLandmarkOrientationAngle(PyObject *self, PyObject *args);
PyObject *Route(PyObject *self, PyObject *args);
PyObject *Predictions(PyObject *self, PyObject *args);
PyObject *MakeIntersectionLane(PyObject *self, PyObject *args);
PyObject *SetENURefPoint(PyObject *self, PyObject *args);
PyObject *SetLaneDirection(PyObject * /*self*/, PyObject *args);
PyObject *SetLaneType(PyObject * /*self*/, PyObject *args);
PyObject *SetLaneSpeedLimit(PyObject * /*self*/, PyObject *args);
PyObject *SetLaneComplianceVer(PyObject * /*self*/, PyObject *args);
PyObject *DeleteLane(PyObject * /*self*/, PyObject *py_lane_id);
PyObject *DeleteContacts(PyObject * /*self*/, PyObject *args);
PyObject *AddContact(PyObject * /*self*/, PyObject *args);
PyObject *AddLane(PyObject * /*self*/, PyObject *args);
PyObject *RemovePartition(PyObject * /*self*/, PyObject *args);

////////////////////
// adg::Log wrappers
extern PyObject *LogDebug(PyObject *self, PyObject *args);
extern PyObject *LogInfo(PyObject *self, PyObject *args);
extern PyObject *LogWarning(PyObject *self, PyObject *args);
extern PyObject *LogError(PyObject *self, PyObject *args);
extern PyObject *LogInternalError(PyObject *self, PyObject *args);
extern PyObject *LogLevel(PyObject *self, PyObject *args);
extern PyObject *LogFileName(PyObject *self, PyObject *args);

/////////////////
// Initialization

static PyMethodDef s_ad_map_access_python_methods[]
  = {{"Open",
      Open,
      METH_O,
      "Open(<string>)\n"
      "   Opens/Loads the AD Map Database.\n"
      "   Returns Bool indicating success or failure.\n"
      "\n"
      "  - param: Configuration string for the AD Map Database.\n"
      "           Currently -- The name of the file.\n"
      "                        First number in the file name is considered to be Tile Identifer."},
     {"Close",
      Close,
      METH_NOARGS,
      "Close()\n"
      "   Closes the AD Map Database."},
     {"GetMetaData",
      GetMetaData,
      METH_NOARGS,
      "GetMetaData()\n"
      "   Returns the meta data of the map in the store."},
     {"GetPartitions",
      GetPartitions,
      METH_NOARGS,
      "GetPartitions()\n"
      "   Returns list of partitions currently in the store."},
     {"GetLaneIds",
      GetLaneIds,
      METH_VARARGS,
      "GetLaneIds([<part-id>,] [<type-filter>,] [<hov-filter>]])\n"
      "\n"
      "   - part-id:     Partition identifier,\n"
      "   - type-filter: String containing types of lanes to be returned,\n"
      "   - hov-filter:  Minimum number of passengers on the lane,\n"
      "   Returns list of lane identifiers (integers)."},
     {"RemovePartition",
      RemovePartition,
      METH_O,
      "RemovePartition(<part-id>)\n"
      "\n"
      "   - part-id: Partition identifier,\n"},
     {"GetLane",
      GetLane,
      METH_O,
      "GetLane(<lane-id>)\n"
      "   Returns all Lane infomation except edges.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneEdgeRight",
      GetLaneEdgeRight,
      METH_O,
      "GetLaneEdgeRight(<lane-id>)\n"
      "   Returns Right Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeRight",
      GetLaneSubEdgeRight,
      METH_VARARGS,
      "GetLaneSubEdgeRight(<lane-id>, <t-start>, <t-end>)\n"
      "   Returns Part of the lane right edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneEdgeLeft",
      GetLaneEdgeLeft,
      METH_O,
      "GetLaneEdgeLeft(<lane-id>)\n"
      "   Returns Left Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeLeft",
      GetLaneSubEdgeLeft,
      METH_VARARGS,
      "GetLaneSubEdgeLeft(<lane-id>)\n"
      "   Returns Part of the lane left edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneEdgeRightECEF",
      GetLaneEdgeRightECEF,
      METH_O,
      "GetLaneEdgeRightECEF(<lane-id>)\n"
      "   Returns Right Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeRightECEF",
      GetLaneSubEdgeRightECEF,
      METH_VARARGS,
      "GetLaneSubEdgeRightECEF(<lane-id>, <t-start>, <t-end>)\n"
      "   Returns Part of the lane right edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneEdgeLeftECEF",
      GetLaneEdgeLeftECEF,
      METH_O,
      "GetLaneEdgeLeftECEF(<lane-id>)\n"
      "   Returns Left Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeLeftECEF",
      GetLaneSubEdgeLeftECEF,
      METH_VARARGS,
      "GetLaneSubEdgeLeftECEF(<lane-id>)\n"
      "   Returns Part of the lane left edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneEdgeRightENU",
      GetLaneEdgeRightENU,
      METH_O,
      "GetLaneEdgeRightENU(<lane-id>)\n"
      "   Returns Right Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeRightENU",
      GetLaneSubEdgeRightENU,
      METH_VARARGS,
      "GetLaneSubEdgeRightENU(<lane-id>, <t-start>, <t-end>)\n"
      "   Returns Part of the lane right edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneEdgeLeftENU",
      GetLaneEdgeLeftENU,
      METH_O,
      "GetLaneEdgeLeftENU(<lane-id>)\n"
      "   Returns Left Edge of the Lane.\n"
      "\n"
      " - param: Lane identifier."},
     {"GetLaneSubEdgeLeftENU",
      GetLaneSubEdgeLeftENU,
      METH_VARARGS,
      "GetLaneSubEdgeLeftENU(<lane-id>)\n"
      "   Returns Part of the lane left edge.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - t-start: Parameteric start of the sub-edge.\n"
      " - t-end:   Parametric end of the sub-edge."},
     {"GetLaneParamPoint",
      GetLaneParamPoint,
      METH_VARARGS,
      "GetLane(<lane-id>, <lon-t>, <lat-t>)\n"
      "   Returns all Lane infomation except edges.\n"
      "\n"
      " - lane-id: Lane identifier.\n"
      " - lon-t:   Longitude parameter, between 0.0 and 1.0.\n"
      " - lat-t:   Latitude parameter, between 0.0 and 1.0.\n"
      "\n"
      "   Returns (lon, lat, alt) touple."},

     {"GetGeoDistance",
      GetGeoDistance,
      METH_VARARGS,
      "GetGeoDistance((<lon>, <lat>, [<alt>]), (<lon>, <lat>, [<alt>]))\n"
      "   Returns distance in meters between two points.\n"},

     {"FindLanes",
      FindLanes,
      METH_VARARGS,
      "FindLanes((<lon>, <lat>, [<alt>]), <distance>))\n"
      "   Returns lanes that are less than <distance> from given position.\n"},

     {"GetLandmarkIds",
      GetLandmarkIds,
      METH_VARARGS,
      "GetLandmarkIds([<part-id>])\n"
      "\n"
      "   - part-id:     Partition identifier,\n"
      "   Returns list of landmark identifiers (integers)."},
     {"GetLandmark",
      GetLandmark,
      METH_O,
      "GetLandmark(<landmark-id>)\n"
      "   Returns all Landmark infomation.\n"
      "\n"
      " - param: Landmark identifier."},
     {"GetLandmarkPosition",
      GetLandmarkPosition,
      METH_O,
      "GetLandmarkPosition(<landmark-id>)\n"
      "   Returns Position of the Landmark.\n"
      "\n"
      " - param: Landmark identifier."},
     {"GetLandmarkPositionECEF",
      GetLandmarkPositionECEF,
      METH_O,
      "GetLandmarkPosition(<landmark-id>)\n"
      "   Returns Position of the Landmark.\n"
      "\n"
      " - param: Landmark identifier."},
     {"GetLandmarkPositionENU",
      GetLandmarkPositionENU,
      METH_O,
      "GetLandmarkPosition(<landmark-id>)\n"
      "   Returns Position of the Landmark.\n"
      "\n"
      " - param: Landmark identifier."},
     {"GetLandmarkOrientationAngle",
      GetLandmarkOrientationAngle,
      METH_O,
      "GetLandmarkOrientationAngle(<landmark-id>)\n"
      "   Returns Orientation of the Landmark as angle w.r.t ENU.\n"
      "\n"
      " - param: Landmark identifier."},
     {"Route",
      Route,
      METH_VARARGS,
      "Route((<lon>, <lat>, <alt>), (<lon>, <lat>, <alt>))\n"
      "   Returns route between two points."},
     {"Predictions",
      Predictions,
      METH_VARARGS,
      "Predictions((<lon>, <lat>, <alt>))\n"
      "   Returns predictions starting from points."},

     {"MakeIntersectionLane",
      MakeIntersectionLane,
      METH_VARARGS,
      "MakeIntersectionLane(lane_id_1, lane_id_2, bool)\n"
      "   Creates intersection lane between two lanes.\n"
      "   If last parameter is True, new lane will be straight.\n"
      "   If last parameter is False, it will be created using Bezier curve.\n"
      "   Returns identifier of new lane, or None if not successful."},

     {"SetENURefPoint",
      SetENURefPoint,
      METH_O,
      "SetENURefPoint((<lon>, <lat>, <alt>))\n"
      "   Sets the reference point for ENU coordinate system.\n"
      "   Returns true if successful.\n"},

     {"SetLaneDirection",
      SetLaneDirection,
      METH_VARARGS,
      "SetLaneDirection(<lane-id>, <string>)\n"
      "   Sets the driving direction along the lane.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - param: 'UNKNOWN', 'POSITIVE', 'NEGATIVE', 'REVERSABLE', 'BIDIRECTIONAL', 'NONE'.\n"
      "\n"
      "returns True if successful, false if not."},
     {"SetLaneType",
      SetLaneType,
      METH_VARARGS,
      "SetLaneType(<lane-id>, <string>)\n"
      "   Sets the type of the lane.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - param: 'UNKNOWN', 'NORMAL', 'INTERSECTION', 'SHOULDER', 'EMERGENCY', 'MULTI',\n"
      "          'PEDESTRIAN', 'OVERTAKING', 'TURN', 'BIKE'.\n"
      "\n"
      "returns True if successful, false if not."},
     {"SetLaneComplianceVer",
      SetLaneComplianceVer,
      METH_VARARGS,
      "SetLaneComplianceVer(<lane-id>, <unsigned-int>)\n"
      "   Sets the type of the lane.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - param: Compliance version as unsigned integer.\n"
      "\n"
      "returns True if successful, false if not."},
     {"SetLaneSpeedLimit",
      SetLaneSpeedLimit,
      METH_VARARGS,
      "SetLaneSpeedLimit(<lane-id>, <double>)\n"
      "   Sets the type of the lane.\n"
      "\n"
      " - param: Lane identifier.\n"
      " - param: Speed Limit in meters-per-second.\n"
      "\n"
      "returns True if successful, false if not."},
     {"DeleteLane",
      DeleteLane,
      METH_O,
      "DeleteLane(<lane-id>)\n"
      "   Deletes lane with specified identifier.\n"
      "\n"
      " - param: Lane identifier."
      "\n"
      "returns True if successful."},
     {"DeleteContacts",
      DeleteContacts,
      METH_VARARGS,
      "DeleteContacts(<from-lane-id>, <to-lane-id>)\n"
      "   Deletes all contacts from one lane to another.\n"
      "\n"
      " - param: From-Lane identifier.\n"
      " - param: To-Lane identifier.\n"
      "\n"
      "returns True if successful."},
     {"AddContact",
      AddContact,
      METH_VARARGS,
      "AddContact(<from-lane-id>, <to-lane-id>, <string>)\n"
      "   Add FREE contact from one lane to another.\n"
      "\n"
      " - param: From-Lane identifier.\n"
      " - param: To-Lane identifier.\n"
      " - param: 'LEFT', 'RIGHT', 'SUCCESSOR', 'PREDECESSOR', 'OVERLAP'\n"
      "\n"
      "returns True if successful."},
     {"AddLane",
      AddLane,
      METH_VARARGS,
      "AddLane((<lon>, <lat> [, <alt>]), ...], (<lon>, <lat> [, <alt>]), ...])\n"
      "   Adds new lane to the database. Lane will be NORMAL and in POSITIVE driving direction.\n"
      "\n"
      " - param: Edge: List of <lon>, <lat> pairs (altitude is optional).\n"
      " - param: Edge: List of <lon>, <lat> pairs (altitude is optional).\n"
      "\n"
      "returns LAne Identifier if successful, None if not."},

     {"LogDebug",
      LogDebug,
      METH_O,
      "LogDebug(<string>)\n"
      "  Logs debug message."},
     {"LogInfo",
      LogInfo,
      METH_O,
      "LogInfo(<string>)\n"
      "  Logs information message."},
     {"LogWarning",
      LogWarning,
      METH_O,
      "LogWarning(<string>)\n"
      "  Logs warning message."},
     {"LogError",
      LogError,
      METH_O,
      "LogError(<string>)\n"
      "  Logs error message."},
     {"LogInternalError",
      LogInternalError,
      METH_O,
      "LogInternalError(<string>)\n"
      "  Logs internal error message."},
     {"SetLogLevel",
      LogLevel,
      METH_O,
      "SetLogLevel(<int>)\n"
      "  Sets the logging level. Messages that are above specified level are ignored.\n"
      "  Levels are: 0: none, 1: errors, 2: warnings, 3: infos, 4: debug."},
     {"GetLogFileName",
      LogFileName,
      METH_NOARGS,
      "GetLogFileName()\n"
      "  Returns name of the log file."},
     {nullptr, nullptr, 0, nullptr}};

///////////////////////////////
// Python Module Initialization

PyMODINIT_FUNC initad_map_access_python(void)
{
  std::string desc("Intel ad_map_access for Python.\n");
  desc += std::string("Version ") + AD_MAP_ACCESS_VERSION_STRING + "\n";
  desc += std::string("Copyright (c) 2017-2020 Intel Corp.");
  Py_InitModule3("ad_map_access_python", s_ad_map_access_python_methods, desc.c_str());
}
