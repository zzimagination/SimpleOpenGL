#include "WindowsText.h"
#include <codecvt>
#include <memory>
#include <Windows.h>

namespace SemperEngine
{
	namespace Text
	{
		using namespace std;

		string GWinText::UnicodeToUTF8(const wstring& wstr)
		{
			//wstring_convert<codecvt_utf8<wchar_t>> convert;
			//string result = convert.to_bytes(wstr);
			const wchar_t* data = wstr.data();
			size_t size = wstr.size();
			size_t bufferSize = WideCharToMultiByte(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, nullptr, 0, NULL, NULL);
			unique_ptr<char> buffer2(new char[bufferSize]);
			WideCharToMultiByte(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, buffer2.get(), (int)bufferSize, NULL, NULL);
			string result = buffer2.get();
			return result;
		}

		wstring GWinText::UTF8ToUnicode(const string& str)
		{
			/*wstring_convert<codecvt_utf8<wchar_t>> convert;
			wstring result = convert.from_bytes(str);*/
			const char* data = str.data();
			size_t size = str.size();
			size_t bufferSize = MultiByteToWideChar(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, nullptr, 0);
			unique_ptr<wchar_t> buffer2(new wchar_t[bufferSize]);
			MultiByteToWideChar(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, buffer2.get(), (int)bufferSize);
			wstring result = buffer2.get();
			return result;
		}

		string GWinText::UnicodeToANSI(const wstring& wstr)
		{
			const wchar_t* p = wstr.data();
			mbstate_t mbs = {};

			unique_ptr<size_t> size2(new size_t);
			if (wcsrtombs_s(size2.get(), nullptr, 0, &p, 0, &mbs) != 0)
			{
				return string();
			}

			unique_ptr<char> buffer2(new char[*size2.get() + 1]);
			if (wcsrtombs_s(size2.get(), buffer2.get(), *size2.get() + 1, &p, *size2.get(), &mbs) != 0)
			{
				return string();
			}
			string result = buffer2.get();
			return result;
		}

		wstring GWinText::ANSIToUnicode(const string& str)
		{
			//setlocale(LC_CTYPE, "");
			const char* p = str.data();
			mbstate_t mbs = {};

			unique_ptr<size_t> size2(new size_t);
			if (mbsrtowcs_s(size2.get(), nullptr, 0, &p, 0, &mbs) != 0)
			{
				return wstring();
			}

			unique_ptr<wchar_t> buffer2(new wchar_t[*size2.get() + 1]);
			if (mbsrtowcs_s(size2.get(), buffer2.get(), *size2.get() + 1, &p, *size2.get(), &mbs) != 0)
			{
				return wstring();
			}
			wstring result = buffer2.get();
			return result;
		}
	}
}