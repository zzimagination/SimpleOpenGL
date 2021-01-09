#include "ResourceTextureLibrary.h"
#include "ResourceDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		ResourceTextureLibrary::~ResourceTextureLibrary()
		{
		}
		TextureObject* ResourceTextureLibrary::Load(std::string path)
		{
			for (int i = 0; i < (int)_library.Size(); i++)
			{
				if (!_library[i].usable)
				{
					continue;
				}
				if (_library[i].value->filePath == path)
				{
					return _library[i].value;
				}
			}

			auto package = ResourceDataCenter::LoadTexture(path);
			auto object = new TextureObject;
			object->filePath = path;
			object->resourcePackage = package;
			object->Use();
			_library.Add(object);
			return object;
		}
	}
}