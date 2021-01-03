#pragma once
#ifndef __RENDERCUSTOMOBJECT__
#define __RENDERCUSTOMOBJECT__

#include <memory>
#include "Mesh.h"
#include "Material.h"
#include "RenderObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class RenderCustomObject : public RenderObject
		{
		public:

			std::shared_ptr<Mesh> mesh;

			Matrix4x4 modelMat;

			std::shared_ptr<Material> material;

		public:

			RenderCustomObject();

			virtual ~RenderCustomObject() override;

			virtual std::shared_ptr<Mesh> GetMesh() override;

			virtual std::shared_ptr<Material> GetMaterial() override;

			virtual Matrix4x4 GetModelMat() override;

		};
	}
}

#endif // !__RENDERCUSTOMOBJECT__
