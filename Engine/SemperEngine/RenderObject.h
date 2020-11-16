#ifndef __RENDEROBJECT__
#define __RENDEROBJECT__

#include <memory>
#include "Mathz.h"
#include "Material.h"
#include "Mesh.h"
#include "LifeContainer.h"
#include "VertexDataCenter.h"
#include "RenderLayer.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderObject
		{
		public:

			std::shared_ptr<Mesh> vertexData;

			Matrix4x4 modelMatrix;

			std::shared_ptr<Material> material;

			LifeContainer<RenderObject> mylife;

			RenderLayer layer;

		public:

			RenderObject();

			~RenderObject();

		};
	}
}
#endif // !RRENDEROBJECT
