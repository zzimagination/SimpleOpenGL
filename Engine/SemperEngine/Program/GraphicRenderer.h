#pragma once
#ifndef __GRAPHICBATCH_MANAGER__
#define __GRAPHICBATCH_MANAGER__

#include <vector>
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicRenderer
		{
		public:

			static void Wireframe(bool enable);

			static void RenderScreen(
				RenderOperation operation, 
				ShaderProperty sproperty, 
				std::vector<GraphicTextureInfo> textures);

			static void Render(
				GraphicVertexInfo vertex, 
				RenderOperation operation, 
				RenderMatrix matrix, 
				ShaderProperty sproperty, 
				std::vector<GraphicTextureInfo> textures);

			static void Clear(Color color, Graphic::ClearMode mode);

			static void Clear(Color color);

		};
	}
}

#endif // !__GRAPHIC_BATCH__
