#pragma once
#include "IFillStyle.h"
#include "IStyleEnumerator.h"

class CCompositeFillStyle : public IFillStyle
{
public:
	CCompositeFillStyle(IStyleEnumerator<IFillStyle>& enumerator);

	std::optional<RGBAColor> GetColor() const override;
	void SetColor(std::optional<RGBAColor> color) override;

private:
	IStyleEnumerator<IFillStyle>& m_enumerator;
};