/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-1988
 */

#pragma once

#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include "ad/map/match/LaneOccupiedRegionList.hpp"
#include "ad/map/match/MapMatchedPositionConfidenceList.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace match
 *
 * Map matching
 */
namespace match {

/*!
 * \brief DataType MapMatchedObjectBoundingBox
 */
struct MapMatchedObjectBoundingBox
{
  /*!
   * \brief Smart pointer on MapMatchedObjectBoundingBox
   */
  typedef std::shared_ptr<MapMatchedObjectBoundingBox> Ptr;

  /*!
   * \brief Smart pointer on constant MapMatchedObjectBoundingBox
   */
  typedef std::shared_ptr<MapMatchedObjectBoundingBox const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  MapMatchedObjectBoundingBox() = default;

  /*!
   * \brief standard destructor
   */
  ~MapMatchedObjectBoundingBox() = default;

  /*!
   * \brief standard copy constructor
   */
  MapMatchedObjectBoundingBox(const MapMatchedObjectBoundingBox &other) = default;

  /*!
   * \brief standard move constructor
   */
  MapMatchedObjectBoundingBox(MapMatchedObjectBoundingBox &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns Reference to this MapMatchedObjectBoundingBox.
   */
  MapMatchedObjectBoundingBox &operator=(const MapMatchedObjectBoundingBox &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns Reference to this MapMatchedObjectBoundingBox.
   */
  MapMatchedObjectBoundingBox &operator=(MapMatchedObjectBoundingBox &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox
   *
   * \returns \c true if both MapMatchedObjectBoundingBox are equal
   */
  bool operator==(const MapMatchedObjectBoundingBox &other) const
  {
    return (laneOccupiedRegions == other.laneOccupiedRegions)
      && (referencePointPositions == other.referencePointPositions);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other MapMatchedObjectBoundingBox.
   *
   * \returns \c true if both MapMatchedObjectBoundingBox are different
   */
  bool operator!=(const MapMatchedObjectBoundingBox &other) const
  {
    return !operator==(other);
  }

  ::ad::map::match::LaneOccupiedRegionList laneOccupiedRegions;
  typedef std::vector<::ad::map::match::MapMatchedPositionConfidenceList> ReferencePointPositionsType;
  ReferencePointPositionsType referencePointPositions;
};

} // namespace match
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
#define GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace match
 *
 * Map matching
 */
namespace match {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value MapMatchedObjectBoundingBox value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, MapMatchedObjectBoundingBox const &_value)
{
  os << "MapMatchedObjectBoundingBox(";
  os << "laneOccupiedRegions:";
  os << _value.laneOccupiedRegions;
  os << ",";
  os << "referencePointPositions:";
  os << "[";
  for (auto it_value_referencePointPositions = _value.referencePointPositions.begin();
       it_value_referencePointPositions != _value.referencePointPositions.end();
       it_value_referencePointPositions++)
  {
    if (it_value_referencePointPositions != _value.referencePointPositions.begin())
    {
      os << ",";
    }
    auto &_value_referencePointPositionsVal = *it_value_referencePointPositions;
    os << _value_referencePointPositionsVal;
  }
  os << "]";
  os << ")";
  return os;
}

} // namespace match
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for MapMatchedObjectBoundingBox
 */
inline std::string to_string(::ad::map::match::MapMatchedObjectBoundingBox const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std
#endif // GEN_GUARD_AD_MAP_MATCH_MAPMATCHEDOBJECTBOUNDINGBOX
