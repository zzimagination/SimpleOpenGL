#ifndef TEXTURE
#define TEXTURE

#include <vector>

namespace SemperEngine {

	using namespace std;

	class Texture
	{
	public:

		int width;

		int height;

		int channels;

		unsigned char* data;

		Texture();

		~Texture();

		void LoadFile(string path);

	private:



	};

}
#endif // !TEXTURE
