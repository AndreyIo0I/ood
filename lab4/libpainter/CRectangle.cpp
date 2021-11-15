
#include "CRectangle.h"

CRectangle::CRectangle(float x, float y, float w, float h, Color color)
	: CShape(color), m_x(x), m_y(y), m_w(w), m_h(h)
{
}

Point CRectangle::GetLeftTop() const
{
	return {m_x, m_y};
}

Point CRectangle::GetRightBottom() const
{
	return {m_x + m_w, m_y + m_h};
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_x, m_y, m_x + m_w, m_y);
	canvas.DrawLine(m_x, m_y, m_x, m_y + m_h);
	canvas.DrawLine(m_x + m_w, m_y + m_h, m_x + m_w, m_y);
	canvas.DrawLine(m_x + m_w, m_y + m_h, m_x, m_y + m_h);
}