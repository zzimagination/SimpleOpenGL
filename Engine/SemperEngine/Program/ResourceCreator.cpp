#include "ResourceCreator.h"
#include <memory>

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourcePackage<TextureData> TextureCreator::Create()
		{
			ResourcePackage<TextureData> package = ResourcePackage<TextureData>(new TextureData);
			return package;
		}

		ResourcePackage<TextureData> TextureCreator::Copy(ResourcePackage<TextureData> package)
		{
			auto data = package.GetResource()->Copy();
			ResourcePackage<TextureData> copy(data);
			return copy;
		}
		ResourcePackage<VertexDataCollection> ModelCreator::Create()
		{
			auto collection = new VertexDataCollection();
			collection->data =shared_ptr<VertexData>(new VertexData());
			return collection;
		}
		ResourcePackage<VertexDataCollection> ModelCreator::CreateCube()
		{
			auto collection = new VertexDataCollection();
			collection->data = shared_ptr<VertexData>(VertexData::CreateCube());
			return collection;
		}
		ResourcePackage<VertexDataCollection> ModelCreator::CreateRectangle()
		{
			auto collection = new VertexDataCollection();
			collection->data = shared_ptr<VertexData>(VertexData::CreateRectangle());
			return collection;
		}
		ResourcePackage<VertexDataCollection> ModelCreator::Copy(ResourcePackage<VertexDataCollection> package)
		{
			return ResourcePackage<VertexDataCollection>();
		}
	}
}