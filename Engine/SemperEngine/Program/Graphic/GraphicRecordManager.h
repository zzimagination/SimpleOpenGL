#ifndef __GRAPHIC_RECORDMANAGER__
#define __GRAPHIC_RECORDMANAGER__

#include "../Common.h"
#include "GraphicRecord.h"
#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		class GraphicRecordManager
		{
		public:

			static GraphicRecord* lastRecord;

			static GraphicRecord* currentRecord;

		private:

			static std::vector<std::shared_ptr<GraphicRecord>> _recordListA;

			static std::vector<std::shared_ptr<GraphicRecord>> _recordListB;

			static bool _isRenderA;

		public:

			static GraphicRecord* CreateRecord(std::string name);

			static GraphicRecord* GetRecord(int id);

			static GraphicRecord* GetRecord(std::string name);

			static std::vector<GraphicRecord*> GetExecuteList();

			static void Clear();
		};
	}
}
#endif // !__GRAPHIC_RECORDMANAGER__
