#ifndef RENDER_DRAW
#define RENDER_DRAW

#define OPENGL

#include <vector>
#include "Mathz.h"
#include "Material.h"
#include "ShaderProgram.h"

#define MODEL_MATRIX "_model"
#define VIEW_MATRIX "_view"
#define PROJECTION_MARIX "_projection"

class VertexData;
class TextureData;
using namespace std;

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

class RenderDraw
{
public:

	static Matrix4x4 model;

	static Matrix4x4 view;

	static Matrix4x4 projection;

private:

	static int drawCount;

	static int textureIndex;

public:

	static void SetClear(int mode, Vector4 color );

	static void SetDepthTest(bool test);

	static void SetDepthTest(bool test, DepthTestFunc f);

	static void SetCullFace(bool cull);

	static void SetCullFace(bool cull, CullFace mode);

	static void SetShader(ShaderProgram* shader,
		vector<ShaderProperty<float>> f,
		vector<ShaderProperty<Vector2>> vector2,
		vector<ShaderProperty<Vector3>> vector3,
		vector<ShaderProperty<Vector4>> vector4,
		vector<ShaderProperty<Matrix4x4>> matrix); 

	static void SetTransform(Matrix4x4 model, Matrix4x4 view, Matrix4x4 projection);

	static void SetVertexData(VertexData* data);

	static void SetTextureData(TextureData* data);

	static void Draw();

};

#endif // !RENDER_DRAW

