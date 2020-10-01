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

	class GraphicRenderDraw
	{
	public:

		static Matrix4x4 model;

		static Matrix4x4 view;

		static Matrix4x4 projection;

	private:

		static int drawCount;

		static int textureIndex;

	public:

		static void TestRender();


		static void SetClear(int mode, Vector4 color);

		static void SetDepthTest(bool test);

		static void SetDepthTest(bool test, DepthTestFunc f);

		static void SetCullFace(bool cull);

		static void SetCullFace(bool cull, CullFace mode);

		static void SetShader(Material* material);

		static void SetTransform(Matrix4x4 model, Matrix4x4 view, Matrix4x4 projection);

		static void SetVertexData(GraphicVertexData &data);

		static void SetTextureData(GraphicTextureData* data);

		static void Draw();



		static GraphicVertexData AddVertexData(Vector3* vertices, Vector2* uv, int* index, int count);

		static void ClearVertexData(const unsigned int VAO, const unsigned int VBO, const  unsigned int EBO);

		static GraphicTextureData* AddTextureData(Texture* data);

		static void ClearTextureData(GraphicTextureData* data);

	};
}
#endif // !RENDER_DRAW

