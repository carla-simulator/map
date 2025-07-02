#!/bin/bash
##
# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2018-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------
##
##
# Generated file
#
# Generator Version : 0.0.0
##

#--------------------
# Renaming of data types members from CamelCase -> underscore_case
#--------------------
#
# defines a function to perform a sed call recursively until the file doesn't change any more
#
function call_sed_inplace
{
  INFILE=$1
  BACKUPFILE="${1}.bak"
  if [ "x$3" == "x" ]; then
    SED_COMMAND="sed --in-place=.bak -r '/$2/d'"
  elif [ "x$3" == "xN" ]; then
    SED_COMMAND="sed --in-place=.bak -r 'N;/$2/d'"
  elif [ "x$3" == "xNN" ]; then
    SED_COMMAND="sed --in-place=.bak -r 'N;N;/$2/d'"
  elif [ "x$3" == "xNNN" ]; then
    SED_COMMAND="sed --in-place=.bak -r 'N;N;N;/$2/d'"
  else
    SED_COMMAND="sed --in-place=.bak -r 's/$2/$3/g'"
  fi
  #echo "Execute(${SED_COMMAND}) ..."
  SOMETHING_DONE=1
  ANYTHING_DONE=0
  while (( SOMETHING_DONE )); do
    if [ -e $BACKUPFILE ]; then
      rm ${BACKUPFILE}
    fi
    eval ${SED_COMMAND} ${INFILE}
    DIFF=`diff ${BACKUPFILE} ${INFILE}`
    if [ "x$DIFF" == "x" ]; then
      SOMETHING_DONE=0
    else
      ANYTHING_DONE=1
    fi
    if [ "x$4" == "xONCE" ]; then
      SOMETHING_DONE=0
    fi
  done
  if [ -e $BACKUPFILE ]; then
    rm ${BACKUPFILE}
  fi
  #echo "Done."
  return ${ANYTHING_DONE}
}

