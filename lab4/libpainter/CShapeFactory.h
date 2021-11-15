#pragma once
#include <memory>
#include <string>
#include "IShapeFactory.h"
#include <optional>

class CShapeFactory: public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(const std::string& description) override;

private:
	std::optional<Color> GetColor(std::istringstream& descriptionStream);
	std::unique_ptr<CShape> GetRectangle(std::istringstream& descriptionStream);
	std::unique_ptr<CShape> GetTriangle(std::istringstream& descriptionStream);
	std::unique_ptr<CShape> GetEllipse(std::istringstream& descriptionStream);
	std::unique_ptr<CShape> GetRegularPolygon(std::istringstream& descriptionStream);
};