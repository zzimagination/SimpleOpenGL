#ifndef __MATERIALOBJECT__
#define __MATERIALOBJECT__

#include <vector>
#include <memory>
#include "ResourceObject.h"
#include "Texture.h"
#include "Graphic.h"


namespace SemperEngine
{
	namespace Core
	{
		class MaterialObject : public ResourceObject
		{
		public:

			static MaterialObject* Create();

		public:

			std::vector<std::shared_ptr<Texture>> textures;

			RenderOperation renderOperation;

			ShaderProperty shaderProperty;

		public:

			virtual ~MaterialObject() override;

			MaterialObject* Copy();
		};
	}
}

#endif // !__MATERIALOBJECT__
