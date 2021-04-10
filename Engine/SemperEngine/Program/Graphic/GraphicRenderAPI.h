#ifndef __GRAPHIC_RENDERAPI__
#define __GRAPHIC_RENDERAPI__

#include <vector>
#include "../Material.h"
#include "Graphic.h"
#include "GraphicShader.h"
#include "GraphicData.h"
#include "GraphicRecord.h"

namespace SemperEngine {

	namespace Core 
	{

		class GraphicRenderAPI
		{
		private:

			enum class DrawType
			{
				Nomal,

				Index
			};

		private:

			static GraphicShader _shader;

			static int _vertexCount;

			static DrawType _drawType;

		public:

			static void SetClearColor(Color color);

			static void SetClear(Graphic::ClearMode mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(Graphic::DepthFunc func);

			static void SetCullFace(bool enable);

			static void SetCullMode(Graphic::CullFace face);

			static void SetBlend(bool enable);

			static void SetBlendFunc();

			static void SetVertexData(GraphicVertexData data);

			static void SetShader(std::string shader);

			static void SetShaderProperty(std::string name, float& value);
			static void SetShaderProperty(std::string name, Float2& value);
			static void SetShaderProperty(std::string name, Float3& value);
			static void SetShaderProperty(std::string name, Float4& value);
			static void SetShaderProperty(std::string name, Matrix4x4& value);
			static void SetShaderProperty(int id, GraphicTextureData& data);

			static void Draw();

			static void SetWireframe(bool enable);

			static void CreateRecord(GraphicRecord* record);

			static void StopRecord();

			static void DeleteRecord(GraphicRecord* record);
		};
	}
}
#endif // !RENDER_DRAW

