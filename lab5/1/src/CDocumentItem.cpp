#include "CDocumentItem.h"

using namespace std;

CDocumentItem::CDocumentItem(Item item)
	: CConstDocumentItem(item)
{
}

std::shared_ptr<IImage> CDocumentItem::GetImage()
{
	if (auto itemPtr = get_if<std::shared_ptr<IImage>>(&m_item))
		return *itemPtr;
	return nullptr;
}

std::shared_ptr<IParagraph> CDocumentItem::GetParagraph()
{
	if (auto itemPtr = get_if<std::shared_ptr<IParagraph>>(&m_item))
		return *itemPtr;
	return nullptr;
}
