#ifndef MATERIAL
#define MATERIAL
#include <vector>
#include "Mathz.h"
#include "ShaderProperty.h"

class ShaderProgram;
class Texture;

using namespace std;

class Material {

public:

	string name;

	ShaderProgram* shader;

	ShaderProperty<float> floatProperty;

	ShaderProperty<Vector2> vector2Property;

	ShaderProperty<Vector3> vector3Property;

	ShaderProperty<Vector4> vector4Property;

	ShaderProperty<Matrix4x4> matrixProperty;

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

#endif // !MATERIAL
