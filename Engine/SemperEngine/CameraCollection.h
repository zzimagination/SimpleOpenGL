#pragma once
#ifndef __CAMERA_COLLECTION__
#define __CAMERA_COLLECTION__

#include "Camera.h"

namespace SemperEngine
{
	namespace Core
	{
		class CameraCollection
		{
		private:

			static std::vector<LifeContainer<GameObject>> _cameras;

		public:

			static void AddCamera(LifeContainer<GameObject> camera);

			static std::vector<Camera*> GetCameras();

			static void ClearCameras();
		};
	}
}

#endif // !CAMERA_COLLECTION
