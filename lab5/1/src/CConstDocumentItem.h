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

	// ���������� ��������� �� ����������� �����������, ���� nullptr, ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage() const;

	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<const IParagraph> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	Item m_item;
};
