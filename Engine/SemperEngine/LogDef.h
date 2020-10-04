#pragma once
#ifndef LOG_DEF
#define LOG_DEF

#include<string>

namespace SemperEngine
{
	namespace Core
	{

		constexpr const char* logFolder = "Log/";

		constexpr const char* logPath = "Log/log.text";

		class LogItem
		{
		public:

			std::string info;

			std::wstring winfo;
		};
	}
}


#endif // !LOG_DEF
