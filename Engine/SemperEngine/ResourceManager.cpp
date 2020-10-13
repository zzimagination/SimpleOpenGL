#include "ResourceManager.h"
#include "VertexDataCenter.h"
#include "TextureDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		void ResourceManager::Collection()
		{
			VertexDataCenter::UnloadUnse();
			TextureDataCenter::UnloadUnuse();
		}
	}
}