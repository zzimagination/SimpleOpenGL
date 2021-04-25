#include "DebugSystem.h"
#include <iostream>
#include "Time.h"

namespace Semper
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
			_debugThread = thread(DebugThread);
		}

		void DebugSystem::DebugThread()
		{
			_file = DebugFile::Open();
			while (_isOpen)
			{
				LogItem item = DebugOutput::OutputLog();
				OutputItem(item);
			}
		}

		void DebugSystem::Close()
		{
			LogItem item(Time::SystemTime());
			item.info = "Game End.";
			DebugOutput::InputLog(item);
			_isOpen = false;
			_debugThread.join();

			while (true)
			{
				if (!DebugOutput::HasLog())
				{
					break;
				}
				auto log = DebugOutput::OutputLog();
				OutputItem(log);
			}

			_file->Close();
		}

		void DebugSystem::OutputItem(LogItem item)
		{
			string time = "[";
			time.append(item.time);
			time.append("]:");
			_file->Write(time);
			if (item.info != "")
			{
				_file->WriteLine(item.info);
			}
			else
			{
				_file->WriteLine(item.winfo);
			}
			if (item.type == LogItem::Type::Error)
			{
				_file->Flush();
			}
		}
	}
}