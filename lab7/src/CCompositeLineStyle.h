#pragma once
#include "ILineStyle.h"
#include "IStyleEnumerator.h"

class CCompositeLineStyle : public ILineStyle
{
public:
	CCompositeLineStyle(IStyleEnumerator<ILineStyle>& enumerator);

	std::optional<double> GetLineWidth() const override;
	void SetLineWidth(double width) override;

	std::optional<RGBAColor> GetColor() const override;
	void SetColor(std::optional<RGBAColor> color) override;

private:
	IStyleEnumerator<ILineStyle>& m_enumerator;
};