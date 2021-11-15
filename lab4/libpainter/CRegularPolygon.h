#pragma once

#include "Color.h"
#include "CShape.h"
#include "Point.h"

class CRegularPolygon: public CShape
{
public:
	CRegularPolygon(float x, float y, float r, int n, Color color = Color::Black);
	int GetVertexCount() const;
	Point GetCenter() const;
	float GetRadius() const;
	void Draw(ICanvas& canvas) const override;

private:
	float m_x, m_y, m_r;
	int m_n;
};