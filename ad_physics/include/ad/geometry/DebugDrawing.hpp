// ----------------- BEGIN LICENSE BLOCK ---------------------------------
//
// Copyright (C) 2020-2021 Intel Corporation
//
// SPDX-License-Identifier: MIT
//
// ----------------- END LICENSE BLOCK -----------------------------------
/**
 * @file
 */
#pragma once

#include <string>
#include <utility>
#include <vector>
#include "ad/geometry/Types.hpp"

#define DEBUG_DRAWING_POLYGON(polygon, color, ns)                                                                      \
  (::ad::geometry::DebugDrawing::getInstance()->drawPolygon(polygon, color, ns))
#define DEBUG_DRAWING_LINE(line, color, ns) (::ad::geometry::DebugDrawing::getInstance()->drawLine(line, color, ns))
#define DEBUG_DRAWING_IS_ENABLED() (::ad::geometry::DebugDrawing::getInstance()->isEnabled())

/*!
 * @brief namespace ad
 */
namespace ad {
/*!
 * @brief namespace geometry
 */
namespace geometry {

class DebugDrawing
{
public:
  struct NullDeleter
  {
    void operator()(const void *)
    {
    }
  };
  struct DebugPoint
  {
    DebugPoint(double inX, double inY)
      : x(inX)
      , y(inY){};
    double x;
    double y;

    bool operator==(const DebugPoint &other) const
    {
      return (std::abs(x - other.x) <= std::numeric_limits<double>::epsilon())
        && (std::abs(y - other.y) <= std::numeric_limits<double>::epsilon());
    }

    bool operator!=(const DebugPoint &other) const
    {
      return !operator==(other);
    }
  };

  typedef std::vector<DebugPoint> DebugPointVector;

  struct DebugLine
  {
    DebugLine(Line const &iLine, std::string const &iColor, std::string const &iNs)
      : line(iLine)
      , color(iColor)
      , ns(iNs)
    {
    }
    Line line;
    std::string color{"white"};
    std::string ns;

    bool operator==(const DebugLine &other) const
    {
      return (line == other.line) && (color == other.color) && (ns == other.ns);
    }

    bool operator!=(const DebugLine &other) const
    {
      return !operator==(other);
    }

    DebugPointVector getVector()
    {
      DebugPointVector vectorLine;
      for (auto const &pt : line)
      {
        vectorLine.push_back(DebugPoint(pt.x(), pt.y()));
      }
      return vectorLine;
    }
  };

  typedef std::vector<DebugLine> DebugLineVector;

  struct DebugPolygon
  {
    DebugPolygon(Polygon const &iPolygon, std::string const &iColor, std::string const &iNs)
      : polygon(iPolygon)
      , color(iColor)
      , ns(iNs)
    {
    }
    Polygon polygon;
    std::string color{"white"};
    std::string ns;

    bool operator==(const DebugPolygon &other) const
    {
      return (polygon == other.polygon) && (color == other.color) && (ns == other.ns);
    }

    bool operator!=(const DebugPolygon &other) const
    {
      return !operator==(other);
    }

    DebugPointVector getVector()
    {
      DebugPointVector vectorPolygon;
      for (auto const &pt : polygon.outer())
      {
        vectorPolygon.push_back(DebugPoint(pt.x(), pt.y()));
      }
      return vectorPolygon;
    }
  };

  typedef std::vector<DebugPolygon> DebugPolygonVector;

  explicit DebugDrawing() = default;

  /**
   * @brief singelton instance getter
   */
  static std::shared_ptr<DebugDrawing> getInstance()
  {
    static DebugDrawing *mSingleton = new DebugDrawing();
    return std::shared_ptr<DebugDrawing>(mSingleton, NullDeleter());
  }

  /**
   * @brief clean up all geometries to draw (before a new cycle)
   */
  void reset()
  {
    if (!mEnabled)
    {
      return;
    }
    mLines.clear();
    mPolygons.clear();
  }

  /**
   * @brief enable/disable debug drawing
   */
  void enable(bool value)
  {
    mEnabled = value;
  }

  /**
   * @brief enable/disable debug drawing
   */
  bool isEnabled()
  {
    return mEnabled;
  }

  /**
   * @brief draw a line
   *
   * @param[in] line line to draw
   * @param[in] color line color
   * @param[in] ns namespace to identify geometry
   */
  void drawLine(Line const &line, std::string const &color = "white", std::string const &ns = "")
  {
    if (!mEnabled)
    {
      return;
    }
    mLines.push_back(DebugLine(line, color, ns));

    spdlog::trace("DRAW;{};{};{};LINE", ns, color, std::to_string(line));
  }

  /**
   * @brief draw a polygon
   *
   * @param[in] polygon polygon to draw
   * @param[in] color line color
   * @param[in] ns namespace to identify geometry
   */
  void drawPolygon(Polygon const &polygon, std::string const &color = "white", std::string const &ns = "")
  {
    if (!mEnabled)
    {
      return;
    }
    mPolygons.push_back(DebugPolygon(polygon, color, ns));
  }

  /**
   * @brief draw a list of polygons
   *
   * @param[in] polygons polygons to draw
   * @param[in] color line color
   * @param[in] ns namespace to identify geometry
   */
  void drawPolygons(PolygonVector const &polygons, std::string const &color = "white", std::string const &ns = "")
  {
    if (!mEnabled)
    {
      return;
    }
    for (auto const &polygon : polygons)
    {
      mPolygons.push_back(DebugPolygon(polygon, color, ns));
    }
  }

  DebugLineVector mLines;
  DebugPolygonVector mPolygons;
  bool mEnabled{false};
};

} // namespace geometry
} // namespace ad
