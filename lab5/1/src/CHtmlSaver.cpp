#pragma once

#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "IDocument.h"
#include "CHtmlSaver.h"

using namespace std;
namespace fs = filesystem;

void CHtmlSaver::Save(const IDocument& document, const string& path)
{
	if (!fs::exists(path) || !fs::is_directory(path))
		throw logic_error("Save path (" + path + ") must exist and be a directory!");
	
	string docFolder = path + "/doc";
	for (int i = 0;; ++i)
	{
		if (!fs::exists(docFolder))
			break;
		docFolder = path + "/doc" + to_string(i);
	}
	fs::create_directory(docFolder);

	string imagesFolder = docFolder + "/images";
	fs::create_directory(imagesFolder);

	string htmlPath = docFolder + "/index.html";
	ofstream out(htmlPath);

	out << "<!DOCTYPE html>\n"
		<< "<html>\n"
		<< "<head>\n"
		<< "	<title>" << HtmlEncode(document.GetTitle()) << "</title>\n"
		<< "</head>\n"
		<< "<body>\n";

	for (auto i = 0; i < document.GetItemsCount(); ++i)
	{
		auto item = document.GetItem(i);
		auto paragraph = item.GetParagraph();
		auto image = item.GetImage();
		if (paragraph != nullptr)
		{
			out << "	" << ParagraphToHtml(*paragraph) << '\n';
		}
		else if (image != nullptr)
		{
			fs::copy_file(image->GetPath(), imagesFolder / image->GetPath().filename());
			out << "	" << ImageToHtml(*image) << '\n';
		}
	}

	out << "</body>\n"
		<< "</html>\n";
}

string CHtmlSaver::ParagraphToHtml(const IParagraph& paragraph)
{
	return "<p>" + HtmlEncode(paragraph.GetText()) + "</p>";
}

string CHtmlSaver::ImageToHtml(const IImage& image)
{
	return "<img src='" + HtmlEncode(image.GetPath().string())
		+ "' width='" + HtmlEncode(to_string(image.GetWidth()))
		+ "' height='" + HtmlEncode(to_string(image.GetHeight()))
		+ "'/>";
}

string CHtmlSaver::HtmlEncode(const string& str)
{
	string encoded;
	for (auto ch : str)
		switch (ch)
		{
		case '<':
			encoded.append("&lt;");
			break;
		case '>':
			encoded.append("&gt;");
			break;
		case '"':
			encoded.append("&quot;");
			break;
		case '\'':
			encoded.append("&apos;");
			break;
		case '&':
			encoded.append("&amp;");
			break;
		default:
			encoded.push_back(ch);
		}
	return encoded;
}
