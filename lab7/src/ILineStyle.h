#pragma once
#include "CommonTypes.h"
#include <optional>

class ILineStyle
{
public:
	virtual double GetLineWidth() const = 0;
	virtual void SetLineWidth(double width) = 0;

	virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(std::optional<RGBAColor> color) = 0;

	virtual ~ILineStyle() = default;
};