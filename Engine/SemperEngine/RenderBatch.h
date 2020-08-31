#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include "Mathz.h"
#include "GraphicVertexData.h"
#include "GraphicTextureData.h"
#include "Material.h"
namespace SemperEngine {

	class RenderObject;
	class GraphicShader;
	class Camera;
	class Texture;

	using namespace std;

	class RenderBatch
	{
	public:

		RenderVertexData *vertexData;

		vector<Texture*> textureDatas;

		Matrix4x4 modelMatrix;

		Matrix4x4 viewMatrix;

		Matrix4x4 projectionMatrix;

		GraphicShader* shader;

		vector<ShaderProperty<float>> floatProperty;

		vector<ShaderProperty<Vector2>> vector2Property;

		vector < ShaderProperty<Vector3>> vector3Property;

		vector < ShaderProperty<Vector4>> vector4Property;

		vector < ShaderProperty<Matrix4x4>> matrixProperty;

		vector<RenderObject*> renderObjects;

	};
}
#endif // !RENDERBATCH




