/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
 * de Barcelona (UAB).
 * Copyright (C) 2019-2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

#pragma once

#include <cmath>
#include <limits>
#include <map>
#include <memory>
#include <set>
#include <spdlog/spdlog.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace opendrive {

enum class GeometryType : unsigned int
{
  NONE,
  ARC,
  LINE,
  SPIRAL,
  POLY3,
  PARAMPOLY3
};

enum class LaneType : std::uint8_t
{
  None,
  Driving,
  Stop,
  Shoulder,
  Biking,
  Sidewalk,
  Border,
  Restricted,
  Parking,
  Bidirectional,
  Median,
  Special1,
  Special2,
  Special3,
  RoadWorks,
  Tram,
  Rail,
  Entry,
  Exit,
  OffRamp,
  OnRamp
};

enum class RoadType : std::uint8_t
{
  Unknown,
  Tural,
  Motorway,
  Town,
  LowSpeed,
  Pedestrian,
  Bicycle
};

enum class RoadmarkType : std::uint8_t
{
  None,
  Solid,
  Broken,
  SolidSolid,
  SolidBroken,
  BrokenSolid,
  BrokenBroken,
  BottsDots,
  Grass,
  Curb
};

enum class ElementType : std::uint8_t
{
  Invalid,
  Junction,
  Road
};

enum class ContactPoint : std::uint8_t
{
  Invalid,
  Start,
  End
};

struct Point
{
  double x{0.};
  double y{0.};
  double z{0.};

  Point() = default;

  Point(double _x, double _y, double _z)
    : x(_x)
    , y(_y)
    , z(_z)
  {
  }

  static constexpr double cCoordinateTolerance = 1e-3;

  bool operator==(const Point &rhs) const
  {
    ensureValid();
    rhs.ensureValid();
    // Points are treated as equal when below 1 mm
    return (std::fabs(x - rhs.x) < cCoordinateTolerance) && (std::fabs(y - rhs.y) < cCoordinateTolerance)
      && (std::fabs(z - rhs.z) < cCoordinateTolerance);
  }
  bool operator!=(const Point &rhs) const
  {
    ensureValid();
    rhs.ensureValid();
    return !operator==(rhs);
  }
  double normSquared() const
  {
    ensureValid();
    return x * x + y * y + z * z;
  }

  double norm() const
  {
    ensureValid();
    return sqrt(normSquared());
  }

  double dot(const Point &other) const
  {
    ensureValid();
    other.ensureValid();
    return x * other.x + y * other.y + z * other.z;
  }

  void ensureValid() const
  {
    if (!isValid())
    {
      spdlog::error("ensureValid(Point)>> {},{},{} value out of range", x, y, z);
      throw std::out_of_range("Point value out of range");
    }
  }

  bool isValid() const
  {
    auto const valueClassX = std::fpclassify(x);
    auto const valueClassY = std::fpclassify(y);
    auto const valueClassZ = std::fpclassify(z);
    return ((valueClassX == FP_NORMAL) || (valueClassX == FP_ZERO))
      && ((valueClassY == FP_NORMAL) || (valueClassY == FP_ZERO))
      && ((valueClassZ == FP_NORMAL) || (valueClassZ == FP_ZERO));
  }
};

inline Point operator-(const Point &left, const Point &right)
{
  left.ensureValid();
  right.ensureValid();
  return Point(left.x - right.x, left.y - right.y, left.z - right.z);
}
inline Point operator+(const Point &left, const Point &right)
{
  left.ensureValid();
  right.ensureValid();
  return Point(left.x + right.x, left.y + right.y, left.z + right.z);
}
inline Point operator*(const double &scalar, const Point &point)
{
  point.ensureValid();
  return Point(scalar * point.x, scalar * point.y, scalar * point.z);
}

inline Point operator*(const Point &point, const double &scalar)
{
  point.ensureValid();
  return operator*(scalar, point);
}

struct GeometryAttributes
{
  GeometryType type{GeometryType::NONE}; // geometry type
  double length{0.};                     // length of the road section
                                         // [meters]

  double start_position{0.}; // s-offset [meters]
  double heading{0.};        // start orientation [radians]

  double start_position_x{0.}; // [meters]
  double start_position_y{0.}; // [meters]
  double start_position_z{0.};
};

struct GeometryAttributesArc : public GeometryAttributes
{
  double curvature{0.};
};

struct GeometryAttributesLine : public GeometryAttributes
{
  // Nothing else here
};

