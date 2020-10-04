#include "DebugOutput.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		mutex DebugOutput::_logLock;

		queue<LogItem> DebugOutput::_logs;

		void DebugOutput::InputLog(LogItem log)
		{
			lock_guard<mutex> lock(_logLock);
			_logs.push(log);
		}

		LogItem DebugOutput::OutputLog()
		{
			lock_guard<mutex> lock(_logLock);
			LogItem item = _logs.front();
			_logs.pop();
			return item;
		}
		bool DebugOutput::HasLog()
		{
			lock_guard<mutex> lock(_logLock);
			return _logs.size() > 0;
		}
	}
}