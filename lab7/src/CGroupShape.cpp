#include <memory>
#include <iostream>
#include "CommonTypes.h"
#include "CGroupShape.h"

using namespace std;

RectD CGroupShape::GetFrame()
{
	double minX = numeric_limits<double>::max();
	double maxX = numeric_limits<double>::min();
	double minY = numeric_limits<double>::max();
	double maxY = numeric_limits<double>::min();

	for (auto& shape: m_shapes)
	{
		minX = min(minX, shape->GetFrame().left);
		minY = min(minY, shape->GetFrame().top);
		maxX = max(maxX, shape->GetFrame().left + shape->GetFrame().width);
		maxY = max(maxY, shape->GetFrame().top + shape->GetFrame().height);
	}

	return {
		minX,
		minY,
		maxX - minX,
		maxY - minY,
	};
}

void CGroupShape::SetFrame(const RectD& newFrame)
{
	auto currentFrame = GetFrame();
	auto zoomX = newFrame.width / currentFrame.width;
	auto zoomY = newFrame.height / currentFrame.height;

	for (auto& shape: m_shapes)
	{
		auto shapeFrame = shape->GetFrame();
		shape->SetFrame({
			newFrame.left + (shapeFrame.left - currentFrame.left) * zoomX,
			newFrame.top + (shapeFrame.top - currentFrame.top) * zoomY,
			shapeFrame.width * zoomX,
			shapeFrame.height * zoomY,
		});
	}
}

ILineStyle& CGroupShape::GetOutlineStyle()
{
	return *m_lineStyle;
}

const ILineStyle& CGroupShape::GetOutlineStyle() const
{
	return *m_lineStyle;
}

IFillStyle& CGroupShape::GetFillStyle()
{
	return *m_fillStyle;
}

const IFillStyle& CGroupShape::GetFillStyle() const
{
	return *m_fillStyle;
}

shared_ptr<IGroupShape> CGroupShape::GetGroup()
{
	return shared_from_this();
}

shared_ptr<const IGroupShape> CGroupShape::GetGroup() const
{
	return shared_from_this();
}

size_t CGroupShape::GetShapesCount() const
{
	return m_shapes.size();
}

shared_ptr<IShape> CGroupShape::GetShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount())
		throw std::out_of_range("out of range");
	return m_shapes.at(index);
}

void CGroupShape::InsertShape(const shared_ptr<IShape>& shape, size_t position)
{
	if (position >= GetShapesCount())
		m_shapes.push_back(shape);
	else
		m_shapes.insert(m_shapes.begin() + position, shape);
}

void CGroupShape::RemoveShapeAtIndex(size_t index)
{
	if (index >= GetShapesCount())
		throw std::out_of_range("out of range");
	m_shapes.erase(m_shapes.begin() + index);
}

void CGroupShape::Draw(ICanvas& canvas)
{
	for (auto& shape: m_shapes)
		shape->Draw(canvas);
}

void CGroupShape::EnumerateAll(const std::function<void(IFillStyle&)>& callback) const
{
	for (auto& shape : m_shapes)
		callback(shape->GetFillStyle());
}

void CGroupShape::EnumerateAll(const std::function<void(ILineStyle&)>& callback) const
{
	for (auto& shape : m_shapes)
		callback(shape->GetOutlineStyle());
}
