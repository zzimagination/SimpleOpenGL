#ifndef __GRAPHIC_RENDERAPI__
#define __GRAPHIC_RENDERAPI__

#include <vector>
#include "Mathz.h"
#include "Material.h"
#include "VertexData.h"
#include "GraphicResource.h"
#include "GraphicShader.h"

namespace SemperEngine {

	namespace Core {

		class GraphicRenderAPI
		{
		private:

			static GraphicShader _shader;

			static int _vertexCount;

		public:

			static void SetClearColor(Color color);

			static void SetClear(int mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(int func);

			static void SetCullFace(bool enable);

			static void SetCullMode(int mode);

			static void SetBlend(bool enable);

			static void SetBlendFunc();

			static void SetVertexData(GraphicVertexData& data);

			static void SetShader(std::string shader);

			static void SetShaderProperty(std::string name, float& value);
			static void SetShaderProperty(std::string name, Vector2& value);
			static void SetShaderProperty(std::string name, Vector3& value);
			static void SetShaderProperty(std::string name, Vector4& value);
			static void SetShaderProperty(std::string name, Matrix4x4& value);
			static void SetShaderProperty(int id, GraphicTextureData& data);

			static void Draw();

			static void SetWireframe(bool enable);

		};
	}
}
#endif // !RENDER_DRAW

