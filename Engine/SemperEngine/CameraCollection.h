#pragma once
#ifndef CAMERA_COLLECTION
#define CAMERA_COLLECTION

#include <vector>
#include <memory>
#include "LifeContainer.h"
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
