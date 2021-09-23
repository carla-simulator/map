## Latest changes

## Release 2.6.0
#### :ghost: Maintenance
* Fix map matching with AltitudeUnknown
* Remove Ubuntu 16.04 support

## Release 2.5.1
#### :ghost: Maintenance
* Fix ENU conversion of OpenDrive imports

## Release 2.5.0
#### :ghost: Maintenance
* Ease version number handling and folder layout
* Route planning fixes and extensions
  - Split CoreIntersection parts from Intersection wich are independant from
    the route and right-of-way handling. And fixed outgoingParaPoints()
  - Extend map matching, route prediction and connecting route handling by
    relevantLane parameter to restrict the functionality to a fixed subset
    of the map.
  - Added route::planning::predictRoutesDirectionless().
  - Made operation mode of route::planning::filterDuplicateRoutes() and all
    of the route::planning::predictRoute*() functions configurable
  - Fixed the search for start interval in
    route::planning::compareRoutesOnIntervalLevel() and made function
    public.
  - route::extendRouteToDistance() considers the shorter version of the
    expanded routes instead of larger to prevent consecutive route
    expansions to overlook possible routes through the intersection;
  - route::calculateConnectingRoute() considers not only the shortest
    connecting route, but judges also the feasibility of the connecting
    route based on the actual heading differences in respect to the route.
    This prevents from selecting e.g. wrong 90° crossing lanes with very
    small connecting route because vehicles would drive there side by side.
  - route::alignRoute{Ending|Starting}Points() prevent from invalid or
    unnecesary alignments.
  - route: :planning::RouteAStar/RoutePrediction: handle
    RoutingDirection: :DONT_CARE as input correctly

## Release 2.4.8
#### :ghost: Maintenance
* Allow larger ENUCoordinates up to 1e9 (previously 1e6) and ENUCoordinate input up to 1e8 (previously 1.6e4)

## Release 2.4.7
#### :ghost: Maintenance
* Fixed version numbers
* Fixed OpenDRIVE import
* Removed outdated and error prone plain cmake build from documentation

## Release 2.4.6
#### :rocket: New Features
* Add creation of python wheels

## Release 2.4.5
#### :rocket: New Features
* Complete geometry import of OpenDRIVE reader

## Release 2.4.4
#### :rocket: New Features
* Add elevation profile to road geometry on OpenDRIVE import
* Added support for point::AltitudeUnknown in match::AdMapMatching

## Release 2.4.3
#### :rocket: New Features
* Enabled use of Proj4 reference strings in OpenDRIVE maps

## Release 2.4.2
#### :ghost: Maintenance
* Fix plan route: Ignore empty routes (of length 0) when searching for the shortest route
* CoordinateTransform: Fix error messages
* Opendrive reader: handle exception when traffic signal type is no integer
* ad_map_access_qgis
  - Adapt ad_map_access imports
  - Close opendrive file after usage and provide default Geo reference if required (i.e. if not present in xodr file)
  - Snapping: fix error handling, increase search radius
  - Fix visibility of feature attributes
  - Fix point layer useage in tests

## Release 2.4.0
#### :rocket: New Features
* Qgis 2.18 to QGis 3.14
   - The plugin code is adapted to QGis3.14, Python 3 and the python bindings of the new C++ interface.
   - QGis-Logger is restored.
   - Button to enable LaneIDs in view for all layers at once.
   - Settings for Route Prediction test,Routing Test at run time.
   - For open drive map, the attributes roadId, laneSectionIndex and laneIndex are added.
   - The ENU coordinates of the map snapped point is added as an attribute.
* Added AdMapMatching::findRouteLanes()
* Added lane::findNearestPointOnLaneInterval()
* Added matchRadius and samplingDistance members to match::MapMatchedObjectBoundingBox

#### :ghost: Maintenance
* Use target python version for build
* Generate list types and tests: ENUBorderList, GeoBorderList, ECEFBorderList,
  FullRouteList, MapMatchedObjectReferencePositionList
* Fixed issue in reading of some OpenDRIVE maps
* Fixed point::getParametricRange() for degenerated edges
* Fixed lane::calcLength(<ENU,ECEF,Geo>BorderList) functions
* Allow rounding errors in lane::isPointWithinBorderPoints() (might e.g. happen after projection of outside points onto the borders)
* Fix route::planning::createRoutingPoint(match::LaneOccupiedRegion)

## Release 2.3.0
#### :rocket: New Features
* Added ad::physics::<Type>List types
#### :ghost: Maintenance
* ad_map_opendrive_reader: fixed reading of CARLA v0.9.10 maps
* Improved user interface of python binding

## Release 2.2.1
#### :ghost: Maintenance
* Fix build with C++ 17
* Suppressed python code generation build output

## Release 2.2.0
#### :ghost: Maintenance
* Fix build of unit tests under Ubuntu18.04 with gcc 7.5.0
* Added ad::map::route::extendRouteToDestinations()
* Fixed AdMapMatching function constness
* Made ad::map::route::filterDuplicateRoutes() public available
* ad::map::access::initializeFromOpenDriveContent can be initialized twice with same open drive content
* Build documentation update to make the plain cmake build more robust and especially make repeated builds with -DBUILD_PYTHON_BINDING=ON working

