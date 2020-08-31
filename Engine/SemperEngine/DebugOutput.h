#ifndef DEBUG_OUTPUT
#define DEBUG_OUTPUT

#include <string>
#include <mutex>
#include <queue>
#include "LogItem.h"

namespace SemperEngine
{
	class DebugOutput
	{
	private:

		static std::mutex _logLock;

		static std::queue<LogItem> _logs;

	public:

		static void InputLog(LogItem log);

		static LogItem OutputLog();

		static bool HasLog();
	};
}

#endif // !DEBUG_OUTPUT
