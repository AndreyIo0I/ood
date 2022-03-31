#include "CDocument.h"
#include "CDocumentItem.h"
#include "command/CChangeStringCommand.h"
#include "command/CAddItemCommand.h"
#include "CParagraph.h"
#include <memory>
#include <string>
#include <filesystem>
#include <CImage.h>
#include <command/CReplaceTextCommand.hpp>
#include <command/CResizeImageCommand.hpp>

using namespace std;
namespace fs = filesystem;

CDocument::CDocument()
	: m_history(make_unique<CHistory>())
{
}

shared_ptr<IParagraph> CDocument::InsertParagraph(const string& text, const optional<size_t>& position)
{
	auto paragraph = make_shared<CParagraph>(text);

	CDocumentItem item(paragraph);
	m_history->AddAndExecuteCommand(make_unique<CAddItemCommand>(m_items, item, position));

	return paragraph;
}

shared_ptr<IImage> CDocument::InsertImage(const string& path, int width, int height, const optional<size_t>& position)
{
	auto image = make_shared<CImage>(path, width, height);

	CDocumentItem item(image);
	m_history->AddAndExecuteCommand(make_unique<CAddItemCommand>(m_items, item, position));

	return shared_ptr<IImage>();
}

void CDocument::ReplaceText(size_t position, const std::string& newText)
{
	auto item = GetItem(position);
	if (auto paragraph = item.GetParagraph())
		m_history->AddAndExecuteCommand(make_unique<CReplaceTextCommand>(paragraph, newText));
}

void CDocument::ResizeImage(size_t position, int width, int height)
{
	auto item = GetItem(position);
	if (auto image = item.GetImage())
		m_history->AddAndExecuteCommand(make_unique<CResizeImageCommand>(image, width, height));
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(size_t index) const
{
	return m_items.at(index);
}

CDocumentItem CDocument::GetItem(size_t index)
{
	return m_items.at(index);
}

void CDocument::DeleteItem(size_t index)
{
	m_items.erase(m_items.begin() + index);
}

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
