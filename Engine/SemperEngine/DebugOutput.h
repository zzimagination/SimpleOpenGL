#ifndef __DEBUG_OUTPUT__
#define __DEBUG_OUTPUT__

#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>

namespace SemperEngine
{
	namespace Core
	{
		class LogItem
		{
		public:

			enum class Type
			{
				Debug,

				Error
			};

		public:

			std::string info;

			std::wstring winfo;

			std::string time;

			Type type;

			LogItem(std::string time)
			{
				info = "";
				winfo = L"";
				this->time = time;
				this->type = Type::Debug;
			}

			LogItem(std::string time, Type t)
			{
				info = "";
				winfo = L"";
				this->time = time;
				this->type = t;
			}
		};

		class DebugOutput
		{
		private:

			static std::mutex _logLock;

			static std::queue<LogItem> _logs;

			static std::condition_variable _waitToHave;

			static std::mutex _waitLock;

		public:

			static void InputLog(LogItem log);

			static LogItem OutputLog();

			static bool HasLog();

			static void Close();

		private:

			static void Wait();

			static void Send();
		};
	}
}

#endif // !DEBUG_OUTPUT
