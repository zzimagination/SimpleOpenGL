#pragma once
#ifndef GRAPHICCMD_DRAW
#define GRAPHICCMD_DRAW

#include <vector>
#include "ShaderProperty.h"
#include "GraphicCommand.h"
#include "Mathz.h"
#include "Material.h"

namespace SemperEngine
{
	class RenderVertexData;
	class Texture;
	class GraphicShader;
	class RenderBatch;

	namespace Core
	{
		class GraphicDraw : public GraphicCommand 
		{
		public:

			RenderVertexData* vertexData;

			std::vector<Texture*> textureList;

			Matrix4x4 modelMatrix;

			Matrix4x4 viewMatrix;

			Matrix4x4 projectionMatrix;

			Material* material;

		public:

			GraphicDraw(RenderBatch batch);

			virtual void Excute() override;
		};
	}
}

#endif // !GRAPHICCMD_DRAW
