#ifndef __TEXTURE__
#define __TEXTURE__

#include <vector>
#include <string>
#include <memory>

namespace SemperEngine {

	class Texture
	{
	public:

		int width;

		int height;

		std::shared_ptr<unsigned char> data;

		Texture();

		~Texture();

	private:
	};

}
#endif // !TEXTURE
