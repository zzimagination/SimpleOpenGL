#ifndef TEXTUREDATA
#define TEXTUREDATA
#include <vector>
#include "Texture.h"
namespace SemperEngine {
#define MAX_TEXTURE_COUNT  32

	class Material;
	class RenderObject;

	using namespace std;

	class GraphicTextureData
	{

	public:

		unsigned int textureId;

	private:

		Texture* _texture;

	public:

		GraphicTextureData(Texture* textures);

		~GraphicTextureData();

	private:

		void BindData(Texture* textures);

		void BindOpenGLTexture(Texture* tex);
	};
}
#endif // !TEXTUREDATA
