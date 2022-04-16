#pragma once

#include "CMenu.h"
#include "CDocument.h"
#include "IDocument.h"
#include "IParagraph.h"
#include "IImage.h"
#include <iostream>
#include <functional>
#include <filesystem>
#include <CHtmlSaver.h>

namespace
{
	class CEditor
	{
	public:
		CEditor()
			: m_document(std::make_unique<CDocument>())
		{
			m_menu.AddItem("help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
			m_menu.AddItem("exit", "Exit", [this](std::istream&) { m_menu.Exit(); });
			AddMenuItem("setTitle", "Changes title. Args: <new title>", &CEditor::SetTitle);
			AddMenuItem("insertParagraph", "Insert paragraph. Args: <position>|end <text>", &CEditor::InsertParagraph);
			AddMenuItem("insertImage", "Insert image. Args: <position>|end <width> <height> <path>", &CEditor::InsertImage);
			AddMenuItem("replaceText", "Replace text. Args: <position> <text>", &CEditor::ReplaceText);
			AddMenuItem("resizeImage", "Resize image. Args: <position> <width> <height>", &CEditor::ResizeImage);
			AddMenuItem("deleteItem", "Delete item. Args: <position>", &CEditor::DeleteItem);
			AddMenuItem("list", "Show document", &CEditor::List);
			AddMenuItem("undo", "Undo command", &CEditor::Undo);
			AddMenuItem("redo", "Redo undone command", &CEditor::Redo);
			AddMenuItem("save", "Create folder with document data. Args: <dir path>", &CEditor::Save);
		}

		void Start()
		{
			m_menu.Run();
		}

	private:
		// Указатель на метод класса CEditor, принимающий istream& и возвращающий void
		typedef void (CEditor::*MenuHandler)(std::istream& in);

		void AddMenuItem(const std::string& shortcut, const std::string& description, MenuHandler handler)
		{
			m_menu.AddItem(shortcut, description, bind(handler, this, std::placeholders::_1));
		}

		void SetTitle(std::istream& in)
		{
			std::string title;
			getline(in >> std::ws, title);
			m_document->SetTitle(title);
		}

		void InsertParagraph(std::istream& in)
		{
			std::optional<size_t> position = std::nullopt;
			std::string positionStr;
			in >> positionStr;

			try
			{
				if (positionStr != "end")
					position = stoi(positionStr);

				std::string text;
				std::getline(in >> std::ws, text);

				m_document->InsertParagraph(text, position);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what() << '\n';
			}
		}

		void InsertImage(std::istream& in)
		{
			std::optional<size_t> position = std::nullopt;
			std::string positionStr;
			in >> positionStr;

			try
			{
				if (positionStr != "end")
					position = stoi(positionStr);

				int width, height;
				std::string path;
				in >> width >> height;
				std::getline(in >> std::ws, path);

				m_document->InsertImage(path, width, height, position);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what() << '\n';
			}
		}

		void ReplaceText(std::istream& in)
		{
			try
			{
				int position;
				in >> position;
				std::string text;
				getline(in >> std::ws, text);

				m_document->ReplaceText(position, text);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what() << '\n';
			}
		}

		void ResizeImage(std::istream& in)
		{
			try
			{
				size_t position;
				int width, height;
				in >> position >> width >> height;

				m_document->ResizeImage(position, width, height);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what() << '\n';
			}
		}

		void DeleteItem(std::istream& in)
		{
			try
			{
				size_t position;
				in >> position;

				m_document->DeleteItem(position);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what() << '\n';
			}
		}

		void List(std::istream&)
		{
			std::cout << "-------------\n";
			std::cout << "Title: " << m_document->GetTitle() << "\n";
			for (size_t i = 0; i < m_document->GetItemsCount(); ++i)
			{
				std::cout << i << ". ";
				auto item = m_document->GetItem(i);

				std::shared_ptr<const IParagraph> paragraph = item.GetParagraph();
				if (paragraph != nullptr)
				{
					std::cout << "Paragraph: " << paragraph->GetText() << '\n';
				}

				std::shared_ptr<const IImage> image = item.GetImage();
				if (image != nullptr)
				{
					std::cout << "Image: " << image->GetWidth() << ' ' << image->GetHeight() << ' ' << image->GetPath() << '\n';
				}
			}
			std::cout << "-------------\n";
		}

		void Undo(std::istream&)
		{
			if (m_document->CanUndo())
				m_document->Undo();
			else
				std::cout << "Can't undo\n";
		}

		void Redo(std::istream&)
		{
			if (m_document->CanRedo())
				m_document->Redo();
			else
				std::cout << "Can't redo\n";
		}

		void Save(std::istream& in)
		{
			std::string path;
			std::getline(in >> std::ws, path);

			try
			{
				CHtmlSaver::Save(*m_document, path);
			}
			catch (const std::exception& exc)
			{
				std::cout << exc.what();
			}
		}

		CMenu m_menu;
		std::unique_ptr<IDocument> m_document;
	};
}
