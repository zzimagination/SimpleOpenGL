#include "NativeResource.h"
#include "ResourceLoader.h"


namespace Semper
{
	namespace Core
	{
		TextureLib::Texture NativeResource::LoadTexture(std::string path)
		{
			TextureLoader loader;
			return loader.Load(path); 
		}
		ModelLib::Model NativeResource::LoadModel(std::string path)
		{
			ModelLoader loader;
			return loader.Load(path);
		}
	}
}