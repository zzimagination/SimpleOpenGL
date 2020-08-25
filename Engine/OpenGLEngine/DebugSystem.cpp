#include "DebugSystem.h"
#include "DebugFile.h"
#include "DebugOutput.h"
#include <iostream>

namespace SemperEngine {

	using namespace std;

	thread DebugSystem::_debugThread;

	bool DebugSystem::_isOpen = false;

	void DebugSystem::Initialization()
	{
		_isOpen = true;
		_debugThread = thread(Start);
	}

	void DebugSystem::Dispose()
	{
		_isOpen = false;
		_debugThread.join();
	}

	void DebugSystem::Start()
	{
		DebugFile::Open();
		while (_isOpen)
		{
			Update();
			this_thread::sleep_for(chrono::milliseconds(100));
		}
		DebugFile::Close();
	}

	void DebugSystem::Update()
	{
		while (DebugOutput::HasLog())
		{
			LogItem item = DebugOutput::OutputLog();
			std::string content;
			content.append(item.info);
			DebugFile::Write(content);
			std::cout << content << std::endl;
		}
		DebugFile::Flush();
	}
}