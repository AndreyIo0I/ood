#pragma once
#include "IFillStyle.h"

class CFillStyle : public IFillStyle
{
public:
	CFillStyle(std::optional<RGBAColor> color = std::nullopt);

	std::optional<RGBAColor> GetColor() const override;
	void SetColor(std::optional<RGBAColor> color) override;
private:
	std::optional<RGBAColor> m_color;
};