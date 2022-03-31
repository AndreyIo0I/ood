#pragma once

#include <memory>
#include <string>
#include <variant>
#include "IParagraph.h"
#include "IImage.h"

class CConstDocumentItem
{
public:
	typedef std::variant<std::shared_ptr<IParagraph>, std::shared_ptr<IImage>> Item;

	CConstDocumentItem(Item item);

	// Возвращает указатель на константное изображение, либо nullptr, если элемент не является изображением
	std::shared_ptr<const IImage> GetImage() const;

	// Возвращает указатель на константный параграф, либо nullptr, если элемент не является параграфом
	std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	Item m_item;
};
