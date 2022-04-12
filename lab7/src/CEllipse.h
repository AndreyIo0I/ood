#pragma once
#include "CShape.h"
#include "CommonTypes.h"

class CEllipse : public CShape
{
public:
	CEllipse(double cx, double cy, double rx, double ry);
	RectD GetFrame() override;
	void SetFrame(const RectD& rect) override;

	void Draw(ICanvas& canvas) override;
private:
	Point m_center;
	double m_rx, m_ry;
};
