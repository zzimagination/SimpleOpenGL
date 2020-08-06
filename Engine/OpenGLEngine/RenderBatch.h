#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include "Mathz.h"
#include "VertexData.h"
#include "TextureData.h"
#include "Material.h"

class RenderObject;
class ShaderProgram;
class Camera;


using namespace std;

class RenderBatch
{
public:

	VertexData *vertexData;

	vector<TextureData*> textureDatas;

	Matrix4x4 modelMatrix;

	ShaderProgram* shader;

	vector<ShaderProperty<float>> floatProperty;

	vector<ShaderProperty<Vector2>> vector2Property;

	vector < ShaderProperty<Vector3>> vector3Property;

	vector < ShaderProperty<Vector4>> vector4Property;

	vector < ShaderProperty<Matrix4x4>> matrixProperty;

	vector<RenderObject*> renderObjects;

public:

	~RenderBatch();

	void DrawCall(Camera* camera);

private:

};

#endif // !RENDERBATCH




