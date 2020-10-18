#include "CameraCollection.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<CameraObject>> CameraCollection::_cameras;

		void CameraCollection::AddCamera(LifeContainer<CameraObject> camera)
		{
			if (WorldManager::Inside())
			{
				return;
			}
			_cameras.push_back(camera);
		}

		vector<CameraObject*> CameraCollection::GetCameras()
		{
			vector<CameraObject*> result;
			for (int i = 0; i < _cameras.size(); i++)
			{
				if (_cameras[i].life)
				{
					result.push_back(_cameras[i].self);
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