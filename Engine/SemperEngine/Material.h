#ifndef MATERIAL
#define MATERIAL

#include <vector>
#include "Mathz.h"
#include "ShaderProperty.h"
#include "GraphicShader.h"

namespace SemperEngine {

	class GraphicShader;

	class Texture;

	using namespace std;

	class Material {

	public:

		string name;

		GraphicShader* shader;

		ShaderProperty<float> floatProperty;

		ShaderProperty<Vector2> vector2Property;

		ShaderProperty<Vector3> vector3Property;

		ShaderProperty<Vector4> vector4Property;

		ShaderProperty<Matrix4x4> matrix4x4Property;

		vector<Texture*> textures;

	public:

		Material(string shader);

		void SetMainColor(Vector4 color);

		void SetFloat(float value, string name);

		void SetVector2(Vector2 value, string name);

		void SetVector3(Vector3 value, string name);

		void SetVector4(Vector4 value, string name);

		void SetMatrix(Matrix4x4 value, string name);

		void SetTexture(Texture* tex);

		void RemoveTexture(Texture* tex);
	};
}
#endif // !MATERIAL
