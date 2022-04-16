
#include "CCompositeLineStyle.h"

using namespace std;

CCompositeLineStyle::CCompositeLineStyle(IStyleEnumerator<ILineStyle>& enumerator)
	: m_enumerator(enumerator)
{
}

optional<double> CCompositeLineStyle::GetLineWidth() const
{
	optional<double> result;
	bool isFirstStyle = true;

	auto callback = [&](ILineStyle& style) {
		if (isFirstStyle)
		{
			result = style.GetLineWidth().value();
			isFirstStyle = false;
		}
		else if (style.GetLineWidth() != result)
			result = nullopt;
	};

	m_enumerator.EnumerateAll(callback);
	return result;
}

void CCompositeLineStyle::SetLineWidth(double width)
{
	function<void(ILineStyle&)> callback = [&](ILineStyle& style) {
		style.SetLineWidth(width);
	};

	m_enumerator.EnumerateAll(callback);
}

optional<RGBAColor> CCompositeLineStyle::GetColor() const
{
	optional<RGBAColor> result;
	bool isFirstStyle = true;

	auto callback = [&](ILineStyle& style) {
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

void CCompositeLineStyle::SetColor(optional<RGBAColor> color)
{
	function<void(ILineStyle&)> callback = [&](ILineStyle& style) {
		style.SetColor(color);
	};

	m_enumerator.EnumerateAll(callback);
}
