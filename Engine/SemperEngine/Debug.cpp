#include "Debug.h"
#include "DebugOutput.h"
#include <iostream>
#include "Time.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	void Debug::Log(int& message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(float& message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(double& message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(bool& message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(char& message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(std::string& message)
	{
		LogItem item(Time::SystemTime());
		item.info = message;
		cout << item.time<< ' ' << item.info << endl;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(const char* message)
	{
		LogItem item(Time::SystemTime());
		item.info = message;
		cout << item.time << ' ' << item.info << endl;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(std::wstring& message)
	{
		LogItem item(Time::SystemTime());
		item.winfo = message;
		cout << item.time<< ' ';
		wcout << item.winfo << endl;
		DebugOutput::InputLog(item);
	}

	void Debug::Log(const wchar_t* message)
	{
		LogItem item(Time::SystemTime());
		item.winfo = message;
		cout << item.time << ' ';
		wcout << item.winfo << endl;
		DebugOutput::InputLog(item);
	}
	void Debug::Log(initializer_list<string> messages)
	{
		string sentence = *messages.begin();
		for (auto i = messages.begin() + 1; i != messages.end(); i++)
		{
			sentence.append(*i);
		}
		Log(sentence);
	}
}