#pragma once
#ifndef __RESOURCETEXTURELIBRARY__
#define __RESOURCETEXTURELIBRARY__

#include "ResourceLibrary.h"
#include "TextureObject.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceTextureLibrary : public ResourceLibrary<TextureObject>
		{
		public:

			virtual ~ResourceTextureLibrary() override;

			TextureObject* Load(std::string path);

		};


	}
}

#endif // !__RESOURCETEXTURELIBRARY__
