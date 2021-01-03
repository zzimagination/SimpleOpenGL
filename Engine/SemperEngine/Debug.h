#ifndef __DEBUG_SCRIPT__
#define __DEBUG_SCRIPT__

#include <string>
#include <initializer_list>

namespace SemperEngine {

	class Debug
	{
	public:

		static void Log(int &message);

		static void Log(float& message);

		static void Log(double& message);

		static void Log(bool& message);

		static void Log(char& message);

		static void Log(std::string& message);

		static void Log(const char* message);

		static void Log(std::wstring& message);

		static void Log(const wchar_t* message);

		static void Log(std::initializer_list<std::string> messages);

		static void LogError(int& message);

		static void LogError(float& message);

		static void LogError(double& message);

		static void LogError(bool& message);

		static void LogError(char& message);

		static void LogError(std::string& message);

		static void LogError(const char* message);

		static void LogError(std::wstring& message);

		static void LogError(const wchar_t* message);

		static void LogError(std::initializer_list<std::string> messages);

	private:


	};

}
#endif // !DEBUG_TOOL
