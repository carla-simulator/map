// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2017-2019 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------

#include "ad/map/maker/common/StringHelper.hpp"
#include <iostream>
#include <limits.h> /* for INT_MIN, INT_MAX */
#include <string.h> /* for memcmp, strlen */

namespace ad {
namespace map {
namespace maker {
namespace common {

std::vector<std::string> splitString(std::string const &splitString, const char separator)
{
  std::vector<std::string> result;
  std::string::size_type startPos = 0;

  do
  {
    std::string::size_type endPos = splitString.find(separator, startPos);
    if (endPos == std::string::npos)
    {
      endPos = splitString.size();
    }
    result.push_back(splitString.substr(startPos, endPos - startPos));
    startPos = endPos + 1;
  } while (startPos <= splitString.size());

  return result;
}

std::string replace(std::string const &needle, std::string const &pitchfork, std::string const &haystack)
{
  // if needle is empty we return the original haystack
  if (needle.empty())
  {
    return haystack;
  }

  auto startOfNeedle = haystack.find(needle);
  if (startOfNeedle > haystack.size())
  {
    return haystack;
  }
  auto endOfNeedle = startOfNeedle + needle.size();
  std::string result = haystack.substr(0, startOfNeedle);
  result += pitchfork;
  result += haystack.substr(endOfNeedle, haystack.size() - endOfNeedle);
  return result;
}

bool readStringWithOptionalQuotes(std::istream &input, std::string &result)
{
  if (!(input >> std::ws))
  {
    return false;
  }
  if (input.peek() == '\"')
  {
    input.get(); // get rid of first '\"'
    if (std::getline(input, result, '\"'))
    {
      if (input.eof())
      {
        return false;
      }
      else
      {
        return true;
      }
    }
  }
  else
  {
    bool retVal = bool(input >> result);
    return retVal;
  }

  return false;
}

std::string writeStringParam(std::string const &param)
{
  // do we nee any error handling?
  if ((param.front() != '\"') && (param.back() != '\"'))
  {
    return {"\"" + param + "\""};
  }

  return param;
}

bool integerFromString(const char *const value, int32_t &result)
{
  if (!value)
  {
    return false;
  }

  /* In my opinion, std::stoi does not help here because
   * - it may throw
   * - and I have to do all the checks (remainder portion) anyway
   */
  errno = 0;
  char *endPtr{};
  long const convertedValue = strtol(value, &endPtr, 10);
  if (endPtr == value)
  {
    // no characters parsed
    return false;
  }

  if (*endPtr != '\0')
  {
    // characters left
    return false;
  }

  // errors in the converted value itself?
  if (errno != 0)
  {
    return false;
  }

  // since we want an int32_t as result make sure we don't under/overrun
  if ((convertedValue > static_cast<long>(INT_MAX)) || (convertedValue < static_cast<long>(INT_MIN)))
  {
    return false;
  }

  result = static_cast<int32_t>(convertedValue);
  return true;
}

bool doubleFromString(const char *const value, double &result)
{
  if (!value)
  {
    return false;
  }

  /* In my opinion, std::stoi does not help here because
   * - it may throw
   * - and I have to do all the checks (remainder portion) anyway
   */
  errno = 0;
  char *endPtr{};
  double const convertedValue = strtod(value, &endPtr);
  if (endPtr == value)
  {
    // no characters parsed
    return false;
  }

  if (*endPtr != '\0')
  {
    // characters left
    return false;
  }

  // errors in the converted value itself?
  if (errno != 0)
  {
    return false;
  }

  result = convertedValue;
  return true;
}

bool endsWith(const char *const haystack, const char *const needle)
{
  if (!haystack || !needle)
  {
    return false;
  }

  size_t const haystackLen = strlen(haystack);
  size_t const needleLen = strlen(needle);
  if (needleLen > haystackLen)
  {
    return false;
  }

  return (memcmp(&haystack[haystackLen - needleLen], needle, needleLen) == 0);
}

} // namespace common
} // namespace maker
} // namespace map
} // namespace ad
