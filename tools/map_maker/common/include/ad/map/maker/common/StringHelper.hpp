// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#pragma once

#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace ad {
namespace map {
namespace maker {
namespace common {

/**
 * @brief split string at separator
 * @param splitString string to be split
 * @param separator separator to be used
 * @return list of strings
 *
 * Return all strings enclosed with the separator. The start and end of the string
 * are also treated as a separator, using ';' as separator, one gets:
 * "a;b" --> {"a", "b"}
 * ";b" --> {"", "b"}
 * "a;" --> {"a", ""}
 * ";" --> {"", ""}
 * "a;;b" --> {"a", "", "b"}
 * "" --> {""} (@todo should it return an empty list?)
 */
std::vector<std::string> splitString(std::string const &splitString, const char separator);

/**
 * @brief replace first occurence of needle with pitchfork in the haystack
 *
 * @param needle string to be replaced
 * @param pitchfork string used as replacement
 * @param haystack string to apply the replacement
 * @return copy of haystack where needle was replaced by pitchfork
 */
std::string replace(std::string const &needle, std::string const &pitchfork, std::string const &haystack);

/**
 * Read in a string from the given stream. The string may be enclosed with double-quotes
 *
 * @return true if a string was read
 */
bool readStringWithOptionalQuotes(std::istream &input, std::string &result);

/**
 * Add quotes to given string, if the string hasn't already one.
 *
 * @return return changed string
 */
std::string writeStringParam(std::string const &param);

template <typename T> void readParameter(std::istream &input, T &t, std::string const parameter)
{
  if (!(input >> t))
  {
    throw std::invalid_argument("Unable to parse " + parameter);
  }
}

/**
 * @brief Convert given string into an integer
 * @param value string to be converted
 * @param result converted integer value
 * @return true if conversion happened
 *
 * Encapsulate strtod(3) in a function. If any characters are left it will be treated as an error
 * (returning false).
 */
bool integerFromString(const char *const value, int32_t &result);

/**
 * @brief Convert given string into a double
 * @param value string to be converted
 * @param result converted double value
 * @return true if conversion happened
 *
 * Encapsulate strtod(3) in a function. If any characters are left it will be treated as an error
 * (returning false).
 */
bool doubleFromString(const char *const value, double &result);

bool endsWith(const char *const haystack, const char *const needle);

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
