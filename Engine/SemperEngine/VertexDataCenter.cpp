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

		std::vector<ResourcePackage<VertexData>> VertexDataCenter::shareResources;

		std::vector<ResourcePackage<VertexData>> VertexDataCenter::instanceResources;

		ResourcePackage<VertexData> VertexDataCenter::LoadCube(bool share = false)
		{
			if (share)
			{
				if (shareCube.IsEmpty())
				{
					auto cube = CreateCubeData();
					shareCube = ResourcePackage<VertexData>(cube);
					GraphicDataCenter::AddVertexData(shareCube);
				}
				return shareCube;
			}

			auto cube = CreateCubeData();
			auto instance = ResourcePackage<VertexData>(cube);
			GraphicDataCenter::AddVertexData(instance);
			cubes.push_back(instance);
			return instance;
		}

		void VertexDataCenter::UnloadUnse()
		{
			vector<ResourcePackage<VertexData>> newCubes;
			for (int i = 0; i < cubes.size(); i++)
			{
				if (UnloadOnce(cubes[i]))
				{
					continue;
				}
				newCubes.push_back(cubes[i]);
			}
			cubes = newCubes;
		}

		VertexData * VertexDataCenter::CreateCubeData()
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

		bool VertexDataCenter::UnloadOnce(ResourcePackage<VertexData> package)
		{
			if (*package._useCount > 0)
			{
				return false;
			}
			GraphicDataCenter::RemoveVertexData(package);
			package.Destory();
			return true;
		}
	}
}