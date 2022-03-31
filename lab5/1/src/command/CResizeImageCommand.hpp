#pragma once

#include "CAbstractCommand.h"
#include "CDocumentItem.h"

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(std::shared_ptr<IImage> item, int width, int height)
		: m_item(item)
		, m_width(width)
		, m_height(height)
	{
	}

protected:
	void DoExecute() override
	{
		SwapSize();
	}

	void DoUnexecute() override
	{
		SwapSize();
	}

private:

	void SwapSize()
	{
		int tmpWidth = m_item->GetWidth();
		int tmpHeight = m_item->GetHeight();
		m_item->Resize(m_width, m_height);
		m_width = tmpWidth;
		m_height = tmpHeight;
	}

	std::shared_ptr<IImage> m_item;
	int m_width, m_height;
};
