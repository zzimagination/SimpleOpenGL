#ifndef __RENDEROBJECT__
#define __RENDEROBJECT__

#include <memory>
#include "Mathz.h"
#include "Material.h"
#include "LifeContainer.h"
#include "VertexDataCenter.h"
#include "VertexData.h"

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

			int layer;

		public:

			RenderObject();

			~RenderObject();

		};
	}
}
#endif // !RRENDEROBJECT
