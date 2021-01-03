#pragma once
#ifndef __GWIN32_TEXT__
#define __GWIN32_TEXT__

#include <string>

namespace SemperEngine
{
	namespace Text
	{
		class GWinText
		{
		public:

			static std::string UnicodeToUTF8(const std::wstring& wstr);

			static std::wstring UTF8ToUnicode(const std::string& str);

			static std::string UnicodeToANSI(const std::wstring& wstr);

			static std::wstring ANSIToUnicode(const std::string& str);
		};
	}
}

#endif // !WIN32_TEXT
