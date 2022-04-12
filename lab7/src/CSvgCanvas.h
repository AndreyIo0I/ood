#pragma once
#include <optional>
#include <vector>
#include <iostream>
#include "CommonTypes.h"
#include "ICanvas.h"

class CSvgCanvas : public ICanvas
{
public:
	CSvgCanvas(std::ostream& out, double width, double height);

	void DrawLine(const Point& from, const Point& to) override;
	void FillPolygon(const std::vector<Point>& points) override;

	void DrawEllipse(double left, double top, double width, double height) override;
	void FillEllipse(double left, double top, double width, double height) override;

	void SetLineColor(std::optional<RGBAColor> color) override;
	void SetFillColor(std::optional<RGBAColor> color) override;
	void SetLineWidth(double width) override;

	~CSvgCanvas() override;

private:
	static std::string ColorToString(std::optional<RGBAColor> color);

	std::ostream& m_out;
	std::optional<RGBAColor> m_lineColor = std::nullopt;
	std::optional<RGBAColor> m_fillColor = std::nullopt;
	double m_lineWidth = 1;
};