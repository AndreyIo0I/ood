
#include "CRectangle.h"

CRectangle::CRectangle(float x, float y, float w, float h, Color color)
	: CShape(color), m_leftX(x), m_topY(y), m_width(w), m_height(h)
{
}

Point CRectangle::GetLeftTop() const
{
	return {m_leftX, m_topY};
}

Point CRectangle::GetRightBottom() const
{
	return {m_leftX + m_width, m_topY + m_height};
}

void CRectangle::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	canvas.DrawLine(m_leftX, m_topY, m_leftX + m_width, m_topY);
	canvas.DrawLine(m_leftX, m_topY, m_leftX, m_topY + m_height);
	canvas.DrawLine(m_leftX + m_width, m_topY + m_height, m_leftX + m_width, m_topY);
	canvas.DrawLine(m_leftX + m_width, m_topY + m_height, m_leftX, m_topY + m_height);
}