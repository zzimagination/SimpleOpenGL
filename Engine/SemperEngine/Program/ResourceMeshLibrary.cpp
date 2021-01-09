#include "ResourceMeshLibrary.h"

namespace SemperEngine
{
	namespace Core
	{
		ResourceMeshLibrary::~ResourceMeshLibrary()
		{
		}
		MeshObject* ResourceMeshLibrary::ScreenObject()
		{
			if (_screen == nullptr)
			{
				_screen = MeshObject::CreateRectangle();
			}
			return _screen;
		}
	}
}