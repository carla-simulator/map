// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/access/Operation.hpp"

#include <boost/filesystem/path.hpp>
#include <fstream>
#include <iomanip>
#include "AdMapAccess.hpp"
#include "ad/map/access/Logging.hpp"
#include "ad/map/config/MapConfigFileHandler.hpp"
#include "ad/map/opendrive/AdMapFactory.hpp"
#include "ad/map/point/Operation.hpp"
#include "ad/map/point/Transform.hpp"
#include "ad/map/serialize/SerializerFileCRC32.hpp"

namespace ad {
namespace map {
namespace access {

void setENUReferencePoint(point::GeoPoint const &point)
{
  auto coordinateTransform = getCoordinateTransform();
  if (!coordinateTransform->isENUValid() || (coordinateTransform->getENUReferencePoint() != point))
  {
    coordinateTransform->setENUReferencePoint(point);
  }
}

std::shared_ptr<point::CoordinateTransform> getCoordinateTransform()
{
  // coordinate transform (at least without ENURefPoint) can actually used before initialization
  // therefore, return the transform without initialization check
  return AdMapAccess::getAdMapAccessInstance().mCoordinateTransform;
}

point::GeoPoint getENUReferencePoint()
{
  return AdMapAccess::getAdMapAccessInstance().mCoordinateTransform->getENUReferencePoint();
}

bool isENUReferencePointSet()
{
  return AdMapAccess::getAdMapAccessInstance().mCoordinateTransform->isENUValid();
}

std::vector<config::PointOfInterest> getPointsOfInterest(point::GeoPoint const &geo_point,
                                                         physics::Distance const &radius)
{
  std::vector<config::PointOfInterest> resultVector;
  point::ECEFPoint const geoPointEcef = point::toECEF(geo_point);
  for (auto const &poi : AdMapAccess::getInitializedInstance().mConfigFileHandler.pointsOfInterest())
  {
    point::ECEFPoint const poiPointEcef = point::toECEF(poi.geo_point);
    physics::Distance const poiDistance = point::distance(poiPointEcef, geoPointEcef);
    if (poiDistance <= radius)
    {
      resultVector.push_back(poi);
    }
  }
  return resultVector;
}

std::vector<config::PointOfInterest> const &getPointsOfInterest()
{
  return AdMapAccess::getInitializedInstance().mConfigFileHandler.pointsOfInterest();
}

bool getPointOfInterest(std::string const &name, config::PointOfInterest &poi)
{
  for (auto pointOfInterest : getPointsOfInterest())
  {
    if (pointOfInterest.name == name)
    {
      poi = pointOfInterest;
      return true;
    }
  }
  return false;
}

bool init(std::string const &configFileName)
{
  // initialization has to be performed without initialization check
  return AdMapAccess::getAdMapAccessInstance().initialize(configFileName);
}

bool initFromOpenDriveContent(std::string const &openDriveContent,
                              double const overlapMargin,
                              intersection::IntersectionType const defaultIntersectionType,
                              landmark::TrafficLightType const defaultTrafficLightType)
{
  return AdMapAccess::getAdMapAccessInstance().initializeFromOpenDriveContent(
    openDriveContent, overlapMargin, defaultIntersectionType, defaultTrafficLightType);
}

bool init(Store::Ptr store)
{
  // initialization has to be performed without initialization check
  return AdMapAccess::getAdMapAccessInstance().initialize(store);
}

void cleanup()
{
  // initialization has to be performed without initialization check
  AdMapAccess::getAdMapAccessInstance().reset();
}

bool isLeftHandedTraffic()
{
  return getStore().getMetaData().traffic_type == TrafficType::LEFT_HAND_TRAFFIC;
}

bool isRightHandedTraffic()
{
  return getStore().getMetaData().traffic_type == TrafficType::RIGHT_HAND_TRAFFIC;
}

Store &getStore()
{
  return *AdMapAccess::getInitializedInstance().mStore;
}

bool saveAsAdm(std::string const &admFileName, bool writeConfigFile)
{
  // write map for convenience
  serialize::SerializerFileCRC32 serializer(true);
  size_t versionMajorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MAJOR;
  size_t versionMinorWrite = ::ad::map::serialize::SerializerFileCRC32::VERSION_MINOR;
  if (!serializer.open(admFileName, versionMajorWrite, versionMinorWrite))
  {
    access::getLogger()->warn("Unable to open map for writing {}", admFileName);
    return false;
  }
  if (!access::getStore().save(serializer))
  {
    access::getLogger()->warn("Unable to save map to file {}", admFileName);
    return false;
  }
  serializer.close();
  access::getLogger()->info("Successfully saved map to file {}", admFileName);

  if (writeConfigFile)
  {
    auto const configFileName = admFileName + ".txt";
    std::ofstream out(configFileName, std::ios_base::trunc);
    if (out.fail())
    {
      access::getLogger()->warn("Unable to save map config text file {}", configFileName);
      return false;
    }
    out << "[ADMap]" << std::endl;
    out << "map=" << boost::filesystem::path(admFileName).filename().string() << std::endl;
    out << std::endl;
    out << "[ENUReference]" << std::endl;
    out << "default=" << std::setprecision(10) << getENUReferencePoint().latitude.mLatitude << " "
        << getENUReferencePoint().longitude.mLongitude << " " << getENUReferencePoint().altitude.mAltitude << " "
        << std::endl;
    out.close();
    access::getLogger()->info("Successfully saved map config text file {}", configFileName);
  }

  return true;
}

} // namespace access
} // namespace map
} // namespace ad
