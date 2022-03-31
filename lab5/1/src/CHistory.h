#pragma once

#include "ICommand.h"
#include <deque>

class CHistory
{
public:

	const static size_t MAX_SIZE = 10;

	bool CanUndo() const;

	void Undo();

	bool CanRedo() const;

	void Redo();

	void AddAndExecuteCommand(ICommandPtr&& command);

private:
	std::deque<ICommandPtr> m_commands;
	size_t m_nextCommandIndex = 0;
};

