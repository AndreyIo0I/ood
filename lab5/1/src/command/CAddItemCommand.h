#pragma once

#include <vector>
#include <optional>
#include "CAbstractCommand.h"
#include "CDocumentItem.h"

class CAddItemCommand : public CAbstractCommand
{
public:
	CAddItemCommand(std::vector<CDocumentItem>& items, CDocumentItem item, const std::optional<size_t>& position);

protected:
	void DoExecute() override;

	void DoUnexecute() override;

private:
	std::vector<CDocumentItem>& m_items;
	CDocumentItem m_item;
	const size_t m_position;
};
