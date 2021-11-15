#pragma once

#include "Color.h"

struct ICanvas
{
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(float x1, float y1, float x2, float y2) = 0;
	virtual void DrawEllipse(float cx, float cy, float rx, float ry) = 0;

	virtual ~ICanvas() = default;
};