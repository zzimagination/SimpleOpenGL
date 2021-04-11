#ifndef __GRAPHIC_RECORDMANAGER__
#define __GRAPHIC_RECORDMANAGER__

#include "Graphic.h"
#include "GraphicRecord.h"
#include <memory>
#include <map>

namespace SemperEngine
{
	namespace Core
	{
		class GraphicRecordManager
		{
		private:

			static std::vector<GraphicRecord*> _tempRecords;

			static std::vector<GraphicRecord*> _inUseRecords;

		public:

			static int CreateRecord(std::string name);

			static void StopRecord();

			static GraphicRecord* UseRecord(int id);

			static void Clear();

			static void Swap();
		};
	}
}
#endif // !__GRAPHIC_RECORDMANAGER__
