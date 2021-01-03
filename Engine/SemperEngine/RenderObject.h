#ifndef __RENDEROBJECT__
#define __RENDEROBJECT__

#include <memory>
#include "Mathz.h"
#include "LifeContainer.h"
#include "RenderLayer.h"
#include "Mesh.h"
#include "Material.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderObject
		{
		public:

			LifeContainer<RenderObject> mylife;

			RenderLayer layer;

			bool hasMesh;

			bool hasMaterial;

		public:

			RenderObject();

			virtual ~RenderObject();

			virtual std::shared_ptr<Mesh> GetMesh() = 0;

			virtual std::shared_ptr<Material> GetMaterial() = 0;

			virtual Matrix4x4 GetModelMat() = 0;
		};
	}
}
#endif // !RRENDEROBJECT
