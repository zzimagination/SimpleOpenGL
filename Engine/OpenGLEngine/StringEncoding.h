#ifndef STRINGENCODING
#define STRINGENCODING

#include <string>

namespace SemperEngine {

	using namespace std;

	class StringEncoding
	{
	public:

		static string UnicodeToUTF8(const wstring& wstr);

		static wstring UTF8ToUnicode(const string& str);

		static string UnicodeToANSI(const wstring& wstr);

		static wstring ANSIToUnicode(const string& str);
	};
}
#endif // !STRINGENCODING
