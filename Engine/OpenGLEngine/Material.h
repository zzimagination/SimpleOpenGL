#ifndef MATERIAL
#define MATERIAL
#include <vector>
#include "Mathz.h"
#include "ShaderProperty.h"
namespace SemperEngine {
	class ShaderProgram;
	class Texture;

	using namespace std;

	class Material {

	public:

		string name;

		ShaderProgram* shader;

		vector<ShaderProperty<float>> floatProperty;

		vector<ShaderProperty<Vector2>> vector2Property;

		vector<ShaderProperty<Vector3>> vector3Property;

		vector<ShaderProperty<Vector4>> vector4Property;

		vector<ShaderProperty<Matrix4x4>> matrixProperty;

		vector<Texture*> textures;

	public:

		Material(string shader);

		Material(ShaderProgram* shader);

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
