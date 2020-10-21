#include "Resource.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	shared_ptr<Mesh> Resource::LoadCube(bool share)
	{
		return VertexDataCenter::LoadCube(share);
	}

	shared_ptr<Texture> Resource::LoadTexture(string path, bool share)
	{
		return TextureDataCenter::LoadTexture(path);
	}
}