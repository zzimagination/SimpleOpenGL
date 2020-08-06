#ifndef TEXTUREDATA
#define TEXTUREDATA
#include <vector>
#include "Texture.h"

#define MAX_TEXTURE_COUNT  32

class Material;
class RenderObject;

using namespace std;

class TextureData
{

public:

	unsigned int textureId;

private:

	Texture* _texture;

public:

	TextureData(Texture* textures);

	~TextureData();

private:

	void BindData(Texture* textures);

	void BindOpenGLTexture(Texture* tex);
};

#endif // !TEXTUREDATA
