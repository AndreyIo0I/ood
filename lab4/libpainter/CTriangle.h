#pragma once

#include "Color.h"
#include "CShape.h"
#include "Point.h"

class CTriangle: public CShape
{
public:
	CTriangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color = Color::Black);
	Point GetVertex1() const;
	Point GetVertex2() const;
	Point GetVertex3() const;
	void Draw(ICanvas& canvas) const override;

private:
	float m_x1, m_y1, m_x2, m_y2, m_x3, m_y3;
};