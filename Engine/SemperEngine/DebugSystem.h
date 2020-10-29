#ifndef __DEBUG_SYSTEM__
#define __DEBUG_SYSTEM__

#include <memory>
#include <chrono>
#include <thread>
#include <condition_variable>
#include "DebugFile.h"
#include "DebugOutput.h"

namespace SemperEngine {

	namespace Core
	{
		class DebugSystem
		{
		private:

			static std::thread _debugThread;

			static bool _isOpen;

			static std::shared_ptr<DebugFile> _file;

		public:

			static void Initialization();

			static void Start();

			static void Update();

			static void Close();

		private:

			static void OutputItem(LogItem item);
		};
	}
}
#endif // !DEBUG_SYSTEM
