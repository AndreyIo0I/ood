#pragma once
#include "CShape.h"
#include "CommonTypes.h"

class CTriangle : public CShape
{
public:
	CTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	std::optional<RectD> GetFrame() override;
	void SetFrame(const RectD& rect) override;

	void Draw(ICanvas& canvas) override;
private:
	Point m_point1, m_point2, m_point3;
};
