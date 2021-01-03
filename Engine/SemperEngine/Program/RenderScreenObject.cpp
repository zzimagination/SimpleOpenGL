#include "RenderScreenObject.h"

namespace SemperEngine
{
	namespace Core
	{
		RenderScreenObject::RenderScreenObject()
		{
			hasMesh = false;
			hasMaterial = true;
		}
		RenderScreenObject::~RenderScreenObject()
		{
		}

		std::shared_ptr<Mesh> RenderScreenObject::GetMesh()
		{
			return std::shared_ptr<Mesh>();
		}
		std::shared_ptr<Material> RenderScreenObject::GetMaterial()
		{
			return material;
		}
		Matrix4x4 RenderScreenObject::GetModelMat()
		{
			return Matrix4x4();
		}
	}
}