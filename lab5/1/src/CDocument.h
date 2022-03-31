#pragma once

#include <string>
#include <vector>
#include "IDocument.h"
#include "CHistory.h"
#include "CDocumentItem.h"

class CDocument : public IDocument
{
public:
	CDocument();

	std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, const std::optional<size_t>& position = std::nullopt) override;

	std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, const std::optional<size_t>& position = std::nullopt) override;

	void ReplaceText(size_t position, const std::string& newText) override;
	void ResizeImage(size_t position, int width, int height) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(size_t index) const override;
	CDocumentItem GetItem(size_t index) override;

	void DeleteItem(size_t index) override;

	void SetTitle(const std::string& title) override;

	std::string GetTitle() const override;

	bool CanUndo() const override;

	void Undo() override;

	bool CanRedo() const override;

	void Redo() override;

private:
	std::string m_title;
	std::unique_ptr<CHistory> m_history;
	std::vector<CDocumentItem> m_items;
};