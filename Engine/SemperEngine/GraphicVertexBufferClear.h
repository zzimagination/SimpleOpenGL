#pragma once
#ifndef GRAPHICCMD_VERTEXBUFFERCLEAR
#define GRAPHICCMD_VERTEXBUFFERCLEAR

#include "GraphicCommand.h"
#include "GraphicCommandData.h"
#include "VertexData.h"
#include "GraphicVertexData.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicVertexBufferClear : public GraphicCommand
		{
		public:

			std::shared_ptr<Vertex> data;

		public:

			GraphicVertexBufferClear(std::shared_ptr<Vertex> data);

			virtual void Excute() override;
		};
	}
}

#endif // !GRAPHICCMD_VERTEXBUFFERCLEAR
