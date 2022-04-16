#pragma once

#include <optional>
#include "IShape.h"
#include "IFillStyle.h"
#include "ILineStyle.h"
#include "CLineStyle.h"
#include "CFillStyle.h"

class IGroupShape;

class CShape : public IShape
{
public:
	std::optional<RectD> GetFrame() override = 0;
	void SetFrame(const RectD& rect) override = 0;

	ILineStyle& GetOutlineStyle() override;
	const ILineStyle& GetOutlineStyle() const override;

	IFillStyle& GetFillStyle() override;
	const IFillStyle& GetFillStyle() const override;

	std::shared_ptr<IGroupShape> GetGroup() override;
	std::shared_ptr<const IGroupShape> GetGroup() const override;

	void Draw(ICanvas& canvas) override;

private:
	std::shared_ptr<ILineStyle> m_lineStyle = std::make_shared<CLineStyle>();
	std::shared_ptr<IFillStyle> m_fillStyle = std::make_shared<CFillStyle>();
};