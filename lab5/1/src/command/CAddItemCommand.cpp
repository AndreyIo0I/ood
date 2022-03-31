#include "CAddItemCommand.h"
#include "CDocumentItem.h"
#include <vector>
#include <optional>
#include <stdexcept>
#include <iostream>

using namespace std;

CAddItemCommand::CAddItemCommand(std::vector<CDocumentItem>& items, CDocumentItem item, const optional<size_t>& position)
	: m_items(items)
	, m_item(item)
	, m_position(position.has_value() ? position.value() : items.size())
{
}

void CAddItemCommand::DoExecute()
{
	if (m_position > m_items.size())
		throw exception("position out of range");
	else
		m_items.insert(m_items.begin() + m_position, m_item);
}

void CAddItemCommand::DoUnexecute()
{
	if (m_position >= m_items.size())
		throw exception("position out of range");
	m_items.erase(m_items.begin() + m_position);
}
