
#include "CLineStyle.h"

CLineStyle::CLineStyle(double width, std::optional<RGBAColor> color)
	: m_width(width)
	, m_color(color)
{
}

void CLineStyle::SetLineWidth(double width)
{
	m_width = width;
}

double CLineStyle::GetLineWidth() const
{
	return m_width;
}

void CLineStyle::SetColor(std::optional<RGBAColor> color)
{
	m_color = color;
}

std::optional<RGBAColor> CLineStyle::GetColor() const
{
	return m_color;
}