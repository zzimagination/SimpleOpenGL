#ifndef RRENDEROBJECT
#define RRENDEROBJECT

#include "Mathz.h"
#include "Material.h"
#include "RenderVertexData.h"
#include "LifeContainer.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderObject
		{
		public:

			RenderVertexData* renderVertex;

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
