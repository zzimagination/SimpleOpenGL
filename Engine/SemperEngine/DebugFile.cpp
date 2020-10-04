#include "DebugFile.h"
#include <iostream>
#include <filesystem>
#include "StringEncoding.h"
#include "LogDef.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;
		using namespace std::filesystem;

		fstream DebugFile::_file;

		bool DebugFile::isOpen = false;

		void DebugFile::Open()
		{
			if (!exists(logFolder))
			{
				create_directory(logFolder);
			}

			_file.open(logPath, std::fstream::out);
			isOpen = true;
		}

		void DebugFile::Close()
		{
			if (!isOpen)
			{
				return;
			}
			if (_file.is_open())
			{
				_file.close();
			}
		}

		void DebugFile::Write(std::string log)
		{
			if (!isOpen)
			{
				return;
			}

			wstring un = StringEncoding::ANSIToUnicode(log);
			string u8 = StringEncoding::UnicodeToUTF8(un);
			_file.write(u8.data(), u8.size());
			_file.write("\r", 1);
		}

		void DebugFile::Write(std::wstring log)
		{
			if (!isOpen)
			{
				return;
			}

			string u8 = StringEncoding::UnicodeToUTF8(log);
			_file.write(u8.data(), u8.size());
			_file.write("\r", 1);
		}

		void DebugFile::Flush()
		{
			if (!isOpen)
			{
				return;
			}
			_file.flush();
		}
	}
}