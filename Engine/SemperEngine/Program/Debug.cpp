#include "Debug.h"
#include "DebugOutput.h"
#include <iostream>
#include "Time.h"
#include "DebugSystem.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	void Debug::Log(int message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(float message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(double message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(bool message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(char message)
	{
		auto str = to_string(message);
		Log(str);
	}

	void Debug::Log(std::string message)
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

	void Debug::Log(std::wstring message)
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

	void Debug::LogError(int message)
	{
		auto str = to_string(message);
		LogError(str);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(float message)
	{
		auto str = to_string(message);
		LogError(str);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(double message)
	{
		auto str = to_string(message);
		LogError(str);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(bool message)
	{
		auto str = to_string(message);
		LogError(str);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(char message)
	{
		auto str = to_string(message);
		LogError(str);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(std::string message)
	{
		LogItem item(Time::SystemTime(), LogItem::Type::Error);
		item.info = message;
		cout << item.time << ' ' << item.info << endl;
		DebugOutput::InputLog(item);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(const char* message)
	{
		LogItem item(Time::SystemTime(), LogItem::Type::Error);
		item.info = message;
		cout << item.time << ' ' << item.info << endl;
		DebugOutput::InputLog(item);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(std::wstring message)
	{
		LogItem item(Time::SystemTime(), LogItem::Type::Error);
		item.winfo = message;
		cout << item.time << ' ';
		wcout << item.winfo << endl;
		DebugOutput::InputLog(item);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(const wchar_t* message)
	{
		LogItem item(Time::SystemTime(), LogItem::Type::Error);
		item.winfo = message;
		cout << item.time << ' ';
		wcout << item.winfo << endl;
		DebugOutput::InputLog(item);
		DebugSystem::Close();
		throw message;
	}
	void Debug::LogError(std::initializer_list<std::string> messages)
	{
		string sentence = *messages.begin();
		for (auto i = messages.begin() + 1; i != messages.end(); i++)
		{
			sentence.append(*i);
		}
		LogError(sentence);
	}
}