#ifndef __OS__
#define __OS__

#include <string>

namespace Semper
{
	class OS
	{
	public:

		static std::string FileName(std::string fullPath)
		{
			auto start = fullPath.rfind('/');
			if (start < 0)
			{
				start = fullPath.rfind('\\');
			}
			if (start < 0)
			{
				throw "Format error.";
			}
			start = start + 1;
			auto end = fullPath.rfind('.');
			if (end < 0)
			{
				return fullPath.substr(start);
			}
			return fullPath.substr(start, end - start);
		}
	};
}

#endif // !__OS__
