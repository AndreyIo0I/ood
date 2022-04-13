#pragma once

#include <string>
#include "IDocument.h"
#include "IParagraph.h"
#include "IImage.h"

class CHtmlSaver
{
public:
	static void Save(const std::unique_ptr<IDocument>& document, const std::string& path);

private:
	static std::string ParagraphToHtml(const std::shared_ptr<IParagraph>& paragraph);
	static std::string ImageToHtml(const std::shared_ptr<IImage>& image);
	static std::string HtmlEncode(const std::string& str);
};
