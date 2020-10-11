#include "DebugSystem.h"
#include "DebugFile.h"
#include "DebugOutput.h"
#include <iostream>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		thread DebugSystem::_debugThread;

		bool DebugSystem::_isOpen = false;

		std::chrono::milliseconds DebugSystem::_time;

		void DebugSystem::Initialization()
		{
			_time = chrono::milliseconds(100);
			_isOpen = true;
			_debugThread = thread(Start);
		}

		void DebugSystem::Start()
		{
			DebugFile::Open();
			while (_isOpen)
			{
				Update();
				this_thread::sleep_for(_time);
			}
		}

		void DebugSystem::Update()
		{
			while (DebugOutput::HasLog())
			{
				LogItem item = DebugOutput::OutputLog();
				if (item.info != "")
				{
					DebugFile::Write(item.info);
					std::cout << item.info << std::endl;
				}
				else
				{
					DebugFile::Write(item.winfo);
					std::wcout << item.winfo << std::endl;
				}
			}
		}
		void DebugSystem::Close()
		{
			_isOpen = false;
			_debugThread.join();
			while (DebugOutput::HasLog())
			{
				LogItem item = DebugOutput::OutputLog();
				if (item.info != "")
				{
					DebugFile::Write(item.info);
					std::cout << item.info << std::endl;
				}
				else
				{
					DebugFile::Write(item.winfo);
					std::wcout << item.winfo << std::endl;
				}
			}
			DebugFile::Close();
		}
	}
}