#pragma once
#ifndef __CAMERA_COLLECTION__
#define __CAMERA_COLLECTION__

#include "CameraObject.h"

namespace Semper
{
	namespace Core
	{
		class CameraCollection
		{
		private:

			static std::vector<LifeContainer<RenderObject>> _cameras;

		public:

			static void AddCamera(CameraObject* camera);

			static std::vector<CameraObject*> GetCameras();

			static void ClearCameras();
		};
	}
}

#endif // !CAMERA_COLLECTION
