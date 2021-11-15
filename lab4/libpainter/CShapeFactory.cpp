
#include <memory>
#include <sstream>
#include "CShape.h"
#include "CShapeFactory.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRegularPolygon.h"
#include <optional>

using namespace std;

unique_ptr<CShape> CShapeFactory::CreateShape(const string& description)
{
	auto descriptionStream = istringstream(description);
	string shapeName;
	descriptionStream >> shapeName;

	if (shapeName == "rectangle")
		return GetRectangle(descriptionStream);
	else if (shapeName == "triangle")
		return GetTriangle(descriptionStream);
	else if (shapeName == "ellipse")
		return GetEllipse(descriptionStream);
	else if (shapeName == "regular_polygon")
		return GetRegularPolygon(descriptionStream);
	else
		throw invalid_argument("unknown shape name: " + shapeName);
}

optional<Color> CShapeFactory::GetColor(istringstream& descriptionStream)
{
	string color;
	descriptionStream >> color;

	if (color.empty())
		return nullopt;

	if (color == "black")
		return Color::Black;
	else if (color == "blue")
		return Color::Blue;
	else if (color == "green")
		return Color::Green;
	else if (color == "pink")
		return Color::Pink;
	else if (color == "red")
		return Color::Red;
	else if (color == "yellow")
		return Color::Yellow;
	else
		throw invalid_argument("unknown color: " + color);
}

unique_ptr<CShape> CShapeFactory::GetRectangle(istringstream& descriptionStream)
{
	float x, y, w, h;

	if (!(descriptionStream >> x) || !(descriptionStream >> y) || !(descriptionStream >> w) || !(descriptionStream >> h))
		throw invalid_argument("parameters expected");

	auto color = GetColor(descriptionStream);
	if (color.has_value())
		return make_unique<CRectangle>(x, y, w, h, color.value());
	else
		return make_unique<CRectangle>(x, y, w, h);
}

std::unique_ptr<CShape> CShapeFactory::GetTriangle(istringstream& descriptionStream)
{
	float x1, y1, x2, y2, x3, y3;

	if (!(descriptionStream >> x1) || !(descriptionStream >> y1)
		|| !(descriptionStream >> x2) || !(descriptionStream >> y2)
		|| !(descriptionStream >> x3) || !(descriptionStream >> y3)
		)
		throw invalid_argument("parameters expected");

	auto color = GetColor(descriptionStream);
	if (color.has_value())
		return make_unique<CTriangle>(x1, y1, x2, y2, x3, y3, color.value());
	else
		return make_unique<CTriangle>(x1, y1, x2, y2, x3, y3);
}

std::unique_ptr<CShape> CShapeFactory::GetEllipse(istringstream& descriptionStream)
{
	float x, y, rx, ry;

	if (!(descriptionStream >> x) || !(descriptionStream >> y) || !(descriptionStream >> rx) || !(descriptionStream >> ry))
		throw invalid_argument("parameters expected");

	auto color = GetColor(descriptionStream);
	if (color.has_value())
		return make_unique<CEllipse>(x, y, rx, ry, color.value());
	else
		return make_unique<CEllipse>(x, y, rx, ry);
}

std::unique_ptr<CShape> CShapeFactory::GetRegularPolygon(istringstream& descriptionStream)
{
	float x, y, r, n;

	if (!(descriptionStream >> x) || !(descriptionStream >> y) || !(descriptionStream >> r) || !(descriptionStream >> n))
		throw invalid_argument("parameters expected");

	auto color = GetColor(descriptionStream);
	if (color.has_value())
		return make_unique<CRegularPolygon>(x, y, r, n, color.value());
	else
		return make_unique<CRegularPolygon>(x, y, r, n);
}
