#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include "Mathz.h"
#include "RenderVertexData.h"
#include "Material.h"
namespace SemperEngine {

	class RenderBatch
	{
	public:

		RenderVertexData *vertexData;

		Matrix4x4 modelMatrix;

		Matrix4x4 viewMatrix;

		Matrix4x4 projectionMatrix;

		Material* material;
	};
}
#endif // !RENDERBATCH




