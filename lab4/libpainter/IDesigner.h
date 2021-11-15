#pragma once

#include "CPictureDraft.h"

struct IDesigner
{
	virtual CPictureDraft CreateDraft(std::istream& inputData) = 0;

	virtual ~IDesigner() = default;
};