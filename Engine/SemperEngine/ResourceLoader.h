#pragma once
#ifndef __RESOURCELOADER__
#define __RESOURCELOADER__

#include <string>
#include <map>
#include "TextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceLoader
		{
		public:



		public:

			static TextureData* LoadTexture(std::string file);

			static std::string InternalFile(std::string file);

			static std::string ExternalFile(std::string file);
		};
	}
}

#endif // !__RESOURCELOADER__
