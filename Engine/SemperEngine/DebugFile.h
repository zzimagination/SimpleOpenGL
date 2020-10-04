#ifndef DEBUG_FILE
#define DEBUG_FILE
#include <string>
#include <fstream>
#include <string>

namespace SemperEngine
{
	namespace Core {
		class DebugFile
		{
		private:

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
}

#endif // !DEBUG_FILE
