#pragma once
#ifndef GRAPHICCMD_VERTEXBUFFERCLEAR
#define GRAPHICCMD_VERTEXBUFFERCLEAR

#include "GraphicCommand.h"

namespace SemperEngine
{
	class RenderVertexData;

	namespace Core
	{
		class GraphicVertexBufferClear : public GraphicCommand
		{
		public:

			RenderVertexData* gameData;

		public:

			GraphicVertexBufferClear(RenderVertexData* gameData);

			virtual void Excute() override;
		};
	}
}

#endif // !GRAPHICCMD_VERTEXBUFFERCLEAR
