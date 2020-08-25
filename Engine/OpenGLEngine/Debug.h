#ifndef DEBUG_SCRIPT
#define DEBUG_SCRIPT

#include <string>

namespace SemperEngine {

	class GameObject;

	class Debug
	{
	public:

		static void Log(int message);

		static void Log(float message);

		static void Log(double message);

		static void Log(bool message);

		static void Log(char message);

		static void Log(std::string message);

	};

}
#endif // !DEBUG_TOOL
