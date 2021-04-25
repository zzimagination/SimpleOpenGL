#ifndef __RENDERRECORDMANAGER__
#define __RENDERRECORDMANAGER__

#include <map>
#include "../CameraObject.h"
#include "Render.h"

namespace Semper
{
	namespace Core
	{
		struct RenderRecord
		{
			int graphicID = -1;
		};

		class RenderRecordManager
		{
		private:

			static std::map<CameraObject*, std::map<std::string, RenderRecord>> _recordMap;

			static RenderRecord* _current;

		public:

			static void CreateRecord(std::string key, CameraObject* camera);

			static void CreateRecord(std::string key, CameraObject* camera, Render::MSAA msaa);

			static void StartRecord(std::string key, CameraObject* camera);

			static void StopRecord();

			static RenderRecord GetRecord(std::string key, CameraObject* camera);

		private:

		};
	}
}

#endif // !__RENDERRECORDMANAGER__
