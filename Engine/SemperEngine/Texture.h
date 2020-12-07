#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>
#include "TextureObject.h"

namespace SemperEngine 
{
	class Texture
	{
	public:

		std::shared_ptr<Core::TextureObject> object;

	public:

		Texture();

		~Texture();

		Texture* Copy();

		void ColorBuffer(std::shared_ptr<unsigned char> buffer);

		std::shared_ptr<unsigned char> ColorBuffer();
	};
}
#endif // !TEXTURE
