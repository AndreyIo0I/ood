#include <memory>
#include <iostream>
#include "CommonTypes.h"
#include "CGroupShape.h"

using namespace std;

optional<RectD> CGroupShape::GetFrame()
{
	if (GetShapesCount() == 0)
		return nullopt;

	double minX = numeric_limits<double>::max();
	double maxX = numeric_limits<double>::min();
	double minY = numeric_limits<double>::max();
	double maxY = numeric_limits<double>::min();

	for (auto& shape: m_shapes)
	{
		if (!shape->GetFrame().has_value())
			continue;
		auto shapeFrame = shape->GetFrame().value();
		minX = min(minX, shapeFrame.left);
		minY = min(minY, shapeFrame.top);
		maxX = max(maxX, shapeFrame.left + shapeFrame.width);
		maxY = max(maxY, shapeFrame.top + shapeFrame.height);
	}

	return RectD {
		minX,
		minY,
		maxX - minX,
		maxY - minY,
	};
}

void CGroupShape::SetFrame(const RectD& newFrame)
{
	if (GetShapesCount() == 0)
		throw logic_error("resize of empty group of shapes");

	auto currentFrame = GetFrame().value();
	auto zoomX = newFrame.width / currentFrame.width;
	auto zoomY = newFrame.height / currentFrame.height;

	for (auto& shape: m_shapes)
	{
		if (!shape->GetFrame().has_value())
			continue;
		auto shapeFrame = shape->GetFrame().value();
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
