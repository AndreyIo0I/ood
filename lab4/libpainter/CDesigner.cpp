#include "CDesigner.h"
#include <istream>
#include <iostream>

using namespace std;

CDesigner::CDesigner(IShapeFactory& factory)
	:m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& inputData)
{
	CPictureDraft draft;
	string line;
	while (getline(inputData, line))
	{
		if (line == "quit")
			break;
		try
		{
			draft.AddShape(m_factory.CreateShape(line));
		}
		catch (const exception& e)
		{
			cout << e.what();
		}
	}
	return draft;
}