function convert_camel_case_to_underscore
{
  FILE=$1
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routeA([^a-zA-Z0-9(]+|$)" "\1route_a\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routeB([^a-zA-Z0-9(]+|$)" "\1route_b\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)toLane([^a-zA-Z0-9(]+|$)" "\1to_lane\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)landmarkId([^a-zA-Z0-9(]+|$)" "\1landmark_id\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)edgeType([^a-zA-Z0-9(]+|$)" "\1edge_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lateralAlignment([^a-zA-Z0-9(]+|$)" "\1lateral_alignment\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lateralAlignment([^a-zA-Z0-9(]+|$)" "\1lateral_alignment\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)edgeType([^a-zA-Z0-9(]+|$)" "\1edge_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)trafficLightType([^a-zA-Z0-9(]+|$)" "\1traffic_light_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)centerPoint([^a-zA-Z0-9(]+|$)" "\1center_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)enuReferencePoint([^a-zA-Z0-9(]+|$)" "\1enu_reference_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)enuPoints([^a-zA-Z0-9(]+|$)" "\1enu_points\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)enuVersion([^a-zA-Z0-9(]+|$)" "\1enu_version\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)roadSegments([^a-zA-Z0-9(]+|$)" "\1road_segments\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routePlanningCounter([^a-zA-Z0-9(]+|$)" "\1route_planning_counter\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)fullRouteSegmentCount([^a-zA-Z0-9(]+|$)" "\1full_route_segment_count\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)destinationLaneOffset([^a-zA-Z0-9(]+|$)" "\1destination_lane_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)minLaneOffset([^a-zA-Z0-9(]+|$)" "\1min_lane_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)maxLaneOffset([^a-zA-Z0-9(]+|$)" "\1max_lane_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routeCreationMode([^a-zA-Z0-9(]+|$)" "\1route_creation_mode\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lateralAlignment([^a-zA-Z0-9(]+|$)" "\1lateral_alignment\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)edgeType([^a-zA-Z0-9(]+|$)" "\1edge_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)isValid([^a-zA-Z0-9(]+|$)" "\1is_valid\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)isClosed([^a-zA-Z0-9(]+|$)" "\1is_closed\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)ecefPoints([^a-zA-Z0-9(]+|$)" "\1ecef_points\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)private_enuPointsCache([^a-zA-Z0-9(]+|$)" "\1private_enu_points_cache\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)leftEdgeOffset([^a-zA-Z0-9(]+|$)" "\1left_edge_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)rightEdgeOffset([^a-zA-Z0-9(]+|$)" "\1right_edge_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)leftEdgePoints([^a-zA-Z0-9(]+|$)" "\1left_edge_points\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)rightEdgePoints([^a-zA-Z0-9(]+|$)" "\1right_edge_points\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)boundingBox([^a-zA-Z0-9(]+|$)" "\1bounding_box\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)supplementaryText([^a-zA-Z0-9(]+|$)" "\1supplementary_text\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)trafficLightType([^a-zA-Z0-9(]+|$)" "\1traffic_light_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)trafficSignType([^a-zA-Z0-9(]+|$)" "\1traffic_sign_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lengthRange([^a-zA-Z0-9(]+|$)" "\1length_range\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)widthRange([^a-zA-Z0-9(]+|$)" "\1width_range\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)speedLimits([^a-zA-Z0-9(]+|$)" "\1speed_limits\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)edgeLeft([^a-zA-Z0-9(]+|$)" "\1edge_left\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)edgeRight([^a-zA-Z0-9(]+|$)" "\1edge_right\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)contactLanes([^a-zA-Z0-9(]+|$)" "\1contact_lanes\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)complianceVersion([^a-zA-Z0-9(]+|$)" "\1compliance_version\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)boundingSphere([^a-zA-Z0-9(]+|$)" "\1bounding_sphere\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)visibleLandmarks([^a-zA-Z0-9(]+|$)" "\1visible_landmarks\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneId([^a-zA-Z0-9(]+|$)" "\1lane_id\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)wrongWay([^a-zA-Z0-9(]+|$)" "\1wrong_way\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneId([^a-zA-Z0-9(]+|$)" "\1lane_id\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)longitudinalRange([^a-zA-Z0-9(]+|$)" "\1longitudinal_range\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lateralRange([^a-zA-Z0-9(]+|$)" "\1lateral_range\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)paraPoint([^a-zA-Z0-9(]+|$)" "\1para_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lateralT([^a-zA-Z0-9(]+|$)" "\1lateral_t\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneLength([^a-zA-Z0-9(]+|$)" "\1lane_length\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneWidth([^a-zA-Z0-9(]+|$)" "\1lane_width\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)leftNeighbor([^a-zA-Z0-9(]+|$)" "\1left_neighbor\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)rightNeighbor([^a-zA-Z0-9(]+|$)" "\1right_neighbor\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneInterval([^a-zA-Z0-9(]+|$)" "\1lane_interval\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routeLaneOffset([^a-zA-Z0-9(]+|$)" "\1route_lane_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)openDriveOverlapMargin([^a-zA-Z0-9(]+|$)" "\1open_drive_overlap_margin\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)openDriveDefaultIntersectionType([^a-zA-Z0-9(]+|$)" "\1open_drive_default_intersection_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)openDriveDefaultTrafficLightType([^a-zA-Z0-9(]+|$)" "\1open_drive_default_traffic_light_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneOccupiedRegions([^a-zA-Z0-9(]+|$)" "\1lane_occupied_regions\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)referencePointPositions([^a-zA-Z0-9(]+|$)" "\1reference_point_positions\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)samplingDistance([^a-zA-Z0-9(]+|$)" "\1sampling_distance\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)matchRadius([^a-zA-Z0-9(]+|$)" "\1match_radius\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lanePoint([^a-zA-Z0-9(]+|$)" "\1lane_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)matchedPoint([^a-zA-Z0-9(]+|$)" "\1matched_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)queryPoint([^a-zA-Z0-9(]+|$)" "\1query_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)matchedPointDistance([^a-zA-Z0-9(]+|$)" "\1matched_point_distance\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)trafficType([^a-zA-Z0-9(]+|$)" "\1traffic_type\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)enuPosition([^a-zA-Z0-9(]+|$)" "\1enu_position\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)mapMatchedBoundingBox([^a-zA-Z0-9(]+|$)" "\1map_matched_bounding_box\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)laneId([^a-zA-Z0-9(]+|$)" "\1lane_id\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)parametricOffset([^a-zA-Z0-9(]+|$)" "\1parametric_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)geoPoint([^a-zA-Z0-9(]+|$)" "\1geo_point\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)roadUserTypes([^a-zA-Z0-9(]+|$)" "\1road_user_types\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)passengersMin([^a-zA-Z0-9(]+|$)" "\1passengers_min\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)drivableLaneSegments([^a-zA-Z0-9(]+|$)" "\1drivable_lane_segments\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)segmentCountFromDestination([^a-zA-Z0-9(]+|$)" "\1segment_count_from_destination\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)boundingSphere([^a-zA-Z0-9(]+|$)" "\1bounding_sphere\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)routePlanningCounter([^a-zA-Z0-9(]+|$)" "\1route_planning_counter\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)segmentCountFromDestination([^a-zA-Z0-9(]+|$)" "\1segment_count_from_destination\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)parametricOffset([^a-zA-Z0-9(]+|$)" "\1parametric_offset\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)speedLimit([^a-zA-Z0-9(]+|$)" "\1speed_limit\2"
  call_sed_inplace ${FILE} "([^a-zA-Z0-9]+|^)lanePiece([^a-zA-Z0-9(]+|$)" "\1lane_piece\2"
}

for FILE in $@; do
  if [ -f $FILE ]; then
    convert_camel_case_to_underscore $FILE
  fi
done
