#include "StringEncoding.h"
#include "WindowsText.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Text;

	string StringEncoding::UnicodeToUTF8(const wstring & wstr)
	{
		auto result = GWinText::UnicodeToUTF8(wstr);
		return result;
	}

	wstring StringEncoding::UTF8ToUnicode(const string & str)
	{
		auto result = GWinText::UTF8ToUnicode(str);
		return result;
	}

	string StringEncoding::UnicodeToANSI(const wstring & wstr)
	{
		auto result = GWinText::UnicodeToANSI(wstr);
		return result;
	}

	wstring StringEncoding::ANSIToUnicode(const string & str)
	{
		auto result = GWinText::ANSIToUnicode(str);
		return result;
	}
}