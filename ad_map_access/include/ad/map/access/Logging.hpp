// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2018-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */

#pragma once

#include <spdlog/logger.h>

/** @brief namespace ad */
namespace ad {
/** @brief namespace map */
namespace map {
/** @brief namespace access */
namespace access {

/**
 * @brief get the admap logger
 */
std::shared_ptr<spdlog::logger> getLogger();

/**
 * @brief get the log level of the admap logger
 */
spdlog::level::level_enum getLogLevel();

/**
 * @brief set the log level of the admap logger
 */
void setLogLevel(spdlog::level::level_enum const logLevel);

/**
 * @brief set the log level of the admap logger from string
 *
 * uses spdlog::level::from_str() to convert to spdlog::level::level_enum
 */
void setLogLevel(std::string const &logLevel);

} // namespace access
} // namespace map
} // namespace ad
