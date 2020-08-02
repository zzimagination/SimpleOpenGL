#ifndef RRENDEROBJECT
#define RRENDEROBJECT

#include <map>
#include "Mathz.h"
#include "Texture.h"
#include "Material.h"

using namespace std;

class RenderBatch;

class RenderObject
{
private:

	int vertexCount;

	Vector3* vertexBuffer;

	int* indexBuffer;

	Vector2* uvBuffer;

	Material *material;

	Matrix4x4 modelMatrix;

	RenderBatch* batch;

public:

	RenderObject();

	~RenderObject();

	bool HasBatch();

	bool IsBreakBatch();

	Vector3* GetVertices();

	int GetVertexCount();

	void SetVertices(Vector3* buffer, int count);

	int* GetIndex();

	void SetIndex(int* buffer);

	Vector2* GetUV();

	void SetUV(Vector2* buffer);

	Material* GetMaterial();

	void SetMaterial(Material* mat);

	Matrix4x4* GetModelMatrix();

	void SetModelMatrix(Matrix4x4 matrix);

	void SetRenderBatch(RenderBatch* renderBatch);

private:

	bool _breakBatch;

};


#endif // !RRENDEROBJECT