struct GeometryAttributesSpiral : public GeometryAttributes
{
  double curve_start{0.};
  double curve_end{0.};
};

struct GeometryAttributesPoly3 : public GeometryAttributes
{
  double a{0.};
  double b{0.};
  double c{0.};
  double d{0.};
};

struct GeometryAttributesParamPoly3 : public GeometryAttributes
{
  double aU{0.};
  double bU{0.};
  double cU{0.};
  double dU{0.};
  double aV{0.};
  double bV{0.};
  double cV{0.};
  double dV{0.};
  std::string p_range{"arcLength"};
};

/////////////////////////////////////////////////////////////////

struct LaneAttributes
{
  int id{-1};
  LaneType type{LaneType::None};
  bool level{false};
};

struct OffsetPoly3
{
  // f(s) = a + b*s + c*s*s + d*s*s*s
  double start_offset{0.}; // start position (s - start_offset)[meters]]
  double a{0.};            // a - polynomial value at start_offset=0
  double b{0.};            // b
  double c{0.};            // c
  double d{0.};            // d

  double eval(double const s);
  bool operator<(OffsetPoly3 const &other) const
  {
    return start_offset < other.start_offset;
  }
};

struct LaneWidth : public OffsetPoly3
{
};

typedef std::set<LaneWidth> LaneWidthSet;

struct LaneRoadMark
{
  double start_offset{0.};
  double width{0.};

  std::string type{""};
  std::string weigth{"standard"};

  // See OpenDRIVE Format Specification, Rev. 1.4
  // Doc No.: VI2014.107 (5.3.7.2.1.1.4 Road Mark Record)
  std::string material{"standard"};

  std::string color{"white"};
  std::string lane_change{"none"};
};

struct LaneRoadMarkLine
{
  double length{0.};
  double space{0.};
  double t{0.};
  double start_offset{0.};
  std::string rule{""};
  double width{0.};
};

struct LaneRoadMarkType
{
  std::string name{""};
  double width{0.};
};

struct LaneMaterial
{
  double start_offset{0.};
  std::string surface{""};
  double friction{0.};
  double roughness{0.};
};

struct LaneVisibility
{
  double start_offset{0.};
  double forward{0.};
  double back{0.};
  double left{0.};
  double right{0.};
};

struct LaneAccess
{
  double start_offset{0.};
  std::string restriction{""};
};

struct LaneHeight
{
  double start_offset{0.};
  double inner{0.};
  double outer{0.};
  bool operator<(LaneHeight const &other) const
  {
    return start_offset < other.start_offset;
  }
};
typedef std::set<LaneHeight> LaneHeightSet;

struct LaneRule
{
  double start_offset{0.};
  std::string value{""};
};

struct LaneBorder : public OffsetPoly3
{
};

struct LaneOffset : public OffsetPoly3
{
};
typedef std::set<LaneOffset> LaneOffsetSet;

struct LaneSpeed
{
  double start_offset{0.}; // start position(s - offset from the
                           // current lane section) [meters]
  double max_speed{0.};    // maximum allowed speed [meters/second]
  std::string unit{""};
};

struct LaneLink
{
  int predecessor_id{-1};
  int successor_id{-1};
};

struct ParametricSpeed
{
  double start{0.};
  double end{1.};
  double speed{0.};

  ParametricSpeed()
    : start{0.}
    , end{1.0}
    , speed{0.}
  {
  }
  explicit ParametricSpeed(double _speed)
    : start{0.}
    , end{1.0}
    , speed{_speed}
  {
  }
};

