#pragma once

#include "ISlide.h"
#include <optional>
#include <vector>

class CSlide : public ISlide
{
public:
	CSlide(double width, double height, std::optional<RGBAColor> = std::nullopt);

	double GetWidth() const override;
	double GetHeight() const override;

	std::optional<RGBAColor> GetBackgroundColor() const override;
	void SetBackgroundColor(RGBAColor color);

	void Draw(ICanvas& canvas) override;

	size_t GetShapesCount() const override;
	std::shared_ptr<IShape> GetShapeAtIndex(size_t index) override;
	void InsertShape(const std::shared_ptr<IShape>& shape, size_t position = std::numeric_limits<size_t>::max()) override;
	void RemoveShapeAtIndex(size_t index) override;

private:
	double m_width, m_height;
	std::optional<RGBAColor> m_background;
	std::vector<std::shared_ptr<IShape>> m_shapes;
};
