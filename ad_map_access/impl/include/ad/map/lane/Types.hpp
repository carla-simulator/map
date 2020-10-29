// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <string>
#include "ad/map/lane/ComplianceVersion.hpp"
#include "ad/map/lane/ContactLane.hpp"
#include "ad/map/lane/ContactLaneList.hpp"
#include "ad/map/lane/ContactLocationList.hpp"
#include "ad/map/lane/ContactTypeList.hpp"
#include "ad/map/lane/ECEFBorder.hpp"
#include "ad/map/lane/ENUBorder.hpp"
#include "ad/map/lane/GeoBorder.hpp"
#include "ad/map/lane/Lane.hpp"
#include "ad/map/lane/LaneDirection.hpp"
#include "ad/map/lane/LaneId.hpp"
#include "ad/map/lane/LaneIdList.hpp"
#include "ad/map/lane/LaneIdSet.hpp"
#include "ad/map/lane/LaneType.hpp"

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace map
 */
namespace map {
/*!
 * @brief namespace lane
 *
 * Handling of lanes
 */
namespace lane {

typedef std::vector<ad::map::lane::ENUBorder> ENUBorderList;
typedef std::vector<ad::map::lane::ECEFBorder> ECEFBorderList;
typedef std::vector<ad::map::lane::GeoBorder> GeoBorderList;

} // namespace lane
} // namespace map
} // namespace ad
