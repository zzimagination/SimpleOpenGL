#ifndef __GRAPHIC_RENDERAPI__
#define __GRAPHIC_RENDERAPI__

#include <vector>
#include "../Material.h"
#include "Graphic.h"
#include "GraphicShader.h"
#include "GraphicData.h"
#include "GraphicRecord.h"

namespace Semper {

	namespace Core 
	{

		class GraphicRenderAPI
		{
		public:

			static void SetClearColor(Color color);

			static void SetClear(Graphic::ClearMode mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(Graphic::DepthFunc func);

			static void SetCullFace(bool enable);

			static void SetCullMode(Graphic::CullFace face);

			static void SetBlend(bool enable);

			static void SetBlendFunc();

			static void SetVertexData(GraphicVertexData* data);

			static void UseShader(GraphicShader* shader);

			static void SetShaderProperty(GraphicShader* shader, std::string name, float& value);

			static void SetShaderProperty(GraphicShader* shader, std::string name, Float2& value);

			static void SetShaderProperty(GraphicShader* shader, std::string name, Float3& value);

			static void SetShaderProperty(GraphicShader* shader, std::string name, Float4& value);

			static void SetShaderProperty(GraphicShader* shader, std::string name, Matrix4x4& value);

			static void SetShaderProperty(GraphicShader* shader, int id, GraphicTextureData* data);

			static void Draw(GraphicVertexData* data);

			static void SetWireframe(bool enable);

			static void CreateRecord(GraphicRecord* record);

			static void StartRecord(GraphicRecord* record);

			static void StopRecord(GraphicRecord* record);

			static void DeleteRecord(GraphicRecord* record);

			static void DefaultFrameBuffer(GraphicRecord* record);

		};
	}
}
#endif // !RENDER_DRAW

