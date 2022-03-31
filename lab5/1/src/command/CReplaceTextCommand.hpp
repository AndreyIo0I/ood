#pragma once

#include "CAbstractCommand.h"
#include "CDocumentItem.h"
#include <string>

class CReplaceTextCommand : public CAbstractCommand
{
public:
	CReplaceTextCommand(std::shared_ptr<IParagraph> item, const std::string& text)
		: m_item(item)
		, m_text(text)
	{
	}

protected:
	void DoExecute() override
	{
		SwapText();
	}

	void DoUnexecute() override
	{
		SwapText();
	}

private:

	void SwapText()
	{
		std::string tempStr = m_item->GetText();
		m_item->SetText(m_text);
		m_text = tempStr;
	}

	std::shared_ptr<IParagraph> m_item;
	std::string m_text;
};
