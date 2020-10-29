#include "Debug.h"
#include "DebugOutput.h"
#include <iostream>
#include "Time.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	void Debug::Log(int &message)
	{
		LogItem item(Time::SystemTime());
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(float& message)
	{
		LogItem item(Time::SystemTime());
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(double& message)
	{
		LogItem item(Time::SystemTime());
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(bool& message)
	{
		LogItem item(Time::SystemTime());
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(char& message)
	{
		LogItem item(Time::SystemTime());
		item.info = to_string(message);
		DebugOutput::InputLog(item);
	}

	void Debug::Log(std::string& message)
	{
		LogItem item(Time::SystemTime());
		item.info = message;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(const char* message)
	{
		LogItem item(Time::SystemTime());
		item.info = message;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(std::wstring& message)
	{
		LogItem item(Time::SystemTime());
		item.winfo = message;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(const wchar_t* message)
	{
		LogItem item(Time::SystemTime());
		item.winfo = message;
		DebugOutput::InputLog(item);
	}
	void Debug::Log(initializer_list<string> messages)
	{
		string sentence = *messages.begin();
		for (auto i = messages.begin()+1; i != messages.end(); i++)
		{
			sentence.append(*i);
		}
		Log(sentence);
	}
}