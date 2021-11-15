#pragma once

#include "ICanvas.h"
#include "Color.h"

class CShape
{
public:
	CShape(Color color);
	virtual void Draw(ICanvas& canvas) const = 0;
	Color GetColor() const;

	virtual ~CShape() = default;
private:
	Color m_color;
};
