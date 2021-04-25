#include "ResourceLoader.h"
#include "Debug.h"

namespace Semper
{
	namespace Core
	{
		using namespace std;

		TextureLib::Texture TextureLoader::Load(std::string path)
		{
			auto file = TextureLib::LoadTexture(path);
			if (file.error == "")
			{
				return file;
			}
			Debug::LogError(file.error);
			return file;
		}

		ModelLib::Model ModelLoader::Load(std::string path)
		{
			auto file = ModelLib::LoadObject(path);
			if (file.error == "")
			{
				if (file.warning != "")
				{
					Debug::Log(file.warning);
				}
				return file;
			}
			Debug::LogError(file.error);
			return file;
		}
	}
}