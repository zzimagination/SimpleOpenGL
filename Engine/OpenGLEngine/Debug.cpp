#include "Debug.h"
#include "DebugOutput.h"
#include <iostream>

namespace SemperEngine
{
	using namespace std;

	void Debug::Log(int message)
	{
		LogItem item;
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(float message)
	{
		LogItem item;
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(double message)
	{
		LogItem item;
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(bool message)
	{
		LogItem item;
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(char message)
	{
		LogItem item;
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(std::string message)
	{
		LogItem item;
		item.info = message;
		DebugOutput::InputLog(item);
	}
}