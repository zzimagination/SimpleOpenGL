#ifndef RRENDEROBJECT
#define RRENDEROBJECT

#include "Mathz.h"
#include "Material.h"
#include "LifeContainer.h"
#include "ResourcePackage.h"
#include "VertexData.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderObject
		{
		public:

			ResourcePackage<VertexData> vertexData;

			Matrix4x4 modelMatrix;

			Material* material;

			LifeContainer<RenderObject> mylife = LifeContainer<RenderObject>(this);

		public:

			RenderObject();

			~RenderObject();

		};
	}
}
#endif // !RRENDEROBJECT
