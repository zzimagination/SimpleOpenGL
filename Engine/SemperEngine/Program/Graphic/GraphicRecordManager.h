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

			static std::vector<std::shared_ptr<GraphicRecord>> _recordListA;

			static std::vector<std::shared_ptr<GraphicRecord>> _recordListB;

			static bool _isRenderA;

			//static std::map<std::string, GraphicRecord> 

		public:

			static GraphicRecord* CreateRecord(std::string name);

			static GraphicRecord* GetRecord(int id);

			static GraphicRecord* GetRecord(std::string name);

			static std::vector<GraphicRecord*> GetExecuteList();

			static void Clear();

			static void Swap();
		};
	}
}
#endif // !__GRAPHIC_RECORDMANAGER__