## Release 2.1.0
#### :ghost: Maintenance
* Added physics::AngleRange, physics::AngluarAcceleration data types and some AngleOperations
* Extended physics Parametric and Ratio Operations to all physics basic types
* Map Matching
  - map::match::MapMatchedPosition get matchedPointDistance member
  - removed distance parameter from match::AdMapMatching::getMapMatchedBoundingBox() and match::AdMapMatching::getLaneOccupiedRegions() functions which is now derived automatically from samplingDistance parameter
  - The occupied regions only consider longitudinal in-lane matches
* Removed misleading functions route::getRouteIntervalStart/End(LaneInterval); directly use the LaneInterval members instead
* route::calculateConnectingRoute() shortens the result route by removing overlapping regions with the objects; the length of the connecting route now reflects the distance of the vehicles much better
* Improved documentation (BUILDING, map_maker)
* Added qgis plugin static build colcon meta file

## Release 2.0.3
#### :ghost: Maintenance
* Added python interface test execution
* Fixed test build on Ubuntu18.04
* Fixed clang-8 and gcc-9 build

## Release 2.0.2
#### :ghost: Maintenance
* Fixed python binding for multiple python version built

## Release 2.0.1
#### :ghost: Maintenance
* Fixed missing boost include

## Release 2.0.0
#### :rocket: New Features
* Support robust calculation of the ENUHeading of an object on a route getENUHeadingOfRoute(match::Object, route::FullRoute):
  - Get center waypoint: route::findCenterWaypoint(match::Object)
  - Get a route section around the object: route::getRouteSection()
  - Get its vector<ENUBorder>: route::getENUBorderOfRoute(route::FullRoute)
  - Calculate ENUHeading of the borders at given point lane::getENUHeading(vector<ENUBorder>, ENUPoint)
* route::shortenRoute():
  - Result value ShortenRouteResult provides more insight in the actual result
  - Indroduced ShortenRouteMode::PrependIfSucceededBeforeRoute
  - Indroduced ShortenRouteMode::DontCutIntersectionAndPrependIfSucceededBeforeRoute
* intersection::Intersection
  - Added Intersection::isRoadSegmentEnteringIntersection()
  - Added Intersection::isRoutePartOfAnIntersection()
  - Added Intersection::objectRouteCrossesIntersection()
  - And so optimized route::isConnectedRoutePartOfAnIntersection() (renamed from route::intersectionOnConnectedRoute())
  - Extended intersection to get along with routes stopping within intersection
* Refactoring of ConnectingRoute by making use of FullRoute subtype:
  - Enables use of FullRoute operations also for connecting route types
  - Removes code duplications and fixes connecting route segment ordering
  - Moved lane offset handling directly into FullRoute
  - Introduced different ConnectingRouteTypes
  - Fix: Consider also that objectA might be 'Following' of obectB
  - Feature: Consider also routes connecting by 'Merging' of routes
* Route planning and Prediction
  - Made duration and distance restrictions available on all route planning and prediction functions
  - Provide RouteCreationMode parameter to all route planning functions and store mode in FullRoute to enable route operations to reuse the mode.
* Other:
  - OpenDrive: allow setting of defaultTrafficLightType
  - Add: lane::calcLength(match::LaneOccupiedRegion)
  - Add: lane::calcWidth(match::LaneOccupiedRegion)
  - Add: route::isRouteDirectionAlignedWithDrivingDirection(lane::LaneInterval)
  - Add: additional lane::get*ProjectedEdge() overloads
  - Add: route::findCenterWaypoint(match::Object)
  - Add: route::getENUHeadingOfRoute(match::Object)
  - Add: route::isObjectHeadingInRouteDirection(match::Object)
  - Add: point::calculateWidthRange(Edge, Edge)
  - Add: route::getMetricRanges(LaneInterval)
  - Extend planRoute for vector of ENUPoints

#### :ghost: Maintenance
* Fixed Intersection::objectRouteFromSameArmAsIntersectionRoute calculation
* Fix inline declaration of restriction::areAttributesEqual()
* Fixed match::AdMapMatching::getMapMatchedBoundingBox calculation
* route::planning::predictRoutes*() and route::extendRouteToDistance():
  - Fixed route planning counters
  - Ensure result routes don't stop within Intersections
  - Fixed duplicate handling
  - Removed unfinshed route predictions from result list
* Fix: Calculate wrongWay flag of LaneInterval correctly
* Fix: Remove LaneType::UNKNOWN from routable lanes
* Fix: Allow lateral routing also within intersections
* Fix: Convert opendrive Bidirectional lanes to LaneType::NORMAL lanes
* Fix: Clear references to erased successors in route::shortenRouteToDistance()
* Renamed match::getParaPoint(match::LaneOccupiedRegion) to match::getCenterParaPoint(match::LaneOccupiedRegion)
* Adaptions for python binding built to support multiple python version at once and newer boost versions

## Release 1.1.0
#### :rocket: New Features
* Added Python bindings
* Add route::planRoute() overload for ENUPoints
* Added route::getSpeedLimits() overloads for route types
* Added Distance2D and Dimension2D DataTypes

#### :ghost: Maintenance
* Simplified code to enable python binding
* Fixed match::getObjectENUHeading() calculation
* Fixed unit tests for gcc 7.4.0 (shipped with ubuntu 18.04)

## Release 1.0.0
* Initial release
