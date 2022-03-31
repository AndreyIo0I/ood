#pragma once

#include <memory>
#include <string>
#include "IParagraph.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(const std::string& text);

	std::string GetText() const override;

	void SetText(const std::string& text) override;

private:
	std::string m_text;
};

