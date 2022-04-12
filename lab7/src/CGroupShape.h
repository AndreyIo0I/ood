#pragma once

#include <vector>
#include <memory>
#include "IGroupShape.h"
#include "CLineStyle.h"
#include "CFillStyle.h"

class CGroupShape : public IGroupShape
{
public:
	RectD GetFrame() override;
	void SetFrame(const RectD& newFrame) override;

	ILineStyle& GetOutlineStyle() override;
	const ILineStyle& GetOutlineStyle() const override;

	IFillStyle& GetFillStyle() override;
	const IFillStyle& GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max()) override;
	void RemoveShapeAtIndex(size_t index) override;

	void Draw(ICanvas& canvas) override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ILineStyle> m_lineStyle = std::make_shared<CLineStyle>();
	std::shared_ptr<IFillStyle> m_fillStyle = std::make_shared<CFillStyle>();
};