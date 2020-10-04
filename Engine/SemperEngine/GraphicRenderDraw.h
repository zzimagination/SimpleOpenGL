#ifndef RENDER_DRAW
#define RENDER_DRAW

#include <vector>
#include "EngineDef.h"
#include "Mathz.h"
#include "Material.h"
#include "ShaderProperty.h"
#include "VertexData.h"
#include "GraphicVertexData.h"

namespace SemperEngine {

	constexpr const char* MODEL_MATRIX = "_model";
	constexpr const char* VIEW_MATRIX = "_view";
	constexpr const char* PROJECTION_MARIX = "_projection";
	constexpr const char* MAINCOLOR = "_color";

	class GraphicShader;
	class Texture;
	class GraphicVertexData;
	class GraphicTextureData;

	enum DepthTestFunc
	{
		Never,

		Less,

		Equal,

		LEqual,

		Greater,

		GEqual,

		NotEqual,

		Always
	};

	enum ClearMode
	{

		Color = 1,

		Depth = 2,

		Stencil = 4
	};

	enum CullFace {
		Front,
		Back
	};

	namespace Core {

		class GraphicRenderDraw
		{
		private:

			static GraphicVertexData _vertexData;

			static Matrix4x4 _model;

			static Matrix4x4 _view;

			static Matrix4x4 _projection;

			static Material* _material;

			static int textureIndex;

		public:

			static void SetClearColor(Vector4 color);

			static void SetClear(int mode);

			static void SetDepthTest(bool enable);

			static void SetDepthTestFunc(int func);

			static void SetCullFace(bool enable);

			static void SetCullMode(int mode);

			static void SetVertexData(GraphicVertexData& data);

			static void SetTransform(Matrix4x4 &model, Matrix4x4 &view, Matrix4x4 &projection);

			static void SetMaterial(Material* material);

			static void SetTextureData(GraphicTextureData* data);

			static void Draw();


			static GraphicTextureData* AddTextureData(Texture* data);

			static void ClearTextureData(GraphicTextureData* data);

		};
	}
}
#endif // !RENDER_DRAW

