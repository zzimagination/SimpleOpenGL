#include "MeshObject.h"

namespace SemperEngine
{
	namespace Core
	{
		MeshObject::MeshObject()
		{
		}
		MeshObject::MeshObject(bool share) : ResourceObject(share)
		{
		}
		MeshObject::MeshObject(bool share, Setting setting) : ResourceObject(share)
		{
			readOnly = setting.readOnly;
		}
		MeshObject::~MeshObject()
		{
		}
	}
}