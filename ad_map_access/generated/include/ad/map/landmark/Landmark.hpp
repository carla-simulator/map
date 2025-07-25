/*
 * ----------------- BEGIN LICENSE BLOCK ---------------------------------
 *
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * ----------------- END LICENSE BLOCK -----------------------------------
 */

/**
 * Generated file
 * @file
 *
 * Generator Version : 11.0.0-2046
 */

#pragma once

#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include "ad/map/landmark/LandmarkId.hpp"
#include "ad/map/landmark/LandmarkType.hpp"
#include "ad/map/landmark/TrafficLightType.hpp"
#include "ad/map/landmark/TrafficSignType.hpp"
#include "ad/map/point/ECEFPoint.hpp"
#include "ad/map/point/Geometry.hpp"
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace landmark
 *
 * Handling of landmarks
 */
namespace landmark {

/*!
 * \brief DataType Landmark
 *
 * Landmark description in ECEF coordiante frame.
 */
struct Landmark
{
  /*!
   * \brief Smart pointer on Landmark
   */
  typedef std::shared_ptr<Landmark> Ptr;

  /*!
   * \brief Smart pointer on constant Landmark
   */
  typedef std::shared_ptr<Landmark const> ConstPtr;

  /*!
   * \brief standard constructor
   */
  Landmark() = default;

  /*!
   * \brief standard destructor
   */
  ~Landmark() = default;

  /*!
   * \brief standard copy constructor
   */
  Landmark(const Landmark &other) = default;

  /*!
   * \brief standard move constructor
   */
  Landmark(Landmark &&other) = default;

  /**
   * \brief standard assignment operator
   *
   * \param[in] other Other Landmark
   *
   * \returns Reference to this Landmark.
   */
  Landmark &operator=(const Landmark &other) = default;

  /**
   * \brief standard move operator
   *
   * \param[in] other Other Landmark
   *
   * \returns Reference to this Landmark.
   */
  Landmark &operator=(Landmark &&other) = default;

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Landmark
   *
   * \returns \c true if both Landmark are equal
   */
  bool operator==(const Landmark &other) const
  {
    return (name == other.name) && (id == other.id) && (type == other.type) && (position == other.position)
      && (orientation == other.orientation) && (bounding_box == other.bounding_box)
      && (supplementary_text == other.supplementary_text) && (traffic_light_type == other.traffic_light_type)
      && (traffic_sign_type == other.traffic_sign_type);
  }

  /**
   * \brief standard comparison operator
   *
   * \param[in] other Other Landmark.
   *
   * \returns \c true if both Landmark are different
   */
  bool operator!=(const Landmark &other) const
  {
    return !operator==(other);
  }

  /*!
   * name of the landmark (if available)
   */
  std::string name;

  /*!
   * Identifier of the landmark.
   */
  ::ad::map::landmark::LandmarkId id{0};

  /*!
   * Type of the landmark.
   */
  ::ad::map::landmark::LandmarkType type{::ad::map::landmark::LandmarkType::INVALID};

  /*!
   * Position of the landmark
   */
  ::ad::map::point::ECEFPoint position;

  /*!
   * Landmark 2D orientation regardind Z axis (A.K.A. yaw/heading) [rad]Directional heading of the landmark.
   */
  ::ad::map::point::ECEFPoint orientation;
  ::ad::map::point::Geometry bounding_box;

  /*!
   * If landmark has supplementary text, this is stored in here.
   */
  std::string supplementary_text;

  /*!
   * Type of traffic light
   */
  ::ad::map::landmark::TrafficLightType traffic_light_type;

  /*!
   * Type of traffic sign
   */
  ::ad::map::landmark::TrafficSignType traffic_sign_type;
};

} // namespace landmark
} // namespace map
} // namespace ad

/*!
 * \brief protect the definition of functions from duplicates by typedef usage within other data types
 */
#ifndef GEN_GUARD_AD_MAP_LANDMARK_LANDMARK
#define GEN_GUARD_AD_MAP_LANDMARK_LANDMARK
/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace landmark
 *
 * Handling of landmarks
 */
namespace landmark {

/**
 * \brief standard ostream operator
 *
 * \param[in] os The output stream to write to
 * \param[in] _value Landmark value
 *
 * \returns The stream object.
 *
 */
inline std::ostream &operator<<(std::ostream &os, Landmark const &_value)
{
  os << "Landmark(";
  os << "name:";
  os << _value.name;
  os << ",";
  os << "id:";
  os << _value.id;
  os << ",";
  os << "type:";
  os << _value.type;
  os << ",";
  os << "position:";
  os << _value.position;
  os << ",";
  os << "orientation:";
  os << _value.orientation;
  os << ",";
  os << "bounding_box:";
  os << _value.bounding_box;
  os << ",";
  os << "supplementary_text:";
  os << _value.supplementary_text;
  os << ",";
  os << "traffic_light_type:";
  os << _value.traffic_light_type;
  os << ",";
  os << "traffic_sign_type:";
  os << _value.traffic_sign_type;
  os << ")";
  return os;
}

} // namespace landmark
} // namespace map
} // namespace ad

namespace std {
/*!
 * \brief overload of the std::to_string for Landmark
 */
inline std::string to_string(::ad::map::landmark::Landmark const &value)
{
  stringstream sstream;
  sstream << value;
  return sstream.str();
}
} // namespace std

/*!
 * \brief overload of fmt::formatter calling std::to_string
 */
template <> struct fmt::formatter<::ad::map::landmark::Landmark> : formatter<string_view>
{
  template <typename FormatContext> auto format(::ad::map::landmark::Landmark const &value, FormatContext &ctx)
  {
    return formatter<string_view>::format(std::to_string(value), ctx);
  }
};

#endif // GEN_GUARD_AD_MAP_LANDMARK_LANDMARK
