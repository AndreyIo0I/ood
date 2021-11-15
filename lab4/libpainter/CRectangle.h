#pragma once

#include "Color.h"
#include "CShape.h"
#include "Point.h"

class CRectangle: public CShape
{
public:
	CRectangle(float x, float y, float w, float h, Color color = Color::Black);
	Point GetLeftTop() const;
	Point GetRightBottom() const;
	void Draw(ICanvas& canvas) const override;

private:
	float m_x, m_y, m_w, m_h;
};