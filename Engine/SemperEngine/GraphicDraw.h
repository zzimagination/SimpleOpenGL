#pragma once
#ifndef GRAPHICCMD_DRAW
#define GRAPHICCMD_DRAW

#include "GraphicCommand.h"
#include "GraphicCommandData.h"
#include "RenderBatch.h"
#include "Material.h"

namespace SemperEngine
{

	namespace Core
	{
		class GraphicDraw : public GraphicCommand
		{
		public:

			std::shared_ptr<Vertex> vertexData;

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
