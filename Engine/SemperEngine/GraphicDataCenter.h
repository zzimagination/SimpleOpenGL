#pragma once
#ifndef __GRAPHIC_DATACENTER__
#define __GRAPHIC_DATACENTER__

#include <memory>
#include "FillList.h"
#include "VertexData.h"
#include "TextureData.h"
#include "ShaderProperty.h"
#include "GraphicTextureData.h"
#include "GraphicVertexData.h"
#include "GraphicCommand.h"
#include "Graphic.h"

namespace SemperEngine
{
	namespace Core
	{
		class GraphicDataCenter
		{
		public:

			static GraphicDataInfo screenVertexData;

		private:

			static FillList<std::shared_ptr<GraphicTextureData>> _textureData;

			static FillList<std::shared_ptr<GraphicVertexData>> _vertexData;

		public:

			static void Initialize();


			static GraphicDataInfo AddVertexData(VertexData* data);

			static void RemoveVertexData(GraphicDataInfo info);

			static void DeleteGraphicVertexData(GraphicDataInfo info);

			static std::shared_ptr<GraphicVertexData> GetVertexData(GraphicDataInfo info);


			static GraphicDataInfo AddTextureData(TextureData* data);

			static void RemoveTextureData(GraphicDataInfo info);

			static void DeleteGraphicTextureData(GraphicDataInfo info);

			static std::shared_ptr<GraphicTextureData> GetTextureData(GraphicDataInfo info);

		};
	}
}

#endif // !GRAPHICDATACENTER
