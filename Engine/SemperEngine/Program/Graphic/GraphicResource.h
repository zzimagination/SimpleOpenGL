#ifndef __GRAPHIC_DATACENTER__
#define __GRAPHIC_DATACENTER__

#include <memory>
#include "Graphic.h"
#include "GraphicData.h"
#include "GraphicCommand.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicResource
		{
		private:

			static FillList<std::shared_ptr<GraphicTextureData>> _textureData;

			static FillList<std::shared_ptr<GraphicVertexData>> _vertexData;

		public:

			static void Initialize();


			static GraphicDataInfo AddVertexData(GraphicVertexResource resource);

			static void RemoveVertexData(GraphicDataInfo info);

			static void DeleteGraphicVertexData(GraphicDataInfo info);

			static std::shared_ptr<GraphicVertexData> GetVertexData(GraphicDataInfo info);


			static GraphicDataInfo AddTextureData(GraphicTextureResource resource);

			static void RemoveTextureData(GraphicDataInfo info);

			static void DeleteGraphicTextureData(GraphicDataInfo info);

			static std::shared_ptr<GraphicTextureData> GetTextureData(GraphicDataInfo info);

		};
	}
}

#endif // !GRAPHICDATACENTER
