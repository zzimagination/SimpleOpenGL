#pragma once
#ifndef __LOG_DEF__
#define __LOG_DEF__

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
