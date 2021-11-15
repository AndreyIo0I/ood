
#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>
#include "CRegularPolygon.h"

using namespace std;

CRegularPolygon::CRegularPolygon(float x, float y, float r, int n, Color color)
	: CShape(color), m_x(x), m_y(y), m_r(abs(r)), m_n(n)
{
	if (n < 3)
	{
		throw invalid_argument("n must be greater then zero");
	}
}

int CRegularPolygon::GetVertexCount() const
{
	return m_n;
}

Point CRegularPolygon::GetCenter() const
{
	return {m_x, m_y};
}

float CRegularPolygon::GetRadius() const
{
	return m_r;
}

void CRegularPolygon::Draw(ICanvas& canvas) const
{
	canvas.SetColor(GetColor());
	float x1 = m_x;
	float y1 = m_y + m_r;
	for (int i = 0; i < m_n; ++i)
	{
		float currAngle = M_PI * 2 * i / m_n;
		float x2 = m_x + m_r * sinf(currAngle);
		float y2 = m_y + m_r * cosf(currAngle);
		canvas.DrawLine(x1, y1, x2, y2);
		x1 = x2;
		y1 = y2;
	}
	canvas.DrawLine(x1, y1, m_x, m_y + m_r);
}
