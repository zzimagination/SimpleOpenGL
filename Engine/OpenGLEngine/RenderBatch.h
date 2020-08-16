#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include "Mathz.h"
#include "VertexData.h"
#include "TextureData.h"
#include "Material.h"
namespace SemperEngine {
	class RenderObject;
	class ShaderProgram;
	class Camera;
	class Texture;

	using namespace std;

	class RenderBatch
	{
	public:

		RenderVertex *vertexData;

		vector<Texture*> textureDatas;

		Matrix4x4 modelMatrix;

		Matrix4x4 viewMatrix;

		Matrix4x4 projectionMatrix;

		ShaderProgram* shader;

		vector<ShaderProperty<float>> floatProperty;

		vector<ShaderProperty<Vector2>> vector2Property;

		vector < ShaderProperty<Vector3>> vector3Property;

		vector < ShaderProperty<Vector4>> vector4Property;

		vector < ShaderProperty<Matrix4x4>> matrixProperty;

		vector<RenderObject*> renderObjects;

	};
}
#endif // !RENDERBATCH




