#include "DebugFile.h"
#include <iostream>
#include <filesystem>
#include "StringEncoding.h"

namespace SemperEngine {

	namespace Core
	{
		using namespace std;
		using namespace std::filesystem;

		shared_ptr<DebugFile> DebugFile::Open()
		{
			string path(logFolder);
			path.append("/");
			path.append(logFile);
			return Open(path);
		}

		shared_ptr<DebugFile> DebugFile::Open(std::string file)
		{
			if (!exists(logFolder))
			{
				create_directory(logFolder);
			}
			auto ptr = shared_ptr<DebugFile>(new DebugFile());
			ptr->isOpen = true;
			ptr->_file.open(file, fstream::out);
			return ptr;
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

		void DebugFile::Write(std::string& log)
		{
			if (!isOpen)
			{
				return;
			}

			wstring un = StringEncoding::ANSIToUnicode(log);
			string u8 = StringEncoding::UnicodeToUTF8(un);
			_file.write(u8.data(), u8.size());
		}

		void DebugFile::Write(std::wstring& log)
		{
			if (!isOpen)
			{
				return;
			}

			string u8 = StringEncoding::UnicodeToUTF8(log);
			_file.write(u8.data(), u8.size());
		}
		void DebugFile::WriteLine(std::string& log)
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
		void DebugFile::WriteLine(std::wstring& log)
		{
			if (!isOpen)
			{
				return;
			}
			string u8 = StringEncoding::UnicodeToUTF8(log);
			_file.write(u8.data(), u8.size());
			_file.write("\r", 1);
		}
		void DebugFile::WriteLine()
		{
			if (!isOpen)
			{
				return;
			}
			_file.write("\r", 1);
		}
	}
}