#ifndef __GRAPHIC_DATACENTER__
#define __GRAPHIC_DATACENTER__

#include <memory>
#include "Graphic.h"
#include "GraphicData.h"
#include "GraphicCommand.h"

namespace Semper
{
	namespace Core
	{
		class GraphicResource
		{
		public:

			static void Initialize();

#pragma region VertexData
		private:

			static FillList<GraphicVertexData*> _vertexData;

		public:

			static GraphicDataInfo AddVertexData(GraphicVertexResource resource);

			static void RemoveVertexData(GraphicDataInfo info);

			static GraphicVertexData* GetVertexData(GraphicDataInfo info);

		private:

			static void DeleteVertexFunc(GraphicVertexData* data);

#pragma endregion

#pragma region Texture
		private:

			static FillList<GraphicTextureData*> _textureData;

		public:

			static GraphicDataInfo AddTextureData(GraphicTextureResource resource);

			static void RemoveTextureData(GraphicDataInfo info);

			static GraphicTextureData* GetTexture(GraphicDataInfo info);

		private:

			static void DeleteTextureFunc(GraphicTextureData* data);

#pragma endregion
		};
	}
}

#endif // !GRAPHICDATACENTER
