#include "CameraCollection.h"
#include "WorldManager.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		vector<LifeContainer<GameObject>> CameraCollection::_cameras;

		void CameraCollection::AddCamera(LifeContainer<GameObject> camera)
		{
			if (WorldManager::Inside())
			{
				return;
			}
			_cameras.push_back(camera);
		}

		vector<Camera*> CameraCollection::GetCameras()
		{
			vector<Camera*> result;
			for (int i = 0; i < _cameras.size(); i++)
			{
				if (_cameras[i].life)
				{
					result.push_back((Camera*)_cameras[i].self);
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