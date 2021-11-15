
#include <cmath>
#include "CEllipse.h"

CEllipse::CEllipse(float x, float y, float rx, float ry, Color color)
	: CShape(color), m_x(x), m_y(y), m_rx(abs(rx)), m_ry(abs(ry))
{
}

Point CEllipse::GetCenter() const
{
	return {m_x, m_y};
}

void CEllipse::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawEllipse(m_x, m_y, m_rx, m_ry);
}

float CEllipse::GetHorizontalRadius() const
{
	return m_rx;
}

float CEllipse::GetVerticalRadius() const
{
	return m_ry;
}
