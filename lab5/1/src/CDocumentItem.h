#pragma once

#include "CConstDocumentItem.h"

class CDocumentItem : public CConstDocumentItem
{
public:

	CDocumentItem(Item item);

	// ���������� ��������� �� �����������, ���� nullptr, ���� ������� �� �������� ������������
	std::shared_ptr<IImage> GetImage();

	// ���������� ��������� �� ��������, ���� nullptr, ���� ������� �� �������� ����������
	std::shared_ptr<IParagraph> GetParagraph();
};
