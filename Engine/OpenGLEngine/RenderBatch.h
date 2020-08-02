#ifndef RENDERBATCH
#define RENDERBATCH

#include <vector>
#include <map>
#include "Mathz.h"
#include "VertexData.h"
#include "Material.h"
#include "TextureData.h"

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

public:

	void DrawCall(Camera* camera);

private:

};

#endif // !RENDERBATCH




