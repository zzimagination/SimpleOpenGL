#include "ResourceDataCenter.h"
#include "ResourceLoader.h"
#include "ResourceInternal.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		DataCenter<TextureData> ResourceDataCenter::textureDataCenter;

		DataCenter<VertexData> ResourceDataCenter::vertexDataCetner;

		ResourcePackage<TextureData> ResourceDataCenter::CreateTexture()
		{
			return textureDataCenter.CreatePackage();
		}
		ResourcePackage<TextureData> ResourceDataCenter::CopyTexture(ResourcePackage<TextureData> package)
		{
			return textureDataCenter.CopyPackage(package);
		}
		ResourcePackage<TextureData> ResourceDataCenter::LoadTexture(std::string path)
		{
			auto data = ResourceLoader::LoadTexture(path);
			auto package = textureDataCenter.CreatePackage(data);
			package.clerk->AddPath(path);
			return package;
		}
		ResourcePackage<VertexData> ResourceDataCenter::CreateVertexData()
		{
			return vertexDataCetner.CreatePackage();
		}
		ResourcePackage<VertexData> ResourceDataCenter::CopyVertexData(ResourcePackage<VertexData> package)
		{
			return vertexDataCetner.CopyPackage(package);
		}
		ResourcePackage<VertexData> ResourceDataCenter::CreateCube()
		{
			auto data = VertexData::CreateCube();
			return vertexDataCetner.CreatePackage(data);
		}
	}
}