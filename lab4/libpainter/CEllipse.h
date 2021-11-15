#pragma once

#include "Color.h"
#include "CShape.h"
#include "Point.h"

class CEllipse: public CShape
{
public:
	CEllipse(float x, float y, float rx, float ry, Color color = Color::Black);
	Point GetCenter() const;
	float GetHorizontalRadius() const;
	float GetVerticalRadius() const;
	void Draw(ICanvas& canvas) const override;

private:
	float m_x, m_y, m_rx, m_ry;
};