#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include "Mathz.h"
#include "ResourcePackage.h"
#include "VertexData.h"
#include "Material.h"
namespace SemperEngine {

	namespace Core
	{
		class RenderBatch
		{
		public:

			ResourcePackage<VertexData> vertexData;

			Matrix4x4 modelMatrix;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectionMatrix;

			Material* material;
		};
	}
}
#endif // !RENDERBATCH




