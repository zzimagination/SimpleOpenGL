#ifndef __RENDERRECORDMANAGER__
#define __RENDERRECORDMANAGER__

#include "../CameraObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderRecord
		{
		public:

			CameraObject* camera = nullptr;

			std::string name;

			int graphicID = 0;

		public:

			RenderRecord();

			RenderRecord(CameraObject* camera, std::string name);

			bool operator==(const RenderRecord& record);
		};

		class RenderRecordManager
		{
		private:

			static std::vector<RenderRecord> _records;

		public:

			static void CreateRecord(std::string name, CameraObject* camera);

			static void StopRecord();

			static std::vector<int> GetGraphicRecords(std::vector<RenderRecord> records);
		};
	}
}

#endif // !__RENDERRECORDMANAGER__
