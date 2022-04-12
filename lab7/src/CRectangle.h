#pragma once
#include "CShape.h"
#include "CommonTypes.h"

class CRectangle : public CShape
{
public:
	CRectangle(double x1, double y1, double x2, double y2);
	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	void Draw(ICanvas& canvas) override;
private:
	Point m_leftTop;
	Point m_rightBottom;
};
