#pragma once
#ifndef __CAMERA_COLLECTION__
#define __CAMERA_COLLECTION__

#include "CameraObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class CameraCollection
		{
		private:

			static std::vector<LifeContainer<CameraObject>> _cameras;

		public:

			static void AddCamera(LifeContainer<CameraObject> camera);

			static std::vector<CameraObject*> GetCameras();

			static void ClearCameras();
		};
	}
}

#endif // !CAMERA_COLLECTION
