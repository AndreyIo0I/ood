#pragma once

#include "Color.h"
#include "ICanvas.h"

class CSvgCanvas: public ICanvas
{
public:
	CSvgCanvas();
	void SetColor(Color color) override;
	void DrawLine(float x1, float y1, float x2, float y2) override;
	void DrawEllipse(float cx, float cy, float rx, float ry) override;
	void Print(std::ostream& output);

private:
	static std::string ColorToStr(Color color);
	Color m_color;
	std::string m_outputStr;
};