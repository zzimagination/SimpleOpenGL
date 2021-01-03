#ifndef __GRAPHIC_RENDERAPI__
#define __GRAPHIC_RENDERAPI__

#include <vector>
#include "Mathz.h"
#include "Material.h"
#include "VertexData.h"
#include "GraphicDataCenter.h"
#include "GraphicShader.h"
#include "Render.h"

namespace SemperEngine {

	namespace Core {

		class GraphicRenderAPI
		{
		private:

			static GraphicShader _shader;

			static int _vertexCount;

		public:

			static void SetClearColor(Color color);

			static void SetClear(RenderEnum::ClearMode mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(RenderEnum::DepthFunc func);

			static void SetCullFace(bool enable);

			static void SetCullMode(RenderEnum::CullFace face);

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

		};
	}
}
#endif // !RENDER_DRAW

