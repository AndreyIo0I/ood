#pragma once

#include "IDrawable.h"
#include "IShapes.h"

class ISlide : public IDrawable, IShapes
{
public:
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual std::optional<RGBAColor> GetBackgroundColor() const = 0;
	virtual void SetBackgroundColor(RGBAColor color) = 0;

	virtual ~ISlide() = default;
};