#ifndef INTERFACE_LOG
#define INTERFACE_LOG

#include <string>
namespace SemperEngine {
	class ILog
	{
	public:

		virtual std::string ConvertToLog() = 0;
	};
}

#endif // !LOGINTERFACE
