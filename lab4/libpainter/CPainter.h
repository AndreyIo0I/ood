#pragma once
#include <iosfwd>
#include "IDesigner.h"
#include "CPictureDraft.h"

class CPainter
{
public:
	void DrawPicture(CPictureDraft& draft, ICanvas& canvas) const;
};

