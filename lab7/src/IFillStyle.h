#pragma once
#include "CommonTypes.h"
#include <optional>

class IFillStyle
{
public:
	virtual std::optional<RGBAColor> GetColor() const = 0;
	virtual void SetColor(std::optional<RGBAColor> color) = 0;

	virtual ~IFillStyle() = default;
};