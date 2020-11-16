#pragma once
#ifndef __GRAPHICCMD_MANAGER__
#define __GRAPHICCMD_MANAGER__

#include <vector>
#include <memory>
#include <map>
#include "Graphic.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "GraphicCommand.h"

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

			static void AddVertexBuffer(GraphicDataInfo info);

			static void ClearVertexBuffer(GraphicDataInfo info);

			static void AddTextureBuffer(GraphicDataInfo info);

			static void ClearTextureBuffer(GraphicDataInfo info);

			static void Draw(
				GraphicVertexInfo vertex, 
				RenderOperation operation, 
				RenderMatrix matrix, 
				ShaderProperty sproperty, 
				std::vector<GraphicTextureInfo> textures);

			static void Clear(Color color, RenderEnum::ClearMode mode);

			static void SetWireframe(bool enable);

		private:

			static void Excute(std::vector<GraphicCommand*>& cmds);
		};
	}
}

#endif // !GRAPHICCOMD_MANAGER
