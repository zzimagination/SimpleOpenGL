#ifndef DEBUG_FILE
#define DEBUG_FILE
#include <string>
#include <fstream>
#include <string>

namespace SemperEngine
{
	class DebugFile
	{
	private:

		static const char* logFolder;

		static const char* logPath;

		static std::fstream _file;

		static bool isOpen;

	public:

		static void Open();

		static void Close();

		static void Write(std::string log);

		static void Write(std::wstring log);

		static void Flush();
	};
}

#endif // !DEBUG_FILE
