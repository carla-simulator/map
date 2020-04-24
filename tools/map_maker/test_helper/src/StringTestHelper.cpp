// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2020 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/test_helper/StringTestHelper.hpp"
#include <stdio.h>

namespace ad {
namespace map {
namespace maker {
namespace test_helper {
static bool useColorForComparison{false};

/* the color mode has to be set at least once
 * Either this was done by user-code (which called setColorMode)
 * or from testStringAndPrintDifference
 */
static bool colorModeInitiallySet{false};

static void setInitialColorMode()
{
  if (!colorModeInitiallySet)
  {
    setColorMode(ColorMode::On);
  }
}

static void adustColorModeForConsole()
{
  if (useColorForComparison)
  {
    const char *term = getenv("TERM");
    if (term)
    {
      // if it starts with 'xterm' we assume that is supports color
      if ((term[0] == 'x') && (term[1] == 't') && (term[2] == 'e') && (term[3] == 'r') && (term[4] == 'm'))
      {
        return;
      }
    }
    // turn off coloring if the console doesn't support this
    useColorForComparison = false;
  }
}

void setColorMode(ColorMode mode)
{
  colorModeInitiallySet = true;
  useColorForComparison = (mode == ColorMode::On);
  adustColorModeForConsole();
}

void turnColorOn(const char *const color)
{
  if (useColorForComparison)
  {
    printf("%s", color); // turn color on
  }
}

void turnColorOff()
{
  if (useColorForComparison)
  {
    printf("\x1b[0m"); // turn to normal
  }
}

size_t getMaxLengthOfStrings(std::string const &s1, std::string const &s2)
{
  size_t len = s1.length();
  if (s2.length() < len)
  {
    len = s2.length();
  }
  return len;
}

void printDifferenceOfString(std::string const &toPrint,
                             std::string const &toCompare,
                             const char *const color,
                             size_t const len)
{
  for (size_t i = 0; i < len; i++)
  {
    if (toPrint[i] != toCompare[i])
    {
      turnColorOn(color);
    }
    printf("%c", toPrint[i]);
    if (toPrint[i] != toCompare[i])
    {
      turnColorOff();
    }
  }
}

void printStringDifferences(std::string const &expected, std::string const &actual)
{
  const size_t len = getMaxLengthOfStrings(expected, actual);
  if (expected == actual)
  {
    return;
  }

  if (len > 0)
  {
    printf("Expected:\n");
    printDifferenceOfString(expected, actual, "\x1b[32m", len);
    printf("\nActual:\n");
    printDifferenceOfString(actual, expected, "\x1b[31m", len);
  }
  else
  {
    printf("Either exected (size: %lu) or actual (size: %lu) is empty\n", expected.size(), actual.size());
  }
}

// make this a macro similar to gtest ASSERT_STREQ, maybe ASSERT_STREQ_PRINT_DIFF
bool testStringAndPrintDifference(std::string const &expected, std::string const &actual)
{
  if (expected != actual)
  {
    setInitialColorMode();
    printStringDifferences(expected, actual);

    // print missing parts if strings have different sizes
    if (expected.length() != actual.length())
    {
      if (expected.size() > actual.size())
      {
        printf("\nMissing part from expected:\n");
        turnColorOn("\x1b[32m");
        if (actual.size() > 0)
        {
          printf("%s", &expected.c_str()[actual.size()]);
        }
        else
        {
          printf("%s", expected.c_str());
        }
        turnColorOff();
      }
      else
      {
        printf("\nAdditional part from actual:\n");
        turnColorOn("\x1b[31m");
        if (expected.size() > 0)
        {
          printf("%s", &actual.c_str()[expected.size()]);
        }
        else
        {
          printf("%s", actual.c_str());
        }
        turnColorOff();
      }
      printf("\n");
    }
    return false;
  }

  return true;
}

bool readFile(char const *fileName, std::string &fileContent)
{
  FILE *input = fopen(fileName, "r");
  if (input == nullptr)
  {
    return false;
  }

  if (fseek(input, 0, SEEK_END) != 0)
  {
    return false;
  }

  size_t fileSize = static_cast<size_t>(ftell(input));
  rewind(input);

  char *content = new char[fileSize + 1];
  size_t readCount = fread(content, sizeof(char), fileSize, input);
  if (readCount != fileSize)
  {
    delete[] content;
    content = nullptr;
    return false;
  }
  content[fileSize] = 0;

  fileContent.assign(content);
  return true;
}

} // namespace test_helper
} // namespace maker
} // namespace map
} // namespace ad
