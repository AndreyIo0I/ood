#pragma once
#include <memory>
#include <string>
#include "IParagraph.h"
#include "IImage.h"
#include "CConstDocumentItem.h"
#include "CDocumentItem.h"
#include <optional>

class IDocument
{
public:
	// ��������� �������� ������ � ��������� ������� (������� ����������� ��������)
	// ���� �������� position �� ������, ������� ���������� � ����� ���������
	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, const std::optional<size_t>& position = std::nullopt) = 0;

	//// ��������� ����������� � ��������� ������� (������� ����������� ��������)
	//// �������� path ������ ���� � ������������ �����������
	//// ��� ������� ����������� ������ ������������ � ���������� images 
	//// ��� ������������� ��������������� ������
	virtual std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, const std::optional<size_t>& position = std::nullopt) = 0;

	virtual void ReplaceText(size_t position, const std::string& newText) = 0;
	virtual void ResizeImage(size_t position, int width, int height) = 0;

	//// ���������� ���������� ��������� � ���������
	virtual size_t GetItemsCount()const = 0;

	//// ������ � ��������� �����������
	virtual CConstDocumentItem GetItem(size_t index)const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	//// ������� ������� �� ���������
	virtual void DeleteItem(size_t index) = 0;

	// ���������� ��������� ���������
	virtual std::string GetTitle()const = 0;
	// �������� ��������� ���������
	virtual void SetTitle(const std::string& title) = 0;

	// �������� � ����������� �������� Undo
	virtual bool CanUndo()const = 0;
	// �������� ������� ��������������
	virtual void Undo() = 0;

	// �������� � ����������� �������� Redo
	virtual bool CanRedo()const = 0;
	// ��������� ���������� ������� ��������������
	virtual void Redo() = 0;

	virtual ~IDocument() = default;
};
