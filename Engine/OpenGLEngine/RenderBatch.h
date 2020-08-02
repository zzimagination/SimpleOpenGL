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

	TextureData *textureData;

	Matrix4x4 *modelMatrix;

	Material* material;

	vector<RenderObject*> renderObjects;

public:

	~RenderBatch();

	void DrawCall(Camera* camera);

	bool IsBreak();

	void Break();

private:

};

#endif // !RENDERBATCH




