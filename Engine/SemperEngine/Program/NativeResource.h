#ifndef __NATIVERESOURCE__
#define __NATVIERESOURCE__

#include <string>
#include <Engine/ModelLib.h>
#include <Engine/TextureLib.h>

namespace SemperEngine
{
	namespace Core
	{
		class NativeResource
		{
		public:

			static TextureLib::Texture LoadTexture(std::string path);

			static ModelLib::Model LoadModel(std::string path);
		};
	}
}


#endif // !__NATIVERESOURCE__
