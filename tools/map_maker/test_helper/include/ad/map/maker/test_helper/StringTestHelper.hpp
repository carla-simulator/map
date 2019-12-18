// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#ifndef STRING_TEST_HELPER_HPP
#define STRING_TEST_HELPER_HPP

#include <gtest/gtest.h>
#include <string>

namespace ad {
namespace map {
namespace maker {
namespace test_helper {

/**
 * Helper functions to highlight differences if strings do not match
 * Makes use of ansi color codes
 */

extern void printStringDifferences(const std::string &expected, const std::string &actual);
extern bool readFile(char const *fileName, std::string &fileContent);
bool testStringAndPrintDifference(std::string const &expected, std::string const &actual);

enum class ColorMode
{
  On,
  Off
};
// default is On (if colors are supported)
extern void setColorMode(ColorMode mode);

} // namespace test_helper
} // namespace maker
} // namespace map
} // namespace ad

/**
 * @brief Compare two strings and highlight difference with red and green (if colors are supported)
 */
#define ASSERT_STREQ_PRINT_DIFF(a, b)                                                                                  \
  if (std::string(a) != std::string(b))                                                                                \
  {                                                                                                                    \
    ::ad::map::maker::test_helper::testStringAndPrintDifference((a), (b));                                             \
    ASSERT_TRUE(false);                                                                                                \
  }

/**
 * @brief Compare string b with content from file a and highlight difference with red and green (if colors are
 * supported)
 *
 * @param b string to be tested
 * @param a name of file
 */
#define ASSERT_FILE_STREQ_PRINT_DIFF(a, b)                                                                             \
  {                                                                                                                    \
    std::string fileContent;                                                                                           \
    ASSERT_TRUE(test_helper::readFile(a, fileContent));                                                                \
    ASSERT_STREQ_PRINT_DIFF(b, fileContent);                                                                           \
  }

#endif /* STRING_TEST_HELPER */
