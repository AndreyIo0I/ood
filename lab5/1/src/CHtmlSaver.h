#pragma once

#include <string>
#include "IDocument.h"
#include "IParagraph.h"
#include "IImage.h"

class CHtmlSaver
{
public:
	void Save(const std::unique_ptr<IDocument>& document, const std::string& path);

private:
	std::string ParagraphToHtml(const std::shared_ptr<IParagraph>& paragraph);
	std::string ImageToHtml(const std::shared_ptr<IImage>& image);
	std::string HtmlEncode(const std::string& str);
};
