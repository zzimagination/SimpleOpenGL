#include "ResourceTextureLibrary.h"
#include "NativeResource.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourceTextureLibrary::~ResourceTextureLibrary()
		{
		}
		TextureObject* ResourceTextureLibrary::Load(std::string path)
		{
			for (int i = 0; i < (int)_library.Size(); i++)
			{
				if (_library.IsEmpty(i))
				{
					continue;
				}
				if (_library[i]->filePath == path)
				{
					return _library[i];
				}
			}

			auto resource = NativeResource::LoadTexture(path);
			auto object = new TextureObject;
			object->filePath = path;
			object->name = OS::FileName(resource.path);
			object->pixels = ArrayList<ColorByte>(resource.data, resource.size);
			object->width = resource.width;
			object->height = resource.height;
			object->id = _library.Add(object);
			object->Use();
			return object;
		}
	}
}