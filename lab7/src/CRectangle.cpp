#include "CRectangle.h"
#include "CommonTypes.h"

using namespace std;

CRectangle::CRectangle(double x1, double y1, double x2, double y2)
	: m_leftTop({x1, y1})
	, m_rightBottom({x2, y2})
{
}

optional<RectD> CRectangle::GetFrame()
{
	return RectD {
		m_leftTop.x,
		m_leftTop.y,
		m_rightBottom.x - m_leftTop.x,
		m_rightBottom.y - m_leftTop.y,
	};
}

void CRectangle::SetFrame(const RectD& rect)
{
	m_leftTop.x = rect.left;
	m_leftTop.y = rect.top;
	m_rightBottom.x = rect.left + rect.width;
	m_rightBottom.y = rect.top + rect.height;
}

void CRectangle::Draw(ICanvas& canvas)
{
	CShape::Draw(canvas);

	canvas.DrawLine(m_leftTop, {m_rightBottom.x, m_leftTop.y});
	canvas.DrawLine(m_leftTop, {m_leftTop.x, m_rightBottom.y});
	canvas.DrawLine(m_rightBottom, {m_leftTop.x, m_rightBottom.y});
	canvas.DrawLine(m_rightBottom, {m_rightBottom.x, m_leftTop.y});

	canvas.FillPolygon({
		m_leftTop,
		{m_rightBottom.x, m_leftTop.y},
		m_rightBottom,
		{m_leftTop.x, m_rightBottom.y}
	});
}
