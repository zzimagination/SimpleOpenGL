#include "StringEncoding.h"

#include <Windows.h>

#include <codecvt>
#include <memory>



namespace SemperEngine
{
	using namespace std;

	string StringEncoding::UnicodeToUTF8(const wstring & wstr)
	{
		
		//wstring_convert<codecvt_utf8<wchar_t>> convert;
		//string result = convert.to_bytes(wstr);
		
		const wchar_t* data = wstr.data();
		size_t size = wstr.size();
		size_t bufferSize = WideCharToMultiByte(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, nullptr, 0, NULL, NULL);
		char *buffer = new char[bufferSize];
		WideCharToMultiByte(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, buffer, bufferSize, NULL, NULL);
		string result = buffer;
		delete[] buffer;
		return result;
	}

	wstring StringEncoding::UTF8ToUnicode(const string & str)
	{
		/*wstring_convert<codecvt_utf8<wchar_t>> convert;
		wstring result = convert.from_bytes(str);*/

		const char* data = str.data();
		size_t size = str.size();
		size_t bufferSize = MultiByteToWideChar(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, nullptr, 0);
		wchar_t* buffer = new wchar_t[bufferSize];
		MultiByteToWideChar(CP_UTF8, WC_NO_BEST_FIT_CHARS, data, -1, buffer, bufferSize);
		wstring result = buffer;
		delete[] buffer;
		return result;
	}

	string StringEncoding::UnicodeToANSI(const wstring & wstr)
	{
		const wchar_t * p = wstr.data();
		mbstate_t mbs = {};
		size_t* size = new size_t;
		if (wcsrtombs_s(size, nullptr, 0, &p, 0, &mbs) != 0)
		{
			return string();
		}

		char *buffer = new char[*size + 1];
		if (wcsrtombs_s(size, buffer, *size + 1, &p, *size, &mbs) != 0)
		{
			return string();
		}
		string result = buffer;

		delete[] buffer;
		delete size;
		return result;
	}

	wstring StringEncoding::ANSIToUnicode(const string & str)
	{
		//setlocale(LC_CTYPE, "");
		const char* p = str.data();
		mbstate_t mbs = {};
		size_t* size = new size_t;
		if (mbsrtowcs_s(size, nullptr, 0, &p, 0, &mbs) != 0)
		{
			return wstring();
		}

		wchar_t* buffer = new wchar_t[*size + 1];
		if (mbsrtowcs_s(size, buffer, *size+1, &p, *size, &mbs) != 0)
		{
			return wstring();
		}
		wstring result = buffer;

		delete[] buffer;
		delete size;
		return result;
	}
}