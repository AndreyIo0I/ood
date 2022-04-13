#include <string>
#include <sstream>
#include <iomanip>
#include "CSvgCanvas.h"

using namespace std;

CSvgCanvas::CSvgCanvas(ostream& out, double width, double height)
	: m_out(out)
{
	m_out << "<svg width='" << width << "' height='" << height << "' xmlns='http://www.w3.org/2000/svg' >\n";
}

CSvgCanvas::~CSvgCanvas()
{
	m_out << "</svg>\n";
}

void CSvgCanvas::DrawLine(const Point& from, const Point& to)
{
	m_out << "<line "
		  << "x1='" << from.x << "' x2='" << to.x << "' y1='" << from.y << "' y2='" << to.y << "' "
		  << "fill='" << ColorToString(m_fillColor) << "' "
		  << "stroke='" << ColorToString(m_lineColor) << "' "
		  << "stroke-width='" << m_lineWidth << "' />\n";
}

void CSvgCanvas::DrawEllipse(double left, double top, double width, double height)
{
	double rx = width / 2;
	double ry = height / 2;
	double cx = left + rx;
	double cy = top + ry;

	m_out << "<ellipse "
		  << "cx='" << cx << "' "
		  << "cy='" << cy << "' "
		  << "rx='" << rx << "' "
		  << "ry='" << ry << "' "
		  << "fill-opacity='0' "
		  << "stroke='" << ColorToString(m_lineColor) << "' "
		  << "stroke-width='" << m_lineWidth << "' "
		  << "/>\n";
}

void CSvgCanvas::FillEllipse(double left, double top, double width, double height)
{
	double rx = width / 2;
	double ry = height / 2;
	double cx = left + rx;
	double cy = top + ry;

	m_out << "<ellipse "
		  << "cx='" << cx << "' "
		  << "cy='" << cy << "' "
		  << "rx='" << rx << "' "
		  << "ry='" << ry << "' "
		  << "fill='" << ColorToString(m_fillColor) << "' "
		  << "stroke-opacity='0' "
		  << "/>\n";
}

void CSvgCanvas::FillPolygon(const vector<Point>& points)
{
	m_out << "<polyline points='";
	for (const auto& point: points)
		m_out << point.x << ' ' << point.y << ' ';
	m_out << "' fill='" << ColorToString(m_fillColor) << "' stroke='none' />\n";
}

void CSvgCanvas::SetLineColor(optional<RGBAColor> color)
{
	m_lineColor = color;
}

void CSvgCanvas::SetFillColor(optional<RGBAColor> color)
{
	m_fillColor = color;
}

void CSvgCanvas::SetLineWidth(std::optional<double> width)
{
	if (width.has_value())
		m_lineWidth = width.value();
	else
		m_lineWidth = 1;
}

std::string CSvgCanvas::ColorToString(optional<RGBAColor> color)
{
	if (!color.has_value())
		return "black";

	stringstream stream;
	stream << '#' << std::setfill('0') << std::setw(6) << std::hex << color.value();
	return stream.str();
}
