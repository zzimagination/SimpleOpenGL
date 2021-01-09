#pragma once
#ifndef __RESOURCELOADER__
#define __RESOURCELOADER__

#include <string>
#include <vector>
#include <map>
#include "Common.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceLoader
		{
		public:

			static TextureData* LoadTexture(std::string file);

		};
	}
}

#endif // !__RESOURCELOADER__
