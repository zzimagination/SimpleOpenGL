#ifndef __RENDERBATCH__
#define __RENDERBATCH__

#include <vector>
#include <memory>
#include "Mathz.h"
#include "VertexDataCenter.h"
#include "Material.h"

namespace SemperEngine {

	namespace Core
	{
		class RenderBatch
		{
		public:

			bool screenDraw;

			ResourcePackage<VertexData> vertexData;

			Matrix4x4 modelMatrix;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectionMatrix;

			std::shared_ptr<Material> material;
		};
	}
}
#endif // !RENDERBATCH




