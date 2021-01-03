#include "RenderCustomObject.h"

namespace SemperEngine
{
	namespace Core
	{
		RenderCustomObject::RenderCustomObject()
		{
			hasMesh = true;
			hasMaterial = true;
		}
		RenderCustomObject::~RenderCustomObject()
		{
		}
		std::shared_ptr<Mesh> RenderCustomObject::GetMesh()
		{
			return mesh;
		}
		std::shared_ptr<Material> RenderCustomObject::GetMaterial()
		{
			return material;
		}
		Matrix4x4 RenderCustomObject::GetModelMat()
		{
			return modelMat;
		}
	}
}