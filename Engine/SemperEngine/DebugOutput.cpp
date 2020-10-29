#include "DebugOutput.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		mutex DebugOutput::_logLock;

		queue<LogItem> DebugOutput::_logs;

		condition_variable DebugOutput::_waitToHave;

		mutex DebugOutput::_waitLock;

		void DebugOutput::InputLog(LogItem& log)
		{
			lock_guard<mutex> lock(_logLock);
			_logs.push(log);
			Send();
		}

		LogItem DebugOutput::OutputLog()
		{
			unique_lock<mutex> lock(_logLock);
			auto empty = _logs.empty();
			lock.unlock();
			if (empty)
			{
				Wait();
			}

			lock.lock();
			LogItem item = _logs.front();
			_logs.pop();
			return item;
		}

		bool DebugOutput::HasLog()
		{
			lock_guard<mutex> lock(_logLock);
			return _logs.size() > 0;
		}

		void DebugOutput::Wait()
		{
			unique_lock<mutex> wait(_waitLock);
			_waitToHave.wait(wait);
		}

		void DebugOutput::Send()
		{
			unique_lock<mutex> wait(_waitLock);
			_waitToHave.notify_one();
		}
	}
}