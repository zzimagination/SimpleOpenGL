#ifndef __GRAPHIC_RECORDMANAGER__
#define __GRAPHIC_RECORDMANAGER__

#include "Graphic.h"
#include "GraphicRecord.h"
#include <memory>
#include <map>

namespace Semper
{
	namespace Core
	{
		class GraphicRecordManager
		{
		private:

			static FillList<GraphicRecord*> _records;

		public:

			static int CreateRecord(int msaa);

			static void StartRecord(int id);

			static void StopRecord(int id);

			static void DeleteRecord(int id);

			static GraphicRecord* GetRecord(int id);

		private:

			static void DeleteRecordFunc(GraphicRecord* record);
		};
	}
}
#endif // !__GRAPHIC_RECORDMANAGER__
