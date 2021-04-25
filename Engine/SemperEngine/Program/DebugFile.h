#ifndef __DEBUG_FILE__
#define __DEBUG_FILE__

#include <string>
#include <fstream>
#include <string>
#include <memory>

namespace Semper
{
	namespace Core
	{
		constexpr const char* logFolder = "Log";

		constexpr const char* logFile = "log.text";

		class DebugFile
		{
		private:

			std::fstream _file;

			bool isOpen;

		public:

			static std::shared_ptr<DebugFile> Open();

			static std::shared_ptr<DebugFile> Open(std::string file);

		public:

			void Close();

			void Write(std::string& log);

			void Write(std::wstring& log);

			void WriteLine(std::string& log);

			void WriteLine(std::wstring& log);

			void WriteLine();

			void Flush();
		};
	}
}

#endif // !DEBUG_FILE
