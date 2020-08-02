#ifndef RRENDEROBJECT
#define RRENDEROBJECT

#include <map>
#include "Mathz.h"
#include "Texture.h"
#include "Material.h"

using namespace std;

class VertexData;
class TextureData;

class RenderObject
{
private:

	struct GLTexture {
		string path;

		unsigned int ID;
	};

public:

	vector<Vector3> vertexBuffer;

	vector<int> indexBuffer;

	vector<Vector2> uvBuffer;

	vector<Vector3> normalBuffer;

	Matrix4x4 modelMatrix;

	Material *material;

	VertexData* vertexData;

	TextureData* textureData;

	RenderObject();

	~RenderObject();

	void BindVerticesData();

	void BindTextureData();

private:

};


#endif // !RRENDEROBJECT
