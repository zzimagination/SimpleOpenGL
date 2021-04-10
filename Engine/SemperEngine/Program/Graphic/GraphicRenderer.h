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

			static void Render(
				GraphicVertexInfo vertex,
				RenderOperation operation,
				RenderMatrix matrix,
				ShaderProperty sproperty,
				std::vector<GraphicTextureInfo> textures,
				bool useRecord = false,
				std::vector<int> records = {});

			static void Render(
				GraphicVertexInfo vertex,
				RenderOperation operation,
				ShaderProperty sproperty,
				std::vector<GraphicTextureInfo> textures,
				bool useRecord = false,
				std::vector<int> records = {}
			);

			static void Render(
				GraphicVertexInfo vertex,
				ShaderProperty sproperty,
				std::vector<GraphicTextureInfo> textures,
				bool useRecord = false,
				std::vector<int> records = {}
			);

			static void Clear(Color color, Graphic::ClearMode mode);

			static void Clear(Color color);

			static void CreateRecord(std::string name);

			static void StopRecord();

		};
	}
}

#endif // !__GRAPHIC_BATCH__