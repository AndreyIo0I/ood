
#include "CCompositeFillStyle.h"

using namespace std;

CCompositeFillStyle::CCompositeFillStyle(IStyleEnumerator<IFillStyle>& enumerator)
	: m_enumerator(enumerator)
{
}

optional<RGBAColor> CCompositeFillStyle::GetColor() const
{
	optional<RGBAColor> result;
	bool isFirstStyle = true;

	function<void(IFillStyle&)> callback = [&](IFillStyle& style) {
		if (isFirstStyle)
		{
			result = style.GetColor();
			isFirstStyle = false;
		}
		else if (style.GetColor() != result)
			result = nullopt;
	};

	m_enumerator.EnumerateAll(callback);
	return result;
}

void CCompositeFillStyle::SetColor(optional<RGBAColor> color)
{
	function<void(IFillStyle&)> callback = [&](IFillStyle& style) {
		style.SetColor(color);
	};

	m_enumerator.EnumerateAll(callback);
}
