#ifndef DEBUG_SYSTEM
#define DEBUG_SYSTEM

#include <thread>

namespace SemperEngine {

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
#endif // !DEBUG_SYSTEM
