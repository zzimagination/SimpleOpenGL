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
		class MaterialObject : public ResourceObject, public IGraphicResource
		{
		public:

			static MaterialObject* Create();

			static MaterialObject* Create(std::string shader);

		public:

			std::vector<std::shared_ptr<Texture>> textures;

			RenderOperation renderOperation;

			ShaderProperty shaderProperty;

		public:

			virtual ~MaterialObject() override;

			MaterialObject* Copy();

		public:

			// Í¨¹ý IGraphicResource ¼Ì³Ð
			virtual void CreateGraphicResource() override;

			virtual void DeleteGraphicResource() override;
		};
	}
}

#endif // !__MATERIALOBJECT__
