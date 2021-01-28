#ifndef __RESOURCECREATOR__
#define __RESOURCECREATOR__

#include "Common.h"
#include "ResourcePackage.h"

namespace SemperEngine
{
	namespace Core
	{
		class ResourceCreator
		{

		};


		class TextureCreator : public ResourceCreator
		{
		public:

			ResourcePackage<TextureData> Create();

			ResourcePackage<TextureData> Copy(ResourcePackage<TextureData> package);
		};

		class ModelCreator : public ResourceCreator
		{
		public:

			ResourcePackage<VertexDataCollection> Create();

			ResourcePackage<VertexDataCollection> CreateCube();

			ResourcePackage<VertexDataCollection> CreateRectangle();

			ResourcePackage<VertexDataCollection> Copy(ResourcePackage<VertexDataCollection> package);
		};
	}
}

#endif // !__RESOURCECREATOR__
