#ifndef __DEBUG_SYSTEM__
#define __DEBUG_SYSTEM__

#include <thread>

namespace SemperEngine {

	namespace Core
	{
		class DebugSystem
		{
		private:

			static std::thread _debugThread;

			static bool _isOpen;

			static std::chrono::milliseconds _time;

		public:

			static void Initialization();

			static void Start();

			static void Update();

			static void Close();
		};
	}
}
#endif // !DEBUG_SYSTEM
