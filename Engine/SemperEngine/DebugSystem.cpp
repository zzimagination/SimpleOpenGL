#include "DebugSystem.h"
#include <iostream>
#include "Time.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		thread DebugSystem::_debugThread;

		bool DebugSystem::_isOpen = false;

		shared_ptr<DebugFile> DebugSystem::_file;

		void DebugSystem::Initialization()
		{
			_isOpen = true;
			_debugThread = thread(Start);
		}

		void DebugSystem::Start()
		{
			_file = DebugFile::Open();
			return Update();
		}

		void DebugSystem::Update()
		{
			while (_isOpen)
			{
				LogItem item = DebugOutput::OutputLog();
				OutputItem(item);
			}
		}

		void DebugSystem::Close()
		{
			_isOpen = false;
			LogItem item(Time::SystemTime());
			DebugOutput::InputLog(item);
			_debugThread.join();
			while (DebugOutput::HasLog())
			{
				LogItem item = DebugOutput::OutputLog();
				OutputItem(item);
			}
			_file->Close();
		}

		void DebugSystem::OutputItem(LogItem item)
		{
			string time = "[";
			time.append(item.time);
			time.append("]:");
			_file->Write(time);
			cout << time;
			if (item.info != "")
			{
				_file->WriteLine(item.info);
				cout << item.info << endl;
			}
			else
			{
				_file->WriteLine(item.winfo);
				wcout << item.winfo << endl;
			}
		}
	}
}