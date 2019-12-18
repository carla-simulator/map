// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// INTEL CONFIDENTIAL
//
// Copyright (c) 2017-2019 Intel Corporation
//
// This software and the related documents are Intel copyrighted materials, and
// your use of them is governed by the express license under which they were
// provided to you (License). Unless the License provides otherwise, you may not
// use, modify, copy, publish, distribute, disclose or transmit this software or
// the related documents without Intel's prior written permission.
//
// This software and the related documents are provided as is, with no express or
// implied warranties, other than those that are expressly stated in the License.
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#include <osmium/osm/types.hpp>
#pragma GCC diagnostic pop

#include <ad/map/maker/common/RightOfWay.hpp>

namespace ad {
namespace map {
namespace maker {
namespace osm_converter {

struct OsmJunctionArm
{
  ::osmium::object_id_type mArmId{};
  ::osmium::object_id_type mWayId{};
  ::osmium::object_id_type mCenterId{};
  uint32_t mIndexOfCenter{static_cast<uint32_t>(-1)}; // the index of the center point in the nodes list of the way
  // if true: the attached segment leads into the junction. That is, mArmId is the node before the junction
  bool mIncoming{true};
  double mDirection{-1.}; //! direction of arm, 0 radians pointing to the right (east)
                          //! right of way when entering the intersection (independent if incoming or outgoing
  common::RightOfWay mRightOfWay{common::RightOfWay::Undefined};
};

} // namespace osm_converter
} // namespace maker
} // namespace map
} // namespace ad

/*
 * Required to use OsmJunctionArm together with std::unordered_set
 */
#include <functional>
namespace std {
template <> struct hash<::ad::map::maker::osm_converter::OsmJunctionArm>
{
  std::size_t operator()(::ad::map::maker::osm_converter::OsmJunctionArm const &t) const
  {
    // replicate boost hash, see
    // https://stackoverflow.com/questions/5889238/why-is-xor-the-default-way-to-combine-hashes#comment54810251_27952689
    std::size_t const hash = 0x9E3779B97F4A7C15;
    std::size_t lhs = t.mArmId;
    std::size_t rhs = t.mCenterId;
    lhs ^= rhs + hash + (lhs << 6) + (lhs >> 2);
    return lhs;
  }
};

template <> struct equal_to<::ad::map::maker::osm_converter::OsmJunctionArm>
{
  constexpr bool operator()(::ad::map::maker::osm_converter::OsmJunctionArm const &lhs,
                            ::ad::map::maker::osm_converter::OsmJunctionArm const &rhs) const
  {
    return ((lhs.mArmId == rhs.mArmId) && (lhs.mIncoming == rhs.mIncoming) && (lhs.mWayId == rhs.mWayId)
            && (lhs.mCenterId == rhs.mCenterId));
  }
};

} // namespace std
