#ifndef TEXTUREDATA
#define TEXTUREDATA
#include <vector>

namespace SemperEngine {
#define MAX_TEXTURE_COUNT  32

	class Texture;

	class GraphicTextureData
	{

	public:

		Texture* gameData;

		unsigned int textureId;

	public:

		GraphicTextureData(Texture* gameData, unsigned int id);

		~GraphicTextureData();
	};
}
#endif // !TEXTUREDATA
