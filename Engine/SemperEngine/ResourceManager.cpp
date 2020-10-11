#include "ResourceManager.h"
#include "VertexDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		void ResourceManager::Collection()
		{
			VertexDataCenter::UnloadNoUse();
		}
	}
}