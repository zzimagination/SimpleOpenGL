#pragma once
#ifndef GRAPHICCMD_BUFFER
#define GRAPHICCMD_BUFFER

#include "GraphicCommand.h"
#include "Mathz.h"

namespace SemperEngine
{
	class RenderVertexData;
	class GraphicVertexData;

	namespace Core
	{
		class GraphicVertexBuffer : public GraphicCommand
		{
		public:

			RenderVertexData* gameData;

		public:

			GraphicVertexBuffer(RenderVertexData* gameData);

			virtual void Excute() override;
;
		};
	}
}

#endif // !GRAPHICCMD_BUFFER
