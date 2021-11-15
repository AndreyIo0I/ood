
#include <ostream>
#include <format>
#include "CSvgCanvas.h"

using namespace std;

CSvgCanvas::CSvgCanvas()
	: m_color(Color::Black)
	, m_outputStr()
{
}

void CSvgCanvas::SetColor(Color color)
{
	m_color = color;
}

void CSvgCanvas::DrawLine(float x1, float y1, float x2, float y2)
{
	m_outputStr += '\t';
	m_outputStr += format(R"(<line x1="{}" y1="{}" x2="{}" y2="{}" stroke="{}" />)", x1, y1, x2, y2, ColorToStr(m_color));
	m_outputStr += '\n';
}

void CSvgCanvas::DrawEllipse(float cx, float cy, float rx, float ry)
{
	m_outputStr += '\t';
	m_outputStr += format(R"(<ellipse cx="{}" cy="{}" rx="{}" ry="{}" stroke="{}" />)", cx, cy, rx, ry, ColorToStr(m_color));
	m_outputStr += '\n';
}

void CSvgCanvas::Print(ostream& output)
{
	output << R"(<svg width="400" height="400" viewBox="0 0 400 400" fill="none" xmlns="http://www.w3.org/2000/svg">)"
		<< '\n'
		<< m_outputStr
		<< "</svg>\n";
}

std::string CSvgCanvas::ColorToStr(Color color)
{
	if (color == Color::Black)
		return "black";
	else if (color == Color::Blue)
		return "blue";
	else if (color == Color::Green)
		return "green";
	else if (color == Color::Pink)
		return "pink";
	else if (color == Color::Red)
		return "red";
	else
		return "yellow";
}
