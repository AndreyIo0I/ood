#pragma once

#include <string>
#include "IDocument.h"
#include "IParagraph.h"
#include "IImage.h"

class CHtmlSaver
{
public:
	static void Save(const IDocument& document, const std::string& path);

private:
	static std::string ParagraphToHtml(const IParagraph& paragraph);
	static std::string ImageToHtml(const IImage& image);
	static std::string HtmlEncode(const std::string& str);
};
