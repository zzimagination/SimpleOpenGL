#include "VertexDataCenter.h"
#include "CubeData.h"
#include "GraphicDataCenter.h"

namespace SemperEngine
{
	namespace Core
	{
		using namespace std;

		ResourcePackage<VertexData> VertexDataCenter::shareCube;

		std::vector<ResourcePackage<VertexData>> VertexDataCenter::cubes;

		vector<int> VertexDataCenter::unuseCube;

		RsVertexRef VertexDataCenter::LoadCube(bool share = false)
		{
			if (share)
			{
				if (shareCube.IsEmpty())
				{
					auto cube = CreateCubeData();
					shareCube = ResourcePackage<VertexData>(cube);
					shareCube.onDestroy = Unload;
					shareCube.id = 0;
					shareCube.Use();
					GraphicDataCenter::AddVertexData(shareCube);
				}
				auto instance = new ResourceReference<VertexData>(shareCube);
				RsVertexRef rs(instance);
				return rs;
			}

			auto cube = CreateCubeData();
			ResourcePackage<VertexData> package(cube);
			package.onDestroy = Unload;
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
			GraphicDataCenter::AddVertexData(package);
			auto instance = new ResourceReference<VertexData>(package);
			RsVertexRef rs(instance);
			return rs;
		}

		void VertexDataCenter::Unload(ResourceID id)
		{
			auto package = cubes[id];
			GraphicDataCenter::RemoveVertexData(package);
			unuseCube.push_back(id);
		}

		VertexData* VertexDataCenter::CreateCubeData()
		{
			auto cube = new VertexData();
			for (int i = 0; i < CubeData::vertexCount; i++)
			{
				cube->vertices.push_back(CubeData::vertices[i]);
			}
			cube->vertexCount = CubeData::vertexCount;
			for (int i = 0; i < CubeData::vertexCount; i++)
			{
				cube->uv.push_back(CubeData::uvs[i]);
			}
			for (int i = 0; i < CubeData::vertexCount / 4 * 6; i++)
			{
				cube->index.push_back(CubeData::indices[i]);
			}
			return cube;
		}

	}
}