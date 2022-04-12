#pragma once
#include "ILineStyle.h"

class CLineStyle : public ILineStyle
{
public:
	CLineStyle(double width = 1, std::optional<RGBAColor> color = std::nullopt);

	double GetLineWidth() const override;
	void SetLineWidth(double width) override;

	std::optional<RGBAColor> GetColor() const override;
	void SetColor(std::optional<RGBAColor> color) override;
private:
	double m_width;
	std::optional<RGBAColor> m_color;
};