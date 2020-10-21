#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>
#include "TextureData.h"
#include "ResourcePackage.h"

namespace SemperEngine {

	typedef Core::ResourcePackage<Core::TextureData> TexturePackage;

	class Texture
	{
	public:



	private:

		TexturePackage _package;

	public:

		Texture();

		Texture(TexturePackage package);

		~Texture();

		TexturePackage Package();
	};

}
#endif // !TEXTURE
