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
	// Вставляет параграф текста в указанную позицию (сдвигая последующие элементы)
	// Если параметр position не указан, вставка происходит в конец документа
	virtual std::shared_ptr<IParagraph> InsertParagraph(const std::string& text, const std::optional<size_t>& position = std::nullopt) = 0;

	//// Вставляет изображение в указанную позицию (сдвигая последующие элементы)
	//// Параметр path задает путь к вставляемому изображению
	//// При вставке изображение должно копироваться в подкаталог images 
	//// под автоматически сгенерированным именем
	virtual std::shared_ptr<IImage> InsertImage(const std::string& path, int width, int height, const std::optional<size_t>& position = std::nullopt) = 0;

	virtual void ReplaceText(size_t position, const std::string& newText) = 0;
	virtual void ResizeImage(size_t position, int width, int height) = 0;

	//// Возвращает количество элементов в документе
	virtual size_t GetItemsCount()const = 0;

	//// Доступ к элементам изображения
	virtual CConstDocumentItem GetItem(size_t index)const = 0;
	virtual CDocumentItem GetItem(size_t index) = 0;

	//// Удаляет элемент из документа
	virtual void DeleteItem(size_t index) = 0;

	// Возвращает заголовок документа
	virtual std::string GetTitle()const = 0;
	// Изменяет заголовок документа
	virtual void SetTitle(const std::string& title) = 0;

	// Сообщает о доступности операции Undo
	virtual bool CanUndo()const = 0;
	// Отменяет команду редактирования
	virtual void Undo() = 0;

	// Сообщает о доступности операции Redo
	virtual bool CanRedo()const = 0;
	// Выполняет отмененную команду редактирования
	virtual void Redo() = 0;

	virtual ~IDocument() = default;
};
