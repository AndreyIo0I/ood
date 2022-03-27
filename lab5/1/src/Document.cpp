#include "Document.h"
#include "ChangeStringCommand.h"
#include <string>

using namespace std;

void CDocument::SetTitle(const string& title)
{
	m_history->AddAndExecuteCommand(make_unique<CChangeStringCommand>(m_title, title));
}

string CDocument::GetTitle() const
{
	return m_title;
}

bool CDocument::CanUndo() const
{
	return m_history->CanUndo();
}

void CDocument::Undo()
{
	m_history->Undo();
}

bool CDocument::CanRedo() const
{
	return m_history->CanRedo();
}

void CDocument::Redo()
{
	m_history->Redo();
}
