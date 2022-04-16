#include "CEllipse.h"

CEllipse::CEllipse(double cx, double cy, double rx, double ry)
	: m_center({cx, cy})
	, m_rx(rx)
	, m_ry(ry)
{
}

std::optional<RectD> CEllipse::GetFrame()
{
	return RectD {
		m_center.x - m_rx,
		m_center.y - m_ry,
		m_center.x + m_rx,
		m_center.y + m_ry,
	};
}

void CEllipse::SetFrame(const RectD& rect)
{
	m_center = {
		rect.left + rect.width / 2,
		rect.top + rect.height / 2,
	};
	m_rx = rect.width / 2;
	m_ry = rect.height / 2;
}

void CEllipse::Draw(ICanvas& canvas)
{
	CShape::Draw(canvas);

	canvas.FillEllipse(m_center.x - m_rx, m_center.y - m_ry, m_rx * 2, m_ry * 2);
	canvas.DrawEllipse(m_center.x - m_rx, m_center.y - m_ry, m_rx * 2, m_ry * 2);
}
