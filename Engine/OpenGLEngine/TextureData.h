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

	vector<unsigned int> textures;

public:

	TextureData(vector<Texture*> textures);

	~TextureData();

	void UseData();

private:

	void BindData(vector<Texture*> textures);

	void BindOpenGLTexture(Texture* tex);
};

#endif // !TEXTUREDATA
