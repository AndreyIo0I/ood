#pragma once
#include <iosfwd>
#include "IDesigner.h"
#include "IShapeFactory.h"
#include "CPictureDraft.h"

class CDesigner: IDesigner
{
public:
	CDesigner(IShapeFactory& factory);
	CPictureDraft CreateDraft(std::istream& inputData) override;

private:
	IShapeFactory& m_factory;
};

