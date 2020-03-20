## Latest changes

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
