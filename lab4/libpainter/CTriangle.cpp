
#include "CTriangle.h"

CTriangle::CTriangle(float x1, float y1, float x2, float y2, float x3, float y3, Color color)
	: CShape(color), m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
{
}

Point CTriangle::GetVertex1() const
{
	return {m_x1, m_y1};
}

Point CTriangle::GetVertex2() const
{
	return {m_x2, m_y2};
}

Point CTriangle::GetVertex3() const
{
	return {m_x3, m_y3};
}

void CTriangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(GetVertex1().x, GetVertex1().y, GetVertex2().x, GetVertex2().y);
	canvas.DrawLine(GetVertex3().x, GetVertex3().y, GetVertex2().x, GetVertex2().y);
	canvas.DrawLine(GetVertex3().x, GetVertex3().y, GetVertex1().x, GetVertex1().y);
}
