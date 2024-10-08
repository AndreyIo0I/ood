#include <string>
#include "CChangeStringCommand.h"

CChangeStringCommand::CChangeStringCommand(std::string& target, std::string const& newValue)
	: m_target(target), m_newValue(newValue)
{
}

void CChangeStringCommand::DoExecute()
{
	m_newValue.swap(m_target);
}

void CChangeStringCommand::DoUnexecute()
{
	m_newValue.swap(m_target);
}
