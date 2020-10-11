#ifndef __GRAPHIC_RENDERAPI__
#define __GRAPHIC_RENDERAPI__

#include <vector>
#include "Mathz.h"
#include "Material.h"
#include "ShaderProperty.h"
#include "VertexData.h"
#include "GraphicVertexData.h"
#include "GraphicShader.h"

namespace SemperEngine {

	class Texture;
	class GraphicTextureData;

	namespace Core {

		class GraphicRenderAPI
		{
		private:

			static GraphicVertexData _vertexData;

			static Matrix4x4 _model;

			static Matrix4x4 _view;

			static Matrix4x4 _projection;

			static GraphicShader _shader;

			static ShaderProperty _shaderProperty;

			static int textureIndex;

		public:

			static void SetClearColor(Color color);

			static void SetClear(int mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(int func);

			static void SetCullFace(bool enable);

			static void SetCullMode(int mode);

			static void SetVertexData(GraphicVertexData& data);

			static void SetTransform(Matrix4x4 &model, Matrix4x4 &view, Matrix4x4 &projection);

			static void SetShader(std::string shader);

			static void SetShaderProperty(ShaderProperty value);

			static void SetTextureData(GraphicTextureData* data);

			static void Draw();

			static void SetWireframe(bool enable);


			static GraphicTextureData* AddTextureData(Texture* data);

			static void ClearTextureData(GraphicTextureData* data);


		};
	}
}
#endif // !RENDER_DRAW

