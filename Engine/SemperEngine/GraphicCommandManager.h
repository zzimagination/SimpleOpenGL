#pragma once
#ifndef __GRAPHICCMD_MANAGER__
#define __GRAPHICCMD_MANAGER__

#include <vector>
#include <memory>
#include "GraphicCommand.h"
#include "RenderBatch.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicCommandManager
		{
		public:

			static std::vector<GraphicCommand*> resources;

			static std::vector<GraphicCommand*> front_DrawCommands;

			static std::vector<GraphicCommand*> front_Setting;

			static std::vector<GraphicCommand*> back_DrawCommands;

			static std::vector<GraphicCommand*> back_setting;

		public:

			static void Render();

			static void Resource();

			static void SwapCommands();

			static void AddVertexBuffer(VertexCommandData data);

			static void ClearVertexBuffer(VertexCommandData data);

			static void AddTextureBuffer(TextureCommandData data);

			static void ClearTextureBuffer(TextureCommandData data);

			static void DrawScreen(RenderBatch &batch);

			static void Draw(RenderBatch &batch);

			static void Clear(Color color, int mode);

			static void SetWireframe(bool enable);
		};
	}
}

#endif // !GRAPHICCOMD_MANAGER
