#include "VertexDataCenter.h"
#include "CubeData.h"
#include "GraphicDataCenter.h"
#include "ScreenTextureData.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourcePackage<VertexData> VertexDataCenter::shareCube;

		std::vector<ResourcePackage<VertexData>> VertexDataCenter::cubes;

		vector<int> VertexDataCenter::unuseCube;

		shared_ptr<Mesh> VertexDataCenter::LoadCube(bool share = false)
		{
			//if (share)
			//{
			//	if (shareCube.IsEmpty())
			//	{
			//		auto cube = CreateCubeData();
			//		shareCube = ResourcePackage<VertexData>(cube);
			//		shareCube.onDestroy = Unload;
			//		shareCube.id = 0;
			//		shareCube.Use();
			//		GraphicDataCenter::AddVertexData(shareCube);
			//	}
			//	auto instance = new ResourceReference<VertexData>(shareCube);
			//	RsVertexRef rs(instance);
			//	return rs;
			//}

			auto cube = CreateCubeData();
			ResourcePackage<VertexData> package(cube);
			package.onDestroy = UnloadCube;
			unsigned int id = 0;
			if (unuseCube.size() > 0)
			{
				id = *(unuseCube.end() - 1);
				unuseCube.pop_back();
				package.id = id;
				cubes[id] = package;
			}
			else
			{
				id = (unsigned int)cubes.size();
				package.id = id;
				cubes.push_back(package);
			}
			package.GetResource()->Package(package);
			return shared_ptr<Mesh>(new Mesh(package));
		}

		void VertexDataCenter::UnloadCube(ResourceID id)
		{
			auto package = cubes[id];
			GraphicDataCenter::RemoveVertexData(package);
			unuseCube.push_back(id);
		}

		VertexData* VertexDataCenter::CreateCubeData()
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