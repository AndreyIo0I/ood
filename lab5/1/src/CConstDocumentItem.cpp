#include "CConstDocumentItem.h"
#include <variant>

CConstDocumentItem::CConstDocumentItem(Item item)
	: m_item(item)
{
}

std::shared_ptr<const IImage> CConstDocumentItem::GetImage() const
{
	if (auto itemPtr = get_if<std::shared_ptr<IImage>>(&m_item))
		return *itemPtr;
	return nullptr;
}

std::shared_ptr<const IParagraph> CConstDocumentItem::GetParagraph() const
{
	if (auto itemPtr = get_if<std::shared_ptr<IParagraph>>(&m_item))
		return *itemPtr;
	return nullptr;
}

