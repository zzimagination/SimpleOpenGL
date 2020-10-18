#include "Resource.h"

namespace SemperEngine
{
	using namespace std;
	using namespace Core;

	Core::RsVertexRef Resource::LoadCube(bool share)
	{
		return VertexDataCenter::LoadCube(share);
	}
	Core::RsTextureRef Resource::LoadTexture(string path, bool share)
	{
		return TextureDataCenter::LoadTexture(path);
	}
}