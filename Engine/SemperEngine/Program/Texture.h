#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>
#include "Mathz.h"
#include "TextureObject.h"

namespace SemperEngine
{
	class Texture
	{
	public:

		Core::TextureObject* object;

	public:

		Texture();

		Texture(Core::TextureObject* obj);

		~Texture();

		Texture* Copy();

		void SetColors(ArrayList<ColorByte> pixels);

		ArrayList<ColorByte> GetColors();
	};
}
#endif // !TEXTURE
