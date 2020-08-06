#ifndef RRENDEROBJECT
#define RRENDEROBJECT

#include <map>
#include "Mathz.h"
#include "Texture.h"
#include "Material.h"
#include "RenderVertex.h"

using namespace std;

class RenderBatch;

class RenderObject
{
public:

	RenderVertex* renderVertex;

	Matrix4x4 modelMatrix;

	ShaderProgram* shader;

	vector<ShaderProperty<float>> floatProperty;

	vector<ShaderProperty<Vector2>> vector2Property;

	vector<ShaderProperty<Vector3>> vector3Property;

	vector<ShaderProperty<Vector4>> vector4Property;

	vector<ShaderProperty<Matrix4x4>> matrixProperty;

	vector<Texture*> textures;

	RenderBatch* batch;

public:

	RenderObject();

	~RenderObject();

	bool HasBatch();

	bool IsBreakBatch();

	void BreakBatch();

	void SetRenderBatch(RenderBatch* renderBatch);

private:

	bool _breakBatch;

};


#endif // !RRENDEROBJECT
