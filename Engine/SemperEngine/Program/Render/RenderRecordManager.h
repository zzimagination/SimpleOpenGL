#ifndef __RENDERRECORDMANAGER__
#define __RENDERRECORDMANAGER__

#include <string>

namespace SemperEngine
{
	namespace Core
	{
		class RenderRecordManager
		{
		public:

			static void CreateRecord(std::string name);

			static void StopRecord();
		};
	}
}

#endif // !__RENDERRECORDMANAGER__
