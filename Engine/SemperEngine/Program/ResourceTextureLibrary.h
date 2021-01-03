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

			virtual TextureObject* Load(std::string path) override;

		};


	}
}

#endif // !__RESOURCETEXTURELIBRARY__
