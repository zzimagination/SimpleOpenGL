#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>
#include "Common.h"
#include "TextureObject.h"

namespace SemperEngine
{
	class Texture
	{
	public:

		enum class Filter
		{
			Nearest,

			Linear
		};

	private:

		Core::TextureObject* _object;

	public:

		Texture(int width, int height);

		Texture(Core::TextureObject* obj);

		~Texture();

		Core::TextureObject* GetObject();

		Texture* Copy();

		void SetColors(ArrayList<ColorByte> pixels);

		ArrayList<ColorByte> GetColors();

		void SetFilter(Filter filter);

		Filter GetFilter();
	};
}
#endif // !TEXTURE
