// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2022 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include "ad/map/lane/Types.hpp"
#include "ad/map/point/ECEFOperation.hpp"
#include "ad/map/point/ENUOperation.hpp"
#include "ad/map/point/GeoOperation.hpp"
#include "ad/map/point/HeadingOperation.hpp"
#include "ad/map/point/Transform.hpp"

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace lane */
namespace lane {

/**
 * @brief lateral_alignment constant for the left edge
 */
const physics::ParametricValue cLateralAlignmentLeft{1.};

/**
 * @brief lateral_alignment constant for the right edge
 */
const physics::ParametricValue cLateralAlignmentRight{0.};

/**
 * @brief lateral_alignment constant for the center between left and right edge
 */
const physics::ParametricValue cLateralAlignmentCenter{0.5};

/**
 * @brief Get the ENUEdge between the given border with corresponding lateral_alignment
 *
 * @param[in] border the ENU border, the edge is calculated from
 * @param[in] lateral_alignment the lateral alignment as TParam [0.;1.] used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateral_alignment is 1., the left edge is returned (see also
 * \a cLateralAlignmentLeftEdge),
 *   if lateral_alignment is 0., the right edge is returned (see also \a cLateralAlignmentRightEdge)
 *
 * @throws std::invalid_argument if the lateral_alignment parameter is smaller than 0. or larger than 1.
 */
ENUEdge getLateralAlignmentEdge(ENUBorder const &border, physics::ParametricValue const lateral_alignment);

/**
 * @brief Get the ENUEdge between the given border with corresponding lateral_alignment
 *
 * @param[in] border the ENU border, the edge is calculated from
 * @param[in] lateral_alignment the lateral alignment as RatioValue used to calculate the resulting edge.
 *   The lateral alignment is relative to the left edge. If lateral_alignment is 1., the left edge is returned (see also
 * \a cLateralAlignmentLeftEdge),
 *   if lateral_alignment is 0., the right edge is returned (see also \a cLateralAlignmentRightEdge)
 *   If lateral_alignment is smaller than 0. or larger than 1., the egde is actually outside of the border
 */
ENUEdge getLateralAlignmentEdge(ENUBorder const &border, physics::RatioValue const lateral_alignment);

/**
 * @brief Get the distance between an ENU point and the lateral alignment edge
 *
 * @param[in] enuPoint is the point for which the distance should be calculated
 * @param[in] lateralAlignmentEdge the lateral alignment in ENU form
 *
 * @return calculated Distance
 */
physics::Distance getDistanceEnuPointToLateralAlignmentEdge(point::ENUPoint const &enuPoint,
                                                            ENUEdge const &lateralAlignmentEdge);

/**
 * @brief normalizes the border
 *
 * At first the left and right edges of the border are checked for irregular directional vectors
 * (scalarproduct of the vectors of three consecutive edge points has to be positive)
 * Irregular points are dropped.
 *
 * Then, the number of points of the left and right edge of the border are made equal by extending the smaller edge.
 * If an edge has less than 2 points, nothing is done.
 *
 * The previousBorder (optional parameter) is used to extend the irregular directional vector check to the beginning
 * of the border edges; here leading to an potential overwrite of the first edge point by the end of the previousBorder.
 */
void normalizeBorder(ENUBorder &border, ENUBorder const *previousBorder = nullptr);

/**
 * @brief operation to make the transition between two edges continuous
 *
 * If the end point of \c first is near (<=0.1m) to the end point of \c second or one of the edges has less than two
 * points, nothing is done.
 * Otherwise the first point of the second edge will exchanged by the last point of the first edge.
 * The second point of the second edge is placed at some distance along the edge which is calculated using:
 * - the distance of the displacement of the two edges
 * - the direction of the displacement of the two edges compared to the the corresponding direction of the edges
 *
 * @param[in] first the first edge (is untouched by the algorithm)
 * @param[in] second the second edge to be adapted if required to make the transition continuous
 */
void makeTransitionToSecondEdgeContinuous(ENUEdge const &first, ENUEdge &second);

/**
 * @brief operation to make the transition between two borders continuous
 *
 * This executes the makeTransitionToSecondEdgeContinuous() for left and right edges.
 * In addition, adds interpolation points to the respective other edge if required.
 *
 * @param[in] first the first border (is untouched by the algorithm)
 * @param[in] second the second border to be adapted if required to make the transition continuous
 */
void makeTransitionToSecondBorderContinuous(ENUBorder const &first, ENUBorder &second);

/**
 * @brief operation to make the transition between two edges continuous
 *
 * If the end point of \c first is near (<=0.1m) to the end point of \c second or one of the edges has less than two
 * points, nothing is done.
 * Otherwise the first point of the second edge will exchanged by the last point of the first edge.
 * The second point of the second edge is placed at some distance along the edge which is calculated using:
 * - the distance of the displacement of the two edges
 * - the direction of the displacement of the two edges compared to the the corresponding direction of the edges
 *
 * @param[in] first the first edge to be adapted if required to make the transition continuous
 * @param[in] second the second edge (is untouched by the algorithm)
 */
void makeTransitionFromFirstEdgeContinuous(ENUEdge &first, ENUEdge const &second);

/**
 * @brief operation to make the transition between two borders continuous
 *
 * This executes the makeTransitionToSecondEdgeContinuous() for left and right edges.
 * In addition, adds interpolation points to the respective other edge if required.
 *
 * @param[in] first the first border to be adapted if required to make the transition continuous
 * @param[in] second the second border (is untouched by the algorithm)
 */
void makeTransitionFromFirstBorderContinuous(ENUBorder &first, ENUBorder const &second);

/** @brief calculate the length of the provided edge as distance value
 *
 * Length calculation is performed within Cartesian ENU coordinate frame.
 */
physics::Distance calcLength(ENUEdge const &edge);

/** @brief calculate the length of the provided border as distance value
 *
 * Length calculation is performed within Cartesian ECEF coordinate frame.
 */
physics::Distance calcLength(ECEFEdge const &edge);

/** @brief calculate the length of the provided border as distance value
 *
 * Length calculation is performed within Cartesian ECEF coordinate frame.
 */
physics::Distance calcLength(GeoEdge const &edge);

/** @brief calculate the length of the provided border as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within Cartesian ENU coordinate frame.
 */
physics::Distance calcLength(ENUBorder const &border);

/** @brief calculate the length of the provided border as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within Cartesian ECEF coordinate frame.
 */
physics::Distance calcLength(ECEFBorder const &border);

/** @brief calculate the length of the provided border as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within Cartesian ECEF coordinate frame.
 */
physics::Distance calcLength(GeoBorder const &border);

/** @brief calculate the length out of the provided ENU border List as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within Cartesian ENU coordinate frame.
 */
physics::Distance calcLength(ENUBorderList const &borderList);

/** @brief calculate the length out of the provided ECEF border List as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within Cartesian ECEF coordinate frame.
 */
physics::Distance calcLength(ECEFBorderList const &borderList);

/** @brief calculate the length out of the provided GEO border List as distance value
 *
 * For length calculation the average between left and right edge of the border is returned.
 * Length calculation is performed within GEO coordinate frame.
 */
physics::Distance calcLength(GeoBorderList const &borderList);

/** @brief calculate the ENUHeading of the vector<ENUBorder> at the given ENUPoint
 *
 * @param[in] borderList the border list to search within
 * @param[in] enuPoint the enuPoint to search
 * @param[in] toleranceDistanceOutsideBorder allow a certain tolerance distance for the ENUPoint
     to be allowed directly in front of the borders and directly after the borders. This can be
     used if the enuPoint belongs to an object center that is directly standing in front/after the border,
     but only touching with the front/back and the center beeing outside
 *
 *  If the given ENUPoint is not within the given borders,
 *  an ENUHeading(2*M_PI) is returned.
 */
point::ENUHeading getENUHeading(ENUBorderList const &borderList,
                                point::ENUPoint const &enuPoint,
                                physics::Distance const &toleranceDistanceOutsideBorder = physics::Distance(0.01));

/**
 * @brief perform coordinate transformation from ECEFEdge to GeoEdge
 */
inline GeoEdge toGeo(ECEFEdge const &edge)
{
  GeoEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toGeo(edge.points);
  return resultEdge;
}

/**
 * @brief perform coordinate transformation from ENUEdge to GeoEdge
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline GeoEdge toGeo(ENUEdge const &edge)
{
  GeoEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toGeo(edge.points);
  return resultEdge;
}

/**
 * @brief perform coordinate transformation from ECEFEdge to ENUEdge
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUEdge toENU(ECEFEdge const &edge)
{
  ENUEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toENU(edge.points);
  return resultEdge;
}

/**
 * @brief perform coordinate transformation from GeoEdge to ENUEdge
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ENUEdge toENU(GeoEdge const &edge)
{
  ENUEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toENU(edge.points);
  return resultEdge;
}

/**
 * @brief perform coordinate transformation from GeoEdge to ECEFEdge
 */
inline ECEFEdge toECEF(GeoEdge const &edge)
{
  ECEFEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toECEF(edge.points);
  return resultEdge;
}

/**
 * @brief perform coordinate transformation from ENUEdge to ECEFEdge
 *
 * The transformation into ENU coordinate frame makes use of the globally set ENUReferencePoint
 * (see AdMapAccess::setENUReferencePoint())
 */
inline ECEFEdge toECEF(ENUEdge const &edge)
{
  ECEFEdge resultEdge;
  resultEdge.edge_type = edge.edge_type;
  resultEdge.lateral_alignment = edge.lateral_alignment;
  resultEdge.points = toECEF(edge.points);
  return resultEdge;
}
} // namespace lane
} // namespace map
} // namespace ad
