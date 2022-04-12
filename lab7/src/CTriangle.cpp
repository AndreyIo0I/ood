#include "CTriangle.h"
#include <algorithm>
#include <iostream>

using namespace std;

CTriangle::CTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
	: m_point1({x1, y1})
	, m_point2({x2, y2})
	, m_point3({x3, y3})
{
}

RectD CTriangle::GetFrame()
{
	auto left = min({m_point1.x, m_point2.x, m_point3.x});
	auto top = min({m_point1.y, m_point2.y, m_point3.y});
	auto right = max({m_point1.x, m_point2.x, m_point3.x});
	auto bottom = max({m_point1.y, m_point2.y, m_point3.y});
	return {
		left,
		top,
		right - left,
		bottom - top,
	};
}

void CTriangle::SetFrame(const RectD& rect)
{
	auto currentFrame = GetFrame();
	auto zoomX = rect.width / currentFrame.width;
	auto zoomY = rect.height / currentFrame.height;

	m_point1.x = rect.left + (m_point1.x - currentFrame.left) * zoomX;
	m_point2.x = rect.left + (m_point2.x - currentFrame.left) * zoomX;
	m_point3.x = rect.left + (m_point3.x - currentFrame.left) * zoomX;

	m_point1.y = rect.top + (m_point1.y - currentFrame.top) * zoomY;
	m_point2.y = rect.top + (m_point2.y - currentFrame.top) * zoomY;
	m_point3.y = rect.top + (m_point3.y - currentFrame.top) * zoomY;
}

void CTriangle::Draw(ICanvas& canvas)
{
	canvas.SetFillColor(GetFillStyle().GetColor());
	canvas.SetLineColor(GetOutlineStyle().GetColor());
	canvas.SetLineWidth(GetOutlineStyle().GetLineWidth());

	canvas.FillPolygon({m_point1, m_point2, m_point3});
}
