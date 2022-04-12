#pragma once

#include "IShape.h"
#include "IShapes.h"

class IGroupShape : public IShape, public IShapes, public std::enable_shared_from_this<IGroupShape>
{
public:
	virtual ~IGroupShape() = default;
};