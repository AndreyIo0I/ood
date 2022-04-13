
#include "ILineStyle.h"
#include "CShape.h"

ILineStyle& CShape::GetOutlineStyle()
{
	return *m_lineStyle;
}

const ILineStyle& CShape::GetOutlineStyle() const
{
	return *m_lineStyle;
}

IFillStyle& CShape::GetFillStyle()
{
	return *m_fillStyle;
}

const IFillStyle& CShape::GetFillStyle() const
{
	return *m_fillStyle;
}

std::shared_ptr<IGroupShape> CShape::GetGroup()
{
	return nullptr;
}

std::shared_ptr<const IGroupShape> CShape::GetGroup() const
{
	return nullptr;
}

void CShape::Draw(ICanvas& canvas)
{
	canvas.SetFillColor(GetFillStyle().GetColor());
	canvas.SetLineColor(GetOutlineStyle().GetColor());
	canvas.SetLineWidth(GetOutlineStyle().GetLineWidth());
}
