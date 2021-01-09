#include "CameraCollection.h"
#include "WorldManager.h"
#include "Debug.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<RenderObject>> CameraCollection::_cameras;

		void CameraCollection::AddCamera(CameraObject* camera)
		{
			if (camera == nullptr)
			{
				Debug::LogError("camera is null");
				return;
			}
			if (WorldManager::Inside())
			{
				return;
			}
			auto life = camera->mylife;
			_cameras.push_back(life);
		}

		vector<CameraObject*> CameraCollection::GetCameras()
		{
			vector<CameraObject*> result;
			for (int i = 0; i < _cameras.size(); i++)
			{
				auto camera = _cameras[i];
				if (camera.Life())
				{
					result.push_back((CameraObject*)camera.self);
				}
			}
			return result;
		}

		void CameraCollection::ClearCameras()
		{
			_cameras.clear();
		}
	}
}