struct Validity
{
  static int const LOWER_BOUND{-100};
  static int const UPPER_BOUND{100};
  int from_lane{LOWER_BOUND};
  int to_lane{UPPER_BOUND};
  bool IsWithinRange(int id) const
  {
    if ((from_lane <= id) && (id <= to_lane))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

struct TrafficSignalReference
{
  int id{-1};
  double start_position{0.}; // s
  double track_position{0.}; // t
  std::string orientation{""};
  std::string relation{""};
  Validity validityInfo;
};

struct SignalReference
{
  int id{-1};
  double parametricPosition{0.};
  bool inLaneOrientation{false};
  std::string turnRelation{""};
};

using Id = uint64_t;
using Edge = std::vector<Point>;

struct LaneInfo
{
  std::vector<LaneSpeed> lane_speed;

  LaneAttributes attributes;
  LaneWidthSet lane_width;
  std::vector<LaneMaterial> lane_materials;
  std::vector<LaneVisibility> lane_visibility;
  std::vector<LaneAccess> lane_access;
  LaneHeightSet lane_height;
  std::vector<LaneRule> lane_rule;
  std::vector<LaneBorder> lane_border;
  std::vector<LaneRoadMarkLine> road_marker_line;
  std::vector<LaneRoadMark> road_marker;
  std::vector<LaneRoadMarkType> road_marker_type;
  std::unique_ptr<LaneLink> link;

  std::vector<TrafficSignalReference> lane_trafficlight_references;
};

struct LaneSection
{
  double start_position{0.};
  double end_position{0.}; // extended value
  std::vector<LaneInfo> left, center, right;
};

struct Lanes
{
  LaneOffsetSet lane_offset;
  std::vector<LaneSection> lane_sections;
};

/////////////////////////////////////////////////////////////////

struct ElevationProfile : public OffsetPoly3
{
};
typedef std::set<ElevationProfile> ElevationProfileSet;

struct LateralProfileSuperelevation : public OffsetPoly3
{
};
typedef std::set<LateralProfileSuperelevation> LateralProfileSuperelevationSet;

struct LateralProfileShape : public OffsetPoly3
{
  double s_position{0.}; // Shape polynomial is in t-axis direction, a set of this is placed at different s-positions
};

typedef std::set<LateralProfileShape> LateralProfileShapeSet;
typedef std::map<double, LateralProfileShapeSet> LateralProfileShapeSetMap;

struct RoadProfiles
{
  ElevationProfileSet elevation_profile;
  LateralProfileSuperelevationSet lateral_profile_superelevation;
  LateralProfileShapeSetMap lateral_profile_shape;
};

/////////////////////////////////////////////////////////////////
struct TrafficSignalDependency
{
  int dependent_signal_id{-1};
  std::string type{""};
};

struct TrafficSignPositionInertial
{
  bool valid{false};
  Point location; // point of the location
  double hdg{0.}; // rad: Heading of the signal, relative to the inertial system
  double pitch{
    0.}; // rad: Pitch angle of the signal after applying heading, relative to the inertial system (x’y’-plane)
  double roll{0.}; // rad: Roll angle of the signal after applying heading and pitch, relative to the inertial system
                   // (x’’y’’-plane)
};

struct TrafficSignPositionRoad
{
  bool valid{false};
  int reference_road_id{-1}; // Unique ID of the referenced road
  double sOffset{0.};        // s: s-coordinate
  double tOffset{0.};        // m: t-coordinate
  double zOffset{0.};        // m: z offset from road level to bottom edge of the signal
  double hOffset{0.};        // rad: Heading offset of the signal (relative to @orientation)
  double pitch{
    0.}; // rad: Pitch angle of the signal after applying hOffset, relative to the inertial system (x’y’-plane)
  double roll{0.}; // rad: Roll angle of the signal after applying hOffset and pitch, relative to the inertial system
                   // (x’’y’’-plane)
};

struct TrafficSignalInformation
{
  int id{-1};

  double start_position{0.}; // s
  double track_position{0.}; // t

  double zoffset{0.}; // z offset from track level
  double value{0.};   // value of the signal (e.g. speed,
                      // mass � depending on type)

  std::string name{""};        // name of the signal (e.g. gfx bead
                               // name)
  std::string dynamic{""};     // boolean identification whether
                               // signal is a dynamic
                               // signal(e.g.traffic light)
  std::string orientation{""}; // "+" = valid in positive track
                               // direction; "-" = valid in
                               // negative track direction; "none"
                               // = valid in both directions

  std::string country{""}; // country code of the signal
  std::string type{""};    // type identifier according to
                           // country code or "-1" / "none"
  std::string subtype{""}; // subtype identifier according to
                           // country code or "-1" / "none"

  Validity validityInformation; // for which lanes is the signal valid.

  std::string unit{""};
  double height{0.};
  double width{0.};
  std::string text{""};
  double hoffset{0.};
  double pitch{0.};
  double roll{0.};

  std::vector<TrafficSignalDependency> dependencies;
  TrafficSignPositionInertial physical_position_inertial;
  TrafficSignPositionRoad physical_position_road;
};

/////////////////////////////////////////////////////////////////

struct RoadTypeInfo
{
  double s{0.};
  std::string type{""};
};

struct RoadSpeed
{
  double s{0.};
  double max{0.};
  std::string unit{""};
};

struct RoadAttributes
{
  std::string name{""};
  int id{-1};
  int junction{-1};
  double length{0.};
  std::vector<RoadTypeInfo> type;
  std::vector<RoadSpeed> speed;
};

struct RoadLinkInformation
{
  int id{-1};
  ElementType element_type{ElementType::Invalid};
  ContactPoint contact_point{ContactPoint::Invalid};
};

struct RoadLink
{
  std::unique_ptr<RoadLinkInformation> successor;
  std::unique_ptr<RoadLinkInformation> predecessor;
};

struct RoadOutline
{
  double u{0.};
  double v{0.};
  double z{0.};
};

struct RoadObjects
{
  std::string type{""};
  std::string name{""};
  RoadOutline outline;
  double speed{0.};
};

struct RoadInformation
{
  RoadLink road_link;
  RoadProfiles road_profiles;

  RoadAttributes attributes;
  Lanes lanes;

  std::vector<TrafficSignalInformation> traffic_signals;
  std::vector<TrafficSignalReference> traffic_signal_references;

  std::vector<std::unique_ptr<GeometryAttributes>> geometry_attributes;
  // std::vector<Validity> validity;
  std::vector<RoadObjects> road_objects;
};

/////////////////////////////////////////////////////////////////

struct JunctionAttribues
{
  int id{-1};
  std::string name{""};
};

struct JunctionConnectionAttributes
{
  int id{-1};
  int incoming_road{-1};
  int connecting_road{-1};
  std::string contact_point{""};
};

struct JunctionControllerAttributes
{
  int id{-1};
};

struct JunctionLaneLink
{
  int from{-1};
  int to{-1};
};

struct JunctionController
{
  JunctionControllerAttributes attributes;
};

struct JunctionConnection
{
  JunctionConnectionAttributes attributes;
  std::vector<JunctionLaneLink> links;
};

struct Junction
{
  JunctionAttribues attributes;
  std::vector<JunctionConnection> connections;
  std::vector<JunctionController> controllers;
};

struct BoxComponent
{
  double x_pos{0.}, y_pos{0.}, z_pos{0.};
  double x_rot{0.}, y_rot{0.}, z_rot{0.};
  double scale{1.};
};

struct TrafficLight
{
  double x_pos{0.}, y_pos{0.}, z_pos{0.};
  double x_rot{0.}, y_rot{0.}, z_rot{0.};
  double scale{1.};
  std::vector<BoxComponent> box_areas;
};

struct TrafficLightGroup
{
  std::vector<TrafficLight> traffic_lights;
  double red_time{0.}, yellow_time{0.}, green_time{0.};
};

struct TrafficSign
{
  double x_pos{0.}, y_pos{0.}, z_pos{0.};
  double x_rot{0.}, y_rot{0.}, z_rot{0.};
  double scale{1.};
  int speed{30};
  std::vector<BoxComponent> box_areas;
};

struct Controller
{
  int id{0};
  std::string name{""};
  int sequence{0};
};

struct ControllerSignal
{
  int id{0};
  std::string type{""};
};

/////////////////////////////////////////////////////////////////
namespace geom {
struct GeoLocation
{
  double latitude{std::numeric_limits<double>::quiet_NaN()};
  double longitude{std::numeric_limits<double>::quiet_NaN()};
  double altitude{0.};
  std::string projection{""};
};
} // namespace geom

/////////////////////////////////////////////////////////////////
struct Lane
{
  Id id{0u};
  LaneType type{LaneType::None};
  Edge leftEdge;
  Edge rightEdge;
  std::set<Id> successors;
  std::set<Id> predecessors;
  std::set<Id> overlaps;
  std::vector<ParametricSpeed> speed;
  std::vector<SignalReference> signalReferences;

  Id leftNeighbor{0u};
  Id rightNeighbor{0u};
  int index{0};
  int junction{-1};
};

struct Landmark
{
  int id{-1};
  int type{-1};
  int subtype{-1};
  Point position{0., 0., 0.};
  double orientation{0.};
};

using LaneMap = std::unordered_map<Id, Lane>;
using LandmarkMap = std::unordered_map<int, Landmark>;

struct OpenDriveData
{
  geom::GeoLocation geoReference;
  std::vector<RoadInformation> roads;
  std::vector<Junction> junctions;
  std::vector<TrafficLightGroup> trafficlightgroups;
  std::vector<TrafficSign> trafficsigns;
  std::vector<Controller> controllers;
  std::vector<ControllerSignal> controllersignals;

  LaneMap laneMap;
  LandmarkMap landmarks;
  std::unordered_map<int, std::vector<Id>> intersectionLaneIds;
};
} // namespace opendrive
