#pragma once
#ifndef __GRAPHICCMD_MANAGER__
#define __GRAPHICCMD_MANAGER__

#include <vector>
#include <memory>
#include "GraphicCommand.h"
#include "RenderBatch.h"

namespace SemperEngine
{
	class Texture;

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

			static void SwapCommands();

			static void AddVertexBuffer(std::shared_ptr<VertexCommandData> data);

			static void AddTextureBuffer(Texture* data);

			static void ClearVertexBuffer(std::shared_ptr<VertexCommandData> data);

			static void ClearTextureBuffer(Texture* data);

			static void Draw(RenderBatch &batch);

			static void Clear(Color color, int mode);

			static void SetWireframe(bool enable);
		};
	}
}

#endif // !GRAPHICCOMD_MANAGER
