
#include "CFillStyle.h"

CFillStyle::CFillStyle(std::optional<RGBAColor> color)
	: m_color(color)
{
}

void CFillStyle::SetColor(std::optional<RGBAColor> color)
{
	m_color = color;
}

std::optional<RGBAColor> CFillStyle::GetColor() const
{
	return m_color;
}