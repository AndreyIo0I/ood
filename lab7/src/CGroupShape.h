#pragma once

#include <vector>
#include <memory>
#include "IGroupShape.h"
#include "CLineStyle.h"
#include "CFillStyle.h"
#include "IStyleEnumerator.h"
#include "CCompositeLineStyle.h"
#include "CCompositeFillStyle.h"

class CGroupShape : public IGroupShape, public IStyleEnumerator<IFillStyle>, public IStyleEnumerator<ILineStyle>, public std::enable_shared_from_this<IGroupShape>
{
public:
	std::optional<RectD> GetFrame() override;
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

	void EnumerateAll(const std::function<void(IFillStyle& style)>& callback) const override;
	void EnumerateAll(const std::function<void(ILineStyle& style)>& callback) const override;

private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
	std::shared_ptr<ILineStyle> m_lineStyle = std::make_shared<CCompositeLineStyle>(*this);
	std::shared_ptr<IFillStyle> m_fillStyle = std::make_shared<CCompositeFillStyle>(*this);
};