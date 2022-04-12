#include "CSlide.h"
#include "CRectangle.h"
#include <optional>

using namespace std;

CSlide::CSlide(double width, double height, optional<RGBAColor> background)
	: m_width(width)
	, m_height(height)
	, m_background(background)
{
}

double CSlide::GetWidth() const
{
	return m_width;
}

double CSlide::GetHeight() const
{
	return m_height;
}

std::optional<RGBAColor> CSlide::GetBackgroundColor() const
{
	return m_background;
}

void CSlide::SetBackgroundColor(RGBAColor color)
{
	m_background = color;
}

void CSlide::Draw(ICanvas& canvas)
{
	CRectangle background(0, 0, m_width, m_height);
	background.GetFillStyle().SetColor(m_background);
	background.Draw(canvas);
	for (const auto& shape: m_shapes)
		shape->Draw(canvas);
}

size_t CSlide::GetShapesCount() const
{
	return m_shapes.size();
}

std::shared_ptr<IShape> CSlide::GetShapeAtIndex(size_t index)
{
	return m_shapes.at(index);
}

void CSlide::InsertShape(const shared_ptr<IShape>& shape, size_t position)
{
	if (position > m_shapes.size())
		m_shapes.push_back(shape);
	else
		m_shapes.insert(m_shapes.begin() + position, shape);
}

void CSlide::RemoveShapeAtIndex(size_t index)
{
	m_shapes.erase(m_shapes.begin() + index);
}
