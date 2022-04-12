#pragma once
#include <functional>
#include "IShape.h"
#include "ICanvas.h"

typedef std::function<void(ICanvas& canvas, const IShape& shape)> DrawingStrategy;

class CSimpleShape : public IShape
{
public:
	CSimpleShape(const DrawingStrategy& drawingStrategy)
	{
		(void) &drawingStrategy;
	}
};