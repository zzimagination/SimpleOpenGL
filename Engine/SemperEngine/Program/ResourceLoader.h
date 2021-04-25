#pragma once
#ifndef __RESOURCELOADER__
#define __RESOURCELOADER__

#include <string>
#include "Common.h"
#include <Engine/TextureLib.h>
#include <Engine/ModelLib.h>

namespace Semper
{
	namespace Core
	{
		class ResourceLoader
		{
		};

		class TextureLoader : public ResourceLoader
		{
		public:

			TextureLib::Texture Load(std::string path);
		};

		class ModelLoader : public ResourceLoader
		{
		public:

			ModelLib::Model Load(std::string path);
		};
	}
}

#endif // !__RESOURCELOADER__
