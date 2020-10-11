#ifndef __STRINGENCODING__
#define __STRINGENCODING__

#include <string>

namespace SemperEngine 
{
	class StringEncoding
	{
	public:

		static std::string UnicodeToUTF8(const std::wstring& wstr);

		static std::wstring UTF8ToUnicode(const std::string& str);

		static std::string UnicodeToANSI(const std::wstring& wstr);

		static std::wstring ANSIToUnicode(const std::string& str);
	};
}
#endif // !STRINGENCODING
