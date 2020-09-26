#pragma once
#ifndef GRAPHICCMD_MANAGER
#define GRAPHICCMD_MANAGER

#include <vector>
#include "GraphicCommand.h"
#include "GraphicVertexBuffer.h"
#include "GraphicVertexBufferClear.h"
#include "GraphicTextureBuffer.h"
#include "GraphicTextureBufferClear.h"
#include "GraphicDraw.h"
#include "RenderBatch.h"

namespace SemperEngine
{
	class RenderVertexData;
	class Texture;
	class RenderBatch;

	namespace Core
	{
		class GraphicCommandManager
		{
		public:

			static std::vector<GraphicCommand*> front_AddResource;

			static std::vector<GraphicCommand*> front_CollectResource;
			
			static std::vector<GraphicCommand*> front_DrawCommands;

			static std::vector<GraphicCommand*> back_AddResource;

			static std::vector<GraphicCommand*> back_CollectResource;

			static std::vector<GraphicCommand*> back_DrawCommands;

		public:

			static void SwapCommands();

			static void AddVertexBuffer(RenderVertexData* data);

			static void AddTextureBuffer(Texture* data);

			static void ClearVertexBuffer(RenderVertexData* data);

			static void ClearTextureBuffer(Texture* data);

			static void Draw(RenderBatch batch);
		};
	}
}

#endif // !GRAPHICCOMD_MANAGER
