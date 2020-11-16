#include "ResourceInternal.h"
#include "CubeData.h"
#include "VertexDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		std::map < std::string, std::shared_ptr<Texture>> ResourceInternal::_texutures;

		void ResourceInternal::AddTexture(std::string name, std::shared_ptr<Texture> texture)
		{
			_texutures[name] = texture;
		}
		std::weak_ptr<Texture> ResourceInternal::GetTexture(std::string name)
		{
			weak_ptr<Texture> result = _texutures[name];
			return result;
		}
		std::shared_ptr<Mesh> ResourceInternal::GetCube()
		{
			auto data = CreateCubeData();
			auto package = VertexDataCenter::InputData(data);
			auto mesh = shared_ptr<Mesh>(new Mesh(package));
			return mesh;
		}
		VertexData* ResourceInternal::CreateCubeData()
		{
			auto cube = new VertexData();
			auto size = sizeof(CubeData::vertices);
			cube->vertices.resize(size);
			memcpy(cube->vertices.data(), CubeData::vertices, size);
			size = sizeof(CubeData::uvs);
			cube->uv.resize(size);
			memcpy(cube->uv.data(), CubeData::uvs, size);
			size = sizeof(CubeData::indices);
			cube->index.resize(size);
			memcpy(cube->index.data(), CubeData::indices, size);
			cube->vertexCount = CubeData::vertexCount;
			return cube;
		}
	}
}