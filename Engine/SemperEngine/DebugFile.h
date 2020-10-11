#ifndef __DEBUG_FILE__
#define __DEBUG_FILE__
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
		};
	}
}

#endif // !DEBUG_FILE
