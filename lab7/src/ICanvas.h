#pragma once
#include <optional>
#include <vector>
#include "CommonTypes.h"

class ICanvas
{
public:
	virtual void DrawLine(Point const& from, Point const& to) = 0;
	virtual void FillPolygon(std::vector<Point> const& points) = 0;

	virtual void DrawEllipse(double left, double top, double width, double height) = 0;
	virtual void FillEllipse(double left, double top, double width, double height) = 0;

	virtual void SetLineColor(std::optional<RGBAColor> color) = 0;
	virtual void SetFillColor(std::optional<RGBAColor> color) = 0;
	virtual void SetLineWidth(double width) = 0;

	virtual ~ICanvas() = default;
};